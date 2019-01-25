#include <stdio.h>
#include <string.h>
#include <vector>
#include <emscripten.h>
#include <emscripten/html5.h>
#include <emscripten/fetch.h>
#include <emscripten/val.h>

#include "WebAssemblyIntrinsic.h"
#include "WebAssemblyIntrinsicTests.h"

using namespace emscripten;
using namespace std;

//globals
vector<UNIT_TEST_FUNCTION> UnitTests;
V128_i8 a;
V128_i8 b;

//getInput
string getInput(string fieldName)
{
  val document = val::global("document");
  val value = document.call<val>("getElementById", fieldName)["value"];
  return value.as<string>();
}

//setOutput
void setOutput(std::string fieldname, std::string value)
{
  val document = val::global("document");
  val elem = document.call<val>("getElementById", std::string(fieldname));
  elem.set("value", value);
}

//on_run_click
int on_run_click(int eventType, const EmscriptenMouseEvent *mouseEvent, void *userData)
{
  int Ret;
  int startingTest, endingTest;
  string OutputResults = "";
/*
  auto &Test = UnitTests[0];
  Ret = Test();
*/
  for (auto &Test : UnitTests ) {
          Ret = Test();
          if (Ret < WASM_TEST_SUCCESS)
            break;
        }
/*
  startingTest = stoi(getInput("startTest").c_str());
  endingTest = startingTest;

  vector<UNIT_TEST_FUNCTION>::iterator ptr = UnitTests.begin();
  for (auto i = startingTest; i <= endingTest; i++)
  {
    advance(ptr, 1);
    auto &Test = *ptr;
    Ret = Test();
  }

  OutputResults = "Tests Run ";
  */
  OutputResults = "Tests Run ";
  OutputResults += to_string(Ret);
  setOutput("cbtestRet", OutputResults.c_str());
  return Ret;
}

//begin unit tests

//wasm_i8x16_load
int wasm_i8x16_load_test()
{
  int i;
  char aBuff[17];
  char bBuff[17];
  int Ret;

  Ret = WASM_TEST_SUCCESS;
  for (i = 0; i < 17; i++)
  {
    aBuff[i] = 0;
    bBuff[i] = 0;
  }
  bBuff[16] = 1;

  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_load(&a);

  //rrw todo

  i = 0;
  for (i = 0; i < sizeof(aBuff); i++)
  {
    if (aBuff[i] != bBuff[i])
      break;
  }
  if (i < 16)
  {
    Ret = -wasm_i8x16_load_test_number;
  }

  return Ret;
}

//simple wasm_i8x16_const Note: wasm_i8x16_const is tested in the load test
int wasm_i8x16_const_test()
{
  int Ret;
  Ret = wasm_i8x16_load_test();
  if (Ret != WASM_TEST_SUCCESS)
  {
    Ret = -wasm_i8x16_const_test_number;
  }
  return -11; //rrw Ret;
}
/*
int wasm_v128_load_test()
{
  V128_i8 aVal;
  char aBuff[16];
  char bBuff[16];
  int i;
  int Ret;

  Ret = -wasm_i8x16_load_test_number;
  for (i = 0; i < 16; i++)
  {
    aBuff[i] = 16 - i;
  }

  aVal = wasm_v128_load((V128_i8 *)aBuff);

  i = 0;
  for (i = 0; i < sizeof(aBuff); i++)
  {
    if (aBuff[i] != bBuff[i])
      break;
  }
  //rrw still need to validate
  Ret = WASM_TEST_SUCCESS;
  return Ret;
}

//V128 storemem;

int wasm_v128_store_test()
{
  int i;
  char *pChar;
  V128 storemem;
  int Ret;

  Ret = WASM_TEST_SUCCESS;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  wasm_v128_store((V128_i8 *)&storemem, a);
  //rrw validate big endian little endian issue
  pChar = (char *)&storemem;
  for (i = 0; i < 16; i++)
  {
    if (*pChar++ != 15 - i)
    {
      Ret = WASM_TEST_SUCCESS;
      break;
    }
  }
  return WASM_TEST_SUCCESS;
}

int wasm_i8x16_splat_test()
{
  V128_i8 b;
  int8_t a;
  a = 11;
  b = wasm_i8x16_splat(a);
  return WASM_TEST_SUCCESS;
}

int wasm_i16x8_splat_test()
{
  V128_i16 b;
  int16_t a;
  a = 11;
  b = wasm_i16x8_splat(a);
  return WASM_TEST_SUCCESS;
}

int wasm_i32x4_splat_test()
{
  V128_i32 b;
  int32_t a;
  a = 11;
  b = wasm_i32x4_splat(a);
  return WASM_TEST_SUCCESS;
}

int wasm_i64x2_splat_test()
{
  V128_i64 b;
  int64_t a;
  a = 11;
  b = wasm_i64x2_splat(a);
  return WASM_TEST_SUCCESS;
}

int wasm_f32x4_splat_test()
{
  V128_f32 b;
  float a;
  a = 11.11;
  b = wasm_f32x4_splat(a);
  return WASM_TEST_SUCCESS;
}

int wasm_f64x2_splat_test()
{
  V128_f64 b;
  double a;
  a = 11.11;
  b = wasm_f64x2_splat(a);
  return WASM_TEST_SUCCESS;
}

int wasm_i8x16_extract_lane_s_test()
{
  V128_i8 a;
  int32_t b;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_i8x16_extract_lane_s(a, 1);
  return WASM_TEST_SUCCESS;
}

#ifdef __wasm_undefined_simd128__
int wasm_i8x16_extract_lane_u_test()
{
  V128_i8 a;
  uint32_t b;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_i8x16_extract_lane_u(a, 1);
  return WASM_TEST_SUCCESS;
}
#endif

int wasm_i16x8_extract_lane_s_test()
{
  V128_i16 a;
  int32_t b;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_i16x8_extract_lane_s(a, 1);
  return WASM_TEST_SUCCESS;
}

#ifdef __wasm_undefined_simd128__
int wasm_i16x8_extract_lane_u_test()
{
  V128_i16 a;
  uint32_t b;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_i16x8_extract_lane_u(a, 1);
  return WASM_TEST_SUCCESS;
}
#endif

int wasm_i32x4_extract_lane_test()
{
  V128_i32 a;
  int32_t b;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_i32x4_extract_lane(a, 1);
  return WASM_TEST_SUCCESS;
}

#ifdef __wasm_undefined_simd128__
int wasm_i64x2_extract_lane_test()
{
  V128_i64 a;
  int32_t b;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_i64x2_extract_lane(a, 1);
  return WASM_TEST_SUCCESS;
}
#endif

//rrw fails
int wasm_f32x4_extract_lane_test()
{
  V128_f32 a;
  int32_t b;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_f32x4_extract_lane(a, 1);
  return WASM_TEST_SUCCESS;
}

//rrw fails
#ifdef __wasm_undefined_simd128__
int wasm_f64x2_extract_lane_test()
{
  V128_f64 a;
  int32_t b;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_f64x2_extract_lane(a, 1);
  return WASM_TEST_SUCCESS;
}
#endif

int wasm_i8x16_replace_lane_test()
{
  V128_i8 a;
  int8_t b;
  V128_i8 c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = 7;
  c = wasm_i8x16_replace_lane(a, 2, b);
  return WASM_TEST_SUCCESS;
}

int wasm_i16x8_replace_lane_test()
{
  V128_i16 a;
  int8_t b;
  V128_i16 c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = 7;
  c = wasm_i16x8_replace_lane(a, 2, b);
  return WASM_TEST_SUCCESS;
}

int wasm_i32x4_replace_lane_test()
{
  V128_i32 a;
  int8_t b;
  V128_i32 c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = 7;
  c = wasm_i32x4_replace_lane(a, 2, b);
  return WASM_TEST_SUCCESS;
}

#ifdef __wasm_unimplemented_simd128__
int wasm_i64x2_replace_lane_test()
{
  V128_i64 a;
  int8_t b;
  V128_i64 c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = 7;
  c = wasm_i64x2_replace_lane(a, 2, b);
  return WASM_TEST_SUCCESS;
}
#endif

//fail
int wasm_f32x4_replace_lane_test()
{
  V128_f32 a;
  int8_t b;
  V128_f32 c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = 7;
  c = wasm_f32x4_replace_lane(a, 2, b);
  return WASM_TEST_SUCCESS;
}

//fail
#ifdef __wasm_unimplemented_simd128__
int wasm_f64x2_replace_lane_test()
{
  V128_f64 a;
  int8_t b;
  V128_f64 c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = 7;
  c = wasm_f64x2_replace_lane(a, 2, b);
  return WASM_TEST_SUCCESS;
}
#endif

int wasm_v128_shuffle_test()
{
  V128_i16 a;
  V128_i16 b;
  V128_i16 c;
  //   V128_i16 s = {0,1,2,3,4,5,6,7};
  c = wasm_v128_shuffle(a, b); //,0,1,2,3,4,5,6,7);
  return WASM_TEST_SUCCESS;
}

//simple wasm_i8x16_add
int wasm_i8x16_add_test()
{
  V128_i8 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i8x16_add(a, b);
  return WASM_TEST_SUCCESS;
}

int wasm_i16x8_add_test()
{
  V128_i16 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i16x8_add(a, b);
  return WASM_TEST_SUCCESS;
}

int wasm_i32x4_add_test()
{
  V128_i32 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i32x4_add(a, b);
  return WASM_TEST_SUCCESS;
}

int wasm_i64x2_add_test()
{
  V128_i64 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i64x2_add(a, b);
  return WASM_TEST_SUCCESS;
}

//simple wasm_i8x16_sub
int wasm_i8x16_sub_test()
{
  V128_i8 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i8x16_sub(a, b);
  return WASM_TEST_SUCCESS;
}

int wasm_i16x8_sub_test()
{
  V128_i16 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i16x8_sub(a, b);
  return WASM_TEST_SUCCESS;
}

int wasm_i32x4_sub_test()
{
  V128_i32 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i32x4_sub(a, b);
  return WASM_TEST_SUCCESS;
}

int wasm_i64x2_sub_test()
{
  V128_i64 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i64x2_sub(a, b);
  return WASM_TEST_SUCCESS;
}

int wasm_i8x16_mul_test()
{
  V128_i8 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i8x16_mul(a, b);
  return WASM_TEST_SUCCESS;
}

int wasm_i16x8_mul_test()
{
  V128_i16 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i16x8_mul(a, b);
  return WASM_TEST_SUCCESS;
}

int wasm_i32x4_mul_test()
{
  V128_i32 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i32x4_mul(a, b);
  return WASM_TEST_SUCCESS;
}

int wasm_i8x16_shl_test()
{
  V128_i8 a, b, c;
  int32_t d = 2;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i8x16_shl(a, d);
  return WASM_TEST_SUCCESS;
}

int wasm_i16x8_shl_test()
{
  V128_i16 a, b, c;
  int32_t d = 2;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i16x8_shl(a, d);
  return WASM_TEST_SUCCESS;
}

int wasm_i32x4_shl_test()
{
  V128_i32 a, b, c;
  int32_t d = 2;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i32x4_shl(a, d);
  return WASM_TEST_SUCCESS;
}

int wasm_i64x2_shl_test()
{
  V128_i64 a, b, c;
  int32_t d = 2;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i64x2_shl(a, d);
  return WASM_TEST_SUCCESS;
}

int wasm_v128_and_test()
{
  V128_i8 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_v128_and(a, b);
  return WASM_TEST_SUCCESS;
}

int wasm_v128_or_test()
{
  V128_i8 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_v128_or(a, b);
  return WASM_TEST_SUCCESS;
}

int wasm_v128_xor_test()
{
  V128_i8 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_v128_xor(a, b);
  return WASM_TEST_SUCCESS;
}

int wasm_v128_not_test()
{
  V128_i8 a, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  c = wasm_v128_not(a);
  return WASM_TEST_SUCCESS;
}

int wasm_i8x16_eq_test()
{
  V128_i8 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i8x16_eq(a, b);
  return WASM_TEST_SUCCESS;
}

int wasm_i16x8_eq_test()
{
  V128_i16 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i16x8_eq(a, b);
  return WASM_TEST_SUCCESS;
}

int wasm_i32x4_eq_test()
{
  V128_i32 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i32x4_eq(a, b);
  return WASM_TEST_SUCCESS;
}

int wasm_i8x16_ne_test()
{
  V128_i8 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i8x16_eq(a, b);
  return WASM_TEST_SUCCESS;
}

int wasm_i16x8_ne_test()
{
  V128_i16 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i16x8_eq(a, b);
  return WASM_TEST_SUCCESS;
}

int wasm_i32x4_ne_test()
{
  V128_i32 a, b, c;
  a = wasm_v128_const(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  b = wasm_v128_const(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
  c = wasm_i32x4_eq(a, b);
  return WASM_TEST_SUCCESS;
}
//end unit tests
*/
void InitializeTests()
{
  UnitTests.push_back(wasm_i8x16_const_test);
/*  
  UnitTests.push_back(wasm_i8x16_load_test);
  UnitTests.push_back(wasm_v128_load_test);
  UnitTests.push_back(wasm_v128_store_test);
  UnitTests.push_back(wasm_i8x16_splat_test);
  UnitTests.push_back(wasm_i16x8_splat_test);
  UnitTests.push_back(wasm_i32x4_splat_test);
  UnitTests.push_back(wasm_i64x2_splat_test);
  UnitTests.push_back(wasm_f32x4_splat_test);
  UnitTests.push_back(wasm_f64x2_splat_test);
  UnitTests.push_back(wasm_i8x16_extract_lane_s_test);
#ifdef __wasm_undefined_simd128__
  UnitTests.push_back(wasm_i8x16_extract_lane_u_test);
#endif
  UnitTests.push_back(wasm_i16x8_extract_lane_s_test);
#ifdef __wasm_undefined_simd128__
  UnitTests.push_back(wasm_i16x8_extract_lane_u_test);
#endif
  UnitTests.push_back(wasm_i32x4_extract_lane_test);
#ifdef __wasm_undefined_simd128__
  UnitTests.push_back(wasm_i64x2_extract_lane_test);
#endif
  UnitTests.push_back(wasm_f32x4_extract_lane_test);
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
  UnitTests.push_back(wasm_v128_shuffle_test);
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
  UnitTests.push_back(wasm_i8x16_shl_test);
  UnitTests.push_back(wasm_i16x8_shl_test);
  UnitTests.push_back(wasm_i32x4_shl_test);
  UnitTests.push_back(wasm_i64x2_shl_test);
  UnitTests.push_back(wasm_v128_and_test);
  UnitTests.push_back(wasm_v128_or_test);
  UnitTests.push_back(wasm_v128_xor_test);
  UnitTests.push_back(wasm_i8x16_eq_test);
  UnitTests.push_back(wasm_i16x8_eq_test);
  UnitTests.push_back(wasm_i32x4_eq_test);
  UnitTests.push_back(wasm_i8x16_ne_test);
  UnitTests.push_back(wasm_i16x8_ne_test);
  UnitTests.push_back(wasm_i32x4_ne_test);
  */
}


//main
int main()
{
  emscripten_set_click_callback("cbRun", (void *)0, 0, on_run_click);
  InitializeTests();
  EM_ASM(Module['noExitRuntime'] = true);
  return 0;
}
