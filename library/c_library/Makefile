all:
	make library && make app

library:
	gcc -shared -o libdavid_sum.so -fPIC david_sum.c

app:
	gcc main.c -o the_app -L. -ldavid_sum

run:
	LD_LIBRARY_PATH=. ./the_app

clean:
	rm libdavid_sum.so && rm the_app