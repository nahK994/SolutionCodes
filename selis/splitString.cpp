#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s, aa;
    vector<string>ans;
    getline(cin, s);
    for(int i=0 ; i<s.size() ; i++)
    {
        if(s[i] == ' ')
        {
            ans.push_back(aa);
            aa.clear();
        }
        else aa = aa + s[i];
    }
    if(aa.size()) ans.push_back(aa);

    for(int i=0 ; i<ans.size() ; i++)
        cout<<ans[i]<<endl;
    return 0;
}