#include<bits/stdc++.h>
using namespace std;

bool visited[30][30][30];
vector< vector < string > > v1;
int x,y,z;

int di[]={-1,1,0,0,0,0};
int dj[]={0,0,-1,1,0,0};
int dk[]={0,0,0,0,-1,1};

struct node
{
    int a, b, c, cost;
    node(int x, int y, int z, int w)
    {
        a=x;
        b=y;
        c=z;
        cost=w;
    }
};

void bfs(int a,int b, int c)
{
    queue<node> Q;
    Q.push(node(a,b,c,0));
    memset(visited,false,sizeof(visited));
    visited[a][b][c]=true;
    int j,k,l,I,J,K;
    while(!Q.empty())
    {
        node aux=Q.front();
        Q.pop();
        j=aux.a;
        k=aux.b;
        l=aux.c;
        if(v1[l][k][j]=='E')
        {
            printf("Escaped in %d minute(s).\n", aux.cost);//;cout<<"Escaped in "<<aux.costo<<" minute(s)."<<endl;
            return;
        }

        for(int i=0;i<6;i++)
        {
            I=j+di[i];
            J=k+dj[i];
            K=l+dk[i];
            if(I>=0 && I<x && J>=0 && J<y && K>=0 && K<z && !visited[I][J][K] && v1[K][J][I]!='#')
            {
                Q.push(node(I,J,K,aux.cost+ 1));
                visited[I][J][K]=true;
            }
        }

    }
    printf("Trapped!\n");
    return;
}

int main()
{
    vector<string> v2;
    string s;
    int m,n,p;
    while(true)
    {
        scanf("%d %d %d", &z, &y, &x);
        if(x==0 && y==0 && z==0) break;
        v1.clear();
        for(int i=0;i<z;i++)
        {
            v2.clear();
            for(int j=0;j<y;j++)
            {
                cin>>s;
                v2.push_back(s);
            }
            v1.push_back(v2);
        }
        int flag=1 ;
        for(int i=0;i<z && flag;i++)
            for(int j=0;j<y && flag;j++)
                for(int k=0;k<x && flag;k++)
                    if(v1[i][j][k]=='S')
                    {
                        m=k;
                        n=j;
                        p=i;
                        flag=0 ; break ;
                    }
        bfs(m,n,p);
    }
    return 0;
}
