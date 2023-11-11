#include<bits/stdc++.h>
using namespace std;

struct Item
{
    string name;
    double weight,price,unitPrice;
};

bool comp(Item i1, Item i2)
{
    return (i1.unitPrice>i2.unitPrice);
}

int main()
{
    int n;
    double capacity;
    cout << "Enter the number of items: ";
    cin >> n;

    Item arr[n];

    for(int i=0; i<n; i++)
    {
        cin >> arr[i].name >> arr[i].weight >> arr[i].price;
        arr[i].unitPrice = arr[i].price/arr[i].weight;
    }
    sort(arr, arr+n, comp);

    cout << "Enter the capacity of Knapsack : ";
    cin >> capacity;

    double profit=0;

    for(int i=0; i<n; i++)
    {
        if(arr[i].weight<=capacity)
        {
            profit+=arr[i].price;
            capacity-=arr[i].weight;
        }
        else
        {
            profit+=arr[i].unitPrice*capacity;
            break;
        }
    }

    cout << "Profit: " << profit << endl;

    return 0;
}
