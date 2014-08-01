# -*-Makefile-*- for maintenance jobs
# Copyright (C) 2013-2014 Kaz Nishimura

# Copying and distribution of this file, with or without modification, are
# permitted in any medium without royalty provided the copyright notice and
# this notice are preserved.  This file is offered as-is, without any
# warranty.

# This file SHOULD NOT be contained in the source package.

topdir := $(if $(WORKSPACE),$(WORKSPACE),$(shell pwd))
srcdir = $(topdir)
builddir = $(topdir)/_build
prefix = $(topdir)/_usr

AUTORECONF = autoreconf
TAR = tar

CFLAGS = -g -O2 -fvisibility=hidden -Wall -Wextra
CXXFLAGS = -g -O2 -fvisibility=hidden -Wall -Wextra

build: clean install dist
	hg status || true

all check uninstall clean distclean: $(builddir)/Makefile
	cd $(builddir) && $(MAKE) CFLAGS='$(CFLAGS)' CXXFLAGS='$(CXXFLAGS)' $@

install: $(builddir)/Makefile
	rm -fr $(prefix)
	cd $(builddir) && $(MAKE) CFLAGS='$(CFLAGS)' CXXFLAGS='$(CXXFLAGS)' $@

dist distcheck: $(builddir)/Makefile
	rm -f $(builddir)/libvm68k-*.tar.*
	cd $(builddir) && $(MAKE) CFLAGS='$(CFLAGS)' CXXFLAGS='$(CXXFLAGS)' $@

$(builddir)/Makefile: configure build.makefile
	mkdir -p $(builddir)
	cd $(builddir) && $(srcdir)/configure --prefix=$(prefix)

configure: stamp-configure
stamp-configure: configure.ac
	@rm -f $@
	$(AUTORECONF) --install
	touch $@

.PHONY: build all check install uninstall dist distcheck clean distclean
