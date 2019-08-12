// -*- coding:utf-8 -*-
// author:liushangliang
// desc: 语言特性整体描述

#include <iostream>
#include <string>

using namespace std;

void say (string message) { cout << message << endl; }

class Pserson {
  private:
    string name;
};

const string message = "hello,world!";

int main (int argc, char *argv[]) {
    if (true) {
    }
    int a = 1;
    string bbbb = "hello";
    say (message);
    return 0;
}
