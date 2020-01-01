#include<bits/stdc++.h>
using namespace std;
long  n, m, coloredNode[500], pairNode[500];
vector<long>adj[500], V;

bool bpm(long a)
{
   // printf("%ld\n",a);
    if(coloredNode[a]) return false;
    coloredNode[a]=1;
    for(long i=0 ; i<adj[a].size() ; i++)
           if( pairNode[adj[a][i]]==-1 || bpm(pairNode[adj[a][i]]) )
           {
                   pairNode[ adj[a][i] ]=a;
                   return true;
           }
           return false;
}

int main()
{
    long loop, test, a, b, c, S, D, i, j ;
    char ch[500][500];
    scanf("%ld",&test);
    for(loop=1 ; loop<=test ; loop++)
    {
        scanf("%ld%ld",&n,&m);
        memset(pairNode, -1, sizeof pairNode);
        V.clear();
        for(a=0 ; a<=n*m ; a++)
            adj[a].clear();
        for(a=0  ; a<n ; a++)
            scanf("%s",ch[a]);

       // printf("D\n");
        for(i=0 ; i<n ; i++)
            for(j=0 ; j<m ; j++)
                if(ch[i][j]=='*')
                {
                    long aaa=i*m+j;
                    V.push_back(aaa);
                    if(i-1>=0 && ch[i-1][j]=='*')
                        adj[aaa].push_back((i-1)*m+j);
                    if(i+1<n && ch[i+1][j]=='*')
                        adj[aaa].push_back((i+1)*m+j);
                    if(j-1>=0 && ch[i][j-1]=='*')
                        adj[aaa].push_back(i*m+j-1);
                    if(j+1<m && ch[i][j+1]=='*')
                        adj[aaa].push_back(i*m+j+1);
                }

        long count1=0, count2=0;
         for(i=0 ; i<V.size() ; i++)
            {
                memset(coloredNode, 0, sizeof coloredNode);
                if(bpm(V[i])) count1++;
                else count2++;
            }
        printf("Case %ld: %ld\n",loop,(count1/2)+count2);
    }
    return 0;
}
/*
4
7 9
ooo**oooo
**oo*ooo*
o*oo**o**
ooooooooo
*******oo
o*o*oo*oo
*******oo
10 1
*
*
*
o
*
*
*
*
*
*
5 8
oo**oooo
*oo*ooo*
******oo
*o*oo*oo
******oo
3 4
**oo
**oo
*oo*
*/

