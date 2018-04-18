// -*- coding:utf-8 -*-
// author:phenix3443
// desc: 各种版本的单例模式实现

// 单线程版本
class Singleton
{
public:
        Singleton();
        virtual ~Singleton();
};

// 以下是多线程安全版本
// 懒汉模式
class LazySingleton
{
public:
        LazySingleton();
        virtual ~LazySingleton();
};

// 饿汗模式

// 最佳实现
class BestSingleton
{
public:
        virtual ~BestSingleton() {}

private:
        BestSingleton() {}
};
