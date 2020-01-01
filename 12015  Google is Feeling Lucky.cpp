#include<stdio.h>

int main()
{
    long a , i , j , loop , test , max , ara[10] ;
    char ch[10][100] ;
    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        max=0 ;
        for(i=0 ; i<10 ; i++)
        {
            scanf("%s %ld",ch[i],&ara[i]) ;
            if(ara[i]>max) max=ara[i] ;
        }
        printf("Case #%ld:\n",loop) ;
        for(i=0 ; i<10 ; i++)
        if(ara[i]==max)
        printf("%s\n",ch[i]) ;
    }
    return 0 ;
}
