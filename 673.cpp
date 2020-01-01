#include<stdio.h>
#include<string.h>
#include<stack>

using namespace std ;

int main()
{
    long loop , test , a , i , true_value , left , right ;
    stack<char>s ;
    char ch[1000] , asd ;
    scanf("%ld",&test) ;
    char as=getchar() ;
    for(loop=1 ; loop<=test ; loop++)
    {
        true_value=1 ; left=right=0 ;
        gets(ch) ;
        //printf("ans = %s\n",ch) ;
        for(i=0 ; i<strlen(ch) ; i++)
        {
            if(ch[i]==')' || ch[i]=='}' || ch[i]==']')
            {
                right++ ;
                if(s.empty()==false)
                    asd=s.top() ;
                else asd='1' ;
                if((ch[i]!=asd+1 && ch[i]==')') || (ch[i]!=asd+2 && (ch[i]=='}' || ch[i]==']')))
                {
                    true_value=0 ;
                    break ;
                }
                else s.pop() ;
            }
            else
            {
                s.push(ch[i]) ; left++ ;
            }
        }
        if(true_value==1 && left==right) printf("Yes\n") ;
       // else if(strlen(ch)==0) printf("Yes\n") ;
        else printf("No\n") ;
        while(s.empty()==false) s.pop() ;
    }
   /*  printf(" ( = %ld ) = %ld\n",'(',')') ;
     printf(" { = %ld } = %ld\n",'{','}') ;
     printf(" [ = %ld ] = %ld\n",'[',']') ;*/
    return 0 ;
}
