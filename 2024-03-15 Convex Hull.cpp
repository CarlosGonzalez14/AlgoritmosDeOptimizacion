//Resolviendo el ejercicio de: https://py.checkio.org/es/mission/convex-hull/
#include <bits/stdc++.h>

using namespace std;

typedef double C;
typedef complex<C> P;
#define X real()
#define Y imag()

P min_punto;

bool comparar_doble(const P a, const P b);

double calcularOrientacion(P p0, P p1,  P p2);

// double calcular_pendiente(pair<double,double> p1, pair<double,double> p2);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<P> vertices(n);

    
    double a, b;
    for(int i= 0; i < n; ++i)
    {
        cin >> a >> b;
        vertices[i] = {a,b};
        // cout << vertices[i].X << " " << vertices[i].Y << '\n';
    }

    min_punto = vertices[0];

    for(int i= 1; i < n; ++i)
    {
        if(vertices[i].Y < min_punto.Y)
        {
            min_punto = vertices[i];
        }
        if(vertices[i].Y == min_punto.Y && vertices[i].X < min_punto.X)
        {
            min_punto = vertices[i];
        }
    }
    // cout << min_punto.X << " " << min_punto.Y << '\n';

    sort(vertices.begin() , vertices.end(), comparar_doble);

    // for(auto p : vertices)
    // {
    //     cout << p.X << " " << p.Y << '\n';
    // }

    vector<P> convex_hull;
    for(int i= 0; i < n; ++i)
    {
        while( convex_hull.size() >= 2 && calcularOrientacion(convex_hull[convex_hull.size()-2],convex_hull[convex_hull.size()-1],vertices[i]) > 0)
        {
            convex_hull.pop_back();
        }
        convex_hull.push_back(vertices[i]);
        // if(convex_hull.size() >= 3)
        // {
        //     cout << vertices[i-3].X << " " << vertices[i-3].Y << " , " << vertices[i-2].X << " " << vertices[i-2].Y << " , " << vertices[i-1].X << " " << vertices[i-1].Y << "\n";
        //     cout << calcularOrientacion(vertices[i-3],vertices[i-2],vertices[i-1]) << '\n';
        // }
    }

    for(auto p : convex_hull)
    {
        cout << p.X << " " << p.Y << '\n';
    }
}

bool comparar_doble(const P a, const P b)
{
        P tempA = {a.X - min_punto.X,a.Y - min_punto.Y};
        P tempB = {b.X - min_punto.X,b.Y - min_punto.Y};

        double angleA = arg(tempA);
        double angleB = arg(tempB);

        double distA = abs(a-min_punto);
        double distB = abs(b-min_punto);

        if(angleA != angleB)
        {
            return angleA < angleB;
        }
        else
        {
            return distA < distB;
        }
        // if (a.Y != b.Y) {
        //     return a.Y < b.Y;
        // } else {
        //     return a.X < b.X;
        // }
}

double calcularOrientacion(P p0, P p1,  P p2)
{
    P a = (p1-p0);
    P b = (p1-p2);

    C c = (conj(a)*b).Y;

    return c;
}
// double calcular_pendiente(pair<double,double> p1, pair<double,double> p2)
// {
//     return (p2.second - p1.second)/(p2.first - p1.second);
// }
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

/*
    7
    7 6
    8 4
    7 2
    3 2
    1 6
    1 8
    4 9
*/

/*
6
0 0
0 4
-4 0
5 0
0 -6
1 0
*/

/*
3
1 2
3 1
5 6
*/