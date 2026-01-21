PORTNAME=	XnViewMP
PORTVERSION=	1.9.10
CATEGORIES=	graphics linux
MASTER_SITES=	https://download.xnview.com/
PKGNAMEPREFIX=	linux-
DISTNAME=	XnViewMP-linux-x64

MAINTAINER=	matias@pizarro.net
COMMENT=	Powerful cross-platform image viewer and converter
WWW=		https://www.xnview.com/en/XnViewMP/

LICENSE=	XnViewMP
LICENSE_NAME=	XnViewMP End User License Agreement
LICENSE_FILE=	${FILESDIR}/LICENSE
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	upstream only provides 64-bit Linux binaries

USES=		desktop-file-utils gnome linux tar:tgz
USE_LINUX=	alsa-plugins-pulseaudio dbuslibs dri fontconfig gtk3 \
		libxkbcommon opus pulseaudio-libs xorglibs

DESKTOP_ENTRIES=	"XnViewMP" \
			"Image Viewer and Converter" \
			"${DATADIR}/xnview.png" \
			"XnViewMP" \
			"Graphics;Viewer;Photography;" \
			true

NO_BUILD=	yes
SUB_FILES=	XnViewMP

WRKSRC=		${WRKDIR}/XnView

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/XnViewMP ${STAGEDIR}${PREFIX}/bin/XnViewMP
.for res in 16 32 48 64 128 256
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${res}x${res}/apps
	${INSTALL_DATA} ${WRKSRC}/xnview.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${res}x${res}/apps/XnViewMP.png 2>/dev/null || true
.endfor

.include <bsd.port.mk>
