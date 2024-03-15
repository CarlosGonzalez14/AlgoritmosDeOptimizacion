#include <bits/stdc++.h>

using namespace std;

vector< vector<int> > matriz_adyacencia;
vector< vector<int> > matriz_rutas;

void mostrarRuta(int o, int d, bool first);

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);

    //Ingresar la cantidad de nodos
    int n;
    cout << "Ingresa la cantidad de nodos:\n";
    cin >> n;

    //Ingresar el grafo en forma de una
    //matriz de adyacencia
    // int matriz_adyacencia[n][n];

    cout << "Ingresa la matriz en forma de una matriz de adyacencia:\n";
    matriz_adyacencia.resize(n);
    matriz_adyacencia.assign(n,vector<int>(n));

    matriz_rutas.resize(n);
    matriz_rutas.assign(n,vector<int>(n));

    for(int i= 0; i < n; ++i)
    {
        for(int j= 0; j < n; ++j)
        {
            cin >> matriz_adyacencia[i][j];
            if(i == j)
            {
                matriz_rutas[i][j] = -1;
            }
            else
            {
                matriz_rutas[i][j] = j;
            }
        }
    }

    // for(int i= 0; i < n; ++i)
    // {
    //     for(int j= 0; j < n; ++j)
    //     {
    //         cout << matriz_rutas[i][j] << " ";
    //     }
    //     cout << '\n';
    // }



    for(int t =0; t < n; ++t)
    {
        for(int i= 0; i < n; ++i)
        {
            if(i == t)
            {
                continue;
            }
            for(int j= 0; j < n; ++j)
            {
                if(j == t)
                {
                    continue;
                }
                // matriz_adyacencia[i][j] = min(matriz_adyacencia[i][j],
                //                               (matriz_adyacencia[i][t] + matriz_adyacencia[t][j]));
                int res = matriz_adyacencia[i][t] + matriz_adyacencia[t][j];
                if(res < matriz_adyacencia[i][j])
                {
                    matriz_adyacencia[i][j] = res;
                    matriz_rutas[i][j] = t;
                }
            }
        }
    }

    // for(int i= 0; i < n; ++i)
    // {
    //     for(int j= 0; j < n; ++j)
    //     {
    //         cout << matriz_adyacencia[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    // for(int i= 0; i < n; ++i)
    // {
    //     for(int j= 0; j < n; ++j)
    //     {
    //         cout << matriz_rutas[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    int o, d;
    cout << "Ingrese los nodos entre los que desea encontrar la ruta más corta:\n";
    cout << "Nodo de Origen: ";
    cin >> o;
    cout << "\nNodo de destino: ";
    cin >> d; 
    cin >> d; 
    cin >> d; 
    mostrarRuta(o,d,true);
    return 0;
}

void mostrarRuta(int o, int d, bool first)
{
    int nodo_intermedio = matriz_rutas[o][d];
    if(nodo_intermedio == d)
    {
        return;
    }
    if(matriz_adyacencia[o][d] != 10000)
    {
        if(first)
        {
            cout << "La ruta mas corta entre el nodo "
                << o+1 << " y el nodo " << d+1 << " es:\n ";
            cout << o+1 << "->";
        }
        mostrarRuta(o,nodo_intermedio,false);
        cout << nodo_intermedio+1 << "->";
        if(first)
        {
            cout << d+1 << "\n";
            cout << "Con un peso de: " << matriz_adyacencia[o][d];
        }
    }
    else
    {
        cout << "No existe una ruta que vaya del nodo " << o+1
            << " al nodo " << d+1 << '\n';
    }
}

/*
5
0	    7	    2	    10000	10000
10000	0	    10000	10000	1
10000	4	    0	    2	    10000
10000	1	    10000	0	    1
10000	10000	10000	10000	0
*/