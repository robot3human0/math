CC = gcc
EXP_MATH_C = exp_*.c
EXP_MATH_O = exp_*.o
CFLAGS = -Wall -Wextra -Werror -std=c11
CCOV = -fprofile-arcs -ftest-coverage
COVFLAGS = --coverage
OS=$(shell uname)
ifeq ($(OS), Linux)
	LIBS=-lcheck -lpthread -lrt -lm -lsubunit
else
	LIBS=-lcheck
endif


all: clean test exp_math.a gcov_report

exp_math.a: $(EXP_MATH_C)
	$(CC) $(CFLAGS) -c -g $(EXP_MATH_C)
	ar rcs exp_math.a $(EXP_MATH_O)
	ranlib exp_math.a

test: exp_math.a test_math.o
	$(CC) $(CCOV) test_math.o exp_math.a -o test $(LIBS)
	./test

test_math.o: test_math.c
	$(CC) $(CFLAGS) -c test_math.c

	
gcov_report: exp_math.a 
	$(CC) $(GFLAGS) $(CCOV) -g test_math.c $(EXP_MATH_C) exp_math.a -L. exp_math.a $(LIBS) -o ./htmlreport.out
	./htmlreport.out
	lcov -t "htmlreport" -o test.info -c -d .
	genhtml -o report test.info

gcovr: exp_math.a 
	$(CC) $(GFLAGS) $(CCOV) -g test_math.c $(EXP_MATH_C) exp_math.a -L. exp_math.a $(LIBS) -o ./htmlreport.out
	./htmlreport.out
	gcov -f *.gcda
	gcovr
	gcovr --html-details -o report.html
	open report.html



check:
	python3 ../linter/cpplint.py --extension=c *.c

leakscheck:
	CK_FORK=no leaks --atExit -- ./test   	


clean:
	rm -rf *.o *.a *.css *.html *.gcno *.gcda *.out *.info test report *.dSYM *.gcov

rebuild: clean all

