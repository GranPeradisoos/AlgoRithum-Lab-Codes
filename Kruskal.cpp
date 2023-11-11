#include <bits/stdc++.h>

#define sz 200005

using namespace std;

int par[sz];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
// priority_queue<int,vector<int>,greater<int> > pq;        //min heap

int find_set(int node)
{
    if (par[node] == node)
        return node;
    return par[node] = find_set(par[node]);
}

int k()
{
    vector<pair<int, pair<int, int>>> ans;
    int c, u, v, tot = 0, x, y;
    while (!pq.empty())
    {
        c = pq.top().first;
        u = pq.top().second.first;
        v = pq.top().second.second;
        x = find_set(u);
        y = find_set(v);
        if (x != y)
        {
            ans.push_back({c, {u, v}});
            par[x] = y;
            tot += c;
        }
        pq.pop();
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << i << ":" << ans[i].first << " -> (" << ans[i].second.first << "," << ans[i].second.second << ")" << endl;
    }
    return tot;
}

int main()
{
    int node, edge, x, y, z;
    cout<<"Enter number of nodes : ";
    cin >> node;
    cout<<"Enter number of edge : ";
    cin >> edge;
    for (int i = 0; i <= node; i++)
        par[i] = i;
        cout<<"Enter ";
    for (int i = 0; i < edge; i++)
    {
        cin >> x >> y >> z;
        pq.push({z, {x, y}});
    }
    cout << "Total Cost of MST = " << k() << endl;
    return 0;
}

/* Sample Input -
4 6
1 2 2
1 3 1
1 4 3
2 3 4
2 4 1
3 4 2
*/
