## $ReOpenLDAP$
## Copyright 1992-2017 ReOpenLDAP AUTHORS: please see AUTHORS file.
## All rights reserved.
##
## This file is part of ReOpenLDAP.
##
## Redistribution and use in source and binary forms, with or without
## modification, are permitted only as authorized by the OpenLDAP
## Public License.
##
## A copy of this license is available in the file LICENSE in the
## top-level directory of the distribution or, alternatively, at
## <http://www.OpenLDAP.org/license.html>.
##

pkginclude_HEADERS = lber.h ldap_cdefs.h ldap.h ldap_schema.h \
	ldap_utf8.h ldif.h slapi-plugin.h lber_types.h ldap_features.h

noinst_HEADERS = ac/alloca.h ac/bytes.h ac/crypt.h ac/ctype.h \
	ac/dirent.h ac/errno.h ac/fdset.h ac/localize.h ac/param.h \
	ac/regex.h ac/setproctitle.h ac/signal.h ac/socket.h \
	ac/stdarg.h ac/stdlib.h ac/string.h ac/sysexits.h ac/syslog.h \
	ac/termios.h ac/time.h ac/unistd.h ac/wait.h avl.h \
	getopt-compat.h lber_hipagut.h lber_pvt.h ldap_defaults.h \
	ldap_int_thread.h ldap_log.h ldap_pvt.h ldap_pvt_thread.h \
	ldap_pvt_uc.h ldap_queue.h ldap_rq.h lutil.h lutil_hash.h \
	lutil_ldap.h lutil_lockf.h lutil_md5.h lutil_meter.h \
	lutil_sha1.h reldap.h rewrite.h sysexits-compat.h

BUILT_SOURCES = ldap_dirs.h
CLEANFILES = ldap_dirs.h
EXTRA_DIST = ldap_dirs.h.in

ldap_dirs.h: $(srcdir)/ldap_dirs.h.in Makefile
	@if $(AM_V_P); then set -x; else echo "  GEN      $@"; fi; \
	$(RM) $@ && \
	echo "/* Generated from $< on `date --rfc-3339=seconds --utc` */" > $@ && \
	$(FIXUP_DIST) $< | $(FIXUP_DIRS) >> $@
