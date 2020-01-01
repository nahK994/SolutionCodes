#include<stdio.h>
#include<string.h>

int main()
{
    long loop , test , a , b , month , year , month1 , year1 ;
    char c , ch[50] , ch1[50] ;
    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        scanf("%s%ld%c%ld",ch,&month,&c,&year) ;
        scanf("%s%ld%c%ld",ch1,&month1,&c,&year1) ;
        if(strcmp(ch,"January")==0 || strcmp(ch,"February")==0) year-- ;
        if(strcmp(ch1,"January")==0 || (strcmp(ch1,"February")==0 && month1!=29)) year1-- ;
        year=(year/4)-(year/100)+(year/400) ;
        year1=(year1/4)-(year1/100)+(year1/400) ;
        printf("Case %ld: %ld\n",loop,year1-year) ;
    }
    return 0 ;
}
