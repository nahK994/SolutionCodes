#include<stdio.h>
#include<string.h>

char ch[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ" , ans[50] ;
long color[50] , N , K , count ;

void backtrack(long a)
{
    long i , j ;
    if(a==N)
    {
        printf("%s\n",ans) ;
        ans[N-1]='\0' ;
        count++ ;
        return ;
    }
    for(i=0 ; i<N ; i++)
    {
        if(count==K) break ;
        if(color[i]==0)
        {
            ans[a]=ch[i] ; ans[a+1]='\0' ;
            color[i]=1 ;
            backtrack(a+1) ;
            color[i]=0 ;
        }
    }
}

int main()
{
    long a , i , loop , test ;
    scanf("%ld",&test) ;
    //printf("%o\n",test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        count=0 ;
        scanf("%ld%ld",&N,&K) ;
        for(i=0 ; i<N ; i++) color[i]=0 ;
        printf("Case %ld:\n",loop) ;
        ans[0]='\0' ;
        backtrack(0) ;
    }
    return 0 ;
}
