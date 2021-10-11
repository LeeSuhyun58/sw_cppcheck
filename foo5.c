void f3(int a)
{
    struct fred_t *p = NULL;
    if(a==1){
        p = fred1; //a가 1이 아닌 경우 p는 계속 NULL
    }

    //if a is not 1 then p is NULL
    p->x = 0; //p는 NULL이므로 p->x가 성립이 되지 않음 = 프로그램 종료
}