#include<iostream>

#include<algorithm>

#include<vector>


using namespace std;

int n,m,k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    string s[n];
    for (int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    int wx = n, wo = 0;
    int index[n][2];
    for (int i = 0; i < n; i++)
    {
        index[i][m%2]=i;
    }
    for (int j=m-1;j>=0;j--)
    {
        int o=0,x=0;
        for (int i=0;i<wx;i++)
        {
            if (s[index[n-i-1][(j+1)%2]][j]=='X')
            {
                index[n-(x++)-1][j%2]=index[n-i-1][(j+1)%2];
            }
            else
            {
                index[o++][j%2]=index[n-i-1][(j+1)%2];
            }
        }
        for (int i = 0; i < wo; i++)
        {
            if (s[index[i][(j+1)%2]][j]=='X')
            {
                index[n-(x++)-1][j%2]=index[i][(j+1)%2];
            }
            else
            {
                index[o++][j%2]=index[i][(j+1)%2];
            }
        }
        wx=x;wo=o;
    }
    for (int i=0;i<k;i++)
    {
        if (i>=wx)
                cout<<s[index[i-wx][0]]<<"\n";
        else
                cout<<s[index[n-i-1][0]]<<"\n";
    }
    return 0;
}


