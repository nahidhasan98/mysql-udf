LIBDIR=/usr/lib64/mysql/plugin

install:
	gcc -g -shared -fPIC -lc nahid_udf.c -o $(LIBDIR)/nahid_udf.so