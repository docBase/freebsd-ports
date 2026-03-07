PORTNAME=	pulumi-plugins-aws
DISTVERSIONPREFIX=	v
DISTVERSION=	7.20.0
CATEGORIES=	devel

MAINTAINER=	matias@pizarro.net
COMMENT=	Pulumi AWS Resource Provider
WWW=		https://github.com/pulumi/pulumi-aws

LICENSE=	APACHE20

BUILD_DEPENDS=	git:devel/git \
		go:lang/go \
		pulumi:devel/pulumi
RUN_DEPENDS=	pulumi:devel/pulumi

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	pulumi
GH_PROJECT=	pulumi-aws

# Upstream terraform-provider-aws submodule (commit from v7.20.0)
GH_TUPLE=	hashicorp:terraform-provider-aws:ea6e951e24066a24891c63a37a3b95f9971d16b8:upstream

GO_BUILDFLAGS=	-buildvcs=false \
		-ldflags "-X github.com/pulumi/pulumi-aws/provider/v7/pkg/version.Version=${DISTVERSION}"

# FreeBSD-specific Go dependency fixes
GO_DBUS_VERSION=	v5.2.2
GO_TERM_VERSION=	v1.2.0-beta.2

post-extract:
	@${ECHO_MSG} "===> Setting up upstream terraform-provider-aws"
	${RM} -rf ${WRKSRC}/upstream
	${MV} ${WRKDIR}/terraform-provider-aws-ea6e951e24066a24891c63a37a3b95f9971d16b8 ${WRKSRC}/upstream
	@${ECHO_MSG} "===> Applying Pulumi patches to upstream"
	@cd ${WRKSRC}/upstream && for p in ${WRKSRC}/patches/*.patch; do \
		${ECHO_MSG} "  Applying $${p##*/}"; \
		/usr/bin/patch -p1 < "$${p}"; \
	done

pre-build:
	@${ECHO_MSG} "===> Updating Go dependencies for FreeBSD compatibility"
	cd ${WRKSRC}/provider && ${GO_CMD} get \
		github.com/godbus/dbus/v5@${GO_DBUS_VERSION} \
		github.com/pkg/term@${GO_TERM_VERSION}
	cd ${WRKSRC}/provider && ${GO_CMD} mod tidy
	cd ${WRKSRC}/provider && ${GO_CMD} mod vendor
	@${ECHO_MSG} "===> Running go generate for terraform-bridged provider"
	cd ${WRKSRC}/provider/cmd/pulumi-resource-aws && \
		VERSION=${DISTVERSION} ${GO_CMD} generate
	cd ${WRKSRC}/provider/cmd/pulumi-resource-aws && \
		PULUMI_AWS_MINIMAL_SCHEMA=true VERSION=${DISTVERSION} ${GO_CMD} generate

do-build:
	@${ECHO_MSG} "===> Building pulumi-resource-aws"
	cd ${WRKSRC}/provider && GOMAXPROCS=8 ${GO_CMD} build ${GO_BUILDFLAGS} \
		-o ${WRKSRC}/bin/pulumi-resource-aws \
		./cmd/pulumi-resource-aws

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pulumi-resource-aws \
		${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
