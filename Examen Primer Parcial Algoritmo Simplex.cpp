#include <bits/stdc++.h>

using namespace std;

int n;
int filas, columnas;
double tabla_simplex[1000][1000], nueva_tabla[1000][1000];
bool continuar_funcion;

void calcularNuevaTablaSimplex();
void pasarDatosEntreTablas();
void mostrarSolucion();

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);

    // int n;
    cout << "Ingresa la cantidad de variables de la función objetivo\n";
    cin >> n;

    int m;
    cout << "Ingresa la cantidad de variables de holgura\n";
    cin >> m;

    // int tabla_simplex[m+1][n+m+2], nueva_tabla[m+1][n+m+2];
    filas = m+1, columnas = n+m+2;

    for(int i= 0; i < (m+1); ++i)
    {
        for(int j= 0; j < (n+m+2); ++j)
        {
            cin >> nueva_tabla[i][j];
        }
    }

    // for(int i= 0; i < (m+1); ++i)
    // {
    //     for(int j= 0; j < (n+m+2); ++j)
    //     {
    //         cout << tabla_simplex[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    continuar_funcion = true;

    while(continuar_funcion)
    {
        calcularNuevaTablaSimplex();
    }

    mostrarSolucion();
    return 0;
}

void calcularNuevaTablaSimplex()
{
    pasarDatosEntreTablas();
    bool hay_negativos = false;
    double min_col = 0;
    int min_index_c = -1;
    for(int j = 0; j < columnas; ++j)
    {
        if(tabla_simplex[0][j] < min_col)
        {
            hay_negativos = true;
            min_col = tabla_simplex[0][j];
            min_index_c = j;
        }
    }
    cout << "La columna con el valor Z más ngeativo es la columna: " << (min_index_c+1) << " con un valor de: " << min_col << '\n';
    // continuar_funcion = false;
    continuar_funcion = hay_negativos;
    if(continuar_funcion == false)
    {
        return;
    }
    // bool columna_es_cero, cero_negativo;
    double min_fila = 1e6, coeficiente_fila_actual;
    int min_index_f;
    for(int i= 1; i < filas; ++i)
    {
        if(tabla_simplex[i][min_index_c] == 0)
        {
            continue;
        }
        if(tabla_simplex[i][columnas-1] == 0 && tabla_simplex[i][min_index_c] < 0)
        {
            continue;
        }
        coeficiente_fila_actual = tabla_simplex[i][columnas-1]/tabla_simplex[i][min_index_c]; 
        if(coeficiente_fila_actual < min_fila && coeficiente_fila_actual > 0)
        {
            min_fila = coeficiente_fila_actual;
            min_index_f = i;
        }
    }
    cout << "La fila con el coeficiente más bajo no negativo es: " << (min_index_f+1) << " con un valor de: " << min_fila << '\n';
    int columna_pivote = min_index_c,
        fila_pivote = min_index_f;
    double elemento_pivote = tabla_simplex[fila_pivote][columna_pivote],
        inverso_multi = 1/elemento_pivote;
    
    for(int j= 0; j < columnas; ++j)
    {
        nueva_tabla[fila_pivote][j] = tabla_simplex[fila_pivote][j]*inverso_multi;
    }

    double inverso_adi, sumando, nuevo_valor;
    for(int i= 0; i < filas; ++i)
    {
        if(i == fila_pivote)
        {
            continue;
        }
        inverso_adi = tabla_simplex[i][columna_pivote] * -1;
        // cout << inverso_adi << '\n';
        // cout << inverso_adi << '\n';
        for(int j= 0; j < columnas; ++j)
        {
            sumando = inverso_adi * nueva_tabla[fila_pivote][j];
            // nuevo_valor = sumando + tabla_simplex[i][j];
            // cout << sumando << " ";
            // cout << nuevo_valor << " ";
            nueva_tabla[i][j] = sumando + tabla_simplex[i][j];
        }
        // cout << '\n';
    }
    for(int i= 0; i < filas; ++i)
    {
        for(int j= 0; j < columnas; ++j)
        {
            cout << nueva_tabla[i][j] << " ";
        }
        cout << '\n';
    }
}

void pasarDatosEntreTablas()
{
    for(int i = 0; i < filas; ++i)
    {
        for(int j= 0; j < columnas; ++j)
        {
            tabla_simplex[i][j] = nueva_tabla[i][j];
        }
    }
}

void mostrarSolucion()
{
    cout << "La solución óptima al problema es la siguiente:\n";
    for(int t= 1; t <= n; ++t)
    {
        bool valor_encontrado = false;
        for(int i = 1; i < filas; ++i)
        {
            if(tabla_simplex[i][t] == 1)
            {
                valor_encontrado = true;
                cout << "x_" << t << "= " << tabla_simplex[i][columnas-1] << '\n';
            }
        }
        if(valor_encontrado == false)
        {
            cout << "x_" << t << "= " << 0 << '\n';
        }
    }
    cout << "max Z= " << tabla_simplex[0][columnas-1] << '\n';
}

/*
4
3
1 -2 -3 -4 -5 0 0 0 0
0  1  0 -1  1 1 0 0 10
0  1  2  0  0 0 1 0 8
0  0  0  1  1 0 0 1 20
*/