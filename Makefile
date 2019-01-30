PROJECT_NAME = WebAssemblyIntrinsic
EXECUTABLE_NAME = WebAssemblyIntrinsic

CXX = emcc
CXXFLAGS = -s FETCH=1 -s WASM=2 -O3 -s SIMD=1 -s ASSERTIONS=1

D8 = d8
D8FLAGS = --experimental-wasm-simd --no-wasm-async-compilation

SRCS = WebAssemblyIntrinsic.cpp
HEADERS = WebAssemblyIntrinsic.h WebAssemblyIntrinsicTests.h

all: $(EXECUTABLE_NAME).js $(EXECUTABLE_NAME).wasm

$(EXECUTABLE_NAME).js $(EXECUTABLE_NAME).wasm: $(SRCS) $(HEADERS)
	export EMCC_WASM_BACKEND=2
	$(CXX) --bind $(SRCS) $(CXXFLAGS) -o $(EXECUTABLE_NAME).js

run: $(EXECUTABLE_NAME).js $(EXECUTABLE_NAME).wasm
	$(D8) $(D8FLAGS) $(EXECUTABLE_NAME).js

clean:
	 rm -f $(EXECUTABLE_NAME).js $(EXECUTABLE_NAME).wasm

.PHONY: all run clean
