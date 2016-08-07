#include <iostream>
#include <vector>
#include <ctime>
#include <random>


/**
 * @name 			quickSort
 * @parameter 		std::vector<T> &, const int begin, const int end 
 * @return 			void
 *
 * @author 			Diogo Dantas
 *
 * Implementation of classic sort algorithm called quick sort.
 * The pivot is always chosen as the last element of the vector. 
 */

template<typename T>
void quickSort(std::vector<T> &unordered_vector ,const int begin, const int end)
{
	T pivot = end; 

	std::swap(unordered_vector[pivot], unordered_vector[end]);
	pivot = end;

	int i = begin;
	int j = end-1;

	while(true){
		while(unordered_vector[i] <= unordered_vector[pivot] && i < end)
			i++;

		while(unordered_vector[j] > unordered_vector[pivot] && j >= begin)
			j--;

		if(i < j){
			std::swap(unordered_vector[j], unordered_vector[i]);
		}
		else{
			std::swap(unordered_vector[pivot], unordered_vector[i]);
			break;
		}
	}

	if(begin < i-1)
		quickSort(unordered_vector, begin, i-1);
	if(i+1 < end)
		quickSort(unordered_vector, i+1, end);
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

	// calling the quickSort procedure
	quickSort(v_int, 0, v_int.size() - 1);
	quickSort(v_float, 0, v_float.size() - 1);
	
	//Output 	
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
