#include<bits/stdc++.h>
using namespace std ;
#define ll long long
ll ara[40] , limit , W , n ;
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
    if(sum+2*ara[a] <= W)
        rec(a+1,sum+2*ara[a],flag) ;
}

bool bs(ll a)
{
    ll i , j , mid , left=0 , right=V1.size()-1 ;
    while(left<right)
    {
        mid=(left+right)/2 ;
        if(V1[mid] > a)
            right=mid-1 ;
        else if(V1[mid] < a)
            left=mid+1 ;
       else return true ;
            //printf("D\n") ;
    }
    return a == V1[left] ;
}

int main()
{
    ll loop , test , a , b ;
    scanf("%lld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        scanf("%lld%lld",&n,&W) ;
        for(a=0 ; a<n ; a++)
            scanf("%lld",&ara[a]) ;

        limit=n/2 ;
        rec(0,0,true) ;
        limit=n-1 ;
        rec((n/2)+1,0,false) ;

        sort(V.begin(),V.end()) ;
        sort(V1.begin(),V1.end()) ;

        for(a=0 ; a<V.size() ; a++)
            if(bs(W-V[a]))
                break ;

         if(a != V.size()) printf("Case %lld: Yes\n",loop) ;
        else printf("Case %lld: No\n",loop) ;

        V.clear() ;
        V1.clear() ;
    }
}
