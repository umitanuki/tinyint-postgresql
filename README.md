### INSTALL
Download and unzip content, then use `make` tool (seems also server restart needed in some cases). Here is all-in-one command;

```
cd /tmp \
apt install unzip -y \
apt install postgresql-server-dev-13 -y \ # or any version
wget https://github.com/k-gun/tinyint-postgresql/archive/master.zip \
unzip master.zip && cd tinyint-postgresql-master \
make && make install && service postgresql restart
```

### NOTICE
Fixed some bugs those addressed on issue pages and added `int1` alias as domain. But after some tests the results were very surprising; because `tinyint` field index (BTree) size became very huge (about %150-200 more) comparing to `smallint` and `enum` fields. So, for this issue, field types can be converted to `smallint` and also GIN method can be used instead. But, seems whatever we do, both these methods ain't able to get speed of real integers.

| rows       | table  | x    | y     | z     | x idx  | x idx1 | x idx2 | y idx | z idx |
|---------------------------------------------------------------------------------------|
| 10,512,101 | 364 MB | 10 MB | 20 MB | 40 MB | 226 MB | 70 MB | 18 MB  | 85 MB | 70 MB |


Test Stuff
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

-- select count(*) from a where x = 3;             -- uses x idx  > btree(tinyint)           > 0.0417280197
-- select count(*) from a where x = 3;             -- uses x idx1 > btree(tinyint::smallint) > 0.1382019521
-- select count(*) from a where x::smallint = 3;   -- uses x idx2 > gin(tinyint::smallint)   > 0.1412460804
-- select count(*) from a where y = 3333;          -- uses y idx  > btree(smallint)          > 0.0051538944
-- select count(*) from a where z = 'on';          -- uses z idx  > btree(enum)              > 0.4917960167
```


### ORIGINAL README

```
tinyint-postgresql

This is an extension that impelements tinyint (1 byte integer) as a data type
of PostgreSQL. Traditionally, PostgreSQL core has a policy not to have 1 byte
integer in it. With this module, you can define 1 byte integer column on your
tables, which will help query performances and portabilities from other RDBMS.


Hitoshi Harada
```
