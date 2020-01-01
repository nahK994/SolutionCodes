
#include<stdio.h>
int main()
{
    struct student
    {
        char name[100] ;
        long mark ;
        long roll ;
    } ;
    student v[1000] ;
    long i , j , a , b , c , d ;
    scanf("%ld",&j) ;
    char o=getchar() ;
    for(i=0 ; i<j ; i++)
    {
        //gets(v[i].name) ;
        scanf("%s",v[i].name) ;
        scanf("%ld",&v[i].roll) ;
        scanf("%ld",&v[i].mark) ;
    }
    for(a=0 ; a<j ; a++)
    {
        c=v[a].mark ;
        for(b=0 ; b<j ; b++)
        {
            if(c<v[b].mark)
            {
                c=v[b].mark ;
                d=b ;
            }
        }
        printf("%ld %ld %s %ld\n",a+1,v[d].roll,v[d].name,v[d].mark) ;
        v[d].mark=0 ;
      //  c=0;
    }
    return 0 ;
}
