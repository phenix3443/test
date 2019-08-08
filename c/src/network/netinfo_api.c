/* coding;utf-8 */
/* 测试网络信息api */

#include <stdio.h>

#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    struct hostent* ent = gethostbyname("www.baidu.com");

    printf("host_name: %s\n", ent->h_name);

    for(char** p_alias = ent->h_aliases; *p_alias != NULL; p_alias++) {
        printf("host alias:%s\n", *p_alias);
    }

    for(char** p_addr = ent->h_addr_list; *p_addr != NULL; p_addr++) {
        char ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, (void *)*p_addr, ip, INET_ADDRSTRLEN);
        printf("host ip:%s\n", ip);
    }

    struct servent* s_ent = getservbyname("www", "tcp");

    printf("server name: %s\n", s_ent->s_name);
    for(char** p_alias=s_ent->s_aliases; *p_alias != NULL; p_alias++) {
        printf("server alias:%s\n",*p_alias);
    }
    return 0;
}
