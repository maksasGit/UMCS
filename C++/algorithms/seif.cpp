#include<iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n , m , k;
    cin >> n >> m >> k;
    string tab[n];
    int pos_tab[2][n][2];
    for (int i = 0; i < n; i++) {
        cin >> tab[i];
        pos_tab[1][i][m%2] = n-i-1;
    }
    int last_x = n;
    int last_o = 0;
    for (int j = m - 1; j > -1; j--) {
        int kol_o = 0;
        int kol_x = 0;
        for (int i = 0; i < last_x; i++) {
            if (tab[pos_tab[1][i][(j+1)%2]][j] == 'X') {
                pos_tab[1][kol_x][j%2]=pos_tab[1][i][(j+1)%2];
                kol_x++;
            }else {
                pos_tab[0][kol_o][j%2]=pos_tab[1][i][(j+1)%2];
                kol_o++;
            }
        }
        for (int i = 0; i < last_o; i++) {
            if (tab[pos_tab[0][i][(j+1)%2]][j] == 'X') {
                pos_tab[1][kol_x][j%2]=pos_tab[0][i][(j+1)%2];
                kol_x++;
            }else {
                pos_tab[0][kol_o][j%2]=pos_tab[0][i][(j+1)%2];
                kol_o++;
            }
        }
        last_x = kol_x;
        last_o = kol_o;
    }
    for (int i = 0; i < min(k , last_x); i++) {
        cout << tab[pos_tab[1][i][0]] << "\n";
    }
    k-=last_x;
    if (k > 0) {
        for (int i = 0; i < min(k , last_o); i++) {
            cout << tab[pos_tab[0][i][0]] << "\n";
        }
    }
    return 0;
}


