#include <stdio.h>

int main(){
    int A[10] = {131, 450, -100, 150, 50, -10, 0, 40, 32, 1};

    int Mincha = 533;
    int N = 0, Ans = N;
    int cha = 0;

    do{
        if(A[N] >= 33){
            cha = A[N] - 33;
        }
        else cha = 33 - A[N];

        if(cha < Mincha){
            Mincha = cha;
            Ans = N;
        }
        N++;
    } while(N<10);

    printf("%d\n", Ans+1);
}