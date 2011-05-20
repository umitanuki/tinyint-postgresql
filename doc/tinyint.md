tinyint 0.1.1
=============

Synopsis
--------

    % CREATE EXTENSION tinyint;
    CREATE EXTENSION

    % SELECT 1::tinyint;


Description
-----------

This module provides 1 byte signed integer type with operators,
index access methods and support functions. You can use it as
like the corresponding data type in other RDBMS as well as
smallint, integer or bigint in PostgreSQL. Although the byte
used for 1 tinyint is exactly 1 byte, you need to take account
into its position in the row if you really care the table size
since PostgreSQL usually pads extra bytes for the alignment of 4.

tinyint holds -127 to 127. +, -, *, %. min(), max(), sum(), avg(),
btree index and gin index are supported as other integer types.

Support
-------

This library is stored in an open [GitHub
repository](http://github.com/umitanuki/tinyint-postgresql).
Feel free to fork and contribute! Please file bug reports
via [GitHub Issues](http://github.com/umitanuki/tinyint-postgresql/issues/).

Author
------

[Hitoshi Harada](mailto:umi.tanuki@gmail.com)

Copyright and License
---------------------

Copyright (c) Hitoshi Harada

This module is free software; you can redistribute it and/or modify it under
the [PostgreSQL License](http://www.opensource.org/licenses/postgresql).

Permission to use, copy, modify, and distribute this software and its 
documentation for any purpose, without fee, and without a written agreement is
hereby granted, provided that the above copyright notice and this paragraph
and the following two paragraphs appear in all copies.

In no event shall Hitoshi Harada be liable to any party for direct,
indirect, special, incidental, or consequential damages, including
lost profits, arising out of the use of this software and its documentation,
even if Hitoshi Harada has been advised of the possibility of such damage.

Hitoshi Harada specifically disclaim any warranties,
including, but not limited to, the implied warranties of merchantability and 
fitness for a particular purpose. The software provided hereunder is on an "as 
is" basis, and Hitoshi Harada has no obligations to provide maintenance,
support, updates, enhancements, or modifications.

