#include <stdio.h>

int main(){
    int B[5];
    int O[5];
    int T[5];
    int i = 0;

    for(int i = 0; i<5; i++){
        scanf("%d", &B[i]);
    }

    do{
        O[i] = 1-B[i];
        i++;
    }while(i<5);

    i = 4;
    int C = 1;
    do {
        T[i] = 1;
        if(O[i] == C){
            T[i] = 0;
        }

        C *= O[i];
        i--;
    } while(i>=0); 

    for(int j = 0; j<5; j++){
        printf("%d ", T[j]);
    }
}