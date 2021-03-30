#include <caml/mlvalues.h>
#include <caml/alloc.h>
#include <caml/fail.h>
#include <caml/callback.h>
#include <caml/memory.h>

#include <stdio.h>

#ifdef CAMLprim
#undef CAMLprim
#endif

#define CAMLprim __attribute__((used))
#define STUB { trace(__func__); err_not_implemented(__func__); return Atom(0); }
#define STUB0 { trace(__func__); return Atom(0); }

void trace(const char *func) {
    char __buf[64];
    snprintf(__buf, sizeof(__buf), "unix stub: %s(...)\n", func);
#ifdef __wasi__
    __wasi_trace(__buf);
#endif
}

void err_not_implemented(const char *func) {
    CAMLparam0();
    CAMLlocal2(exn, err);

    const value *unix_error_exn = caml_named_value("Unix.Unix_error");
    if (unix_error_exn == NULL) {
        caml_invalid_argument("Exception Unix.Unix_error not initialized");
        return;
    }

    err = caml_alloc_small(1, 0);
    Store_field(err, 0, Val_int(-1));

    value name = caml_copy_string(func),
          arg = caml_copy_string("(not implemented)");

    exn = caml_alloc_small(4, 0);
    Store_field(exn, 0, *unix_error_exn);
    Store_field(exn, 1, err);
    Store_field(exn, 2, name);
    Store_field(exn, 3, arg);
    caml_raise(exn);
}


CAMLprim value ml_z_of_int(value v)   STUB
CAMLprim value ml_z_of_nativeint(value v)   STUB
CAMLprim value ml_z_of_int32(value v)   STUB
CAMLprim value ml_z_of_int64(value v)   STUB
CAMLprim value ml_z_of_float(value v)   STUB
CAMLprim value ml_z_of_substring_base(value b, value v, value offset, value length)   STUB
CAMLprim value ml_z_to_int(value v)   STUB
CAMLprim value ml_z_to_nativeint(value v)   STUB
CAMLprim value ml_z_to_int32(value v)   STUB
CAMLprim value ml_z_to_int64(value v)   STUB
CAMLprim value ml_z_format(value f, value v)   STUB
CAMLprim value ml_z_extract(value arg, value off, value len)   STUB
CAMLprim value ml_z_to_bits(value arg)   STUB
CAMLprim value ml_z_of_bits(value arg)   STUB
CAMLprim value ml_z_compare(value arg1, value arg2)   STUB
CAMLprim value ml_z_equal(value arg1, value arg2)   STUB
CAMLprim value ml_z_sign(value arg)   STUB
CAMLprim value ml_z_fits_int(value v)   STUB
CAMLprim value ml_z_fits_nativeint(value v)   STUB
CAMLprim value ml_z_fits_int32(value v)   STUB
CAMLprim value ml_z_fits_int64(value v)   STUB
CAMLprim value ml_z_size(value v)   STUB
CAMLprim value ml_z_neg(value arg)   STUB
CAMLprim value ml_z_abs(value arg)   STUB
CAMLprim value ml_z_add(value arg1, value arg2)   STUB
CAMLprim value ml_z_sub(value arg1, value arg2)   STUB
CAMLprim value ml_z_mul_overflows(value vx, value vy)   STUB
CAMLprim value ml_z_mul(value arg1, value arg2)   STUB
CAMLprim value ml_z_div_rem(value arg1, value arg2)   STUB
CAMLprim value ml_z_div(value arg1, value arg2)   STUB
CAMLprim value ml_z_rem(value arg1, value arg2)   STUB
CAMLprim value ml_z_cdiv(value arg1, value arg2)   STUB
CAMLprim value ml_z_fdiv(value arg1, value arg2)   STUB
CAMLprim value ml_z_succ(value arg)   STUB
CAMLprim value ml_z_pred(value arg)   STUB
CAMLprim value ml_z_sqrt(value arg)   STUB
CAMLprim value ml_z_sqrt_rem(value arg)   STUB
CAMLprim value ml_z_gcd(value arg1, value arg2)   STUB
CAMLprim value ml_z_gcdext_intern(value arg1, value arg2)   STUB
CAMLprim value ml_z_logand(value arg1, value arg2)   STUB
CAMLprim value ml_z_logor(value arg1, value arg2)   STUB
CAMLprim value ml_z_logxor(value arg1, value arg2)   STUB
CAMLprim value ml_z_lognot(value arg)   STUB
CAMLprim value ml_z_shift_left(value arg, value count)   STUB
CAMLprim value ml_z_shift_right(value arg, value count)   STUB
CAMLprim value ml_z_shift_right_trunc(value arg, value count)   STUB
CAMLprim value ml_z_numbits(value arg)   STUB
CAMLprim value ml_z_trailing_zeros(value arg)   STUB
CAMLprim value ml_z_popcount(value arg)   STUB
CAMLprim value ml_z_hamdist(value arg1, value arg2)   STUB
CAMLprim value ml_z_testbit(value arg, value index)   STUB
CAMLprim value ml_z_divexact(value arg1, value arg2)   STUB
CAMLprim value ml_z_powm(value base, value exp, value mod)   STUB
CAMLprim value ml_z_powm_sec(value base, value exp, value mod)   STUB
CAMLprim value ml_z_pow(value base, value exp)   STUB
CAMLprim value ml_z_root(value a, value b)   STUB
CAMLprim value ml_z_rootrem(value a, value b)   STUB
CAMLprim value ml_z_perfect_power(value a)   STUB
CAMLprim value ml_z_perfect_square(value a)   STUB
CAMLprim value ml_z_probab_prime(value a, int b)   STUB
CAMLprim value ml_z_nextprime(value a)   STUB
CAMLprim value ml_z_invert(value base, value mod)   STUB
CAMLprim value ml_z_divisible(value a, value b)   STUB
CAMLprim value ml_z_congruent(value a, value b, value c)   STUB
CAMLprim value ml_z_jacobi(value a, value b)   STUB
CAMLprim value ml_z_legendre(value a, value b)   STUB
CAMLprim value ml_z_kronecker(value a, value b)   STUB
CAMLprim value ml_z_remove(value a, value b)   STUB
CAMLprim value ml_z_fac(value a)   STUB
CAMLprim value ml_z_fac2(value a)   STUB
CAMLprim value ml_z_facM(value a, value b)   STUB
CAMLprim value ml_z_primorial(value a)   STUB
CAMLprim value ml_z_bin(value a, value b)   STUB
CAMLprim value ml_z_fib(value a)   STUB
CAMLprim value ml_z_lucnum(value a)   STUB
CAMLprim value ml_z_hash(value v)   STUB
CAMLprim value ml_z_mlgmpidl_of_mpz(value a)   STUB
CAMLprim value ml_z_mlgmpidl_set_mpz(value r, value a)   STUB
CAMLprim value ml_z_init(value unit)   STUB0
