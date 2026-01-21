PORTNAME=	pulumi
DISTVERSIONPREFIX=	v
DISTVERSION=	3.216.0
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES+=	https://raw.githubusercontent.com/${PORTNAME}/${PORTNAME}/${DISTVERSIONFULL}/

MAINTAINER=	matias@pizarro.net
COMMENT=	Infrastructure as Code SDK
WWW=		https://www.pulumi.com/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}grpcio>0:devel/py-grpcio@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}grpcio>0:devel/py-grpcio@${PY_FLAVOR}

USES=		gmake go python:3.11 shebangfix
USE_GITHUB=	yes

SHEBANG_FILES=	sdk/python/cmd/pulumi-language-python-exec \
		sdk/python/dist/pulumi-analyzer-policy-python \
		sdk/python/dist/pulumi-resource-pulumi-python

GO_TARGET=	:${BIN_NAME}
GO_BUILDFLAGS=	-ldflags=" \
		-X github.com/pulumi/pulumi/sdk/v3/go/common/version.Version=${DISTVERSION}"

# FreeBSD-specific Go dependency fixes
GO_DBUS_VERSION=	v5.2.2
GO_TERM_VERSION=	v1.2.0-beta.2

OPTIONS_DEFINE=		GO NODEJS PYTHON
OPTIONS_DEFAULT=	GO NODEJS PYTHON
OPTIONS_SUB=		yes

GO_DESC=	Go language support
NODEJS_DESC=	Node.js language support
PYTHON_DESC=	Python language support

NODEJS_BUILD_DEPENDS=	node:www/node \
			yarn:www/yarn
PYTHON_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${PY_FLAVOR}
PYTHON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}grpcio>0:devel/py-grpcio@${PY_FLAVOR}

.include <bsd.port.options.mk>

post-extract:
	@${ECHO_MSG} "===> Fixing FreeBSD Go dependencies"

pre-build:
	@${ECHO_MSG} "===> Updating Go dependencies for FreeBSD compatibility"
	cd ${WRKSRC}/pkg && ${GO_CMD} get \
		github.com/godbus/dbus/v5@${GO_DBUS_VERSION} \
		github.com/pkg/term@${GO_TERM_VERSION}
	cd ${WRKSRC}/pkg && ${GO_CMD} mod tidy
	cd ${WRKSRC}/sdk && ${GO_CMD} get \
		github.com/godbus/dbus/v5@${GO_DBUS_VERSION} \
		github.com/pkg/term@${GO_TERM_VERSION}
	cd ${WRKSRC}/sdk && ${GO_CMD} mod tidy
	cd ${WRKSRC}/pkg && ${GO_CMD} mod vendor

do-build:
	@${ECHO_MSG} "===> Building Pulumi CLI"
	cd ${WRKSRC}/pkg && ${GO_CMD} build \
		-o ${WRKSRC}/bin/pulumi \
		${GO_BUILDFLAGS} \
		./cmd/pulumi

.if ${PORT_OPTIONS:MPYTHON}
	@${ECHO_MSG} "===> Building Python language plugin"
	cd ${WRKSRC}/sdk/python/cmd/pulumi-language-python && \
		${GO_CMD} mod tidy && \
		${GO_CMD} mod vendor && \
		${GO_CMD} build \
		-o ${WRKSRC}/bin/pulumi-language-python \
		${GO_BUILDFLAGS} \
		.
.endif

.if ${PORT_OPTIONS:MNODEJS}
	@${ECHO_MSG} "===> Building Node.js language plugin"
	cd ${WRKSRC}/sdk/nodejs/cmd/pulumi-language-nodejs && \
		${GO_CMD} mod tidy && \
		${GO_CMD} mod vendor && \
		${GO_CMD} build \
		-o ${WRKSRC}/bin/pulumi-language-nodejs \
		${GO_BUILDFLAGS} \
		.
.endif

.if ${PORT_OPTIONS:MGO}
	@${ECHO_MSG} "===> Building Go language plugin"
	cd ${WRKSRC}/sdk/go/pulumi-language-go && \
		${GO_CMD} mod tidy && \
		${GO_CMD} mod vendor && \
		${GO_CMD} build \
		-o ${WRKSRC}/bin/pulumi-language-go \
		${GO_BUILDFLAGS} \
		.
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pulumi ${STAGEDIR}${PREFIX}/bin/

.if ${PORT_OPTIONS:MPYTHON}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pulumi-language-python ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/sdk/python/cmd/pulumi-language-python-exec \
		${STAGEDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/sdk/python/dist/pulumi-resource-pulumi-python \
		${STAGEDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/sdk/python/dist/pulumi-analyzer-policy-python \
		${STAGEDIR}${PREFIX}/bin/
.endif

.if ${PORT_OPTIONS:MNODEJS}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pulumi-language-nodejs ${STAGEDIR}${PREFIX}/bin/
.endif

.if ${PORT_OPTIONS:MGO}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pulumi-language-go ${STAGEDIR}${PREFIX}/bin/
.endif

BIN_NAME=	pulumi

.include <bsd.port.mk>
