#include<stdio.h>
#include<algorithm>

using namespace std ;

int main ()

{
    int i , j , c , d , ara1[3005] , ara2[3005] ;
    while(scanf("%d",&j)!=EOF)
    {
    for(i=0 ; i<j ; i++)
    scanf("%d",&ara1[i]) ;
    for(c=0 ; c<j-1 ; c++)
    {
        if(ara1[c]-ara1[c+1]>0)
        ara2[c]=ara1[c]-ara1[c+1] ;
        else ara2[c]=-1*(ara1[c]-ara1[c+1]) ;
    }
    sort(ara2,ara2+j-1) ;
    for(d=0 ; d<j-1 ; d++)
    {
        if(ara2[d]!=d+1)
        {
            printf("Not jolly\n") ;
            break ;
        }
    }
     if(d==j-1)
     printf("Jolly\n") ;
    }
    return 0 ;
}
