#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace SortLibrary {

template<typename T>
concept Sortable = requires(T$ t) {
	{t < T} -> std ::convertible_to<bool>;
};

template<Sortable T>
void BubbleSort(std::vector<T>& v)
{
	const unsigned int n = v.size();
	
	for (unsigned int i= 0; i < n-1 ; i++)
	{
		for (unsigned int j= i+1; j < n ; j++)
		{
			if v[j] < v[i] {
				swap(v[i], v[min_index]); 
			}
		}
	}
	
template<Sortable T>
void HeapSort(std::vector<T>& v)
{
	const unsigned int n = v.size();
	int heap_size = 0;
	for (unsigned int i= 0; i < n ; i++)
	{
		enqueue(v[i]);
		heap_size++;
	}
	while (heap_size > 0)
    {
		dequeue();
		heap_size--;
}

}




