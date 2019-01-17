PROJECT_NAME = WebAssemblyIntrinsic
EXECUTABLE_NAME = WebAssemblyIntrinsic

CXX = emcc
CXXFLAGS = -s WASM=2 -s SIMD=1 -std=c++17 -O2

D8 = d8
D8FLAGS = --experimental-wasm-simd --no-wasm-async-compilation

SRCS = WebAssemblyIntrinsic.cpp
HEADERS = WebAssemblyIntrinsic.h WebAssemblyIntrinsicTests.h


all: $(EXECUTABLE_NAME).js $(EXECUTABLE_NAME).wasm

$(EXECUTABLE_NAME).js $(EXECUTABLE_NAME).wasm: $(SRCS) $(HEADERS)
	$(CXX) $(SRCS) $(CXXFLAGS) -o $(EXECUTABLE_NAME).js

run: $(EXECUTABLE_NAME).js $(EXECUTABLE_NAME).wasm
	$(D8) $(D8FLAGS) $(EXECUTABLE_NAME).js

clean:
	 rm -f $(EXECUTABLE_NAME).js $(EXECUTABLE_NAME).wasm

.PHONY: all run clean
