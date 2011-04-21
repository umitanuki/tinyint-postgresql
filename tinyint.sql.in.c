#include "pg_config.h"

CREATE FUNCTION tinyint_in(cstring) RETURNS tinyint AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE FUNCTION tinyint_out(tinyint) RETURNS cstring AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE FUNCTION tinyint_recv(internal) RETURNS tinyint AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE FUNCTION tinyint_send(tinyint) RETURNS bytea AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;

CREATE TYPE tinyint (
	INPUT = tinyint_in,
	OUTPUT = tinyint_out,
	RECEIVE = tinyint_recv,
	SEND = tinyint_send,
	INTERNALLENGTH = 1,
	PASSEDBYVALUE,
	ALIGNMENT = char,
	STORAGE = plain
);

CREATE FUNCTION tinyint_to_i2(tinyint) RETURNS smallint AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE CAST (tinyint AS smallint)
WITH FUNCTION tinyint_to_i2(tinyint) AS IMPLICIT;

CREATE FUNCTION i2_to_tinyint(smallint) RETURNS tinyint AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE CAST (smallint AS tinyint)
WITH FUNCTION i2_to_tinyint(smallint) AS ASSIGNMENT;

CREATE FUNCTION tinyint_to_i4(tinyint) RETURNS integer AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE CAST (tinyint AS integer)
WITH FUNCTION tinyint_to_i4(tinyint) AS IMPLICIT;

CREATE FUNCTION i4_to_tinyint(integer) RETURNS tinyint AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE CAST (integer AS tinyint)
WITH FUNCTION i4_to_tinyint(integer) AS ASSIGNMENT;

CREATE FUNCTION tinyint_to_i8(tinyint) RETURNS bigint AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE CAST (tinyint AS bigint)
WITH FUNCTION tinyint_to_i8(tinyint) AS IMPLICIT;

CREATE FUNCTION i8_to_tinyint(bigint) RETURNS tinyint AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE CAST (bigint AS tinyint)
WITH FUNCTION i8_to_tinyint(bigint) AS ASSIGNMENT;

CREATE FUNCTION tinyint_to_bool(tinyint) RETURNS bool AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE CAST (tinyint AS bool)
WITH FUNCTION tinyint_to_bool(tinyint) AS ASSIGNMENT;

CREATE FUNCTION bool_to_tinyint(bool) RETURNS tinyint AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE CAST (bool AS tinyint)
WITH FUNCTION bool_to_tinyint(bool) AS ASSIGNMENT;

CREATE FUNCTION tinyint_lt(tinyint, tinyint) RETURNS bool AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR < (
	LEFTARG = tinyint,
	RIGHTARG = tinyint,
	PROCEDURE = tinyint_lt,
	COMMUTATOR = >,
	NEGATOR = >=,
	RESTRICT = scalarltsel,
	JOIN = scalarltjoinsel
);

CREATE FUNCTION tinyint_le(tinyint, tinyint) RETURNS bool AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR <= (
	LEFTARG = tinyint,
	RIGHTARG = tinyint,
	PROCEDURE = tinyint_le,
	COMMUTATOR = >=,
	NEGATOR = >,
	RESTRICT = scalarltsel,
	JOIN = scalarltjoinsel
);

CREATE FUNCTION tinyint_gt(tinyint, tinyint) RETURNS bool AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR > (
	LEFTARG = tinyint,
	RIGHTARG = tinyint,
	PROCEDURE = tinyint_gt,
	COMMUTATOR = <,
	NEGATOR = <=,
	RESTRICT = scalargtsel,
	JOIN = scalargtjoinsel
);

CREATE FUNCTION tinyint_ge(tinyint, tinyint) RETURNS bool AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR >= (
	LEFTARG = tinyint,
	RIGHTARG = tinyint,
	PROCEDURE = tinyint_ge,
	COMMUTATOR = <=,
	NEGATOR = <,
	RESTRICT = scalargtsel,
	JOIN = scalargtjoinsel
);

CREATE FUNCTION tinyint_eq(tinyint, tinyint) RETURNS bool AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR = (
	LEFTARG = tinyint,
	RIGHTARG = tinyint,
	PROCEDURE = tinyint_eq,
	COMMUTATOR = =,
	NEGATOR = <>,
	RESTRICT = eqsel,
	JOIN = eqjoinsel,
	HASHES,
	MERGES
);

CREATE FUNCTION tinyint_ne(tinyint, tinyint) RETURNS bool AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR <> (
	LEFTARG = tinyint,
	RIGHTARG = tinyint,
	PROCEDURE = tinyint_ne,
	COMMUTATOR = <>,
	NEGATOR = =,
	RESTRICT = neqsel,
	JOIN = neqjoinsel,
	MERGES
);


CREATE FUNCTION tinyint_i2_eq(tinyint, smallint) RETURNS bool AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR = (
	LEFTARG = tinyint,
	RIGHTARG = smallint,
	PROCEDURE = tinyint_i2_eq,
	COMMUTATOR = =,
	NEGATOR = <>,
	RESTRICT = eqsel,
	JOIN = eqjoinsel,
	HASHES,
	MERGES
);

CREATE FUNCTION tinyint_i2_ne(tinyint, smallint) RETURNS bool AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR <> (
	LEFTARG = tinyint,
	RIGHTARG = smallint,
	PROCEDURE = tinyint_i2_ne,
	COMMUTATOR = <>,
	NEGATOR = =,
	RESTRICT = neqsel,
	JOIN = neqjoinsel,
	MERGES
);

CREATE FUNCTION tinyint_i2_lt(tinyint, smallint) RETURNS bool AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR < (
	LEFTARG = tinyint,
	RIGHTARG = smallint,
	PROCEDURE = tinyint_i2_lt,
	COMMUTATOR = >,
	NEGATOR = >=,
	RESTRICT = scalarltsel,
	JOIN = scalarltjoinsel
);

CREATE FUNCTION tinyint_i2_le(tinyint, smallint) RETURNS bool AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR <= (
	LEFTARG = tinyint,
	RIGHTARG = smallint,
	PROCEDURE = tinyint_i2_le,
	COMMUTATOR = >=,
	NEGATOR = >,
	RESTRICT = scalarltsel,
	JOIN = scalarltjoinsel
);

CREATE FUNCTION tinyint_i2_gt(tinyint, smallint) RETURNS bool AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR > (
	LEFTARG = tinyint,
	RIGHTARG = smallint,
	PROCEDURE = tinyint_i2_gt,
	COMMUTATOR = <,
	NEGATOR = <=,
	RESTRICT = scalargtsel,
	JOIN = scalargtjoinsel
);

CREATE FUNCTION tinyint_i2_ge(tinyint, smallint) RETURNS bool AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR >= (
	LEFTARG = tinyint,
	RIGHTARG = smallint,
	PROCEDURE = tinyint_i2_ge,
	COMMUTATOR = <=,
	NEGATOR = <,
	RESTRICT = scalargtsel,
	JOIN = scalargtjoinsel
);


CREATE FUNCTION tinyint_i4_eq(tinyint, integer) RETURNS bool AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR = (
	LEFTARG = tinyint,
	RIGHTARG = integer,
	PROCEDURE = tinyint_i4_eq,
	COMMUTATOR = =,
	NEGATOR = <>,
	RESTRICT = eqsel,
	JOIN = eqjoinsel,
	HASHES,
	MERGES
);

CREATE FUNCTION tinyint_i4_ne(tinyint, integer) RETURNS bool AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR <> (
	LEFTARG = tinyint,
	RIGHTARG = integer,
	PROCEDURE = tinyint_i4_ne,
	COMMUTATOR = <>,
	NEGATOR = =,
	RESTRICT = neqsel,
	JOIN = neqjoinsel,
	MERGES
);

CREATE FUNCTION tinyint_i4_lt(tinyint, integer) RETURNS bool AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR < (
	LEFTARG = tinyint,
	RIGHTARG = integer,
	PROCEDURE = tinyint_i4_lt,
	COMMUTATOR = >,
	NEGATOR = >=,
	RESTRICT = scalarltsel,
	JOIN = scalarltjoinsel
);

CREATE FUNCTION tinyint_i4_le(tinyint, integer) RETURNS bool AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR <= (
	LEFTARG = tinyint,
	RIGHTARG = integer,
	PROCEDURE = tinyint_i4_le,
	COMMUTATOR = >=,
	NEGATOR = >,
	RESTRICT = scalarltsel,
	JOIN = scalarltjoinsel
);

CREATE FUNCTION tinyint_i4_gt(tinyint, integer) RETURNS bool AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR > (
	LEFTARG = tinyint,
	RIGHTARG = integer,
	PROCEDURE = tinyint_i4_gt,
	COMMUTATOR = <,
	NEGATOR = <=,
	RESTRICT = scalargtsel,
	JOIN = scalargtjoinsel
);

CREATE FUNCTION tinyint_i4_ge(tinyint, integer) RETURNS bool AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR >= (
	LEFTARG = tinyint,
	RIGHTARG = integer,
	PROCEDURE = tinyint_i4_ge,
	COMMUTATOR = <,
	NEGATOR = <=,
	RESTRICT = scalargtsel,
	JOIN = scalargtjoinsel
);


CREATE FUNCTION tinyint_i8_eq(tinyint, bigint) RETURNS bool AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR = (
	LEFTARG = tinyint,
	RIGHTARG = bigint,
	PROCEDURE = tinyint_i8_eq,
	COMMUTATOR = =,
	NEGATOR = <>,
	RESTRICT = eqsel,
	JOIN = eqjoinsel,
	HASHES,
	MERGES
);

CREATE FUNCTION tinyint_i8_ne(tinyint, bigint) RETURNS bool AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR <> (
	LEFTARG = tinyint,
	RIGHTARG = bigint,
	PROCEDURE = tinyint_i8_ne,
	COMMUTATOR = <>,
	NEGATOR = =,
	RESTRICT = neqsel,
	JOIN = neqjoinsel,
	MERGES
);

CREATE FUNCTION tinyint_i8_lt(tinyint, bigint) RETURNS bool AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR < (
	LEFTARG = tinyint,
	RIGHTARG = bigint,
	PROCEDURE = tinyint_i8_lt,
	COMMUTATOR = >,
	NEGATOR = >=,
	RESTRICT = scalarltsel,
	JOIN = scalarltjoinsel
);

CREATE FUNCTION tinyint_i8_le(tinyint, bigint) RETURNS bool AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR <= (
	LEFTARG = tinyint,
	RIGHTARG = bigint,
	PROCEDURE = tinyint_i8_le,
	COMMUTATOR = >=,
	NEGATOR = >,
	RESTRICT = scalarltsel,
	JOIN = scalarltjoinsel
);

CREATE FUNCTION tinyint_i8_gt(tinyint, bigint) RETURNS bool AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR > (
	LEFTARG = tinyint,
	RIGHTARG = bigint,
	PROCEDURE = tinyint_i8_gt,
	COMMUTATOR = <,
	NEGATOR = <=,
	RESTRICT = scalargtsel,
	JOIN = scalargtjoinsel
);

CREATE FUNCTION tinyint_i8_ge(tinyint, bigint) RETURNS bool AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR >= (
	LEFTARG = tinyint,
	RIGHTARG = bigint,
	PROCEDURE = tinyint_i8_ge,
	COMMUTATOR = <,
	NEGATOR = <=,
	RESTRICT = scalargtsel,
	JOIN = scalargtjoinsel
);


CREATE FUNCTION i2_tinyint_eq(smallint, tinyint) RETURNS bool AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR = (
	LEFTARG = smallint,
	RIGHTARG = tinyint,
	PROCEDURE = i2_tinyint_eq,
	COMMUTATOR = =,
	NEGATOR = <>,
	RESTRICT = eqsel,
	JOIN = eqjoinsel,
	HASHES,
	MERGES
);

CREATE FUNCTION i2_tinyint_ne(smallint, tinyint) RETURNS bool AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR <> (
	LEFTARG = smallint,
	RIGHTARG = tinyint,
	PROCEDURE = i2_tinyint_ne,
	COMMUTATOR = <>,
	NEGATOR = =,
	RESTRICT = neqsel,
	JOIN = neqjoinsel,
	MERGES
);

CREATE FUNCTION i2_tinyint_lt(smallint, tinyint) RETURNS bool AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR < (
	LEFTARG = smallint,
	RIGHTARG = tinyint,
	PROCEDURE = i2_tinyint_lt,
	COMMUTATOR = >,
	NEGATOR = >=,
	RESTRICT = scalarltsel,
	JOIN = scalarltjoinsel
);

CREATE FUNCTION i2_tinyint_le(smallint, tinyint) RETURNS bool AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR <= (
	LEFTARG = smallint,
	RIGHTARG = tinyint,
	PROCEDURE = i2_tinyint_le,
	COMMUTATOR = >=,
	NEGATOR = >,
	RESTRICT = scalarltsel,
	JOIN = scalarltjoinsel
);

CREATE FUNCTION i2_tinyint_gt(smallint, tinyint) RETURNS bool AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR > (
	LEFTARG = smallint,
	RIGHTARG = tinyint,
	PROCEDURE = i2_tinyint_gt,
	COMMUTATOR = <,
	NEGATOR = <=,
	RESTRICT = scalargtsel,
	JOIN = scalargtjoinsel
);

CREATE FUNCTION i2_tinyint_ge(smallint, tinyint) RETURNS bool AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR >= (
	LEFTARG = smallint,
	RIGHTARG = tinyint,
	PROCEDURE = i2_tinyint_ge,
	COMMUTATOR = <,
	NEGATOR = <=,
	RESTRICT = scalargtsel,
	JOIN = scalargtjoinsel
);


CREATE FUNCTION i4_tinyint_eq(integer, tinyint) RETURNS bool AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR = (
	LEFTARG = integer,
	RIGHTARG = tinyint,
	PROCEDURE = i4_tinyint_eq,
	COMMUTATOR = =,
	NEGATOR = <>,
	RESTRICT = eqsel,
	JOIN = eqjoinsel,
	HASHES,
	MERGES
);

CREATE FUNCTION i4_tinyint_ne(integer, tinyint) RETURNS bool AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR <> (
	LEFTARG = integer,
	RIGHTARG = tinyint,
	PROCEDURE = i4_tinyint_ne,
	COMMUTATOR = <>,
	NEGATOR = =,
	RESTRICT = neqsel,
	JOIN = neqjoinsel,
	MERGES
);

CREATE FUNCTION i4_tinyint_lt(integer, tinyint) RETURNS bool AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR < (
	LEFTARG = integer,
	RIGHTARG = tinyint,
	PROCEDURE = i4_tinyint_lt,
	COMMUTATOR = >,
	NEGATOR = >=,
	RESTRICT = scalarltsel,
	JOIN = scalarltjoinsel
);

CREATE FUNCTION i4_tinyint_le(integer, tinyint) RETURNS bool AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR <= (
	LEFTARG = integer,
	RIGHTARG = tinyint,
	PROCEDURE = i4_tinyint_le,
	COMMUTATOR = >=,
	NEGATOR = >,
	RESTRICT = scalarltsel,
	JOIN = scalarltjoinsel
);

CREATE FUNCTION i4_tinyint_gt(integer, tinyint) RETURNS bool AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR > (
	LEFTARG = integer,
	RIGHTARG = tinyint,
	PROCEDURE = i4_tinyint_gt,
	COMMUTATOR = <,
	NEGATOR = <=,
	RESTRICT = scalargtsel,
	JOIN = scalargtjoinsel
);

CREATE FUNCTION i4_tinyint_ge(integer, tinyint) RETURNS bool AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR >= (
	LEFTARG = integer,
	RIGHTARG = tinyint,
	PROCEDURE = i4_tinyint_ge,
	COMMUTATOR = <,
	NEGATOR = <=,
	RESTRICT = scalargtsel,
	JOIN = scalargtjoinsel
);


CREATE FUNCTION i8_tinyint_eq(bigint, tinyint) RETURNS bool AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR = (
	LEFTARG = bigint,
	RIGHTARG = tinyint,
	PROCEDURE = i8_tinyint_eq,
	COMMUTATOR = =,
	NEGATOR = <>,
	RESTRICT = eqsel,
	JOIN = eqjoinsel,
	HASHES,
	MERGES
);

CREATE FUNCTION i8_tinyint_ne(bigint, tinyint) RETURNS bool AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR <> (
	LEFTARG = bigint,
	RIGHTARG = tinyint,
	PROCEDURE = i8_tinyint_ne,
	COMMUTATOR = <>,
	NEGATOR = =,
	RESTRICT = neqsel,
	JOIN = neqjoinsel,
	MERGES
);

CREATE FUNCTION i8_tinyint_lt(bigint, tinyint) RETURNS bool AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR < (
	LEFTARG = bigint,
	RIGHTARG = tinyint,
	PROCEDURE = i8_tinyint_lt,
	COMMUTATOR = >,
	NEGATOR = >=,
	RESTRICT = scalarltsel,
	JOIN = scalarltjoinsel
);

CREATE FUNCTION i8_tinyint_le(bigint, tinyint) RETURNS bool AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR <= (
	LEFTARG = bigint,
	RIGHTARG = tinyint,
	PROCEDURE = i8_tinyint_le,
	COMMUTATOR = >=,
	NEGATOR = >,
	RESTRICT = scalarltsel,
	JOIN = scalarltjoinsel
);

CREATE FUNCTION i8_tinyint_gt(bigint, tinyint) RETURNS bool AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR > (
	LEFTARG = bigint,
	RIGHTARG = tinyint,
	PROCEDURE = i8_tinyint_gt,
	COMMUTATOR = <,
	NEGATOR = <=,
	RESTRICT = scalargtsel,
	JOIN = scalargtjoinsel
);

CREATE FUNCTION i8_tinyint_ge(bigint, tinyint) RETURNS bool AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR >= (
	LEFTARG = bigint,
	RIGHTARG = tinyint,
	PROCEDURE = i8_tinyint_ge,
	COMMUTATOR = <,
	NEGATOR = <=,
	RESTRICT = scalargtsel,
	JOIN = scalargtjoinsel
);


CREATE FUNCTION tinyint_um(tinyint) RETURNS tinyint AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR - (
	RIGHTARG = tinyint,
	PROCEDURE = tinyint_um
);

CREATE FUNCTION tinyint_up(tinyint) RETURNS tinyint AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR + (
	RIGHTARG = tinyint,
	PROCEDURE = tinyint_up
);

CREATE FUNCTION tinyint_pl(tinyint, tinyint) RETURNS tinyint AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR + (
	LEFTARG = tinyint,
	RIGHTARG = tinyint,
	PROCEDURE = tinyint_pl,
	COMMUTATOR = +
);

CREATE FUNCTION tinyint_mi(tinyint, tinyint) RETURNS tinyint AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR - (
	LEFTARG = tinyint,
	RIGHTARG = tinyint,
	PROCEDURE = tinyint_mi
);

CREATE FUNCTION tinyint_mul(tinyint, tinyint) RETURNS tinyint AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR * (
	LEFTARG = tinyint,
	RIGHTARG = tinyint,
	PROCEDURE = tinyint_mul,
	COMMUTATOR = *
);

CREATE FUNCTION tinyint_div(tinyint, tinyint) RETURNS tinyint AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR / (
	LEFTARG = tinyint,
	RIGHTARG = tinyint,
	PROCEDURE = tinyint_div
);

CREATE FUNCTION tinyint_inc(tinyint) RETURNS tinyint AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;

CREATE FUNCTION tinyint_i2_pl(tinyint, smallint) RETURNS smallint AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR + (
	LEFTARG = tinyint,
	RIGHTARG = smallint,
	PROCEDURE = tinyint_i2_pl,
	COMMUTATOR = +
);

CREATE FUNCTION tinyint_i2_mi(tinyint, smallint) RETURNS smallint AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR - (
	LEFTARG = tinyint,
	RIGHTARG = smallint,
	PROCEDURE = tinyint_i2_mi
);

CREATE FUNCTION tinyint_i2_mul(tinyint, smallint) RETURNS smallint AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR * (
	LEFTARG = tinyint,
	RIGHTARG = smallint,
	PROCEDURE = tinyint_i2_mul,
	COMMUTATOR = *
);

CREATE FUNCTION tinyint_i2_div(tinyint, smallint) RETURNS smallint AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR / (
	LEFTARG = tinyint,
	RIGHTARG = smallint,
	PROCEDURE = tinyint_i2_div
);


CREATE FUNCTION tinyint_i4_pl(tinyint, integer) RETURNS integer AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR + (
	LEFTARG = tinyint,
	RIGHTARG = integer,
	PROCEDURE = tinyint_i4_pl,
	COMMUTATOR = +
);

CREATE FUNCTION tinyint_i4_mi(tinyint, integer) RETURNS integer AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR - (
	LEFTARG = tinyint,
	RIGHTARG = integer,
	PROCEDURE = tinyint_i4_mi
);

CREATE FUNCTION tinyint_i4_mul(tinyint, integer) RETURNS integer AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR * (
	LEFTARG = tinyint,
	RIGHTARG = integer,
	PROCEDURE = tinyint_i4_mul,
	COMMUTATOR = *
);

CREATE FUNCTION tinyint_i4_div(tinyint, integer) RETURNS integer AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR / (
	LEFTARG = tinyint,
	RIGHTARG = integer,
	PROCEDURE = tinyint_i4_div
);


CREATE FUNCTION tinyint_i8_pl(tinyint, bigint) RETURNS bigint AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR + (
	LEFTARG = tinyint,
	RIGHTARG = bigint,
	PROCEDURE = tinyint_i8_pl,
	COMMUTATOR = +
);

CREATE FUNCTION tinyint_i8_mi(tinyint, bigint) RETURNS bigint AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR - (
	LEFTARG = tinyint,
	RIGHTARG = bigint,
	PROCEDURE = tinyint_i8_mi
);

CREATE FUNCTION tinyint_i8_mul(tinyint, bigint) RETURNS bigint AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR * (
	LEFTARG = tinyint,
	RIGHTARG = bigint,
	PROCEDURE = tinyint_i8_mul,
	COMMUTATOR = *
);

CREATE FUNCTION tinyint_i8_div(tinyint, bigint) RETURNS bigint AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR / (
	LEFTARG = tinyint,
	RIGHTARG = bigint,
	PROCEDURE = tinyint_i8_div
);


CREATE FUNCTION i2_tinyint_pl(smallint, tinyint) RETURNS smallint AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR + (
	LEFTARG = smallint,
	RIGHTARG = tinyint,
	PROCEDURE = i2_tinyint_pl,
	COMMUTATOR = +
);

CREATE FUNCTION i2_tinyint_mi(smallint, tinyint) RETURNS smallint AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR - (
	LEFTARG = smallint,
	RIGHTARG = tinyint,
	PROCEDURE = i2_tinyint_mi
);

CREATE FUNCTION i2_tinyint_mul(smallint, tinyint) RETURNS smallint AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR * (
	LEFTARG = smallint,
	RIGHTARG = tinyint,
	PROCEDURE = i2_tinyint_mul,
	COMMUTATOR = *
);

CREATE FUNCTION i2_tinyint_div(smallint, tinyint) RETURNS smallint AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR / (
	LEFTARG = smallint,
	RIGHTARG = tinyint,
	PROCEDURE = i2_tinyint_div
);


CREATE FUNCTION i4_tinyint_pl(integer, tinyint) RETURNS integer AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR + (
	LEFTARG = integer,
	RIGHTARG = tinyint,
	PROCEDURE = i4_tinyint_pl,
	COMMUTATOR = +
);

CREATE FUNCTION i4_tinyint_mi(integer, tinyint) RETURNS integer AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR - (
	LEFTARG = integer,
	RIGHTARG = tinyint,
	PROCEDURE = i4_tinyint_mi
);

CREATE FUNCTION i4_tinyint_mul(integer, tinyint) RETURNS integer AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR * (
	LEFTARG = integer,
	RIGHTARG = tinyint,
	PROCEDURE = i4_tinyint_mul,
	COMMUTATOR = *
);

CREATE FUNCTION i4_tinyint_div(integer, tinyint) RETURNS integer AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR / (
	LEFTARG = integer,
	RIGHTARG = tinyint,
	PROCEDURE = i4_tinyint_div
);


CREATE FUNCTION i8_tinyint_pl(bigint, tinyint) RETURNS bigint AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR + (
	LEFTARG = bigint,
	RIGHTARG = tinyint,
	PROCEDURE = i8_tinyint_pl,
	COMMUTATOR = +
);

CREATE FUNCTION i8_tinyint_mi(bigint, tinyint) RETURNS bigint AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR - (
	LEFTARG = bigint,
	RIGHTARG = tinyint,
	PROCEDURE = i8_tinyint_mi
);

CREATE FUNCTION i8_tinyint_mul(bigint, tinyint) RETURNS bigint AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR * (
	LEFTARG = bigint,
	RIGHTARG = tinyint,
	PROCEDURE = i8_tinyint_mul,
	COMMUTATOR = *
);

CREATE FUNCTION i8_tinyint_div(bigint, tinyint) RETURNS bigint AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR / (
	LEFTARG = bigint,
	RIGHTARG = tinyint,
	PROCEDURE = i8_tinyint_div
);


CREATE FUNCTION tinyint_mod(tinyint, tinyint) RETURNS tinyint AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR % (
	LEFTARG = tinyint,
	RIGHTARG = tinyint,
	PROCEDURE = tinyint_mod
);

CREATE FUNCTION tinyint_abs(tinyint) RETURNS tinyint AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE FUNCTION tinyint_larger(tinyint, tinyint) RETURNS tinyint AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE AGGREGATE max(tinyint) (
	SFUNC = tinyint_larger,
	STYPE = tinyint,
	SORTOP = >
);

CREATE FUNCTION tinyint_smaller(tinyint, tinyint) RETURNS tinyint AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE AGGREGATE min(tinyint) (
	SFUNC = tinyint_smaller,
	STYPE = tinyint,
	SORTOP = <
);

CREATE FUNCTION tinyint_and(tinyint, tinyint) RETURNS tinyint AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR & (
	LEFTARG = tinyint,
	RIGHTARG = tinyint,
	PROCEDURE = tinyint_and
);

CREATE FUNCTION tinyint_or(tinyint, tinyint) RETURNS tinyint AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR | (
	LEFTARG = tinyint,
	RIGHTARG = tinyint,
	PROCEDURE = tinyint_or
);
CREATE FUNCTION tinyint_xor(tinyint, tinyint) RETURNS tinyint AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR # (
	LEFTARG = tinyint,
	RIGHTARG = tinyint,
	PROCEDURE = tinyint_xor
);

CREATE FUNCTION tinyint_shl(tinyint, tinyint) RETURNS tinyint AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR << (
	LEFTARG = tinyint,
	RIGHTARG = tinyint,
	PROCEDURE = tinyint_shl
);

CREATE FUNCTION tinyint_shr(tinyint, tinyint) RETURNS tinyint AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR >> (
	LEFTARG = tinyint,
	RIGHTARG = tinyint,
	PROCEDURE = tinyint_shr
);

CREATE FUNCTION tinyint_not(tinyint) RETURNS tinyint AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE OPERATOR ~ (
	RIGHTARG = tinyint,
	PROCEDURE = tinyint_not
);

CREATE FUNCTION bt_tinyint_cmp(tinyint, tinyint) RETURNS integer AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;

CREATE FUNCTION bt_tinyint_i2_cmp(tinyint, smallint) RETURNS integer AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;

CREATE FUNCTION bt_tinyint_i4_cmp(tinyint, integer) RETURNS integer AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;

CREATE FUNCTION bt_tinyint_i8_cmp(tinyint, bigint) RETURNS integer AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;

CREATE FUNCTION bt_i2_tinyint_cmp(smallint, tinyint) RETURNS integer AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;

CREATE FUNCTION bt_i4_tinyint_cmp(integer, tinyint) RETURNS integer AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;

CREATE FUNCTION bt_i8_tinyint_cmp(bigint, tinyint) RETURNS integer AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;

CREATE OPERATOR CLASS btree_tinyint_ops
#if PG_VERSION_NUM >= 80300
DEFAULT FOR TYPE tinyint USING btree FAMILY integer_ops AS
#else
DEFAULT FOR TYPE tinyint USING btree AS
#endif
	OPERATOR 1 <,
	OPERATOR 2 <=,
	OPERATOR 3 =,
	OPERATOR 4 >=,
	OPERATOR 5 >,
	FUNCTION 1 bt_tinyint_cmp(tinyint, tinyint);

#if PG_VERSION_NUM >= 80300
ALTER OPERATOR FAMILY integer_ops USING btree ADD
	OPERATOR 1 < (tinyint, smallint),
	OPERATOR 2 <= (tinyint, smallint),
	OPERATOR 3 = (tinyint, smallint),
	OPERATOR 4 >= (tinyint, smallint),
	OPERATOR 5 > (tinyint, smallint),
	FUNCTION 1 bt_tinyint_i2_cmp(tinyint, smallint),

	OPERATOR 1 < (tinyint, integer),
	OPERATOR 2 <= (tinyint, integer),
	OPERATOR 3 = (tinyint, integer),
	OPERATOR 4 >= (tinyint, integer),
	OPERATOR 5 > (tinyint, integer),
	FUNCTION 1 bt_tinyint_i4_cmp(tinyint, integer),

	OPERATOR 1 < (tinyint, bigint),
	OPERATOR 2 <= (tinyint, bigint),
	OPERATOR 3 = (tinyint, bigint),
	OPERATOR 4 >= (tinyint, bigint),
	OPERATOR 5 > (tinyint, bigint),
	FUNCTION 1 bt_tinyint_i8_cmp(tinyint, bigint),

	OPERATOR 1 < (smallint, tinyint),
	OPERATOR 2 <= (smallint, tinyint),
	OPERATOR 3 = (smallint, tinyint),
	OPERATOR 4 >= (smallint, tinyint),
	OPERATOR 5 > (smallint, tinyint),
	FUNCTION 1 bt_i2_tinyint_cmp(smallint, tinyint),

	OPERATOR 1 < (integer, tinyint),
	OPERATOR 2 <= (integer, tinyint),
	OPERATOR 3 = (integer, tinyint),
	OPERATOR 4 >= (integer, tinyint),
	OPERATOR 5 > (integer, tinyint),
	FUNCTION 1 bt_i4_tinyint_cmp(integer, tinyint),

	OPERATOR 1 < (bigint, tinyint),
	OPERATOR 2 <= (bigint, tinyint),
	OPERATOR 3 = (bigint, tinyint),
	OPERATOR 4 >= (bigint, tinyint),
	OPERATOR 5 > (bigint, tinyint),
	FUNCTION 1 bt_i8_tinyint_cmp(bigint, tinyint)
	;

#endif

CREATE OPERATOR CLASS _tinyint_ops
DEFAULT FOR TYPE tinyint[] USING gin AS
	OPERATOR 1 &&(anyarray, anyarray),
	OPERATOR 2 @>(anyarray, anyarray),
#if PG_VERSION_NUM >= 80400
	OPERATOR 3 <@(anyarray, anyarray),
	OPERATOR 4 =(anyarray, anyarray),
#elif PG_VERSION_NUM >= 80300
	OPERATOR 3 <@(anyarray, anyarray) RECHECK,
	OPERATOR 4 =(anyarray, anyarray) RECHECK,
#endif
	FUNCTION 1 bt_tinyint_cmp(tinyint, tinyint),
	FUNCTION 2 ginarrayextract(anyarray, internal),
#if PG_VERSION_NUM >= 90100
	FUNCTION 3 ginqueryarrayextract(anyarray, internal, smallint, internal, internal, internal, internal),
	FUNCTION 4 ginarrayconsistent(internal, smallint, anyarray, integer, internal, internal, internal, internal),
#elif PG_VERSION_NUM >= 80400
	FUNCTION 3 ginqueryarrayextract(anyarray, internal, smallint, internal, internal),
	FUNCTION 4 ginarrayconsistent(internal, smallint, anyarray, integer, internal, internal),
#elif PG_VERSION_NUM >= 80300
	FUNCTION 3 ginqueryarrayextract(anyarray, internal, smallint),
	FUNCTION 4 ginarrayconsistent(internal, smallint, internal),
#elif PG_VERSION_NUM >= 80200
	FUNCTION 3 ginarrayextract(anyarray, internal),
	FUNCTION 4 ginarrayconsistent(internal, smallint, internal),
#endif
	STORAGE tinyint;

CREATE FUNCTION hash_tinyint(tinyint) RETURNS integer AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;

CREATE OPERATOR CLASS hash_tinyint_ops
FOR TYPE tinyint USING hash FAMILY integer_ops AS
	OPERATOR 1 =,
	FUNCTION 1 hash_tinyint(tinyint);

CREATE FUNCTION tinyint_sum(bigint, tinyint) RETURNS bigint AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE;
CREATE AGGREGATE sum(tinyint) (
	SFUNC = tinyint_sum,
	STYPE = bigint
);

CREATE FUNCTION tinyint_avg_accum(bigint[], tinyint) RETURNS bigint[] AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE AGGREGATE avg(tinyint) (
	SFUNC = tinyint_avg_accum,
	STYPE = bigint[],
	INITCOND = '{0,0}',
	FINALFUNC = int8_avg
);
