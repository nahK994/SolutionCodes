#include<stdio.h>

int main ()

{
    int i , j , n , b ;
    scanf("%d",&j) ;
    printf("Lumberjacks:\n") ;
    for(i=1 ; i<=j ; i++)
    {
        int a , ara[10]={0} ;
        for(a=0 ; a<10 ; a++)
        scanf("%d",&ara[a]) ;
        if(ara[0]>ara[1]) n=1 ;
        else n=2 ;
        switch(n)
        {
            case 1 :
            {
                for(b=0 ; b<9 ; b++)
                if(ara[b]<ara[b+1]) break ;
                if(b==9) printf("Ordered\n") ;
                else printf("Unordered\n") ;
                break ;
            }
            default :
            {
                for(b=0 ; b<9 ; b++)
                if(ara[b]>ara[b+1]) break ;
                if(b==9) printf("Ordered\n") ;
                else printf("Unordered\n") ;
                break ;
            }
        }
    }
    return 0 ;
}
