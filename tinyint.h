#ifndef TINYINT_H
#define TINYINT_H

/**
 * This is where it begins..
 */
typedef char tinyint;

/**
 * Seems these was removed in recent versions.
 * Source: http://web.mit.edu/databases/pgsql/arch/i386_nbsd1/include/c.h
 */
#ifndef GET_1_BYTE
#define GET_1_BYTE(datum) (((Datum) (datum)) & 0x000000ff)
#endif
#ifndef SET_1_BYTE
#define SET_1_BYTE(value) (((Datum) (value)) & 0x000000ff)
#endif

#define DatumGetTinyInt(x) ((tinyint) GET_1_BYTE(x))
#define TinyIntGetDatum(x) ((Datum) SET_1_BYTE(x))

#define PG_GETARG_TINYINT(n) DatumGetTinyInt(PG_GETARG_DATUM(n))
#define PG_RETURN_TINYINT(x) return TinyIntGetDatum(x)

extern Datum tinyint_in(PG_FUNCTION_ARGS);
extern Datum tinyint_out(PG_FUNCTION_ARGS);
extern Datum tinyint_recv(PG_FUNCTION_ARGS);
extern Datum tinyint_send(PG_FUNCTION_ARGS);

extern Datum tinyint_to_smallint(PG_FUNCTION_ARGS);
extern Datum smallint_to_tinyint(PG_FUNCTION_ARGS);
extern Datum tinyint_to_int(PG_FUNCTION_ARGS);
extern Datum int_to_tinyint(PG_FUNCTION_ARGS);
extern Datum tinyint_to_bigint(PG_FUNCTION_ARGS);
extern Datum bigint_to_tinyint(PG_FUNCTION_ARGS);
extern Datum tinyint_to_bool(PG_FUNCTION_ARGS);
extern Datum bool_to_tinyint(PG_FUNCTION_ARGS);

extern Datum tinyint_eq(PG_FUNCTION_ARGS);
extern Datum tinyint_ne(PG_FUNCTION_ARGS);
extern Datum tinyint_lt(PG_FUNCTION_ARGS);
extern Datum tinyint_le(PG_FUNCTION_ARGS);
extern Datum tinyint_gt(PG_FUNCTION_ARGS);
extern Datum tinyint_ge(PG_FUNCTION_ARGS);

extern Datum tinyint_i2_eq(PG_FUNCTION_ARGS);
extern Datum tinyint_i2_ne(PG_FUNCTION_ARGS);
extern Datum tinyint_i2_lt(PG_FUNCTION_ARGS);
extern Datum tinyint_i2_le(PG_FUNCTION_ARGS);
extern Datum tinyint_i2_gt(PG_FUNCTION_ARGS);
extern Datum tinyint_i2_ge(PG_FUNCTION_ARGS);

extern Datum tinyint_i4_eq(PG_FUNCTION_ARGS);
extern Datum tinyint_i4_ne(PG_FUNCTION_ARGS);
extern Datum tinyint_i4_lt(PG_FUNCTION_ARGS);
extern Datum tinyint_i4_le(PG_FUNCTION_ARGS);
extern Datum tinyint_i4_gt(PG_FUNCTION_ARGS);
extern Datum tinyint_i4_ge(PG_FUNCTION_ARGS);

extern Datum tinyint_i8_eq(PG_FUNCTION_ARGS);
extern Datum tinyint_i8_ne(PG_FUNCTION_ARGS);
extern Datum tinyint_i8_lt(PG_FUNCTION_ARGS);
extern Datum tinyint_i8_le(PG_FUNCTION_ARGS);
extern Datum tinyint_i8_gt(PG_FUNCTION_ARGS);
extern Datum tinyint_i8_ge(PG_FUNCTION_ARGS);

extern Datum i2_tinyint_eq(PG_FUNCTION_ARGS);
extern Datum i2_tinyint_ne(PG_FUNCTION_ARGS);
extern Datum i2_tinyint_lt(PG_FUNCTION_ARGS);
extern Datum i2_tinyint_le(PG_FUNCTION_ARGS);
extern Datum i2_tinyint_gt(PG_FUNCTION_ARGS);
extern Datum i2_tinyint_ge(PG_FUNCTION_ARGS);

extern Datum i4_tinyint_eq(PG_FUNCTION_ARGS);
extern Datum i4_tinyint_ne(PG_FUNCTION_ARGS);
extern Datum i4_tinyint_lt(PG_FUNCTION_ARGS);
extern Datum i4_tinyint_le(PG_FUNCTION_ARGS);
extern Datum i4_tinyint_gt(PG_FUNCTION_ARGS);
extern Datum i4_tinyint_ge(PG_FUNCTION_ARGS);

extern Datum i8_tinyint_eq(PG_FUNCTION_ARGS);
extern Datum i8_tinyint_ne(PG_FUNCTION_ARGS);
extern Datum i8_tinyint_lt(PG_FUNCTION_ARGS);
extern Datum i8_tinyint_le(PG_FUNCTION_ARGS);
extern Datum i8_tinyint_gt(PG_FUNCTION_ARGS);
extern Datum i8_tinyint_ge(PG_FUNCTION_ARGS);

extern Datum tinyint_um(PG_FUNCTION_ARGS);
extern Datum tinyint_up(PG_FUNCTION_ARGS);
extern Datum tinyint_pl(PG_FUNCTION_ARGS);
extern Datum tinyint_mi(PG_FUNCTION_ARGS);
extern Datum tinyint_mul(PG_FUNCTION_ARGS);
extern Datum tinyint_div(PG_FUNCTION_ARGS);
extern Datum tinyint_inc(PG_FUNCTION_ARGS);

extern Datum tinyint_i2_pl(PG_FUNCTION_ARGS);
extern Datum tinyint_i2_mi(PG_FUNCTION_ARGS);
extern Datum tinyint_i2_mul(PG_FUNCTION_ARGS);
extern Datum tinyint_i2_div(PG_FUNCTION_ARGS);

extern Datum tinyint_i4_pl(PG_FUNCTION_ARGS);
extern Datum tinyint_i4_mi(PG_FUNCTION_ARGS);
extern Datum tinyint_i4_mul(PG_FUNCTION_ARGS);
extern Datum tinyint_i4_div(PG_FUNCTION_ARGS);

extern Datum tinyint_i8_pl(PG_FUNCTION_ARGS);
extern Datum tinyint_i8_mi(PG_FUNCTION_ARGS);
extern Datum tinyint_i8_mul(PG_FUNCTION_ARGS);
extern Datum tinyint_i8_div(PG_FUNCTION_ARGS);

extern Datum i2_tinyint_pl(PG_FUNCTION_ARGS);
extern Datum i2_tinyint_mi(PG_FUNCTION_ARGS);
extern Datum i2_tinyint_mul(PG_FUNCTION_ARGS);
extern Datum i2_tinyint_div(PG_FUNCTION_ARGS);

extern Datum i4_tinyint_pl(PG_FUNCTION_ARGS);
extern Datum i4_tinyint_mi(PG_FUNCTION_ARGS);
extern Datum i4_tinyint_mul(PG_FUNCTION_ARGS);
extern Datum i4_tinyint_div(PG_FUNCTION_ARGS);

extern Datum i8_tinyint_pl(PG_FUNCTION_ARGS);
extern Datum i8_tinyint_mi(PG_FUNCTION_ARGS);
extern Datum i8_tinyint_mul(PG_FUNCTION_ARGS);
extern Datum i8_tinyint_div(PG_FUNCTION_ARGS);

extern Datum tinyint_mod(PG_FUNCTION_ARGS);
extern Datum tinyint_abs(PG_FUNCTION_ARGS);
extern Datum tinyint_larger(PG_FUNCTION_ARGS);
extern Datum tinyint_smaller(PG_FUNCTION_ARGS);
extern Datum tinyint_and(PG_FUNCTION_ARGS);
extern Datum tinyint_or(PG_FUNCTION_ARGS);
extern Datum tinyint_xor(PG_FUNCTION_ARGS);
extern Datum tinyint_shl(PG_FUNCTION_ARGS);
extern Datum tinyint_shr(PG_FUNCTION_ARGS);
extern Datum tinyint_not(PG_FUNCTION_ARGS);

extern Datum bt_tinyint_cmp(PG_FUNCTION_ARGS);
extern Datum bt_tinyint_i2_cmp(PG_FUNCTION_ARGS);
extern Datum bt_tinyint_i4_cmp(PG_FUNCTION_ARGS);
extern Datum bt_tinyint_i8_cmp(PG_FUNCTION_ARGS);
extern Datum bt_i2_tinyint_cmp(PG_FUNCTION_ARGS);
extern Datum bt_i4_tinyint_cmp(PG_FUNCTION_ARGS);
extern Datum bt_i8_tinyint_cmp(PG_FUNCTION_ARGS);

extern Datum hash_tinyint(PG_FUNCTION_ARGS);

extern Datum tinyint_sum(PG_FUNCTION_ARGS);
extern Datum tinyint_avg_accum(PG_FUNCTION_ARGS);

#endif   /* TINYINT_H */
