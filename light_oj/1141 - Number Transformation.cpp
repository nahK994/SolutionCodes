#include<bits/stdc++.h>
using namespace std ;

long s  ,t , dist[2000] ;
bool prime[1002] ;
vector<long>V[1005] , prime_V ; ;
queue<long>Q ;

long nextPrime(long a)
{
    while(!prime[++a]) ;
    return a ;
}

void sieve()
{
    long i , j ;
    for(i=2 ; i<=1000 ; i+=2)
        {
            prime[i-1]=true ;
            prime[i]=false ;
        }
    prime[1]=false ;
    prime[2]=true ;

    for(i=3 ; i<=1000 ; i=nextPrime(i))
    {
        for(j=i*i ; j<=1000 ; j+=i)
            prime[j]=false ;
    }

    for(i=1 ; i<=1000 ; i++)
        if(prime[i])
        prime_V.push_back(i) ;

      /*  printf("size = %ld\n",prime_V.size()) ;
        for(i=0 ; i<prime_V.size() ; i++)
            printf("%ld\n",prime_V[i]) ;*/
}

long bfs()
{
    long a , b ;
    memset(dist,-1,sizeof dist) ;
    Q.push(s) ;
    dist[s]=0 ;
    while(!Q.empty())
    {
        a=Q.front() ;
        Q.pop() ;
        if(a == t) break ;
        for(b=0 ; b<V[a].size() ; b++)
            if(dist[ a+V[a][b] ] == -1 && a+V[a][b] <= t)
            {
                Q.push(a+V[a][b]) ;
                dist[ a+V[a][b] ] = dist[a]+1 ;
            }
    }
    while(!Q.empty())
        Q.pop() ;
    return dist[t] ;
}

int main()
{
    long loop , test , a , b , c ;
    sieve() ;
    for(a=0 ; a<prime_V.size() ; a++)
            for(b=2*prime_V[a] ; b<=1002 ; b+=prime_V[a])
            V[b].push_back(prime_V[a]) ;

    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        scanf("%ld%ld",&s,&t) ;
        printf("Case %ld: %ld\n",loop,bfs()) ;
    }
    return 0 ;
}
