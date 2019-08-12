// -*- coding:utf-8 -*-
// author:phenix3443
// desc: 线程安全的单例模式

#include<pthread.h>
#include<boost/noncopyable.hpp>

template<typename T>
class Singleton : boost::noncopyable
{
public:
        static T& instance(){
                pthread_once(&ponce, &Singleton::init);
                return *value;
        }

private:
        Singleton();
        ~Singleton();

        static void init() {
                // 这里只能调用 T 的默认构造函数，若要用户指定 T 的构造方式，可能需要模板特化value = new T ();
    }

  private:
    static pthread_once_t ponce;
    static T* value;
};

template <typename T> pthread_once_t Singleton<T>::ponce = PTHREAD_ONCE_INIT;

template <typename T> T* Singleton<T>::value = NULL;
