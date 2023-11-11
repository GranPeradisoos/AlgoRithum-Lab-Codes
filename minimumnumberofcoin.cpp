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

    int table[n+1][Amount+1];

    for(int i=0; i<=n; i++)
    {
        table[i][0] = 0;
    }
    for(int j=1; j<=Amount; j++)
    {
        table[0][j] = Amount+1;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=Amount; j++)
        {
            if(j>=coins[i-1]){
                table[i][j]=min(table[i-1][j],table[i][j-coins[i-1]] +1);
            }
            else{
                 table[i][j]= table[i-1][j];
            }
        }

    }

    cout << "Minimum number of coins : " << table[n][Amount]<< endl;

            for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= Amount; j++) {
                    cout << table[i][j] << " ";
                }
                    cout << endl;
            }

    }

