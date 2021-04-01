#include <mutex>
#include <iostream>
#include <atomic>

//饿汉方式
class SingletonA
{
public:
    static SingletonA* get_instance(){return instance;}
private:
    SingletonA(){}

private:
    static SingletonA* instance;
};

SingletonA* SingletonA::instance = new SingletonA();


//考虑多个non-local static对象依赖同一个单例时，初始化顺序不保证的情况
//另一种饿汉模式写法
class SingletonB
{
public:
    static SingletonB& get_instance()
    {
        static InstanceCreator creator;    //有non-local static对象依赖时确保初始化顺序。
        return *m_instance;
    }
private:
    SingletonB();
    SingletonB(const SingletonB & single);

    struct InstanceCreator        //真正负责单例的构造
    {
        InstanceCreator()
        {
            SingletonB::m_instance = new SingletonB();
        }

        ~InstanceCreator()
        {
            delete SingletonB::m_instance;
            SingletonB::m_instance = nullptr;
        }
    };

    struct InstanceConfirm    //没有non-loacl static对象依赖时，保证在main函数前初始化
    {
        InstanceConfirm()
        {
            SingletonB::get_instance();
        }
    };

private:
    friend class InstanceCreator;
    friend class InstanceConfirm;
    static SingletonB* m_instance;
    static InstanceConfirm* m_confirm;    //最后保证main函数之前完成初始化
};


//考虑线程安全及内存访问顺序问题
//有些内存模型由于编译器优化等原因，无法保证单例初始化完成后才被调用
//懒汉模式
class SingletonC;

class SingletonC
{
public:
    static SingletonC & get_instance()
    {
        if(m_instance == nullptr)     //DCL:Double Check Lock
        {
            std::unique_lock lock(m_mx);   //保证线程安全
            if(m_instance == nullptr)
            {
                m_instance = new SingletonC();
            }
        }
        return *m_instance;
    }
private:
    SingletonC();
    SingletonC(const SingletonC &);
private:
    static std::atomic<SingletonC *> m_instance(nullptr); //atomic保证不同线程无法在修改期间获取该对象
    static std::mutex m_mx;
};

//Meyers’ Singleton
class SingletonD;

class SingletonD
{
public:
    static SingletonD & get_instance()
    {
        static SingletonD instance;  //C++11标准下local static对象初始化在多线程条件下安全
        return instance;
    }
private:
    SingletonD();
    SingletonD(const SingletonD &);
private:
    //other private members

};