#include<iostream>

#include<algorithm>

#include<vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int sad[2][m];
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            cin>>sad[i%2][j];
        }
        if (i==0) continue;
        for (int j=0;j<m;j++) {
            int new_value=sad[i%2][j];
            int max_rodz=sad[(i-1)%2][j];
            if (j-1>=0) if (sad[(i-1)%2][j-1]>max_rodz) max_rodz=sad[(i-1)%2][j-1];
            if (j+1<m) if (sad[(i-1)%2][j+1]>max_rodz) max_rodz=sad[(i-1)%2][j+1];
            new_value+=max_rodz;
            sad[i%2][j]=new_value;
        }
    }
    int index=-1,max_value=-1;
    for (int j=0;j<m;j++)
        if (sad[(n-1)%2][j]>max_value)
        {
            max_value=sad[(n-1)%2][j];
            index=j;
        }

    cout<<index<<' '<<max_value<<endl;
    return 0;
}



