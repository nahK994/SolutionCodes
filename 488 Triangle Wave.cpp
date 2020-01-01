#include<stdio.h>

int main ()

{
    int i , j ;
    scanf("%d",&j) ;
    for(i=1 ; i<=j ; i++)
    {
        int a , b , x , y , z , d , p , q ;
        scanf("%d%d",&a,&b) ;
        if(i!=1)
        printf("\n") ;
        for(x=1 ; x<=b ; x++)
        {
           d=1 ;
           for(y=1 ; y<=a ; y++)
           {
               for(z=1 ; z<=y ; z++)
                  printf("%d",d) ;
                  printf("\n") ;
                  d++ ;
           }
           d=d-2 ;
           for(p=a-1 ; p>=1 ; p--)
           {
               for(q=1 ; q<=p ; q++)
                   printf("%d",d) ;
                   printf("\n") ;
                   d-- ;
           }
           if(x<b)
           printf("\n") ;
        }
    }
    return 0 ;
}
