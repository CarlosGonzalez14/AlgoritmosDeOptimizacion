#include <bits/stdc++.h>

using namespace std;

//sucon y elementos deben tener
//el mismo tipo de dato
vector<int> subcon;
map<int,int> posi, nega;

vector<int> factoriales(1000000);

void search(int cantidad, int k, const vector<int> elementos, bool es_positivo);

unsigned long long calcularFactoriales(int numero);

unsigned long long calcularCombinaciones(int cantidad_ceros);

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    //La cantidad de elementos que
    //vamos a permutar
    int n;
    cin >> n;
    
    vector<int> positivos, negativos;
    int ceros = 0, temp;

    for(int i = 0; i < n; ++i){
        cin >>  temp;
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

    search(positivos.size(),0, positivos, true);
    search(negativos.size(),0, negativos, false);

    posi.erase(0);
    nega.erase(0);

    // cout << ceros << '\n';

    // for(auto x : posi)
    // {
    //     cout << x << " ";
    // }
    // cout << '\n';

    // for(auto x : nega)
    // {
    //     cout << x << " ";
    // }
    // cout << '\n';

    long long formas = 0;
    for(auto x : nega)
    {
        // cout << x.first << ": " << x.second << " ";
        cout << x.first << " " << x.second << " " << posi[abs(x.first)] << '\n';
        formas+= (x.second) * (posi[abs(x.first)]);
    }

    // formas= (formas * (ceros+1)) + ceros;

    cout << formas << '\n';

    fill(factoriales.begin(), factoriales.end(), -1);

    // cout << '\n';

    return 0;
}

void search(int cantidad, int k, const vector<int> elementos, bool es_positivo){
    if(k == cantidad){
        //Procesar el subconjunto
        //Ejemplo de procesamiento:
        int total = 0;
        for(auto x : subcon){
            // cout << x << " ";
            total+= x;
        }
        // cout << '\n';
        if(es_positivo)
        {
            // posi.insert(total);
            ++posi[total];
        }
        else
        {
            // nega.insert(total);
            ++nega[total];
        }
    }else{
        search(cantidad, k+1, elementos, es_positivo);
        subcon.push_back(elementos[k]);
        search(cantidad, k+1, elementos, es_positivo);
        subcon.pop_back();
    }
}

unsigned long long calcularFactoriales(int numero)
{
    if(numero == 0 || numero == 1)
    {
        return 1;
    }
    if(factoriales[numero] != -1)
    {
        return factoriales[numero];
    }
    return numero + calcularFactoriales(numero-1);
}