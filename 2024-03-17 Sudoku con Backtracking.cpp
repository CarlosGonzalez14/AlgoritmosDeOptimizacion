#include <bits/stdc++.h>

using namespace std;

vector< vector <char> > tablero(9);

bool tablero_encontrado;

void leerTablero();
void imprimirTablero();
bool revisarTablero(int r, int s);
void resolverSudoku(int r, int s);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    tablero.assign(9 , vector<char> (9));

    leerTablero();

    imprimirTablero();

    tablero_encontrado = false;
    resolverSudoku(0,0);
    imprimirTablero();
    // cout << revisarTablero(2,3) << '\n';

    return 0;
}

void leerTablero()
{   
    for(int i= 0; i < 9; ++i)
    {
        for(int j= 0; j < 9; ++j)
        {
            cin >> tablero[i][j];
        }
    }
}

void imprimirTablero()
{
    cout << '\n';
    for(int i= 0; i < 9 ; ++i)
    {
        for(int j= 0; j < 9; ++j)
        {
            cout << tablero[i][j] << " ";
        }
        cout << '\n';
    }
}

bool revisarTablero(int r, int s)
{
    for(int i= 0; i < 9; ++i)
    {
        if(i == s)continue;
        if(tablero[r][i] == tablero[r][s])return false;
    }

    for(int j= 0; j < 9; ++j)
    {
        if(j == r)continue;
        if(tablero[j][s] == tablero[r][s])return false;
    }

    int rr = (r/3)*3, ss = (s/3)*3;
    for(int i= rr; i < rr+3; ++i)
    {
        for(int j= ss; j < ss+3; ++j)
        {
            if(i == r && j == s)continue;
            if(tablero[i][j] == tablero[r][s])return false;
        }
    }
    return true;
}

void resolverSudoku(int r, int s)
{
    if(r >= 9)
    {
        imprimirTablero();
        // tablero_encontrado = true;
    }
    if(s >= 9)
    {
        resolverSudoku(r+1 , 0);
        return;
    }
    // cout << tablero[r][s] << '\n';
    if(tablero[r][s] != '.')resolverSudoku(r,s+1);
    else
    {
        for(int i= 49; i <= 57; ++i)
        {
            tablero[r][s] = i;
            imprimirTablero();
            if(revisarTablero(r,s) == true)
            {
                // imprimirTablero();
                resolverSudoku(r,s+1);
            }
            else
            {
                tablero[r][s] = '.';
                continue;
            }
            tablero[r][s] = '.';
        }
    }
    return;
}

/*
. . . 1 2 3 . 8 .
1 . . . . . . 3 7
. . 8 7 4 6 9 . .
3 . 5 . . . 6 2 9
7 2 6 . . . . . .
8 . 1 . . . 3 . 4
. . 7 9 . . 2 . 3
9 . 3 4 7 . . 6 5
. 5 . 6 . 8 . . 1
*/

/*
. . . 1 2 3 . 8 .
1 . . . . . . 3 7
. . 8 7 4 6 9 . .
3 . 5 . . . 6 2 9
7 2 6 . . . . . .
8 . 1 7 . . 3 . 4
. . 7 9 . . 2 . 3
9 . 3 4 7 . . 6 5
. 5 . 6 . 8 . . 1
*/

/*
. . . 1 2 3 . 8 .
1 . . . . . . 3 7
. . 8 7 4 6 9 7 .
3 . 5 . . . 6 2 9
7 2 6 . . . . . .
8 . 1 . . . 3 . 4
. . 7 9 . . 2 . 3
9 . 3 4 7 . . 6 5
. 5 . 6 . 8 . . 1
*/

/*
. . . 1 2 3 . 8 .
1 . . . 7 . . 3 7
. . 8 7 4 6 9 . .
3 . 5 . . . 6 2 9
7 2 6 . . . . . .
8 . 1 . . . 3 . 4
. . 7 9 . . 2 . 3
9 . 3 4 7 . . 6 5
. 5 . 6 . 8 . . 1
*/
/*
4 7 2 1 9 3 5 6 8
9 5 . . . 7 3 4 2
. 3 . 5 2 4 . . 7
. 1 7 4 3 5 . 2 6
3 . . 2 7 . . 5 .
2 . 5 . . 1 4 7 3
. 2 3 7 4 . 6 8 5
7 . . 3 5 . 2 . 9
5 . . . 1 2 7 3 4
*/

/*
. 7 4 2 . 8 5 6 1
. . 2 . . 5 3 . 8
1 . . . 7 . 4 . .
. . 1 . 6 2 . . .
. 4 . 3 . 1 . 5 7
. . . 4 . . . . .
. 9 . 5 . 7 8 . .
2 1 8 . 3 . 7 . 5
. . 3 8 2 . 1 . 6
*/

/*
. 6 . 5 2 . . 1 7
. . . . . 1 . . .
8 . . . . . . 4 .
. . 6 . . . 5 . .
. . . 9 . . . . .
. 5 . 7 3 . . . 2
. 3 . . . 9 . . .
. . 4 3 1 . . 7 .
. . . . . 6 . . 1
*/

/*
4 3 . 5 . 6 9 . .
. 9 . . . . . . 8
. . . . . 2 . . .
. . 7 . . . . 1 .
. . . . 3 . . . .
6 . . 4 . 9 8 . .
. . . . 2 . 5 . .
. . 6 3 . 5 . . 7
3 . . . 8 . . . .
*/

/*
. . . 8 2 . 6 . .
5 . . . . . . . .
3 8 . 7 . . . . 2
. . 6 4 . . . . .
8 4 . . . 3 9 . .
. . 5 . . . . . 8
. . 4 . . . . . . 
2 7 . 3 . . . . 6
. . . . . 9 . 1 .
*/

/*
. . . . . 1 . 7 2
3 2 . . 7 . . . 4
6 . . . . . . . .
7 4 . . 1 . . . 3
. . 8 . . . . . .
. . . 5 . . 9 . .
. . 6 . 2 . . . .
2 8 . . . 9 3 . .
. . 1 . . . . . 8
*/

/*
. 4 . 9 . . 2 . .
. 6 . . . 5 . . .
2 . 5 . 8 . . . 7
. . 6 . . . . . .
5 . 7 . . 1 9 . .
. . . . 4 . . 1 .
. . . 3 . . . . 8
. 2 . . . . . . .
9 . 1 . . 4 7 . .
*/