#include<stdio.h>
#include<string.h>

int main()
{
    long n , year[200] , month[200] , date[200] , i , min , max , maxi , mini ;
    char ch[200][20] ;
    while(scanf("%ld",&n)!=EOF)
    {
        max=0 ;
        min=9999999 ;
        for(i=0 ; i<n ; i++)
        {
            scanf("%s %ld %ld %ld",ch[i],&date[i],&month[i],&year[i]) ;
            if(max<year[i])
            {
                max=year[i] ;
                maxi=i ;
            }
            else if(year[i]==max)
            {
                if(month[i]>month[maxi])
                    maxi=i ;
                else if(month[i]==month[maxi])
                {
                    if(date[i]>date[maxi]) maxi=i ;
                }
            }
            if(min>year[i])
            {
                min=year[i] ;
                mini=i ;
            }
            else if(year[i]==min)
            {
                if(month[i]<month[mini])
                    mini=i ;
                else if(month[i]==month[mini])
                {
                    if(date[i]<date[mini]) mini=i ;
                }
            }
        }
        printf("%s\n%s\n",ch[maxi],ch[mini]) ;
        memset(year,0,sizeof(year)) ;
        memset(month,0,sizeof(month)) ;
        memset(date,0,sizeof(date)) ;
    }
    return 0 ;
}
