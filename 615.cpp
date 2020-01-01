#include <bits/stdc++.h>

using namespace std;
#define MAX 110

vector <int> adj[MAX];
int color[MAX] , par[MAX] , child[MAX];

void dfs(int u)
{
    int i , v;
    color[u] = 1;
    for(i=0;i<adj[u].size();i++)
    {
        v = adj[u][i];
        if(color[v]==0)
        {
            dfs(v);
        }
    }
}

int main()
{
    int x , y;
    map<int , int > mp;
    int a , b , i ,j,k,l , tatal,index,flag,cnt;
    int d1,d2 ,d3;
    int t_c = 1;
    while(scanf("%d%d",&x,&y)==2)
    {
        flag = 0;
        index= 1;
        d2=d3=0;
        for(k=0;k<MAX;k++)
        {
            adj[k].clear();
            mp.clear();
        }
        l = 0;
        memset(color , 0 , sizeof(color));
        //memset(dist , 0, sizeof(color));
        memset(par , -1 , sizeof(par));
        memset(child , 0 , sizeof(child));

        cnt = 0;

        if(x<0 && y<0)
            break;
        if(x==0 && y==0)
        {
            printf("Case %d is a tree.\n",t_c);
            t_c++;
            continue;
        }


        if(!mp[x])
            mp[x] = index++;
        if(!mp[y])
            mp[y] = index++;
            a = mp[x];
            b = mp[y];
            if(a==b)
                flag =1;
            par[b] = a;
            child[b]++;
            //printf("%d %d\n",a,b);
            adj[a].push_back(b);

        while(scanf("%d%d",&x,&y)!=EOF)
        {
            if(x==0 && y == 0)
                {
                    break;
                }
            if(!mp[x])
                mp[x] = index++;
            if(!mp[y])
                mp[y] = index++;
            a = mp[x];
            b = mp[y];
            if(a==b)
                flag =1;
            par[b] = a;
            child[b]++;
            //printf("%d %d\n",a,b);
            adj[a].push_back(b);
            //cnt++;
        }
        //printf("%d\n",index);
        for(i=1;i<index;i++)
        {
            if(child[i]==2)
                flag = 1;
                //printf("%d ",child[i]);
        }
        if(flag==0)
        {
            for(i=1;i<index;i++)
            {
                if(par[i]==-1)
                {
                    cnt++;
                    d1 = i;
                }
            }
            //printf("cnt == %d\n",cnt);
            if(cnt==0 ||cnt == 2)
                printf("Case %d is not a tree.\n",t_c);
            else
            {
                dfs(d1);
                for(i=1;i<index;i++)
                {
                    if(color[i]==0)
                        d2=1;
                }
                if(d2==1)
                    printf("Case %d is not a tree.\n",t_c);
                else printf("Case %d is a tree.\n",t_c);
            }
        }
        else printf("Case %d is not a tree.\n",t_c);
        t_c++;
    }
}
