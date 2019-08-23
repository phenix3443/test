/* -*- coding:utf-8 -*- */
/* 测试libevent可全局调用的变量和函数 */
#include <stdio.h>
#include <event2/event.h>

int main(int argc, char *argv[])
{
    printf("version: %s\n", event_get_version());

    printf("supported methods:\n");
    const char **methods =  event_get_supported_methods();
    for (int i=0; methods[i] != NULL; ++i) {
        printf("%s\n",methods[i]);
    }

    struct event_base *base = event_base_new();
    printf("current use: %s\n", event_base_get_method(base));

    event_base_free(base);
    return 0;
}
