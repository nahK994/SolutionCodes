#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std ;
long par[200000] ;
long find(long n)
{
    if(par[n]==n) return n ;
    return par[n]=find(par[n]) ;
}
int main()
{
    long test , successful , unsuccessful , a , b , node , j , i ;
    char ch[1000] , ch1 ;
    cin>>test ;
    int space=0;
    while(test--)
    {
        cin>>node ;
        ch1=getchar() ;
        successful=0 ;
        unsuccessful=0 ;
        for(a=0 ; a<=node ; a++) par[a]=a ;
        while(gets(ch))
        {
            //cout<<strlen(ch)<<endl ;
            j=1 ;
            a=b=0 ;
            if(strlen(ch)==0) break ;
            sscanf(ch+2,"%ld %ld",&a,&b);
            //cout<<ch<<" "<<a<<" "<<b<<endl ;
            if(ch[0]=='c')
            {
                a=find(a) ;
                b=find(b) ;
                par[a]=b ;
            }
            else
            {
                if(find(a)==find(b))
                    successful++ ;
                else
                    unsuccessful++ ;
            }
            memset(ch,0,sizeof(ch)) ;
        }
        if(space)
            printf("\n");
        space=1;
        cout<<successful<<","<<unsuccessful<<endl ;
        memset(par,0,sizeof(par)) ;
    }
    return 0 ;
}
