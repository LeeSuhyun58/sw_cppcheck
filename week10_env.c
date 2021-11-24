#include <stdio.h>

void main(int argc, char* argv[], char* envp[]){
    //3번쨰 argument -> 환경변수를 접근할 수 있는 첫번쨰 방법
    int i = 0;
    while(envp[i] != NULL){ //envp값이 존재한다면 계속해서 출력
        printf("%s\n", envp[i++]);
    }
}