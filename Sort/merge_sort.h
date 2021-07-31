#include <iostream>

/*
*递推公式：
*merge_sort(l…r) = merge(merge_sort(l…mid), merge_sort(mid+1…r))
*终止条件：
*l >= r 不用再继续分解
*/
template<typename T>
void merge(T arr[], int l, int mid, int r)
{
    T tmp[r-l+1];
    for(int i = l; i <= r; i++)
        tmp[i-l] = arr[i];
    
    int i = l, j = mid+1;
    for(int k = l; k <= r; k++)
    {
        if(i > mid)
        {
            arr[k] = tmp[j-l];
            j++;
        }
        else if(j > r)
        {
            arr[k] = tmp[i-l];
            i++;
        }
        else if(tmp[i-l] > tmp[j-l])
        {
            arr[k] = tmp[j-l];
            j++;
        }
        else
        {
            arr[k] = tmp[i-l];
            i++;
        }
    }
}

template<typename T>
void merge_sort(T arr[], int l, int r)
{
    if(l >= r)
        return;
    
    int mid = l + (r-l)/2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid+1, r);
    if(arr[mid] > arr[mid+1])
        merge(arr, l, mid, r);
}

template<typename T>
void merge_sort_way(T arr[], int n)
{
    merge_sort(arr, 0, n-1);
}