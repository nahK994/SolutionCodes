#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std ;

char beverage[110][110] ;
long node , edge , indegree[110] , ara[110][110] ;
vector<long>V ;

void ini()
{
    for(long i=1 ; i<=node ; i++)
        indegree[i]=0 ;
    for(long i=1 ; i<=node ; i++)
        for(long j=1 ; j<=node ; j++)
            ara[i][j]=0 ;
}

int main()
{
    long i , j , m , n , a , N=1 ;
    char ch1[100] , ch2[100] ;
    while(cin>>node)
    {
        ini() ;
        for(i=1 ; i<=node ; i++)
            cin>>beverage[i] ;


        cin>>edge ;
        for(i=1 ; i<=edge ; i++)
        {
            scanf("%s %s",ch1,ch2) ;
            for(j=1 ; j<=node ; j++)
                if(strcmp(ch1,beverage[j])==0)
                {
                    m=j ;
                    break ;
                }
            for(j=1 ; j<=node ; j++)
                if(strcmp(ch2,beverage[j])==0)
                {
                    n=j ;
                    break ;
                }
                ara[m][n]=1 ;
              //  cout<<m<<" "<<n<<endl ;
        }
        for(i=1 ; i<=node ; i++)
        for(j=1 ; j<=node ; j++)
        if(ara[j][i]==1)
        indegree[i]++ ;
        do
        {
            for(i=1 ; i<=node ; i++)
            {
                if(indegree[i]==0)
                {
                    V.push_back(i) ;
                    indegree[i]=-1 ;
                    for(j=1 ; j<=node ; j++)
                    if(ara[i][j]==1)
                    indegree[j]-- ;
                    break ;
                }
            }
        }
        while(V.size()<node) ;

        cout<<"Case #"<<N<<": Dilbert should drink beverages in this order: " ;
        for(i=0 ; i<V.size()-1 ; i++)
        {
            a=V[i] ;
            cout<<beverage[a]<<" " ;
           // cout<<a<<" " ;
        }
        a=V[i] ;
        cout<<beverage[a]<<"."<<endl<<endl ;
       //cout<<a<<endl ;
        N++ ;
        for(i=1 ; i<=node ; i++)
        V.pop_back() ;
    }
    return 0 ;
}
