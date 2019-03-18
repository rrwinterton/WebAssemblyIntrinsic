#include <emscripten.h>
#include <emscripten/fetch.h>
#include <emscripten/html5.h>
#include <emscripten/val.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

#include "WebAssemblyIntrinsic.h"
#include "WebAssemblyIntrinsicTests.h"

using namespace emscripten;
using namespace std;

// globals to help keep code from getting optimized way by the compiler
vector<UNIT_TEST_FUNCTION> UnitTests;
int8_t g_randInsert = 1;  // in html * 1
i8x16 i8x16_a;
i8x16 i8x16_b;
i8x16 i8x16_c;
int8_t i8x16_aBuff[16];
int8_t i8x16_bBuff[16];
u8x16 u8x16_a;
u8x16 u8x16_b;
u8x16 u8x16_c;
uint8_t u8x16_aBuff[16];
uint8_t u8x16_bBuff[16];
i16x8 i16x8_a;
i16x8 i16x8_b;
i16x8 i16x8_c;
int16_t i16x8_aBuff[8];
int16_t i16x8_bBuff[8];
i32x4 i32x4_a;
i32x4 i32x4_b;
i32x4 i32x4_c;
int32_t i32x4_aBuff[4];
int32_t i32x4_bBuff[4];
i64x2 i64x2_a;
i64x2 i64x2_b;
i64x2 i64x2_c;
int64_t i64x2_aBuff[2];
int64_t i64x2_bBuff[2];
f32x4 f32x4_a;
f32x4 f32x4_b;
f32x4 f32x4_c;
float f32x4_aBuff[4];
float f32x4_bBuff[4];
f64x2 f64x2_a;
f64x2 f64x2_b;
f64x2 f64x2_c;
double f64x2_aBuff[2];
double f64x2_bBuff[2];

i32x4 bv32;

// randInsert to keep code from getting optimized away by the compiler
uint8_t randInsert(uint32_t seed) {
  uint8_t retVal;
  if (seed < 16) {
    retVal = seed;
  } else {
    srand(seed);
    retVal = (uint8_t)(rand() * seed);
  }
  return retVal;
}

// getInput used to get input from html page
string getInput(string fieldName) {
  val document = val::global("document");
  val value = document.call<val>("getElementById", fieldName)["value"];
  return value.as<string>();
}

// setOutput provides test results to html page
void setOutput(std::string fieldname, std::string value) {
  val document = val::global("document");
  val elem = document.call<val>("getElementById", std::string(fieldname));
  elem.set("value", value);
}

// wasm_v128_const
int32_t wasm_v128_const_test() {
  int32_t Ret;
  i8x16_a = (v128 ) wasm_v128_const(0, 11, 22, 33, 44, 55, 66, 77, 88, 99, 10, 11, 12,
                             13, 14, 15);
  Ret = WASM_TEST_SUCCESS;
  return Ret;
}

// wasm_v128_load
int32_t wasm_v128_load_test() {
  int8_t ai[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
  int32_t i;
  int32_t Ret;

  ai[2] = i * randInsert(g_randInsert);
  i8x16_a = (v128 ) wasm_v128_load((v128 *) ai);
  wasm_v128_store((v128 *) i8x16_bBuff, (v128 ) i8x16_a);
  for (i = 0; i < 16; i++) {
    if (ai[i] != i8x16_bBuff[i]) {
      break;
    }
  }
  if (i < 16) {
    Ret = WASM_TEST_GENERAL_FAIL;
  } else {
    Ret = WASM_TEST_SUCCESS;
  }
  return Ret;
}

// wasm_v128_store
int32_t wasm_v128_store_test() {
  int Ret;
  Ret = wasm_v128_load_test();
  return Ret;
}

// wasm_i8x16_splat
int32_t wasm_i8x16_splat_test() {
  int8_t i8a;
  int8_t ai[16];
  int Ret;

  i8a = 11;
  i8x16_a = wasm_i8x16_splat(i8a);
  wasm_v128_store((i8x16*)ai, i8x16_a);
  Ret = WASM_TEST_SUCCESS;
  for (auto i = 0; i < 16; i++) {
    if (ai[i] != 11) {
      Ret = WASM_TEST_GENERAL_FAIL;
      break;
    }
  }
  return Ret;
}

int32_t wasm_i16x8_splat_test() {
  int16_t i8a;
  int16_t ai[8];
  int Ret;

  i8a = 77;
  i16x8_a = wasm_i16x8_splat(i8a);
  wasm_v128_store((i8x16*)ai, i16x8_a);
  Ret = WASM_TEST_SUCCESS;
  for (auto i = 0; i < 8; i++) {
    if (ai[i] != 77) {
      Ret = WASM_TEST_GENERAL_FAIL;
      break;
    }
  }
  return Ret;
}

// wasm_i32x4_splat
int32_t wasm_i32x4_splat_test() {
  int32_t i32a;
  int32_t ai[4];
  int Ret;

  i32a = 32;
  i32x4_a = wasm_i32x4_splat(i32a);
  wasm_v128_store((i8x16*)ai, i32x4_a);
  Ret = WASM_TEST_SUCCESS;
  for (auto i = 0; i < 4; i++) {
    if (ai[i] != 32) {
      Ret = WASM_TEST_GENERAL_FAIL;
      break;
    }
  }
  return Ret;
}

int32_t wasm_i64x2_splat_test() {
  int64_t i64a;
  int64_t ai[2];
  int Ret;

  i64a = 64;
  i64x2_a = wasm_i64x2_splat(i64a);
  wasm_v128_store((i8x16*)ai, i64x2_a);
  Ret = WASM_TEST_SUCCESS;
  for (auto i = 0; i < 2; i++) {
    if (ai[i] != 64) {
      Ret = WASM_TEST_GENERAL_FAIL;
      break;
    }
  }
  return Ret;
}

int32_t wasm_f32x4_splat_test() {
  float f32a;
  float af[4];
  int Ret;

  f32a = 64.1;
  f32x4_a = wasm_f32x4_splat(f32a);
  wasm_v128_store((i8x16*)af, f32x4_a);
  Ret = WASM_TEST_SUCCESS;
  for (auto i = 0; i < 4; i++) {
    if (af[i] != 64.1) {
      Ret = WASM_TEST_GENERAL_FAIL;
      break;
    }
  }
  return Ret;
}

int32_t wasm_f64x2_splat_test() {
  double f64a;
  double af[2];
  int Ret;

  f64a = 64.11;
  f64x2_a = wasm_f64x2_splat(f64a);
  wasm_v128_store((i8x16*)af, f64x2_a);
  Ret = WASM_TEST_SUCCESS;
  for (auto i = 0; i < 2; i++) {
    if (af[i] != 64.11) {
      Ret = WASM_TEST_GENERAL_FAIL;
      break;
    }
  }
  return Ret;
}

int32_t wasm_i8x16_extract_lane_test() {
  int8_t b;
  int8_t ai[16] = {-1, 0, 2, -3, 4, -5, 6, 7, -8, 9, 10, 11, 12, 13, 14, 15};
  int32_t insertVal;
  int32_t Ret;

  insertVal = randInsert(g_randInsert);
  ai[3] *= (insertVal % 3) + 1;
  i8x16_a = wasm_v128_load((i8x16*)ai);
  if (insertVal == 1) {
    b = wasm_i8x16_extract_lane(i8x16_a, 1);
  }
  else {
    b = wasm_i8x16_extract_lane(i8x16_a, 3);
  }
  Ret = (int32_t ) b;
  return Ret;
}

#ifdef __wasm_undefined_simd128__
int32_t wasm_u8x16_extract_lane_test() {
  uint8_t b;
  uint8_t ai[16] = {1, 0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
  int32_t insertVal;
  int32_t Ret;

  insertVal = randInsert(g_randInsert);
  ai[3] *= (insertVal % 3) + 1;
  u8x16_a = wasm_v128_load((i8x16*)ai);
  if (insertVal == 1) {
    b = wasm_u8x16_extract_lane(u8x16_a, 1);
  }
  else {
    b = wasm_u8x16_extract_lane(u8x16_a, 3);
  }
  Ret = (int32_t ) b;
  return Ret;
}
#endif

int32_t wasm_i16x8_extract_lane_test() {
  int16_t b;
  int16_t ai[8] = {-7, 0, 2, -3, 4, -5, 6, 7};
  int32_t insertVal;
  int32_t Ret;

  insertVal = randInsert(g_randInsert);
  ai[1] = insertVal - 1;
  i16x8_a = wasm_v128_load((i8x16*)ai);
  if (insertVal == 1) {
    b = wasm_i16x8_extract_lane(i16x8_a, 1);
  }
  else {
    b = wasm_i16x8_extract_lane(i16x8_a, 4);
  }
  Ret = (int32_t ) b;
  return Ret;
}

int32_t wasm_i32x4_extract_lane_test() {
  i32x4 a;
  int32_t b;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_i32x4_extract_lane(a, 1);
  return WASM_TEST_SUCCESS;
}

#ifdef __wasm_undefined_simd128__
int32_t wasm_i64x2_extract_lane_test() {
  i64x2 a;
  int32_t b;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_i64x2_extract_lane(a, 1);
  return WASM_TEST_SUCCESS;
}
#endif

int32_t wasm_f32x4_extract_lane_test() {
  f32x4 a;
  int32_t b;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_f32x4_extract_lane(a, 1);
  return WASM_TEST_SUCCESS;
}

#ifdef __wasm_undefined_simd128__
int32_t wasm_f64x2_extract_lane_test() {
  i8x16_f64 a;
  int32_t b;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_f64x2_extract_lane(a, 1);
  return WASM_TEST_SUCCESS;
}
#endif

int32_t wasm_i8x16_replace_lane_test() {
  int32_t b;
  i8x16_a =
      wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = 7;
  i8x16_c = wasm_i8x16_replace_lane(i8x16_a, 2, b);
  return WASM_TEST_SUCCESS;
}

int32_t wasm_i16x8_replace_lane_test() {
  i16x8 a;
  int32_t b;
  i16x8 c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = 7;
  c = wasm_i16x8_replace_lane(a, 2, b);
  return WASM_TEST_SUCCESS;
}

int32_t wasm_i32x4_replace_lane_test() {
  i32x4 a;
  int32_t b;
  i32x4 c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = 7;
  c = wasm_i32x4_replace_lane(a, 2, b);
  return WASM_TEST_SUCCESS;
}

#ifdef __wasm_unimplemented_simd128__
int32_t wasm_i64x2_replace_lane_test() {
  i64x2 a;
  int64_t b;
  i64x2 c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = 7;
  c = wasm_i64x2_replace_lane(a, 2, b);
  return WASM_TEST_SUCCESS;
}
#endif

int32_t wasm_f32x4_replace_lane_test() {
  f32x4 a;
  int8_t b;
  f32x4 c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = 7;
  c = wasm_f32x4_replace_lane(a, 2, b);
  return WASM_TEST_SUCCESS;
}

#ifdef __wasm_unimplemented_simd128__
int32_t wasm_f64x2_replace_lane_test() {
  i8x16_f64 a;
  int8_t b;
  i8x16_f64 c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = 7;
  c = wasm_f64x2_replace_lane(a, 2, b);
  return WASM_TEST_SUCCESS;
}
#endif

#ifdef __wasm_unimplemented_simd128__
int32_t wasm_i8x16_shuffle_test() {
  i8x16 s = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
  c = wasm_i8x16_shuffle(a, b);
  return WASM_TEST_SUCCESS;
}
#endif

// simple wasm_i8x16_add
int32_t wasm_i8x16_add_test() {
  i8x16 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i8x16_add(a, b);
  return WASM_TEST_SUCCESS;
}

int32_t wasm_i16x8_add_test() {
  i16x8 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i16x8_add(a, b);
  return WASM_TEST_SUCCESS;
}

int32_t wasm_i32x4_add_test() {
  i32x4 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i32x4_add(a, b);
  return WASM_TEST_SUCCESS;
}

int32_t wasm_i64x2_add_test() {
  i64x2 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i64x2_add(a, b);
  return WASM_TEST_SUCCESS;
}

// simple wasm_i8x16_sub
int32_t wasm_i8x16_sub_test() {
  i8x16 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i8x16_sub(a, b);
  return WASM_TEST_SUCCESS;
}

int32_t wasm_i16x8_sub_test() {
  i16x8 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i16x8_sub(a, b);
  return WASM_TEST_SUCCESS;
}

int32_t wasm_i32x4_sub_test() {
  i32x4 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i32x4_sub(a, b);
  return WASM_TEST_SUCCESS;
}

int32_t wasm_i64x2_sub_test() {
  i64x2 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i64x2_sub(a, b);
  return WASM_TEST_SUCCESS;
}

int32_t wasm_i8x16_mul_test() {
  i8x16 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i8x16_mul(a, b);
  return WASM_TEST_SUCCESS;
}

int32_t wasm_i16x8_mul_test() {
  i16x8 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i16x8_mul(a, b);
  return WASM_TEST_SUCCESS;
}

int32_t wasm_i32x4_mul_test() {
  i32x4 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i32x4_mul(a, b);
  return WASM_TEST_SUCCESS;
}

int32_t wasm_i64x2_mul_test() {
  i64x2 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i64x2_mul(a, b);
  return WASM_TEST_SUCCESS;
}

int32_t wasm_i8x16_neg_test() {
  i8x16 a, b;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_i8x16_neg(a);
  return WASM_TEST_SUCCESS;
}

int32_t wasm_i16x8_neg_test() {
  i16x8 a, b;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_i16x8_neg(a);
  return WASM_TEST_SUCCESS;
}

int32_t wasm_i32x4_neg_test() {
  i32x4 a, b;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_i32x4_neg(a);
  return WASM_TEST_SUCCESS;
}

int32_t wasm_i64x2_neg_test() {
  i64x2 a, b;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_i64x2_neg(a);
  return WASM_TEST_SUCCESS;
}

int32_t wasm_i8x16_add_saturate_test() {
  i8x16 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  c = wasm_i8x16_add_saturate(a, b);
  return WASM_TEST_SUCCESS;
}

int32_t wasm_u8x16_add_saturate_test() {
  u8x16 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  c = wasm_u8x16_add_saturate(a, b);
  return WASM_TEST_SUCCESS;
}

int32_t wasm_i16x8_add_saturate_test() {
  i8x16 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  c = wasm_i16x8_add_saturate(a, b);
  return WASM_TEST_SUCCESS;
}

int32_t wasm_u16x8_add_saturate_test() {
  u16x8 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  c = wasm_u16x8_add_saturate(a, b);
  return WASM_TEST_SUCCESS;
}

int32_t wasm_i8x16_sub_saturate_test() {
  i8x16 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  c = wasm_i8x16_sub_saturate(a, b);
  return WASM_TEST_SUCCESS;
}

int32_t wasm_u8x16_sub_saturate_test() {
  u8x16 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  c = wasm_i8x16_sub_saturate(a, b);
  return WASM_TEST_SUCCESS;
}

int32_t wasm_i16x8_sub_saturate_test() {
  i8x16 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  c = wasm_i16x8_sub_saturate(a, b);
  return WASM_TEST_SUCCESS;
}

int32_t wasm_u16x8_sub_saturate_test() {
  u16x8 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  c = wasm_i16x8_sub_saturate(a, b);
  return WASM_TEST_SUCCESS;
}

int32_t wasm_i8x16_shl_test() {
  i8x16 a, b;
  int32_t c = 2;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_i8x16_shl(a, c);
  return WASM_TEST_SUCCESS;
}

int32_t wasm_i16x8_shl_test() {
  i16x8 a, b;
  int32_t c = 2;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_i16x8_shl(a, c);
  return WASM_TEST_SUCCESS;
}

int32_t wasm_i32x4_shl_test() {
  i32x4 a, b;
  int32_t c = 2;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_i32x4_shl(a, c);
  return WASM_TEST_SUCCESS;
}

int32_t wasm_i64x2_shl_test() {
  i64x2 a, b;
  int32_t c = 2;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_i64x2_shl(a, c);
  return WASM_TEST_SUCCESS;
}

int32_t wasm_i8x16_shr_test() {
  i8x16 a, b;
  int32_t c = 2;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_i8x16_shr(a, c);
  return WASM_TEST_SUCCESS;
}

int32_t wasm_u8x16_shr_test() {
  u8x16 a, b;
  int32_t c = 2;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_u8x16_shr(a, c);
  return WASM_TEST_SUCCESS;
}

int32_t wasm_i16x8_shr_test() {
  i16x8 a, b;
  int32_t c = 2;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_i16x8_shr(a, c);
  return WASM_TEST_SUCCESS;
}

int32_t wasm_u16x8_shr_test() {
  u16x8 a, b;
  int32_t c = 2;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_u16x8_shr(a, c);
  return WASM_TEST_SUCCESS;
}

int32_t wasm_i32x4_shr_test() {
  i32x4 a, b;
  int32_t c = 2;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_i32x4_shr(a, c);
  return WASM_TEST_SUCCESS;
}

int32_t wasm_u32x4_shr_test() {
  u32x4 a, b;
  int32_t c = 2;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_u32x4_shr(a, c);
  return WASM_TEST_SUCCESS;
}

int32_t wasm_i64x2_shr_test() {
  i64x2 a, b;
  int32_t c = 2;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_i64x2_shr(a, c);
  return WASM_TEST_SUCCESS;
}

int32_t wasm_u64x2_shr_test() {
  u64x2 a, b;
  int32_t c = 2;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_u64x2_shr(a, c);
  return WASM_TEST_SUCCESS;
}

int32_t wasm_i8x16_and_test() {
  i8x16 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i8x16_and(a, b);
  return WASM_TEST_SUCCESS;
}

int32_t wasm_i8x16_or_test() {
  i8x16 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i8x16_or(a, b);
  return WASM_TEST_SUCCESS;
}

int32_t wasm_i8x16_xor_test() {
  i8x16 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i8x16_xor(a, b);
  return WASM_TEST_SUCCESS;
}

int32_t wasm_i8x16_not_test() {
  i8x16 a, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  c = wasm_i8x16_not(a);
  return WASM_TEST_SUCCESS;
}

int32_t wasm_i8x16_bitselect_test() {
  i8x16 a, b, c, d;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  c = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  d = wasm_i8x16_bitselect(a, b, c);
  return WASM_TEST_SUCCESS;
}

int32_t wasm_i8x16_any_true_test() {
  i8x16 a;
  bool b;
  b = wasm_i8x16_any_true(a);
  return WASM_TEST_SUCCESS;
}

int32_t wasm_i16x8_any_true_test() {
  i16x8 a;
  bool b;
  b = wasm_i16x8_any_true(a);
  return WASM_TEST_SUCCESS;
}

int32_t wasm_i32x4_any_true_test() {
  i32x4 a;
  bool b;
  b = wasm_i32x4_any_true(a);
  return WASM_TEST_SUCCESS;
}

#ifdef __wasm_unimplemented_simd128__
int32_t wasm_i64x2_any_true_test() {
  i64x2 a;
  bool b;
  b = wasm_i64x2_any_true(a);
  return WASM_TEST_SUCCESS;
}
#endif

int32_t wasm_i8x16_eq_test() {
  i8x16 a, b, c;
  int16_t ai[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
  int16_t bi[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
  int32_t i;
  int32_t Ret;

  a = wasm_v128_load((i8x16*)ai);
  bi[2] = bi[2] * randInsert(g_randInsert);
  b = wasm_v128_load((i8x16*)bi);
  c = wasm_i8x16_eq(a, b);
  wasm_v128_store((i8x16*)bi, c);
  Ret = WASM_TEST_SUCCESS;
  for (i = 0; i < 15; i++) {
    if (bi[i] == 0)
      Ret = WASM_TEST_GENERAL_FAIL;
  }
  return Ret;
}

int32_t wasm_i16x8_eq_test() {
  i16x8 a, b, c;
  int16_t ai[8] = {1, 2, 3, 4, 5, 6, 7};
  int16_t bi[8] = {1, 2, 3, 4, 5, 6, 7};
  int32_t i;
  int32_t Ret;

  a = wasm_v128_load((i8x16*)ai);
  bi[2] = bi[2] * randInsert(g_randInsert);
  b = wasm_v128_load((i8x16*)bi);
  c = wasm_i16x8_eq(a, b);
  wasm_v128_store((i8x16*)bi, c);
  Ret = WASM_TEST_SUCCESS;
  for (i = 0; i < 8; i++) {
    if (bi[i] == 0)
      Ret = WASM_TEST_GENERAL_FAIL;
  }
  return Ret;
}

int32_t wasm_i32x4_eq_test() {
  i32x4 a, b, c;
  int32_t ai[4] = {0, 1, 2, 3};
  int32_t bi[4] = {0, 1, 2, 3};
  int32_t i;
  int32_t Ret;

  a = wasm_v128_load((i8x16*)ai);
  bi[2] = bi[2] * randInsert(g_randInsert);
  b = wasm_v128_load((i8x16*)bi);
  c = wasm_i32x4_eq(a, b);
  wasm_v128_store((i8x16*)bi, c);
  Ret = WASM_TEST_SUCCESS;
  for (i = 0; i < 4; i++) {
    if (bi[i] == 0)
      Ret = WASM_TEST_GENERAL_FAIL;
  }
  return Ret;
}

#ifdef __wasm_unimplemented_simd128__
int32_t wasm_f32x4_eq_test() {
  int32_t i;
  int32_t Ret;
  f32x4 a, b;
  i32x4 c;
  float af[4] = {1.1, 2.2, 3.3, 4.4};
  float bf[4] = {1.1, 2.2, 3.3, 4.4};

  a = wasm_v128_load((i8x16*)af);
  bf[1] = bf[1] * randInsert(g_randInsert);
  b = wasm_v128_load((i8x16*)bf);
  c = wasm_f32x4_eq(af, bf);
  wasm_v128_store((i8x16*)bf, c);
  Ret = WASM_TEST_SUCCESS;
  for (i = 0; i < 4; i++) {
    if (i8x16_bBuff[i] == 0)
      Ret = WASM_TEST_GENERAL_FAIL;
  }
  return Ret;
}
#endif

#ifdef __wasm_unimplemented_simd128__
int32_t wasm_f64x2_eq_test() {
  int32_t i;
  int32_t Ret;
  f64x2 a, b;
  i64x2 c;
  float af[2] = {1.1, 2.2};
  float bf[2] = {1.1, 2.2};

  a = wasm_v128_load((i8x16*)af);
  bf[1] = bf[1] * randInsert(g_randInsert);
  b = wasm_v128_load((i8x16*)bf);
  c = wasm_f64x2_eq(af, bf);
  wasm_v128_store((i8x16*)bf, c);
  Ret = WASM_TEST_SUCCESS;
  for (i = 0; i < 2; i++) {
    if (i8x16_bBuff[i] == 0)
      Ret = WASM_TEST_GENERAL_FAIL;
  }
  return Ret;
}
#endif

int32_t wasm_i8x16_ne_test() {
  i8x16 a, b, c;
  int8_t ai[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
  int8_t bi[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
  int32_t i;
  int32_t Ret;

  a = wasm_v128_load((i8x16*)ai);
  bi[2] = bi[2] * randInsert(g_randInsert);
  b = wasm_v128_load((i8x16*)bi);
  c = wasm_i8x16_ne(a, b);
  wasm_v128_store((i8x16*)bi, c);
  Ret = WASM_TEST_SUCCESS;
  for (i = 0; i < 15; i++) {
    if (bi[i] != 0)
      Ret = WASM_TEST_GENERAL_FAIL;
  }
  return Ret;
}

int32_t wasm_i16x8_ne_test() {
  i16x8 a, b, c;
  int16_t ai[8] = {0, 1, 2, 3, 4, 5, 6, 7};
  int16_t bi[8] = {0, 1, 2, 3, 4, 5, 6, 7};
  int32_t i;
  int32_t Ret;

  a = wasm_v128_load((i8x16*)ai);
  bi[2] = bi[2] * randInsert(g_randInsert);
  b = wasm_v128_load((i8x16*)bi);
  c = wasm_i16x8_ne(a, b);
  wasm_v128_store((i8x16*)bi, c);
  Ret = WASM_TEST_SUCCESS;
  for (i = 0; i < 8; i++) {
    if (bi[i] != 0)
      Ret = WASM_TEST_GENERAL_FAIL;
  }
  return Ret;
}

int32_t wasm_i32x4_ne_test() {
  i32x4 a, b, c;
  int16_t ai[8] = {0, 1, 2, 3};
  int16_t bi[8] = {0, 1, 2, 3};
  int32_t i;
  int32_t Ret;

  a = wasm_v128_load((i8x16*)ai);
  bi[2] = bi[2] * randInsert(g_randInsert);
  b = wasm_v128_load((i8x16*)bi);
  c = wasm_i32x4_ne(a, b);
  wasm_v128_store((i8x16*)bi, c);
  Ret = WASM_TEST_SUCCESS;
  for (i = 0; i < 4; i++) {
    if (bi[i] != 0)
      Ret = WASM_TEST_GENERAL_FAIL;
  }
  return Ret;
}

/*
int32_t wasm_convert_u_f32x4_i32x4_test() {
}
*/

int32_t wasm_i8x16_lt_test() {
  i8x16 a, b, c;
  int8_t ai[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
  int8_t bi[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  int32_t i;
  int32_t Ret;

  a = wasm_v128_load((i8x16*)ai);
  bi[2] = bi[2] * randInsert(g_randInsert);
  b = wasm_v128_load((i8x16*)bi);
  c = wasm_i8x16_lt(a, b);
  wasm_v128_store((i8x16*)bi, c);
  Ret = WASM_TEST_SUCCESS;
  for (i = 0; i < 15; i++) {
    if (bi[i] == 0)
      Ret = WASM_TEST_GENERAL_FAIL;
  }
  return Ret;
}

int32_t wasm_u8x16_lt_test() {
  u8x16 a, b, c;
  c = wasm_u8x16_lt(a, b);
  return WASM_TEST_SUCCESS;
}

//f32x4 wasm_convert_f32x4_i32x4(u32x4 a)
int32_t wasm_convert_f32x4_i32x4_test() {
  int Ret;
  int32_t ai[4] = {1, 0, -3, 4};
  f32x4 b;
  i32x4 a;
  float *pbf;
  float f;

  a = wasm_v128_load((i8x16*) ai);
  b = wasm_convert_f32x4_i32x4(a);
  pbf = (float *) &b;
  f = pbf[randInsert(g_randInsert)%4];
  Ret = (int ) f;
  return Ret;
}

//f32x4 wasm_convert_f32x4_u32x4(u32x4 a)
int32_t wasm_convert_f32x4_u32x4_test() {
  int Ret;
  uint32_t au[4] = {1, 0, 3, 4};
  f32x4 b;
  u32x4 a;
  float *pbf;
  float f;

  a = wasm_v128_load((i8x16*) au);
  b = wasm_convert_f32x4_u32x4(a);
  pbf = (float *) &b;
  f = pbf[randInsert(g_randInsert)%4];
  Ret = ((int ) f) * -1;
  return Ret;
}

//f64x2 wasm_convert_f64x2_i64x2(i64x2 a)
#ifdef __wasm_undefined_simd128__
int32_t wasm_convert_f64x2_i64x2_test() {
  int Ret;
  int64_t ai[4] = {0, -2};
  f64x2 b;
  i64x2 a;
  double *pbf;
  double d;

  a = wasm_v128_load((i8x16*) ai);
  b = wasm_convert_f64x2_i64x2(a);
  pbf = (float *) &b;
  d = pbf[randInsert(g_randInsert)%4];
  Ret = ((int ) d) * -1;
  return Ret;
}
#endif

//f64x2 wasm_convert_f64x2_u64x2(u64x2 a)
#ifdef __wasm_undefined_simd128__
int32_t wasm_convert_f64x2_u64x2_test() {
  int Ret;
  uint64_t au[4] = {0, 2};
  f64x2 b;
  u64x2 a;
  double *pbf;
  double d;

  a = wasm_v128_load((i8x16*) au);
  b = wasm_convert_f64x2_i64x2(a);
  pbf = (float *) &b;
  d = pbf[randInsert(g_randInsert)%4];
  Ret = ((int ) d) * -1;
  return Ret;
}
#endif

// end unit tests

void InitializeTests() {
/*
      UnitTests.push_back(wasm_v128_const_test);
      UnitTests.push_back(wasm_v128_load_test);
      UnitTests.push_back(wasm_v128_store_test);
      UnitTests.push_back(wasm_i8x16_splat_test);
      UnitTests.push_back(wasm_i16x8_splat_test);
      UnitTests.push_back(wasm_i32x4_splat_test);
//f   UnitTests.push_back(wasm_i64x2_splat_test); //no splat int 64
//f   UnitTests.push_back(wasm_f32x4_splat_test); //generates float splat
//f   UnitTests.push_back(wasm_f64x2_splat_test); //(64) splat
      UnitTests.push_back(wasm_i8x16_extract_lane_test);
//f      UnitTests.push_back(wasm_u8x16_extract_lane_test);
*/
      UnitTests.push_back(wasm_i16x8_extract_lane_test);
/*
      UnitTests.push_back(wasm_u16x8_extract_lane_test);
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
      // UnitTests.push_back(wasm_i8x16_shuffle_test);
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
      UnitTests.push_back(wasm_i8x16_add_saturate_test);
      UnitTests.push_back(wasm_u8x16_add_saturate_test);
      UnitTests.push_back(wasm_i16x8_add_saturate_test);
      UnitTests.push_back(wasm_u16x8_add_saturate_test);
      UnitTests.push_back(wasm_i8x16_shl_test);
      UnitTests.push_back(wasm_i16x8_shl_test);
      UnitTests.push_back(wasm_i32x4_shl_test);
      UnitTests.push_back(wasm_i64x2_shl_test);
      UnitTests.push_back(wasm_i8x16_shr_test);
      UnitTests.push_back(wasm_u8x16_shr_test);
      UnitTests.push_back(wasm_i16x8_shr_test);
      UnitTests.push_back(wasm_u16x8_shr_test);
      UnitTests.push_back(wasm_i32x4_shr_test);
      UnitTests.push_back(wasm_u32x4_shr_test);
      UnitTests.push_back(wasm_i64x2_shr_test);
      UnitTests.push_back(wasm_u64x2_shr_test);
      UnitTests.push_back(wasm_i8x16_and_test);
      UnitTests.push_back(wasm_i8x16_or_test);
      UnitTests.push_back(wasm_i8x16_xor_test);
      UnitTests.push_back(wasm_i8x16_not_test);
      UnitTests.push_back(wasm_i8x16_bitselect_test);
      UnitTests.push_back(wasm_i8x16_any_true_test);
      UnitTests.push_back(wasm_i16x8_any_true_test);
      UnitTests.push_back(wasm_i32x4_any_true_test);
    #ifdef __wasm_undefined_simd128__
      UnitTests.push_back(wasm_i64x2_any_true_test);
    #endif
      UnitTests.push_back(wasm_i8x16_eq_test);
      UnitTests.push_back(wasm_i16x8_eq_test);
      UnitTests.push_back(wasm_i32x4_eq_test);
    #ifdef __wasm_undefined_simd128__
      UnitTests.push_back(wasm_f32x4_eq_test);
    #endif

    #ifdef __wasm_undefined_simd128__
      UnitTests.push_back(wasm_f64x2_eq_test);
    #endif

      UnitTests.push_back(wasm_i8x16_ne_test);
      UnitTests.push_back(wasm_i16x8_ne_test);
      UnitTests.push_back(wasm_i32x4_ne_test);
    #ifdef __wasm_undefined_simd128__
      UnitTests.push_back(wasm_f32x4_ne_test);
    #endif
    #ifdef __wasm_undefined_simd128__
      UnitTests.push_back(wasm_f64x2_ne_test);
    #endif

    UnitTests.push_back(wasm_convert_f32x4_i32x4_test);
    UnitTests.push_back(wasm_convert_f32x4_u32x4_test);

#ifdef __wasm_undefined_simd128__
    UnitTests.push_back(wasm_convert_f64x2_i64x2_test);
    UnitTests.push_back(wasm_convert_f64x2_u64x2_test);
#endif
*/

/*
    //rrw
          //not generating i8x16.lt ...
          UnitTests.push_back(wasm_i8x16_lt_s_test);
          UnitTests.push_back(wasm_i8x16_lt_u_test);
          UnitTests.push_back(wasm_i16x8_lt_s_test);
          UnitTests.push_back(wasm_i16x8_lt_u_test);

      i32x4.trunc_s/f32x4:sat
      i32x4.trunc_u/f32x4:sat
      i64x2.trunc_s/f64x2:sat
      i64x2.trunc_u/f64x2:sat
*/

}

// on_run_click runs the tests in the vector (start to end) (main test loop)
int32_t on_run_click(int32_t eventType,
                     const EmscriptenMouseEvent* mouseEvent,
                     void* userData) {
  int32_t Ret;
  int32_t testCnt;
  int32_t testsRun;
  string randInputStr, startTestStr, endTestStr;
  int32_t startTest, endTest;
  string OutputResults = "";

  testCnt = 0;

  randInputStr = getInput("randInsert").c_str();
  if (randInputStr.length()) {
    g_randInsert = stoi(randInputStr.c_str());
  } else {
    g_randInsert = 1;
  }

  startTestStr = getInput("startTest").c_str();
  if (startTestStr.length()) {
    startTest = stoi(startTestStr.c_str()) - 1;  //zero based index
  } else {
    startTest = 0;
  }

  endTestStr = getInput("endTest").c_str();
  if (startTestStr.length()) {
    endTest = stoi(endTestStr.c_str()) - 1;  //zero based index
  } else {
    endTest = UnitTests.size() - 1;  //zero based index
  }

  testsRun = 0;
  vector<UNIT_TEST_FUNCTION>::iterator ptr = UnitTests.begin();
  advance(ptr, startTest);

  for (testCnt = startTest; testCnt <= endTest; testCnt++) {
    auto& Test = *ptr;
    advance(ptr, 1);
    Ret = Test();
    testsRun++;
    if (Ret != WASM_TEST_SUCCESS) {
      break;
    }
  }

  if ((testsRun == UnitTests.size()) && (Ret == WASM_TEST_SUCCESS)) {
    Ret = WASM_TEST_SUCCESS;
  }

  OutputResults = "Tests Run ";
  if (Ret == WASM_TEST_SUCCESS) {
    OutputResults = "Yeah Success! : ";
  } else {
    OutputResults = "Ugh Fail! : ";
  }
  OutputResults += to_string(testsRun);
  OutputResults += " Tests Run, ReturnCode: ";
  OutputResults += to_string(Ret);
  setOutput("cbtestRet", OutputResults.c_str());
  return Ret;
}

// main
int32_t main() {
  emscripten_set_click_callback("cbRun", (void*)0, 0, on_run_click);
  InitializeTests();
  EM_ASM(Module['noExitRuntime'] = true);
  return 0;
}
