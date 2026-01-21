PORTNAME=	pulumi-plugins-terraform
DISTVERSIONPREFIX=	v
DISTVERSION=	6.0.1
PORTREVISION=   2
CATEGORIES=	devel

MAINTAINER=	matias@pizarro.net
COMMENT=	Pulumi Terraform Remote State Resource Provider
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
	@${ECHO_MSG} "===> Building pulumi-resource-terraform"
	cd ${WRKSRC} && ${GO_CMD} build ${GO_BUILDFLAGS} \
		-o ${WRKSRC}/bin/pulumi-resource-terraform \
		main.go

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pulumi-resource-terraform \
		${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
