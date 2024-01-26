CC=gcc
CFLAGS=-std=c89 -D_POSIX_C_SOURCE=200809L -Wall -Wextra -Wpedantic -g
INSTALLDIR=~/.local/bin

TARGETS=b2o b2d b2h o2b o2d o2h d2b d2o d2h h2b h2o h2d

all: $(TARGETS)

b2o: r2r.c
	$(CC) $(CFLAGS) r2r.c -o $@ -DBIN='"$@"' -DIBASE=BASE_BIN -DOBASE=BASE_OCT

b2d: r2r.c
	$(CC) $(CFLAGS) r2r.c -o $@ -DBIN='"$@"' -DIBASE=BASE_BIN -DOBASE=BASE_DEC

b2h: r2r.c
	$(CC) $(CFLAGS) r2r.c -o $@ -DBIN='"$@"' -DIBASE=BASE_BIN -DOBASE=BASE_HEX

o2b: r2r.c
	$(CC) $(CFLAGS) r2r.c -o $@ -DBIN='"$@"' -DIBASE=BASE_OCT -DOBASE=BASE_BIN

o2d: r2r.c
	$(CC) $(CFLAGS) r2r.c -o $@ -DBIN='"$@"' -DIBASE=BASE_OCT -DOBASE=BASE_DEC

o2h: r2r.c
	$(CC) $(CFLAGS) r2r.c -o $@ -DBIN='"$@"' -DIBASE=BASE_OCT -DOBASE=BASE_HEX

d2b: r2r.c
	$(CC) $(CFLAGS) r2r.c -o $@ -DBIN='"$@"' -DIBASE=BASE_DEC -DOBASE=BASE_BIN

d2o: r2r.c
	$(CC) $(CFLAGS) r2r.c -o $@ -DBIN='"$@"' -DIBASE=BASE_DEC -DOBASE=BASE_OCT

d2h: r2r.c
	$(CC) $(CFLAGS) r2r.c -o $@ -DBIN='"$@"' -DIBASE=BASE_DEC -DOBASE=BASE_HEX

h2b: r2r.c
	$(CC) $(CFLAGS) r2r.c -o $@ -DBIN='"$@"' -DIBASE=BASE_HEX -DOBASE=BASE_BIN

h2o: r2r.c
	$(CC) $(CFLAGS) r2r.c -o $@ -DBIN='"$@"' -DIBASE=BASE_HEX -DOBASE=BASE_OCT

h2d: r2r.c
	$(CC) $(CFLAGS) r2r.c -o $@ -DBIN='"$@"' -DIBASE=BASE_HEX -DOBASE=BASE_DEC

install:
	cp $(TARGETS) $(INSTALLDIR)

uninstall:
	rm -rf $(addprefix $(INSTALLDIR), $(TARGETS))

clean:
	rm -rf $(TARGETS)

