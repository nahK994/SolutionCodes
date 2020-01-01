#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std ;

int main()
{
    long loop , test , count , sum1 , sum2 , weight , i , a , b ;
    queue<long>left , right ;
    char ch[10] , p ;
    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
       count=0 ;
       scanf("%ld%ld",&weight,&a) ;
       weight*=100 ;
       while(a--)
       {
           scanf("%ld%s",&b,ch) ;
           if(ch[0]=='l') left.push(b) ;
           else right.push(b) ;
       }
       while(1)
       {
          // printf("L") ;
               sum1=0 ;
               while(left.empty()==false && sum1+left.front()<=weight)
                   {
                        sum1+=left.front() ; left.pop() ;//printf("L\n") ;
                   }
               count++ ;
               if(left.empty()==true && right.empty()==true) break ;
               sum2=0 ;
               while(right.empty()==false && sum2+right.front()<=weight)
                   {
                        sum2+=right.front() ; right.pop() ;//printf("R\n") ;
                   }
               count++ ;
               if(left.empty()==true && right.empty()==true) break ;
       }
       printf("%ld\n",count) ;
    }
    return 0 ;
}
