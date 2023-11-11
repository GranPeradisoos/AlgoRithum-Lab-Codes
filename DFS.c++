#include <bits/stdc++.h>
using namespace std;

int main()
{
    int node, edge, start_node;
    cout << "Enter number of nodes: ";
    cin >> node;
    cout << "Enter number of edges: ";
    cin >> edge;

    bool visit[node + 1];
    vector<int> adj[node + 1]; // array of vector

    cout << "Enter the edges: " << endl;
    for (int i = 0; i < edge; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << "Enter the starting node: ";
    cin >> start_node;

    for (int i = 0; i <= node; i++)
        visit[i] = false;

    stack<int> s;
    s.push(start_node);
    visit[start_node] = true;

    cout << "DFS result (numbers): " << endl;
    while (!s.empty())
    {
        int top = s.top();
        s.pop();
        cout << top << " ";

        for (int i = 0; i < adj[top].size(); i++)
        {
            int neighbor = adj[top][i];
            if (!visit[neighbor])
            {
                visit[neighbor] = true;
                s.push(neighbor);
            }
        }
    }

    cout << endl;

    map<int, char> numberToAlphabet;
    for (int i = 1; i <= node; i++)
    {
        numberToAlphabet[i] = 'A' + i - 1;
    }

    for (int i = 0; i <= node; i++)
        visit[i] = false;
    while (!s.empty())
        s.pop();

    s.push(start_node);
    visit[start_node] = true;

    cout << "DFS result (alphabet): " << endl;
    while (!s.empty())
    {
        int top = s.top();
        s.pop();
        cout << numberToAlphabet[top] << " ";

        for (int i = 0; i < adj[top].size(); i++)
        {
            int neighbor = adj[top][i];
            if (!visit[neighbor])
            {
                visit[neighbor] = true;
                s.push(neighbor);
            }
        }
    }

    return 0;
}
/*
6 8
1 2
1 3
2 4
2 5
3 5
4 5
4 6
5 6
*/