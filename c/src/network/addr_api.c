/* coding:utf-8 */
/* socket地址相关测试 */

#include <stdio.h>
#include <arpa/inet.h>          /* htonl 系列函数 */

int main(int argc, char *argv[])
{
    printf("%04x\n",0x0102);    /* 小端 */
    printf("%04x\n",htons(0x0102));
    return 0;
}
