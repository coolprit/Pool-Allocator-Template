
#pragma once
#include "PoolAllocator.h"

void* PoolAllocator::allocate(size_t size)
{
	if (_allocatorPtr == nullptr)
		_allocatorPtr = allocateBlock(size);

	Chunk* freeChunk = _allocatorPtr;
	_allocatorPtr = _allocatorPtr->next;

	return freeChunk;
}

Chunk* PoolAllocator::allocateBlock(size_t chunkSize)
{
	std::cout << "\nAllocating block <" << _chunksPerBlock << " chunks>:" << std::endl << std::endl;
	size_t blockSize = _chunksPerBlock * chunkSize;
	Chunk* blockBegin = reinterpret_cast<Chunk*>(malloc(blockSize));
	Chunk* chunk = blockBegin;

	for (int i = 0; i < _chunksPerBlock - 1; ++i)
	{
		chunk->next = reinterpret_cast<Chunk*>(reinterpret_cast<char*>(chunk) + chunkSize);
		chunk = chunk->next;
	}
	chunk->next = nullptr;

	return blockBegin;
}

void PoolAllocator::deallocate(void* chunk)
{
	reinterpret_cast<Chunk*>(chunk)->next = _allocatorPtr;
	_allocatorPtr = reinterpret_cast<Chunk*>(chunk);
}