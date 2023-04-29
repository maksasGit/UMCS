#include<iostream>

using namespace std;

#define F first
#define S second
#define pb push_back
#define endl '\n'


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    string uniquer[100][10];
    for (int i =  0; i < n; i++) {
        string a;
        int b, c;
        cin >> a >> b >> c;
        if (uniquer[b][c].size() == 0) {
                uniquer[b][c] = a;
        } else {
            uniquer[b][c] += (" " + a);
        }
    }
    for (int i = 99; i >= 0; i--) {
        for (int j = 0; j < 10; j++) {
            if (uniquer[i][j].size() != 0) {
                cout << uniquer[i][j] << ' ';
            }
        }
    }
    return 0;
}

