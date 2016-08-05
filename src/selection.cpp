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
	std::vector<int> v_int;
	std::vector<float> v_float;
	float low = 0.0f, high = 100.0f;
	srand(time(NULL)); // Seed


	/**
	 * filling the vector of integers
	 */
	for (int i = 0; i < 10; ++i)
	{
		v_int.push_back(rand() % 100);
	}

	/**
	 * filling the vector of floating
	 */
	for (int i = 0; i < 5; ++i)
	{
		v_float.push_back(low + static_cast <float> (rand() / static_cast <float> (RAND_MAX / (high - low))));
	}

	// calling the selectionSort procedure
	selectionSort(v_int);
	selectionSort(v_float);


	for(std::vector<int>::iterator it = v_int.begin(); it != v_int.end(); ++it){
		std::cout << *it << " ";
	}

	
	std::cout << std::endl; 

	for(std::vector<float>::iterator it = v_float.begin(); it != v_float.end(); ++it){
		std::cout << *it << " ";
	}

	std::cout << std::endl;
	
	return 0;
}
