PORTNAME=	bcompare
DISTVERSION=	5.0.7
DISTVERSIONSUFFIX=	.30840
CATEGORIES=	editors devel linux
MASTER_SITES=	https://scootersoftware.com/files/
PKGNAMEPREFIX=	linux-
PKGNAMESUFFIX=	5

DISTNAME_amd64=	${DISTNAME}.x86_64
EXTRACT_SUFX=	.rpm

MAINTAINER=	matias@pizarro.net
COMMENT=	Compare, sync, and merge files and folders (X11)
WWW=		https://www.scootersoftware.com/

LICENSE=	SCOOTERSOFTWARE
LICENSE_NAME=	Scooter Software License
LICENSE_FILE=	${FILESDIR}/LICENSE.txt
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	upstream only supports amd64

USES=		desktop-file-utils gnome linux:rl9 shared-mime-info
USE_LINUX=	base:run curl:run dbuslibs:run devtools:build freetype:run \
		qtx11extras:run systemd-libs:run xcb-util:run \
		xorglibs:run

CONFLICTS_INSTALL=	linux-bcompare[0-9]*

NO_BUILD=	yes

NO_WRKSUBDIR=	true

DATA_FILTER=	-type d -o -name *\.html -o -name *\.js -o -name *\.css -o \
		-name *\.gif -o -name *\.png -o -name *\.jpg -o -name \
		*\.desktop -o -name mime\.types -o -name README -o -name \
		copyright -o -name BCompare.mad -o -name \
		RPM-GPG-KEY-scootersoftware -o -name scootersoftware.repo

LIB_FILES=	lib7z.so libcloudstorage.so.22.0 libQt5Pas.so.1 libunrar.so \
		nosched.so
PROGRAM_FILES=	BCompare
SCRIPT_FILES=	bcmount.sh

.include <bsd.port.options.mk>

LIBDIR=		lib64

BCLIB_SRC=	${WRKSRC}/usr/${LIBDIR}/beyondcompare
BCLIB_STG=	${STAGEDIR}${PREFIX}/lib/beyondcompare

pre-install:
	${LINUXBASE}/usr/bin/gcc --sysroot=${LINUXBASE} -Wall -fPIC -shared \
		${FILESDIR}/nosched.c -ldl -o ${BCLIB_SRC}/nosched.so

do-install:
# bin
	${INSTALL_SCRIPT} ${WRKSRC}/usr/bin/bcompare ${STAGEDIR}${PREFIX}/bin
# lib
	(cd ${BCLIB_SRC}     && ${COPYTREE_SHARE}  .                ${BCLIB_STG} "${DATA_FILTER}")
	(cd ${BCLIB_SRC}     && ${INSTALL_PROGRAM} ${PROGRAM_FILES} ${BCLIB_STG})
	(cd ${BCLIB_SRC}     && ${INSTALL_SCRIPT}  ${SCRIPT_FILES}  ${BCLIB_STG})
	(cd ${BCLIB_SRC}     && ${INSTALL_LIB}     ${LIB_FILES}     ${BCLIB_STG})
	${INSTALL_LIB} ${BCLIB_SRC}/ext/*.so   ${BCLIB_STG}/ext
	${LN} -sf ${LINUXBASE}/usr/${LIBDIR}/libbz2.so.1.0.8 ${BCLIB_STG}/libbz2.so.1.0
# data
	(cd ${WRKSRC}/usr/share && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share)
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/16x16/apps
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/32x32/apps
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps
	${LN} -sf ../../../../pixmaps/bcompare.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/16x16/apps/bcompare.png
	${LN} -sf ../../../../pixmaps/bcomparefull32.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/32x32/apps/bcompare.png
	${LN} -sf ../../../../pixmaps/bcompare.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps/bcompare.png

.include <bsd.port.mk>
