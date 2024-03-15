#include <bits/stdc++.h>
// #define  0.00001;

using namespace std;

double valorFuncion(double x)
{
    double resultado = 2*x*x*x + x*x - 1;

    return resultado;
}

double valorDerivada(double x)
{
    double resultado = 6*x*x + 2*x;

    return resultado;
}

int main()
{   
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);

    double x_i, x_i1, E;
    cout << "Introduzca el número desde el que comenzará la iteración: \n";
    cin >> x_i;
    cout << "x_0= " << x_i << '\n';

    cout << "Introduzca el valor del Error: \n";
    cin >> E;
    // cout << E << '\n';

    x_i1 = x_i - (valorFuncion(x_i)/valorDerivada(x_i));
    cout << "x_1= " << x_i1 << '\n';

    int contador = 2;
    while(abs(x_i1-x_i) > E)
    {
        x_i = x_i1;
        x_i1 = x_i - (valorFuncion(x_i)/valorDerivada(x_i1));
        cout << "x_" << contador << "= " << x_i1 << '\n';
        ++contador;
    }

    cout << "La raíz con un error E= " << E << "es de: " << x_i1 << '\n';
    // cout << x_i1 << '\n';
    return 0;
}
