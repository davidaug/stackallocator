#include "StackAllocator.h"
#include <iostream>

#define KB 1024
#define MB 1024*1024


int main(){

	int a,*b,*c;

	StackAllocator *stack = new StackAllocator(MB*10);

	std::cout << stack->getMarker() << std::endl;

	b = (int*)stack->alloc(sizeof(int)*100);

	std::cout << stack->getMarker() << std::endl;

	c = (int*)stack->alloc(sizeof(int)*10);

	std::cout << stack->getMarker() << std::endl;


	for(a=0;a<10;++a)
		b[a] = a;

	for(a=0;a<10;++a)
		std::cout << b[a] << std::endl;

	std::cout << "SIZE OF INT:" << sizeof(int) << std::endl;

	std::cout << "B:" << b << std::endl << "C:" << c << std::endl;

	std::cin >> a;

	delete stack;

	return 0;
}