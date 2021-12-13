#include <iostream>
#include <queue>
using namespace std;
#define R 7
#define C 6

typedef struct BFS
{
    BFS(int i, int j)
    {
        this->i = i;
        this->j = j;
    }
    int i;
    int j;
} BFS;

bool findPath(char M[R][C], int x, int y)
{
    queue<BFS> q;

    if (M[x][y] != 'x' || M[x][y] != 't')
    {
        q.push(BFS(x, y));
    }

    while (!q.empty())
    {
        BFS x = q.front();
        q.pop();
        int i = x.i;
        int j = x.j;

        if (i < 0 || i > R || j < 0 || j > C)
            continue;

        if (M[i][j] == 'x')
            continue;

        if (M[i][j] == 't')
            return true;

        M[i][j] = 'x';

        for (int k = -1; k <= 1; k += 2)
        {
            q.push(BFS(i + k, j));
            q.push(BFS(i, j + k));
        }
    }

    return false;
}

int main()
{
    int x = 5, y=3;
    /*
    cout << "start x: ";
    cin >> x;
    cout << "start y: ";
    cin >> y;
    */
    char M[R][C] = {{'.', '.', 't', '.', '.', '.'},
                    {'.', '.', 'x', 'x', '.', '.'},
                    {'.', '.', '.', '.', '.', '.'},
                    {'t', 'x', '.', '.', 'x', '.'},
                    {'.', 'x', '.', '.', 'x', 't'},
                    {'.', 'x', 'x', '.', '.', '.'},
                    {'.', '.', 't', '.', '.', '.'}};

    (findPath(M, --x, --y) == true) ? cout << "Yes"
                                    : cout << "No" << endl;

    return 0;
}