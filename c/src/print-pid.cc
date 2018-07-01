#include <stdio.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    printf("process ID=%ld\n", (long)getpid());
    return 0;
}
