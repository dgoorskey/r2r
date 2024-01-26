CC=gcc
CFLAGS=-Wall -Wextra
INSTALLDIR=~/.local/bin

all: b2d b2h d2b d2h h2b h2d

b2d:
	$(CC) $(CFLAGS) r2r.c -o b2d -DBIN='"b2d"' -DIBASE=BASE_BIN -DOBASE=BASE_DEC

b2h:
	$(CC) $(CFLAGS) r2r.c -o b2h -DBIN='"b2h"' -DIBASE=BASE_BIN -DOBASE=BASE_HEX

d2b:
	$(CC) $(CFLAGS) r2r.c -o d2b -DBIN='"d2b"' -DIBASE=BASE_DEC -DOBASE=BASE_BIN

d2h:
	$(CC) $(CFLAGS) r2r.c -o d2h -DBIN='"d2h"' -DIBASE=BASE_DEC -DOBASE=BASE_HEX

h2b:
	$(CC) $(CFLAGS) r2r.c -o h2b -DBIN='"h2b"' -DIBASE=BASE_HEX -DOBASE=BASE_BIN

h2d:
	$(CC) $(CFLAGS) r2r.c -o h2d -DBIN='"h2d"' -DIBASE=BASE_HEX -DOBASE=BASE_DEC

install:
	cp b2d $(INSTALLDIR)
	cp b2h $(INSTALLDIR)
	cp d2b $(INSTALLDIR)
	cp d2h $(INSTALLDIR)
	cp h2b $(INSTALLDIR)
	cp h2d $(INSTALLDIR)

uninstall:
	rm -rf $(INSTALLDIR)/b2d
	rm -rf $(INSTALLDIR)/b2h
	rm -rf $(INSTALLDIR)/d2b
	rm -rf $(INSTALLDIR)/d2h
	rm -rf $(INSTALLDIR)/h2b
	rm -rf $(INSTALLDIR)/h2d

clean:
	rm -rf b2d b2h d2b d2h h2b h2d

