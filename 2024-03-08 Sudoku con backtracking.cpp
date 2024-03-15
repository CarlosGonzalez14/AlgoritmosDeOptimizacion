#include <bits/stdc++.h>

using namespace std;

int tablero[9][9];

bool revisarTablero(int r, int c);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i= 0; i < 9; ++i)
    {
        for(int j= 0; j < 9; ++j)
        {
            cin >> tablero[i][j];
        }
    }

    for(int i= 0; i < 9; ++i)
    {
        for(int j= 0; j < 9; ++j)
        {
            // revisarTablero(i,j);
            cout << revisarTablero(i,j) << ' ';
        }
        cout << '\n';
    }
    // cout << revisarTablero()


    return 0;
}

bool revisarTablero(int r, int c)
{
    for(int i= 0; i < 9; ++i)
    {
        if(i != c && tablero[r][i] == tablero[r][c])
        {
            return false;
        }
    }
    for(int j= 0; j < 9; ++j)
    {
        if(j != r && tablero[j][c] == tablero[r][c])
        {
            return false;
        }
    }
    int rr, cc;
    rr = (r/3)*3;
    cc = (c/3)*3;

    for(int i= 0; i < 3; ++i)
    {
        for(int j= 0; j < 3; ++j)
        {
            if(rr+i == r && cc+j == c)
            {
                continue;
            }
            if(tablero[rr+i][cc+j] == tablero[r][c])
            {
                return false;
            }
        }
    }

    return true;
}

/*
8 0 0 0 0 7 0 9 0
0 2 9 0 0 4 0 0 6
3 0 0 2 0 0 0 0 0
0 0 0 0 0 6 5 0 0
0 1 7 4 0 0 0 3 0
2 0 0 0 0 0 0 0 0
0 9 4 1 0 0 0 7 0
0 0 8 0 0 0 0 0 0
0 0 0 0 7 0 0 0 3
*/

/*
5 3 4 6 7 8 9 1 1
6 7 2 1 9 5 3 4 8
1 9 8 3 4 2 5 6 7
8 5 9 7 6 1 4 2 3
4 2 6 8 5 3 7 9 1
7 1 3 9 2 4 8 5 6
9 6 1 5 3 7 2 8 4
2 8 7 4 1 9 6 3 5
3 4 5 2 8 6 1 7 9
*/

/*
5 3 4 6 7 8 9 1 2
5 7 2 1 9 5 3 4 8
1 9 8 3 4 2 5 6 7
8 5 9 7 6 1 4 2 3
4 2 6 8 5 3 7 9 1
7 1 3 9 2 4 8 5 6
9 6 1 5 3 7 2 8 4
2 8 7 4 1 9 6 3 5
3 4 5 2 8 6 1 7 9
*/

/*
5 3 4 6 7 8 9 1 2
6 7 2 1 9 5 3 4 8
1 9 8 3 4 2 5 6 7
8 5 9 7 6 1 4 2 3
4 2 6 8 5 3 7 9 1
7 1 3 9 2 7 8 5 6
9 6 1 5 3 7 2 8 4
2 8 7 4 1 9 6 3 5
3 4 5 2 8 6 1 7 9
*/