#include <ctime>
#include <cmath>

#include "merge_sort.h"
#include "quick_sort.h"
#include "insertion_sort.h"
#include "selection_sort.h"
#include "heap_sort.h"
#include "sort_test_helper.h"

using namespace std;

void test_max_heap()
{
    MaxHeap<int> max_heap = MaxHeap<int> (20);
    srand(time(NULL));
    for(int i = 0; i < 10; i++)
        max_heap.insert(rand()%20);
    max_heap.testPrint();
    
    while(!max_heap.is_empty())
        cout << max_heap.pop_back() << " ";
    cout << endl;
}


int main()
{
    //test_max_heap();

    int n = 1000000;

    // 测试1 一般性测试
    cout<<"Test for random array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
    int* arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int* arr2 = SortTestHelper::copyIntArray(arr1, n);
    int* arr3 = SortTestHelper::copyIntArray(arr1, n);
    int* arr4 = SortTestHelper::copyIntArray(arr1, n);
    int* arr5 = SortTestHelper::copyIntArray(arr1, n);
    int* arr6 = SortTestHelper::copyIntArray(arr1, n);
    int* arr7 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", merge_sort_way, arr1, n);
    SortTestHelper::testSort("Quick Sort", quick_sort_way1, arr2, n);
    SortTestHelper::testSort("Quick Sort 2 Ways", quick_sort_way2, arr3, n);
    SortTestHelper::testSort("Quick Sort 3 Ways", quick_sort_way3, arr4, n);
    SortTestHelper::testSort("Heap Sort 1", heap_sort, arr5, n);
    //SortTestHelper::testSort("Heap Sort 2", heapSort2, arr6, n);
    //SortTestHelper::testSort("Heap Sort 3", heapSort, arr7, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;

    cout<<endl;
    return 0;
}