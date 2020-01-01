#include<stdio.h>
#include<string.h>

int main()
{
    long long loop , test , sum , i , j , ara[100] , position[100] , error , bigger , smaller ;
    char ch[1000] ;
    ara['B']=1 ;
    ara['U']=10 ;
    ara['S']=100 ;
    ara['P']=1000 ;
    ara['F']=10000 ;
    ara['T']=100000 ;
    ara['M']=1000000 ;
   // printf("%lld\n",ara[66]) ;
    scanf("%lld",&test) ;
    char as=getchar() ;
    for(loop=1 ; loop<=test ; loop++)
    {
        error=bigger=smaller=sum=0 ;
        position['B']=position['U']=position['S']=position['P']=0 ;
        position['F']=position['T']=position['M']=0 ;
        gets(ch) ;
        sum+=ara[ch[0]] ;
        position[ch[0]]++ ;
        for(i=1 ; i<strlen(ch) ; i++)
        {
            sum+=ara[ch[i]] ;
            position[ch[i]]++ ;
            if(ara[ch[i]]-ara[ch[i-1]]>0) bigger++ ;
            else if(ara[ch[i]]-ara[ch[i-1]]<0) smaller++ ;
            if(position[ch[i]]>9 || (bigger>0 && smaller>0))
            {
                error=1 ;
                break ;
            }
        }
        if(error==0) printf("%lld\n",sum) ;
        else printf("error\n") ;
    }
    return 0 ;
}
