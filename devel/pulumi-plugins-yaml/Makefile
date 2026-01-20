PORTNAME=	pulumi-plugins-yaml
DISTVERSIONPREFIX=	v
DISTVERSION=	1.15.0
CATEGORIES=	devel

MAINTAINER=	matias@pizarro.net
COMMENT=	Pulumi YAML Language Plugin
WWW=		https://github.com/pulumi/pulumi-yaml

LICENSE=	APACHE20

BUILD_DEPENDS=	go:lang/go \
		pulumi:devel/pulumi
RUN_DEPENDS=	pulumi:devel/pulumi

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	pulumi
GH_PROJECT=	pulumi-yaml

GO_BUILDFLAGS=	-buildvcs=false

# FreeBSD-specific Go dependency fixes
GO_DBUS_VERSION=	v5.2.2
GO_TERM_VERSION=	v1.2.0-beta.2

pre-build:
	@${ECHO_MSG} "===> Updating Go dependencies for FreeBSD compatibility"
	cd ${WRKSRC} && ${GO_CMD} get \
		github.com/godbus/dbus/v5@${GO_DBUS_VERSION} \
		github.com/pkg/term@${GO_TERM_VERSION}
	cd ${WRKSRC} && ${GO_CMD} mod tidy
	cd ${WRKSRC} && ${GO_CMD} mod vendor

do-build:
	@${ECHO_MSG} "===> Building pulumi-language-yaml"
	cd ${WRKSRC}/cmd/pulumi-language-yaml && \
		${GO_CMD} build ${GO_BUILDFLAGS} -o ${WRKSRC}/bin/pulumi-language-yaml .
	@${ECHO_MSG} "===> Building pulumi-converter-yaml"
	cd ${WRKSRC}/cmd/pulumi-converter-yaml && \
		${GO_CMD} build ${GO_BUILDFLAGS} -o ${WRKSRC}/bin/pulumi-converter-yaml .

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pulumi-converter-yaml ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pulumi-language-yaml ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
