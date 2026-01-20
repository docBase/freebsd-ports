PORTNAME=	pulumi-plugins-hcloud
DISTVERSIONPREFIX=	v
DISTVERSION=	1.31.0
CATEGORIES=	devel

MAINTAINER=	matias@pizarro.net
COMMENT=	Pulumi Hetzner Cloud Resource Provider
WWW=		https://github.com/pulumi/pulumi-hcloud

LICENSE=	APACHE20

BUILD_DEPENDS=	go:lang/go \
		pulumi:devel/pulumi
RUN_DEPENDS=	pulumi:devel/pulumi

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	pulumi
GH_PROJECT=	pulumi-hcloud

GO_BUILDFLAGS=	-buildvcs=false

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
	@${ECHO_MSG} "===> Running go generate for terraform-bridged provider"
	cd ${WRKSRC}/provider/cmd/pulumi-resource-hcloud && \
		VERSION=${DISTVERSION} ${GO_CMD} generate

do-build:
	@${ECHO_MSG} "===> Building pulumi-resource-hcloud"
	cd ${WRKSRC}/provider && ${GO_CMD} build ${GO_BUILDFLAGS} \
		-o ${WRKSRC}/bin/pulumi-resource-hcloud \
		./cmd/pulumi-resource-hcloud

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pulumi-resource-hcloud \
		${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
