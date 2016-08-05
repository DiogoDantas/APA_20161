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

	// calling the insertionSort procedure
	insertionSort(v_int);
	insertionSort(v_float);


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

