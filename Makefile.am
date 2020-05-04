## Process this file with automake to produce Makefile.in.

ACLOCAL_AMFLAGS = -Im4

EXTRA_DIST = libvm68k.groupproj

SUBDIRS = libltdl libvm68kapi libvm68k test

dist-hook: $(distdir)/SHA256SUMS
	if test -n "$$GPG_USERNAME"; then \
	    gpg -ba -u "$$GPG_USERNAME" $(distdir)/SHA256SUMS; \
	fi

$(distdir)/SHA256SUMS:
	cd $(distdir) && \
	find . -type f ! -name \*SUMS -exec sha256sum {} \; > SHA256SUMS
