PORTNAME=	pulumi-plugins-std
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.0
CATEGORIES=	devel

MAINTAINER=	matias@pizarro.net
COMMENT=	Pulumi Standard Resource Plugin
WWW=		https://github.com/pulumi/pulumi-std

LICENSE=	APACHE20

BUILD_DEPENDS=	go:lang/go \
		pulumi:devel/pulumi
RUN_DEPENDS=	pulumi:devel/pulumi

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	pulumi
GH_PROJECT=	pulumi-std

GO_BUILDFLAGS=	-buildvcs=false

# FreeBSD-specific Go dependency fixes
GO_DBUS_VERSION=	v5.2.2
GO_TERM_VERSION=	v1.2.0-beta.2

pre-build:
	@${ECHO_MSG} "===> Updating Go dependencies for FreeBSD compatibility"
	cd ${WRKSRC}/std && ${GO_CMD} get \
		github.com/godbus/dbus/v5@${GO_DBUS_VERSION} \
		github.com/pkg/term@${GO_TERM_VERSION}
	cd ${WRKSRC}/std && ${GO_CMD} mod tidy
	cd ${WRKSRC}/std && ${GO_CMD} mod vendor

do-build:
	@${ECHO_MSG} "===> Building pulumi-resource-std"
	cd ${WRKSRC}/std && ${GO_CMD} build ${GO_BUILDFLAGS} \
		-o ${WRKSRC}/bin/pulumi-resource-std \
		./cmd/pulumi-resource-std

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pulumi-resource-std \
		${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
