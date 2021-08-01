#include <iostream>
#include <algorithm>
#include <string>
#include <cassert>

using namespace std;

template<typename Item>
class MaxHeap
{
private:
    Item* m_data;
    int m_size;
    int m_capacity;
private:
    void shift_up(int index)
    {
        while(index > 1 && m_data[index/2] < m_data[index])
        {
            std::swap(m_data[index/2], m_data[index]);
            index = index/2;
        }
        //std::cout << "shift_up data[" << index << "] = " << m_data[index] << endl;
    }

    void shift_down(int index)
    {
        while(2*index <= m_size)
        {
            int j = 2*index;
            if(j+1 <= m_size && m_data[j+1] > m_data[j])
                j++;
            
            if(m_data[index] >= m_data[j])
                break;
            
            std::swap(m_data[index], m_data[j]);
            index = j;
        }
    }

    void resize(int new_capacity)
    {
        assert(new_capacity >= m_size);
        Item* new_data = new Item[new_capacity+1];
        for(int i = 0; i < m_size+1; i++)
        {
            new_data[i] = m_data[i];
        }
        delete [] m_data;
        m_data = new_data;
        m_capacity = new_capacity;
    }

    void putNumberInLine( int num, string &line, int index_cur_level, int cur_tree_width, bool isLeft){

        int sub_tree_width = (cur_tree_width - 1) / 2;
        int offset = index_cur_level * (cur_tree_width+1) + sub_tree_width;
        assert(offset + 1 < line.size());
        if( num >= 10 ) {
            line[offset + 0] = '0' + num / 10;
            line[offset + 1] = '0' + num % 10;
        }
        else{
            if( isLeft)
                line[offset + 0] = '0' + num;
            else
                line[offset + 1] = '0' + num;
        }
    }

    void putBranchInLine( string &line, int index_cur_level, int cur_tree_width){

        int sub_tree_width = (cur_tree_width - 1) / 2;
        int sub_sub_tree_width = (sub_tree_width - 1) / 2;
        int offset_left = index_cur_level * (cur_tree_width+1) + sub_sub_tree_width;
        assert( offset_left + 1 < line.size() );
        int offset_right = index_cur_level * (cur_tree_width+1) + sub_tree_width + 1 + sub_sub_tree_width;
        assert( offset_right < line.size() );

        line[offset_left + 1] = '/';
        line[offset_right + 0] = '\\';
    }
public:
    MaxHeap(int capacity)
    {
        m_data = new Item[capacity+1];
        m_size = 0;
        m_capacity = capacity;
    }

    MaxHeap(Item arr[], int n)
    {
        m_data = new Item[n+1];
        for(int i = 0; i < n; i++)
            m_data[i+1] = arr[i];
        m_capacity = n;
        m_size = n;
        for(int i = m_size/2; i >=1; i--)
            shift_down(i);
    }
    ~MaxHeap()
    {
        delete [] m_data;
    }

    int size()
    {
        return m_size;
    }

    bool is_empty()
    {
        return m_size == 0;
    }

    void insert(Item item)
    {
        if(m_size == m_capacity)
            resize(2*m_capacity);
        m_data[m_size+1] = item;
        m_size++;
        shift_up(m_size);
    }

    Item pop_back()
    {
        assert(m_size > 0);
        Item res = m_data[1];
        std::swap(m_data[1], m_data[m_size]);
        m_size--;
        shift_down(1);
        return res;
    }

    // 以树状打印整个堆结构
    void testPrint(){

        // 我们的testPrint只能打印100个元素以内的堆的树状信息
        if( size() >= 100 ){
            cout<<"This print function can only work for less than 100 int";
            return;
        }

        // 我们的testPrint只能处理整数信息
        if( typeid(Item) != typeid(int) ){
            cout <<"This print function can only work for int item";
            return;
        }

        cout<<"The max heap size is: "<<size()<<endl;
        cout<<"Data in the max heap: ";
        for( int i = 1 ; i <= size() ; i ++ ){
            // 我们的testPrint要求堆中的所有整数在[0, 100)的范围内
            assert( m_data[i] >= 0 && m_data[i] < 100 );
            cout<<m_data[i]<<" ";
        }
        cout<<endl;
        cout<<endl;

        int n = size();
        int max_level = 0;
        int number_per_level = 1;
        while( n > 0 ) {
            max_level += 1;
            n -= number_per_level;
            number_per_level *= 2;
        }

        int max_level_number = int(pow(2, max_level-1));
        int cur_tree_max_level_number = max_level_number;
        int index = 1;
        for( int level = 0 ; level < max_level ; level ++ ){
            string line1 = string(max_level_number*3-1, ' ');

            int cur_level_number = min(m_size-int(pow(2,level))+1,int(pow(2,level)));
            bool isLeft = true;
            for( int index_cur_level = 0 ; index_cur_level < cur_level_number ; index ++ , index_cur_level ++ ){
                putNumberInLine( m_data[index] , line1 , index_cur_level , cur_tree_max_level_number*3-1 , isLeft );
                isLeft = !isLeft;
            }
            cout<<line1<<endl;

            if( level == max_level - 1 )
                break;

            string line2 = string(max_level_number*3-1, ' ');
            for( int index_cur_level = 0 ; index_cur_level < cur_level_number ; index_cur_level ++ )
                putBranchInLine( line2 , index_cur_level , cur_tree_max_level_number*3-1 );
            cout<<line2<<endl;

            cur_tree_max_level_number /= 2;
        }
        cout<<endl;
    }
};

template<typename T>
void heap_sort1(T arr[], int n)
{
    MaxHeap<T> max_heap = MaxHeap<T>(n);
    for(int i = 0; i < n; i++)
        max_heap.insert(arr[i]);
    
    for(int i = n-1; i >= 0; i--)
        arr[i] = max_heap.pop_back();
}

template<typename T>
void heap_sort2(T arr[], int n)
{
    MaxHeap<T> max_heap = MaxHeap<T>(arr, n);
    
    for(int i = n-1; i >= 0; i--)
        arr[i] = max_heap.pop_back();
}

template<typename T>
void shit_down(T arr[], int n, int index)
{
    T e = arr[index];
    while(2*index + 1 < n)
    {
        int j = 2*index+1;
        if(j+1 < n && arr[j+1] > arr[j])
            j = j+1;
            
        if(arr[index] >= arr[j])
            break;
            
        arr[index] = arr[j];
        index = j;
    }
    arr[index] = e;
}

template<typename T>
void heap_sort(T arr[], int n)
{
    for(int i = (n-1-1)/2; i >=0; i--)
    {
        shit_down(arr, n, i);
    }

    for(int i = n-1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        shit_down(arr, i, 0);
    }
}