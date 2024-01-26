CC=gcc
CFLAGS=-Wall -Wextra
INSTALLDIR=~/.local/bin

all: b2d h2d d2b d2h

b2d:
	$(CC) $(CFLAGS) b2d.c -o b2d

h2d:
	$(CC) $(CFLAGS) h2d.c -o h2d

d2b:
	$(CC) $(CFLAGS) d2b.c -o d2b

d2h:
	$(CC) $(CFLAGS) d2h.c -o d2h

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

