#include <stdio.h>
#if 0 // Make clang happy
#include <string>
#include <cstdlib>
#endif
#include "WebAssemblyIntrinsic.h"

//using namespace std;


//simple tests

//simple wasm_i8x16_const
int wasm_i8x16_const_test() {
   V128_i8 a;
   a = wasm_v128_const(0,1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15);
   return 0;
}

//simple wasm_i8x16_add
int wasm_i8x16_add_test() {
   V128_i8 a, b, c;
   a = wasm_v128_const(0,1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15);
   b = wasm_v128_const(1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15,16);   
   c = wasm_i8x16_add(a,b);
   return 0;
}

//simple wasm_i8x16_sub
int wasm_i8x16_sub_test() {
   V128_i8 a, b, c;
   a = wasm_v128_const(0,1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15);
   b = wasm_v128_const(1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15,16);   
   c = wasm_i8x16_sub(a,b);
   return 0;
}

//main
int main(int argc, char *argv[]) {
   int Ret;
   Ret = wasm_i8x16_const_test();
   Ret = wasm_i8x16_add_test();
   Ret = wasm_i8x16_sub_test();
   return Ret;
}
