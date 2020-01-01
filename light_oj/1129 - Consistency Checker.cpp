#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct node
{
    bool mark ;
    node *points[10] ;
    node()
    {
        mark=false ;
        for(ll i=0 ; i<10 ; i++)
            points[i]=NULL ;
    }
} *root ;

bool insert_and_search(char *ch , ll length , node *current)
{
    ll i , a , count=0 ;
    for(i=0 ; i<length ; i++)
    {
        a=ch[i]-48 ;
        if(current->points[a]==NULL)
            current->points[a]=new node() ;
        else count++ ;
        current=current->points[a] ;
        if(current->mark==true)
            return false ;
    }
    if(count==strlen(ch))
        return false ;
    current->mark=true ;
    return current->mark ;
}

void del(node *a)
{
   // node *b=a ;
    ll i ;
    for(i=0 ; i<10 ; i++)
        if(a->points[i])
            del(a->points[i]) ;
    delete(a) ;
}

int main()
{
    ll loop , test , a , b , c ;
    bool cheak ;
    char ch[1000] ;
    scanf("%lld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        root=new node() ;
        cheak=true ;
        scanf("%lld",&a) ;
        char cc=getchar() ;
        for(b=1 ; b<=a ; b++)
        {
            gets(ch) ;
         //printf("   %s\n",ch) ;
            if(cheak==true)
                cheak=insert_and_search(ch,strlen(ch),root) ;
        }
        if(cheak==true) printf("Case %lld: YES\n",loop) ;
        else printf("Case %lld: NO\n",loop) ;
        del(root) ;
    }
    return 0 ;
}
