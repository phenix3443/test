// -*- coding:utf-8 -*-
// author:liushangliang
// desc: string模拟
// doc: https://coolshell.cn/articles/10478.html
#include <cstring>
#include <utility>

class String
{
public:
        //! Default constructor
        String():data(new char[1]) {
                *data = '\0';
        }

        //! Copy constructor
        // 由于涉及到资源动态分配，考察类拷贝控制成员的三五原则
        String(const String &rhs) : data(new char[strlen(rhs.data) + 1]){
                strcpy(data, rhs.data);
        }

        //! Copy assignment operator
        // 考察点：自赋值
        // Traditional:
        // String& operator= (const String& rhs) {
        //         String tmp(rhs);
        //         swap(tmp);
        //         return *this;
        // }

        String& operator= (const String rhs) { // 注意pass-by-value避免了自赋值
                swap(rhs);
                return *this;
        }

        //! Destructor
        virtual ~String() {
                delete []data;
        }
        // 以下是C++11新特性String (String &&rhs) : data (rhs.data) { rhs.data = nullptr; }

    String &operator= (String &&rhs) {
        swap (rhs);
        return *this;
    }

    void swap (String &rhs) { std::swap (data, rhs.data); }

    String (const char *str) : data (new char[strlen (str) + 1]) {
        strcpy (data, str);
    }

  private:
    char *data;
};
