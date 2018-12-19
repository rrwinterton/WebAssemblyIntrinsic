PROJECT_NAME = WebAssemblyIntrinsic
EXECUTABLE_NAME = WebAssemblyIntrinsic
COMPILER = clang++
#COMPILER = g++

INCLUDE_DIRS = -I/usr/include/c++/7 -I/usr/include/x86_64-linux-gnu/c++/7
CCFLAGS = -std=c++17 -O0 -emit-llvm --target=wasm32-unknown-unknown -mcpu=bleeding-edge -mllvm -wasm-enable-unimplemented-simd
LFLAGS = --target=wasm32 -nostdlib -Wl,--no-entry,--export-dynamic
WOBJDFLAGS = --disassemble
INCLUDE_DIR = ./
TEST_DIR = ./
SRC_DIR = ./

all: $(EXECUTABLE_NAME)

#-Wl,--no-entry if no main
$(EXECUTABLE_NAME): $(EXECUTABLE_NAME).o
	$(COMPILER) $(LFLAGS) -o $(EXECUTABLE_NAME).wasm $(EXECUTABLE_NAME).o

$(EXECUTABLE_NAME).o: disasm $(EXECUTABLE_NAME).cpp
	$(COMPILER) $(CCFLAGS) $(INCLUDE_DIRS) -c $(EXECUTABLE_NAME).cpp -o $(EXECUTABLE_NAME).o
#	./wasm-objdump $(WOBJDFLAGS) $(EXECUTABLE_NAME).wasm > $(EXECUTABLE_NAME).wdis
#	llvm-dis < $(EXECUTABLE_NAME).wasm > $(EXECUTABLE_NAME).wdis

disasm:
	$(COMPILER) $(CCFLAGS) $(INCLUDE_DIRS) -c $(EXECUTABLE_NAME).cpp -o $(EXECUTABLE_NAME).bc
	llvm-dis < $(EXECUTABLE_NAME).bc > $(EXECUTABLE_NAME).irdis

clean:
	 rm -f $(EXECUTABLE_NAME).o $(EXECUTABLE_NAME).bc $(EXECUTABLE_NAME).dis $(EXECUTABLE_NAME).wasm
