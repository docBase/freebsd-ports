PORTNAME=	pulumi-plugins-terraform
DISTVERSIONPREFIX=	v
DISTVERSION=	6.0.1
CATEGORIES=	devel

MAINTAINER=	matias@pizarro.net
COMMENT=	Pulumi Terraform Resource Provider
WWW=		https://github.com/pulumi/pulumi-terraform

LICENSE=	APACHE20

BUILD_DEPENDS=	go:lang/go \
		pulumi:devel/pulumi
RUN_DEPENDS=	pulumi:devel/pulumi

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	pulumi
GH_PROJECT=	pulumi-terraform

GO_BUILDFLAGS=	-buildvcs=false \
		-ldflags "-X github.com/pulumi/pulumi-terraform/v6/provider/version.version=${DISTVERSION}"

PLIST_FILES=	bin/pulumi-resource-terraform

# FreeBSD-specific: upstream Go modules require dependency updates for
# FreeBSD compatibility (godbus/dbus, pkg/term). These cannot be patched
# statically because vendor directories are regenerated from go.sum.
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
	@${ECHO_MSG} "===> Building pulumi-resource-terraform"
	cd ${WRKSRC} && GOMAXPROCS=${MAKE_JOBS_NUMBER} ${GO_CMD} build ${GO_BUILDFLAGS} \
		-o ${WRKSRC}/bin/pulumi-resource-terraform \
		main.go

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pulumi-resource-terraform \
		${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
