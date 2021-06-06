#include "PoolAllocator.h"

int main() 
{
	std::cout << "Pool Allocator v. 0.1" << std::endl;
	constexpr int arrSize = 10;

	std::cout << "Pepegas: "<< std::endl;
	PoolObj<Pepega, 7>* pepegas[arrSize];
	std::cout << "Size obj = " << sizeof(PoolObj<Pepega, 7>) << std::endl;
	std::cout << "Allocating: " << arrSize << " objs" << std::endl;
	for (int i = 0; i < arrSize; ++i) {
		pepegas[i] = new PoolObj<Pepega, 7>();
		std::cout << "new obj <" << i << "> = " << pepegas[i] << std::endl;
	}
	std::cout << std::endl;
	for (int i = arrSize - 1; i >= 0; --i) {
		std::cout << "delete obj <" << i << "> = " << pepegas[i] << std::endl;
		delete pepegas[i];
	}
	std::cout << std::endl;
	pepegas[0] = new PoolObj<Pepega, 7>();
	std::cout << "new obj <0> = " << pepegas[0] << std::endl << std::endl;

	std::cout << "Pyramids: " << std::endl;
	PoolObj<Pyramid, 10>* pyramids[arrSize];
	std::cout << "Size obj = " << sizeof(PoolObj<Pyramid, 10>) << std::endl;
	std::cout << "Allocating: " << arrSize << " objs" << std::endl;
	for (int i = 0; i < arrSize; ++i) {
		pyramids[i] = new PoolObj<Pyramid, 10>();
		std::cout << "new obj <" << i << "> = " << pyramids[i] << std::endl;
	}
	std::cout << std::endl;
	for (int i = arrSize - 1; i >= 0; --i) {
		std::cout << "delete obj <" << i << "> = " << pyramids[i] << std::endl;
		delete pyramids[i];
	}
	std::cout << std::endl;
	pyramids[0] = new PoolObj<Pyramid, 10>();
	std::cout << "delete obj <0> = " << pyramids[0] << std::endl << std::endl;
}