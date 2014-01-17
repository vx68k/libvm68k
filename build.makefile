# -*-Makefile-*- for maintenance jobs
# Copyright (C) 2013-2014 Kaz Nishimura

# Copying and distribution of this file, with or without modification, are
# permitted in any medium without royalty provided the copyright notice and
# this notice are preserved.  This file is offered as-is, without any
# warranty.

# This file SHOULD NOT be contained in the source package.

builddir = build
prefix = /tmp/vx68k

AUTORECONF = autoreconf
CC = gcc -std=gnu99
CXX = g++ -std=gnu++11
TAR = tar

CFLAGS = -g -O2 -fvisibility=hidden -Wall -Wextra
CXXFLAGS = -g -O2 -fvisibility=hidden -Wall -Wextra

export CC CXX CFLAGS CXXFLAGS

build: clean check image dist
	hg status || true

all check clean dist distcheck: $(builddir)/Makefile
	cd $(builddir) && $(MAKE) $@

install: $(builddir)/Makefile
	cd $(builddir) && $(MAKE) DESTDIR=$$(pwd)/root $@

image: install
	@rm -f $(builddir)/libvm68k-image.tar.gz
	(cd $(builddir)/root && $(TAR) -c -f - .) | \
	  gzip -9c > $(builddir)/libvm68k-image.tar.gz
	rm -rf $(builddir)/root

$(builddir)/Makefile: configure build.makefile
	test -d $(builddir) || mkdir $(builddir)
	rm -f $(builddir)/libvm68k-*.tar.*
	srcdir=$$(pwd); \
	cd $(builddir) && $$srcdir/configure --prefix=$(prefix)

configure: stamp-configure
stamp-configure: configure.ac
	@rm -f $@
	$(AUTORECONF) --install
	touch $@

.PHONY: build all check clean dist distcheck install image
