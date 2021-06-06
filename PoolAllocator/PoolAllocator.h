#pragma once
#include <iostream>

struct Chunk {
	Chunk* next;
};

class PoolAllocator {
public:
	PoolAllocator(size_t chunksPerBlock) : _chunksPerBlock(chunksPerBlock) {}
	void* allocate(size_t size);
	void deallocate(void* ptr);
private:
	size_t _chunksPerBlock;
	Chunk* _allocatorPtr = nullptr;
	Chunk* allocateBlock(size_t chunkSize);
};

template<typename T, int chunksPerBlock>
class PoolObj
{
public:
	T data;
	static PoolAllocator poolAllocator;
	void* operator new(size_t size)
	{
		return poolAllocator.allocate(size);
	}
	void operator delete(void* ptr)
	{
		poolAllocator.deallocate(ptr);
	}
};

template<typename T, int chunksPerBlock>
PoolAllocator PoolObj<T, chunksPerBlock>::poolAllocator{ chunksPerBlock };

class Pepega {
	public:
		int width, length;
		uint64_t test[4];
};

struct Pyramid {
	double length, width, height;
};