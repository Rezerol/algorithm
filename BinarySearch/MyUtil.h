#include <cassert>

class MyUtil
{
public:
    int *generate_ordered_array(int n)
    {
        assert(n > 0);
        int *arr = new int[n];
        for(int i = 0; i < n; i++)
            arr[i] = i;
        return arr;
    }
};