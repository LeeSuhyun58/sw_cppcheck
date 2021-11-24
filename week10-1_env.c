#include <stdio.h>

extern char** environ; //환경변수로 사용되는 전역변수

void main(int argc, char* argv[], char* envp[]){
    int i = 0;
    while(environ[i] != NULL){ 
        printf("%s\n", environ[i++]);
    }
}