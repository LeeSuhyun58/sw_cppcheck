void f1(struct fred_t *p)
{
    //dereference p and then check if it't NULL
    int x = p->x; 
    if(p){
        do_something(x);
    }
    //p가 가리키는 값을 x에 넣은 후
    //if문으로 p에 값이 있는지 없는지 점검 -> do something ?

    /*if(p){
        do_something(x);
        int x = p->x;
    } -> 점검 먼저하고 do something(x)*/ 
}