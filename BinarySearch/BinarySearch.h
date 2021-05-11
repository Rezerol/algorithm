template<typename T>
int binary_search(T arr[], int n, int target)
{
    int l = 0, r = n - 1;   //find target in [l, r]
    while(l <= r)
    {
        //int mid = (l + r) / 2;  //l+r may out of the range of int
        int mid = l + (r-l)/2; 
        if(arr[mid] == target)
        {
            return mid;
        }
        else if(arr[mid] < target)  //target in [mid+1, r]
        {
            l = mid + 1;
        }
        else        //target is in [l, mid-1]
        {
            r = mid - 1;
        }
    }

    return -1;
}