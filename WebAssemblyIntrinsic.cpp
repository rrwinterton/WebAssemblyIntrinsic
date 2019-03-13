#include <emscripten.h>
#include <emscripten/fetch.h>
#include <emscripten/html5.h>
#include <emscripten/val.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>

#include "WebAssemblyIntrinsic.h"
#include "WebAssemblyIntrinsicTests.h"

using namespace emscripten;
using namespace std;

// globals
vector<UNIT_TEST_FUNCTION> UnitTests;
int8_t g_randInsert = 1; //in html * 1
V128_i8 a;
V128_i8 b;
V128_i8 c;
uint8_t aBuff[16];
uint8_t bBuff[16];
V128_i32 bv32;


uint8_t randInsert(uint32_t seed) {
  uint8_t retVal;
  if (seed == 1) {
    retVal = 1;
  }
  else {
    srand(seed);
    retVal = (uint8_t ) (rand() * seed);
  }
  return retVal;
}

// getInput
string getInput(string fieldName) {
  val document = val::global("document");
  val value = document.call<val>("getElementById", fieldName)["value"];
  return value.as<string>();
}

// setOutput
void setOutput(std::string fieldname, std::string value) {
  val document = val::global("document");
  val elem = document.call<val>("getElementById", std::string(fieldname));
  elem.set("value", value);
}

// simple wasm_v128_const
int wasm_v128_const_test() {
  int Ret;
  a = wasm_v128_const(0, 11, 22, 33, 44, 55, 66, 77, 88, 99, 10, 11, 12, 13, 14, 15);
  Ret = WASM_TEST_SUCCESS;
  return Ret;
}

// wasm_v128_load
int wasm_v128_load_test() {
  int i;
  int Ret;

  for (i = 0; i < 16; i++) {
    aBuff[i] = i*10;
  }

  a = wasm_v128_load((V128*)aBuff);
  wasm_v128_store((V128*) bBuff, a);

  for (i = 0; i < 16; i++) {
    if (aBuff[i] != bBuff[i]) {
       break;
    }
  }
  if (i < 16) {
    Ret = WASM_TEST_GENERAL_FAIL;
  }
  else {
    Ret = WASM_TEST_SUCCESS;
  }
  return Ret;
}

// V128 storemem;
int wasm_v128_store_test() {
  int i;
  uint8_t* pChar;
  static V128 storemem;
  int Ret;
  Ret = WASM_TEST_SUCCESS;
  for (i = 0; i < 16; i++) {
    aBuff[i] = i * randInsert(g_randInsert);
  }

  a = wasm_v128_load((V128*) &aBuff);

  wasm_v128_store((V128 *) &storemem, a);
  // rrw validate big endian little endian issue
  pChar = (uint8_t *)&storemem;
  for (i = 0; i < 16; i++) {
    if (*pChar++ != i) {
      Ret = WASM_TEST_GENERAL_FAIL;
      break;
    }
  }
  return Ret;
}

int wasm_i8x16_splat_test() {
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
  V128_i32 bv32;
  int32_t i32a;
  i32a = 117711;
  bv32 = wasm_i32x4_splat(i32a);
  wasm_v128_store((V128*) bBuff, bv32);
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
  a = 11.11;
  b = wasm_f32x4_splat(a);
  return WASM_TEST_SUCCESS;
}

int wasm_f64x2_splat_test() {
  V128_f64 b;
  double a;
  a = 11.11;
  b = wasm_f64x2_splat(a);
  return WASM_TEST_SUCCESS;
}

int wasm_i8x16_extract_lane_test() {
  V128_i8 a;
  int32_t b;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_i8x16_extract_lane(a, 1);
  return WASM_TEST_SUCCESS;
}

int wasm_i16x8_extract_lane_test() {
  V128_i16 a;
  int32_t b;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_i16x8_extract_lane(a, 1);
  return WASM_TEST_SUCCESS;
}

int wasm_i32x4_extract_lane_test() {
  V128_i32 a;
  int32_t b;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_i32x4_extract_lane(a, 1);
  return WASM_TEST_SUCCESS;
}

#ifdef __wasm_undefined_simd128__
int wasm_i64x2_extract_lane_test() {
  V128_i64 a;
  int32_t b;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_i64x2_extract_lane(a, 1);
  return WASM_TEST_SUCCESS;
}
#endif

int wasm_f32x4_extract_lane_test() {
  V128_f32 a;
  int32_t b;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_f32x4_extract_lane(a, 1);
  return WASM_TEST_SUCCESS;
}

#ifdef __wasm_undefined_simd128__
int wasm_f64x2_extract_lane_test() {
  V128_f64 a;
  int32_t b;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_f64x2_extract_lane(a, 1);
  return WASM_TEST_SUCCESS;
}
#endif

int wasm_i8x16_replace_lane_test() {
  int32_t b;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = 7;
  c = wasm_i8x16_replace_lane(a, 2, b);
  return WASM_TEST_SUCCESS;
}

int wasm_i16x8_replace_lane_test() {
  V128_i16 a;
  int32_t b;
  V128_i16 c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = 7;
  c = wasm_i16x8_replace_lane(a, 2, b);
  return WASM_TEST_SUCCESS;
}

int wasm_i32x4_replace_lane_test() {
  V128_i32 a;
  int32_t b;
  V128_i32 c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = 7;
  c = wasm_i32x4_replace_lane(a, 2, b);
  return WASM_TEST_SUCCESS;
}

#ifdef __wasm_unimplemented_simd128__
int wasm_i64x2_replace_lane_test() {
  V128_i64 a;
  int64_t b;
  V128_i64 c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = 7;
  c = wasm_i64x2_replace_lane(a, 2, b);
  return WASM_TEST_SUCCESS;
}
#endif

int wasm_f32x4_replace_lane_test() {
  V128_f32 a;
  int8_t b;
  V128_f32 c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = 7;
  c = wasm_f32x4_replace_lane(a, 2, b);
  return WASM_TEST_SUCCESS;
}

#ifdef __wasm_unimplemented_simd128__
int wasm_f64x2_replace_lane_test() {
  V128_f64 a;
  int8_t b;
  V128_f64 c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = 7;
  c = wasm_f64x2_replace_lane(a, 2, b);
  return WASM_TEST_SUCCESS;
}
#endif

// rrw need to fix const variable
int wasm_i8x16_shuffle_test() {
  V128_i8 s = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
  c = wasm_i8x16_shuffle(a, b, s);
  return WASM_TEST_SUCCESS;
}

// simple wasm_i8x16_add
int wasm_i8x16_add_test() {
  V128_i8 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i8x16_add(a, b);
  return WASM_TEST_SUCCESS;
}

int wasm_i16x8_add_test() {
  V128_i16 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i16x8_add(a, b);
  return WASM_TEST_SUCCESS;
}

int wasm_i32x4_add_test() {
  V128_i32 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i32x4_add(a, b);
  return WASM_TEST_SUCCESS;
}

int wasm_i64x2_add_test() {
  V128_i64 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i64x2_add(a, b);
  return WASM_TEST_SUCCESS;
}

// simple wasm_i8x16_sub
int wasm_i8x16_sub_test() {
  V128_i8 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i8x16_sub(a, b);
  return WASM_TEST_SUCCESS;
}

int wasm_i16x8_sub_test() {
  V128_i16 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i16x8_sub(a, b);
  return WASM_TEST_SUCCESS;
}

int wasm_i32x4_sub_test() {
  V128_i32 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i32x4_sub(a, b);
  return WASM_TEST_SUCCESS;
}

int wasm_i64x2_sub_test() {
  V128_i64 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i64x2_sub(a, b);
  return WASM_TEST_SUCCESS;
}

int wasm_i8x16_mul_test() {
  V128_i8 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i8x16_mul(a, b);
  return WASM_TEST_SUCCESS;
}

int wasm_i16x8_mul_test() {
  V128_i16 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i16x8_mul(a, b);
  return WASM_TEST_SUCCESS;
}

int wasm_i32x4_mul_test() {
  V128_i32 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i32x4_mul(a, b);
  return WASM_TEST_SUCCESS;
}

int wasm_i64x2_mul_test() {
  V128_i64 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i64x2_mul(a, b);
  return WASM_TEST_SUCCESS;
}

int wasm_i8x16_neg_test() {
  V128_i8 a, b;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_i8x16_neg(a);
  return WASM_TEST_SUCCESS;
}

int wasm_i16x8_neg_test() {
  V128_i16 a, b;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_i16x8_neg(a);
  return WASM_TEST_SUCCESS;
}

int wasm_i32x4_neg_test() {
  V128_i32 a, b;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_i32x4_neg(a);
  return WASM_TEST_SUCCESS;
}

int wasm_i64x2_neg_test() {
  V128_i64 a, b;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_i64x2_neg(a);
  return WASM_TEST_SUCCESS;
}

int wasm_i8x16_add_saturate_s_test() {
  V128_i8 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  c = wasm_i8x16_add_saturate_s(a, b);
  return WASM_TEST_SUCCESS;
}

int wasm_i8x16_add_saturate_u_test() {
  V128_i8 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  c = wasm_i8x16_add_saturate_u(a, b);
  return WASM_TEST_SUCCESS;
}

int wasm_i16x8_add_saturate_s_test() {
  V128_i8 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  c = wasm_i16x8_add_saturate_s(a, b);
  return WASM_TEST_SUCCESS;
}

int wasm_i16x8_add_saturate_u_test() {
  V128_i16 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  c = wasm_i16x8_add_saturate_u(a, b);
  return WASM_TEST_SUCCESS;
}

int wasm_i8x16_sub_saturate_s_test() {
  V128_i8 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  c = wasm_i8x16_sub_saturate_s(a, b);
  return WASM_TEST_SUCCESS;
}

int wasm_i8x16_sub_saturate_u_test() {
  V128_i8 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  c = wasm_i8x16_sub_saturate_u(a, b);
  return WASM_TEST_SUCCESS;
}

int wasm_i16x8_sub_saturate_s_test() {
  V128_i8 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  c = wasm_i16x8_sub_saturate_s(a, b);
  return WASM_TEST_SUCCESS;
}

int wasm_i16x8_sub_saturate_u_test() {
  V128_i16 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  c = wasm_i16x8_sub_saturate_u(a, b);
  return WASM_TEST_SUCCESS;
}

int wasm_i8x16_shl_test() {
  V128_i8 a, b;
  int32_t c = 2;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_i8x16_shl(a, c);
  return WASM_TEST_SUCCESS;
}

int wasm_i16x8_shl_test() {
  V128_i16 a, b;
  int32_t c = 2;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_i16x8_shl(a, c);
  return WASM_TEST_SUCCESS;
}

int wasm_i32x4_shl_test() {
  V128_i32 a, b;
  int32_t c = 2;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_i32x4_shl(a, c);
  return WASM_TEST_SUCCESS;
}

int wasm_i64x2_shl_test() {
  V128_i64 a, b;
  int32_t c = 2;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_i64x2_shl(a, c);
  return WASM_TEST_SUCCESS;
}

int wasm_i8x16_shr_s_test() {
  V128_i8 a, b;
  int32_t c = 2;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_i8x16_shr_s(a, c);
  return WASM_TEST_SUCCESS;
}

int wasm_i8x16_shr_u_test() {
  V128_i8 a, b;
  int32_t c = 2;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_i8x16_shr_u(a, c);
  return WASM_TEST_SUCCESS;
}

int wasm_i16x8_shr_s_test() {
  V128_i16 a, b;
  int32_t c = 2;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_i16x8_shr_s(a, c);
  return WASM_TEST_SUCCESS;
}

int wasm_i16x8_shr_u_test() {
  V128_i16 a, b;
  int32_t c = 2;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_i16x8_shr_u(a, c);
  return WASM_TEST_SUCCESS;
}

int wasm_i32x4_shr_s_test() {
  V128_i32 a, b;
  int32_t c = 2;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_i32x4_shr_s(a, c);
  return WASM_TEST_SUCCESS;
}

int wasm_i32x4_shr_u_test() {
  V128_i32 a, b;
  int32_t c = 2;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_i32x4_shr_u(a, c);
  return WASM_TEST_SUCCESS;
}

int wasm_i64x2_shr_s_test() {
  V128_i64 a, b;
  int32_t c = 2;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_i64x2_shr_s(a, c);
  return WASM_TEST_SUCCESS;
}

int wasm_i64x2_shr_u_test() {
  V128_i64 a, b;
  int32_t c = 2;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_i64x2_shl(a, c);
  return WASM_TEST_SUCCESS;
}

int wasm_v128_and_test() {
  V128_i8 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_v128_and(a, b);
  return WASM_TEST_SUCCESS;
}

int wasm_v128_or_test() {
  V128_i8 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_v128_or(a, b);
  return WASM_TEST_SUCCESS;
}

int wasm_v128_xor_test() {
  V128_i8 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_v128_xor(a, b);
  return WASM_TEST_SUCCESS;
}

int wasm_v128_not_test() {
  V128_i8 a, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  c = wasm_v128_not(a);
  return WASM_TEST_SUCCESS;
}

int wasm_v128_bitselect_test() {
  V128_i8 a, b, c, d;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  c = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  d = wasm_v128_bitselect(a, b, c);
  return WASM_TEST_SUCCESS;
}

int wasm_v128_i8_any_true_test() {
  V128 a;
  int32_t b;
  b = wasm_v128_i8_any_true(a);
  return WASM_TEST_SUCCESS;
}

int wasm_v128_i16_any_true_test() {
  V128_i16 a;
  int32_t b;
  b = wasm_v128_i16_any_true(a);
  return WASM_TEST_SUCCESS;
}

int wasm_v128_i32_any_true_test() {
  V128_i32 a;
  int32_t b;
  b = wasm_v128_i32_any_true(a);
  return WASM_TEST_SUCCESS;
}

#ifdef __wasm_unimplemented_simd128__
int wasm_v128_i64_any_true_test() {
  V128_i64 a;
  int32_t b;
  b = wasm_v128_i64_any_true(a);
  return WASM_TEST_SUCCESS;
}
#endif

int wasm_i8x16_eq_test() {
  V128_i8 a, b, c;
  int i;
  int Ret;

  for (i = 0; i < 16; i++) {
    aBuff[i] = i*2;
    bBuff[i] = aBuff[i];
  }

  a = wasm_v128_load((V128*)aBuff);
  bBuff[2] = bBuff[2] * randInsert(g_randInsert);
  b = wasm_v128_load((V128*)bBuff);
  c = wasm_i8x16_eq(a, b);
  wasm_v128_store((V128*) bBuff, c);
  Ret = WASM_TEST_SUCCESS;
  for (i = 0; i < 15; i++) {
    if (bBuff[2] == 0)
      Ret = WASM_TEST_GENERAL_FAIL;
  }
  return Ret;
}

int wasm_i16x8_eq_test() {
  V128_i16 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i16x8_eq(a, b);
  return WASM_TEST_SUCCESS;
}

int wasm_i32x4_eq_test() {
  V128_i32 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i32x4_eq(a, b);
  return WASM_TEST_SUCCESS;
}

int wasm_f32x4_eq_test() {
  int i;
  int Ret;
  V128_f32 a, b, c;
  float af[4] = {1.1, 3.1, 2.2, 3.3};
  float bf[4] = {2.2, 1.1, 2.2, 4.4};
  float d[4];
  a = wasm_v128_load((V128 *) &af);
  b = wasm_v128_load((V128 *) &bf);
  c = wasm_f32x4_eq(a, b);
  wasm_v128_store((V128 *) &d, c);
  for (i = 0; i < 3; i++) {
    if (d[i] != 0) {
      Ret = i;
      break;
    }
  }
  if (Ret == 2) {
     Ret = WASM_TEST_SUCCESS;
  }
  else {
    Ret = WASM_TEST_GENERAL_FAIL;
  }
  return Ret;
}

int wasm_i8x16_ne_test() {
  V128_i8 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i8x16_ne(a, b);
  return WASM_TEST_SUCCESS;
}

int wasm_i16x8_ne_test() {
  V128_i16 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i16x8_ne(a, b);
  return WASM_TEST_SUCCESS;
}

int wasm_i32x4_ne_test() {
  V128_i32 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i32x4_ne(a, b);
  return WASM_TEST_SUCCESS;
}

int wasm_i8x16_lt_s_test() {
  V128_i8 a, b, c;
  int8_t ia[8], ib[8];
  c = wasm_i8x16_lt_s(a,b);
  return WASM_TEST_SUCCESS;
}

int wasm_i8x16_lt_u_test() {
  V128_i8 a, b, c;
  c = wasm_i8x16_lt_u(a,b);
  return WASM_TEST_SUCCESS;
}
/*
wasm_i8x16_lt_u
wasm_i16x8_lt_s
wasm_i16x8_lt_u
wasm_i32x4_lt_s
wasm_i32x4_lt_u
wasm_f32x4_lt
wasm_f64x2_lt

int wasm_convert_s_f32x4_i32x4_test() {
  float fa[4];
  V128_f32 a;
  V128_i8 b;

  a = wasm_v128_load((V128*)fa);
  b = wasm_convert_s_f32x4_i32x4(a);
  return WASM_TEST_SUCCESS;
}
int wasm_convert_u_f32x4_i32x4_test() {
  return WASM_TEST_SUCCESS;
}

int wasm_convert_s_f64x2_i64x2_test() {
  return WASM_TEST_SUCCESS;
}

int wasm_convert_u_f32x2_i64x2_test() {
  return WASM_TEST_SUCCESS;
}
*/

// end unit tests

void InitializeTests() {

  UnitTests.push_back(wasm_v128_const_test);
  UnitTests.push_back(wasm_v128_load_test);
  UnitTests.push_back(wasm_v128_store_test);
  UnitTests.push_back(wasm_i8x16_splat_test);
  UnitTests.push_back(wasm_i16x8_splat_test);
  UnitTests.push_back(wasm_i32x4_splat_test);
  UnitTests.push_back(wasm_i64x2_splat_test);
  UnitTests.push_back(wasm_f32x4_splat_test);
  UnitTests.push_back(wasm_f64x2_splat_test);
  UnitTests.push_back(wasm_i8x16_extract_lane_test);
  UnitTests.push_back(wasm_i16x8_extract_lane_test);
  UnitTests.push_back(wasm_i32x4_extract_lane_test);
  #ifdef __wasm_undefined_simd128__
    UnitTests.push_back(wasm_i64x2_extract_lane_test);
  #endif
  UnitTests.push_back(wasm_f32x4_extract_lane_test);
  #ifdef __wasm_undefined_simd128__
    UnitTests.push_back(wasm_f64x2_extract_lane_test);
  #endif
  UnitTests.push_back(wasm_i8x16_replace_lane_test);
  UnitTests.push_back(wasm_i16x8_replace_lane_test);
  UnitTests.push_back(wasm_i32x4_replace_lane_test);
  #ifdef __wasm_undefined_simd128__
  UnitTests.push_back(wasm_i64x2_replace_lane_test);
  #endif
  UnitTests.push_back(wasm_f32x4_replace_lane_test);
  #ifdef __wasm_undefined_simd128__
    UnitTests.push_back(wasm_f64x2_replace_lane_test);
  #endif
  // rrw need to fix
  //UnitTests.push_back(wasm_i8x16_shuffle_test);
  // rrw
  UnitTests.push_back(wasm_i8x16_add_test);
  UnitTests.push_back(wasm_i16x8_add_test);
  UnitTests.push_back(wasm_i32x4_add_test);
  UnitTests.push_back(wasm_i64x2_add_test);
  UnitTests.push_back(wasm_i8x16_sub_test);
  UnitTests.push_back(wasm_i16x8_sub_test);
  UnitTests.push_back(wasm_i32x4_sub_test);
  UnitTests.push_back(wasm_i64x2_sub_test);
  UnitTests.push_back(wasm_i8x16_mul_test);
  UnitTests.push_back(wasm_i16x8_mul_test);
  UnitTests.push_back(wasm_i32x4_mul_test);
  UnitTests.push_back(wasm_i64x2_mul_test);
  UnitTests.push_back(wasm_i8x16_neg_test);
  UnitTests.push_back(wasm_i16x8_neg_test);
  UnitTests.push_back(wasm_i32x4_neg_test);
  UnitTests.push_back(wasm_i64x2_neg_test);
  UnitTests.push_back(wasm_i8x16_add_saturate_s_test);
  UnitTests.push_back(wasm_i8x16_add_saturate_u_test);
  UnitTests.push_back(wasm_i16x8_add_saturate_s_test);
  UnitTests.push_back(wasm_i16x8_add_saturate_u_test);
  UnitTests.push_back(wasm_i8x16_shl_test);
  UnitTests.push_back(wasm_i16x8_shl_test);
  UnitTests.push_back(wasm_i32x4_shl_test);
  UnitTests.push_back(wasm_i64x2_shl_test);
  UnitTests.push_back(wasm_i8x16_shr_s_test);
  UnitTests.push_back(wasm_i8x16_shr_u_test);
  UnitTests.push_back(wasm_i16x8_shr_s_test);
  UnitTests.push_back(wasm_i16x8_shr_u_test);
  UnitTests.push_back(wasm_i32x4_shr_s_test);
  UnitTests.push_back(wasm_i32x4_shr_u_test);
  UnitTests.push_back(wasm_i64x2_shr_s_test);
  UnitTests.push_back(wasm_i64x2_shr_u_test);
  UnitTests.push_back(wasm_v128_and_test);
  UnitTests.push_back(wasm_v128_or_test);
  UnitTests.push_back(wasm_v128_xor_test);
  UnitTests.push_back(wasm_v128_not_test);
  UnitTests.push_back(wasm_v128_bitselect_test);
  UnitTests.push_back(wasm_v128_i8_any_true_test);
  UnitTests.push_back(wasm_v128_i16_any_true_test);
  UnitTests.push_back(wasm_v128_i32_any_true_test);
  #ifdef __wasm_undefined_simd128__
    UnitTests.push_back(wasm_v128_i64_any_true_test);
  #endif
  UnitTests.push_back(wasm_i8x16_eq_test);


/*
wasm_i8x16_eq
wasm_i16x8_eq
wasm_i32x4_eq
wasm_f32x4_eq

wasm_i8x16_ne
wasm_i16x8_ne
wasm_i32x4_ne
wasm_f32x4_ne
*/

/*
  UnitTests.push_back(wasm_i8x16_eq_test);
  UnitTests.push_back(wasm_i16x8_eq_test);
  UnitTests.push_back(wasm_i32x4_eq_test);
  //rrw need i64 eq
  UnitTests.push_back(wasm_f32x4_eq_test);
  UnitTests.push_back(wasm_i8x16_ne_test);
  UnitTests.push_back(wasm_i16x8_ne_test);
  UnitTests.push_back(wasm_i32x4_ne_test);
  //rrw need i64 eq

//  UnitTests.push_back(wasm_convert_s_f32x4_i32x4_test);
//wasm_convert_u_f32x4_i32x4
//wasm_convert_s_f64x2_i64x2
//wasm_convert_u_f32x2_i64x2

wasm_convert_s_f32x4_i32x4
wasm_convert_u_f32x4_i32x4
wasm_convert_s_f64x2_i64x2
wasm_convert_u_f32x2_i64x2

i32x4.trunc_s/f32x4:sat
i32x4.trunc_u/f32x4:sat
i64x2.trunc_s/f64x2:sat
i64x2.trunc_u/f64x2:sat
*/

}

// on_run_click (main test loop)
int on_run_click(int eventType,
                 const EmscriptenMouseEvent* mouseEvent,
                 void* userData) {
  int Ret;
  int testCnt;
  int testsRun;
  string randInputStr, startTestStr, endTestStr;
  int startTest, endTest;
  string OutputResults = "";

  testCnt = 0;

  randInputStr = getInput("randInsert").c_str();
  if (randInputStr.length()) {
    g_randInsert = stoi(randInputStr.c_str());
  }
  else {
    g_randInsert = 1;
  }

  startTestStr = getInput("startTest").c_str();
  if (startTestStr.length()) {
    startTest = stoi(startTestStr.c_str()) - 1; //zero based index
  }
  else {
    startTest = 0;
  }

  endTestStr = getInput("endTest").c_str();
  if (startTestStr.length()) {
    endTest = stoi(endTestStr.c_str()) - 1; //zero based index
  }
  else {
    endTest = UnitTests.size()-1; //zero based index
  }
  testsRun = 0;
  vector<UNIT_TEST_FUNCTION>::iterator ptr = UnitTests.begin();
  advance(ptr, startTest);
  for (testCnt = startTest; testCnt <= endTest; testCnt++) {
//  for (auto& Test : UnitTests) {
    auto &Test = *ptr;
    advance(ptr, 1);
    Ret = Test();
    if (Ret < WASM_TEST_SUCCESS) {
      break;
    }
    testsRun++;
  }
  if ((testCnt == UnitTests.size()) && (Ret == WASM_TEST_SUCCESS)) {
    Ret = WASM_TEST_SUCCESS;
  }

  /*
  startingTest = stoi(getInput("startTest").c_str());
  endingTest = startingTest;

  vector<UNIT_TEST_FUNCTION>::iterator ptr = UnitTests.begin();
  for (auto i = startingTest; i <= endingTest; i++) {
    advance(ptr, 1);
    auto &Test = *ptr;
    Ret = Test();
  }

  OutputResults = "Tests Run ";
  */
  if (Ret == WASM_TEST_SUCCESS) {
  OutputResults = "Yeah Success! : ";
  }
  else {
  OutputResults = "Ugh Fail! : ";
  }
  OutputResults += to_string(testsRun);
  OutputResults += " Tests Run, ReturnCode: ";
  OutputResults += to_string(Ret);
  setOutput("cbtestRet", OutputResults.c_str());
  return Ret;
}

// end test loop

// main
int main() {
  emscripten_set_click_callback("cbRun", (void*)0, 0, on_run_click);
  InitializeTests();
  EM_ASM(Module['noExitRuntime'] = true);
  return 0;
}
