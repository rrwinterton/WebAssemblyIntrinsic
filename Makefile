PROJECT_NAME = webassemblyintrinsic
COMPILER = clang++
#COMPILER = g++

INCLUDE_DIRS = -I/usr/include/c++/7 -I/usr/include/x86_64-linux-gnu/c++/7

CCFLAGS = -std=c++17 -O0 -emit-llvm --target=wasm32-unknown-unknown
LFLAGS = --target=wasm32 -nostdlib
INCLUDE_DIR = ./
TEST_DIR = ./
SRC_DIR = ./
EXECUTABLE_NAME = WebAssemblyIntrinsic

all: $(EXECUTABLE_NAME)

#-Wl,--no-entry if no main
$(EXECUTABLE_NAME): $(EXECUTABLE_NAME).o
	 $(COMPILER) $(LFLAGS) -Wl,--no-entry -o $(EXECUTABLE_NAME) $(EXECUTABLE_NAME).o

$(EXECUTABLE_NAME).o: $(EXECUTABLE_NAME).cpp
	 $(COMPILER) $(CCFLAGS) -c $(EXECUTABLE_NAME).cpp

disasm:
	$(COMPILER) $(CCFLAGS) $(INCLUDE_DIRS) $(EXECUTABLE_NAME).cpp -c -o $(EXECUTABLE_NAME).bc
	llvm-dis < $(EXECUTABLE_NAME).bc > $(EXECUTABLE_NAME).dis
clean:
	 rm -f $(EXECUTABLE_NAME).o $(EXECUTABLE_NAME).bc $(EXECUTABLE_NAME).dis $(EXECUTABLE_NAME)
