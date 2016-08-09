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
	std::vector<int> v_int;
	std::vector<float> v_float;
	float low = 0.0f, high = 100.0f;
	srand(time(NULL)); // Seed

	/*/**
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

	// calling the heapSort procedure
	heapSort(v_int);
	heapSort(v_float);

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
