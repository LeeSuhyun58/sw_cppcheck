#include <stdio.h>

void func2(int D){
    int T[32] = {0};
    int M, N, i=0;

    do {
        M = D / 2;
        N = D % 2;
        T[i] = N;
        i++;
        D = M;
    } while(M>=2);

    T[i] = M;

    printf("10->2: ");
    for(int j = 31; j>=0; j--){
        printf("%d",T[j]);
    }
    printf("\n");
    
}

void func8(int D){
    int T[11] = {0};
    int M, N, i=0;

    do {
        M = D / 8;
        N = D % 8;
        T[i] = N;
        i++;
        D = M;
    } while(M>=8);

    T[i] = M;

    printf("10->8: ");
    for(int j = 10; j>=0; j--){
        printf("%d",T[j]);
    }
    printf("\n");
}

void func16(int D){
    int T[8] = {0};
    int M, N, i=0;

    do {
        M = D / 16;
        N = D % 16;
        T[i] = N;
        i++;
        D = M;
    } while(M>=16);

    T[i] = M;

    printf("10->16: ");
    for(int j = 7; j>=0; j--){
        printf("%d",T[j]);
    }
    printf("\n");
}

int main(){
    int D; //입력 받을 정수 예 :3,-3

    printf("input: ");
    scanf("%d", &D);

    if(D>0){
        func2(D);
        func8(D);
        func16(D);
    }
    else{
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
        int Bin[32] = {1};
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
        printf("\n"); //B[32] = 2의 보수 1011 1111 1111 1111 1111 1111 1111 1111 
        
        //------------------------------------------------ 8진수

        int R = 1; //공비 2
        int j = 0;
        int cnt = 0, sum = 0, h = 0;
        int eig[11];

        do{
            sum += Bin[j]*R;
            R *=2;
            j++;
            cnt++;

            if(cnt == 3){
                eig[h] = sum;
                h++;

                sum = 0;
                cnt = 0;
                R = 1; // 전부 초기화
            }

        } while(j<30);

        j = 30;

        for(j=30; j<32; j++){
            sum += Bin[j]*R;
            R *=2;
        }

        eig[h] = sum;

        printf("10->8: ");
        for(int a=10; a>=0; a--){
            printf("%d", eig[a]);
        }
        printf("\n");

        //------------------------------------------------- 16진수

        R = 1; //공비 2
        int q = 0;
        cnt = 0, sum = 0, h = 0;
        char H[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
        char si[8];

        do{
            sum += Bin[q]*R;
            R *=2;
            q++;
            cnt++;

            if(cnt == 4){
                si[h] = H[sum];
                h++;

                sum = 0;
                cnt = 0;
                R = 1; // 전부 초기화
            }

        } while(q<32);

        printf("10->16: ");
        for(int a=7; a>=0; a--){
            printf("%C", si[a]);
        }
        printf("\n");

    }
}