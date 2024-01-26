import itertools

BASES = {
        'BASE_BIN': 'b',
        'BASE_OCT': 'o',
        'BASE_DEC': 'd',
        'BASE_HEX': 'h',
}

def gentargetname(ibase: str, obase: str) -> str:
    return BASES[ibase] + '2' + BASES[obase]

def gentarget(target: str, ibase: str, obase: str) -> None:

    print(target + ': r2r.c')
    print(f'\t$(CC) $(CFLAGS) r2r.c -o $@ -DBIN=\'"$@"\' -DIBASE={ibase} -DOBASE={obase}')
    print()

if __name__ == '__main__':
    print('TARGETS=', end='')
    for c in itertools.combinations(BASES, 2):
        ibase, obase = c
        print(gentargetname(ibase, obase), end=' ')
        print(gentargetname(obase, ibase), end=' ')
    print('\n')

    for c in itertools.combinations(BASES, 2):
        ibase, obase = c
        target = gentargetname(ibase, obase)
        gentarget(target, ibase, obase);

        obase, ibase = c
        target = gentargetname(ibase, obase)
        gentarget(target, ibase, obase);

