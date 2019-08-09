// -*- coding:utf-8 -*-
// author:liushangliang
// desc: 语言特性整体描述

#include <iostream>
#include <string>

using namespace std;

void say(string message) {
    cout << message << endl;
}

const string message = "hello,world!";

int main(int argc, char *argv[])
{
    say(message);
    return 0;
}
