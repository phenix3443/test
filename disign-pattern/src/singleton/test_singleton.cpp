#include<iostream>

#include<unistd.h>
#include<cstdlib>

#include "safe_singleton.hpp"

class test{// 测试对象
public:
        void show(){
                std::cout<<"show()"<<std::endl;
        }
};


int main(){
        test& p=Singleton<test>::instance();// 注意使用方法
        p.show();
        test& q=Singleton<test>::instance();
        if(&p==&q)
                std::cout<<"Singleton success"<<std::endl;
        else
                std::cout<<"Singleton failure"<<std::endl;
        return 0;
}
