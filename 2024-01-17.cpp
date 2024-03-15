#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> positivos, negativos;
    int ceros = 0;
     int temp;

     for(int i = 0; i <n; ++i)
     {
        cin >> temp;
        if(temp == 0)
        {
            ++ceros;
        }
        else if(temp > 0)
        {
            positivos.push_back(temp);
        }
        else
        {
            negativos.push_back(temp);
        }
     }

    for(auto x : positivos)
    {
        cout << x << " ";
    }
    cout << '\n';

    for(auto x : negativos)
    {
        cout << x << " ";
    }
    cout << '\n';

    return 0;
}