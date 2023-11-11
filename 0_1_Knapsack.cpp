#include <bits/stdc++.h>
using namespace std;

struct item
{
    string name;
    int price, weight;
};

int main()
{
    int n, cap;
    cin >> n >> cap;
    item a[n];
    int arr[n+1][cap+1];
    for(int i=0; i<n; i++)
    {
        cin >> a[i].name >> a[i].weight >> a[i].price;
    }

    for(int i=0; i<=n; i++)
    {
        arr[i][0] = 0;
    }
    for(int i=0; i<=cap; i++)
    {
        arr[0][i] = 0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=cap; j++)
        {
            if(j >= a[i-1].weight)
            {
                arr[i][j] = max(arr[i-1][j], (arr[i-1][j-a[i-1].weight] + a[i-1].price));
            }
            else
            {
                arr[i][j] = arr[i-1][j];

            }
        }

    }

    cout << arr[n][cap]<< endl;


    int val = arr[n][cap];
    int i = n, j = cap;

    cout << "Selected items: " << endl;

    while (i>0 && val>0)
    {
        if(val == arr[i-1][j])
        {
            i--;
            continue;
        }
        else
        {
            cout << a[i-1].name << endl;
            val -=a[i-1].price;
            j -= a[i-1].weight;
        }
        i--;
    }
}
