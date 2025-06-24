PORTNAME=	dmidecode
DISTVERSION=	b125744b65641fbb2fad7237305606d21b70a2c2
PORTVERSION=	g20250616.${DISTVERSION}
CATEGORIES=	sysutils
PKGNAMESUFFIX=  -devel
MASTER_SITES=	https://cgit.git.savannah.gnu.org/cgit/${PORTNAME}.git/snapshot/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tool for dumping DMI (SMBIOS) contents in human-readable format
WWW=		https://www.nongnu.org/dmidecode/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 armv6 armv7 i386 riscv64 riscv64sf

#USES=		tar:gz

SUB_FILES=	dmidecode

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

# Additional programs are only built for x86 platforms.
.if ${ARCH} == "amd64" || ${ARCH} == "i386"
PLIST_SUB+=	X86=""
.else
PLIST_SUB+=	X86="@comment "
.endif

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/daily/
	${INSTALL_SCRIPT} ${WRKDIR}/dmidecode ${STAGEDIR}${PREFIX}/etc/periodic/daily/

.include <bsd.port.post.mk>
