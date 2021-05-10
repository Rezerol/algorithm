#include <iostream>
#include <cmath>
#include <ctime>
#include <cassert>

#include "BinarySearch.h"
#include "MyUtil.h"

using namespace std;

MyUtil* g_my_util = new MyUtil();

int main()
{
    int n = 1000000;
    int* data = g_my_util->generate_ordered_array(n);

    clock_t start_time = clock();
    for(int i = 0; i < n; i++)
        assert(i == binary_search(data, n, i));
    clock_t end_time = clock();

    cout << "binary search test complete." << endl;
    cout << "Time cost:" << double(end_time - start_time)/CLOCKS_PER_SEC << "s" << endl;
}