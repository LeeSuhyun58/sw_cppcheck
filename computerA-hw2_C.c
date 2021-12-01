#include <stdio.h>

//컴퓨터알고리즘 과제2 - C(5,5)

int main(){

    int C[5][5];
    int V = 26;
    int S = 1, i = 0, j = -1; //s는 행과 열의 증감용 변수, i는 열 변수, j는 행 변수
    int K = 5; //배열에 숫자를 배정하는 수행 횟수에 대한 변수

    while(1)
    {
        for(int P = 0; P<K; P++){
            V = V - 1;
            j = j + S;
            C[j][i] = V; //열 우선 -> i 고정
        }
        K = K - 1;
        if( K <= 0) break;
        for(int P = 0; P<K; P++){
            V = V - 1;
            i = i + S;
            C[j][i] = V; //행 우선 -> j 고정
        }
        S = S*(-1); //-1값을 곱함에 따라 행과 열이 증감하는 것을 표현
    }

   
    for(int i =0; i<5; i++){
        for(int j =0; j<5; j++){
            printf("%-3d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}