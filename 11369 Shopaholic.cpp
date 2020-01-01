#include<stdio.h>
#include<algorithm>

using namespace std;

int main ()

{
    int i , j ;
    scanf("%d",&j) ;
    for(i=1 ; i<=j ; i++)
    {
        int a , b , c ;
        scanf("%d",&c) ;
        int ara[c] ;
        for(a=0 ; a<c ; a++)
        scanf("%d",&ara[a]) ;
        sort(ara,ara+c) ;
        printf("%d\n",ara[c-1]) ;
    }
    return 0 ;
}
