# $NetBSD$

DISTNAME=	netmiko-0.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils net
MASTER_SITES=	-https://github.com/ktbyers/${PKGBASE}/archive/v${PKGVERSION_NOREV}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ktbyers/${PKGBASE}
COMMENT=	Multi-vendor library to simplify Paramiko use
LICENSE=	mit

USE_LANGUAGES=	# none
PLIST_SUBST+=	PYVERSUFFIX=${PYVERSUFFIX}

DEPENDS+=	${PYPKGPREFIX}-paramiko>=1.13.0:../../security/py-paramiko

PYDISTUTILSPKG=	yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
