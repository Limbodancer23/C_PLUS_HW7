#include <iostream>

namespace test1{
	float* initArr(size_t size) {
		srand(time(NULL));
		float* myArr = new float[size];

		std::fill(myArr, myArr + size, 3.14);

		for (size_t i = 0; i < size; i++)
		{
			myArr[i] = -0.01 * (rand() % 2000 - 1000);
		}
		return myArr;
	}

	void printArr(float* arr, size_t size) {
		for (size_t i = 0; i < size; i++)
		{
			std::cout << arr[i] << std::endl;
		}
	}

	void arrCounter(float* arr, size_t size) {
		int count = size;
		for (size_t i = 0; i < size; i++)
		{
			if (arr[i] < 0)
			{
				count--;
			}
		}

		std::cout << "Positive: " << count << "\n" << "Negative: " << size - count << std::endl;
		delete[] arr;
	}
}