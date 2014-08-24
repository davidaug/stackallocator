#include <cstdlib>
#include <cstdint>

class StackAllocator{

public:
	typedef intptr_t U32;
	typedef intptr_t Marker;

	explicit StackAllocator(U32 stackSize_bytes);

	virtual ~StackAllocator();

	void* alloc(U32 size_bytes);
	
	Marker getMarker();

	void freeToMarker(Marker marker);

	void clear();

private:
	Marker marker;
	Marker currMarker;

};