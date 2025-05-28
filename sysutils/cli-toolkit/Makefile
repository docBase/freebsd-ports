PORTNAME=	cli-toolkit
PORTVERSION=	0.1.1
CATEGORIES=	sysutils
MASTER_SITES=	GH

MAINTAINER=	matias@pizarro.net
COMMENT=	A collection of desktop utilities
WWW=		https://github.com/matias-pizarro/sysutils/

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	matias-pizarro

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/* ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
