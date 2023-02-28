CC = gcc
FLAGS = -Wall -Werror -Wextra -std=c11 # -g -fsanitize=address
TEST_FLAGS = -lcheck -lm -lpthread
FLAG_COV = -lcheck -lgcov -fprofile --coverage
TARGET = GLWidget
TAR = GLWidget.tar.gz
ifeq ($(shell uname), Linux)
	TEST_FLAGS += -lrt -lsubunit
	FLAG_COV = -lcheck -lgcov -lm -lpthread -lsubunit --coverage
endif

all: install

.PHONY: install
install:
	cd ../build && cmake ../src/rendering/. && make
	../build/GLWidget

.PHONY: uninstall
uninstall:
	rm -fr ../build/*

.PHONY: gcov_report
gcov_report: test
	gcc -o test s21_3DViever.a ./backend/parser.c ./tests/s21_3DViever_test.c $(FLAG_COV)
	./test
	lcov -t "gcov_report" -o gcov_report.info -c -d ./
	genhtml -o report gcov_report.info
	open ./report/index.html
	rm -fr parser.o s21_3DViever.a test *.gcda *.gcno gcov_report.info

.PHONY: test
test: s21_smart_calc.a
	$(CC) $(FLAGS) tests/s21_3DViever_test.c s21_3DViever.a $(TEST_FLAGS) -o test
	./test
	rm *.o

.PHONY: s21_smart_calc.a 
s21_smart_calc.a: o_files
	ar rcs s21_3DViever.a *.o
	ranlib s21_3DViever.a

.PHONY: o_files
o_files:
	gcc -c ./backend/parser.c

.PHONY: clean
clean: uninstall
	rm -fr parser.o s21_3DViever.a test *.gcda *.gcno gcov_report.info ./report