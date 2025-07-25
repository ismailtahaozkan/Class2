all: clean test

appTests: test_arrayListType.cpp arrayListType.h catch_amalgamated.cpp
	g++ -Wall --std=c++17 test_arrayListType.cpp catch_amalgamated.cpp -o appTests

test: appTests
	./appTests

clean:
	rm -f appTests
