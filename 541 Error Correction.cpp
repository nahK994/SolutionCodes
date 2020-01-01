#include<stdio.h>
#include<string.h>

int main()
{
    long cor , n , i , j , sum , row , coloum , ara[200][200] ;
    while(scanf("%ld",&n)!=EOF)
    {
        if(n==0) break ;
        row=coloum=-1 ;
        cor=0 ;
        for(i=0 ; i<n ; i++)
            for(j=0 ; j<n ; j++)
                scanf("%ld",&ara[i][j]) ;
        for(i=0 ; i<n ; i++)
        {
            sum=0 ;
            for(j=0 ; j<n ; j++) sum+=ara[i][j] ;   // row cheaking ........
            if(sum%2!=0)
            {
                cor++ ;
                row=i+1 ;
            }
            if(cor>1) break ;
        }
        if(cor<=1)
        {
            cor=0 ;
            for(i=0 ; i<n ; i++)
            {
                sum=0 ;
                for(j=0 ; j<n ; j++) sum+=ara[j][i] ;   // coloum cheaking ........
                if(sum%2!=0)
                {
                    cor++ ;
                    coloum=i+1 ;
                }
                if(cor>1) break ;
            }
        }
        if(row==-1 && coloum==-1) printf("OK\n") ;
        else if(cor>1) printf("Corrupt\n") ;
        else printf("Change bit (%ld,%ld)\n",row,coloum) ;
        for(i=0 ; i<n ; i++) memset(ara[i],0,sizeof(ara[i])) ;
    }
    return 0 ;
}
