#ifndef _WEBASSEMBLYINTRINSICTESTS_H
#define _WEBASSEMBLYINTRINSICTESTS_H 1

#define WASM_TEST_SUCCESS 0

#define NUMBER_OF_TESTS 50
#define WASM_TEST_GENERAL_FAIL -NUMBER_OF_TESTS

//has to be less than NUMBER_OF_TESTS
#define wasm_null_test_number 0
#define wasm_i8x16_const_test_number 1
#define wasm_i8x16_load_test_number 2
#define wasm_v128_load_test_number 3
#define wasm_v128_store_test_number 4
#define wasm_i8x16_splat_test_number 5
#define wasm_i16x8_splat_test_number 6
#define wasm_i32x4_splat_test_number 7
#define wasm_i64x2_splat_test_number 8
#define wasm_f32x4_splat_test_number 9
#define wasm_f64x2_splat_test_number 10
#define wasm_i8x16_extract_lane_s_test_number 11
#define wasm_i8x16_extract_lane_u_test_number 12
#define wasm_i16x8_extract_lane_s_test_number 13
#define wasm_i16x8_extract_lane_u_test_number 14
#define wasm_i32x4_extract_lane_test_number 15
#define wasm_i64x2_extract_lane_test_number 16
#define wasm_f32x4_extract_lane_test_number 17 //fail
#define wasm_f64x2_extract_lane_test_number 18 //fail
#define wasm_i8x16_replace_lane_test_number 19
#define wasm_i16x8_replace_lane_test_number 20
#define wasm_i32x4_replace_lane_test_number 21
#define wasm_i64x2_replace_lane_test_number 22
#define wasm_f32x4_replace_lane_test_number 23 //fail
#define wasm_f64x2_replace_lane_test_number 24 //fail
#define wasm_v128_shuffle_test_number 25
#define wasm_i8x16_add_test_number 26
#define wasm_i16x8_add_test_number 27
#define wasm_i32x4_add_test_number 28
#define wasm_i64x2_add_test_number 29
#define wasm_i8x16_sub_test_number 30
#define wasm_i16x8_sub_test_number 31
#define wasm_i32x4_sub_test_number 32
#define wasm_i64x2_sub_test_number 33
#define wasm_i8x16_mul_test_number 34
#define wasm_i16x8_mul_test_number 35
#define wasm_i32x4_mul_test_number 36
#define wasm_i8x16_shl_test_number 37
#define wasm_i16x8_shl_test_number 38
#define wasm_i32x4_shl_test_number 39
#define wasm_i64x2_shl_test_number 40
#define wasm_v128_and_test_number 41
#define wasm_v128_or_test_number 42
#define wasm_v128_xor_test_number 43
#define wasm_i8x16_eq_test_number 44
#define wasm_i16x8_eq_test_number 45
#define wasm_i32x4_eq_test_number 46
#define wasm_i8x16_ne_test_number 47
#define wasm_i16x8_ne_test_number 48
#define wasm_i32x4_ne_test_number 49

#endif 