void foo(char *str)//외부 입력
{
    char buf[8];
    strcpy(buf, "Hello world!");//buf의 크기보다 문자열의 길이가 김

    printf("foo says %d\n", buf);//출력 format이 맞지 않음
}