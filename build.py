# ========================  IMPORTS  ========================
import os
import sys
from colored import fg, attr

# ========================  VARIABLES   ========================
CC = "g++"
CPP_VERSION = "-std=c++17"

BIN = "bin"
SRC = "src"
INCLUDE = "include"
OBJ = "obj"
APP_NAME = "Application"

SFML_COMPILE_FLAGS = "-lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio"

CFLAGS = "-O2 " + SFML_COMPILE_FLAGS


# ========================  HELPER FUNCTIONS  ========================
def build_directory(parts):
    directory = ""
    for part in parts:
        directory += part + "/"
    directory = directory[0:len(directory) - 1]
    return directory


# ========================  FILE DICTIONARY  ========================
files = {

    "main"      : build_directory([SRC, "main.cpp"]),
    "Game"      : build_directory([SRC, "Game.cpp"]),
    "State"     : build_directory([SRC, "State.cpp"]),
    "GameState" : build_directory([SRC, "States", "GameState.cpp"])

}


# ========================  COMPILE FUNCTION  ========================
def compile():
    for key, val in files.items():
        string_to_run = ""

        string_to_run += CC + " "
        string_to_run += "-c "
        string_to_run += val + " "
        string_to_run += "-o "
        string_to_run += build_directory([OBJ, key + ".o"]) + " "
        string_to_run += "-I" + INCLUDE + " "
        string_to_run += CPP_VERSION

        print(f"{fg('yellow')}Compiling " + val + "...")
        print(f"{fg('white')}" + string_to_run)

        if (os.system(string_to_run) != 0):
            print(f"{fg('red')}Did not compile succesfully ❌")
            sys.exit()

        print(f"{fg('green')}Compiled", val, "✅")
        print("\n" * 1)


# ========================  LINK FUNCTION  ========================
def link():
    print(f"{fg('yellow')}Linking everything...")

    string_to_run = ""
    string_to_run += CC + " "

    for key, val in files.items():
        string_to_run += build_directory([OBJ, key]) + ".o "

    string_to_run += "-o "
    string_to_run += build_directory([BIN, APP_NAME]) + " "
    string_to_run += CFLAGS

    print(f"{fg('white')}" + string_to_run)

    if (os.system(string_to_run) != 0):
        print(f"{fg('red')}Did not link succesfully ❌")
        sys.exit()

    print(f"{fg('green')}Application ready at", build_directory([BIN, APP_NAME]), "!!!! ✅")


# ========================  MAIN FUNCTION  ========================
def main():
    if len(sys.argv) == 1:
        print('\033[1m{}\033[0m'.format('Compiling and linking...\n'))
        # print("Compiling and linking...\n")
        compile()
        link()
    else:
        if sys.argv[1] == "compile":
            print('\033[1m{}\033[0m'.format('Compiling...\n'))
            compile()
        elif sys.argv[1] == "link":
            print('\033[1m{}\033[0m'.format('Linking...\n'))
            link()



# ========================  FUNCTION CALLS  ========================
if __name__ == "__main__":
    main()
    print(f"{attr('reset')}")
