#include<stdio.h>
#include<string.h>
int main()
{
    long max , min, i , j , loop , test , min_ad , max_ad , a , b , c ;
    char ch[103][50] ;
    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        max=-1 , min=1000003 ;
        scanf("%ld",&j) ;
        for(i=0 ; i<j ; i++)
        {
              scanf("%s%ld%ld%ld",ch[i],&a,&b,&c) ;
              if(min>a*b*c)
              {
                  min=a*b*c ;
                  min_ad=i ;
              }
              if(max<a*b*c)
              {
                  max=a*b*c ;
                  max_ad=i ;
              }
        }
        if(max==min) printf("Case %ld: no thief\n",loop) ;
        else printf("Case %ld: %s took chocolate from %s\n",loop,ch[max_ad],ch[min_ad]) ;
        for(i=0 ; i<j ; i++)
        ch[i][0]=0 ;
    }
    return 0 ;
}
