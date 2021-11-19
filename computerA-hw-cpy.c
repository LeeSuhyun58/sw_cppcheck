#include <stdio.h>

void func2(int D){
    int T[32] = {};
    int M, N, i=0;

    do {
        M = D / 2; //M = 몫
        N = D % 2; //N = 나머지(N = D-M*2와 동일)
        T[i] = N;
        i++;
        D = M;
    } while(M>=2);

    T[i] = M;
    int k = i;

    printf("10->2: "); //반대로 출력하기 위해 k값을 i로 설정
     do{
        printf("%d", T[k]);
        k--;
    }while(k>=0);
    printf("\n");
}

void func8(int D){
    int T[32] = {};
    int M, N, i=0;

    do {
        M = D / 8;
        N = D % 8;
        T[i] = N;
        i++;
        D = M;
    } while(M>=8);

    T[i] = M;
    int k = i;

    printf("10->8: ");
    do{
        printf("%d", T[k]);
        k--;
    }while(k>=0);
    printf("\n");
}

void func16(int D){
    char H[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    char T[32] = {}; 
    int M, N, i=0;

    do {
        M = D / 16;
        N = D % 16;
        T[i] = H[N];
        i++;
        D = M;
    } while(M>=16);

    T[i] = H[M];
    int k = i;

    printf("10->16: ");
    do{
        printf("%c", T[k]);
        k--;
    } while(k>=0);
    printf("\n");
}

int Bin[32];
int* func12(int D){
    
    int T[32] = {0};
        int M, N, i=0;
        do{
            M = D / 2;
            N = D % 2;
            T[i] = N;
            i++;
            D = M;
        } while(M>=2);

        T[i] = M; // 2진수로 바꿈 1100 0000 0000 0000 0000 00000 0000 0000

        int O[32];
        int k = 0;

        do{
            O[k] = 1 - T[k]; 
            k++;
        } while(k<32);//0011 1111 1111 1111 1111 1111 1111 1111 

        k=0;
        int Carry = 1;

        do{
            Bin[k] = 1;
            if (O[k] == Carry){
                Bin[k] = 0;
            }
            Carry = O[k]*Carry;
            k++;
        } while(k<32);

        printf("10->2: ");
        for(int a=31; a>=0; a--){
            printf("%d", Bin[a]);
        }
        printf("\n");

        return Bin;
}

void func128(int Bin[]){
    int R = 1; //2진수를 10진수로 바꾸려면 각 자리에 2^0 *(비트0,1) + 2^1*(비트 0,1) + 2^2*()... 2를 공비로 판단
    int j = 0;
    int cnt = 0, sum = 0, h = 0; 
    //3비트마다의 초기화가 필요 = cnt, 각 비트를 10진수로 바꾼 값의 합 = sum, 8진수 배열 인덱스 = h
    int eig[11];

    do{
        sum += Bin[j]*R;
        R *=2;
        j++;
        cnt++;

        if(cnt == 3){ //32비트를 3비트씩 나눠 계산 
            eig[h] = sum; //10진수로 바꾼 값의 합을 eig[]에 넣음
            h++;//다음 eig[] 배열 위치를 위해 증가

            sum = 0;
            cnt = 0;
            R = 1; // 전부 초기화
        }

    } while(j<30);//32비트를 3비트로 나눈 몫이 10이므로 30까지만 작업

    j = 30;
    for(j=30; j<32; j++){ //나머지 30,31의 2자리 비트는 따로 계산
        sum += Bin[j]*R;
        R *=2;
    }
    eig[h] = sum;

    printf("10->8: ");
    for(int a=10; a>=0; a--){
        printf("%d", eig[a]);
    }
    printf("\n");

}

void func1216(int Bin[]){
    int R = 1; 
    int j = 0;
    int cnt = 0, sum = 0, h = 0;
    char H[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    // 16진법의 수를 담고 있는 배열 = H[16]
    char si[8];

    do{
        sum += Bin[j]*R;
        R *=2;
        j++;
        cnt++;

        if(cnt == 4){
            si[h] = H[sum];
            h++;

            sum = 0;
            cnt = 0;
            R = 1; // 전부 초기화
        }

    } while(j<32);

    printf("10->16: ");
    for(int a=7; a>=0; a--){
        printf("%c", si[a]);
    }
    printf("\n");

}

int main(){
    int inputN; //입력 받을 정수 예 :3,-3
    printf("input: ");
    scanf("%d", &inputN);

    if(inputN>0){ //입력되는 input값이 양수인 경우
        func2(inputN);
        func8(inputN);
        func16(inputN);
    }
    else{ //입력된 input값이 음수인 경우
        int* BIN = func12(inputN); //2진수 2의 보수
        func128(BIN); //8진수로 변환
        func1216(BIN); //16진수로 변환
    }
}