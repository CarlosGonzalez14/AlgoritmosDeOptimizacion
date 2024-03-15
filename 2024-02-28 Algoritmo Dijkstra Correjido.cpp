#include <bits/stdc++.h>
using namespace std;
#define INF 1000000

vector<vector<pair<int,int>>> Grafo;
vector<int> distancia;
vector<bool> processed;

void dijkstra(int nodo){
    priority_queue<pair<int,int>> q;
    //for (int i = 1; i <= n; i++) distancia[i] = INF;
    distancia[nodo] = 0;
    q.push({0,nodo});

    while (!q.empty()) {
         int a = q.top().second;
         q.pop();
         if (processed[a]) continue;
         processed[a] = true;
         for (auto u : Grafo[a]) {
            int b = u.first, w = u.second;
            if (distancia[a]+w < distancia[b]) {
                distancia[b] = distancia[a]+w;
                q.push({-distancia[b],b});
            }
         }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,nodo=1;
    cin >> n >> m;

    //Inicializar grafo
    Grafo.assign(n+1,vector<pair<int,int>>());
    distancia.assign(n+1,INF);
    processed.assign(n+1,false);

    int u,v,p;

    for(int i=0;i<m;++i){
        cin >> u >> v >> p;
        Grafo[u].push_back({v,p});
        // Grafo[v].push_back({u,p});
    }

    dijkstra(nodo);

    for(int i=1;i<distancia.size();++i){
        cout << distancia[i] << " ";
    }

    return 0;
}

/*
EJEMPLO 2024-02-28
EQUIVALENCIA DE NODOS
A-1
B-2
C-3
D-4
E-5
F-6
G-7
H-8
I-9
Z-10

10 13 
1 2 2
1 4 5
2 3 3
2 5 2
3 10 7
4 5 1
4 6 6
5 7 2
5 8 8
6 10 5
7 10 3
8 9 4
9 10 1
*/