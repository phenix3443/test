/* -*- coding:utf-8 -*- */

#include <stdio.h>
#include <event2/event.h>


int main(int argc, char *argv[])
{
    printf("%s\n", event_get_version());

    const char **methods =  event_get_supported_methods();
    for (int i=0; methods[i] != NULL; ++i) {
        printf("%s\n",methods[i]);
    }

    struct event_base *evb = event_base_new();
    printf("%s\n", event_base_get_method(evb));
    event_base_free(evb);
    return 0;
}
