#include <iostream>


/*
 *将数组分成两个区间，已排序区间和未排序区间，
 *初始已排序区间只有一个元素，就是数组的第一个元素，
 *插入算法的核心是取未排序区间中的元素，在已排序区间中找到合适的插入位置将其插入，
 *并保证已排序区间的数据一致有序。
 *时间复杂度：O（n^2）
 */
template<typename T>
void insertion_sort(T arr[], int n)
{
    for(int i = 1; i < n; i++)
    {
        T e = arr[i];
        int j;  //保存元素e应该插入的位置
        for(j = i; j > 0 && arr[j-1] > e; j--)
            arr[j] = arr[j-1];    //以赋值的方式代替传统的swap，避免多次赋值（一次swap有三次赋值）
        arr[j] = e;
    }
}