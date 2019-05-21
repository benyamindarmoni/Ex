#!make -f

all: demo
	./$<

demo:  Demo.o 
	g++ -std=c++11 $^ -o demo

test:  Test.o 
	g++ -std=c++11 $^ -o test

%.o: %.cpp range.hpp chain.hpp powerset.hpp product.hpp zip.hpp
	g++ -std=c++11 --compile $< -o $@

clean:
	rm -f *.o demo test