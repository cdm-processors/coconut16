# Coconut-16
Educational system based on CdM-16e processor. 

## Building
This project uses `SCons` as build system.
To build project run `scons`. It will put files to `build` directory.

Couple useful commands:
+ Run build with `n` parallel jobs
  
    `scons -j n`

+ Clean build files
  
    `scons -c`

## Setting up development environment

### Prerequisites
+ Python
+ VS Code
+ Logisim

### Install Logisim libraries
Put following libraries in `logisim/libs/`:
+ `cdm16e.circ`
+ `logisim-banked-memory-0.2.0.jar`
+ `logisim-uart.jar`

### Setup build system and compilers
+ Install `SCons` build system

    `pip install scons`
+ Install `cdm-devkit` 
  
    `pip install cdm-devkit`
+ Optionally, set `CDM_COCAS_PATH` environment variable to `cocas` executable, otherwise it will be taken from `PATH`
+ Build [this](https://github.com/leadpogrommer/llvm-project-cdm/tree/backend/cdm) C compiler, note that it is developed in `backend/cdm` branch
+ Set `CDM_CLANG_PATH` environment variable to `bin/clang` executable of recently built compiler, otherwise `clang` will be taken from `PATH`

### Setup VS Code
+ Open project folder in VS Code.

+ Create `.vscode/settings.json` file with following text
    ```json
    {
        "python.analysis.ignore": [
            "SConstruct",
            "src/"
        ],
        "C_Cpp.clang_format_fallbackStyle": "{ BasedOnStyle: Google, IndentWidth: 4 }",
        "C_Cpp.default.systemIncludePath" : ["${workspaceFolder}/include/"],
        "files.associations": {
            "*.s": "cdm16-assembly"
        }
    }
    ```
    It will:

    + Disable Python error checking for `SCons` build files
    + Setup formatting style
    + Setup include paths for VS Code analysis
    + Associate `.s` files with `CdM-16 Assembly`

+ Additionaly, create `.vscode/c_cpp_properties.json` file with following text:
    ```json
    {
        "configurations": [
            {
                "name": "Coconut-16",
                "compilerPath": "<path to clang>",
                "cStandard": "c11",
                "intelliSenseMode": "clang-x64"
            }
        ],
        "version": 4
    }
    ```

    Fill in `compilerPath` with path to your system's `clang`, note that our proprietary `clang` may not work with it, so you need `clang` from official LLVM distrubution.

### Debugging in VS Code
+ Install proprietary extension

+ Add following launch configuration to `launch.json`
    ```json
    {
        "name": "Debug Coconut-16",
        "type": "coconut",
        "request": "launch",
        "address": "ws://localhost:7001",
        "target": "coconut16",
        "debugInfos": {
            "0": "${workspaceFolder}/build/bootloader.dbg.json",
            "1": "${workspaceFolder}/build/loader.dbg.json"
        }
    }
    ```

### Running `SCons` before starting debug
+ Create new task in `tasks.json`
    ```json
    {
        "label": "runScons",
        "type": "shell",
        "command": "scons"
    }
    ```

+ Add following property to launch configuration
    ```json
    "preLaunchTask": "runScons"
    ```
