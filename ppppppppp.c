#include<stdio.h>
int main ()
{
    long ara1[3][3] , ara2[3][3] , ara3[3][3] ;
    long i , j , a , b , c , d , m1 , n1 , m2 , n2 ;
    while(scanf("%ld%ld%ld%ld",&m1,&n1,&m2,&n2)!=EOF)
    {
    printf("\n") ;
    if(m2!=n1)
    {
        printf("Not valid\n") ;
        continue ;
    }
    for(a=0 ; a<m1 ; a++)
    for(b=0 ; b<n1 ; b++)
    scanf("%ld",&ara1[m1][n1]) ;
    printf("\n") ;
   /* for(a=0 ; a<m1 ; a++)
    {
        for(b=0 ; b<n2 ; b++)
        printf("%ld ",ara1[a][b]) ;
        printf("\n") ;
    }*/
    for(a=0 ; a<m2 ; a++)
    for(b=0 ; b<n2 ; b++)
    scanf("%ld",&ara2[m2][n2]) ;
    for(a=0 ; a<m1 ; a++)
    for(b=0 ; b<n2 ; b++)
    ara3[a][b]=0 ;
    for(a=0 ; a<m1 ; a++)
    {
        for(b=0 ; b<n2 ; b++)
        {
            for(c=0 ; c<n1 ; c++)
            ara3[a][b]=ara3[a][b]+(ara1[a][c]*ara2[c][b]) ;
        }
    }
    printf("\n") ;
    for(a=0 ; a<m1 ; a++)
    {
        for(b=0 ; b<n2 ; b++)
        printf("%ld ",ara3[a][b]) ;
        printf("\n") ;
    }
   }
   return 0 ;
}
