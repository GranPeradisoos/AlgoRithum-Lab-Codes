#include <bits/stdc++.h>

using namespace std;

priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

int check[200005];
int find_set(int node)
{
    if (check[node] == node)
        return node;
    return check[node] = find_set(check[node]);
}

int kruskal()
{

    vector<pair<int, pair<int, int>>> ans;
    int c, u, v, cost = 0, x, y;
    while (!pq.empty())
    {
        c = pq.top().first;
        u = pq.top().second.first;
        v = pq.top().second.second;
        x = find_set(u);
        y = find_set(v);
        if (x != y)
        {
            
            check[x] = y;
            cost += c;
        }
        pq.pop();
    }
    
    return cost;
}

int main()
{
    int node, edge, x, y, z;
    cout << "Enter number of nodes : ";
    cin >> node;
    cout << "Enter number of edge : ";
    cin >> edge;
    for (int i = 0; i < 200005; i++)
        check[i] = i;
    cout << "Enter all the edges : " <<endl;
    for (int i = 0; i < edge; i++)
    {
        cin >> x >> y >> z;
        pq.push({z, {x, y}});
    }
    cout << "Total Cost of MST = " << kruskal() << endl;
    return 0;
}