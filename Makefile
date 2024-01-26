CC=gcc
CFLAGS=-Wall -Wextra
INSTALLDIR=~/.local/bin

#TARGETS=b2d b2h b2o d2b d2o d2h o2b o2d o2h h2b h2d h2o
#TARGETS=b2d b2h d2b d2h h2b h2d o2b b2o
TARGETS=b2o o2b b2d d2b b2h h2b o2d d2o o2h h2o d2h h2d

all: $(TARGETS)

b2o: r2r.c
	$(CC) $(CFLAGS) r2r.c -o $@ -DBIN='"$@"' -DIBASE=BASE_BIN -DOBASE=BASE_OCT

o2b: r2r.c
	$(CC) $(CFLAGS) r2r.c -o $@ -DBIN='"$@"' -DIBASE=BASE_OCT -DOBASE=BASE_BIN

b2d: r2r.c
	$(CC) $(CFLAGS) r2r.c -o $@ -DBIN='"$@"' -DIBASE=BASE_BIN -DOBASE=BASE_DEC

d2b: r2r.c
	$(CC) $(CFLAGS) r2r.c -o $@ -DBIN='"$@"' -DIBASE=BASE_DEC -DOBASE=BASE_BIN

b2h: r2r.c
	$(CC) $(CFLAGS) r2r.c -o $@ -DBIN='"$@"' -DIBASE=BASE_BIN -DOBASE=BASE_HEX

h2b: r2r.c
	$(CC) $(CFLAGS) r2r.c -o $@ -DBIN='"$@"' -DIBASE=BASE_HEX -DOBASE=BASE_BIN

o2d: r2r.c
	$(CC) $(CFLAGS) r2r.c -o $@ -DBIN='"$@"' -DIBASE=BASE_OCT -DOBASE=BASE_DEC

d2o: r2r.c
	$(CC) $(CFLAGS) r2r.c -o $@ -DBIN='"$@"' -DIBASE=BASE_DEC -DOBASE=BASE_OCT

o2h: r2r.c
	$(CC) $(CFLAGS) r2r.c -o $@ -DBIN='"$@"' -DIBASE=BASE_OCT -DOBASE=BASE_HEX

h2o: r2r.c
	$(CC) $(CFLAGS) r2r.c -o $@ -DBIN='"$@"' -DIBASE=BASE_HEX -DOBASE=BASE_OCT

d2h: r2r.c
	$(CC) $(CFLAGS) r2r.c -o $@ -DBIN='"$@"' -DIBASE=BASE_DEC -DOBASE=BASE_HEX

h2d: r2r.c
	$(CC) $(CFLAGS) r2r.c -o $@ -DBIN='"$@"' -DIBASE=BASE_HEX -DOBASE=BASE_DEC

install:
	cp $(TARGETS) $(INSTALLDIR)

uninstall:
	rm -rf $(addprefix $(INSTALLDIR), $(TARGETS))

clean:
	rm -rf $(TARGETS)

