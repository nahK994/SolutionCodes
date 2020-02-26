#include<bits/stdc++.h>
using namespace std;

int main()
{
    long n, a, b, c;
    vector<long> V, ans;
    V.push_back(0);
    
    scanf("%ld", &n);
    for(int i=1 ; i<=n ; i++)
    {
        scanf("%ld", &a);
        V.push_back(a);
        for(int j = V.size()-1 ; j/2>=1 ; j/=2)
        {         
            if(V[j] < V[j/2])
            {
                b = V[j/2];
                V[j/2] = V[j];
                V[j] = b;
            }
            else
            {
                break;
            }
        }
    }

    while(V.size() > 1)
    {
        ans.push_back(V[1]);
        V[1] = V[V.size()-1];
        V.pop_back();
            
        for(int i=1 ; i<V.size() ; )
        {
            if(2*i < V.size() && 2*i+1 < V.size())
            {
                if(V[2*i] <= V[2*i+1] && V[i] > V[2*i])
                {
                    b = V[2*i];
                    V[2*i] = V[i];
                    V[i] = b;
                    i*=2;
                }
                else if(V[2*i+1] < V[2*i] && V[i] > V[2*i+1])
                {
                    b = V[2*i+1];
                    V[2*i+1] = V[i];
                    V[i] = b;
                    i = 2*i+1;
                }
                else
                {
                    break;
                }
                
            }
            else if(2*i < V.size() && V[i] > V[2*i])
            {
                b = V[2*i];
                V[2*i] = V[i];
                V[i] = b;
                i*=2;
            }
            else if(2*i+1 < V.size() && V[i] > V[2*i+1])
            {
                b = V[2*i+1];
                V[2*i+1] = V[i];
                V[i] = b;
                i = 2*i+1;
            }
            else
            {
                break;
            }
        }
    }

    printf("%ld", ans[0]);
    for(int i=1 ; i<ans.size() ; i++)
        printf(" %ld", ans[i]);
    printf("\n");
}

/*
10
0 4 2 -5 -4 -23 -2 99 2 111
*/