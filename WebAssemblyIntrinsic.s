(module
  (type (;0;) (func (param i32 i32 i32) (result i32)))
  (type (;1;) (func (param i32)))
  (type (;2;) (func))
  (type (;3;) (func (param i32) (result i32)))
  (type (;4;) (func (param i32 i32 i32)))
  (type (;5;) (func (param i32 i32)))
  (type (;6;) (func (param i32 i32) (result i32)))
  (type (;7;) (func (param i32 i32 i32 i32) (result i32)))
  (import "env" "__cxa_atexit" (func $__cxa_atexit (type 0)))
  (import "env" "_ZdlPv" (func $operator_delete_void*_ (type 1)))
  (import "env" "_ZSt20__throw_length_errorPKc" (func $std::__throw_length_error_char_const*_ (type 1)))
  (import "env" "_ZSt17__throw_bad_allocv" (func $std::__throw_bad_alloc__ (type 2)))
  (import "env" "_Znwm" (func $operator_new_unsigned_long_ (type 3)))
  (import "env" "memmove" (func $memmove (type 0)))
  (func $__wasm_call_ctors (type 2)
    call $_GLOBAL__sub_I_WebAssemblyIntrinsic.cpp)
  (func $_GLOBAL__sub_I_WebAssemblyIntrinsic.cpp (type 2)
    call $__cxx_global_var_init)
  (func $__cxx_global_var_init (type 2)
    i32.const 1024
    call $std::vector<int__*_____std::allocator<int__*___>_>::vector__
    drop
    i32.const 1
    i32.const 0
    i32.const 1024
    call $__cxa_atexit
    drop)
  (func $std::vector<int__*_____std::allocator<int__*___>_>::vector__ (type 3) (param i32) (result i32)
    (local i32)
    get_global 0
    i32.const 16
    i32.sub
    tee_local 1
    set_global 0
    get_local 1
    get_local 0
    i32.store offset=12
    get_local 1
    i32.load offset=12
    tee_local 0
    call $std::_Vector_base<int__*_____std::allocator<int__*___>_>::_Vector_base__
    drop
    get_local 1
    i32.const 16
    i32.add
    set_global 0
    get_local 0)
  (func $__cxx_global_array_dtor (type 1) (param i32)
    i32.const 1024
    call $std::vector<int__*_____std::allocator<int__*___>_>::~vector__
    drop)
  (func $std::_Vector_base<int__*_____std::allocator<int__*___>_>::_Vector_base__ (type 3) (param i32) (result i32)
    (local i32)
    get_global 0
    i32.const 16
    i32.sub
    tee_local 1
    set_global 0
    get_local 1
    get_local 0
    i32.store offset=12
    get_local 1
    i32.load offset=12
    tee_local 0
    call $std::_Vector_base<int__*_____std::allocator<int__*___>_>::_Vector_impl::_Vector_impl__
    drop
    get_local 1
    i32.const 16
    i32.add
    set_global 0
    get_local 0)
  (func $std::vector<int__*_____std::allocator<int__*___>_>::~vector__ (type 3) (param i32) (result i32)
    (local i32)
    get_global 0
    i32.const 16
    i32.sub
    tee_local 1
    set_global 0
    get_local 1
    get_local 0
    i32.store offset=12
    get_local 1
    i32.load offset=12
    tee_local 0
    i32.load
    get_local 0
    i32.load offset=4
    get_local 0
    call $std::_Vector_base<int__*_____std::allocator<int__*___>_>::_M_get_Tp_allocator__
    call $void_std::_Destroy<int__**_____int__*___>_int__**_____int__**_____std::allocator<int__*___>&_
    get_local 0
    call $std::_Vector_base<int__*_____std::allocator<int__*___>_>::~_Vector_base__
    drop
    get_local 1
    i32.const 16
    i32.add
    set_global 0
    get_local 0)
  (func $std::_Vector_base<int__*_____std::allocator<int__*___>_>::_M_get_Tp_allocator__ (type 3) (param i32) (result i32)
    (local i32)
    get_global 0
    i32.const 16
    i32.sub
    tee_local 1
    get_local 0
    i32.store offset=12
    get_local 1
    i32.load offset=12)
  (func $void_std::_Destroy<int__**_____int__*___>_int__**_____int__**_____std::allocator<int__*___>&_ (type 4) (param i32 i32 i32)
    (local i32)
    get_global 0
    i32.const 16
    i32.sub
    tee_local 3
    set_global 0
    get_local 3
    get_local 0
    i32.store offset=12
    get_local 3
    get_local 1
    i32.store offset=8
    get_local 3
    get_local 2
    i32.store offset=4
    get_local 3
    i32.load offset=12
    get_local 3
    i32.load offset=8
    call $void_std::_Destroy<int__**___>_int__**_____int__**____
    get_local 3
    i32.const 16
    i32.add
    set_global 0)
  (func $std::_Vector_base<int__*_____std::allocator<int__*___>_>::~_Vector_base__ (type 3) (param i32) (result i32)
    (local i32)
    get_global 0
    i32.const 16
    i32.sub
    tee_local 1
    set_global 0
    get_local 1
    get_local 0
    i32.store offset=12
    get_local 1
    i32.load offset=12
    tee_local 0
    get_local 0
    i32.load
    get_local 0
    i32.load offset=8
    get_local 0
    i32.load
    i32.sub
    i32.const 2
    i32.shr_s
    call $std::_Vector_base<int__*_____std::allocator<int__*___>_>::_M_deallocate_int__**_____unsigned_long_
    get_local 0
    call $std::_Vector_base<int__*_____std::allocator<int__*___>_>::_Vector_impl::~_Vector_impl__
    drop
    get_local 1
    i32.const 16
    i32.add
    set_global 0
    get_local 0)
  (func $void_std::_Destroy<int__**___>_int__**_____int__**____ (type 5) (param i32 i32)
    (local i32)
    get_global 0
    i32.const 16
    i32.sub
    tee_local 2
    set_global 0
    get_local 2
    get_local 0
    i32.store offset=12
    get_local 2
    get_local 1
    i32.store offset=8
    get_local 2
    i32.load offset=12
    get_local 2
    i32.load offset=8
    call $void_std::_Destroy_aux<true>::__destroy<int__**___>_int__**_____int__**____
    get_local 2
    i32.const 16
    i32.add
    set_global 0)
  (func $std::_Vector_base<int__*_____std::allocator<int__*___>_>::_M_deallocate_int__**_____unsigned_long_ (type 4) (param i32 i32 i32)
    (local i32)
    get_global 0
    i32.const 16
    i32.sub
    tee_local 3
    set_global 0
    get_local 3
    get_local 0
    i32.store offset=12
    get_local 3
    get_local 1
    i32.store offset=8
    get_local 3
    get_local 2
    i32.store offset=4
    get_local 3
    i32.load offset=12
    set_local 2
    block  ;; label = @1
      get_local 3
      i32.load offset=8
      i32.const 0
      i32.eq
      br_if 0 (;@1;)
      get_local 2
      get_local 3
      i32.load offset=8
      get_local 3
      i32.load offset=4
      call $std::allocator_traits<std::allocator<int__*___>_>::deallocate_std::allocator<int__*___>&__int__**_____unsigned_long_
    end
    get_local 3
    i32.const 16
    i32.add
    set_global 0)
  (func $std::_Vector_base<int__*_____std::allocator<int__*___>_>::_Vector_impl::~_Vector_impl__ (type 3) (param i32) (result i32)
    (local i32)
    get_global 0
    i32.const 16
    i32.sub
    tee_local 1
    set_global 0
    get_local 1
    get_local 0
    i32.store offset=12
    get_local 1
    i32.load offset=12
    tee_local 0
    call $std::allocator<int__*___>::~allocator__
    drop
    get_local 1
    i32.const 16
    i32.add
    set_global 0
    get_local 0)
  (func $std::allocator_traits<std::allocator<int__*___>_>::deallocate_std::allocator<int__*___>&__int__**_____unsigned_long_ (type 4) (param i32 i32 i32)
    (local i32)
    get_global 0
    i32.const 16
    i32.sub
    tee_local 3
    set_global 0
    get_local 3
    get_local 0
    i32.store offset=12
    get_local 3
    get_local 1
    i32.store offset=8
    get_local 3
    get_local 2
    i32.store offset=4
    get_local 3
    i32.load offset=12
    get_local 3
    i32.load offset=8
    get_local 3
    i32.load offset=4
    call $__gnu_cxx::new_allocator<int__*___>::deallocate_int__**_____unsigned_long_
    get_local 3
    i32.const 16
    i32.add
    set_global 0)
  (func $std::allocator<int__*___>::~allocator__ (type 3) (param i32) (result i32)
    (local i32)
    get_global 0
    i32.const 16
    i32.sub
    tee_local 1
    set_global 0
    get_local 1
    get_local 0
    i32.store offset=12
    get_local 1
    i32.load offset=12
    tee_local 0
    call $__gnu_cxx::new_allocator<int__*___>::~new_allocator__
    drop
    get_local 1
    i32.const 16
    i32.add
    set_global 0
    get_local 0)
  (func $__gnu_cxx::new_allocator<int__*___>::~new_allocator__ (type 3) (param i32) (result i32)
    (local i32)
    get_global 0
    i32.const 16
    i32.sub
    tee_local 1
    get_local 0
    i32.store offset=12
    get_local 1
    i32.load offset=12)
  (func $__gnu_cxx::new_allocator<int__*___>::deallocate_int__**_____unsigned_long_ (type 4) (param i32 i32 i32)
    (local i32)
    get_global 0
    i32.const 16
    i32.sub
    tee_local 3
    set_global 0
    get_local 3
    get_local 0
    i32.store offset=12
    get_local 3
    get_local 1
    i32.store offset=8
    get_local 3
    get_local 2
    i32.store offset=4
    get_local 3
    i32.load offset=8
    call $operator_delete_void*_
    get_local 3
    i32.const 16
    i32.add
    set_global 0)
  (func $void_std::_Destroy_aux<true>::__destroy<int__**___>_int__**_____int__**____ (type 5) (param i32 i32)
    (local i32)
    get_global 0
    i32.const 16
    i32.sub
    tee_local 2
    get_local 0
    i32.store offset=12
    get_local 2
    get_local 1
    i32.store offset=8)
  (func $std::_Vector_base<int__*_____std::allocator<int__*___>_>::_Vector_impl::_Vector_impl__ (type 3) (param i32) (result i32)
    (local i32)
    get_global 0
    i32.const 16
    i32.sub
    tee_local 1
    set_global 0
    get_local 1
    get_local 0
    i32.store offset=12
    get_local 1
    i32.load offset=12
    tee_local 0
    call $std::allocator<int__*___>::allocator__
    drop
    get_local 0
    i32.const 0
    i32.store
    get_local 0
    i32.const 0
    i32.store offset=4
    get_local 0
    i32.const 0
    i32.store offset=8
    get_local 1
    i32.const 16
    i32.add
    set_global 0
    get_local 0)
  (func $std::allocator<int__*___>::allocator__ (type 3) (param i32) (result i32)
    (local i32)
    get_global 0
    i32.const 16
    i32.sub
    tee_local 1
    set_global 0
    get_local 1
    get_local 0
    i32.store offset=12
    get_local 1
    i32.load offset=12
    tee_local 0
    call $__gnu_cxx::new_allocator<int__*___>::new_allocator__
    drop
    get_local 1
    i32.const 16
    i32.add
    set_global 0
    get_local 0)
  (func $__gnu_cxx::new_allocator<int__*___>::new_allocator__ (type 3) (param i32) (result i32)
    (local i32)
    get_global 0
    i32.const 16
    i32.sub
    tee_local 1
    get_local 0
    i32.store offset=12
    get_local 1
    i32.load offset=12)
  (func $std::vector<int__*_____std::allocator<int__*___>_>::push_back_int__*&&____ (type 5) (param i32 i32)
    (local i32)
    get_global 0
    i32.const 16
    i32.sub
    tee_local 2
    set_global 0
    get_local 2
    get_local 0
    i32.store offset=12
    get_local 2
    get_local 1
    i32.store offset=8
    get_local 2
    i32.load offset=12
    get_local 2
    i32.load offset=8
    call $std::remove_reference<int__*&___>::type&&_std::move<int__*&___>_int__*&____
    call $int__*&std::vector<int__*_____std::allocator<int__*___>_>::emplace_back<int__*___>_int__*&&_______
    drop
    get_local 2
    i32.const 16
    i32.add
    set_global 0)
  (func $std::remove_reference<int__*&___>::type&&_std::move<int__*&___>_int__*&____ (type 3) (param i32) (result i32)
    (local i32)
    get_global 0
    i32.const 16
    i32.sub
    tee_local 1
    get_local 0
    i32.store offset=12
    get_local 1
    i32.load offset=12)
  (func $int__*&std::vector<int__*_____std::allocator<int__*___>_>::emplace_back<int__*___>_int__*&&_______ (type 6) (param i32 i32) (result i32)
    (local i32)
    get_global 0
    i32.const 16
    i32.sub
    tee_local 2
    set_global 0
    get_local 2
    get_local 0
    i32.store offset=12
    get_local 2
    get_local 1
    i32.store offset=8
    block  ;; label = @1
      block  ;; label = @2
        get_local 2
        i32.load offset=12
        tee_local 1
        i32.load offset=4
        get_local 1
        i32.load offset=8
        i32.eq
        br_if 0 (;@2;)
        get_local 1
        get_local 1
        i32.load offset=4
        get_local 2
        i32.load offset=8
        call $int__*&&std::forward<int__*___>_std::remove_reference<int__*___>::type&____
        call $void_std::allocator_traits<std::allocator<int__*___>_>::construct<int__*_____int__*___>_std::allocator<int__*___>&__int__**_____int__*&&____
        get_local 1
        get_local 1
        i32.load offset=4
        i32.const 4
        i32.add
        i32.store offset=4
        br 1 (;@1;)
      end
      get_local 2
      get_local 1
      call $std::vector<int__*_____std::allocator<int__*___>_>::end__
      i32.store
      get_local 2
      i32.load offset=8
      call $int__*&&std::forward<int__*___>_std::remove_reference<int__*___>::type&____
      set_local 0
      get_local 1
      get_local 2
      i32.load
      get_local 0
      call $void_std::vector<int__*_____std::allocator<int__*___>_>::_M_realloc_insert<int__*___>___gnu_cxx::__normal_iterator<int__**_____std::vector<int__*_____std::allocator<int__*___>_>_>__int__*&&____
    end
    get_local 1
    call $std::vector<int__*_____std::allocator<int__*___>_>::back__
    set_local 1
    get_local 2
    i32.const 16
    i32.add
    set_global 0
    get_local 1)
  (func $int__*&&std::forward<int__*___>_std::remove_reference<int__*___>::type&____ (type 3) (param i32) (result i32)
    (local i32)
    get_global 0
    i32.const 16
    i32.sub
    tee_local 1
    get_local 0
    i32.store offset=12
    get_local 1
    i32.load offset=12)
  (func $void_std::allocator_traits<std::allocator<int__*___>_>::construct<int__*_____int__*___>_std::allocator<int__*___>&__int__**_____int__*&&____ (type 4) (param i32 i32 i32)
    (local i32)
    get_global 0
    i32.const 16
    i32.sub
    tee_local 3
    set_global 0
    get_local 3
    get_local 0
    i32.store offset=12
    get_local 3
    get_local 1
    i32.store offset=8
    get_local 3
    get_local 2
    i32.store offset=4
    get_local 3
    i32.load offset=12
    get_local 3
    i32.load offset=8
    get_local 3
    i32.load offset=4
    call $int__*&&std::forward<int__*___>_std::remove_reference<int__*___>::type&____
    call $void___gnu_cxx::new_allocator<int__*___>::construct<int__*_____int__*___>_int__**_____int__*&&____
    get_local 3
    i32.const 16
    i32.add
    set_global 0)
  (func $std::vector<int__*_____std::allocator<int__*___>_>::end__ (type 3) (param i32) (result i32)
    (local i32)
    get_global 0
    i32.const 16
    i32.sub
    tee_local 1
    set_global 0
    get_local 1
    get_local 0
    i32.store offset=4
    get_local 1
    i32.const 8
    i32.add
    get_local 1
    i32.load offset=4
    i32.const 4
    i32.add
    call $__gnu_cxx::__normal_iterator<int__**_____std::vector<int__*_____std::allocator<int__*___>_>_>::__normal_iterator_int__**_const&____
    i32.load
    set_local 0
    get_local 1
    i32.const 16
    i32.add
    set_global 0
    get_local 0)
  (func $void_std::vector<int__*_____std::allocator<int__*___>_>::_M_realloc_insert<int__*___>___gnu_cxx::__normal_iterator<int__**_____std::vector<int__*_____std::allocator<int__*___>_>_>__int__*&&____ (type 4) (param i32 i32 i32)
    (local i32)
    get_global 0
    i32.const 48
    i32.sub
    tee_local 3
    set_global 0
    get_local 3
    get_local 1
    i32.store offset=40
    get_local 3
    get_local 0
    i32.store offset=36
    get_local 3
    get_local 2
    i32.store offset=32
    get_local 3
    get_local 3
    i32.load offset=36
    tee_local 2
    i32.const 1
    i32.const 1036
    call $std::vector<int__*_____std::allocator<int__*___>_>::_M_check_len_unsigned_long__char_const*__const
    i32.store offset=28
    get_local 3
    get_local 2
    call $std::vector<int__*_____std::allocator<int__*___>_>::begin__
    i32.store offset=16
    get_local 3
    get_local 3
    i32.const 40
    i32.add
    get_local 3
    i32.const 16
    i32.add
    call $__gnu_cxx::__normal_iterator<int__**_____std::vector<int__*_____std::allocator<int__*___>_>_>::difference_type___gnu_cxx::operator-<int__**_____std::vector<int__*_____std::allocator<int__*___>_>_>___gnu_cxx::__normal_iterator<int__**_____std::vector<int__*_____std::allocator<int__*___>_>_>_const&____gnu_cxx::__normal_iterator<int__**_____std::vector<int__*_____std::allocator<int__*___>_>_>_const&_
    i32.store offset=24
    get_local 3
    get_local 2
    get_local 3
    i32.load offset=28
    call $std::_Vector_base<int__*_____std::allocator<int__*___>_>::_M_allocate_unsigned_long_
    i32.store offset=12
    get_local 3
    get_local 3
    i32.load offset=12
    i32.store offset=8
    get_local 2
    get_local 3
    i32.load offset=12
    get_local 3
    i32.load offset=24
    i32.const 2
    i32.shl
    i32.add
    get_local 3
    i32.load offset=32
    call $int__*&&std::forward<int__*___>_std::remove_reference<int__*___>::type&____
    call $void_std::allocator_traits<std::allocator<int__*___>_>::construct<int__*_____int__*___>_std::allocator<int__*___>&__int__**_____int__*&&____
    get_local 3
    i32.const 0
    i32.store offset=8
    get_local 2
    i32.load
    get_local 3
    i32.const 40
    i32.add
    call $__gnu_cxx::__normal_iterator<int__**_____std::vector<int__*_____std::allocator<int__*___>_>_>::base___const
    i32.load
    get_local 3
    i32.load offset=12
    get_local 2
    call $std::_Vector_base<int__*_____std::allocator<int__*___>_>::_M_get_Tp_allocator__
    call $int__**std::__uninitialized_move_if_noexcept_a<int__**_____int__**_____std::allocator<int__*___>_>_int__**_____int__**_____int__**_____std::allocator<int__*___>&____
    set_local 1
    get_local 3
    get_local 1
    i32.store offset=8
    get_local 3
    get_local 3
    i32.load offset=8
    i32.const 4
    i32.add
    i32.store offset=8
    get_local 3
    i32.const 40
    i32.add
    call $__gnu_cxx::__normal_iterator<int__**_____std::vector<int__*_____std::allocator<int__*___>_>_>::base___const
    i32.load
    get_local 2
    i32.load offset=4
    get_local 3
    i32.load offset=8
    get_local 2
    call $std::_Vector_base<int__*_____std::allocator<int__*___>_>::_M_get_Tp_allocator__
    call $int__**std::__uninitialized_move_if_noexcept_a<int__**_____int__**_____std::allocator<int__*___>_>_int__**_____int__**_____int__**_____std::allocator<int__*___>&____
    set_local 1
    get_local 3
    get_local 1
    i32.store offset=8
    get_local 2
    i32.load
    get_local 2
    i32.load offset=4
    get_local 2
    call $std::_Vector_base<int__*_____std::allocator<int__*___>_>::_M_get_Tp_allocator__
    call $void_std::_Destroy<int__**_____int__*___>_int__**_____int__**_____std::allocator<int__*___>&_
    get_local 2
    get_local 2
    i32.load
    get_local 2
    i32.load offset=8
    get_local 2
    i32.load
    i32.sub
    i32.const 2
    i32.shr_s
    call $std::_Vector_base<int__*_____std::allocator<int__*___>_>::_M_deallocate_int__**_____unsigned_long_
    get_local 2
    get_local 3
    i32.load offset=12
    i32.store
    get_local 2
    get_local 3
    i32.load offset=8
    i32.store offset=4
    get_local 2
    get_local 3
    i32.load offset=12
    get_local 3
    i32.load offset=28
    i32.const 2
    i32.shl
    i32.add
    i32.store offset=8
    get_local 3
    i32.const 48
    i32.add
    set_global 0)
  (func $std::vector<int__*_____std::allocator<int__*___>_>::back__ (type 3) (param i32) (result i32)
    (local i32)
    get_global 0
    i32.const 16
    i32.sub
    tee_local 1
    set_global 0
    get_local 1
    get_local 0
    i32.store offset=12
    get_local 1
    get_local 1
    i32.load offset=12
    call $std::vector<int__*_____std::allocator<int__*___>_>::end__
    i32.store
    get_local 1
    get_local 1
    i32.const 1
    call $__gnu_cxx::__normal_iterator<int__**_____std::vector<int__*_____std::allocator<int__*___>_>_>::operator-_long__const
    i32.store offset=8
    get_local 1
    i32.const 8
    i32.add
    call $__gnu_cxx::__normal_iterator<int__**_____std::vector<int__*_____std::allocator<int__*___>_>_>::operator*___const
    set_local 0
    get_local 1
    i32.const 16
    i32.add
    set_global 0
    get_local 0)
  (func $void___gnu_cxx::new_allocator<int__*___>::construct<int__*_____int__*___>_int__**_____int__*&&____ (type 4) (param i32 i32 i32)
    (local i32)
    get_global 0
    i32.const 16
    i32.sub
    tee_local 3
    set_global 0
    get_local 3
    get_local 0
    i32.store offset=12
    get_local 3
    get_local 1
    i32.store offset=8
    get_local 3
    get_local 2
    i32.store offset=4
    get_local 3
    i32.load offset=8
    get_local 3
    i32.load offset=4
    call $int__*&&std::forward<int__*___>_std::remove_reference<int__*___>::type&____
    i32.load
    i32.store
    get_local 3
    i32.const 16
    i32.add
    set_global 0)
  (func $__gnu_cxx::__normal_iterator<int__**_____std::vector<int__*_____std::allocator<int__*___>_>_>::__normal_iterator_int__**_const&____ (type 6) (param i32 i32) (result i32)
    (local i32)
    get_global 0
    i32.const 16
    i32.sub
    tee_local 2
    get_local 0
    i32.store offset=12
    get_local 2
    get_local 1
    i32.store offset=8
    get_local 2
    i32.load offset=12
    tee_local 1
    get_local 2
    i32.load offset=8
    i32.load
    i32.store
    get_local 1)
  (func $std::vector<int__*_____std::allocator<int__*___>_>::_M_check_len_unsigned_long__char_const*__const (type 0) (param i32 i32 i32) (result i32)
    (local i32)
    get_global 0
    i32.const 32
    i32.sub
    tee_local 3
    set_global 0
    get_local 3
    get_local 0
    i32.store offset=28
    get_local 3
    get_local 1
    i32.store offset=24
    get_local 3
    get_local 2
    i32.store offset=20
    block  ;; label = @1
      get_local 3
      i32.load offset=28
      tee_local 2
      call $std::vector<int__*_____std::allocator<int__*___>_>::max_size___const
      get_local 2
      call $std::vector<int__*_____std::allocator<int__*___>_>::size___const
      i32.sub
      get_local 3
      i32.load offset=24
      i32.ge_u
      br_if 0 (;@1;)
      get_local 3
      i32.load offset=20
      call $std::__throw_length_error_char_const*_
      unreachable
    end
    get_local 2
    call $std::vector<int__*_____std::allocator<int__*___>_>::size___const
    set_local 1
    get_local 3
    get_local 2
    call $std::vector<int__*_____std::allocator<int__*___>_>::size___const
    i32.store offset=12
    get_local 3
    get_local 1
    get_local 3
    i32.const 12
    i32.add
    get_local 3
    i32.const 24
    i32.add
    call $unsigned_long_const&_std::max<unsigned_long>_unsigned_long_const&__unsigned_long_const&_
    i32.load
    i32.add
    i32.store offset=16
    block  ;; label = @1
      block  ;; label = @2
        block  ;; label = @3
          get_local 3
          i32.load offset=16
          get_local 2
          call $std::vector<int__*_____std::allocator<int__*___>_>::size___const
          i32.lt_u
          br_if 0 (;@3;)
          get_local 3
          i32.load offset=16
          get_local 2
          call $std::vector<int__*_____std::allocator<int__*___>_>::max_size___const
          i32.le_u
          br_if 1 (;@2;)
        end
        get_local 2
        call $std::vector<int__*_____std::allocator<int__*___>_>::max_size___const
        set_local 2
        br 1 (;@1;)
      end
      get_local 3
      i32.load offset=16
      set_local 2
    end
    get_local 3
    i32.const 32
    i32.add
    set_global 0
    get_local 2)
  (func $std::vector<int__*_____std::allocator<int__*___>_>::begin__ (type 3) (param i32) (result i32)
    (local i32)
    get_global 0
    i32.const 16
    i32.sub
    tee_local 1
    set_global 0
    get_local 1
    get_local 0
    i32.store offset=4
    get_local 1
    i32.const 8
    i32.add
    get_local 1
    i32.load offset=4
    call $__gnu_cxx::__normal_iterator<int__**_____std::vector<int__*_____std::allocator<int__*___>_>_>::__normal_iterator_int__**_const&____
    i32.load
    set_local 0
    get_local 1
    i32.const 16
    i32.add
    set_global 0
    get_local 0)
  (func $__gnu_cxx::__normal_iterator<int__**_____std::vector<int__*_____std::allocator<int__*___>_>_>::difference_type___gnu_cxx::operator-<int__**_____std::vector<int__*_____std::allocator<int__*___>_>_>___gnu_cxx::__normal_iterator<int__**_____std::vector<int__*_____std::allocator<int__*___>_>_>_const&____gnu_cxx::__normal_iterator<int__**_____std::vector<int__*_____std::allocator<int__*___>_>_>_const&_ (type 6) (param i32 i32) (result i32)
    (local i32)
    get_global 0
    i32.const 16
    i32.sub
    tee_local 2
    set_global 0
    get_local 2
    get_local 0
    i32.store offset=12
    get_local 2
    get_local 1
    i32.store offset=8
    get_local 2
    i32.load offset=12
    call $__gnu_cxx::__normal_iterator<int__**_____std::vector<int__*_____std::allocator<int__*___>_>_>::base___const
    i32.load
    set_local 1
    get_local 2
    i32.load offset=8
    call $__gnu_cxx::__normal_iterator<int__**_____std::vector<int__*_____std::allocator<int__*___>_>_>::base___const
    i32.load
    set_local 0
    get_local 2
    i32.const 16
    i32.add
    set_global 0
    get_local 1
    get_local 0
    i32.sub
    i32.const 2
    i32.shr_s)
  (func $std::_Vector_base<int__*_____std::allocator<int__*___>_>::_M_allocate_unsigned_long_ (type 6) (param i32 i32) (result i32)
    (local i32)
    get_global 0
    i32.const 16
    i32.sub
    tee_local 2
    set_global 0
    get_local 2
    get_local 0
    i32.store offset=12
    get_local 2
    get_local 1
    i32.store offset=8
    get_local 2
    i32.load offset=12
    set_local 1
    block  ;; label = @1
      block  ;; label = @2
        get_local 2
        i32.load offset=8
        i32.eqz
        br_if 0 (;@2;)
        get_local 1
        get_local 2
        i32.load offset=8
        call $std::allocator_traits<std::allocator<int__*___>_>::allocate_std::allocator<int__*___>&__unsigned_long_
        set_local 1
        br 1 (;@1;)
      end
      i32.const 0
      set_local 1
    end
    get_local 2
    i32.const 16
    i32.add
    set_global 0
    get_local 1)
  (func $__gnu_cxx::__normal_iterator<int__**_____std::vector<int__*_____std::allocator<int__*___>_>_>::base___const (type 3) (param i32) (result i32)
    (local i32)
    get_global 0
    i32.const 16
    i32.sub
    tee_local 1
    get_local 0
    i32.store offset=12
    get_local 1
    i32.load offset=12)
  (func $int__**std::__uninitialized_move_if_noexcept_a<int__**_____int__**_____std::allocator<int__*___>_>_int__**_____int__**_____int__**_____std::allocator<int__*___>&____ (type 7) (param i32 i32 i32 i32) (result i32)
    (local i32)
    get_global 0
    i32.const 32
    i32.sub
    tee_local 4
    set_global 0
    get_local 4
    get_local 0
    i32.store offset=28
    get_local 4
    get_local 1
    i32.store offset=24
    get_local 4
    get_local 2
    i32.store offset=20
    get_local 4
    get_local 3
    i32.store offset=16
    get_local 4
    get_local 4
    i32.load offset=28
    call $std::move_iterator<int__**___>_std::__make_move_if_noexcept_iterator<int__*_____std::move_iterator<int__**___>_>_int__**____
    i32.store offset=8
    get_local 4
    get_local 4
    i32.load offset=24
    call $std::move_iterator<int__**___>_std::__make_move_if_noexcept_iterator<int__*_____std::move_iterator<int__**___>_>_int__**____
    i32.store
    get_local 4
    i32.load offset=8
    get_local 4
    i32.load
    get_local 4
    i32.load offset=20
    get_local 4
    i32.load offset=16
    call $int__**std::__uninitialized_copy_a<std::move_iterator<int__**___>__int__**_____int__*___>_std::move_iterator<int__**___>__std::move_iterator<int__**___>__int__**_____std::allocator<int__*___>&____
    set_local 3
    get_local 4
    i32.const 32
    i32.add
    set_global 0
    get_local 3)
  (func $__gnu_cxx::__normal_iterator<int__**_____std::vector<int__*_____std::allocator<int__*___>_>_>::operator-_long__const (type 6) (param i32 i32) (result i32)
    (local i32)
    get_global 0
    i32.const 32
    i32.sub
    tee_local 2
    set_global 0
    get_local 2
    get_local 0
    i32.store offset=20
    get_local 2
    get_local 1
    i32.store offset=16
    get_local 2
    get_local 2
    i32.load offset=20
    i32.load
    i32.const 0
    get_local 2
    i32.load offset=16
    i32.sub
    i32.const 2
    i32.shl
    i32.add
    i32.store offset=12
    get_local 2
    i32.const 24
    i32.add
    get_local 2
    i32.const 12
    i32.add
    call $__gnu_cxx::__normal_iterator<int__**_____std::vector<int__*_____std::allocator<int__*___>_>_>::__normal_iterator_int__**_const&____
    i32.load
    set_local 1
    get_local 2
    i32.const 32
    i32.add
    set_global 0
    get_local 1)
  (func $__gnu_cxx::__normal_iterator<int__**_____std::vector<int__*_____std::allocator<int__*___>_>_>::operator*___const (type 3) (param i32) (result i32)
    (local i32)
    get_global 0
    i32.const 16
    i32.sub
    tee_local 1
    get_local 0
    i32.store offset=12
    get_local 1
    i32.load offset=12
    i32.load)
  (func $std::vector<int__*_____std::allocator<int__*___>_>::max_size___const (type 3) (param i32) (result i32)
    (local i32)
    get_global 0
    i32.const 16
    i32.sub
    tee_local 1
    set_global 0
    get_local 1
    get_local 0
    i32.store offset=12
    get_local 1
    i32.load offset=12
    call $std::_Vector_base<int__*_____std::allocator<int__*___>_>::_M_get_Tp_allocator___const
    call $std::allocator_traits<std::allocator<int__*___>_>::max_size_std::allocator<int__*___>_const&_
    set_local 0
    get_local 1
    i32.const 16
    i32.add
    set_global 0
    get_local 0)
  (func $std::vector<int__*_____std::allocator<int__*___>_>::size___const (type 3) (param i32) (result i32)
    (local i32)
    get_global 0
    i32.const 16
    i32.sub
    tee_local 1
    get_local 0
    i32.store offset=12
    get_local 1
    i32.load offset=12
    tee_local 0
    i32.load offset=4
    get_local 0
    i32.load
    i32.sub
    i32.const 2
    i32.shr_s)
  (func $unsigned_long_const&_std::max<unsigned_long>_unsigned_long_const&__unsigned_long_const&_ (type 6) (param i32 i32) (result i32)
    (local i32)
    get_global 0
    i32.const 16
    i32.sub
    tee_local 2
    get_local 0
    i32.store offset=8
    get_local 2
    get_local 1
    i32.store offset=4
    block  ;; label = @1
      block  ;; label = @2
        get_local 2
        i32.load offset=8
        i32.load
        get_local 2
        i32.load offset=4
        i32.load
        i32.ge_u
        br_if 0 (;@2;)
        get_local 2
        get_local 2
        i32.load offset=4
        i32.store offset=12
        br 1 (;@1;)
      end
      get_local 2
      get_local 2
      i32.load offset=8
      i32.store offset=12
    end
    get_local 2
    i32.load offset=12)
  (func $std::allocator_traits<std::allocator<int__*___>_>::allocate_std::allocator<int__*___>&__unsigned_long_ (type 6) (param i32 i32) (result i32)
    (local i32)
    get_global 0
    i32.const 16
    i32.sub
    tee_local 2
    set_global 0
    get_local 2
    get_local 0
    i32.store offset=12
    get_local 2
    get_local 1
    i32.store offset=8
    get_local 2
    i32.load offset=12
    get_local 2
    i32.load offset=8
    i32.const 0
    call $__gnu_cxx::new_allocator<int__*___>::allocate_unsigned_long__void_const*_
    set_local 1
    get_local 2
    i32.const 16
    i32.add
    set_global 0
    get_local 1)
  (func $std::move_iterator<int__**___>_std::__make_move_if_noexcept_iterator<int__*_____std::move_iterator<int__**___>_>_int__**____ (type 3) (param i32) (result i32)
    (local i32)
    get_global 0
    i32.const 16
    i32.sub
    tee_local 1
    set_global 0
    get_local 1
    get_local 0
    i32.store offset=4
    get_local 1
    i32.const 8
    i32.add
    get_local 1
    i32.load offset=4
    call $std::move_iterator<int__**___>::move_iterator_int__**____
    i32.load
    set_local 0
    get_local 1
    i32.const 16
    i32.add
    set_global 0
    get_local 0)
  (func $int__**std::__uninitialized_copy_a<std::move_iterator<int__**___>__int__**_____int__*___>_std::move_iterator<int__**___>__std::move_iterator<int__**___>__int__**_____std::allocator<int__*___>&____ (type 7) (param i32 i32 i32 i32) (result i32)
    (local i32)
    get_global 0
    i32.const 48
    i32.sub
    tee_local 4
    set_global 0
    get_local 4
    get_local 0
    i32.store offset=40
    get_local 4
    get_local 1
    i32.store offset=32
    get_local 4
    get_local 2
    i32.store offset=28
    get_local 4
    get_local 3
    i32.store offset=24
    get_local 4
    i32.const 16
    i32.add
    get_local 4
    i32.const 40
    i32.add
    i32.load
    i32.store
    get_local 4
    i32.const 8
    i32.add
    get_local 4
    i32.const 32
    i32.add
    i32.load
    i32.store
    get_local 4
    i32.load offset=16
    get_local 4
    i32.load offset=8
    get_local 4
    i32.load offset=28
    call $int__**std::uninitialized_copy<std::move_iterator<int__**___>__int__**___>_std::move_iterator<int__**___>__std::move_iterator<int__**___>__int__**_______
    set_local 3
    get_local 4
    i32.const 48
    i32.add
    set_global 0
    get_local 3)
  (func $void_std::allocator_traits<std::allocator<int__*___>_>::destroy<int__*___>_std::allocator<int__*___>&__int__**____ (type 5) (param i32 i32)
    (local i32)
    get_global 0
    i32.const 16
    i32.sub
    tee_local 2
    set_global 0
    get_local 2
    get_local 0
    i32.store offset=12
    get_local 2
    get_local 1
    i32.store offset=8
    get_local 2
    i32.load offset=12
    get_local 2
    i32.load offset=8
    call $void___gnu_cxx::new_allocator<int__*___>::destroy<int__*___>_int__**____
    get_local 2
    i32.const 16
    i32.add
    set_global 0)
  (func $void___gnu_cxx::new_allocator<int__*___>::destroy<int__*___>_int__**____ (type 5) (param i32 i32)
    (local i32)
    get_global 0
    i32.const 16
    i32.sub
    tee_local 2
    get_local 0
    i32.store offset=12
    get_local 2
    get_local 1
    i32.store offset=8)
  (func $std::move_iterator<int__**___>::move_iterator_int__**____ (type 6) (param i32 i32) (result i32)
    (local i32)
    get_global 0
    i32.const 16
    i32.sub
    tee_local 2
    get_local 0
    i32.store offset=12
    get_local 2
    get_local 1
    i32.store offset=8
    get_local 2
    i32.load offset=12
    tee_local 1
    get_local 2
    i32.load offset=8
    i32.store
    get_local 1)
  (func $int__**std::uninitialized_copy<std::move_iterator<int__**___>__int__**___>_std::move_iterator<int__**___>__std::move_iterator<int__**___>__int__**_______ (type 0) (param i32 i32 i32) (result i32)
    (local i32)
    get_global 0
    i32.const 48
    i32.sub
    tee_local 3
    set_global 0
    get_local 3
    get_local 0
    i32.store offset=40
    get_local 3
    get_local 1
    i32.store offset=32
    get_local 3
    get_local 2
    i32.store offset=28
    get_local 3
    i32.const 1
    i32.store8 offset=27
    get_local 3
    i32.const 16
    i32.add
    get_local 3
    i32.const 40
    i32.add
    i32.load
    i32.store
    get_local 3
    i32.const 8
    i32.add
    get_local 3
    i32.const 32
    i32.add
    i32.load
    i32.store
    get_local 3
    i32.load offset=16
    get_local 3
    i32.load offset=8
    get_local 3
    i32.load offset=28
    call $int__**std::__uninitialized_copy<true>::__uninit_copy<std::move_iterator<int__**___>__int__**___>_std::move_iterator<int__**___>__std::move_iterator<int__**___>__int__**_______
    set_local 2
    get_local 3
    i32.const 48
    i32.add
    set_global 0
    get_local 2)
  (func $int__**std::__uninitialized_copy<true>::__uninit_copy<std::move_iterator<int__**___>__int__**___>_std::move_iterator<int__**___>__std::move_iterator<int__**___>__int__**_______ (type 0) (param i32 i32 i32) (result i32)
    (local i32)
    get_global 0
    i32.const 32
    i32.sub
    tee_local 3
    set_global 0
    get_local 3
    get_local 0
    i32.store offset=24
    get_local 3
    get_local 1
    i32.store offset=16
    get_local 3
    get_local 2
    i32.store offset=12
    get_local 3
    i32.const 8
    i32.add
    get_local 3
    i32.const 24
    i32.add
    i32.load
    i32.store
    get_local 3
    get_local 3
    i32.const 16
    i32.add
    i32.load
    i32.store
    get_local 3
    i32.load offset=8
    get_local 3
    i32.load
    get_local 3
    i32.load offset=12
    call $int__**std::copy<std::move_iterator<int__**___>__int__**___>_std::move_iterator<int__**___>__std::move_iterator<int__**___>__int__**_______
    set_local 2
    get_local 3
    i32.const 32
    i32.add
    set_global 0
    get_local 2)
  (func $int__**std::copy<std::move_iterator<int__**___>__int__**___>_std::move_iterator<int__**___>__std::move_iterator<int__**___>__int__**_______ (type 0) (param i32 i32 i32) (result i32)
    (local i32)
    get_global 0
    i32.const 32
    i32.sub
    tee_local 3
    set_global 0
    get_local 3
    get_local 0
    i32.store offset=24
    get_local 3
    get_local 1
    i32.store offset=16
    get_local 3
    get_local 2
    i32.store offset=12
    get_local 3
    i32.const 8
    i32.add
    get_local 3
    i32.const 24
    i32.add
    i32.load
    i32.store
    get_local 3
    i32.load offset=8
    call $decltype___miter_base_fp.base_____std::__miter_base<int__**___>_std::move_iterator<int__**___>_
    set_local 2
    get_local 3
    get_local 3
    i32.const 16
    i32.add
    i32.load
    i32.store
    get_local 2
    get_local 3
    i32.load
    call $decltype___miter_base_fp.base_____std::__miter_base<int__**___>_std::move_iterator<int__**___>_
    get_local 3
    i32.load offset=12
    call $int__**std::__copy_move_a2<true__int__**_____int__**___>_int__**_____int__**_____int__**_______
    set_local 2
    get_local 3
    i32.const 32
    i32.add
    set_global 0
    get_local 2)
  (func $decltype___miter_base_fp.base_____std::__miter_base<int__**___>_std::move_iterator<int__**___>_ (type 3) (param i32) (result i32)
    (local i32)
    get_global 0
    i32.const 16
    i32.sub
    tee_local 1
    set_global 0
    get_local 1
    get_local 0
    i32.store offset=8
    get_local 1
    i32.const 8
    i32.add
    call $std::move_iterator<int__**___>::base___const
    call $int__**std::__miter_base<int__**___>_int__**_______
    set_local 0
    get_local 1
    i32.const 16
    i32.add
    set_global 0
    get_local 0)
  (func $int__**std::__copy_move_a2<true__int__**_____int__**___>_int__**_____int__**_____int__**_______ (type 0) (param i32 i32 i32) (result i32)
    (local i32)
    get_global 0
    i32.const 16
    i32.sub
    tee_local 3
    set_global 0
    get_local 3
    get_local 0
    i32.store offset=12
    get_local 3
    get_local 1
    i32.store offset=8
    get_local 3
    get_local 2
    i32.store offset=4
    get_local 3
    i32.load offset=12
    call $int__**std::__niter_base<int__**___>_int__**_______
    get_local 3
    i32.load offset=8
    call $int__**std::__niter_base<int__**___>_int__**_______
    get_local 3
    i32.load offset=4
    call $int__**std::__niter_base<int__**___>_int__**_______
    call $int__**std::__copy_move_a<true__int__**_____int__**___>_int__**_____int__**_____int__**_______
    set_local 2
    get_local 3
    i32.const 16
    i32.add
    set_global 0
    get_local 2)
  (func $std::move_iterator<int__**___>::base___const (type 3) (param i32) (result i32)
    (local i32)
    get_global 0
    i32.const 16
    i32.sub
    tee_local 1
    get_local 0
    i32.store offset=12
    get_local 1
    i32.load offset=12
    i32.load)
  (func $int__**std::__miter_base<int__**___>_int__**_______ (type 3) (param i32) (result i32)
    (local i32)
    get_global 0
    i32.const 16
    i32.sub
    tee_local 1
    get_local 0
    i32.store offset=12
    get_local 1
    i32.load offset=12)
  (func $int__**std::__niter_base<int__**___>_int__**_______ (type 3) (param i32) (result i32)
    (local i32)
    get_global 0
    i32.const 16
    i32.sub
    tee_local 1
    get_local 0
    i32.store offset=12
    get_local 1
    i32.load offset=12)
  (func $int__**std::__copy_move_a<true__int__**_____int__**___>_int__**_____int__**_____int__**_______ (type 0) (param i32 i32 i32) (result i32)
    (local i32)
    get_global 0
    i32.const 16
    i32.sub
    tee_local 3
    set_global 0
    get_local 3
    get_local 0
    i32.store offset=12
    get_local 3
    get_local 1
    i32.store offset=8
    get_local 3
    get_local 2
    i32.store offset=4
    get_local 3
    i32.const 1
    i32.store8 offset=3
    get_local 3
    i32.load offset=12
    get_local 3
    i32.load offset=8
    get_local 3
    i32.load offset=4
    call $int__**std::__copy_move<true__true__std::random_access_iterator_tag>::__copy_m<int__*___>_int__*_const*_____int__*_const*_____int__**_______
    set_local 2
    get_local 3
    i32.const 16
    i32.add
    set_global 0
    get_local 2)
  (func $int__**std::__copy_move<true__true__std::random_access_iterator_tag>::__copy_m<int__*___>_int__*_const*_____int__*_const*_____int__**_______ (type 0) (param i32 i32 i32) (result i32)
    (local i32)
    get_global 0
    i32.const 16
    i32.sub
    tee_local 3
    set_global 0
    get_local 3
    get_local 0
    i32.store offset=12
    get_local 3
    get_local 1
    i32.store offset=8
    get_local 3
    get_local 2
    i32.store offset=4
    get_local 3
    get_local 3
    i32.load offset=8
    get_local 3
    i32.load offset=12
    i32.sub
    i32.const 2
    i32.shr_s
    i32.store
    block  ;; label = @1
      get_local 3
      i32.load
      i32.eqz
      br_if 0 (;@1;)
      get_local 3
      i32.load offset=4
      get_local 3
      i32.load offset=12
      get_local 3
      i32.load
      i32.const 2
      i32.shl
      call $memmove
      drop
    end
    get_local 3
    i32.load offset=4
    set_local 2
    get_local 3
    i32.load
    set_local 1
    get_local 3
    i32.const 16
    i32.add
    set_global 0
    get_local 2
    get_local 1
    i32.const 2
    i32.shl
    i32.add)
  (func $__gnu_cxx::new_allocator<int__*___>::allocate_unsigned_long__void_const*_ (type 0) (param i32 i32 i32) (result i32)
    (local i32)
    get_global 0
    i32.const 16
    i32.sub
    tee_local 3
    set_global 0
    get_local 3
    get_local 0
    i32.store offset=12
    get_local 3
    get_local 1
    i32.store offset=8
    get_local 3
    get_local 2
    i32.store offset=4
    block  ;; label = @1
      get_local 3
      i32.load offset=8
      get_local 3
      i32.load offset=12
      call $__gnu_cxx::new_allocator<int__*___>::max_size___const
      i32.le_u
      br_if 0 (;@1;)
      call $std::__throw_bad_alloc__
      unreachable
    end
    get_local 3
    i32.load offset=8
    i32.const 2
    i32.shl
    call $operator_new_unsigned_long_
    set_local 2
    get_local 3
    i32.const 16
    i32.add
    set_global 0
    get_local 2)
  (func $__gnu_cxx::new_allocator<int__*___>::max_size___const (type 3) (param i32) (result i32)
    get_global 0
    i32.const 16
    i32.sub
    get_local 0
    i32.store offset=12
    i32.const 1073741823)
  (func $std::_Vector_base<int__*_____std::allocator<int__*___>_>::_M_get_Tp_allocator___const (type 3) (param i32) (result i32)
    (local i32)
    get_global 0
    i32.const 16
    i32.sub
    tee_local 1
    get_local 0
    i32.store offset=12
    get_local 1
    i32.load offset=12)
  (func $std::allocator_traits<std::allocator<int__*___>_>::max_size_std::allocator<int__*___>_const&_ (type 3) (param i32) (result i32)
    (local i32)
    get_global 0
    i32.const 16
    i32.sub
    tee_local 1
    set_global 0
    get_local 1
    get_local 0
    i32.store offset=12
    get_local 1
    i32.load offset=12
    call $__gnu_cxx::new_allocator<int__*___>::max_size___const
    set_local 0
    get_local 1
    i32.const 16
    i32.add
    set_global 0
    get_local 0)
  (func $bool___gnu_cxx::operator!=<int__**_____std::vector<int__*_____std::allocator<int__*___>_>_>___gnu_cxx::__normal_iterator<int__**_____std::vector<int__*_____std::allocator<int__*___>_>_>_const&____gnu_cxx::__normal_iterator<int__**_____std::vector<int__*_____std::allocator<int__*___>_>_>_const&_ (type 6) (param i32 i32) (result i32)
    (local i32)
    get_global 0
    i32.const 16
    i32.sub
    tee_local 2
    set_global 0
    get_local 2
    get_local 0
    i32.store offset=12
    get_local 2
    get_local 1
    i32.store offset=8
    get_local 2
    i32.load offset=12
    call $__gnu_cxx::__normal_iterator<int__**_____std::vector<int__*_____std::allocator<int__*___>_>_>::base___const
    i32.load
    set_local 1
    get_local 2
    i32.load offset=8
    call $__gnu_cxx::__normal_iterator<int__**_____std::vector<int__*_____std::allocator<int__*___>_>_>::base___const
    i32.load
    set_local 0
    get_local 2
    i32.const 16
    i32.add
    set_global 0
    get_local 1
    get_local 0
    i32.ne)
  (func $__gnu_cxx::__normal_iterator<int__**_____std::vector<int__*_____std::allocator<int__*___>_>_>::operator++__ (type 3) (param i32) (result i32)
    (local i32)
    get_global 0
    i32.const 16
    i32.sub
    tee_local 1
    get_local 0
    i32.store offset=12
    get_local 1
    i32.load offset=12
    tee_local 0
    get_local 0
    i32.load
    i32.const 4
    i32.add
    i32.store
    get_local 0)
  (table (;0;) 2 2 anyfunc)
  (memory (;0;) 2)
  (global (;0;) (mut i32) (i32.const 66608))
  (global (;1;) i32 (i32.const 66608))
  (global (;2;) i32 (i32.const 1062))
  (export "memory" (memory 0))
  (export "__heap_base" (global 1))
  (export "__data_end" (global 2))
  (export "_ZNSt6vectorIPFivESaIS1_EEC2Ev" (func $std::vector<int__*_____std::allocator<int__*___>_>::vector__))
  (export "_ZNSt6vectorIPFivESaIS1_EED2Ev" (func $std::vector<int__*_____std::allocator<int__*___>_>::~vector__))
  (export "_ZNSt6vectorIPFivESaIS1_EE9push_backEOS1_" (func $std::vector<int__*_____std::allocator<int__*___>_>::push_back_int__*&&____))
  (export "_ZNSt6vectorIPFivESaIS1_EE5beginEv" (func $std::vector<int__*_____std::allocator<int__*___>_>::begin__))
  (export "_ZN9__gnu_cxxneIPPFivESt6vectorIS2_SaIS2_EEEEbRKNS_17__normal_iteratorIT_T0_EESC_" (func $bool___gnu_cxx::operator!=<int__**_____std::vector<int__*_____std::allocator<int__*___>_>_>___gnu_cxx::__normal_iterator<int__**_____std::vector<int__*_____std::allocator<int__*___>_>_>_const&____gnu_cxx::__normal_iterator<int__**_____std::vector<int__*_____std::allocator<int__*___>_>_>_const&_))
  (export "_ZNSt6vectorIPFivESaIS1_EE3endEv" (func $std::vector<int__*_____std::allocator<int__*___>_>::end__))
  (export "_ZNK9__gnu_cxx17__normal_iteratorIPPFivESt6vectorIS2_SaIS2_EEEdeEv" (func $__gnu_cxx::__normal_iterator<int__**_____std::vector<int__*_____std::allocator<int__*___>_>_>::operator*___const))
  (export "_ZN9__gnu_cxx17__normal_iteratorIPPFivESt6vectorIS2_SaIS2_EEEppEv" (func $__gnu_cxx::__normal_iterator<int__**_____std::vector<int__*_____std::allocator<int__*___>_>_>::operator++__))
  (export "_ZNSt12_Vector_baseIPFivESaIS1_EEC2Ev" (func $std::_Vector_base<int__*_____std::allocator<int__*___>_>::_Vector_base__))
  (export "_ZNSt12_Vector_baseIPFivESaIS1_EE12_Vector_implC2Ev" (func $std::_Vector_base<int__*_____std::allocator<int__*___>_>::_Vector_impl::_Vector_impl__))
  (export "_ZNSaIPFivEEC2Ev" (func $std::allocator<int__*___>::allocator__))
  (export "_ZN9__gnu_cxx13new_allocatorIPFivEEC2Ev" (func $__gnu_cxx::new_allocator<int__*___>::new_allocator__))
  (export "_ZSt8_DestroyIPPFivES1_EvT_S3_RSaIT0_E" (func $void_std::_Destroy<int__**_____int__*___>_int__**_____int__**_____std::allocator<int__*___>&_))
  (export "_ZNSt12_Vector_baseIPFivESaIS1_EE19_M_get_Tp_allocatorEv" (func $std::_Vector_base<int__*_____std::allocator<int__*___>_>::_M_get_Tp_allocator__))
  (export "_ZNSt12_Vector_baseIPFivESaIS1_EED2Ev" (func $std::_Vector_base<int__*_____std::allocator<int__*___>_>::~_Vector_base__))
  (export "_ZSt8_DestroyIPPFivEEvT_S3_" (func $void_std::_Destroy<int__**___>_int__**_____int__**____))
  (export "_ZNSt12_Destroy_auxILb1EE9__destroyIPPFivEEEvT_S5_" (func $void_std::_Destroy_aux<true>::__destroy<int__**___>_int__**_____int__**____))
  (export "_ZNSt12_Vector_baseIPFivESaIS1_EE13_M_deallocateEPS1_m" (func $std::_Vector_base<int__*_____std::allocator<int__*___>_>::_M_deallocate_int__**_____unsigned_long_))
  (export "_ZNSt12_Vector_baseIPFivESaIS1_EE12_Vector_implD2Ev" (func $std::_Vector_base<int__*_____std::allocator<int__*___>_>::_Vector_impl::~_Vector_impl__))
  (export "_ZNSt16allocator_traitsISaIPFivEEE10deallocateERS2_PS1_m" (func $std::allocator_traits<std::allocator<int__*___>_>::deallocate_std::allocator<int__*___>&__int__**_____unsigned_long_))
  (export "_ZN9__gnu_cxx13new_allocatorIPFivEE10deallocateEPS2_m" (func $__gnu_cxx::new_allocator<int__*___>::deallocate_int__**_____unsigned_long_))
  (export "_ZNSaIPFivEED2Ev" (func $std::allocator<int__*___>::~allocator__))
  (export "_ZN9__gnu_cxx13new_allocatorIPFivEED2Ev" (func $__gnu_cxx::new_allocator<int__*___>::~new_allocator__))
  (export "_ZNSt6vectorIPFivESaIS1_EE12emplace_backIJS1_EEERS1_DpOT_" (func $int__*&std::vector<int__*_____std::allocator<int__*___>_>::emplace_back<int__*___>_int__*&&_______))
  (export "_ZSt4moveIRPFivEEONSt16remove_referenceIT_E4typeEOS4_" (func $std::remove_reference<int__*&___>::type&&_std::move<int__*&___>_int__*&____))
  (export "_ZNSt16allocator_traitsISaIPFivEEE9constructIS1_JS1_EEEvRS2_PT_DpOT0_" (func $void_std::allocator_traits<std::allocator<int__*___>_>::construct<int__*_____int__*___>_std::allocator<int__*___>&__int__**_____int__*&&____))
  (export "_ZSt7forwardIPFivEEOT_RNSt16remove_referenceIS2_E4typeE" (func $int__*&&std::forward<int__*___>_std::remove_reference<int__*___>::type&____))
  (export "_ZNSt6vectorIPFivESaIS1_EE17_M_realloc_insertIJS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_" (func $void_std::vector<int__*_____std::allocator<int__*___>_>::_M_realloc_insert<int__*___>___gnu_cxx::__normal_iterator<int__**_____std::vector<int__*_____std::allocator<int__*___>_>_>__int__*&&____))
  (export "_ZNSt6vectorIPFivESaIS1_EE4backEv" (func $std::vector<int__*_____std::allocator<int__*___>_>::back__))
  (export "_ZN9__gnu_cxx13new_allocatorIPFivEE9constructIS2_JS2_EEEvPT_DpOT0_" (func $void___gnu_cxx::new_allocator<int__*___>::construct<int__*_____int__*___>_int__**_____int__*&&____))
  (export "_ZNKSt6vectorIPFivESaIS1_EE12_M_check_lenEmPKc" (func $std::vector<int__*_____std::allocator<int__*___>_>::_M_check_len_unsigned_long__char_const*__const))
  (export "_ZN9__gnu_cxxmiIPPFivESt6vectorIS2_SaIS2_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKSA_SD_" (func $__gnu_cxx::__normal_iterator<int__**_____std::vector<int__*_____std::allocator<int__*___>_>_>::difference_type___gnu_cxx::operator-<int__**_____std::vector<int__*_____std::allocator<int__*___>_>_>___gnu_cxx::__normal_iterator<int__**_____std::vector<int__*_____std::allocator<int__*___>_>_>_const&____gnu_cxx::__normal_iterator<int__**_____std::vector<int__*_____std::allocator<int__*___>_>_>_const&_))
  (export "_ZNSt12_Vector_baseIPFivESaIS1_EE11_M_allocateEm" (func $std::_Vector_base<int__*_____std::allocator<int__*___>_>::_M_allocate_unsigned_long_))
  (export "_ZSt34__uninitialized_move_if_noexcept_aIPPFivES2_SaIS1_EET0_T_S5_S4_RT1_" (func $int__**std::__uninitialized_move_if_noexcept_a<int__**_____int__**_____std::allocator<int__*___>_>_int__**_____int__**_____int__**_____std::allocator<int__*___>&____))
  (export "_ZNK9__gnu_cxx17__normal_iteratorIPPFivESt6vectorIS2_SaIS2_EEE4baseEv" (func $__gnu_cxx::__normal_iterator<int__**_____std::vector<int__*_____std::allocator<int__*___>_>_>::base___const))
  (export "_ZNSt16allocator_traitsISaIPFivEEE7destroyIS1_EEvRS2_PT_" (func $void_std::allocator_traits<std::allocator<int__*___>_>::destroy<int__*___>_std::allocator<int__*___>&__int__**____))
  (export "_ZNKSt6vectorIPFivESaIS1_EE8max_sizeEv" (func $std::vector<int__*_____std::allocator<int__*___>_>::max_size___const))
  (export "_ZNKSt6vectorIPFivESaIS1_EE4sizeEv" (func $std::vector<int__*_____std::allocator<int__*___>_>::size___const))
  (export "_ZSt3maxImERKT_S2_S2_" (func $unsigned_long_const&_std::max<unsigned_long>_unsigned_long_const&__unsigned_long_const&_))
  (export "_ZNSt16allocator_traitsISaIPFivEEE8max_sizeERKS2_" (func $std::allocator_traits<std::allocator<int__*___>_>::max_size_std::allocator<int__*___>_const&_))
  (export "_ZNKSt12_Vector_baseIPFivESaIS1_EE19_M_get_Tp_allocatorEv" (func $std::_Vector_base<int__*_____std::allocator<int__*___>_>::_M_get_Tp_allocator___const))
  (export "_ZNK9__gnu_cxx13new_allocatorIPFivEE8max_sizeEv" (func $__gnu_cxx::new_allocator<int__*___>::max_size___const))
  (export "_ZNSt16allocator_traitsISaIPFivEEE8allocateERS2_m" (func $std::allocator_traits<std::allocator<int__*___>_>::allocate_std::allocator<int__*___>&__unsigned_long_))
  (export "_ZN9__gnu_cxx13new_allocatorIPFivEE8allocateEmPKv" (func $__gnu_cxx::new_allocator<int__*___>::allocate_unsigned_long__void_const*_))
  (export "_ZSt22__uninitialized_copy_aISt13move_iteratorIPPFivEES3_S2_ET0_T_S6_S5_RSaIT1_E" (func $int__**std::__uninitialized_copy_a<std::move_iterator<int__**___>__int__**_____int__*___>_std::move_iterator<int__**___>__std::move_iterator<int__**___>__int__**_____std::allocator<int__*___>&____))
  (export "_ZSt32__make_move_if_noexcept_iteratorIPFivESt13move_iteratorIPS1_EET0_PT_" (func $std::move_iterator<int__**___>_std::__make_move_if_noexcept_iterator<int__*_____std::move_iterator<int__**___>_>_int__**____))
  (export "_ZSt18uninitialized_copyISt13move_iteratorIPPFivEES3_ET0_T_S6_S5_" (func $int__**std::uninitialized_copy<std::move_iterator<int__**___>__int__**___>_std::move_iterator<int__**___>__std::move_iterator<int__**___>__int__**_______))
  (export "_ZNSt20__uninitialized_copyILb1EE13__uninit_copyISt13move_iteratorIPPFivEES5_EET0_T_S8_S7_" (func $int__**std::__uninitialized_copy<true>::__uninit_copy<std::move_iterator<int__**___>__int__**___>_std::move_iterator<int__**___>__std::move_iterator<int__**___>__int__**_______))
  (export "_ZSt4copyISt13move_iteratorIPPFivEES3_ET0_T_S6_S5_" (func $int__**std::copy<std::move_iterator<int__**___>__int__**___>_std::move_iterator<int__**___>__std::move_iterator<int__**___>__int__**_______))
  (export "_ZSt14__copy_move_a2ILb1EPPFivES2_ET1_T0_S4_S3_" (func $int__**std::__copy_move_a2<true__int__**_____int__**___>_int__**_____int__**_____int__**_______))
  (export "_ZSt12__miter_baseIPPFivEEDTcl12__miter_basecldtfp_4baseEEESt13move_iteratorIT_E" (func $decltype___miter_base_fp.base_____std::__miter_base<int__**___>_std::move_iterator<int__**___>_))
  (export "_ZSt13__copy_move_aILb1EPPFivES2_ET1_T0_S4_S3_" (func $int__**std::__copy_move_a<true__int__**_____int__**___>_int__**_____int__**_____int__**_______))
  (export "_ZSt12__niter_baseIPPFivEET_S3_" (func $int__**std::__niter_base<int__**___>_int__**_______))
  (export "_ZNSt11__copy_moveILb1ELb1ESt26random_access_iterator_tagE8__copy_mIPFivEEEPT_PKS5_S8_S6_" (func $int__**std::__copy_move<true__true__std::random_access_iterator_tag>::__copy_m<int__*___>_int__*_const*_____int__*_const*_____int__**_______))
  (export "_ZSt12__miter_baseIPPFivEET_S3_" (func $int__**std::__miter_base<int__**___>_int__**_______))
  (export "_ZNKSt13move_iteratorIPPFivEE4baseEv" (func $std::move_iterator<int__**___>::base___const))
  (export "_ZNSt13move_iteratorIPPFivEEC2ES2_" (func $std::move_iterator<int__**___>::move_iterator_int__**____))
  (export "_ZN9__gnu_cxx13new_allocatorIPFivEE7destroyIS2_EEvPT_" (func $void___gnu_cxx::new_allocator<int__*___>::destroy<int__*___>_int__**____))
  (export "_ZNK9__gnu_cxx17__normal_iteratorIPPFivESt6vectorIS2_SaIS2_EEEmiEl" (func $__gnu_cxx::__normal_iterator<int__**_____std::vector<int__*_____std::allocator<int__*___>_>_>::operator-_long__const))
  (export "_ZN9__gnu_cxx17__normal_iteratorIPPFivESt6vectorIS2_SaIS2_EEEC2ERKS3_" (func $__gnu_cxx::__normal_iterator<int__**_____std::vector<int__*_____std::allocator<int__*___>_>_>::__normal_iterator_int__**_const&____))
  (elem (i32.const 1) $__cxx_global_array_dtor)
  (data (i32.const 1024) "\00\00\00\00\00\00\00\00\00\00\00\00")
  (data (i32.const 1036) "vector::_M_realloc_insert\00"))
