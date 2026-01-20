PORTNAME=	pulumi-plugins-docker
DISTVERSIONPREFIX=	v
DISTVERSION=	4.11.0
CATEGORIES=	devel

MAINTAINER=	matias@pizarro.net
COMMENT=	Pulumi Docker Resource Provider
WWW=		https://github.com/pulumi/pulumi-docker

LICENSE=	APACHE20

BUILD_DEPENDS=	git:devel/git \
		go:lang/go \
		pulumi:devel/pulumi
RUN_DEPENDS=	pulumi:devel/pulumi

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	pulumi
GH_PROJECT=	pulumi-docker

GO_BUILDFLAGS=	-buildvcs=false

# FreeBSD-specific Go dependency fixes
GO_DBUS_VERSION=	v5.2.2
GO_TERM_VERSION=	v1.2.0-beta.2

pre-build:
	@${ECHO_MSG} "===> Initializing upstream submodules"
	cd ${WRKSRC} && git submodule update --init --recursive || true
	cd ${WRKSRC} && ./scripts/upstream.sh init || true
	@${ECHO_MSG} "===> Updating Go dependencies for FreeBSD compatibility"
	cd ${WRKSRC}/provider && ${GO_CMD} get \
		github.com/godbus/dbus/v5@${GO_DBUS_VERSION} \
		github.com/pkg/term@${GO_TERM_VERSION}
	cd ${WRKSRC}/provider && ${GO_CMD} mod tidy
	cd ${WRKSRC}/provider && ${GO_CMD} mod vendor
	@${ECHO_MSG} "===> Running go generate for terraform-bridged provider"
	cd ${WRKSRC}/provider/cmd/pulumi-resource-docker && \
		VERSION=${DISTVERSION} ${GO_CMD} generate

do-build:
	@${ECHO_MSG} "===> Building pulumi-resource-docker"
	cd ${WRKSRC}/provider && ${GO_CMD} build ${GO_BUILDFLAGS} \
		-o ${WRKSRC}/bin/pulumi-resource-docker \
		./cmd/pulumi-resource-docker

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pulumi-resource-docker \
		${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
