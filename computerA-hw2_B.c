#include <stdio.h>

//컴퓨터알고리즘 과제2 - B(5,5)

int main(){

    int B[5][5] = {0,0};
    int R = -1, C = 0; // R은 행 변수, C는 열 변수
    int V = 1, i = 0;

    while(i < 4) // i 값이 4인 경우 while문 탈출
    //(0,0) -> (1,0), (0,1) -> (0,2), (1,1), (2,0) ->...
    //열의 값을 기준으로 열의 값이 0이면 R = R + 1, C = 0으로 시작
    {
        if(C == 0) { //C = 0인 경우, R은 감소하고 C는 증가
            R = R + 1;
            i = R;
            
            while(1){
                B[i][C] = V;
                V = V + 1;
                i = i - 1;
                if(i < 0) break;
                else C = C + 1;
            }
        }
        
        if(C > 0){ //C가 0이 아닌 경우, C = C + 1, R = 0의 규칙을 가짐
        //R은 증가하고 C는 감소
            C = C + 1; 
            R = 0;
            i = R;
            while(1){
                B[i][C] = V;
                V = V + 1;
                C = C - 1;
                if(C < 0) break;
                else {
                    i = i + 1;
                    R = i;
                }
            }
            C = 0;
        }
    }

    // i = 4이므로 R값도 4
    R = 4;
    C = 0;

    while(C < 4) //(4,1), (3,2), (2,3), (1,4) -> (2,4), (3,3), (4,2) ->...
    //R을 기준으로 R = 4인 경우와 그렇지 않은 경우로 나눔
    {
        if(R == 4) { //R = 4인경우
            C = C + 1;
            i = R;
            while(1){
                B[i][C] = V;
                V = V + 1;
                C = C + 1;
                if(C > 4) break;
                else {
                    i = i - 1;
                    R = i;
                } 
            }

        }
        
        if(R != 4){ //R != 4인 경우
            C = 4;
            R = R + 1;
            i = R;
            while(1){
                B[i][C] = V;
                V = V + 1;
                i = i + 1;
                if(i > 4) break;
                else {
                    R = i;
                    C = C - 1;
                }
            }
        }

    }
    
    for(int i =0; i<5; i++){
        for(int j =0; j<5; j++){
            printf(" %-3d ", B[i][j]);
        }
        printf("\n");
    }

    return 0;
}