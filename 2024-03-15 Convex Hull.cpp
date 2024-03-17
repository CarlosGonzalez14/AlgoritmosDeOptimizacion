//Resolviendo el ejercicio de: https://py.checkio.org/es/mission/convex-hull/
#include <bits/stdc++.h>

using namespace std;


bool comparar_doble(const pair<int, int>& a, const pair<int, int>& b);

double calcular_pendiente(pair<double,double> p1, pair<double,double> p2);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector< pair<double , double> > vertices(n);

    int a, b;
    for(int i= 0; i < n; ++i)
    {
        cin >> a >> b;
        vertices[i] = {a,b};
    }

    int min_x = vertices[0].first, min_y = vertices[0].second, min_index = 0;

    for(int i= 1; i < n; ++i)
    {
        if(vertices[i].first < min_x && vertices[i].second < min_y)
        {
            min_index = i;
            min_x = vertices[i].first;
            min_y = vertices[i].second;
        }
    }

    cout << min_x << " " << min_y << " " << min_index << '\n';

}

bool comparar_doble(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second != b.second) {
            return a.second < b.second;
        } else {
            return a.first > b.first;
        }
}

double calcular_pendiente(pair<double,double> p1, pair<double,double> p2)
{
    return (p2.second - p1.second)/(p2.first - p1.second);
}
/*
    6
    3 8
    1 6
    6 2
    7 6
    5 5
    8 4
    6 8
*/

/*
    7
    3 8
    1 6
    6 2
    7 6
    5 5
    8 4
    6 8
*/