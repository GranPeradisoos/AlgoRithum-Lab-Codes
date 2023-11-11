#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, Amount;

    cout<<"Enter The Number of Coin : ";

    cin >> n;

    int coins[n];

    cout<<"Enter The Coins : ";

    for(int i=0; i<n; i++)
    {
        cin >> coins[i];
    }

    cout<<"Enter The Amount : ";

    cin >> Amount;

    int table[n][Amount+1];

    for(int i=0; i<n; i++)
    {
        table[i][0] = 1;
    }
    for (int j = 1; j <= Amount; j++)
    {

        if (j % coins[0] == 0)
        {
            table[0][j] = 1;
        }
        else
        {
            table[0][j] = 0;
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= Amount; j++)
        {
            if (j >=coins[i])
            {
                table[i][j] = table[i - 1][j] + table[i][j - coins[i]];
            }
            else
            {
                table[i][j] = table[i - 1][j];
            }
        }
    }

    cout << "Maximum number of ways to make change: " << table[n-1][Amount] << endl;



}

