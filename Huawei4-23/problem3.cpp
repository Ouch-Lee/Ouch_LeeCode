#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge
{
    int from;
    int to;
    int w;

    Edge(int from, int to, int w) : from(from), to(to), w(w) {}
};

void dfs()
{

}
int main()
{
    int sn, t, M, s, d, p;
    cin >> sn >> t;
    vector<Edge> edges;
    vector<bool> isVisited(M, false);
    vector<bool> isDilivred(M, false);

    for (int i = 0; i < M; i++)
    {
        cin >> s >> d >> p;
        edges.push_back(Edge(s, d, p));
    }   
    



}