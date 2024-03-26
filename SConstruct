import os

from pathlib import Path

assembly_file_action = Action(
    '$CC -target $CLANG_ARCH $CCFLAGS $CPPFLAGS $_CPPDEFFLAGS $_CPPINCFLAGS -o $TARGET -S $SOURCES',
    # 'C to ASM: $TARGET'
)

assembly_file_builder = Builder(
    action=assembly_file_action,
    suffix='.s',
    src_suffix='.c',
    single_source = True
)

env = DefaultEnvironment(    
    ENV={
        'PATH': os.environ['PATH'],
    },

    BUILDERS={
        'AssemblyFile': assembly_file_builder
    },

    CDM_COCAS_PATH=os.getenv('CDM_COCAS_PATH', 'cocas'),
    CDM_CLANG_PATH=os.getenv('CDM_CLANG_PATH', 'clang'),

    COMPILATIONDB_USE_ABSPATH=True,

    COCAS_ARCH='cdm16e',
    CLANG_ARCH='cdm',
    
    AS='$CDM_COCAS_PATH',
    ASCOM='$AS -t $COCAS_ARCH $ASFLAGS -o $TARGET -c $SOURCES',
    ASFLAGS='',
    # ASCOMSTR = "Assembling $TARGET",

    LINK='$AS',
    LINKCOM='$LINK -t $COCAS_ARCH $LINKFLAGS -o $TARGET $SOURCES',
    LINKFLAGS='',
    # LINKCOMSTR = "Linking $TARGET",

    AR='$AS',
    ARCOM='$AR -t $COCAS_ARCH $ARFLAGS -o $TARGET -m $SOURCES',
    ARFLAGS='',
    # ARCOMSTR = "Making static library $TARGET",

    CC='$CDM_CLANG_PATH',
    CCCOM='$CC -target $CLANG_ARCH $CCFLAGS $CPPFLAGS $_CPPDEFFLAGS $_CPPINCFLAGS -o $TARGET -c $SOURCES',
    CCFLAGS='-O3 -Wall',
    CPPFLAGS='',
    # -mllvm -inline-threshold=16 -mllvm -unroll-threshold=16

    CPPPATH=['#/include'],
    CPPDEFINES=[],

    CPPDEFPREFIX='-D',
    CPPDEFSUFFIX='',

    INCPREFIX='-I',
    INCSUFFIX='',

    PROGPREFIX='',
    PROGSUFFIX='.img',

    LIBPREFIX='',
    LIBSUFFIX='.lib',

    OBJPREFIX='',
    OBJSUFFIX='.obj'
    )

# env.Tool('compilation_db')
# env.CompilationDatabase('./build/compile_commands.json')

SConscript('src/SConscript', variant_dir='build', duplicate=False, exports='env')
