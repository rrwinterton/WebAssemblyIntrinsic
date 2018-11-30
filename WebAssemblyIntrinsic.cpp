#include <stdio.h>

#if 0 // Make clang happy
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;
#endif

#include "WebAssemblyIntrinsic.h"
#include "WebAssemblyIntrinsicTests.h"

//
//unit tests
//

//simple wasm_i8x16_const
int wasm_i8x16_const_test() {
   V128_i8 a;
   a = wasm_v128_const(0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15);
   return WASM_TEST_SUCCESS;
}

int wasm_i8x16_load_test() {
   V128_i8 a;
   V128_i8 b;
   a = wasm_v128_const(0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15);
   b = wasm_v128_load(&a);
   return WASM_TEST_SUCCESS; 
}

int wasm_i8x16_store_test() {
   V128_i8 a;
   V128_i8 b;
   V128_i8 *c;
   a = wasm_v128_const(0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15);
   c = &b;
   wasm_v128_store(c, a);
   return WASM_TEST_SUCCESS; 
}


int wasm_i8x16_splat_test() {
   V128_i8 b;
   int8_t a;
   a = 11;
   b = wasm_i8x16_splat(a);
   return WASM_TEST_SUCCESS;
}


int wasm_i16x8_splat_test() {
   V128_i16 b;
   int16_t a;
   a = 11;
   b = wasm_i16x8_splat(a);
   return WASM_TEST_SUCCESS;
}

int wasm_i32x4_splat_test() {
   V128_i32 b;
   int32_t a;
   a = 11;
   b = wasm_i32x4_splat(a);
   return WASM_TEST_SUCCESS;
}

int wasm_i64x2_splat_test() {
   V128_i64 b;
   int64_t a;
   a = 11;
   b = wasm_i64x2_splat(a);
   return WASM_TEST_SUCCESS;
}


int wasm_f32x4_splat_test() {
   V128_f32 b;
   float a;   
   a= 11.11;
   b = wasm_f32x4_splat(a);
   return WASM_TEST_SUCCESS;
}

int wasm_f64x2_splat_test() {
   V128_f64 b;
   double a;   
   a= 11.11;
   b = wasm_f64x2_splat(a);
   return WASM_TEST_SUCCESS;
}

int wasm_i8x16_extract_lane_s_test() {
    V128_i8 a;
    int32_t b;
    a = wasm_v128_const(0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15);
    b = wasm_i8x16_extract_lane_s(a, 1);
    return WASM_TEST_SUCCESS;
}

int wasm_i8x16_extract_lane_u_test() {
    V128_i8 a;
    uint32_t b;
    a = wasm_v128_const(0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15);
    b = wasm_i8x16_extract_lane_u(a, 1);
    return WASM_TEST_SUCCESS;
}

int wasm_i16x8_extract_lane_s_test() {
    V128_i16 a;
    int32_t b;
    a = wasm_v128_const(0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15);
    b = wasm_i16x8_extract_lane_s(a, 1);
    return WASM_TEST_SUCCESS;
}

int wasm_i16x8_extract_lane_u_test() {
    V128_i16 a;
    uint32_t b;
    a = wasm_v128_const(0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15);
    b = wasm_i16x8_extract_lane_u(a, 1);
    return WASM_TEST_SUCCESS;
}

int wasm_i32x4_extract_lane_test() {
    V128_i32 a;
    int32_t b;
    a = wasm_v128_const(0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15);
    b = wasm_i32x4_extract_lane(a, 1);
    return WASM_TEST_SUCCESS;
}

int wasm_i64x2_extract_lane_test() {
    V128_i64 a;
    int32_t b;
    a = wasm_v128_const(0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15);
    b = wasm_i64x2_extract_lane(a, 1);
    return WASM_TEST_SUCCESS;
}

int wasm_f32x4_extract_lane_test() {
    V128_f32 a;
    int32_t b;
    a = wasm_v128_const(0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15);
    b = wasm_f32x4_extract_lane(a, 1);
    return WASM_TEST_SUCCESS;
}

int wasm_f64x2_extract_lane_test() {
    V128_f64 a;
    int32_t b;
    a = wasm_v128_const(0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15);
    b = wasm_f64x2_extract_lane(a, 1);
    return WASM_TEST_SUCCESS;
}

int wasm_i8x16_replace_lane_test() {
   V128_i8 a; 
   int8_t b;
   V128_i8 c;
   a = wasm_v128_const(0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15);
   b = 7;
   c = wasm_i8x16_replace_lane(a, 2, b);
   return WASM_TEST_SUCCESS;
}

int wasm_i16x8_replace_lane_test() {
   V128_i16 a; 
   int8_t b;
   V128_i16 c;
   a = wasm_v128_const(0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15);
   b = 7;
   c = wasm_i16x8_replace_lane(a, 2, b);
   return WASM_TEST_SUCCESS;
}

int wasm_i32x4_replace_lane_test() {
   V128_i32 a; 
   int8_t b;
   V128_i32 c;
   a = wasm_v128_const(0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15);
   b = 7;
   c = wasm_i32x4_replace_lane(a, 2, b);
   return WASM_TEST_SUCCESS;
}

int wasm_i64x2_replace_lane_test() {
   V128_i64 a; 
   int8_t b;
   V128_i64 c;
   a = wasm_v128_const(0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15);
   b = 7;
   c = wasm_i64x2_replace_lane(a, 2, b);
   return WASM_TEST_SUCCESS;
}

int wasm_f32x4_replace_lane_test() {
   V128_f32 a; 
   int8_t b;
   V128_f32 c;
   a = wasm_v128_const(0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15);
   b = 7;
   c = wasm_f32x4_replace_lane(a, 2, b);
   return WASM_TEST_SUCCESS;
}

int wasm_f64x2_replace_lane_test() {
   V128_f64 a; 
   int8_t b;
   V128_f64 c;
   a = wasm_v128_const(0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15);
   b = 7;
   c = wasm_f64x2_replace_lane(a, 2, b);
   return WASM_TEST_SUCCESS;
}

int wasm_v128_shuffle_test() {
   V128_i16 a;
   V128_i16 b;
   V128_i16 c;
//   V128_i16 s = {0,1,2,3,4,5,6,7};
   c = wasm_v128_shuffle(a,b); //,0,1,2,3,4,5,6,7);
   return WASM_TEST_SUCCESS;
}

//simple wasm_i8x16_add
int wasm_i8x16_add_test() {
   V128_i8 a, b, c;
   a = wasm_v128_const(0,1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15);
   b = wasm_v128_const(1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15,16);   
   c = wasm_i8x16_add(a,b);
   return WASM_TEST_SUCCESS;
}

int wasm_i16x8_add_test() {
   V128_i16 a, b, c;
   a = wasm_v128_const(0,1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15);
   b = wasm_v128_const(1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15,16);  
   c = wasm_i16x8_add(a,b);
   return WASM_TEST_SUCCESS;
}

int wasm_i32x4_add_test() {
   V128_i32 a, b, c;
   a = wasm_v128_const(0,1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15);
   b = wasm_v128_const(1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15,16);  
   c = wasm_i32x4_add(a,b);
   return WASM_TEST_SUCCESS;
}

int wasm_i64x2_add_test() {
   V128_i64 a, b, c;
   a = wasm_v128_const(0,1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15);
   b = wasm_v128_const(1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15,16);  
   c = wasm_i64x2_add(a,b);
   return WASM_TEST_SUCCESS;
}

//simple wasm_i8x16_sub
int wasm_i8x16_sub_test() {
   V128_i8 a, b, c;
   a = wasm_v128_const(0,1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15);
   b = wasm_v128_const(1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15,16);   
   c = wasm_i8x16_sub(a,b);
   return WASM_TEST_SUCCESS;
}

int wasm_i16x8_sub_test() {
   V128_i16 a, b, c;
   a = wasm_v128_const(0,1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15);
   b = wasm_v128_const(1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15,16);  
   c = wasm_i16x8_sub(a,b);
   return WASM_TEST_SUCCESS;
}

int wasm_i32x4_sub_test() {
   V128_i32 a, b, c;
   a = wasm_v128_const(0,1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15);
   b = wasm_v128_const(1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15,16);  
   c = wasm_i32x4_sub(a,b);
   return WASM_TEST_SUCCESS;
}

int wasm_i64x2_sub_test() {
   V128_i64 a, b, c;
   a = wasm_v128_const(0,1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15);
   b = wasm_v128_const(1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15,16);  
   c = wasm_i64x2_sub(a,b);
   return WASM_TEST_SUCCESS;
}

int wasm_i8x16_mul_test() {
   V128_i8 a, b, c;
   a = wasm_v128_const(0,1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15);
   b = wasm_v128_const(1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15,16);   
   c = wasm_i8x16_mul(a,b);
   return WASM_TEST_SUCCESS;
}

int wasm_i16x8_mul_test() {
   V128_i16 a, b, c;
   a = wasm_v128_const(0,1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15);
   b = wasm_v128_const(1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15,16);  
   c = wasm_i16x8_mul(a,b);
   return WASM_TEST_SUCCESS;
}

int wasm_i32x4_mul_test() {
   V128_i32 a, b, c;
   a = wasm_v128_const(0,1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15);
   b = wasm_v128_const(1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15,16);  
   c = wasm_i32x4_mul(a,b);
   return WASM_TEST_SUCCESS;
}

int wasm_i8x16_shl_test() {
   V128_i8 a, b, c;
   int32_t d = 2;
   a = wasm_v128_const(0,1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15);
   b = wasm_v128_const(1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15,16);   
   c = wasm_i8x16_shl(a,d);
   return WASM_TEST_SUCCESS;
}

int wasm_i16x8_shl_test() {
   V128_i16 a, b, c;
   int32_t d = 2;
   a = wasm_v128_const(0,1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15);
   b = wasm_v128_const(1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15,16);  
   c = wasm_i16x8_shl(a,d);
   return WASM_TEST_SUCCESS;
}

int wasm_i32x4_shl_test() {
   V128_i32 a, b, c;
   int32_t d = 2;
   a = wasm_v128_const(0,1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15);
   b = wasm_v128_const(1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15,16);  
   c = wasm_i32x4_shl(a,d);
   return WASM_TEST_SUCCESS;
}

int wasm_i64x2_shl_test() {
   V128_i64 a, b, c;
   int32_t d = 2;
   a = wasm_v128_const(0,1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15);
   b = wasm_v128_const(1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15,16);  
   c = wasm_i64x2_shl(a,d);
   return WASM_TEST_SUCCESS;
}

int wasm_v128_and_test() {
   V128_i8 a, b, c;
   a = wasm_v128_const(0,1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15);
   b = wasm_v128_const(1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15,16);   
   c = wasm_v128_and(a,b);
   return WASM_TEST_SUCCESS;
}

int wasm_v128_or_test() {
   V128_i8 a, b, c;
   a = wasm_v128_const(0,1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15);
   b = wasm_v128_const(1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15,16);   
   c = wasm_v128_or(a,b);
   return WASM_TEST_SUCCESS;
}

int wasm_v128_xor_test() {
   V128_i8 a, b, c;
   a = wasm_v128_const(0,1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15);
   b = wasm_v128_const(1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15,16);   
   c = wasm_v128_xor(a,b);
   return WASM_TEST_SUCCESS;
}

int wasm_v128_not_test() {
   V128_i8 a, c;
   a = wasm_v128_const(0,1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15);  
   c = wasm_v128_not(a);
   return WASM_TEST_SUCCESS;
}

int wasm_i8x16_eq_test() {
   V128_i8 a, b, c;
   a = wasm_v128_const(0,1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15);
   b = wasm_v128_const(1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15,16);   
   c = wasm_i8x16_eq(a, b);
   return WASM_TEST_SUCCESS;
}

int wasm_i16x8_eq_test() {
   V128_i16 a, b, c;
   a = wasm_v128_const(0,1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15);
   b = wasm_v128_const(1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15,16);  
   c = wasm_i16x8_eq(a,b);
   return WASM_TEST_SUCCESS;
}

int wasm_i32x4_eq_test() {
   V128_i32 a, b, c;
   a = wasm_v128_const(0,1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15);
   b = wasm_v128_const(1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15,16);  
   c = wasm_i32x4_eq(a,b);
   return WASM_TEST_SUCCESS;
}

int wasm_i8x16_ne_test() {
   V128_i8 a, b, c;
   a = wasm_v128_const(0,1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15);
   b = wasm_v128_const(1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15,16);   
   c = wasm_i8x16_eq(a, b);
   return WASM_TEST_SUCCESS;
}

int wasm_i16x8_ne_test() {
   V128_i16 a, b, c;
   a = wasm_v128_const(0,1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15);
   b = wasm_v128_const(1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15,16);  
   c = wasm_i16x8_eq(a,b);
   return WASM_TEST_SUCCESS;
}

int wasm_i32x4_ne_test() {
   V128_i32 a, b, c;
   a = wasm_v128_const(0,1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15);
   b = wasm_v128_const(1,2,3,4,5,6,7,8,9,10,11, 12,13,14,15,16);  
   c = wasm_i32x4_eq(a,b);
   return WASM_TEST_SUCCESS;
}


//IntializeTests
int InitializeTests() {
   int Ret;  
   Ret = WASM_TEST_SUCCESS;
   return Ret;
}

//main (unit test driver)
int main(int argc, char *argv[]) {
   int Ret; 
   Ret = InitializeTests();
   if (Ret != WASM_TEST_SUCCESS) {
      return Ret;
   }

//todo
//move to initialize and create vector function pointers
//call tests or ranges of tests with vector of functions 
//instead of current implementation

   Ret = wasm_i8x16_const_test();
   Ret = wasm_i8x16_load_test();
   Ret = wasm_i8x16_store_test();
   Ret = wasm_i8x16_splat_test();
   Ret = wasm_i16x8_splat_test();
   Ret = wasm_i32x4_splat_test();
   Ret = wasm_i64x2_splat_test();
   Ret = wasm_f32x4_splat_test();
   Ret = wasm_f64x2_splat_test();
   //rrw look at extract and replace literal issue with spec.
   Ret = wasm_i8x16_extract_lane_s_test();
   Ret = wasm_i8x16_extract_lane_u_test();
   Ret = wasm_i16x8_extract_lane_s_test();
   Ret = wasm_i16x8_extract_lane_u_test();
   Ret = wasm_i32x4_extract_lane_test();
   Ret = wasm_i64x2_extract_lane_test();
   Ret = wasm_f32x4_extract_lane_test();
   Ret = wasm_f64x2_extract_lane_test();
   Ret = wasm_i8x16_replace_lane_test();
   Ret = wasm_i16x8_replace_lane_test();
   Ret = wasm_i32x4_replace_lane_test();
   Ret = wasm_i64x2_replace_lane_test();
   Ret = wasm_f32x4_replace_lane_test();
   Ret = wasm_f64x2_replace_lane_test();
   Ret = wasm_v128_shuffle_test(); //rrw shuffle has some literal problems by definition from spec need to figure out
   Ret = wasm_i8x16_add_test();
   Ret = wasm_i16x8_add_test();
   Ret = wasm_i32x4_add_test();
   Ret = wasm_i64x2_add_test();
   Ret = wasm_i8x16_shl_test();
   Ret = wasm_i8x16_sub_test();
   Ret = wasm_i16x8_sub_test();
   Ret = wasm_i32x4_sub_test();
   Ret = wasm_i64x2_sub_test();
   Ret = wasm_i8x16_mul_test();
   Ret = wasm_i16x8_mul_test();
   Ret = wasm_i32x4_mul_test();
   Ret = wasm_i8x16_shl_test();
   Ret = wasm_i16x8_shl_test();
   Ret = wasm_i32x4_shl_test();
   Ret = wasm_i64x2_shl_test();
   Ret = wasm_v128_and_test();
   Ret = wasm_v128_or_test();
   Ret = wasm_v128_xor_test();
   Ret = wasm_v128_not_test();
   Ret = wasm_i8x16_eq_test();
   Ret = wasm_i16x8_eq_test();
   Ret = wasm_i32x4_eq_test();
   Ret = wasm_i8x16_ne_test();
   Ret = wasm_i16x8_ne_test();
   Ret = wasm_i32x4_ne_test();
   return Ret;
}
