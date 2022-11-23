ListTest: ListTest.o List.o
	g++ -std=c++17 -Wall -g -o ListTest ListTest.o List.o

List.o: List.cpp List.h
	g++ -std=c++17 -Wall -g -c List.cpp

ListTest.o: ListTest.cpp List.h
	g++ -std=c++17 -Wall -g -c ListTest.cpp
clean:
	rm -f List.o ListTest.o ListTest
checkTest:
	valgrind --leak-check=full -v ./ListTest
