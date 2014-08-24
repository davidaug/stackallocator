#include "StackAllocator.h"

StackAllocator::StackAllocator(U32 stackSize_bytes){

	this->marker = (Marker)malloc(stackSize_bytes);
	this->currMarker = this->marker;

}

void* StackAllocator::alloc(U32 size_bytes){

	Marker temp = this->currMarker;

	this->currMarker += size_bytes;
	
	return (void*)temp;
}

StackAllocator::Marker StackAllocator::getMarker(){
	return this->currMarker;
}

void StackAllocator::freeToMarker(Marker marker){

	this->currMarker = marker;
}

void StackAllocator::clear(){

	this->currMarker = this->marker;
}

StackAllocator::~StackAllocator(){

	free((void*)this->marker);

}