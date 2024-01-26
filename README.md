# r2r

tools for converting between binary, decimal, and hex numbers.

each binary performs one type of conversion.

binaries convert values from stdin.
each value's result is printed on its own line.

underscores (`_`) are ignored.
for hex, both uppercase and lowercase letters work.

## building & installing

1. build:
   1. (optional) modify the makefile's build targets.
      you can use `gentargets.py` to generate all possible base combinations,
      which you can paste into the makefile.
   2. run `make`
2. install:
   1. (optional) set the makefile's `INSTALLDIR` variable according to your system.
      this is the path where the binaries will be copied.
   2. run `make install`

you can run `make uninstall` to delete the binaries copied by `make install`.

