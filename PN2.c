#include <stdio.h>

void main(){
    int N = 2, p = 0;

    for(N = 2; N<=100; N++){
        int CNT =0;
        for(int i = 1; i<=N; i++){
            if(N%i == 0){
                CNT++;
            }
        }
        if(CNT == 2){
            p = N;
        }
    }

    printf("%d\n", p);
}