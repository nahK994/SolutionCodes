#include<stdio.h>
#include<deque>
#include<string.h>
using namespace std ;

int main()
{
    deque<long>Q ;
    long loop , test , i , n , j , size , count ;
    char ch[50] ;
    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        count=0 ;
        printf("Case %ld:\n",loop) ;
        scanf("%ld%ld",&size,&n) ;
        for(i=1 ; i<=n ; i++)
        {
            scanf("%s",ch) ;
            if(strcmp(ch,"pushLeft")==0 || strcmp(ch,"pushRight")==0)
            {
                scanf("%ld",&j) ;
                if(strcmp(ch,"pushLeft")==0 && count<size)
                {
                    count++ ;
                    Q.push_front(j) ;
                    printf("Pushed in left: %ld\n",j) ;
                }
                else if(strcmp(ch,"pushRight")==0 && count<size)
                {
                    count++ ;
                    Q.push_back(j) ;
                    printf("Pushed in right: %ld\n",j) ;
                }
                else
                    printf("The queue is full\n") ;
            }
            else
            {
                if(strcmp(ch,"popLeft")==0 && count>0)
                {
                    count-- ;
                    j=Q.front() ;
                    Q.pop_front() ;
                    printf("Popped from left: %ld\n",j) ;
                }
                else if(strcmp(ch,"popRight")==0 && count>0)
                {
                    count-- ;
                    j=Q.back() ;
                    Q.pop_back() ;
                    printf("Popped from right: %ld\n",j) ;
                }
                else printf("The queue is empty\n") ;
            }
        }
        while(!Q.empty())
        Q.pop_front() ;
    }
    return 0 ;
}
