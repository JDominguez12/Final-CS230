mainprogram: main.cpp main.hpp
	g++ -fsanitize=address -std=c++11 main.cpp -o mainprogram

programtest: tests.cpp main.hpp
	g++ -fsanitize=address -std=c++11 tests.cpp -o programtest

test: programtest
	./programtest

clean:
	rm -f programtest mainprogram a.out a.exe