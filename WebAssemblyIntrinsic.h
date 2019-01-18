/*
Proposed WebAssembly SIMD Instructions 14 Jan 2019
*/

#include <stdint.h> //rrw where to get uintx_t's from?
typedef char i8x16 __attribute__ ((__vector_size__(16)));
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

//rrw is there a common definition for this?
#define __DEFAULT_FN_VIS_ATTRS __attribute__((used)) __attribute__((visibility("default")))
#define __DEFAULT_FN_ATTRS __attribute__((__always_inline__,__nodebug__))

//v128.const  i:ImmByte[16]
static __inline__ V128_i8 __DEFAULT_FN_ATTRS
wasm_v128_const(int8_t c15, int8_t c14, int8_t c13, int8_t c12, int8_t c11, int8_t c10, int8_t c9, int8_t c8, 
                int8_t c7, int8_t c6, int8_t c5, int8_t c4, int8_t c3, int8_t c2, int8_t c1, int8_t c0) {
                    return __extension__ (V128_i8){c0,c1,c2,c3,c4,c5,c6,c7,
                                                   c8,c9,c10,c11,c12,c13,c14,c15};
                } 
//v128_load(*memory)
static __inline__ V128 __DEFAULT_FN_ATTRS
wasm_v128_load(V128 *mem) {
   return __extension__ (V128) (*mem);
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

static __inline__ V128_i16 __DEFAULT_FN_ATTRS
wasm_i16x8_add(V128_i16 a, V128_i16 b){
        return __extension__ (V128_i16) {a+b};    
}

static __inline__ V128_i32 __DEFAULT_FN_ATTRS
wasm_i32x4_add(V128_i32 a, V128_i32 b) {
        return __extension__ (V128_i32) {a+b};    
}

static __inline__ V128_i64 __DEFAULT_FN_ATTRS
wasm_i64x2_add(V128_i64 a, V128_i64 b) {
        return __extension__ (V128_i64) {a+b};    
}

static __inline__ V128_i16 __DEFAULT_FN_ATTRS
wasm_i16x8_sub(V128_i16 a, V128_i16 b){
        return __extension__ (V128_i16) {a-b};    
}

static __inline__ V128_i32 __DEFAULT_FN_ATTRS
wasm_i32x4_sub(V128_i32 a, V128_i32 b) {
        return __extension__ (V128_i32) {a-b};    
}

static __inline__ V128_i64 __DEFAULT_FN_ATTRS
wasm_i64x2_sub(V128_i64 a, V128_i64 b) {
        return __extension__ (V128_i64) {a-b};    
}

static __inline__ V128_i8 __DEFAULT_FN_ATTRS
wasm_i8x16_sub(V128_i8 a, V128_i8 b){
        return __extension__ (V128_i8) {a-b};    
}

static __inline__ V128_i8 __DEFAULT_FN_ATTRS
wasm_i8x16_mul(V128_i8 a, V128_i8 b){
        return __extension__ (V128_i8) {a*b};    
}

static __inline__ V128_i16 __DEFAULT_FN_ATTRS
wasm_i16x8_mul(V128_i16 a, V128_i16 b) {
        return __extension__ (V128_i16) {a*b};    
}

static __inline__ V128_i32 __DEFAULT_FN_ATTRS
wasm_i32x4_mul(V128_i32 a, V128_i32 b) {
        return __extension__ (V128_i32) {a*b};    
}

static __inline__ V128_i8 __DEFAULT_FN_ATTRS
wasm_i8x16_shl(V128_i8 a, int32_t b){
        return __extension__ (V128_i8) {a<<b};    
}

static __inline__ V128_i16 __DEFAULT_FN_ATTRS
wasm_i16x8_shl(V128_i16 a, int32_t b) {
        return __extension__ (V128_i16) {a<<b};    
}

static __inline__ V128_i32 __DEFAULT_FN_ATTRS
wasm_i32x4_shl(V128_i32 a, int32_t b) {
        return __extension__ (V128_i32) {a<<b};    
}

static __inline__ V128_i64 __DEFAULT_FN_ATTRS
wasm_i64x2_shl(V128_i64 a, int32_t b) {
        return __extension__ (V128_i64) {a<<b};    
}

static __inline__ V128_i8 __DEFAULT_FN_ATTRS
wasm_i8x16_shr_u(V128_i8 a, int32_t b){
        return __extension__ (V128_i8) {a>>b};    
}

static __inline__ V128_i16 __DEFAULT_FN_ATTRS
wasm_i16x8_shr_u(V128_i16 a, int32_t b) {
        return __extension__ (V128_i16) {a>>b};    
}

static __inline__ V128_i32 __DEFAULT_FN_ATTRS
wasm_i32x4_shr_u(V128_i32 a, int32_t b) {
        return __extension__ (V128_i32) {a>>b};    
}

static __inline__ V128_i64 __DEFAULT_FN_ATTRS
wasm_i64x2_shr_u(V128_i64 a, int32_t b) {
        return __extension__ (V128_i64) {a>>b};    
}

//instruction: v128.and
static __inline__ V128_i8 __DEFAULT_FN_ATTRS
wasm_v128_and(V128 a, V128 b){
        return __extension__ (V128_i64) {a&b};    
}

static __inline__ V128_i8 __DEFAULT_FN_ATTRS
wasm_v128_or(V128 a, V128 b){
        return __extension__ (V128_i64) {a|b};    
}

//instruction: v128.not
static __inline__ V128_i8 __DEFAULT_FN_ATTRS
wasm_v128_not(V128 a){
        return __extension__ (V128_i64) {~a};    
}

//instruction: v128.xor
static __inline__ V128_i8 __DEFAULT_FN_ATTRS
wasm_v128_xor(V128 a,  V128 b){
        return __extension__ (V128_i64) {a^b};    
}

static __inline__ V128_i8 __DEFAULT_FN_ATTRS
wasm_i8x16_eq(V128_i8 a, V128_i8 b){
        return __extension__ (V128_i8) {a = b};    
}

static __inline__ V128_i16 __DEFAULT_FN_ATTRS
wasm_i16x8_eq(V128_i16 a, V128_i16 b) {
        return __extension__ (V128_i16) {a = b};    
}

static __inline__ V128_i32 __DEFAULT_FN_ATTRS
wasm_i32x4_eq(V128_i32 a, V128_i32 b) {
        return __extension__ (V128_i32) {a = b};   
}

static __inline__ V128_i8 __DEFAULT_FN_ATTRS
wasm_i8x16_ne(V128_i8 a, V128_i8 b){
        return __extension__ (V128_i8) {a = b};    
}

static __inline__ V128_i16 __DEFAULT_FN_ATTRS
wasm_i16x8_ne(V128_i16 a, V128_i16 b) {
        return __extension__ (V128_i16) {a = b};    
}

static __inline__ V128_i32 __DEFAULT_FN_ATTRS
wasm_i32x4_ne(V128_i32 a, V128_i32 b) {
        return __extension__ (V128_i32) {a = b};   
}

//i8x16.extract_lane_s	i:LaneIdx16
#define wasm_i8x16_extract_lane_s(a, b) (__builtin_wasm_extract_lane_s_i8x16(a,b))

//instruction: i8x16.extract_lane_u	i:LaneIdx16
#ifdef __wasm_undefined_simd128__
#define wasm_i8x16_extract_lane_u(a, b) (__builtin_wasm_extract_lane_u_i8x16(a,b))
#endif

//instruction: i16x8.extract_lane_s	i:LaneIdx8
#define wasm_i16x8_extract_lane_s(a, b) (__builtin_wasm_extract_lane_s_i16x8(a,b))

//instruction: i16x8.extract_lane_u	i:LaneIdx8
#ifdef __wasm_undefined_simd128__
#define wasm_i16x8_extract_lane_u(a, b) (__builtin_wasm_extract_lane_u_i16x8(a,b))
#endif

//instruction: i32x4.extract_lane	i:LaneIdx4  //rrw why not signed and unsigned 32's
#define wasm_i32x4_extract_lane(a, b) (__builtin_wasm_extract_lane_i32x4(a,b))

//instruction: i64x2.extract_lane	i:LaneIdx2
#define wasm_i64x2_extract_lane(a, b) (__builtin_wasm_extract_lane_i64x2(a,b))

//instruction f32x4.extract_lane i:LaneIdx4
#define wasm_f32x4_extract_lane(a, b) (__builtin_wasm_extract_lane_f32x4(a,b))

//instruction f64x2.extract_lane i:LaneIdx2
#ifdef __wasm_undefined_simd128__
#define wasm_f64x2_extract_lane(a, b) (__builtin_wasm_extract_lane_f64x2(a,b))
#endif

#define wasm_i8x16_replace_lane(a, i, b) (__builtin_wasm_replace_lane_i8x16(a, i, b))

#define wasm_i16x8_replace_lane(a, i, b) (__builtin_wasm_replace_lane_i16x8(a, i, b))

#define wasm_i32x4_replace_lane(a, i, b) (__builtin_wasm_replace_lane_i32x4(a, i, b))

#define wasm_i64x2_replace_lane(a, i, b) (__builtin_wasm_replace_lane_i64x2(a, i, b))

#define wasm_f32x4_replace_lane(a, i, b) (__builtin_wasm_replace_lane_f32x4(a, i, b))

#define wasm_f64x2_replace_lane(a, i, b) (__builtin_wasm_replace_lane_f64x2(a, i, b))

/*
// identity operation - return 4-element vector v1.
__builtin_shufflevector(v1, v1, 0, 1, 2, 3)

// "Splat" element 0 of V1 into a 4-element result.
__builtin_shufflevector(V1, V1, 0, 0, 0, 0)

// Reverse 4-element vector V1.
__builtin_shufflevector(V1, V1, 3, 2, 1, 0)

// Concatenate every other element of 4-element vectors V1 and V2.
__builtin_shufflevector(V1, V2, 0, 2, 4, 6)

// Concatenate every other element of 8-element vectors V1 and V2.
__builtin_shufflevector(V1, V2, 0, 2, 4, 6, 8, 10, 12, 14)

// Shuffle v1 with some elements being undefined
__builtin_shufflevector(v1, v1, 3, -1, 1, -1)
*/

//v128_load(*memory)
#define wasm_v128_shuffle(a,b) (__builtin_shufflevector(a,b,0,1,2,3,4,5,6,7))

/*
static __inline__ V128_i8 __DEFAULT_FN_ATTRS
wasm_v128_shuffle(V128_i8 a, V128_i8 b, uint32_t s[16]) {
   return __builtin_shufflevector(a, b, 0);
}

V128_i8 wasm_i8x16_shr_s(V128_i8 a);

V128_i8 wasm_i8x16_shr_u(V128_i8 a);

V128_i16 wasm_i16x8_shr_s(V128_i16 a);

V128_i16 wasm_i16x8_shr_u(V128_i16 a);

V128_i32 wasm_i32x4_shr_s(V128_i32 a);

V128_i32 wasm_i32x4_shr_u(V128_i32 a);

V128_i64 wasm_i64x4_shr_s(V128_i64 a);

V128_i64 wasm_i64x4_shr_u(V128_i64 a);

*/

//v8x16.shuffle

/*

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
