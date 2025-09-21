
CWD = $(CURDIR)

PONY_VER = 0.32.0
PONY	 = ponyc-$(PONY_VER)
PONY_GZ  = $(PONY).tar.gz

PROC_NUM = $(shell grep proc /proc/cpuinfo|wc -l)

build: $(PONY)/README.md
	cd $(PONY) ;\
	$(MAKE) distclean ;\
	$(MAKE) LLVM_CONFIG=llvm-config-3.9 prefix=$(CWD)/_install static=true -j$(PROC_NUM) ;\
	$(MAKE) install

src: $(PONY)/README.md
$(PONY)/README.md: $(PONY_GZ)
	tar zx < $< && touch $@

gz: $(PONY_GZ)
$(PONY_GZ):
	wget -c -O $@ https://github.com/ponylang/ponyc/archive/$(PONY_VER).tar.gz
