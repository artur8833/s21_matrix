CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11
MAIN_FILES= s21_matrix/*.c 
TEST_FILES=  unit_test/*.c
CHECK_LINK= $(shell pkg-config --libs --cflags check)
GCOVFLAGS= -fprofile-arcs -ftest-coverage
LIBNAME= s21_matrix.a
GLFLAGS= --coverage
LIBS= -lcheck -lsubunit -lm -lgcov

all: s21_matrix.a

object:
	$(CC) $(CFLAGS) $(GCOVFLAGS) $(GLFLAGS) -c $(MAIN_FILES)

lib:
	ar rcs s21_matrix.a *.o

s21_matrix.a:
	$(CC) $(CFLAGS) -c $(MAIN_FILES)
	ar rc s21_matrix.a *.o
	ranlib s21_matrix.a

test: s21_matrix.a
	$(CC) $(CFLAGS) $(TEST_FILES) -L. s21_matrix.a $(CHECK_LINK) $(GLFLAGS) $(GCOVFLAGS) -o s21_matrix_test
	chmod 777 s21_matrix_test
	./s21_matrix_test

gcov_report: object lib test
	gcov *.gcno *.gcda
	~/.local/bin/gcovr -r . --html --html-details -o s21_matrix.html
	open s21_matrix.html

clean:
	rm -f *.o
	rm -f *.a
	rm -f unit_tests/*.o
	rm -f unit_tests/*.a
	rm -f string/*.o
	rm -f string/*.a
	rm -rf *.gcno
	rm -rf *.gcov
	rm -rf *.gcda
	rm -rf *.info
	rm -rf *.html
	rm -rf *.css
	rm -f ./s21_matrix_test
