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

int wasm_i8x16_load_test() {
   V128_i8 a;
   V128_i8 b;
   a = wasm_v128_const(0,1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15);
   b = wasm_v128_load(&a);
   return 0; 
}

int wasm_i8x16_store_test() {
   V128_i8 a;
   V128_i8 b;
   V128_i8 *c;
   a = wasm_v128_const(0,1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15);
   c = &b;
   wasm_v128_store(c, a);
   return 0; 
}


int wasm_i8x16_splat_test() {
   V128_i8 b;
   int8_t a;
   a = 11;
   b = wasm_i8x16_splat(a);
   return 0;
}


int wasm_i16x8_splat_test() {
   V128_i16 b;
   int16_t a;
   a = 11;
   b = wasm_i16x8_splat(a);
   return 0;
}

int wasm_i32x4_splat_test() {
   V128_i32 b;
   int32_t a;
   a = 11;
   b = wasm_i32x4_splat(a);
   return 0;
}

int wasm_i64x2_splat_test() {
   V128_i64 b;
   int64_t a;
   a = 11;
   b = wasm_i64x2_splat(a);
   return 0;
}


int wasm_f32x4_splat_test() {
   V128_f32 b;
   float a;   
   a= 11.11;
   b = wasm_f32x4_splat(a);
   return 0;
}

int wasm_f64x2_splat_test() {
   V128_f64 b;
   double a;   
   a= 11.11;
   b = wasm_f64x2_splat(a);
   return 0;
}

/*
int wasm_i8x16_extract_lane_s_test() {
    V128_i8 a;
    uint32_t b;
    int32_t c;
    a = wasm_v128_const(0,1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15);
    b = 1;
    c = wasm_i8x16_extract_lane_s(a, b);
    return 0;
}
*/

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
   Ret = wasm_i8x16_load_test();
   Ret = wasm_i8x16_store_test();
   Ret = wasm_i8x16_splat_test();
   Ret = wasm_i16x8_splat_test();
   Ret = wasm_i32x4_splat_test();
   Ret = wasm_i64x2_splat_test();
   Ret = wasm_f32x4_splat_test();
   Ret = wasm_f64x2_splat_test();
//   Ret = wasm_i8x16_extract_lane_s_test();
   Ret = wasm_i8x16_add_test();
   Ret = wasm_i8x16_sub_test();
   return Ret;
}
