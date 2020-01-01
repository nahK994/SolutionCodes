#include<bits/stdc++.h>
using namespace std ;

bool vis[100] , no ;
vector<char>charecters , relations[110] ;
long len ;

bool valid(char ch)
{
    for(int i=0 ; i<relations[ch].size() ; i++)
        if(vis[relations[ch][i]]) return false ;
    return true ;
}

void backtrack(string ans)
{
    if(ans.size() == len)
        {
            no=false ;
            cout<<ans[0] ;
            for(int i=1 ; i<ans.size() ; i++)
                cout<<" "<<ans[i] ;
            cout<<endl ;
            return ;
        }

       for(int i=0 ; i<charecters.size() ; i++)
       {
           char c=charecters[i] ;
           if(!vis[c])
           {
               vis[c]=true ;
               if(valid(c))
                    backtrack(ans+c) ;
               vis[c]=false ;
           }
       }
}

int main()
{
    long test , loop , i , j ;
    char s[100] ;
    scanf("%ld",&test) ;
    getchar() ;
   memset(vis,0,sizeof vis) ;

    for(loop=1 ; loop<=test ; loop++)
    {
        if(loop>1) printf("\n") ;
        gets(s) ;
        gets(s) ;
        no=true ;

        for(i=0 ; i<strlen(s) ; i++)
            if(isalpha(s[i]))
                charecters.push_back(s[i]) ;
        len=charecters.size() ;
        sort(charecters.begin(),charecters.end()) ;

        gets(s) ;
        for(i=0 ; i<strlen(s) ;)
            if(isalpha(s[i]) and s[i+1] == '<' and isalpha(s[i+2]))
                {
                    relations[s[i]].push_back(s[i+2]) ;
                    i+=4 ;
                }

        backtrack("") ;
        if(no) printf("NO\n") ;

        charecters.clear() ;
        for(i=0 ; i<110 ; i++)
            relations[i].clear() ;
    }
}
