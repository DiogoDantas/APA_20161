#include <iostream>
#include <vector>
#include <ctime>
#include <random>


/**
 * @name 			insertionSort
 * @parameter 		std::vector<T> &
 * @return 			void
 *
 * @author 			Diogo Dantas
 *
 * implementation of classic sort algorithm called insertion sort.
 */

template <typename T>
inline void insertionSort(std::vector<T> &unordered_vector){

	int i = 0 ;
	unsigned int j = 0;
	T key;

	for (j = 1; j < unordered_vector.size(); ++j)
	{
		key = unordered_vector[j];
		i = j - 1;

		while(i >= 0 && unordered_vector[i] > key) {
		    unordered_vector[i + 1] = unordered_vector[i];
		    i = i - 1;
		}

		unordered_vector[i + 1] = key;
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

 	insertionSort(input);

 	for (std::vector<int>::iterator it = input.begin(); it != input.end(); ++it)
 	{
 		std::cout << *it << std::endl;
 	}

	return 0;
}
