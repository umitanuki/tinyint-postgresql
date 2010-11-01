SET client_min_messages = warning;
\set ECHO none
\i tinyint.sql
\set ECHO all
RESET client_min_messages;

SELECT 0::tinyint;
SELECT 1::integer::tinyint::smallint::tinyint::bigint::tinyint;

SELECT 1::tinyint < 2::tinyint;
SELECT -1::tinyint > +10::tinyint;
SELECT 1::smallint > 0::tinyint;
SELECT 1::integer > 0::tinyint;
SELECT 1::bigint > 0::tinyint;
SELECT 1::tinyint < 0::smallint;
SELECT 1::tinyint < 0::integer;
SELECT 1::tinyint < 0::bigint;

SELECT 1::tinyint + 1::tinyint;
SELECT 1::tinyint + 1::smallint;
SELECT 1::tinyint + 1::integer;
SELECT 1::tinyint + 1::bigint;
SELECT 1::smallint + 1::tinyint;
SELECT 1::integer + 1::tinyint;
SELECT 1::bigint + 1::tinyint;
SELECT 2::tinyint * 2::tinyint;
SELECT 4::tinyint / -2::tinyint;
SELECT 2::smallint * 2::tinyint;
SELECT 2::integer * 2::tinyint;
SELECT 2::bigint * 2::tinyint;
SELECT 2::smallint / 2::tinyint;
SELECT 2::integer / 2::tinyint;
SELECT 2::bigint / 2::tinyint;
SELECT 2::tinyint * 2::smallint;
SELECT 2::tinyint * 2::integer;
SELECT 2::tinyint * 2::bigint;
SELECT 2::tinyint / 2::smallint;
SELECT 2::tinyint / 2::integer;
SELECT 2::tinyint / 2::bigint;

SELECT MAX(val), MIN(val), AVG(val), SUM(val) FROM (VALUES('1'::tinyint),('2'),('5'),('10')) AS s(val);

CREATE TABLE t_tinyint (vals tinyint[]);
INSERT INTO t_tinyint VALUES('{0,0,0,1,2,3,0}'),('{1,2,100,127,-126}'::tinyint[]);
CREATE INDEX t_tinyint_gin ON t_tinyint USING gin(vals);

SELECT 128::tinyint;
SELECT 16::tinyint * 16::tinyint;
SELECT 127::tinyint * 32767::smallint;
SELECT 16::tinyint / 0;
SELECT (1::bigint << 63) * 2::tinyint;
