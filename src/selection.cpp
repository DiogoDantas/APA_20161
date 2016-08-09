#include <iostream>
#include <vector>
#include <ctime>
#include <random>

/**
 * @name 			selectionSort
 * @parameter 		std::vector<T> & 
 * @return 			void
 *
 * @author 			Diogo Dantas
 *
 * implementation of classic sort algorithm called selection sort. 
 */
template <typename T>
void selectionSort(std::vector<T>& unordered_vector){
	int min;

	for (unsigned int i = 0; i < unordered_vector.size() - 1; ++i)
	{
		min = i;

		for (unsigned int j = i + 1; j < unordered_vector.size(); ++j)
		{
			if (unordered_vector[j] < unordered_vector[min])
			{
				min = j;
			}
		}

		std::swap(unordered_vector[i], unordered_vector[min]);
	}
}

int main(int argc, char const *argv[])
{
	std::vector<int> input;
 	int count = 0, tmp = 0, input_size;

 	std::cin >> input_size;

 	while(count < input_size) {
 		std::cin >> tmp;
 		input.push_back(tmp);
 		++count;
 	}

 	selectionSort(input);

 	for (std::vector<int>::iterator it = input.begin(); it != input.end(); ++it)
 	{
 		std::cout << *it << std::endl;
 	}
	
	return 0;
}
