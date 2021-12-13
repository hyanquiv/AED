#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Graph
{
public:
    bool **aMtx;
    int nVertx;
    bool build = false;

public:
    Graph()
    {
        this->nVertx = 0;
        aMtx = nullptr;
    }

    bool isEmpty()
    {
        if (nVertx == 0)
            return true;
        return false;
    }

    void addVertex()
    {
        nVertx++;
        bool **aux = new bool *[nVertx];
        for (int i = 0; i < nVertx; i++)
        {
            aux[i] = new bool[nVertx];
            for (int j = 0; j < nVertx; j++)
            {
                aux[i][j] = false;
                if (!isEmpty() && build)
                    aux[i][j] = aMtx[i][j];
            }
        }
        aMtx = aux;
    }

    void removeVertex(int target)
    {
        nVertx--;
        bool **aux = new bool *[nVertx];
        for (int i = 0; i < nVertx; i++)
        {
            aux[i] = new bool[nVertx];
            for (int j = 0; j < nVertx; j++)
                if (!isEmpty())
                {
                     if (i >= target || j >= target)
                        aux[i][j] = aMtx[i+1][j+1];
                     else
                         aux[i][j] = aMtx[i][j];
                 }
                
        }
        aMtx=aux;
        
    }

    void addEdge(int i, int j)
    {
        aMtx[i][j] = true;
        aMtx[j][i] = true;
        build = true;
    }

    void removeEdge(int i, int j)
    {
        aMtx[i][j] = false;
        aMtx[j][i] = false;

    }

    bool toBeeVertex(int target)
    {
        if (target <= nVertx)
            return true;
        return false;
    }

    bool isAdj(int x, int y)
    {
        if (aMtx[x][y] == true)
            return true;
        return false;
    }

    void seeAdj()
    {
        for (int i = 0; i < nVertx; i++)
        {
            for (int j = 0; j < nVertx; j++)
                cout << aMtx[i][j] << " ";
            cout << "\n";
        }
    }

    ~Graph()
    {
        for (int i = 0; i < nVertx; i++)
            delete[] aMtx[i];
        delete[] aMtx;
    }
};

int main()
{
    Graph g;
    for (int i = 0; i < 5; i++)
        g.addVertex();
    g.addEdge(0, 1);
    g.addEdge(1, 4);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 4);
    g.addEdge(2, 3);
    g.addEdge(0, 4);

    g.seeAdj();

    if (g.isAdj(0, 2))
        cout << "hay adyacencia.\n";
    else
        cout << "no hay adyacencia.\n";

    g.removeVertex(0);

    g.seeAdj();

    if (g.isAdj(0, 2))
        cout << "hay adyacencia.\n";
    else
        cout << "no hay adyacencia.\n";

    
}