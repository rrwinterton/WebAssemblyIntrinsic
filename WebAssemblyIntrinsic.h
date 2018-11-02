/*
Proposed WebAssembly SIMD Instructions 1 Sep 2018
*/

#include <stdint.h> //rrw where to get uintx_t's from?
typedef int8_t V128 __attribute__ ((__vector_size__(16))); //rrw
typedef int8_t V128_i8 __attribute__ ((__vector_size__(16)));
typedef uint8_t V128_u8 __attribute__ ((__vector_size__(16)));
typedef int16_t V128_i16 __attribute__ ((__vector_size__(16)));
typedef uint16_t V128_u16 __attribute__ ((__vector_size__(16)));
typedef int32_t V128_i32 __attribute__ ((__vector_size__(16)));
typedef uint32_t V128_u32 __attribute__ ((__vector_size__(16)));
typedef int64_t V128_i64 __attribute__ ((__vector_size__(16)));
typedef uint64_t V128_u64 __attribute__ ((__vector_size__(16)));
typedef float V128_f32 __attribute__ ((__vector_size__(16)));
typedef double V128_f64 __attribute__ ((__vector_size__(16)));

#define __DEFAULT_FN_ATTRS

//instruction: v128.const  i:ImmByte[16]
static __inline__ V128_i8 __DEFAULT_FN_ATTRS
wasm_v128_const(int8_t c15, int8_t c14, int8_t c13, int8_t c12, int8_t c11, int8_t c10, int8_t c9, int8_t c8, 
                int8_t c7, int8_t c6, int8_t c5, int8_t c4, int8_t c3, int8_t c2, int8_t c1, int8_t c0) {
                    return __extension__ (V128_i8){c0,c1,c2,c3,c4,c5,c6,c7,
                                                   c8,c9,c10,c11,c12,c13,c14,c15};
                } 

static __inline__ V128_i8 __DEFAULT_FN_ATTRS
wasm_v128_load(V128_i8 *mem) {
   return __extension__ (V128_i8) (*mem);
}

static __inline__ void __DEFAULT_FN_ATTRS
wasm_v128_store(V128_i8* mem, V128_i8 a) {
   *(V128_i8 *) mem = a;
   return;
}

//instruction: i8x16.splat
static __inline__ V128_i8 __DEFAULT_FN_ATTRS
wasm_i8x16_splat(int8_t a) {
    return __extension__ (V128_i8){a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a};
}

//instruction: i16x8.splat
static __inline__ V128_i16 __DEFAULT_FN_ATTRS
wasm_i16x8_splat(int16_t a) {
    return __extension__ (V128_i16){a,a,a,a,a,a,a,a};
}

//instruction: i32x4.splat
static __inline__ V128_i32 __DEFAULT_FN_ATTRS
wasm_i32x4_splat(int32_t a) {
    return __extension__ (V128_i32){a,a,a,a};
}


//instruction: i64x2.splat
static __inline__ V128_i64 __DEFAULT_FN_ATTRS
wasm_i64x2_splat(int64_t a) {
    return __extension__ (V128_i64){a,a};
}

//instruction: f32x4.splat
static __inline__ V128_f32 __DEFAULT_FN_ATTRS
wasm_f32x4_splat(float a) {
    return __extension__ (V128_f32){a,a,a,a};
}

//instruction: f64x2.splat
static __inline__ V128_f64 __DEFAULT_FN_ATTRS
wasm_f64x2_splat(double a) {
    return __extension__ (V128_f64){a,a};
}


static __inline__ V128_i8 __DEFAULT_FN_ATTRS
wasm_i8x16_add(V128_i8 a, V128_i8 b){
        return __extension__ (V128_i8) {a+b};    
}

static __inline__ V128_i8 __DEFAULT_FN_ATTRS
wasm_i8x16_sub(V128_i8 a, V128_i8 b){
        return __extension__ (V128_i8) {a-b};    
}


/*

//instruction: i8x16.extract_lane_s	i:LaneIdx16
static __inline__ int32_t __DEFAULT_FN_ATTRS
wasm_i8x16_extract_lane_s(V128_i8 a, uint32_t b) {
    return __builtin_wasm_extract_lane_s_i8x16(a, 1);
//    return __extension__ (a,b);
}

//instruction: i8x16.extract_lane_u	i:LaneIdx16
V128_u8 wasm_i8x16_extract_lane_u(int32_t c);

//instruction: i8x16.extract_lane_s	i:LaneIdx16
V128_i16 wasm_i16x8_extract_lane_s(int32_t c);

//instruction: i8x16.extract_lane_u	i:LaneIdx16
V128_u16 wasm_i16x8_extract_lane_u(int32_t c);

//instruction i32x4.extract_lane i:LaneIdx16
V128_u32 wasm_i32x4_extract_lane(int32_t c);

//instruction i64x2.extract_lane i:LaneIdx16
V128_u64 wasm_i64x2_extract_lane(int32_t c);

//instruction f32x4.extract_lane i:LaneIdx16
V128_f32 wasm_f32x4_extract_lane(int32_t c);

//instruction f64x2.extract_lane i:LaneIdx16
V128_f64 wasm_f64x2_extract_lane(int32_t c);

void wasm_i8x16_replace_lane(int8_t a, int32_t c);

void wasm_i16x8_replace_lane(int16_t a, int32_t c);

void wasm_i32x4_replace_lane(int32_t a, int32_t c);

void wasm_i64x2_replace_lane(int64_t a, int32_t c);

void wasm_f32x4_replace_lane(float a, int32_t c);

void wasm_f64x2_replace_lane(double a, int32_t c);

void wasm_v8x16_shuffle(V128_i8 a, V128_i8 b, int32_t c);

V128_i8 wasm_i8x16_add(V128_i8 a, V128_i8 b);

V128_i16 wasm_i16x8_add(V128_i16 a, V128_i16 b);

V128_i32 wasm_i32x4_add(V128_i32 a, V128_i32 b);

V128_i64 wasm_i64x2_add(V128_i64 a, V128_i64 b);

V128_i8 wasm_i8x16_sub(V128_i8 a, V128_i8 b) {
    return (V128_i8)((V128))
};

V128_i16 wasm_i16x8_sub(V128_i16 a, V128_i16 b);

V128_i32 wasm_i32x4_sub(V128_i32 a, V128_i32 b);

V128_i64 wasm_i64x2_sub(V128_i64 a, V128_i64 b);

V128_i16 wasm_i16x8_mul(V128_i16 a, V128_i16 b);

V128_i32 wasm_i32x4_mul(V128_i32 a, V128_i32 b);

V128_i64 wasm_i64x2_mul(V128_i64 a, V128_i64 b);

V128_i8 wasm_i8x16_neg(V128_i8 a); 

V128_i16 wasm_i16x8_neg(V128_i16 a);

V128_i32 wasm_i32x4_neg(V128_i32 a);

V128_i64 wasm_i64x2_neg(V128_i64 a);

V128_i8 wasm_i8x16_add_saturate_s(V128_i8 a, V128_i8 b);

V128_i8 wasm_i8x16_add_saturate_u(V128_i8 a, V128_i8 b);

V128_i16 wasm_i16x8_add_saturate_s(V128_i16 a, V128_i16 b);

V128_i16 wasm_i16x8_add_saturate_u(V128_i16 a, V128_i16 b);

V128_i16 wasm_i8x16_sub_saturate_s(V128_i8 a, V128_i8 b);

V128_i16 wasm_i8x16_sub_saturate_u(V128_i8 a, V128_i8 b);

V128_i16 wasm_i16x8_sub_saturate_s(V128_i16 a, V128_i16 b);

V128_i16 wasm_i16x8_sub_saturate_u(V128_i16 a, V128_i16 b);

V128_i8 wasm_i8x16_shl(V128_i8 a);

V128_i16 wasm_i16x8_shl(V128_i16 a);

V128_i32 wasm_i32x4_shl(V128_i32 a);

V128_i64 wasm_i64x2_shl(V128_i64 a);

V128_i8 wasm_i8x16_shr_s(V128_i8 a);

V128_i8 wasm_i8x16_shr_u(V128_i8 a);

V128_i16 wasm_i16x8_shr_s(V128_i16 a);

V128_i16 wasm_i16x8_shr_u(V128_i16 a);

V128_i32 wasm_i32x4_shr_s(V128_i32 a);

V128_i32 wasm_i32x4_shr_u(V128_i32 a);

V128_i64 wasm_i64x4_shr_s(V128_i64 a);

V128_i64 wasm_i64x4_shr_u(V128_i64 a);

//instruction: v128.and
V128_i8 wasm_v128_and(V128 a, V128 b);

//instruction: v128.or
V128 wasm_v128_or(V128 a, V128 b);

//instruction: v128.xor
V128 wasm_v128_xor(V128 a, V128 b);

//instruction: v128.not
V128 wasm_v128_not(V128 a);

V128 wasm_v128_bitselect(V128 a, V128 b, V128 c);

i8x16.any_true
i16x8.any_true
i32x4.any_true
i64x2.any_true


i8x16.all_true
i16x8.all_true
i32x4.all_true
i64x2.all_true
i8x16.eq
i16x8.eq
i32x4.eq
f32x4.eq
f64x2.eq
i8x16.ne
i16x8.ne
i32x4.ne
f32x4.ne
f64x2.ne
i8x16.lt_s
i8x16.lt_u
i16x8.lt_s
i16x8.lt_u
i32x4.lt_s
i32x4.lt_u
f32x4.lt
f64x2.lt
i8x16.le_s
i8x16.le_u
i16x8.le_s
i16x8.le_u
i32x4.le_s
i32x4.le_u
f32x4.le
f64x2.le
i8x16.gt_s
i8x16.gt_u
i16x8.gt_s
i16x8.gt_u
i32x4.gt_s
i32x4.gt_u
f32x4.gt
f64x2.gt
i8x16.ge_s
i8x16.ge_u
i16x8.ge_s
i16x8.ge_u
i32x4.ge_s
i32x4.ge_u
f32x4.ge
f64x2.ge
f32x4.neg
f64x2.neg
f32x4.abs
f64x2.abs
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
