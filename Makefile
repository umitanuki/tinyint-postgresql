EXTENSION = tinyint
EXTVERSION = 0.1.1
EXTSQL = $(EXTENSION)--$(EXTVERSION).sql

MODULES = tinyint
OBJS = tinyint.o
DATA_built = tinyint.sql
DATA = uninstall_tinyint.sql
DOCS = doc/tinyint.md
REGRESS = tinyint

SQL_IN = tinyint.sql.in
EXTRA_CLEAN += $(SQL_IN) $(EXTSQL)

USE_EXTENSION = $(shell pg_config --version | grep -qE " 8\.|9\.0" && echo no || echo yes)

ifeq ($(USE_EXTENSION),yes)
all: $(EXTSQL)

$(EXTSQL): $(EXTENSION).sql
	cp $< $@

DATA = $(EXTSQL)
endif

PGXS := $(shell pg_config --pgxs)
include $(PGXS)

$(SQL_IN): tinyint.sql.in.c
	$(CC) -E -P $(CPPFLAGS) $< > $@
