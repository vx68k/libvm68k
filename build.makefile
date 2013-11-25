# -*-Makefile-*- for maintenance jobs
# Copyright (C) 2013 Kaz Nishimura

# Copying and distribution of this file, with or without modification, are
# permitted in any medium without royalty provided the copyright notice and
# this notice are preserved.  This file is offered as-is, without any
# warranty.

# This file SHOULD NOT be contained in the source package.

builddir = build

AUTORECONF = autoreconf
CXX = g++ -std=gnu++11

CXXFLAGS = -g -O2 -fvisibility=hidden -Wall -Wextra

export CXX

all: $(builddir)/Makefile
	cd $(builddir) && $(MAKE) CXXFLAGS='$(CXXFLAGS)' check
	cd $(builddir) && $(MAKE) mostlyclean
	cd $(builddir) && $(MAKE) distcheck

$(builddir)/Makefile: configure
	test -d $(builddir) || mkdir $(builddir)
	srcdir=$$(pwd); \
	cd $(builddir) && $$srcdir/configure

configure: stamp-configure
stamp-configure: configure.ac
	@rm -f $@
	$(AUTORECONF) --install
	touch $@
