/* coding:utf-8 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAXLINE 4096

int main(int argc, char *argv[]) {
    char buff[MAXLINE];
    printf("%% ");
    while (fgets(buff, MAXLINE, stdin) != NULL) {
        if (buff[strlen(buff) - 1] == '\n') {
            buff[strlen(buff) - 1] = 0;
        }
        pid_t pid = fork();
        if (pid < 0) {
            printf("fork child error\n");
            exit(-1);
        } else if(pid ==0) {    /* child */
            execlp(buff,buff,(char*)0);
            exit(0);
        }
        int status;
        if((pid = waitpid(pid,&status,0))<0){
            printf("waitpid error\n");
            exit(-1);
        }
        printf("%% ");
    }

    return 0;
}
