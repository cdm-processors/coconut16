import os

env = DefaultEnvironment(
    ENV={
        'PATH': os.environ['PATH']
    },
    
    AS='cocas',
    ASCOM='$AS $ASFLAGS -c -o $TARGET $SOURCES',
    ASFLAGS='',

    LINK='$AS',
    LINKCOM='$LINK $LINKFLAGS -o $TARGET $SOURCES',
    LINKFLAGS='',

    AR='$AS',
    ARCOM='$AR $ARFLAGS -o $TARGET -m $SOURCES',
    ARFLAGS='',

    PROGPREFIX='',
    PROGSUFFIX='.img',

    LIBPREFIX='',
    LIBSUFFIX='.lib',

    OBJPREFIX='',
    OBJSUFFIX='.obj'
    )

SConscript('src/SConscript', variant_dir='build', duplicate=False)
