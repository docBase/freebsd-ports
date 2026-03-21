PORTNAME=	pulumi-plugins-docker
DISTVERSIONPREFIX=	v
DISTVERSION=	4.11.1
CATEGORIES=	devel

MAINTAINER=	matias@pizarro.net
COMMENT=	Pulumi Docker Resource Provider
WWW=		https://github.com/pulumi/pulumi-docker

LICENSE=	APACHE20

BUILD_DEPENDS=	pulumi:devel/pulumi
RUN_DEPENDS=	pulumi:devel/pulumi

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	pulumi
GH_PROJECT=	pulumi-docker

# Upstream terraform-provider-docker submodule (commit from v4.11.1)
GH_TUPLE=	kreuzwerker:terraform-provider-docker:d7d7ff7f89775a7b71f925a8724de5ce66228019:upstream

GO_BUILDFLAGS=	-buildvcs=false \
		-ldflags "-X github.com/pulumi/pulumi-docker/provider/v4/pkg/version.Version=${DISTVERSION}"

PLIST_FILES=	bin/pulumi-resource-docker

# FreeBSD-specific: upstream Go modules require dependency updates for
# FreeBSD compatibility (godbus/dbus, pkg/term). These cannot be patched
# statically because vendor directories are regenerated from go.sum.
GO_DBUS_VERSION=	v5.2.2
GO_TERM_VERSION=	v1.2.0-beta.2

post-extract:
	@${ECHO_MSG} "===> Setting up upstream terraform-provider-docker"
	${RM} -rf ${WRKSRC}/upstream
	${MV} ${WRKDIR}/terraform-provider-docker-d7d7ff7f89775a7b71f925a8724de5ce66228019 ${WRKSRC}/upstream
	@${ECHO_MSG} "===> Applying Pulumi patches to upstream"
	@if [ -d ${WRKSRC}/patches ]; then \
		cd ${WRKSRC}/upstream && for p in ${WRKSRC}/patches/*.patch; do \
			${ECHO_MSG} "  Applying $${p##*/}"; \
			${PATCH} -p1 < "$${p}"; \
		done; \
	fi

pre-build:
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
	cd ${WRKSRC}/provider && GOMAXPROCS=${MAKE_JOBS_NUMBER} ${GO_CMD} build ${GO_BUILDFLAGS} \
		-o ${WRKSRC}/bin/pulumi-resource-docker \
		./cmd/pulumi-resource-docker

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pulumi-resource-docker \
		${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
