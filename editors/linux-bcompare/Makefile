PORTNAME=	bcompare
DISTVERSION=	5.2.0
DISTVERSIONSUFFIX=	.31950
CATEGORIES=	editors devel linux
MASTER_SITES=	https://scootersoftware.com/files/ \
		https://dl.fedoraproject.org/pub/epel/9/Everything/x86_64/Packages/q/:qt6base \
		https://dl.fedoraproject.org/pub/epel/9/Everything/x86_64/Packages/q/:qt6gui \
		https://dl.fedoraproject.org/pub/epel/9/Everything/x86_64/Packages/l/:libb2 \
		https://dl.rockylinux.org/pub/rocky/9/AppStream/x86_64/os/Packages/d/:dblconv
PKGNAMEPREFIX=	linux-
DISTNAME_amd64=	${DISTNAME}.x86_64
EXTRACT_SUFX=	.rpm
DISTFILES=	${DISTNAME_${ARCH}}${EXTRACT_SUFX} \
		qt6-qtbase-6.6.2-1.el9.x86_64.rpm:qt6base \
		qt6-qtbase-gui-6.6.2-1.el9.x86_64.rpm:qt6gui \
		libb2-0.98.1-6.el9.x86_64.rpm:libb2 \
		double-conversion-3.1.5-6.el9.x86_64.rpm:dblconv
EXTRACT_ONLY=	${DISTNAME_${ARCH}}${EXTRACT_SUFX}

MAINTAINER=	matias@pizarro.net
COMMENT=	Compare, sync, and merge files and folders (X11)
WWW=		https://www.scootersoftware.com/

LICENSE=	SCOOTERSOFTWARE
LICENSE_NAME=	Scooter Software License
LICENSE_FILE=	${FILESDIR}/LICENSE.txt
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	upstream only supports amd64

BUILD_DEPENDS=	rpm2cpio:archivers/rpm2cpio

USES=		desktop-file-utils gnome linux:rl9 shared-mime-info shebangfix
USE_LINUX=	base:run dbuslibs:run devtools:build xorglibs:run

SHEBANG_FILES=	${BCLIB_SRC}/bcmount.sh

CONFLICTS_INSTALL=	linux-bcompare4

NO_BUILD=	yes
NO_WRKSUBDIR=	true

DATA_FILTER=	-type d -o -name *\.html -o -name *\.js -o -name *\.css -o \
		-name *\.gif -o -name *\.png -o -name *\.jpg -o -name \
		*\.desktop -o -name mime\.types -o -name README -o -name \
		BCompare.mad -o -name RPM-GPG-KEY-scootersoftware -o -name \
		scootersoftware.repo

LIB_FILES=	libQt6Pas.so.6 lib7z.so libunrar.so libcloudstorage.so.22.0 \
		nosched.so libQt6Core.so.6 libQt6Gui.so.6 libQt6Widgets.so.6 \
		libQt6PrintSupport.so.6 libQt6DBus.so.6 libQt6XcbQpa.so.6 \
		libdouble-conversion.so.3 libb2.so.1
PROGRAM_FILES=	BCompare
SCRIPT_FILES=	bcmount.sh

.include <bsd.port.options.mk>

LIBDIR=		lib64
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-usr_bin_bcompare_amd64

BCLIB_SRC=	${WRKSRC}/usr/${LIBDIR}/beyondcompare
BCLIB_STG=	${STAGEDIR}${PREFIX}/lib/beyondcompare

_QT6_RPMS=	qt6-qtbase-6.6.2-1.el9.x86_64.rpm \
		qt6-qtbase-gui-6.6.2-1.el9.x86_64.rpm \
		libb2-0.98.1-6.el9.x86_64.rpm \
		double-conversion-3.1.5-6.el9.x86_64.rpm

post-extract:
# Extract bundled Qt6 runtime libraries from EPEL/RL9 RPMs
	@${MKDIR} ${WRKDIR}/qt6tmp
.for rpm in ${_QT6_RPMS}
	@cd ${WRKDIR}/qt6tmp && rpm2cpio < ${DISTDIR}/${rpm} | ${CPIO} -id 2>/dev/null
.endfor
	@${CP} ${WRKDIR}/qt6tmp/usr/${LIBDIR}/libQt6Core.so.6* ${BCLIB_SRC}/
	@${CP} ${WRKDIR}/qt6tmp/usr/${LIBDIR}/libQt6DBus.so.6* ${BCLIB_SRC}/
	@${CP} ${WRKDIR}/qt6tmp/usr/${LIBDIR}/libQt6Gui.so.6* ${BCLIB_SRC}/
	@${CP} ${WRKDIR}/qt6tmp/usr/${LIBDIR}/libQt6PrintSupport.so.6* ${BCLIB_SRC}/
	@${CP} ${WRKDIR}/qt6tmp/usr/${LIBDIR}/libQt6Widgets.so.6* ${BCLIB_SRC}/
	@${CP} ${WRKDIR}/qt6tmp/usr/${LIBDIR}/libQt6XcbQpa.so.6* ${BCLIB_SRC}/
	@${CP} ${WRKDIR}/qt6tmp/usr/${LIBDIR}/libdouble-conversion.so.3* ${BCLIB_SRC}/
	@${CP} ${WRKDIR}/qt6tmp/usr/${LIBDIR}/libb2.so.1* ${BCLIB_SRC}/
	@${RM} -r ${WRKDIR}/qt6tmp

pre-install:
	${LINUXBASE}/usr/bin/gcc --sysroot=${LINUXBASE} -Wall -fPIC -shared \
		${FILESDIR}/nosched.c -ldl -o ${BCLIB_SRC}/nosched.so

do-install:
# bin
	${INSTALL_SCRIPT} ${WRKSRC}/usr/bin/bcompare ${STAGEDIR}${PREFIX}/bin
# lib
	(cd ${BCLIB_SRC} && ${COPYTREE_SHARE}  .                ${BCLIB_STG} "${DATA_FILTER}")
	(cd ${BCLIB_SRC} && ${INSTALL_PROGRAM} ${PROGRAM_FILES} ${BCLIB_STG})
	(cd ${BCLIB_SRC} && ${INSTALL_SCRIPT}  ${SCRIPT_FILES}  ${BCLIB_STG})
	(cd ${BCLIB_SRC} && ${INSTALL_LIB}     ${LIB_FILES}     ${BCLIB_STG})
	${INSTALL_LIB} ${BCLIB_SRC}/ext/*.so   ${BCLIB_STG}/ext
	${LN} -sf ${LINUXBASE}/usr/${LIBDIR}/libbz2.so.1 ${BCLIB_STG}/libbz2.so.1.0
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
