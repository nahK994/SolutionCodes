#include<iostream>
#include<string.h>
using namespace std ;

long fac(long n)
{
    long i , j=1 ;
    for(i=1 ; i<=n ; i++)
        j=j*i ;
    return j ;
}

int main()
{
    long loop , test , N , A ;
    cin>>test ;
    for(loop=1 ; loop<=test ; loop++)
    {
        A=1 ;
        char ch1[1000] , ch2[1000] ;
        cin>>ch1 ;
        for(long i=0 ; i<strlen(ch1) ; i++)
            ch2[i]=1 ;
        N=strlen(ch1) ;
        N=fac(N) ;
        for(long a=0 ; a<strlen(ch1)-1 ; a++)
        {
            if(strcmp(ch1,ch2)==0)
                break ;
            if(ch1[a]==1)
                continue ;
            for(long b=a+1 ; b<strlen(ch1) ; b++)
                if(ch1[a]==ch1[b])
                {
                    A++ ;
                    ch1[b]=1 ;
                }
            A=fac(A) ;
            N=N/A ;
            A=1 ;
          //  cout<<ch1<<endl ;
            ch1[a]=1 ;
        }
        cout<<N<<endl ;
    }
    return 0 ;
}

