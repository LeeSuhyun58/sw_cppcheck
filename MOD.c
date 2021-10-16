#include <stdio.h>

void main(){
    int a[10] = {21, 17, 4, 51, 24, 75, 40, 27, 48, 72};

    int CNT = 0;

    for(int i = 0; i<10; i++){
        if((a[i]%3 + a[i]%4) == 0){
            CNT++;
        }
    } 

    printf("%d\n", CNT);
}