#include<stdio.h>
#include<stack>
#include<string.h>

using namespace std ;

int main()
{
    long loop , test , a , b , c , i , ara[50] ;
    char ch[1000] , as[30]  , d , ans[1000] ;
    stack<char>s ;
    ara['/']=4 ;
    ara['*']=3 ;
    ara['+']=2 ;
    ara['-']=1 ;
      ara['(']=ara[')']=0 ;
    scanf("%ld",&test) ;
    d=getchar() ;
    d=getchar() ;
    for(loop=1 ; loop<=test ; loop++)
    {
        if(loop>1) printf("\n") ;
        i=0 ;
        while(gets(as) && strlen(as)!=0)
        {
            if(as[0]>='0' && as[0]<='9') ans[i++]=as[0] ;
            else if(as[0]!=')' && as[0]!='(')
            {
                if(as[0]>='0' && as[0]<='9') ans[i++]=as[0] ;
                else if((s.empty()==false && ara[s.top()]<=ara[as[0]]) || s.empty()==true)
                    s.push(as[0]) ;
                else if(s.empty()==false && ara[s.top()]>ara[as[0]])
                {
                    ans[i++]=s.top() ;
                    s.pop() ;
                    s.push(as[0]) ;
                }
            }
            else if(as[0]=='(' || (s.empty()==false && s.top()=='('))
                s.push(as[0]) ;
            else if(as[0]==')')
            {
                  while(s.top()!='(')
                  {
                      ans[i++]=s.top() ;
                      s.pop() ;
                  }
                  s.pop() ;
            }
        }
        while(s.empty()==false)
        {
            ans[i++]=s.top() ;
            s.pop() ;
        }
        ans[i]=0 ;
        printf("%s\n",ans) ;
    }
    return 0 ;
}
