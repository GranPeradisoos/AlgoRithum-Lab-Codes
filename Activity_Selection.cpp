#include<bits/stdc++.h>
using namespace std;

struct Activity
{
    string name;
    float start, end;
};

bool comp(Activity act1, Activity act2)
{
    return (act1.end<act2.end);
}

int main()
{
    int n;
    printf("Enter the number of activity: ");
    cin >> n;
    Activity arr[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i].name >> arr[i].start >> arr[i].end;
    }

    sort(arr, arr+n, comp);

    int j = 0, count =1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i].start >= arr[j].end)
        {
            count++;
            j = i;
        }
    }
    cout << "Maximum selected activity: " << count << endl;

}
