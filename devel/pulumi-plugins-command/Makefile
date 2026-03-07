PORTNAME=	pulumi-plugins-command
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.1
CATEGORIES=	devel

MAINTAINER=	matias@pizarro.net
COMMENT=	Pulumi Command Resource Provider
WWW=		https://github.com/pulumi/pulumi-command

LICENSE=	APACHE20

BUILD_DEPENDS=	go:lang/go \
		pulumi:devel/pulumi
RUN_DEPENDS=	pulumi:devel/pulumi

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	pulumi
GH_PROJECT=	pulumi-command

GO_BUILDFLAGS=	-buildvcs=false \
		-ldflags "-X github.com/pulumi/pulumi-command/provider/pkg/version.Version=${DISTVERSION}"

# FreeBSD-specific Go dependency fixes
GO_DBUS_VERSION=	v5.2.2
GO_TERM_VERSION=	v1.2.0-beta.2

pre-build:
	@${ECHO_MSG} "===> Updating Go dependencies for FreeBSD compatibility"
	cd ${WRKSRC}/provider && ${GO_CMD} get \
		github.com/godbus/dbus/v5@${GO_DBUS_VERSION} \
		github.com/pkg/term@${GO_TERM_VERSION}
	cd ${WRKSRC}/provider && ${GO_CMD} mod tidy
	cd ${WRKSRC}/provider && ${GO_CMD} mod vendor

do-build:
	@${ECHO_MSG} "===> Building pulumi-resource-command"
	cd ${WRKSRC}/provider && GOMAXPROCS=8 ${GO_CMD} build ${GO_BUILDFLAGS} \
		-o ${WRKSRC}/bin/pulumi-resource-command \
		./cmd/pulumi-resource-command

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pulumi-resource-command \
		${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
