#include <stdio.h>
#include <math.h>

void main(){

    int p = 2;
    int N = 5;
    while(1){
        int M = (int)sqrt((double)N);
        for(int i = 2; i<=M; i++){
            int R = N%i;
            if(R==0){
                break;
            }
            if(i == M){ // i = M일 때까지 0이 아니라면 소수라는 의미
                p = N;
            }
        }
        N++;
        if(N > 100) break;
    }
   
    printf("%d\n", p);
}