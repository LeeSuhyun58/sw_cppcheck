char f2(char *str)
{
    const char *p = NULL;

    for(int i=0; str[i] !='\0'; i++){
        if(str[i]==' '){ //str에 빈칸이 없는 경우 -> p는 계속 NULL
            p = str + i;
            break;
        }
    }
    return p[1]; //NULL + 1 = NULL
}