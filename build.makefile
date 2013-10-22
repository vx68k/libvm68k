# -*-Makefile-*- for maintenance jobs
# Copyright (C) 2013  Kaz Nishimura

# Copying and distribution of this file, with or without modification, are
# permitted in any medium without royalty provided the copyright notice and
# this notice are preserved.  This file is offered as-is, without any
# warranty.

# This file SHOULD NOT be contained in the source package.

builddir = build

AUTORECONF = autoreconf

CFLAGS = -g -O2 -Wall -Wextra
CXXFLAGS = $(CFLAGS)

all: $(builddir)/Makefile
	cd $(builddir) && $(MAKE) check
	cd $(builddir) && $(MAKE) distcheck

$(builddir)/Makefile: configure
	test -d $(builddir) || mkdir $(builddir)
	srcdir=$$(pwd); \
	cd $(builddir) && \
	  CFLAGS='$(CFLAGS)' CXXFLAGS='$(CXXFLAGS)' $$srcdir/configure

configure: stamp-configure
stamp-configure: configure.ac
	@rm -f $@
	$(AUTORECONF) --install
	touch $@
