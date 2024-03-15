#include <bits/stdc++.h>

using namespace std;

struct edge
{
    int u, v, w;
    edge(int o, int d, int p)
    {
        u = o;
        v = d;
        w = p;
    }
};

vector<edge> adj[7];
// vector<edge> adj;
vector<int> dist(7);

void dijkstra(int start)
{
    //La distancia del nodo de inicio a sí mismo es 0
    dist[start] = 0;

    //Creamos una Priority Queue que ordene los elementos
    //de menor a mayor
    priority_queue <pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;

    //Insertar el nodo de inicio en la Priority Queue
    pq.push(make_pair(dist[start],start));

    //Siempre que haya elementos en la Priority Queue, el ciclo seguirá
    while(!pq.empty())
    {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if(d <= dist[u])
        {
            //Procesar todas las conexiones del nodo u, y si
            //su peso es menor que el peso actual, se actualiza.
            for(int i= 0; i < adj[u].size(); ++i)
            {
                int w = adj[u][i].w;
                int v = adj[u][i].v;
                if(dist[u] + w < dist[v])
                {
                    dist[v] = w + dist[u];
                    pq.push(make_pair(dist[v],v));
                }
            }
        }
    }
}

int main()
{   
    /*EQUIVALENCIA DE NODOS
    A -> 1
    B -> 2
    C -> 3
    D -> 4
    E -> 5
    F -> 6
    G -> 7
    */
//    adj.resize(7);
   fill(dist.begin() , dist.end() , 1000000);

    adj[1].push_back(edge(1,3,3));
    adj[1].push_back(edge(1,6,2));
    adj[2].push_back(edge(2,4,1));
    adj[2].push_back(edge(2,5,2));
    adj[2].push_back(edge(2,6,6));
    adj[2].push_back(edge(2,7,2));
    adj[3].push_back(edge(3,1,3));
    adj[3].push_back(edge(3,4,4));
    adj[3].push_back(edge(3,5,1));
    adj[3].push_back(edge(3,6,2));
    adj[4].push_back(edge(4,2,1));
    adj[4].push_back(edge(4,3,4));
    adj[5].push_back(edge(5,2,2));
    adj[5].push_back(edge(5,3,1));
    adj[5].push_back(edge(5,6,3));
    adj[6].push_back(edge(6,1,2));
    adj[6].push_back(edge(6,2,6));
    adj[6].push_back(edge(6,3,2));
    adj[6].push_back(edge(6,5,3));
    adj[6].push_back(edge(6,7,5));

    dijkstra(1);

    for(int i=1; i < 7; ++i)
    {
        cout << "La distancia más corta del nodo "
            << 1 << " al nodo " << i << " es de "<< dist[i] << "\n";
    }
    return 0;
}