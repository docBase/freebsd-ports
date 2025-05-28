PORTNAME=	foreign-cdm
PORTVERSION=	20231217
CATEGORIES=	www multimedia linux
MASTER_SITES=	https://arrowd.name/:cdm
DISTFILES=	cdm-${CDM_INT_HASH}.tar.gz:cdm
PKGNAMEPREFIX=	linux-rl9-

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	CDM agent for Chromium
WWW=		https://github.com/shkhln/foreign-cdm

LICENSE=	MIT

ONLY_FOR_ARCHS=	amd64

USES=		linux:rl9
USE_LINUX=	devtools:build base:run

BUILD_DEPENDS=	cmake>0:devel/cmake
RUN_DEPENDS=	linux_base-rl9>0:emulators/linux_base-rl9

USE_GITHUB=	yes
GH_ACCOUNT=	shkhln
GH_PROJECT=	foreign-cdm
GH_TAGNAME=	3f69acb63db147c99036f500bb388e5d084247b4
GH_TUPLE=	capnproto:capnproto:1a0e12c0a3ba1f0dbbad45ddfef555166e0a14fc:capnproto/third_party/capnproto

MAKE_ENV=	LINUX_CC=/compat/linux/opt/rh/devtoolset-11/root/usr/bin/g++ \
		MAKE_JOBS_NUMBER=${MAKE_JOBS_NUMBER}

SUB_FILES=	fcdm-setup-env

PLIST_FILES=	libexec/fcdm-jail \
		libexec/fcdm-worker \
		lib/foreign-cdm/fcdm-fbsd.so \
		share/chromium/WidevineCdm/_platform_specific/linux_x64/libwidevinecdm.so \
		share/chromium/WidevineCdm/manifest.json \
		share/foreign-cdm/fcdm-setup-env

CDM_INT_HASH=	fef0b5aa1bd31efb88dfab804bdbe614f3d54f28

post-extract:
	${MV} ${WRKDIR}/*.h ${WRKSRC}/third_party/cdm/

post-patch:
	${REINPLACE_CMD} -e 's|chmod a+srX|chmod a+rX|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/fcdm-jail ${STAGEDIR}${PREFIX}/libexec/
	${CHMOD} u+s ${STAGEDIR}${PREFIX}/libexec/fcdm-jail
	${INSTALL_PROGRAM} ${WRKSRC}/build/fcdm-worker ${STAGEDIR}${PREFIX}/libexec/

	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/fcdm-setup-env ${STAGEDIR}${DATADIR}

	${MKDIR} ${STAGEDIR}${PREFIX}/lib/foreign-cdm
	${CP} ${WRKSRC}/build/fcdm-fbsd.so ${STAGEDIR}${PREFIX}/lib/foreign-cdm/
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/foreign-cdm/fcdm-fbsd.so

	${MKDIR} ${STAGEDIR}${PREFIX}/share/chromium/WidevineCdm/_platform_specific/linux_x64
	${LN} -s ${PREFIX}/lib/foreign-cdm/fcdm-fbsd.so ${STAGEDIR}${PREFIX}/share/chromium/WidevineCdm/_platform_specific/linux_x64/libwidevinecdm.so
	${LN} -s ${PREFIX}/lib/WidevineCdm/manifest.json ${STAGEDIR}${PREFIX}/share/chromium/WidevineCdm/manifest.json

.include <bsd.port.mk>
