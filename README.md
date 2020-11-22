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
Fixed some bugs those addressed on issue pages and added `int1` alias as domain. But after some tests the results were very surprising; because `tinyint` field index (btree) size became very huge (about %150-200 more) comparing to `smallint` and `enum` fields.

row count  | table size | x size  | y size | z size | x idx size | y idx size | z idx size
----------------------------------------------------------------------------------------
10,502,101 |  363 MB    | 10 MB   |  20 MB |  40 MB |  212 MB    | 84 MB      |  70 MB

Test Stuff
```
create extension tinyint;
create type onoff as enum ('on','off');
create table a (x tinyint, y smallint, z onoff);
create index on a (x); create index on a (y); create index on a (z);

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
    replace(substr(count(*)::money::text, 2), '.00', '')    as "row count",
    pg_size_pretty(pg_table_size('a'))                      as "table size",
    pg_size_pretty(sum(pg_column_size(x))::bigint)          as "x size",
    pg_size_pretty(sum(pg_column_size(y))::bigint)          as "y size",
    pg_size_pretty(sum(pg_column_size(z))::bigint)          as "z size",
    pg_size_pretty(pg_relation_size('a_x_idx')::bigint)     as "x idx size",
    pg_size_pretty(pg_relation_size('a_y_idx')::bigint)     as "y idx size",
    pg_size_pretty(pg_relation_size('a_z_idx')::bigint)     as "z idx size"
from a
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
