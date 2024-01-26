CC=gcc
CFLAGS=-Wall -Wextra
INSTALLDIR=~/.local/bin

all: b2d h2d d2b d2h

b2d:
	$(CC) $(CFLAGS) r2r.c -o b2d -DBIN='"b2d"' -DIBASE=BASE_BIN -DOBASE=BASE_DEC

h2d:
	$(CC) $(CFLAGS) r2r.c -o h2d -DBIN='"h2d"' -DIBASE=BASE_HEX -DOBASE=BASE_DEC

d2b:
	$(CC) $(CFLAGS) r2r.c -o d2b -DBIN='"d2b"' -DIBASE=BASE_DEC -DOBASE=BASE_BIN

d2h:
	$(CC) $(CFLAGS) r2r.c -o d2h -DBIN='"d2h"' -DIBASE=BASE_DEC -DOBASE=BASE_HEX

install:
	cp b2d $(INSTALLDIR)
	cp h2d $(INSTALLDIR)
	cp d2b $(INSTALLDIR)
	cp d2h $(INSTALLDIR)

uninstall:
	rm -rf $(INSTALLDIR)/b2d
	rm -rf $(INSTALLDIR)/h2d
	rm -rf $(INSTALLDIR)/d2b
	rm -rf $(INSTALLDIR)/d2h

clean:
	rm -rf b2d h2d d2b d2h

