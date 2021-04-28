#include "MyVector.h"

using namespace std;

int main()
{
    MyVector<int> vec(100);
    int n = 100000;
    cout << "before, vec size:" << vec.size() << endl;
    for(int i = 0; i < n; i++)
    {
        vec.push_back(i);
    }
    cout << "after push, vec size:" << vec.size() << endl;
    for(int i = 0; i < n; i++)
    {
        vec.pop_back();
    }
    cout << "after pop, vec size:" << vec.size() << endl;


    return 0;
}