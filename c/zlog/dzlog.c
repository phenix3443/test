/* -*-coding:utf-8 *- */
/* 测试dzlog各个级别的日志打印 */

#include <stdio.h>
#include <zlog.h>

int main(int argc, char *argv[])
{
    dzlog_init("/home/lsl/github/test/c/zlog/zlog.conf", "my_cat");
    dzlog_info("info log in dzlog");

    return 0;
}
