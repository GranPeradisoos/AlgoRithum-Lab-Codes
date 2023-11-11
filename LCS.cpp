#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    int arr[n+1][m+1];
    char track[n+1][m+1];
    for(int i=0; i<=n; i++)
    {
        arr[i][0] = 0;
    }
    for(int i=0; i<=m; i++)
    {
        arr[0][i] = 0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                arr[i][j] = arr[i-1][j-1] + 1;
                track[i][j] = 'D';
            }
            else
            {
                if(arr[i-1][j] >= arr[i][j-1])
                {
                    arr[i][j] = arr[i-1][j];
                    track[i][j] = 'U';
                }
                else
                {
                    arr[i][j] = arr[i][j-1];
                    track[i][j] = 'L';
                }
            }
        }

    }
    cout <<"The length is the lcs is: "<< arr[n][m] << endl;
    int i = n, j = m;
    vector<char> s;
    while(i>0 && j>0)
    {
        if(track[i][j] == 'D')
        {
            s.push_back(s1[i-1]);
            i--;
            j--;
        }
        else if(track[i][j] == 'U')
            i--;
        else j--;
    }
    reverse(s.begin(), s.end());
    for(int i=0; i<s.size(); i++)
        cout << s[i]<< endl;

    cout << endl;
}
