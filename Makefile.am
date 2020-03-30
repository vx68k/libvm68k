## Process this file with automake to produce Makefile.in.

# Uses foreign for now.
AUTOMAKE_OPTIONS = foreign

ACLOCAL_AMFLAGS = -Im4

SUBDIRS = config libvm68kapi src test

EXTRA_DIST = libvm68k.groupproj

dist-hook: $(distdir)/SHA256SUMS
	if test -n "$$GPG_USERNAME"; then \
	    gpg -ba -u "$$GPG_USERNAME" $(distdir)/SHA256SUMS; \
	fi

$(distdir)/SHA256SUMS:
	cd $(distdir) && \
	find . -type f ! -name \*SUMS -exec sha256sum {} \; > SHA256SUMS
