#include "postgres.h"

#include <ctype.h>
#include <limits.h>

#include "access/hash.h"
#include "catalog/pg_type.h"
#include "libpq/pqformat.h"
#include "utils/array.h"
#include "utils/builtins.h"
#include "tinyint.h"

#define SAMESIGN(a,b)	(((a) < 0) == ((b) < 0))

PG_MODULE_MAGIC;

PG_FUNCTION_INFO_V1(tinyint_in);
PG_FUNCTION_INFO_V1(tinyint_out);
PG_FUNCTION_INFO_V1(tinyint_recv);
PG_FUNCTION_INFO_V1(tinyint_send);

PG_FUNCTION_INFO_V1(tinyint_to_i2);
PG_FUNCTION_INFO_V1(i2_to_tinyint);
PG_FUNCTION_INFO_V1(tinyint_to_i4);
PG_FUNCTION_INFO_V1(i4_to_tinyint);
PG_FUNCTION_INFO_V1(tinyint_to_i8);
PG_FUNCTION_INFO_V1(i8_to_tinyint);
PG_FUNCTION_INFO_V1(tinyint_to_bool);
PG_FUNCTION_INFO_V1(bool_to_tinyint);

PG_FUNCTION_INFO_V1(tinyint_eq);
PG_FUNCTION_INFO_V1(tinyint_ne);
PG_FUNCTION_INFO_V1(tinyint_lt);
PG_FUNCTION_INFO_V1(tinyint_le);
PG_FUNCTION_INFO_V1(tinyint_gt);
PG_FUNCTION_INFO_V1(tinyint_ge);

PG_FUNCTION_INFO_V1(tinyint_i2_eq);
PG_FUNCTION_INFO_V1(tinyint_i2_ne);
PG_FUNCTION_INFO_V1(tinyint_i2_lt);
PG_FUNCTION_INFO_V1(tinyint_i2_le);
PG_FUNCTION_INFO_V1(tinyint_i2_gt);
PG_FUNCTION_INFO_V1(tinyint_i2_ge);

PG_FUNCTION_INFO_V1(tinyint_i4_eq);
PG_FUNCTION_INFO_V1(tinyint_i4_ne);
PG_FUNCTION_INFO_V1(tinyint_i4_lt);
PG_FUNCTION_INFO_V1(tinyint_i4_le);
PG_FUNCTION_INFO_V1(tinyint_i4_gt);
PG_FUNCTION_INFO_V1(tinyint_i4_ge);

PG_FUNCTION_INFO_V1(tinyint_i8_eq);
PG_FUNCTION_INFO_V1(tinyint_i8_ne);
PG_FUNCTION_INFO_V1(tinyint_i8_lt);
PG_FUNCTION_INFO_V1(tinyint_i8_le);
PG_FUNCTION_INFO_V1(tinyint_i8_gt);
PG_FUNCTION_INFO_V1(tinyint_i8_ge);

PG_FUNCTION_INFO_V1(i2_tinyint_eq);
PG_FUNCTION_INFO_V1(i2_tinyint_ne);
PG_FUNCTION_INFO_V1(i2_tinyint_lt);
PG_FUNCTION_INFO_V1(i2_tinyint_le);
PG_FUNCTION_INFO_V1(i2_tinyint_gt);
PG_FUNCTION_INFO_V1(i2_tinyint_ge);

PG_FUNCTION_INFO_V1(i4_tinyint_eq);
PG_FUNCTION_INFO_V1(i4_tinyint_ne);
PG_FUNCTION_INFO_V1(i4_tinyint_lt);
PG_FUNCTION_INFO_V1(i4_tinyint_le);
PG_FUNCTION_INFO_V1(i4_tinyint_gt);
PG_FUNCTION_INFO_V1(i4_tinyint_ge);

PG_FUNCTION_INFO_V1(i8_tinyint_eq);
PG_FUNCTION_INFO_V1(i8_tinyint_ne);
PG_FUNCTION_INFO_V1(i8_tinyint_lt);
PG_FUNCTION_INFO_V1(i8_tinyint_le);
PG_FUNCTION_INFO_V1(i8_tinyint_gt);
PG_FUNCTION_INFO_V1(i8_tinyint_ge);

PG_FUNCTION_INFO_V1(tinyint_um);
PG_FUNCTION_INFO_V1(tinyint_up);
PG_FUNCTION_INFO_V1(tinyint_pl);
PG_FUNCTION_INFO_V1(tinyint_mi);
PG_FUNCTION_INFO_V1(tinyint_mul);
PG_FUNCTION_INFO_V1(tinyint_div);
PG_FUNCTION_INFO_V1(tinyint_inc);

PG_FUNCTION_INFO_V1(tinyint_i2_pl);
PG_FUNCTION_INFO_V1(tinyint_i2_mi);
PG_FUNCTION_INFO_V1(tinyint_i2_mul);
PG_FUNCTION_INFO_V1(tinyint_i2_div);

PG_FUNCTION_INFO_V1(tinyint_i4_pl);
PG_FUNCTION_INFO_V1(tinyint_i4_mi);
PG_FUNCTION_INFO_V1(tinyint_i4_mul);
PG_FUNCTION_INFO_V1(tinyint_i4_div);

PG_FUNCTION_INFO_V1(tinyint_i8_pl);
PG_FUNCTION_INFO_V1(tinyint_i8_mi);
PG_FUNCTION_INFO_V1(tinyint_i8_mul);
PG_FUNCTION_INFO_V1(tinyint_i8_div);

PG_FUNCTION_INFO_V1(i2_tinyint_pl);
PG_FUNCTION_INFO_V1(i2_tinyint_mi);
PG_FUNCTION_INFO_V1(i2_tinyint_mul);
PG_FUNCTION_INFO_V1(i2_tinyint_div);

PG_FUNCTION_INFO_V1(i4_tinyint_pl);
PG_FUNCTION_INFO_V1(i4_tinyint_mi);
PG_FUNCTION_INFO_V1(i4_tinyint_mul);
PG_FUNCTION_INFO_V1(i4_tinyint_div);

PG_FUNCTION_INFO_V1(i8_tinyint_pl);
PG_FUNCTION_INFO_V1(i8_tinyint_mi);
PG_FUNCTION_INFO_V1(i8_tinyint_mul);
PG_FUNCTION_INFO_V1(i8_tinyint_div);

PG_FUNCTION_INFO_V1(tinyint_mod);
PG_FUNCTION_INFO_V1(tinyint_abs);
PG_FUNCTION_INFO_V1(tinyint_larger);
PG_FUNCTION_INFO_V1(tinyint_smaller);
PG_FUNCTION_INFO_V1(tinyint_and);
PG_FUNCTION_INFO_V1(tinyint_or);
PG_FUNCTION_INFO_V1(tinyint_xor);
PG_FUNCTION_INFO_V1(tinyint_shl);
PG_FUNCTION_INFO_V1(tinyint_shr);
PG_FUNCTION_INFO_V1(tinyint_not);

PG_FUNCTION_INFO_V1(bt_tinyint_cmp);
PG_FUNCTION_INFO_V1(bt_tinyint_i2_cmp);
PG_FUNCTION_INFO_V1(bt_tinyint_i4_cmp);
PG_FUNCTION_INFO_V1(bt_tinyint_i8cmp);
PG_FUNCTION_INFO_V1(bt_i2_tinyint_cmp);
PG_FUNCTION_INFO_V1(bt_i4_tinyint_cmp);
PG_FUNCTION_INFO_V1(bt_i8_tinyint_cmp);

PG_FUNCTION_INFO_V1(hash_tinyint);

PG_FUNCTION_INFO_V1(tinyint_sum);
PG_FUNCTION_INFO_V1(tinyint_avg_accum);

/*****************************************************************************
 *	 USER I/O ROUTINES														 *
 *****************************************************************************/

/*
 *	tinyint_in		- converts "num" to tinyint
 */
Datum
tinyint_in(PG_FUNCTION_ARGS)
{
	char	   *num = PG_GETARG_CSTRING(0);

	PG_RETURN_TINYINT(pg_atoi(num, sizeof(tinyint), '\0'));
}

/*
 *	tinyint_out		- converts tinyint to "num"
 */
Datum
tinyint_out(PG_FUNCTION_ARGS)
{
	tinyint		arg1 = PG_GETARG_TINYINT(0);
	char	   *result = (char *) palloc(5);	/* sign, 3 digits, '\0' */

	pg_itoa(arg1, result);
	PG_RETURN_CSTRING(result);
}

/*
 *	tinyint_recv		- converts external binary format to tinyint
 */
Datum
tinyint_recv(PG_FUNCTION_ARGS)
{
	StringInfo	buf = (StringInfo) PG_GETARG_POINTER(0);

	PG_RETURN_TINYINT((tinyint) pq_getmsgint(buf, sizeof(tinyint)));
}

/*
 * tinyint_send			- converts tinyint to binary format
 */
Datum
tinyint_send(PG_FUNCTION_ARGS)
{
	tinyint		arg1 = PG_GETARG_TINYINT(0);
	StringInfoData buf;

	pq_begintypsend(&buf);
	pq_sendint(&buf, arg1, sizeof(tinyint));
	PG_RETURN_BYTEA_P(pq_endtypsend(&buf));
}

/*
 *		===================
 *		CONVERSION ROUTINES
 *		===================
 */

Datum
tinyint_to_i2(PG_FUNCTION_ARGS)
{
	tinyint		arg1 = PG_GETARG_TINYINT(0);

	PG_RETURN_INT16((int16) arg1);
}

Datum
i2_to_tinyint(PG_FUNCTION_ARGS)
{
	int16		arg1 = PG_GETARG_INT16(0);

	if (arg1 < SCHAR_MIN || arg1 > SCHAR_MAX)
		ereport(ERROR,
				(errcode(ERRCODE_NUMERIC_VALUE_OUT_OF_RANGE),
				 errmsg("tinyint out of range")));

	PG_RETURN_TINYINT((tinyint) arg1);
}

Datum
tinyint_to_i4(PG_FUNCTION_ARGS)
{
	tinyint		arg1 = PG_GETARG_TINYINT(0);

	PG_RETURN_INT32((int32) arg1);
}

Datum
i4_to_tinyint(PG_FUNCTION_ARGS)
{
	int32		arg1 = PG_GETARG_INT32(0);

	if (arg1 < SCHAR_MIN || arg1 > SCHAR_MAX)
		ereport(ERROR,
				(errcode(ERRCODE_NUMERIC_VALUE_OUT_OF_RANGE),
				 errmsg("tinyint out of range")));

	PG_RETURN_TINYINT((tinyint) arg1);
}

Datum
tinyint_to_i8(PG_FUNCTION_ARGS)
{
	tinyint		arg1 = PG_GETARG_TINYINT(0);

	PG_RETURN_INT64((int64) arg1);
}

Datum
i8_to_tinyint(PG_FUNCTION_ARGS)
{
	int64		arg1 = PG_GETARG_INT64(0);
	tinyint		result;

	result = (tinyint) arg1;

	if ((int64) result != arg1)
		ereport(ERROR,
				(errcode(ERRCODE_NUMERIC_VALUE_OUT_OF_RANGE),
				 errmsg("tinyint out of range")));

	PG_RETURN_TINYINT(result);
}

Datum
tinyint_to_bool(PG_FUNCTION_ARGS)
{
	if (PG_GETARG_TINYINT(0) == 0)
		PG_RETURN_BOOL(false);
	else
		PG_RETURN_BOOL(true);
}

Datum
bool_to_tinyint(PG_FUNCTION_ARGS)
{
	if (PG_GETARG_BOOL(0) == false)
		PG_RETURN_TINYINT(0);
	else
		PG_RETURN_TINYINT(1);
}

/*
 *		============================
 *		COMPARISON OPERATOR ROUTINES
 *		============================
 */

Datum
tinyint_eq(PG_FUNCTION_ARGS)
{
	PG_RETURN_BOOL(PG_GETARG_TINYINT(0) == PG_GETARG_TINYINT(1));
}

Datum
tinyint_ne(PG_FUNCTION_ARGS)
{
	PG_RETURN_BOOL(PG_GETARG_TINYINT(0) != PG_GETARG_TINYINT(1));
}

Datum
tinyint_lt(PG_FUNCTION_ARGS)
{
	PG_RETURN_BOOL(PG_GETARG_TINYINT(0) < PG_GETARG_TINYINT(1));
}

Datum
tinyint_le(PG_FUNCTION_ARGS)
{
	PG_RETURN_BOOL(PG_GETARG_TINYINT(0) <= PG_GETARG_TINYINT(1));
}

Datum
tinyint_gt(PG_FUNCTION_ARGS)
{
	PG_RETURN_BOOL(PG_GETARG_TINYINT(0) > PG_GETARG_TINYINT(1));
}

Datum
tinyint_ge(PG_FUNCTION_ARGS)
{
	PG_RETURN_BOOL(PG_GETARG_TINYINT(0) >= PG_GETARG_TINYINT(1));
}

Datum
tinyint_i2_eq(PG_FUNCTION_ARGS)
{
	PG_RETURN_BOOL(PG_GETARG_TINYINT(0) == PG_GETARG_INT16(1));
}

Datum
tinyint_i2_ne(PG_FUNCTION_ARGS)
{
	PG_RETURN_BOOL(PG_GETARG_TINYINT(0) != PG_GETARG_INT16(1));
}

Datum
tinyint_i2_lt(PG_FUNCTION_ARGS)
{
	PG_RETURN_BOOL(PG_GETARG_TINYINT(0) < PG_GETARG_INT16(1));
}

Datum
tinyint_i2_le(PG_FUNCTION_ARGS)
{
	PG_RETURN_BOOL(PG_GETARG_TINYINT(0) <= PG_GETARG_INT16(1));
}

Datum
tinyint_i2_gt(PG_FUNCTION_ARGS)
{
	PG_RETURN_BOOL(PG_GETARG_TINYINT(0) > PG_GETARG_INT16(1));
}

Datum
tinyint_i2_ge(PG_FUNCTION_ARGS)
{
	PG_RETURN_BOOL(PG_GETARG_TINYINT(0) >= PG_GETARG_INT16(1));
}

Datum
tinyint_i4_eq(PG_FUNCTION_ARGS)
{
	PG_RETURN_BOOL(PG_GETARG_TINYINT(0) == PG_GETARG_INT32(1));
}

Datum
tinyint_i4_ne(PG_FUNCTION_ARGS)
{
	PG_RETURN_BOOL(PG_GETARG_TINYINT(0) != PG_GETARG_INT32(1));
}

Datum
tinyint_i4_lt(PG_FUNCTION_ARGS)
{
	PG_RETURN_BOOL(PG_GETARG_TINYINT(0) < PG_GETARG_INT32(1));
}

Datum
tinyint_i4_le(PG_FUNCTION_ARGS)
{
	PG_RETURN_BOOL(PG_GETARG_TINYINT(0) <= PG_GETARG_INT32(1));
}

Datum
tinyint_i4_gt(PG_FUNCTION_ARGS)
{
	PG_RETURN_BOOL(PG_GETARG_TINYINT(0) > PG_GETARG_INT32(1));
}

Datum
tinyint_i4_ge(PG_FUNCTION_ARGS)
{
	PG_RETURN_BOOL(PG_GETARG_TINYINT(0) >= PG_GETARG_INT32(1));
}

Datum
tinyint_i8_eq(PG_FUNCTION_ARGS)
{
	PG_RETURN_BOOL(PG_GETARG_TINYINT(0) == PG_GETARG_INT64(1));
}

Datum
tinyint_i8_ne(PG_FUNCTION_ARGS)
{
	PG_RETURN_BOOL(PG_GETARG_TINYINT(0) != PG_GETARG_INT64(1));
}

Datum
tinyint_i8_lt(PG_FUNCTION_ARGS)
{
	PG_RETURN_BOOL(PG_GETARG_TINYINT(0) < PG_GETARG_INT64(1));
}

Datum
tinyint_i8_le(PG_FUNCTION_ARGS)
{
	PG_RETURN_BOOL(PG_GETARG_TINYINT(0) <= PG_GETARG_INT64(1));
}

Datum
tinyint_i8_gt(PG_FUNCTION_ARGS)
{
	PG_RETURN_BOOL(PG_GETARG_TINYINT(0) > PG_GETARG_INT64(1));
}

Datum
tinyint_i8_ge(PG_FUNCTION_ARGS)
{
	PG_RETURN_BOOL(PG_GETARG_TINYINT(0) >= PG_GETARG_INT64(1));
}

Datum
i2_tinyint_eq(PG_FUNCTION_ARGS)
{
	PG_RETURN_BOOL(PG_GETARG_INT16(0) == PG_GETARG_TINYINT(1));
}

Datum
i2_tinyint_ne(PG_FUNCTION_ARGS)
{
	PG_RETURN_BOOL(PG_GETARG_INT16(0) != PG_GETARG_TINYINT(1));
}

Datum
i2_tinyint_lt(PG_FUNCTION_ARGS)
{
	PG_RETURN_BOOL(PG_GETARG_INT16(0) < PG_GETARG_TINYINT(1));
}

Datum
i2_tinyint_le(PG_FUNCTION_ARGS)
{
	PG_RETURN_BOOL(PG_GETARG_INT16(0) <= PG_GETARG_TINYINT(1));
}

Datum
i2_tinyint_gt(PG_FUNCTION_ARGS)
{
	PG_RETURN_BOOL(PG_GETARG_INT16(0) > PG_GETARG_TINYINT(1));
}

Datum
i2_tinyint_ge(PG_FUNCTION_ARGS)
{
	PG_RETURN_BOOL(PG_GETARG_INT16(0) >= PG_GETARG_TINYINT(1));
}

Datum
i4_tinyint_eq(PG_FUNCTION_ARGS)
{
	PG_RETURN_BOOL(PG_GETARG_INT32(0) == PG_GETARG_TINYINT(1));
}

Datum
i4_tinyint_ne(PG_FUNCTION_ARGS)
{
	PG_RETURN_BOOL(PG_GETARG_INT32(0) != PG_GETARG_TINYINT(1));
}

Datum
i4_tinyint_lt(PG_FUNCTION_ARGS)
{
	PG_RETURN_BOOL(PG_GETARG_INT32(0) < PG_GETARG_TINYINT(1));
}

Datum
i4_tinyint_le(PG_FUNCTION_ARGS)
{
	PG_RETURN_BOOL(PG_GETARG_INT32(0) <= PG_GETARG_TINYINT(1));
}

Datum
i4_tinyint_gt(PG_FUNCTION_ARGS)
{
	PG_RETURN_BOOL(PG_GETARG_INT32(0) > PG_GETARG_TINYINT(1));
}

Datum
i4_tinyint_ge(PG_FUNCTION_ARGS)
{
	PG_RETURN_BOOL(PG_GETARG_INT32(0) >= PG_GETARG_TINYINT(1));
}

Datum
i8_tinyint_eq(PG_FUNCTION_ARGS)
{
	PG_RETURN_BOOL(PG_GETARG_INT64(0) == PG_GETARG_TINYINT(1));
}

Datum
i8_tinyint_ne(PG_FUNCTION_ARGS)
{
	PG_RETURN_BOOL(PG_GETARG_INT64(0) != PG_GETARG_TINYINT(1));
}

Datum
i8_tinyint_lt(PG_FUNCTION_ARGS)
{
	PG_RETURN_BOOL(PG_GETARG_INT64(0) < PG_GETARG_TINYINT(1));
}

Datum
i8_tinyint_le(PG_FUNCTION_ARGS)
{
	PG_RETURN_BOOL(PG_GETARG_INT64(0) <= PG_GETARG_TINYINT(1));
}

Datum
i8_tinyint_gt(PG_FUNCTION_ARGS)
{
	PG_RETURN_BOOL(PG_GETARG_INT64(0) > PG_GETARG_TINYINT(1));
}

Datum
i8_tinyint_ge(PG_FUNCTION_ARGS)
{
	PG_RETURN_BOOL(PG_GETARG_INT64(0) >= PG_GETARG_TINYINT(1));
}

/*
 *		pl		- returns arg1 + arg2
 *		mi		- returns arg1 - arg2
 *		mul		- returns arg1 * arg2
 *		div		- returns arg1 / arg2
 */

Datum
tinyint_um(PG_FUNCTION_ARGS)
{
	tinyint		arg = PG_GETARG_TINYINT(0);
	tinyint		result;

	result = -arg;

	if (arg != 0 && SAMESIGN(result, arg))
		ereport(ERROR,
				(errcode(ERRCODE_NUMERIC_VALUE_OUT_OF_RANGE),
				 errmsg("tinyint out of range")));
	PG_RETURN_TINYINT(result);
}

Datum
tinyint_up(PG_FUNCTION_ARGS)
{
	PG_RETURN_TINYINT(PG_GETARG_TINYINT(0));
}

Datum
tinyint_pl(PG_FUNCTION_ARGS)
{
	tinyint		arg1 = PG_GETARG_TINYINT(0);
	tinyint		arg2 = PG_GETARG_TINYINT(1);
	tinyint		result;

	result = arg1 + arg2;

	/*
	 * Overflow check.	If the inputs are of different signs then their sum
	 * cannot overflow.  If the inputs are of the same sign, their sum had
	 * better be that sign too.
	 */
	if (SAMESIGN(arg1, arg2) && !SAMESIGN(result, arg1))
		ereport(ERROR,
				(errcode(ERRCODE_NUMERIC_VALUE_OUT_OF_RANGE),
				 errmsg("tinyint out of range")));
	PG_RETURN_TINYINT(result);
}

Datum
tinyint_mi(PG_FUNCTION_ARGS)
{
	tinyint		arg1 = PG_GETARG_TINYINT(0);
	tinyint		arg2 = PG_GETARG_TINYINT(1);
	tinyint		result;

	result = arg1 - arg2;

	/*
	 * Overflow check.	If the inputs are of different signs then their sum
	 * cannot overflow.  If the inputs are of the same sign, their sum had
	 * better be that sign too.
	 */
	if (!SAMESIGN(arg1, arg2) && !SAMESIGN(result, arg1))
		ereport(ERROR,
				(errcode(ERRCODE_NUMERIC_VALUE_OUT_OF_RANGE),
				 errmsg("tinyint out of range")));
	PG_RETURN_TINYINT(result);
}

Datum
tinyint_mul(PG_FUNCTION_ARGS)
{
	tinyint		arg1 = PG_GETARG_TINYINT(0);
	tinyint		arg2 = PG_GETARG_TINYINT(1);
	tinyint		result;

	result = arg1 * arg2;

	/*
	 * Overflow check.	We basically check to see if result / arg2 gives arg1
	 * again.  There are two cases where this fails: arg2 = 0 (which cannot
	 * overflow) and arg1 = INT_MIN, arg2 = -1 (where the division itself will
	 * overflow and thus incorrectly match).
	 *
	 * Since the division is likely much more expensive than the actual
	 * multiplication, we'd like to skip it where possible.  The best bang for
	 * the buck seems to be to check whether both inputs are in the 4bit
	 * range; if so, no overflow is possible.
	 */
	if (!(arg1 >= (tinyint) -14 && arg1 <= (tinyint) 15 &&
		  arg2 >= (tinyint) -14 && arg2 <= (tinyint) 15) &&
		arg2 != 0 &&
		(result / arg2 != arg1 || (arg2 == -1 && arg1 < 0 && result < 0)))
		ereport(ERROR,
				(errcode(ERRCODE_NUMERIC_VALUE_OUT_OF_RANGE),
				 errmsg("tinyint out of range")));
	PG_RETURN_TINYINT(result);
}

Datum
tinyint_div(PG_FUNCTION_ARGS)
{
	tinyint		arg1 = PG_GETARG_TINYINT(0);
	tinyint		arg2 = PG_GETARG_TINYINT(1);
	tinyint		result;

	if (arg2 == 0)
		ereport(ERROR,
				(errcode(ERRCODE_DIVISION_BY_ZERO),
				 errmsg("division by zero")));

	result = arg1 / arg2;

	/*
	 * Overflow check.	The only possible overflow case is for arg1 = INT_MIN,
	 * arg2 = -1, where the correct result is -INT_MIN, which can't be
	 * represented on a two's-complement machine.  Most machines produce
	 * INT_MIN but it seems some produce zero.
	 */
	if (arg2 == -1 && arg1 < 0 && result <= 0)
		ereport(ERROR,
				(errcode(ERRCODE_NUMERIC_VALUE_OUT_OF_RANGE),
				 errmsg("tinyint out of range")));
	PG_RETURN_INT32(result);
}

Datum
tinyint_inc(PG_FUNCTION_ARGS)
{
	tinyint		arg = PG_GETARG_TINYINT(0);
	tinyint		result;

	result = arg + 1;
	/* Overflow check */
	if (arg > 0 && result < 0)
		ereport(ERROR,
				(errcode(ERRCODE_NUMERIC_VALUE_OUT_OF_RANGE),
				 errmsg("tinyint out of range")));

	PG_RETURN_TINYINT(result);
}

Datum
tinyint_i2_pl(PG_FUNCTION_ARGS)
{
	tinyint		arg1 = PG_GETARG_TINYINT(0);
	int16		arg2 = PG_GETARG_INT16(1);
	int16		result;

	result = arg1 + arg2;

	/*
	 * Overflow check.	If the inputs are of different signs then their sum
	 * cannot overflow.  If the inputs are of the same sign, their sum had
	 * better be that sign too.
	 */
	if (SAMESIGN(arg1, arg2) && !SAMESIGN(result, arg1))
		ereport(ERROR,
				(errcode(ERRCODE_NUMERIC_VALUE_OUT_OF_RANGE),
				 errmsg("smallint out of range")));
	PG_RETURN_INT16(result);
}

Datum
tinyint_i2_mi(PG_FUNCTION_ARGS)
{
	tinyint		arg1 = PG_GETARG_TINYINT(0);
	int16		arg2 = PG_GETARG_INT16(1);
	int16		result;

	result = arg1 - arg2;

	/*
	 * Overflow check.	If the inputs are of the same sign then their
	 * difference cannot overflow.	If they are of different signs then the
	 * result should be of the same sign as the first input.
	 */
	if (!SAMESIGN(arg1, arg2) && !SAMESIGN(result, arg1))
		ereport(ERROR,
				(errcode(ERRCODE_NUMERIC_VALUE_OUT_OF_RANGE),
				 errmsg("smallint out of range")));
	PG_RETURN_INT16(result);
}

Datum
tinyint_i2_mul(PG_FUNCTION_ARGS)
{
	tinyint		arg1 = PG_GETARG_TINYINT(0);
	int16		arg2 = PG_GETARG_INT16(1);
	int16		result;

	result = arg1 * arg2;

	/*
	 * Overflow check.	We basically check to see if result / arg2 gives arg1
	 * again.  There is one case where this fails: arg2 = 0 (which cannot
	 * overflow).
	 *
	 * Since the division is likely much more expensive than the actual
	 * multiplication, we'd like to skip it where possible.  The best bang for
	 * the buck seems to be to check whether both inputs are in the tinyint
	 * range; if so, no overflow is possible.
	 */
	if (!(arg2 >= (int16) SCHAR_MIN && arg2 <= (int16) SCHAR_MAX) &&
		result / arg2 != arg1)
		ereport(ERROR,
				(errcode(ERRCODE_NUMERIC_VALUE_OUT_OF_RANGE),
				 errmsg("smallint out of range")));
	PG_RETURN_INT16(result);
}

Datum
tinyint_i2_div(PG_FUNCTION_ARGS)
{
	tinyint		arg1 = PG_GETARG_TINYINT(0);
	int16		arg2 = PG_GETARG_INT16(1);

	if (arg2 == 0)
		ereport(ERROR,
				(errcode(ERRCODE_DIVISION_BY_ZERO),
				 errmsg("division by zero")));
	/* No overflow is possible */
	PG_RETURN_INT16((int16) arg1 / arg2);
}

Datum
tinyint_i4_pl(PG_FUNCTION_ARGS)
{
	tinyint		arg1 = PG_GETARG_TINYINT(0);
	int32		arg2 = PG_GETARG_INT32(1);
	int32		result;

	result = arg1 + arg2;

	/*
	 * Overflow check.	If the inputs are of different signs then their sum
	 * cannot overflow.  If the inputs are of the same sign, their sum had
	 * better be that sign too.
	 */
	if (SAMESIGN(arg1, arg2) && !SAMESIGN(result, arg1))
		ereport(ERROR,
				(errcode(ERRCODE_NUMERIC_VALUE_OUT_OF_RANGE),
				 errmsg("integer out of range")));
	PG_RETURN_INT32(result);
}

Datum
tinyint_i4_mi(PG_FUNCTION_ARGS)
{
	tinyint		arg1 = PG_GETARG_TINYINT(0);
	int32		arg2 = PG_GETARG_INT32(1);
	int32		result;

	result = arg1 - arg2;

	/*
	 * Overflow check.	If the inputs are of the same sign then their
	 * difference cannot overflow.	If they are of different signs then the
	 * result should be of the same sign as the first input.
	 */
	if (!SAMESIGN(arg1, arg2) && !SAMESIGN(result, arg1))
		ereport(ERROR,
				(errcode(ERRCODE_NUMERIC_VALUE_OUT_OF_RANGE),
				 errmsg("integer out of range")));
	PG_RETURN_INT32(result);
}

Datum
tinyint_i4_mul(PG_FUNCTION_ARGS)
{
	tinyint		arg1 = PG_GETARG_TINYINT(0);
	int32		arg2 = PG_GETARG_INT32(1);
	int32		result;

	result = arg1 * arg2;

	/*
	 * Overflow check.	We basically check to see if result / arg2 gives arg1
	 * again.  There is one case where this fails: arg2 = 0 (which cannot
	 * overflow).
	 *
	 * Since the division is likely much more expensive than the actual
	 * multiplication, we'd like to skip it where possible.  The best bang for
	 * the buck seems to be to check whether both inputs are in the int16
	 * range; if so, no overflow is possible.
	 */
	if (!(arg2 >= (int32) SHRT_MIN && arg2 <= (int32) SHRT_MAX) &&
		result / arg2 != arg1)
		ereport(ERROR,
				(errcode(ERRCODE_NUMERIC_VALUE_OUT_OF_RANGE),
				 errmsg("integer out of range")));
	PG_RETURN_INT32(result);
}

Datum
tinyint_i4_div(PG_FUNCTION_ARGS)
{
	tinyint		arg1 = PG_GETARG_TINYINT(0);
	int32		arg2 = PG_GETARG_INT32(1);

	if (arg2 == 0)
		ereport(ERROR,
				(errcode(ERRCODE_DIVISION_BY_ZERO),
				 errmsg("division by zero")));
	/* No overflow is possible */
	PG_RETURN_INT32((int32) arg1 / arg2);
}

Datum
tinyint_i8_pl(PG_FUNCTION_ARGS)
{
	tinyint		arg1 = PG_GETARG_TINYINT(0);
	int64		arg2 = PG_GETARG_INT64(1);
	int64		result;

	result = arg1 + arg2;

	/*
	 * Overflow check.	If the inputs are of different signs then their sum
	 * cannot overflow.  If the inputs are of the same sign, their sum had
	 * better be that sign too.
	 */
	if (SAMESIGN(arg1, arg2) && !SAMESIGN(result, arg1))
		ereport(ERROR,
				(errcode(ERRCODE_NUMERIC_VALUE_OUT_OF_RANGE),
				 errmsg("bigint out of range")));
	PG_RETURN_INT64(result);
}

Datum
tinyint_i8_mi(PG_FUNCTION_ARGS)
{
	tinyint		arg1 = PG_GETARG_TINYINT(0);
	int64		arg2 = PG_GETARG_INT64(1);
	int64		result;

	result = arg1 - arg2;

	/*
	 * Overflow check.	If the inputs are of the same sign then their
	 * difference cannot overflow.	If they are of different signs then the
	 * result should be of the same sign as the first input.
	 */
	if (!SAMESIGN(arg1, arg2) && !SAMESIGN(result, arg1))
		ereport(ERROR,
				(errcode(ERRCODE_NUMERIC_VALUE_OUT_OF_RANGE),
				 errmsg("bigint out of range")));
	PG_RETURN_INT64(result);
}

Datum
tinyint_i8_mul(PG_FUNCTION_ARGS)
{
	tinyint		arg1 = PG_GETARG_TINYINT(0);
	int64		arg2 = PG_GETARG_INT64(1);
	int64		result;

	result = arg1 * arg2;

	/*
	 * Overflow check.	We basically check to see if result / arg2 gives arg1
	 * again.  There is one case where this fails: arg2 = 0 (which cannot
	 * overflow).
	 *
	 * Since the division is likely much more expensive than the actual
	 * multiplication, we'd like to skip it where possible.  The best bang for
	 * the buck seems to be to check whether both inputs are in the tinyint
	 * range; if so, no overflow is possible.
	 */
	if (arg2 != (int64) ((int32) arg2) &&
		result / arg2 != arg1)
		ereport(ERROR,
				(errcode(ERRCODE_NUMERIC_VALUE_OUT_OF_RANGE),
				 errmsg("bigint out of range")));
	PG_RETURN_INT64(result);
}

Datum
tinyint_i8_div(PG_FUNCTION_ARGS)
{
	tinyint		arg1 = PG_GETARG_TINYINT(0);
	int64		arg2 = PG_GETARG_INT64(1);

	if (arg2 == 0)
		ereport(ERROR,
				(errcode(ERRCODE_DIVISION_BY_ZERO),
				 errmsg("division by zero")));
	/* No overflow is possible */
	PG_RETURN_INT64((int64) arg1 / arg2);
}

Datum
i2_tinyint_pl(PG_FUNCTION_ARGS)
{
	int16		arg1 = PG_GETARG_INT16(0);
	tinyint		arg2 = PG_GETARG_TINYINT(1);
	int16		result;

	result = arg1 + arg2;

	/*
	 * Overflow check.	If the inputs are of different signs then their sum
	 * cannot overflow.  If the inputs are of the same sign, their sum had
	 * better be that sign too.
	 */
	if (SAMESIGN(arg1, arg2) && !SAMESIGN(result, arg1))
		ereport(ERROR,
				(errcode(ERRCODE_NUMERIC_VALUE_OUT_OF_RANGE),
				 errmsg("smallint out of range")));
	PG_RETURN_INT16(result);
}

Datum
i2_tinyint_mi(PG_FUNCTION_ARGS)
{
	int16		arg1 = PG_GETARG_INT16(0);
	tinyint		arg2 = PG_GETARG_TINYINT(1);
	int16		result;

	result = arg1 - arg2;

	/*
	 * Overflow check.	If the inputs are of the same sign then their
	 * difference cannot overflow.	If they are of different signs then the
	 * result should be of the same sign as the first input.
	 */
	if (!SAMESIGN(arg1, arg2) && !SAMESIGN(result, arg1))
		ereport(ERROR,
				(errcode(ERRCODE_NUMERIC_VALUE_OUT_OF_RANGE),
				 errmsg("smallint out of range")));
	PG_RETURN_INT16(result);
}

Datum
i2_tinyint_mul(PG_FUNCTION_ARGS)
{
	int16		arg1 = PG_GETARG_INT16(0);
	tinyint		arg2 = PG_GETARG_TINYINT(1);
	int16		result;

	result = arg1 * arg2;

	/*
	 * Overflow check.	We basically check to see if result / arg2 gives arg1
	 * again.  There is one case where this fails: arg2 = 0 (which cannot
	 * overflow).
	 *
	 * Since the division is likely much more expensive than the actual
	 * multiplication, we'd like to skip it where possible.  The best bang for
	 * the buck seems to be to check whether both inputs are in the tinyint
	 * range; if so, no overflow is possible.
	 */
	if (!(arg1 >= (int16) SCHAR_MIN && arg1 <= (int16) SCHAR_MAX) &&
		result / arg2 != arg1)
		ereport(ERROR,
				(errcode(ERRCODE_NUMERIC_VALUE_OUT_OF_RANGE),
				 errmsg("smallint out of range")));
	PG_RETURN_INT16(result);
}

Datum
i2_tinyint_div(PG_FUNCTION_ARGS)
{
	int16		arg1 = PG_GETARG_INT16(0);
	tinyint		arg2 = PG_GETARG_TINYINT(1);
	int16		result;

	if (arg2 == 0)
		ereport(ERROR,
				(errcode(ERRCODE_DIVISION_BY_ZERO),
				 errmsg("division by zero")));

	result = arg1 / arg2;

	/*
	 * Overflow check.	The only possible overflow case is for arg1 = SHRT_MIN,
	 * arg2 = -1, where the correct result is -INT_MIN, which can't be
	 * represented on a two's-complement machine.  Most machines produce
	 * INT_MIN but it seems some produce zero.
	 */
	if (arg2 == -1 && arg1 < 0 && result <= 0)
		ereport(ERROR,
				(errcode(ERRCODE_NUMERIC_VALUE_OUT_OF_RANGE),
				 errmsg("integer out of range")));
	PG_RETURN_INT16(result);
}

Datum
i4_tinyint_pl(PG_FUNCTION_ARGS)
{
	int32		arg1 = PG_GETARG_INT32(0);
	tinyint		arg2 = PG_GETARG_TINYINT(1);
	int32		result;

	result = arg1 + arg2;

	/*
	 * Overflow check.	If the inputs are of different signs then their sum
	 * cannot overflow.  If the inputs are of the same sign, their sum had
	 * better be that sign too.
	 */
	if (SAMESIGN(arg1, arg2) && !SAMESIGN(result, arg1))
		ereport(ERROR,
				(errcode(ERRCODE_NUMERIC_VALUE_OUT_OF_RANGE),
				 errmsg("integer out of range")));
	PG_RETURN_INT32(result);
}

Datum
i4_tinyint_mi(PG_FUNCTION_ARGS)
{
	int32		arg1 = PG_GETARG_INT32(0);
	tinyint		arg2 = PG_GETARG_TINYINT(1);
	int32		result;

	result = arg1 - arg2;

	/*
	 * Overflow check.	If the inputs are of the same sign then their
	 * difference cannot overflow.	If they are of different signs then the
	 * result should be of the same sign as the first input.
	 */
	if (!SAMESIGN(arg1, arg2) && !SAMESIGN(result, arg1))
		ereport(ERROR,
				(errcode(ERRCODE_NUMERIC_VALUE_OUT_OF_RANGE),
				 errmsg("integer out of range")));
	PG_RETURN_INT32(result);
}

Datum
i4_tinyint_mul(PG_FUNCTION_ARGS)
{
	int32		arg1 = PG_GETARG_INT32(0);
	tinyint		arg2 = PG_GETARG_TINYINT(1);
	int32		result;

	result = arg1 * arg2;

	/*
	 * Overflow check.	We basically check to see if result / arg2 gives arg1
	 * again.  There is one case where this fails: arg2 = 0 (which cannot
	 * overflow).
	 *
	 * Since the division is likely much more expensive than the actual
	 * multiplication, we'd like to skip it where possible.  The best bang for
	 * the buck seems to be to check whether both inputs are in the int16
	 * range; if so, no overflow is possible.
	 */
	if (!(arg1 >= (int32) SHRT_MIN && arg1 <= (int32) SHRT_MAX) &&
		result / arg2 != arg1)
		ereport(ERROR,
				(errcode(ERRCODE_NUMERIC_VALUE_OUT_OF_RANGE),
				 errmsg("integer out of range")));
	PG_RETURN_INT32(result);
}

Datum
i4_tinyint_div(PG_FUNCTION_ARGS)
{
	int32		arg1 = PG_GETARG_INT32(0);
	tinyint		arg2 = PG_GETARG_TINYINT(1);
	int32		result;

	if (arg2 == 0)
		ereport(ERROR,
				(errcode(ERRCODE_DIVISION_BY_ZERO),
				 errmsg("division by zero")));

	result = arg1 / arg2;

	/*
	 * Overflow check.	The only possible overflow case is for arg1 = INT_MIN,
	 * arg2 = -1, where the correct result is -INT_MIN, which can't be
	 * represented on a two's-complement machine.  Most machines produce
	 * INT_MIN but it seems some produce zero.
	 */
	if (arg2 == -1 && arg1 < 0 && result <= 0)
		ereport(ERROR,
				(errcode(ERRCODE_NUMERIC_VALUE_OUT_OF_RANGE),
				 errmsg("integer out of range")));
	PG_RETURN_INT32(result);
}

Datum
i8_tinyint_pl(PG_FUNCTION_ARGS)
{
	int64		arg1 = PG_GETARG_INT64(0);
	tinyint		arg2 = PG_GETARG_TINYINT(1);
	int64		result;

	result = arg1 + arg2;

	/*
	 * Overflow check.	If the inputs are of different signs then their sum
	 * cannot overflow.  If the inputs are of the same sign, their sum had
	 * better be that sign too.
	 */
	if (SAMESIGN(arg1, arg2) && !SAMESIGN(result, arg1))
		ereport(ERROR,
				(errcode(ERRCODE_NUMERIC_VALUE_OUT_OF_RANGE),
				 errmsg("bigint out of range")));
	PG_RETURN_INT64(result);
}

Datum
i8_tinyint_mi(PG_FUNCTION_ARGS)
{
	int64		arg1 = PG_GETARG_INT64(0);
	tinyint		arg2 = PG_GETARG_TINYINT(1);
	int64		result;

	result = arg1 - arg2;

	/*
	 * Overflow check.	If the inputs are of the same sign then their
	 * difference cannot overflow.	If they are of different signs then the
	 * result should be of the same sign as the first input.
	 */
	if (!SAMESIGN(arg1, arg2) && !SAMESIGN(result, arg1))
		ereport(ERROR,
				(errcode(ERRCODE_NUMERIC_VALUE_OUT_OF_RANGE),
				 errmsg("bigint out of range")));
	PG_RETURN_INT64(result);
}

Datum
i8_tinyint_mul(PG_FUNCTION_ARGS)
{
	int64		arg1 = PG_GETARG_INT64(0);
	tinyint		arg2 = PG_GETARG_TINYINT(1);
	int64		result;

	result = arg1 * arg2;

	/*
	 * Overflow check.	We basically check to see if result / arg2 gives arg1
	 * again.  There is one case where this fails: arg2 = 0 (which cannot
	 * overflow).
	 *
	 * Since the division is likely much more expensive than the actual
	 * multiplication, we'd like to skip it where possible.  The best bang for
	 * the buck seems to be to check whether both inputs are in the int32
	 * range; if so, no overflow is possible.
	 */
	if (!(arg1 >= (int64) INT_MIN && arg1 <= (int64) INT_MAX) &&
		result / arg2 != arg1)
		ereport(ERROR,
				(errcode(ERRCODE_NUMERIC_VALUE_OUT_OF_RANGE),
				 errmsg("bigint out of range")));
	PG_RETURN_INT64(result);
}

Datum
i8_tinyint_div(PG_FUNCTION_ARGS)
{
	int64		arg1 = PG_GETARG_INT64(0);
	tinyint		arg2 = PG_GETARG_TINYINT(1);
	int64		result;

	if (arg2 == 0)
		ereport(ERROR,
				(errcode(ERRCODE_DIVISION_BY_ZERO),
				 errmsg("division by zero")));

	result = arg1 / arg2;

	/* no overflow possible? */
	PG_RETURN_INT64(result);
}

Datum
tinyint_mod(PG_FUNCTION_ARGS)
{
	tinyint		arg1 = PG_GETARG_TINYINT(0);
	tinyint		arg2 = PG_GETARG_TINYINT(1);

	if (arg2 == 0)
		ereport(ERROR,
				(errcode(ERRCODE_DIVISION_BY_ZERO),
				 errmsg("division by zero")));
	/* No overflow is possible */
	PG_RETURN_TINYINT(arg1 % arg2);
}

Datum
tinyint_abs(PG_FUNCTION_ARGS)
{
	tinyint		arg1 = PG_GETARG_TINYINT(0);
	tinyint		result;

	result = (arg1 < 0) ? -arg1 : arg1;
	/* overflow check (needed for SCHAR_MIN) */
	if (result < 0)
		ereport(ERROR,
				(errcode(ERRCODE_NUMERIC_VALUE_OUT_OF_RANGE),
				 errmsg("tinyint out of range")));
	PG_RETURN_TINYINT(result);
}

Datum
tinyint_larger(PG_FUNCTION_ARGS)
{
	tinyint		arg1 = PG_GETARG_TINYINT(0);
	tinyint		arg2 = PG_GETARG_TINYINT(1);

	PG_RETURN_TINYINT((arg1 > arg2) ? arg1 : arg2);
}

Datum
tinyint_smaller(PG_FUNCTION_ARGS)
{
	tinyint		arg1 = PG_GETARG_TINYINT(0);
	tinyint		arg2 = PG_GETARG_TINYINT(1);

	PG_RETURN_TINYINT((arg1 < arg2) ? arg1 : arg2);
}

Datum
tinyint_and(PG_FUNCTION_ARGS)
{
	tinyint		arg1 = PG_GETARG_TINYINT(0);
	tinyint		arg2 = PG_GETARG_TINYINT(1);

	PG_RETURN_TINYINT(arg1 & arg2);
}

Datum
tinyint_or(PG_FUNCTION_ARGS)
{
	tinyint		arg1 = PG_GETARG_TINYINT(0);
	tinyint		arg2 = PG_GETARG_TINYINT(1);

	PG_RETURN_TINYINT(arg1 | arg2);
}

Datum
tinyint_xor(PG_FUNCTION_ARGS)
{
	tinyint		arg1 = PG_GETARG_TINYINT(0);
	tinyint		arg2 = PG_GETARG_TINYINT(1);

	PG_RETURN_TINYINT(arg1 ^ arg2);
}

Datum
tinyint_shl(PG_FUNCTION_ARGS)
{
	tinyint		arg1 = PG_GETARG_TINYINT(0);
	tinyint		arg2 = PG_GETARG_TINYINT(1);

	PG_RETURN_TINYINT(arg1 << arg2);
}

Datum
tinyint_shr(PG_FUNCTION_ARGS)
{
	tinyint		arg1 = PG_GETARG_TINYINT(0);
	tinyint		arg2 = PG_GETARG_TINYINT(1);

	PG_RETURN_TINYINT(arg1 >> arg2);
}

Datum
tinyint_not(PG_FUNCTION_ARGS)
{
	tinyint		arg1 = PG_GETARG_TINYINT(0);

	PG_RETURN_TINYINT(~arg1);
}

/*
 *		========================
 *		BTREE STRATEGY OPERATORS
 *		========================
 */

Datum
bt_tinyint_cmp(PG_FUNCTION_ARGS)
{
	tinyint		a = PG_GETARG_TINYINT(0);
	tinyint		b = PG_GETARG_TINYINT(1);

	PG_RETURN_INT32((int32) a - (int32) b);
}

Datum
bt_tinyint_i2_cmp(PG_FUNCTION_ARGS)
{
	tinyint		a = PG_GETARG_TINYINT(0);
	int16		b = PG_GETARG_INT16(1);

	PG_RETURN_INT32((int32) a - (int32) b);
}

Datum
bt_tinyint_i4_cmp(PG_FUNCTION_ARGS)
{
	tinyint		a = PG_GETARG_TINYINT(0);
	int32		b = PG_GETARG_INT32(1);

	PG_RETURN_INT32((int32) a - (int32) b);
}

Datum
bt_tinyint_i8_cmp(PG_FUNCTION_ARGS)
{
	tinyint		a = PG_GETARG_TINYINT(0);
	int64		b = PG_GETARG_INT64(1);

	if (a > b)
		PG_RETURN_INT32(1);
	else if (a == b)
		PG_RETURN_INT32(0);
	else
		PG_RETURN_INT32(-1);
}

Datum
bt_i2_tinyint_cmp(PG_FUNCTION_ARGS)
{
	int16		a = PG_GETARG_INT16(0);
	tinyint		b = PG_GETARG_TINYINT(1);

	PG_RETURN_INT32((int32) a - (int32) b);
}

Datum
bt_i4_tinyint_cmp(PG_FUNCTION_ARGS)
{
	int32		a = PG_GETARG_INT32(0);
	tinyint		b = PG_GETARG_TINYINT(1);

	PG_RETURN_INT32((int32) a - (int32) b);
}

Datum
bt_i8_tinyint_cmp(PG_FUNCTION_ARGS)
{
	int64		a = PG_GETARG_INT64(0);
	tinyint		b = PG_GETARG_TINYINT(1);

	if (a > b)
		PG_RETURN_INT32(1);
	else if (a == b)
		PG_RETURN_INT32(0);
	else
		PG_RETURN_INT32(-1);
}

Datum
hash_tinyint(PG_FUNCTION_ARGS)
{
	return hash_uint32((int32) PG_GETARG_TINYINT(0));
}

Datum
tinyint_sum(PG_FUNCTION_ARGS)
{
	int64		newval;

	if (PG_ARGISNULL(0))
	{
		/* No non-null input seen so far... */
		if (PG_ARGISNULL(1))
			PG_RETURN_NULL();	/* still no non-null */
		/* This is the first non-null input. */
		newval = (int64) PG_GETARG_TINYINT(1);
		PG_RETURN_INT64(newval);
	}

	/*
	 * If we're invoked by nodeAgg, we can cheat and modify our first
	 * parameter in-place to avoid palloc overhead. If not, we need to return
	 * the new value of the transition variable.
	 * (If int8 is pass-by-value, then of course this is useless as well
	 * as incorrect, so just ifdef it out.)
	 */
#ifndef USE_FLOAT8_BYVAL		/* controls int8 too */
	if (fcinfo->context &&
#if PG_VERSION_NUM >= 80400
		(IsA(fcinfo->context, AggState) ||
		 IsA(fcinfo->context, WindowAggState)))
#else
		(IsA(fcinfo->context, AggState)))
#endif
	{
		int64	   *oldsum = (int64 *) PG_GETARG_POINTER(0);

		/* Leave the running sum unchanged in the new input is null */
		if (!PG_ARGISNULL(1))
			*oldsum = *oldsum + (int64) PG_GETARG_TINYINT(1);

		PG_RETURN_POINTER(oldsum);
	}
	else
#endif
	{
		int64		oldsum = PG_GETARG_INT64(0);

		/* Leave sum unchanged if new input is null. */
		if (PG_ARGISNULL(1))
			PG_RETURN_INT64(oldsum);

		/* OK to do the addition. */
		newval = oldsum + (int64) PG_GETARG_TINYINT(1);

		PG_RETURN_INT64(newval);
	}
}

/*
 * Routines for avg(int2) and avg(int4).  The transition datatype
 * is a two-element int8 array, holding count and sum.
 */

typedef struct Int8TransTypeData
{
#ifndef INT64_IS_BUSTED
	int64		count;
	int64		sum;
#else
	/* "int64" isn't really 64 bits, so fake up properly-aligned fields */
	int32		count;
	int32		pad1;
	int32		sum;
	int32		pad2;
#endif
} Int8TransTypeData;

Datum
tinyint_avg_accum(PG_FUNCTION_ARGS)
{
	ArrayType  *transarray;
	tinyint		newval = PG_GETARG_TINYINT(1);
	Int8TransTypeData *transdata;

	/*
	 * If we're invoked by nodeAgg, we can cheat and modify our first
	 * parameter in-place to reduce palloc overhead. Otherwise we need to make
	 * a copy of it before scribbling on it.
	 */
	if (fcinfo->context &&
#if PG_VERSION_NUM >= 80400
		(IsA(fcinfo->context, AggState) ||
		 IsA(fcinfo->context, WindowAggState)))
#else
		(IsA(fcinfo->context, AggState)))
#endif
		transarray = PG_GETARG_ARRAYTYPE_P(0);
	else
		transarray = PG_GETARG_ARRAYTYPE_P_COPY(0);

	if (ARR_HASNULL(transarray) ||
		ARR_SIZE(transarray) != ARR_OVERHEAD_NONULLS(1) + sizeof(Int8TransTypeData))
		elog(ERROR, "expected 2-element int8 array");

	transdata = (Int8TransTypeData *) ARR_DATA_PTR(transarray);
	transdata->count++;
	transdata->sum += newval;

	PG_RETURN_ARRAYTYPE_P(transarray);
}

