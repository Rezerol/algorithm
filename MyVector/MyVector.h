#include <iostream>
#include <cassert>

template<typename T>
class MyVector
{
public:
    MyVector()
    {
        data = new T[10];
        capacity = 10;
        m_size = 0;
    }
    MyVector(int n)
    {
        data = new T[n];
        capacity = n;
        m_size = 0;
    }
    ~MyVector()
    {
        delete[] data;
    }

    int size()
    {
        return m_size;
    }

    bool is_empty()
    {
        return m_size == 0;
    }

    void push_back(T e)
    {
        if(m_size == capacity)
        {
            resize(2*capacity);
        }
        data[m_size++] = e;
    }

    T pop_back()
    {
        assert(m_size > 0);
        T res = data[m_size - 1];
        m_size --;
        if(m_size == capacity/4)
        {
            resize(capacity/2);
        }
        
        return res;
    }
private:
    void resize(int new_capacity)
    {
        assert(new_capacity >= m_size);
        T* new_data = new T[new_capacity];
        for(int i = 0; i < m_size; i++)
        {
            new_data[i] = data[i];
        }
        delete[] data;

        capacity = new_capacity;
        data = new_data;
    }
private:
    T* data;
    int capacity;    //数组大小；
    int m_size;        //数组中元素个数；

};