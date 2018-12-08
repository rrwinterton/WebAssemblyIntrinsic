PROJECT_NAME = WebAssemblyIntrinsic
EXECUTABLE_NAME = WebAssemblyIntrinsic
COMPILER = clang++
#COMPILER = g++

INCLUDE_DIRS = -I/usr/include/c++/7 -I/usr/include/x86_64-linux-gnu/c++/7
CCFLAGS = -std=c++17 -O0 -emit-llvm --target=wasm32-unknown-unknown
LFLAGS = --target=wasm32 -nostdlib
INCLUDE_DIR = ./
TEST_DIR = ./
SRC_DIR = ./

all: $(EXECUTABLE_NAME)

#-Wl,--no-entry if no main
$(EXECUTABLE_NAME): $(EXECUTABLE_NAME).o
	$(COMPILER) $(LFLAGS) -Wl,--no-entry -o $(EXECUTABLE_NAME).wasm $(EXECUTABLE_NAME).o

$(EXECUTABLE_NAME).o: disasm $(EXECUTABLE_NAME).cpp
	$(COMPILER) $(CCFLAGS) $(INCLUDE_DIRS) -c $(EXECUTABLE_NAME).cpp -o $(EXECUTABLE_NAME).o

disasm:
	$(COMPILER) $(CCFLAGS) $(INCLUDE_DIRS) -c $(EXECUTABLE_NAME).cpp -o $(EXECUTABLE_NAME).bc
	llvm-dis < $(EXECUTABLE_NAME).bc > $(EXECUTABLE_NAME).dis

clean:
	 rm -f $(EXECUTABLE_NAME).o $(EXECUTABLE_NAME).bc $(EXECUTABLE_NAME).dis $(EXECUTABLE_NAME).wasm
