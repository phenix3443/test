/* -*-coding:utf-8 *- */
/* 测试zlog各个级别的日志打印 */

#include <zlog.h>
#include <stdio.h>

int main(int argc, char *argv[])
{

    int rc = zlog_init("/home/lsl/github/test/c/zlog/zlog.conf");
    if (rc) {
        printf("init zlog failed!\n");
        return -1;
    }

    zlog_category_t *logger = zlog_get_category("my_cat");
    if (!logger) {
        printf("get logger failed\n");
        zlog_fini();
        return -1;
    }

    zlog_info(logger, "hello,zlog");

    zlog_fini();

    return 0;
}
