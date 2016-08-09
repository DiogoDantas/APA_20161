#include <iostream>
#include <vector>
#include <ctime>
#include <random>

/**
 * @author 			Diogo Dantas
 * @Date 			08/08/2016
 *
 * Implementation of classic sort algorithm called mergeSort.
 */

template<typename T>
void merge(std::vector<T> &unordered_vector, const int begin, const int middle, const int end){
	
	std::vector<T> tmp_vector;

	/**
	 * Copying the elements of the original vector for an auxiliary vector.
	*/

	 tmp_vector = unordered_vector;

	/**
	 * doing the merge of subvectors  
	*/

	 int i = begin, j = middle + 1 , k = begin;

	 while(i <= middle && j <= end)
	 {

	 	if (tmp_vector[i] <= tmp_vector[j])
	 	{
	 		unordered_vector[k] = tmp_vector[i];
	 		++i; 
	 	}else{
	 		unordered_vector[k] = tmp_vector[j];
	 		++j;
	 	}

	 	++k;
	 }

	 while(i <= middle) {
	 	unordered_vector[k] = tmp_vector[i];
	 	++i;
	 	++k;
	 }

	 while(j <= end){
	 	unordered_vector[k] = tmp_vector[j];
	 	++j;
	 	++k;
	 }

}


template<typename T>
void mergeSort(std::vector<T> &unordered_vector, const int begin, const int end){
	if(begin < end){
		int middle = begin + (end - begin) / 2;
		mergeSort(unordered_vector, begin, middle);
		mergeSort(unordered_vector, middle + 1, end);
		merge(unordered_vector, begin, middle, end);
	}
}


int main(int argc, char const *argv[]){
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

	// calling the mergeSort procedure
	mergeSort(v_int, 0, v_int.size() - 1);
	mergeSort(v_float, 0, v_float.size() - 1);

	//Output
	for (std::vector<int>::iterator it = v_int.begin(); it != v_int.end(); ++it){
		std::cout << *it << " ";	
	}

	std::cout << std::endl;
	
	for(std::vector<float>::iterator it = v_float.begin(); it != v_float.end(); ++it){
		std::cout << *it << " ";
	}

	
	std::cout << std::endl;
	
	return 0;

}