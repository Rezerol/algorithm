#include <algorithm>
#include <iostream>


/*
*思路类似插入排序，分为已排序和未排序区间，
*选择排序每次都会从未排序区间中找到最小的元素，将其放到已排序区间的末尾。
*时间复杂度：O（n^2）
*/
template<typename T>
void selection_sort(T arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        int min_index = i;
        for(int j = i+1; j < n; j++)
        {
            if(arr[j] < arr[min_index])
                min_index = j;
        }
        std::swap(arr[i], arr[min_index]);
    }
}