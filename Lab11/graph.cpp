#include <iostream>
#include <vector>
using namespace std;

struct Edge
{
    Edge() : weight(0), toBe(false) {}
    Edge(int value) : weight(value), toBe(false) {}
    bool toBe;
    int weight;
};

class Graph
{
public:
    Edge **aMtx;
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
        Edge **aux = new Edge *[nVertx];
        for (int i = 0; i < nVertx; i++)
        {
            aux[i] = new Edge[nVertx];
            for (int j = 0; j < nVertx; j++)
            {
                if (!isEmpty() && build)
                    aux[i][j] = aMtx[i][j];
            }
        }
        aMtx = aux;
    }

    void removeVertex(int target)
    {
        nVertx--;
        Edge **aux = new Edge *[nVertx];
        for (int i = 0; i < nVertx; i++)
        {
            aux[i] = new Edge[nVertx];
            for (int j = 0; j < nVertx; j++)
                if (!isEmpty())
                {
                    {
                        if (i == target || j == target)
                            aux[i][j] = aMtx[i + 1][j + 1];
                        else
                            aux[i][j] = aMtx[i][j];
                    }
                }
        }
    }

    void addEdge(int i, int j, int weight)
    {
        aMtx[i][j].toBe = true;
        aMtx[j][i].toBe = true;
        aMtx[i][j].weight = weight;
        aMtx[j][i].weight = weight;
        build = true;
    }

    void removeEdge(int i, int j)
    {
        aMtx[i][j].toBe = false;
        aMtx[j][i].toBe = false;
        aMtx[i][j].weight = 0;
        aMtx[j][i].weight = 0;
    }

    bool toBeeVertex(int target)
    {
        if (target <= nVertx)
            return true;
        return false;
    }

    bool isAdj(int x, int y)
    {
        if (aMtx[x][y].toBe == true)
            return true;
        return false;
    }

    void seeAdj()
    {
        cout << "    ";
        for (int i = 0; i < nVertx; i++)
        {
            char *l = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            cout << l[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < nVertx; i++)
        {
            char *l = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            cout << l[i] << " : ";
            for (int j = 0; j < nVertx; j++)
                cout << aMtx[i][j].toBe << " ";
            cout << "\n";
        }
    }

    void dfs(int start, vector<bool> &visited)
    {
        char *l = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        cout << l[start] << " ";

        visited[start] = true;

        for (int i = 0; i < nVertx; i++)
        {
            if (aMtx[start][i].toBe == 1 && (!visited[i]))
            {
                dfs(i, visited);
            }
        }
    }

    void bfs(int start)
    {

        vector<bool> visited(nVertx, false);
        vector<int> q;
        q.push_back(start);

        visited[start] = true;

        char *l = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int vis;
        while (!q.empty())
        {
            vis = q[0];

            cout << l[vis] << " ";
            q.erase(q.begin());

            for (int i = 0; i < nVertx; i++)
            {
                if (aMtx[vis][i].toBe == 1 && (!visited[i]))
                {

                    q.push_back(i);

                    visited[i] = true;
                }
            }
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
    for (int i = 0; i < 6; i++)
        g.addVertex();
    g.addEdge(0, 1, 4);
    g.addEdge(1, 5, 3);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 2, 6);
    g.addEdge(2, 4, 1);
    g.addEdge(2, 3, 0);

    g.seeAdj();

    vector<bool> visited(g.nVertx, false);

    g.dfs(1, visited);
    cout<<"\n";
    g.bfs(2);
}