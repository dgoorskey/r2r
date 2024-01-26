import itertools

# constants for bases
# and corresponding letters for the target name (e.g. b2o)
BASES = {
        'BASE_BIN': 'b',
        'BASE_OCT': 'o',
        'BASE_DEC': 'd',
        'BASE_HEX': 'h',
}

def gentargetname(ibase: str, obase: str) -> str:
    """
    generate target name (e.g. b2o) given ibase and obase base constants
    """
    return BASES[ibase] + '2' + BASES[obase]

def gentarget(target: str, ibase: str, obase: str) -> None:
    """
    generate target makefile rule given target name
    and ibase+obase base constants
    """
    print(target + ': r2r.c')
    print(f'\t$(CC) $(CFLAGS) r2r.c -o $@ -DBIN=\'"$@"\' -DIBASE={ibase} -DOBASE={obase}')
    print()

if __name__ == '__main__':

    # print TARGETS makefile variable
    # which has the names of all targets
    print('TARGETS=', end='')
    for c in itertools.permutations(BASES, 2):
        ibase, obase = c
        print(gentargetname(ibase, obase), end=' ')
    print('\n')

    # print makefile rules for all targets
    for c in itertools.permutations(BASES, 2):
        ibase, obase = c
        target = gentargetname(ibase, obase)
        gentarget(target, ibase, obase);

