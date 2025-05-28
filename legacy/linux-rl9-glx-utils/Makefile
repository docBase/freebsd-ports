PORTNAME=	glx-utils
PORTVERSION=	8.4.0
DISTVERSIONSUFFIX=	-12.20210504git0f9e7d9.el9.0.1
CATEGORIES=	graphics linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	GLX utilities ${LINUX_DIST_VER})
WWW=		http://www.mesa3d.org

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	linux-rl9-libglvnd>0:graphics/linux-rl9-libglvnd

USES=		linux:rl9
LINUX_DIST_VER=	9
USE_LDCONFIG=	yes
USE_LINUX=	base xorglibs
USE_LINUX_RPM=	yes

LIB_DISTNAMES=	${PORTNAME}-${DISTVERSIONFULL}
SRC_DISTFILES=	mesa-demos-${DISTVERSIONFULL}${SRC_SUFX}:SOURCE

CONFLICTS=	linux-c7-glx-utils

.include <bsd.port.mk>
