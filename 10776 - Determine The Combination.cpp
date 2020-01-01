#include <iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
#define MAX 30+5
using namespace std;


bool taken[MAX] ;
vector<char>res ;
string s ;
int r ,len , color[100][150] ;
void call(int start)
{

    if(res.size()==r )
    {
        int j ;
        for(j=0; j<r; j++)  cout<<res[j] ;
        cout<<endl ;
        return ;
    }

    for(int i=start; i<len; i++)
        if(taken[i]==false && color[start][s[i]]==0)
        {
            color[start][s[i]] = 1 ;
            taken[i] = true ;
            res.push_back(s[i]) ;
            call(i+1) ;
            taken[i] = false ;
            res.pop_back() ;
        }
      //  while(s[i]==s[i+1]) i++ ;

    memset(color[start] , 0 , sizeof color[start]) ;

}


int main()
{
    memset(color, 0, sizeof color) ;
    while(cin>>s>>r)
    {
        memset(taken,false,sizeof(taken)) ;
        len = s.length() ;
        sort(s.begin(),s.end()) ;
        call(0) ;
    }

    return 0;
}
