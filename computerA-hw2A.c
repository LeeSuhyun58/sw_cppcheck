#include <stdio.h>

int main(){

    int A[5][5];
    int k = 0;

    for(int SPIN=0;SPIN <9;SPIN++)
    {  //0~8 : 9회전 : 대각선
            for(int i=0;i<5;i++)
            { //0~4 : 5회전 : 행
                int j=SPIN-i; //열                
                if(j>=0&&j<5){ //0보다 크거나 같고 5보다 작은 경우에
                    k=k+1;
                    A[j][i] = k;
                }
            }          
    }

    for(int i =0; i<5; i++){
        for(int j =0; j<5; j++){
            printf(" %-3d ", A[i][j]);
        }
        printf("\n");
    }

    return 0;
}