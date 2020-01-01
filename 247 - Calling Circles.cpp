#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <ctime>

#define Inf 2147483647
#define Pi acos(-1.0)
#define N 100
#define LL long long
#define F(i, n) for( int i = (0); i < (n); i++ )
#define Fs(i, sz) for( size_t i = 0; i < sz.size (); i++ )
#define Set(a, s) memset(a, s, sizeof (a))
inline LL Power(int b, int p) { LL r = 1; for ( int i = 1; i <= p; i++ ) r *= b; return r; }

using namespace std;

map<string, int> names;
vector<string> rNames;

int namesLen = 0;

vector <int> edges [N];
vector <int> rEdges [N];    // reversed edges
vector <int> sortedNode;

bool vis [N];

int comp [N];               // component number of a node

int cases = 0;
bool blank = false;

int n, m;

void reset ()
{
    for ( int i = 0; i < N; i++ ) {
        edges [i].clear();
        rEdges [i].clear();
    }

    sortedNode.clear();
    names.clear();
    rNames.clear();

    namesLen = 0;
    memset (vis, false, sizeof vis);
}

void dfs1 (int x)
{
    vis [x] = true;

    for ( size_t u = 0; u < edges [x].size(); u++ ) {
        if ( !vis [edges [x] [u]] )
            dfs1(edges [x] [u]);
    }

    sortedNode.push_back(x);
}

void dfs2 (int x, int c)
{
    vis [x] = false;

    comp [x] = c;

    for ( size_t u = 0; u < rEdges [x].size(); u++ ) {
        if ( vis [rEdges [x] [u]] )
            dfs2(rEdges [x] [u], c);
    }
}

void assignNumber(string s)
{
    if (!names [s]) {
        ++namesLen;
        names [s] = namesLen;
        rNames.push_back(s);
    }
}

void printOutput(int compLen)
{
    if (blank) printf ("\n");
    blank = true;

    printf ("Calling circles for data set %d:\n", ++cases);

    bool space;

    for (int i = 1; i <= compLen; i++ ) {

        space = false;

        F(j, n) {
            if (comp [j + 1] == i) {

                if (space) printf (", ");
                space = true;

                cout << rNames[j];
            }
        }

        printf ("\n");
    }
}

int main ()
{
    while (scanf ("%d %d", &n, &m)) {

        if ( n == 0 && m == 0 ) break;

        reset();

        string name1, name2;

        F(i, m) {
            cin >> name1 >> name2;

            assignNumber(name1);
            assignNumber(name2);

            edges [names [name1]].push_back(names [name2]);
            rEdges [names [name2]].push_back(names [name1]);
        }

        F(i, namesLen) {
            if (!vis [i + 1]) {
                dfs1(i + 1);
            }
        }

        int compId = 0;

        for ( int i = sortedNode.size() - 1; i >= 0; i-- ) {
            if ( vis [sortedNode [i]] )
                dfs2(sortedNode [i], ++compId);
        }

        printOutput(compId);

    }

    return 0;
}
