/*
Proposed WebAssembly SIMD Instructions 08 March 2019
*/

//standard integer definitions
#include <stdint.h>  //rrw where to get uintx_t's from?
typedef char i8x16 __attribute__((__vector_size__(16)));
typedef int8_t V128 __attribute__((__vector_size__(16)));
typedef int8_t V128_i8 __attribute__((__vector_size__(16)));
typedef uint8_t V128_u8 __attribute__((__vector_size__(16)));
typedef int16_t V128_i16 __attribute__((__vector_size__(16)));
typedef uint16_t V128_u16 __attribute__((__vector_size__(16)));
typedef int32_t V128_i32 __attribute__((__vector_size__(16)));
typedef uint32_t V128_u32 __attribute__((__vector_size__(16)));
typedef int64_t V128_i64 __attribute__((__vector_size__(16)));
typedef uint64_t V128_u64 __attribute__((__vector_size__(16)));
typedef float V128_f32 __attribute__((__vector_size__(16)));
typedef double V128_f64 __attribute__((__vector_size__(16)));

// todo: include definitions from some where
#define __DEFAULT_FN_VIS_ATTRS __attribute__((used)) __attribute__((visibility("default")))
#define __DEFAULT_FN_ATTRS __attribute__((__always_inline__, __nodebug__))

//V128_i8 wasm_v128_constant(...)
static __inline__ V128_i8 __DEFAULT_FN_ATTRS wasm_v128_const(
        int8_t c15, int8_t c14, int8_t c13, int8_t c12,
        int8_t c11, int8_t c10, int8_t c9, int8_t c8,
        int8_t c7, int8_t c6, int8_t c5, int8_t c4, int8_t c3,
        int8_t c2, int8_t c1, int8_t c0) {
  return __extension__(V128_i8){c0, c1, c2,  c3,  c4,  c5,  c6,  c7,
                                c8, c9, c10, c11, c12, c13, c14, c15};
}

//wasm_v128_load(V128* mem)
static __inline__ V128 __DEFAULT_FN_ATTRS wasm_v128_load(V128* mem) {
  return __extension__(V128)(*mem);
}

//wasm_v128_store(V128 *mem, V128 a)
static __inline__ void __DEFAULT_FN_ATTRS wasm_v128_store(V128 *mem,
                                                          V128 a) {
  *(V128*)mem = a;
  return;
}

//wasm_i8x16_splat(int8_t a)
static __inline__ V128_i8 __DEFAULT_FN_ATTRS wasm_i8x16_splat(int8_t a) {
  return __extension__(V128_i8){a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a};
}

//wasm_i16x8_splat(int16_t a)
static __inline__ V128_i16 __DEFAULT_FN_ATTRS wasm_i16x8_splat(int16_t a) {
  return __extension__(V128_i16){a, a, a, a, a, a, a, a};
}

//wasm_i32x4_splat(int32_t a)
static __inline__ V128_i32 __DEFAULT_FN_ATTRS wasm_i32x4_splat(int32_t a) {
  return __extension__(V128_i32){a, a, a, a};
}

//wasm_i64x2_splat(int64_t a)
static __inline__ V128_i64 __DEFAULT_FN_ATTRS wasm_i64x2_splat(int64_t a) {
  return __extension__(V128_i64){a, a};
}

//wasm_f32x4_splat(float a)
static __inline__ V128_f32 __DEFAULT_FN_ATTRS wasm_f32x4_splat(float a) {
  return __extension__(V128_f32){a, a, a, a};
}

//wasm_f64x2_splat(double a)
static __inline__ V128_f64 __DEFAULT_FN_ATTRS wasm_f64x2_splat(double a) {
  return __extension__(V128_f64){a, a};
}

//int32_t wasm_i8x16_extract_lane(V128_i8 a, imm)
#define wasm_i8x16_extract_lane(a, b) \
  (__builtin_wasm_extract_lane_s_i8x16(a, b))

//int32_t wasm_i16x8_extract_lane(V128_i16 a, imm)
#define wasm_i16x8_extract_lane(a, b) \
  (__builtin_wasm_extract_lane_s_i16x8(a, b))

//int32_t wasm_i32x4_extract_lane(V128_i32 a, imm)
#define wasm_i32x4_extract_lane(a, b) (__builtin_wasm_extract_lane_i32x4(a, b))

//int64_t wasm_i64x2_extract_lane(V128_i64, imm)
#define wasm_i64x2_extract_lane(a, b) (__builtin_wasm_extract_lane_i64x2(a, b))

//float __builtin_wasm_extract_lane_f32x4(V128_f32, imm)
#define wasm_f32x4_extract_lane(a, b) (__builtin_wasm_extract_lane_f32x4(a, b))

//double __builtin_wasm_extract_lane_f64x2(V128_f64, imm)
#ifdef __wasm_undefined_simd128__
#define wasm_f64x2_extract_lane(a, b) (__builtin_wasm_extract_lane_f64x2(a, b))
#endif

//wasm_i8x16_replace_lane(V128_i8 a, imm i, int32_t b)
#define wasm_i8x16_replace_lane(a, i, b) \
  (__builtin_wasm_replace_lane_i8x16(a, i, b))

//wasm_i16x8_replace_lane(V128_i16 a, imm i, int32_t b)
#define wasm_i16x8_replace_lane(a, i, b) \
  (__builtin_wasm_replace_lane_i16x8(a, i, b))

//wasm_i32x4_replace_lane(V128_i32 a, imm i, int32_t b)
#define wasm_i32x4_replace_lane(a, i, b) \
  (__builtin_wasm_replace_lane_i32x4(a, i, b))

//wasm_i64x4_replace_lane(V128_i64 a, imm i, int64_t b)
#define wasm_i64x2_replace_lane(a, i, b) \
  (__builtin_wasm_replace_lane_i64x2(a, i, b))

//wasm_f32x4_replace_lane(V128_f32 a, imm i, float b)
#define wasm_f32x4_replace_lane(a, i, b) \
  (__builtin_wasm_replace_lane_f32x4(a, i, b))

#ifdef __wasm_unimplemented_simd128__
//V128_f64 wasm_f64x4_replace_lane(V128_f64 a, imm i, double b)
#define wasm_f64x2_replace_lane(a, i, b) \
  (__builtin_wasm_replace_lane_f64x2(a, i, b))
#endif

//todo: wasm_i8x16_shuffle not sure how to do the shuffles variable input for s?
#define wasm_i8x16_shuffle(a, b, s)                                            \
  (__builtin_shufflevector(a, b, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, \
                           14, 15))

//V128_i8 wasm_i8x16_add(V128_i8 a V128_i8 b)
static __inline__ V128_i8 __DEFAULT_FN_ATTRS wasm_i8x16_add(V128_i8 a,
                                                            V128_i8 b) {
  return __extension__(V128_i8){a + b};
}

//V128_i16 wasm_i16x8_add(V128_i16 a V128_i16 b)
static __inline__ V128_i16 __DEFAULT_FN_ATTRS wasm_i16x8_add(V128_i16 a,
                                                             V128_i16 b) {
  return __extension__(V128_i16){a + b};
}

//V128_i32 wasm_i32x4_add(V128_i32 a V128_i32 b)
static __inline__ V128_i32 __DEFAULT_FN_ATTRS wasm_i32x4_add(V128_i32 a,
                                                             V128_i32 b) {
  return __extension__(V128_i32){a + b};
}

//V128_i64 wasm_i64x2_add(V128_i64 a V128_i64 b)
static __inline__ V128_i64 __DEFAULT_FN_ATTRS wasm_i64x2_add(V128_i64 a,
                                                             V128_i64 b) {
  return __extension__(V128_i64){a + b};
}

//V128_i8 wasm_i8x16_sub(V128_i8 a, V128_i8 b)
static __inline__ V128_i8 __DEFAULT_FN_ATTRS wasm_i8x16_sub(V128_i8 a,
                                                            V128_i8 b) {
  return __extension__(V128_i8){a - b};
}

//V128_i16 wasm_i16x8_sub(V128_i16 a V128_i16 b)
static __inline__ V128_i16 __DEFAULT_FN_ATTRS wasm_i16x8_sub(V128_i16 a,
                                                             V128_i16 b) {
  return __extension__(V128_i16){a - b};
}

//V128_i32 wasm_i32x4_sub(V128_i32 a V128_i32 b)
static __inline__ V128_i32 __DEFAULT_FN_ATTRS wasm_i32x4_sub(V128_i32 a,
                                                             V128_i32 b) {
  return __extension__(V128_i32){a - b};
}

//V128_i64 wasm_i64x2_sub(V128_i64 a V128_i64 b)
static __inline__ V128_i64 __DEFAULT_FN_ATTRS wasm_i64x2_sub(V128_i64 a,
                                                             V128_i64 b) {
  return __extension__(V128_i64){a - b};
}

//V128_i8 wasm_i8x16_mul(V128_i8 a V128_i8 b)
static __inline__ V128_i8 __DEFAULT_FN_ATTRS wasm_i8x16_mul(V128_i8 a,
                                                            V128_i8 b) {
  return __extension__(V128_i8){a * b};
}

//V128_i16 wasm_i16x8_mul(V128_i16 a V128_i16 b)
static __inline__ V128_i16 __DEFAULT_FN_ATTRS wasm_i16x8_mul(V128_i16 a,
                                                             V128_i16 b) {
  return __extension__(V128_i16){a * b};
}

//V128_i32 wasm_i32x4_mul(V128_i32 a V128_i32 b)
static __inline__ V128_i32 __DEFAULT_FN_ATTRS wasm_i32x4_mul(V128_i32 a,
                                                             V128_i32 b) {
  return __extension__(V128_i32){a * b};
}

//V128_i64 wasm_i64x4_mul(V128_i64 a V128_i64 b)
static __inline__ V128_i64 __DEFAULT_FN_ATTRS wasm_i64x2_mul(V128_i64 a,
                                                             V128_i64 b) {
  return __extension__(V128_i64){a * b};
}

//V128_i8 wasm_i8x16_neg(V128_i8 a)
static __inline__ V128_i8 __DEFAULT_FN_ATTRS wasm_i8x16_neg(V128_i8 a) {
  return __extension__(V128_i8){-a};
}

//V128_i16 wasm_i16x8_neg(V128_i16 a)
static __inline__ V128_i16 __DEFAULT_FN_ATTRS wasm_i16x8_neg(V128_i16 a) {
  return __extension__(V128_i16){-a};
}

//V128_i32 wasm_i32x4_neg(V128_i32 a)
static __inline__ V128_i32 __DEFAULT_FN_ATTRS wasm_i32x4_neg(V128_i32 a) {
  return __extension__(V128_i32){-a};
}

//V128_i64 wasm_i64x2_neg(V128_i64 a)
static __inline__ V128_i64 __DEFAULT_FN_ATTRS wasm_i64x2_neg(V128_i64 a) {
  return __extension__(V128_i64){-a};
}

//V128_f32 wasm_f32x4_neg(V128_f32 a)
static __inline__ V128_f32 __DEFAULT_FN_ATTRS wasm_f32x4_neg(V128_f32 a) {
  return __extension__(V128_f32){-a};
}

//V128_f64 wasm_f64x2_neg(V128_f64 a)
static __inline__ V128_f64 __DEFAULT_FN_ATTRS wasm_f64x2_neg(V128_f64 a) {
  return __extension__(V128_f64){-a};
}

//V128_i8 wasm_add_saturate_s(V128_i8 a, V128_i8 b)
#define wasm_i8x16_add_saturate_s(a, b) \
  (__builtin_wasm_add_saturate_s_i8x16(a, b))

//V128_i8 wasm_add_saturate_u(V128_i8 a, V128_i8 b)
#define wasm_i8x16_add_saturate_u(a, b) \
  (__builtin_wasm_add_saturate_u_i8x16(a, b))

//V128_i16 wasm_add_saturate_s(V128_i16 a, V128_i16 b)
#define wasm_i16x8_add_saturate_s(a, b) \
  (__builtin_wasm_add_saturate_s_i16x8(a, b))

//V128_i16 wasm_add_saturate_u(V128_i16 a, V128_i16 b)
#define wasm_i16x8_add_saturate_u(a, b) \
  (__builtin_wasm_add_saturate_u_i16x8(a, b))

//V128_i8 wasm_sub_saturate_s(V128_i8 a, V128_i8 b)
#define wasm_i8x16_sub_saturate_s(a, b) \
  (__builtin_wasm_sub_saturate_s_i8x16(a, b))

//V128_i8 wasm_sub_saturate_u(V128_i8 a, V128_i8 b)
#define wasm_i8x16_sub_saturate_u(a, b) \
  (__builtin_wasm_sub_saturate_u_i8x16(a, b))

//V128_i16 wasm_sub_saturate_s(V128_i16 a, V128_i16 b)
#define wasm_i16x8_sub_saturate_s(a, b) \
  (__builtin_wasm_sub_saturate_s_i16x8(a, b))

//V128_i16 wasm_sub_saturate_u(V128_i16 a, V128_i16 b)
#define wasm_i16x8_sub_saturate_u(a, b) \
  (__builtin_wasm_sub_saturate_u_i16x8(a, b))

//V128_i8 wasm_i8x16_shl(V128_i8 a, int32_t b)
static __inline__ V128_i8 __DEFAULT_FN_ATTRS wasm_i8x16_shl(V128_i8 a,
                                                            int32_t b) {
  return __extension__(V128_i8){a << b};
}

//V128_i16 wasm_i8x16_shl(V128_i16 a, int32_t b)
static __inline__ V128_i16 __DEFAULT_FN_ATTRS wasm_i16x8_shl(V128_i16 a,
                                                             int32_t b) {
  return __extension__(V128_i16){a << b};
}

//V128_i32 wasm_i8x16_shl(V128_i32 a, int32_t b)
static __inline__ V128_i32 __DEFAULT_FN_ATTRS wasm_i32x4_shl(V128_i32 a,
                                                             int32_t b) {
  return __extension__(V128_i32){a << b};
}

static __inline__ V128_i64 __DEFAULT_FN_ATTRS wasm_i64x2_shl(V128_i64 a,
                                                             int32_t b) {
  return __extension__(V128_i64){a << b};
}

static __inline__ V128_i8 __DEFAULT_FN_ATTRS wasm_i8x16_shr_s(V128_i8 a,
                                                              int32_t b) {
  return __extension__(V128_i8){a >> b};
}

static __inline__ V128_i8 __DEFAULT_FN_ATTRS wasm_i8x16_shr_u(V128_u8 a,
                                                              int32_t b) {
  return __extension__(V128_u8){a >> b};
}

static __inline__ V128_i16 __DEFAULT_FN_ATTRS wasm_i16x8_shr_s(V128_i16 a,
                                                               int32_t b) {
  return __extension__(V128_i16){a >> b};
}

static __inline__ V128_i16 __DEFAULT_FN_ATTRS wasm_i16x8_shr_u(V128_u16 a,
                                                               int32_t b) {
  return __extension__(V128_u16){a >> b};
}

static __inline__ V128_i32 __DEFAULT_FN_ATTRS wasm_i32x4_shr_s(V128_i32 a,
                                                               int32_t b) {
  return __extension__(V128_i32){a >> b};
}

static __inline__ V128_i32 __DEFAULT_FN_ATTRS wasm_i32x4_shr_u(V128_u32 a,
                                                               int32_t b) {
  return __extension__(V128_u32){a >> b};
}

static __inline__ V128_i64 __DEFAULT_FN_ATTRS wasm_i64x2_shr_s(V128_i64 a,
                                                               int32_t b) {
  return __extension__(V128_i64){a >> b};
}

static __inline__ V128_i64 __DEFAULT_FN_ATTRS wasm_i64x2_shr_u(V128_u64 a,
                                                               int32_t b) {
  return __extension__(V128_u64){a >> b};
}

static __inline__ V128_i8 __DEFAULT_FN_ATTRS wasm_v128_and(V128 a, V128 b) {
  return __extension__(V128_i64){a & b};
}

static __inline__ V128_i8 __DEFAULT_FN_ATTRS wasm_v128_or(V128 a, V128 b) {
  return __extension__(V128_i64){a | b};
}

static __inline__ V128_i8 __DEFAULT_FN_ATTRS wasm_v128_xor(V128 a, V128 b) {
  return __extension__(V128_i64){a ^ b};
}

static __inline__ V128_i8 __DEFAULT_FN_ATTRS wasm_v128_not(V128 a) {
  return __extension__(V128_i64){~a};
}

#define wasm_v128_bitselect(a, b, c) (__builtin_wasm_bitselect(a, b, c))

#define wasm_v128_i8_any_true(a) (__builtin_wasm_any_true_i8x16(a))

#define wasm_v128_i16_any_true(a) (__builtin_wasm_any_true_i16x8(a))

#define wasm_v128_i32_any_true(a) (__builtin_wasm_any_true_i32x4(a))

#ifdef __wasm_undefined_simd128__
#define wasm_v128_i64_any_true(a) (__builtin_wasm_any_true_i64x2(a))
#endif

static __inline__ V128_i8 __DEFAULT_FN_ATTRS wasm_i8x16_eq(V128_i8 a,
                                                           V128_i8 b) {
  return __extension__(V128_i8){a == b};
}

static __inline__ V128_i16 __DEFAULT_FN_ATTRS wasm_i16x8_eq(V128_i16 a,
                                                            V128_i16 b) {
  return __extension__(V128_i16){a == b};
}

static __inline__ V128_i32 __DEFAULT_FN_ATTRS wasm_i32x4_eq(V128_i32 a,
                                                            V128_i32 b) {
  return __extension__(V128_i32){a == b};
}

static __inline__ V128_f32 __DEFAULT_FN_ATTRS wasm_f32x4_eq(V128_f32 a,
                                                            V128_f32 b) {
  return __extension__(V128_f32){a == b};
}

static __inline__ V128_i8 __DEFAULT_FN_ATTRS wasm_i8x16_ne(V128_i8 a,
                                                           V128_i8 b) {
  return __extension__(V128_i8){a != b};
}

static __inline__ V128_i16 __DEFAULT_FN_ATTRS wasm_i16x8_ne(V128_i16 a,
                                                            V128_i16 b) {
  return __extension__(V128_i16){a != b};
}

static __inline__ V128_i32 __DEFAULT_FN_ATTRS wasm_i32x4_ne(V128_i32 a,
                                                            V128_i32 b) {
  return __extension__(V128_i32){a != b};
}

//V128_i8 wasm_i8x16_lt_s(V128_i8 a, V128_i8)
static __inline__ V128_i8 wasm_i8x16_lt_s(V128_i8 a, V128_i8 b) {
  return __extension__(V128_i8){a < b};
}

//V128_i8 wasm_i8x16_lt_u(V128_u8 a, V128_u8)
static __inline__ V128_u8 wasm_i8x16_lt_u(V128_u8 a, V128_u8 b) {
  return __extension__(V128_u8){a < b};
}

//V128_i16 wasm_i16x8_lt_s(V128_i16 a, V128_i16)
static __inline__ V128_i16 wasm_i16x8_lt_s(V128_i16 a, V128_i16 b) {
  return __extension__(V128_i16){a < b};
}

//V128_i16 wasm_i16x8_lt_u(V128_u16 a, V128_u16)
static __inline__ V128_u16 wasm_i16x8_lt_u(V128_u16 a, V128_u16 b) {
  return __extension__(V128_u16){a < b};
}

//V128_i32 wasm_i32x4_lt_s(V128_i32 a, V128_i32 b)
static __inline__ V128_i32 wasm_i32x4_lt_s(V128_i32 a, V128_i32 b) {
  return __extension__(V128_i32){a < b};
}

//V128_i32 wasm_i32x4_lt_u(V128_u32 a, V128_u32 b)
static __inline__ V128_u32 wasm_i32x4_lt_u(V128_u32 a, V128_u32 b) {
  return __extension__(V128_u32){a < b};
}

//V128_f32 wasm_f32x4_lt(V128_f32 a, V128_f32 b)
static __inline__ V128_f32 wasm_f32x4_lt(V128_f32 a, V128_f32 b) {
  return __extension__(V128_f32){a < b};
}

//V128_f64 wasm_f64x2_lt(V128_f64 a, V128_f64 b)
static __inline__ V128_f64 wasm_f64x2_lt(V128_f64 a, V128_f64 b) {
  return __extension__(V128_f64){a < b};
}

//V128_i8 wasm_i8x16_le_s(V128_i8 a, V128_i8)
static __inline__ V128_i8 wasm_i16x8_le_s(V128_i8 a, V128_i8 b) {
  return __extension__(V128_i8){a <= b};
}

//V128_i8 wasm_i8x16_le_u(V128_u8 a, V128_u8)
static __inline__ V128_u8 wasm_i16x8_le_u(V128_u8 a, V128_u8 b) {
  return __extension__(V128_u8){a <= b};
}

//V128_i16 wasm_i16x8_le_s(V128_i16 a, V128_i16)
static __inline__ V128_i16 wasm_i16x8_le_s(V128_i16 a, V128_i16 b) {
  return __extension__(V128_i16){a <= b};
}

//V128_i16 wasm_i16x8_le_u(V128_u16 a, V128_u16)
static __inline__ V128_u16 wasm_i16x8_le_u(V128_u16 a, V128_u16 b) {
  return __extension__(V128_u16){a <= b};
}

//V128_i32 wasm_i32x4_le_s(V128_i32 a, V128_i32 b)
static __inline__ V128_i32 wasm_i32x4_le_s(V128_i32 a, V128_i32 b) {
  return __extension__(V128_i32){a <= b};
}

//V128_i32 wasm_i32x4_le_u(V128_u32 a, V128_u32 b)
static __inline__ V128_u32 wasm_i32x4_le_u(V128_u32 a, V128_u32 b) {
  return __extension__(V128_u32){a <= b};
}

//V128_f32 wasm_f32x4_le(V128_f32 a, V128_f32 b)
static __inline__ V128_f32 wasm_f32x4_le(V128_f32 a, V128_f32 b) {
  return __extension__(V128_f32){a <= b};
}

//V128_f64 wasm_f64x2_le(V128_f64 a, V128_f64 b)
static __inline__ V128_f64 wasm_f64x2_le(V128_f64 a, V128_f64 b) {
  return __extension__(V128_f64){a <= b};
}

//V128_i8 wasm_i8x16_gt_s(V128_i8 a, V128_i8)
static __inline__ V128_i8 wasm_i16x8_gt_s(V128_i8 a, V128_i8 b) {
  return __extension__(V128_i8){a > b};
}

//V128_i8 wasm_i8x16_gt_u(V128_u8 a, V128_u8)
static __inline__ V128_u8 wasm_i16x8_gt_u(V128_u8 a, V128_u8 b) {
  return __extension__(V128_u8){a > b};
}

//V128_i16 wasm_i16x8_gt_s(V128_i16 a, V128_i16)
static __inline__ V128_i16 wasm_i16x8_gt_s(V128_i16 a, V128_i16 b) {
  return __extension__(V128_i16){a > b};
}

//V128_i16 wasm_i16x8_gt_u(V128_u16 a, V128_u16)
static __inline__ V128_u16 wasm_i16x8_gt_u(V128_u16 a, V128_u16 b) {
  return __extension__(V128_u16){a > b};
}

//V128_i32 wasm_i32x4_gt_s(V128_i32 a, V128_i32 b)
static __inline__ V128_i32 wasm_i32x4_gt_s(V128_i32 a, V128_i32 b) {
  return __extension__(V128_i32){a > b};
}

//V128_i32 wasm_i32x4_gt_u(V128_u32 a, V128_u32 b)
static __inline__ V128_u32 wasm_i32x4_gt_u(V128_u32 a, V128_u32 b) {
  return __extension__(V128_u32){a > b};
}

//V128_f32 wasm_f32x4_gt(V128_f32 a, V128_f32 b)
static __inline__ V128_f32 wasm_f32x4_gt(V128_f32 a, V128_f32 b) {
  return __extension__(V128_f32){a > b};
}

//V128_f64 wasm_f64x2_gt(V128_f64 a, V128_f64 b)
static __inline__ V128_f64 wasm_f64x2_gt(V128_f64 a, V128_f64 b) {
  return __extension__(V128_f64){a > b};
}

//V128_i8 wasm_i8x16_ge_s(V128_i8 a, V128_i8)
static __inline__ V128_i8 wasm_i16x8_ge_s(V128_i8 a, V128_i8 b) {
  return __extension__(V128_i8){a >= b};
}

//V128_i8 wasm_i8x16_ge_u(V128_u8 a, V128_u8)
static __inline__ V128_u8 wasm_i16x8_ge_u(V128_u8 a, V128_u8 b) {
  return __extension__(V128_u8){a >= b};
}

//V128_i16 wasm_i16x8_ge_s(V128_i16 a, V128_i16)
static __inline__ V128_i16 wasm_i16x8_ge_s(V128_i16 a, V128_i16 b) {
  return __extension__(V128_i16){a >= b};
}

//V128_i16 wasm_i16x8_ge_u(V128_u16 a, V128_u16)
static __inline__ V128_u16 wasm_i16x8_ge_u(V128_u16 a, V128_u16 b) {
  return __extension__(V128_u16){a >= b};
}

//V128_i32 wasm_i32x4_ge_s(V128_i32 a, V128_i32 b)
static __inline__ V128_i32 wasm_i32x4_ge_s(V128_i32 a, V128_i32 b) {
  return __extension__(V128_i32){a >= b};
}

//V128_i32 wasm_i32x4_ge_u(V128_u32 a, V128_u32 b)
static __inline__ V128_u32 wasm_i32x4_ge_u(V128_u32 a, V128_u32 b) {
  return __extension__(V128_u32){a >= b};
}

//V128_f32 wasm_f32x4_ge(V128_f32 a, V128_f32 b)
static __inline__ V128_f32 wasm_f32x4_ge(V128_f32 a, V128_f32 b) {
  return __extension__(V128_f32){a >= b};
}

//V128_f64 wasm_f64x2_ge(V128_f64 a, V128_f64 b)
static __inline__ V128_f64 wasm_f64x2_ge(V128_f64 a, V128_f64 b) {
  return __extension__(V128_f32){a >= b};
}

//V128_i8  wasm_v128_i8_abs(V128_i8 a)
#define wasm_v128_i8_abs(a) (__builtin_wasm_abs_i8x16(a))

//V128_i16  wasm_v128_i16_abs(V128_i16 a)
#define wasm_v128_i16_abs(a) (__builtin_wasm_abs_i16x8(a))

//V128_i32  wasm_v128_i32_abs(V128_i32 a)
#define wasm_v128_i32_abs(a) (__builtin_wasm_abs_i32x4(a))

//V128_i64  wasm_v128_i64_abs(V128_i64 a)
#define wasm_v128_i64_abs(a) (__builtin_wasm_abs_i64x2(a))

//V128_f32  wasm_v128_f32_abs(V128_f32 a)
#define wasm_v128_f32_abs(a) (__builtin_wasm_abs_f32x4(a))

//V128_f64  wasm_v128_i64_abs(V128_f64 a)
#define wasm_v128_f64_abs(a) (__builtin_wasm_abs_f64x2(a))

// rrw not sure how this should work with variable input
#define wasm_v128_shuffle(a, b) \
  (__builtin_shufflevector(a, b, 0, 1, 2, 3, 4, 5, 6, 7))

//converts float and doubles to int
//
#define wasm_convert_s_f32x4_i32x4(a, b) (__builtin_convertvector(a, b))
#define wasm_convert_u_f32x4_i32x4(f32x4, v) (__builtin_convertvector(v, f32x4))
#define wasm_convert_s_f64x2_i64x2(f64x2, v) (__builtin_convertvector(v, f64x2))
#define wasm_convert_u_f64x2_i64x2(f64x2, v) (__builtin_convertvector(v, f64x2))
//
/*
f32x4.min
f64x2.min
f32x4.max
f64x2.max
f32x4.add
f64x2.add
f32x4.sub
f64x2.sub
f32x4.div
f64x2.div
f32x4.mul
f64x2.mul
f32x4.sqrt
f64x2.sqrt
f32x4.convert_s/i32x4
f32x4.convert_u/i32x4
f64x2.convert_s/i64x2
f64x2.convert_u/i64x2
i32x4.trunc_s/f32x4:sat
i32x4.trunc_u/f32x4:sat
i64x2.trunc_s/f64x2:sat
i64x2.trunc_u/f64x2:sat
*/
