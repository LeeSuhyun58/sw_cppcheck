#include <stdio.h>

extern char** environ; //환경변수로 사용되는 전역변수

void main(int argc, char* argv[], char* envp[]){
    int i = 0;
    char* v[2];
    char* newenv[3];

    if(argc < 2) return;
    v[0] = "/usr/bin/env";
    v[1] = NULL;
    newenv[0] = "AAA=aaa";
    newenv[1] = "BBB=bbb";
    newenv[2] = NULL;
    switch(argv[1][0]){
        case '2':
            execve(v[0], v, newenv);
            break;
        case '3':
            execve(v[0], v, environ);
            break;
        default:
            execve(v[0], v, NULL);
            break;
    }
}