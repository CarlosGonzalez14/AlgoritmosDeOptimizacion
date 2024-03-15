#include <bits/stdc++.h>

using namespace std;

double calculaValorFuncion(double x)
{
    //Cambiar en esta sección la funcion a la
    //que se aplicará Newton Raphson
    return x*x*x + 2*x*x + 10*x -20;
}

double calcularValorDerivada(double x)
{
    //Cambiar en esta sección la derivada de la
    //funcion a la que se aplicará Newton Raphson
    return 3*x*x + 4*x + 10;
}

int main()
{   
    double x0, x1, E, temp;
    //Leemos nuestro x0 y el error E
    cin >> x0 >> E;

    double fx= calculaValorFuncion(x0);
    double fprimax = calcularValorDerivada(x0);

    x1 = x0 - (fx/fprimax);
    // cout << x0 << " " << x1 << " " << fx << " " << fprimax << '\n';

    while(abs(x1-x0) > E)
    {
        x0 = x1;

        double fx= calculaValorFuncion(x0);
        double fprimax = calcularValorDerivada(x0);

        x1 = x0 - (fx/fprimax);

        // cout << x0 << " " << x1 << " " << fx << " " << fprimax << " " << abs(x1-x0) << '\n';
    }

    cout << x1 << '\n';

    return 0;
}