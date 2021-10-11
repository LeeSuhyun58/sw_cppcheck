void foo(char *str) //외부에서 들어오는 입력 = 신뢰할 수 없음
{
    char *buf = new char[8];//8바이트 메모리 할당
    strcpy(buf,str);
    /*외부 입력인 str을 buf에 복사
     이때 str의 길이가 8바이트 이상일 수 있음*/

    FILE* file = fopen("out.txt", "w"); //fopen(), fclose() 반드시 
    if(!file) return;
    //그냥 return하면 함수는 사라지지만 할당 받은 8바이트는 남아있음 -> oprphan M

    for(char* c = buf; *c; c++){ //buf = str
        fputc((int)*c, file); 
        //c가 가리키는 위치의 값을 file에 put
    }

    delete buf; //new로 받은게 배열이므로 delete도 배열로 해야함 -> delete [] buf
    //fclose(file); 필요
}