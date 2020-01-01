#include<bits/stdc++.h>
using namespace std ;
#define ll long long
ll ara[40] , limit , W , Count , n ;
vector<ll> V , V1 ;
void rec(ll a, ll sum , bool flag)
{
    if(a == limit+1)
    {
        if(flag) V.push_back(sum) ;
        else V1.push_back(sum) ;
        return ;
    }
    rec(a+1,sum,flag) ;
    if(sum+ara[a] <= W)
        rec(a+1,sum+ara[a],flag) ;
}

ll bs(ll a)
{
    ll i , j , mid , left=0 , right=V1.size()-1 , ans ;
    while(left<=right)
    {
        mid=(left+right)/2 ;
        if(V1[mid] > a)
            right=mid-1 ;
        else if(V1[mid] <= a)
            {
                left=mid+1 ;
                ans=mid ;
            }
    }
    return ans+1 ;
}

int main()
{
    ll loop , test , a , b ;
    scanf("%lld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        Count=0 ;
        scanf("%lld%lld",&n,&W) ;
        for(a=0 ; a<n ; a++)
            scanf("%lld",&ara[a]) ;

        limit=n/2 ;
        rec(0,0,true) ;
        limit=n-1 ;
        rec((n/2)+1,0,false) ;

        sort(V.begin(),V.end()) ;
        sort(V1.begin(),V1.end()) ;

        /*printf("%lld",V[0]) ;
        for(a=1 ; a<V.size() ; a++)
            printf(" %lld",V[a]) ;
        printf("\n") ;
        printf("%lld",V1[0]) ;
        for(a=1 ; a<V1.size() ; a++)
            printf(" %lld",V1[a]) ;
         printf("\n") ;*/

        for(a=0 ; a<V.size() ; a++)
             Count+=bs(W-V[a]) ;

        printf("Case %lld: %lld\n",loop,Count) ;
        V.clear() ;
        V1.clear() ;
    }
}
