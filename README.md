Tinyint data type extension for PostgreSQL
==========================================

This is an extension that impelements `tinyint` (1 byte integer) as a data type
of [PostgreSQL](https://www.postgresql.org/). Traditionally, PostgreSQL core has
a policy not to have 1 byte integer in it. With this module, you can define 1 byte
integer column on your tables, which will help query performances and portabilities
from other RDBMS.

Contents
--------

1. [Features](#features)
2. [Supported platforms](#supported-platforms)
3. [Installation](#installation)
4. [Usage](#usage)
5. [Examples](#examples)
6. [Common tests](#common-tests)
7. [Special tests](#special-tests)
8. [Limitations](#limitations)
9. [Development roadmap](#development-roadmap)
10. [Useful links](#useful-links)
11. [Authors](#authors)

Features
--------

`Tinyint` data type provides transformations to or from other integer data types
and arythmetic operations. Also there is `int1` alias as domain.

Supported platforms
-------------------

`Tinyint` was developed on Linux and should run on any reasonably POSIX-compliant system.

Installation
------------

Only source installacion is availlable. There is no `rpm` or `deb` packages. We will be glad if any `tinyint` packages will be made.

### Source installation

Prerequisites:

For Ubuntu/Debian environment
- `postgresql-server-dev-{version}` or similar package for Your version
- `gcc` with `make`
- `postgresql-server-{version}` or similar package as PostgreSQL server for using this extension

#### Installation process:

Change directory to directory of this file downloaded for compiling and just type
`make && sudo make install`.

Sometimes it will be useful someting like `sudo systemctl restart postgresql` or `sudo service postgresql restart`.
Please carefully read output of `sudo make install` for understanding location of `tinyint` extension files in PostgreSQL RDBMS directories.

#### All-in-one shell command

```sh
cd /tmp && \
apt install unzip -y && \
apt install postgresql-server-dev-13 -y && \ # or any version
wget https://github.com/okerem/tinyint-postgresql/archive/master.zip && \
unzip master.zip && cd tinyint-postgresql-master && \
make && make install && service postgresql restart
```

Usage
-----

For each database you need just execute `CREATE EXTENSION tinyint;`

Examples
--------

Install the extension:

    CREATE EXTENSION tinyint;

Create a table using `tinyint`:

    CREATE TABLE test(
      id tinyint,
      val text
    );
    
Common tests
------------

Sample outputs of `psql` are provided in the [`../expected/`](https://github.com/okerem/tinyint-postgresql/tree/master/expected) directory. 


Special tests
-------------

`Tinyint` field index (BTree) size became very huge (about %150-200 more) comparing to `smallint` and `enum` fields. So, for this issue, field types can be converted to `smallint` and also GIN method can be used instead. But, seems whatever we do, both these methods ain't able to get speed of real integers.

| rows       | table  | x     | y     | z     | x idx  | x idx1 | x idx2 | y idx | z idx |
|------------|--------|-------|-------|-------|--------|--------|--------|-------|-------|
| 10,512,101 | 364 MB | 10 MB | 20 MB | 40 MB | 226 MB | 70 MB  | 18 MB  | 85 MB | 70 MB |


Sample script for performance and stored data size tests
```sql
create extension tinyint;
create extension btree_gin; -- needed for gin
create type onoff as enum ('on','off');
create table a (x tinyint, y smallint, z onoff);
create index on a (x);                        -- idx
create index on a using btree((x::smallint)); -- idx1
create index on a using gin((x::smallint));   -- idx2
create index on a (y);
create index on a (z);

do $$ begin
    for i in 1..1500000 loop
        insert into a(x, y, z)
            select
                (random() * 127)::int::tinyint,
                (random() * 32767)::smallint,
                (case when random() > 0.5 then 'on' else 'off' end)::onoff
        ;
    end loop;
end; $$

select
    replace(substr(count(*)::money::text, 2), '.00', '')    as "rows",
    pg_size_pretty(pg_table_size('a'))                      as "table",
    pg_size_pretty(sum(pg_column_size(x))::bigint)          as "x",
    pg_size_pretty(sum(pg_column_size(y))::bigint)          as "y",
    pg_size_pretty(sum(pg_column_size(z))::bigint)          as "z",
    pg_size_pretty(pg_relation_size('a_x_idx')::bigint)     as "x idx",
    pg_size_pretty(pg_relation_size('a_x_idx1')::bigint)    as "x idx1",
    pg_size_pretty(pg_relation_size('a_x_idx2')::bigint)    as "x idx2",
    pg_size_pretty(pg_relation_size('a_y_idx')::bigint)     as "y idx",
    pg_size_pretty(pg_relation_size('a_z_idx')::bigint)     as "z idx"
from a;

select count(*) from a where x = 3           -- uses x idx  > btree(tinyint)           > 0.0417280197 ms
select count(*) from a where x::smallint = 3 -- uses x idx1 > btree(tinyint::smallint) > 0.1382019521 ms
select count(*) from a where x::smallint = 3 -- uses x idx2 > gin(tinyint::smallint)   > 0.1412460804 ms
select count(*) from a where y = 3333        -- uses y idx  > btree(smallint)          > 0.0051538944 ms
select count(*) from a where z = 'on'        -- uses z idx  > btree(enum)              > 0.4917960167 ms
```

Limitations
-----------
Postgresql 9.4+

Development roadmap
-------------------

Waiting on Your pull requests ;-)

Useful links
------------
 - Other 1 byte integer data type for PostgreSQL in repository of unsigned integers for PostgreSQL https://github.com/petere/pguint
 - https://wiki.postgresql.org
 - https://pgxn.org
 
Authors
-------

* Original idea by [*Hitoshi Harada*](https://github.com/umitanuki/tinyint-postgresql).
* Advanced tests and source code actualisation by [*Kerem Güneş*](https://github.com/okerem/tinyint-postgresql). 
