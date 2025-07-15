PORTNAME=	diskcache
DISTVERSIONPREFIX=	v
DISTVERSION=	5.6.4-rc2
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Disk and file backed persistent cache
WWW=		https://grantjenks.com/docs/diskcache/

LICENSE=	APACHE20

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}
TEST_DEPENDS=	${PY_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}django42>0:www/py-django42@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	matias-pizarro
GH_PROJECT=	python-diskcache

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

.include <bsd.port.mk>
