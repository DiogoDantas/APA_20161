#include <iostream>
#include <vector>
#include <ctime>
#include <random>

/**
 * @author 			Diogo Dantas
 * @Date 			08/08/2016 
 *
 * Implementation of sort algorithm called Heap Sort.
 * The implementation below is based on a available pseudocode in the book "Introduction to Algorithms third edition "
 */

template<typename T>
void maxHeapify(std::vector<T> &unordered_vector, const int heap_size, const int index){

	int left_child_index  = (2 * index) + 1;
	int right_child_index = (2 * index) + 2;
	int largest_element = index;

	// checking if the left child is higher
	if(left_child_index <= heap_size && unordered_vector[left_child_index] > unordered_vector[index]){
		largest_element = left_child_index;
	}

	//checking if the right child is higher
	if (right_child_index <= heap_size && unordered_vector[right_child_index] > unordered_vector[largest_element]){
		largest_element = right_child_index;
	}

	if (largest_element != index)
	{
		std::swap(unordered_vector[index], unordered_vector[largest_element]);
		maxHeapify(unordered_vector, heap_size, largest_element);
	}
}


template<typename T>
void buildMaxHeap(std::vector<T> &unordered_vector, const int heap_size){
	
	int heap_size_ = heap_size;
	
	for (int i = (static_cast<int>(unordered_vector.size()) - 1) / 2; i >= 0; --i)
	{
		maxHeapify(unordered_vector, heap_size_, i);
	}
}


template<typename T>
void heapSort(std::vector<T> &unordered_vector){
	
	int heap_size = static_cast<int>(unordered_vector.size()) - 1;
	buildMaxHeap(unordered_vector, heap_size);
	
	for (int i = static_cast<int>(unordered_vector.size()) - 1; i >= 0; --i)
	{
		std::swap(unordered_vector[i], unordered_vector[0]);
		heap_size -= 1;
		maxHeapify(unordered_vector,heap_size, 0);
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

 	heapSort(input);

 	for (std::vector<int>::iterator it = input.begin(); it != input.end(); ++it)
 	{
 		std::cout << *it << std::endl;
 	}
	
	return 0;
}
