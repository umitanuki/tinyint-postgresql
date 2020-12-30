PG_CONFIG   ?= pg_config

EXTENSION = tinyint
EXTVERSION = 0.1.2
EXTSQL = $(EXTENSION)--$(EXTVERSION).sql
EXTSQLTMP = $(EXTENSION).sql

MODULES = tinyint
OBJS = tinyint.o
DATA = uninstall_tinyint.sql
DOCS = doc/tinyint.md
REGRESS = tinyint

SQL_IN = tinyint.sql.in
EXTRA_CLEAN += $(SQL_IN) $(EXTSQL) $(EXTSQLTMP)

USE_EXTENSION = $(shell pg_config --version | grep -qE " 8\.|9\.0" && echo no || echo yes)

ifeq ($(USE_EXTENSION),yes)
all: $(EXTSQL)

$(EXTSQL): $(EXTSQLTMP)
	cp $< $@

DATA = $(EXTSQL)
endif

PGXS := $(shell pg_config --pgxs)
include $(PGXS)

$(SQL_IN): tinyint.sql.in.c
	$(CC) -E -P $(CPPFLAGS) $< > $@
