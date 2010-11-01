MODULES = tinyint
OBJS = tinyint.o
DATA_built = tinyint.sql
DATA = uninstall_tinyint.sql
REGRESS = tinyint

SQL_IN = tinyint.sql.in
EXTRA_CLEAN += $(SQL_IN)

PGXS := $(shell pg_config --pgxs)
include $(PGXS)

ifndef MAJORVERSION
MAJORVERSION := $(basename $(VERSION))
endif

$(SQL_IN): tinyint.sql.in.c
	$(CC) -E -P $(CPPFLAGS) $< > $@
