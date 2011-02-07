
#ifndef TINYINT_H
#define TINYINT_H

#include <ctype.h>

#include "fmgr.h"


typedef char tinyint;

#define DatumGetTinyInt(X) ((tinyint) GET_1_BYTE(X))
#define TinyIntGetDatum(X) ((Datum) SET_1_BYTE(X))

#define PG_GETARG_TINYINT(n)	DatumGetTinyInt(PG_GETARG_DATUM(n))
#define PG_RETURN_TINYINT(x)	return TinyIntGetDatum(x)

extern Datum tinyint_in(PG_FUNCTION_ARGS);
extern Datum tinyint_out(PG_FUNCTION_ARGS);
extern Datum tinyint_recv(PG_FUNCTION_ARGS);
extern Datum tinyint_send(PG_FUNCTION_ARGS);

extern Datum tinyint_to_i2(PG_FUNCTION_ARGS);
extern Datum i2_to_tinyint(PG_FUNCTION_ARGS);
extern Datum tinyint_to_i4(PG_FUNCTION_ARGS);
extern Datum i4_to_tinyint(PG_FUNCTION_ARGS);
extern Datum tinyint_to_i8(PG_FUNCTION_ARGS);
extern Datum i8_to_tinyint(PG_FUNCTION_ARGS);
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
