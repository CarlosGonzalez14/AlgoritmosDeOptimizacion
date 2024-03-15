#include <bits/stdc++.h>

using namespace std;

vector< vector<int> > v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    v.resize(n);
    v.assign(n,vector<int>(n));

    for(int i= 0; i < n; ++i)
    {
        for(int j= 0; j < n; ++j)
        {
            cout << v[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}