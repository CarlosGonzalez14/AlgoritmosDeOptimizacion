#include <bits/stdc++.h>

using namespace std;

vector< vector<char> > tablero;
vector< vector<int> > vecinasVivas;
vector< vector<char> > nuevoTablero;
int alto, ancho; 

void imprimirTablero();
void procesarTablero();

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);


    cout << "Introduce el alto y el ancho del tablero de juego en unidades separados por un espacio: ";
    cin  >> alto >> ancho;

    
    cout << "Ahora representa el tablero de juego. Toma en cuenta lo siguiente:\n\t-Una célula viva es representada por la letra (O).\n\t-Una célula muerta es representada por un punto (.).\n\t-Las células deben estar representadas en filas y separadas por un espacio.\n\n";
    // int tablero[alto][ancho];
    tablero.resize(alto);
    tablero.assign(alto,vector<char>(ancho));
    vecinasVivas.resize(alto);
    vecinasVivas.assign(alto,vector<int>(ancho));
    for(int i= 0; i < alto; ++i)
    {
        for(int j= 0; j < ancho; ++j)
        {
            // cout << '.' << ' ';
            cin >> tablero[i][j];
        }
        // cout << '\n';
    }
    
    int iteracion= 1;
    cout << "\nEscribe cualquier caracter y presiona enter para ver el siguiente estado: ";
    char c;
    while(cin >> c)
    {
        cout << "Iteración número: " << iteracion << '\n';
        ++iteracion;
        procesarTablero();
        imprimirTablero();
        cout << "\nEscribe cualquier caracter y presiona enter para ver el siguiente estado: ";
    }
    // procesarTablero();
    // imprimirTablero();
    return 0;
}

void imprimirTablero()
{
    cout << '\n';
    for(int i= 0; i < alto; ++i)
    {
        for(int j= 0; j < ancho; ++j)
        {
            cout << tablero[i][j] << ' ';
        }
        cout << '\n';
    }
}

void procesarTablero()
{
    int celdasVecinasVivas;
    for(int i= 0; i < alto; ++i)
    {
        for(int j= 0; j < ancho; ++j)
        {
            celdasVecinasVivas = 0;
            for(int r = i-1; r <= i+1; ++r)
            {
                for(int s = j-1; s <= j+1; ++s)
                {
                    if((r == i && s == j) || r < 0 || r >= alto || s < 0 || s >= ancho)continue;
                    if(tablero[r][s] == 'O')
                    {
                        ++celdasVecinasVivas;
                    }
                }
            }
            vecinasVivas[i][j] = celdasVecinasVivas;
            // cout << vecinasVivas[i][j] << " ";
        }
        // cout << '\n';
    }

    for(int i= 0; i < alto; ++i)
    {
        for(int j= 0; j < ancho; ++j)
        {
            if(tablero[i][j] == 'O')
            {
                if(vecinasVivas[i][j] < 2 || vecinasVivas[i][j] > 3)
                    tablero[i][j] = '.';
            }
            else
            {
                if(vecinasVivas[i][j] == 3)
                    tablero[i][j] = 'O';
            }
        }
    }
}

/*

*/

/*
20 40
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . O O O . . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
*/

/*
20 40
. . . O O O . . . O O O . . . O O O . . . O O O . . . O O O . . . O O O . . . O
O O O . . . O O O . . . O O O . . . O O O . . . O O O . . . O O O . . . O O O .
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . O O O . . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
*/