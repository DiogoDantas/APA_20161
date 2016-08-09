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
	std::vector<int> input;
 	int count = 0, tmp = 0, input_size;

 	std::cin >> input_size;

 	while(count < input_size) {
 		std::cin >> tmp;
 		input.push_back(tmp);
 		++count;
 	}

 	mergeSort(input, 0, input.size() - 1);

 	for (std::vector<int>::iterator it = input.begin(); it != input.end(); ++it)
 	{
 		std::cout << *it << std::endl;
 	}
	
	return 0;

}