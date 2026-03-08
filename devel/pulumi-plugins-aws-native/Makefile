PORTNAME=	pulumi-plugins-aws-native
DISTVERSIONPREFIX=	v
DISTVERSION=	1.55.0
CATEGORIES=	devel

MAINTAINER=	matias@pizarro.net
COMMENT=	Pulumi AWS Native Resource Provider
WWW=		https://github.com/pulumi/pulumi-aws-native

LICENSE=	APACHE20

BUILD_DEPENDS=	go:lang/go \
		pulumi:devel/pulumi
RUN_DEPENDS=	pulumi:devel/pulumi

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	pulumi
GH_PROJECT=	pulumi-aws-native

GO_BUILDFLAGS=	-buildvcs=false \
		-ldflags "-X github.com/pulumi/pulumi-aws-native/provider/pkg/version.Version=${DISTVERSION}"

PLIST_FILES=	bin/pulumi-resource-aws-native

# FreeBSD-specific: upstream Go modules require dependency updates for
# FreeBSD compatibility (godbus/dbus, pkg/term). These cannot be patched
# statically because vendor directories are regenerated from go.sum.
GO_DBUS_VERSION=	v5.2.2
GO_TERM_VERSION=	v1.2.0-beta.2

pre-build:
	@${ECHO_MSG} "===> Updating Go dependencies for FreeBSD compatibility"
	cd ${WRKSRC}/provider && ${GO_CMD} get \
		github.com/godbus/dbus/v5@${GO_DBUS_VERSION} \
		github.com/pkg/term@${GO_TERM_VERSION}
	cd ${WRKSRC}/provider && ${GO_CMD} mod tidy
	cd ${WRKSRC}/provider && ${GO_CMD} mod vendor
	@${ECHO_MSG} "===> Creating compressed schema files"
	cd ${WRKSRC}/provider/cmd/pulumi-resource-aws-native && \
		${GZIP_CMD} -kf schema.json && ${GZIP_CMD} -kf metadata.json

do-build:
	@${ECHO_MSG} "===> Building pulumi-resource-aws-native"
	cd ${WRKSRC}/provider && GOMAXPROCS=${MAKE_JOBS_NUMBER} ${GO_CMD} build ${GO_BUILDFLAGS} \
		-o ${WRKSRC}/bin/pulumi-resource-aws-native \
		./cmd/pulumi-resource-aws-native

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pulumi-resource-aws-native \
		${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
