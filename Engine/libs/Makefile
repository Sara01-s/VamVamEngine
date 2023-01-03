.PHONY: all clean cleanall debug

all:
	$(MAKE) -C tinyPTC
	$(MAKE) -C picoPNG

clean:
	$(MAKE) -C tinyPTC clean
	$(MAKE) -C picoPNG clean

cleanall:
	$(MAKE) -C tinyPTC cleanall
	$(MAKE) -C picoPNG cleanall
 
debug:
	$(MAKE) -C tinyPTC DEBUG=1
	$(MAKE) -C picoPNG DEBUG=1
	