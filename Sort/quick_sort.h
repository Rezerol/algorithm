#include <iostream>
#include <ctime>
#include <algorithm>

template<typename T>
int partion(T arr[], int l, int r)
{
    //避免分割不均，导致时间复杂度降到O（n^2）
    std::swap(arr[l], arr[rand()%(r-l+1)+l]);

    T v = arr[l];
    int j = l;
    //使得arr[l+1, j] < v, arr[j+1, i) > v
    for(int i = l+1; i <= r; i++)
    {
        if(arr[i] < v)
        {
            std::swap(arr[j+1], arr[i]);
            j++;
        }
    }
    std::swap(arr[l], arr[j]);
    return j;
}

template<typename T>
int partion2(T arr[], int l, int r)
{
    std::swap(arr[l], arr[rand()%(r-l+1)+l]);
    T v = arr[l];

    int i, j;
    i = l+1;
    j = r;
    while(true)
    {
        while(i <= r && arr[i] < v)
            i++;
        while(j >= l+1 && arr[j] > v)
            j--;
        if(i > j)
            break;
        std::swap(arr[i], arr[j]);
        i++;
        j--;
    }
    std::swap(arr[l], arr[j]);
    return j;
}

//对arr[l,r]进行快速排序
template<typename T>
void quick_sort(T arr[], int l, int r)
{
    if(l >= r)
        return;
    
    int q = partion(arr, l, r);
    quick_sort(arr, l, q-1);
    quick_sort(arr, q+1, r);
}

template<typename T>
void quick_sort_way1(T arr[], int n)
{
    srand(time(NULL));
    quick_sort(arr, 0, n-1);
}

template<typename T>
void quick_sort2(T arr[], int l, int r)
{
    if(l >= r)
        return;
    
    int q = partion2(arr, l, r);
    quick_sort(arr, l, q-1);
    quick_sort(arr, q+1, r);
}

template<typename T>
void quick_sort_way2(T arr[], int n)
{
    srand(time(NULL));
    quick_sort2(arr, 0, n-1);
}

template<typename T>
void quick_sort3_ways(T arr[], int l, int r)
{
    if(l >= r)
        return;
    
    std::swap(arr[l], arr[rand()%(r-l+1)+l]);
    T v = arr[l];
    int lt = l;  //arr[l+1, lt] < v
    int gt = r+1; //arr[gt,r] > v
    int i = l+1;  //arr[lt+1, gt-1] == v
    while(i < gt)
    {
        if(arr[i] > v)
        {
            std::swap(arr[i], arr[gt-1]);
            gt--;
        }
        else if(arr[i] < v)
        {
            std::swap(arr[lt+1], arr[i]);
            lt++;
            i++;
        }
        else
            i++;
    }
    std::swap(arr[l], arr[lt]);

    quick_sort3_ways(arr, l, lt-1);
    quick_sort3_ways(arr, gt, r);
}

template<typename T>
void quick_sort_way3(T arr[], int n)
{
    srand(time(NULL));
    quick_sort3_ways(arr, 0, n-1);
}