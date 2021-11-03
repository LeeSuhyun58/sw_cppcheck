#include <stdio.h>

int main(){

    int CNT = 0;

    for(int N = 4; N <=500; N++){
        int SUM = 0;
        for(int i = 1; i<N; i++){
            if(N%i == 0) SUM += i;
        }
        if(N == SUM){
            printf("N = %d\n", N);
            CNT++;
        }
    }
    printf("CNT = %d\n", CNT);
}