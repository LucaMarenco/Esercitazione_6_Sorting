#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace SortLibrary {

template<typename T>
concept Sortable = requires(T& t) {
    {t < t} -> std::convertible_to<bool>;
};

template<Sortable T>
void BubbleSort(vector<T>& v)
{
	const unsigned int n = v.size();
	
	for (unsigned int i= 0; i < n-1 ; i++)
	{
		for (unsigned int j= i+1; j < n ; j++)
		{
			if (v[j] < v[i]) {
				swap(v[i], v[j]); 
			}
		}
	}
}

template<Sortable T>
void toHeap(vector<T>& v, int n, int i)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && v[left] > v[largest])
        largest = left;

    if (right < n && v[right] > v[largest])
        largest = right;

    if (largest != i)
    {
        swap(v[i], v[largest]);
        toHeap(v, n, largest);
    }
}

template<Sortable T>
void HeapSort(vector<T>& v)
{
    int n = v.size();

    for (int i = n/2 - 1; i >= 0; i--)
        toHeap(v, n, i);

    for (int i = n-1; i > 0; i--)
    {
        swap(v[0], v[i]);
        toHeap(v, i, 0);
    }
}




}
