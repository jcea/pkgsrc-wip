# $NetBSD: Makefile,v 1.1 2016/09/12 22:49:23 kamil Exp $

DISTNAME=	lld-3.8.1.src
PKGNAME=	${DISTNAME:S/.src//}
CATEGORIES=	devel
MASTER_SITES=	http://llvm.org/releases/${PKGVERSION_NOREV}/
#MASTER_SITES=	http://llvm.org/pre-releases/3.8.0/rc1/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lld.llvm.org/
COMMENT=	The LLVM Linker
LICENSE=	modified-bsd

CONFIGURE_DIRS=		${WRKDIR}/build
CMAKE_ARG_PATH=		${WRKSRC}

USE_LANGUAGES=		c c++
USE_CMAKE=		yes
GCC_REQD+=		4.8

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DCMAKE_C_COMPILER=${CC:Q}
CMAKE_ARGS+=	-DCMAKE_CXX_COMPILER=${CXX:Q}

post-extract:
	${RUN} mkdir -p ${WRKDIR}/build

DEPENDS+=	llvm-${PKGVERSION_NOREV}{,nb*}:../../lang/llvm
.include "../../lang/llvm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
