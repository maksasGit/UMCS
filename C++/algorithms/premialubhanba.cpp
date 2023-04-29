#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define pb push_back
#define endl '\n'

vector < vector < long long > > pref;
vector < vector < vector < long long > > > dp;
vector < int > druzyny;
int n;

void clear_dp(int chod){
        int i = chod % 2;
        for (int j = 0; j < n + 1; j++) {
            for (int c = 0; c < n; c++) {
                dp[i][j][c] = 0;
            }
        }
}

void set_start(){
    dp[1][0][0] = druzyny[0];
    dp[1][1][0] = druzyny[0];
    dp[1][1][1] = druzyny[1];
    pref[0][1] = druzyny[0];
    pref[1][1] = max(druzyny[0] , druzyny[1]);
}


void replace_last_dp(int chod){
        for (int j = 1; j <= chod ; j++) {
            for (int c = 0; c <= chod; c++) {
                if (dp[(chod - 1)%2][j - 1][c] != 0)
                    dp[chod%2][j][c] = dp[(chod - 1)%2][j - 1][c] + druzyny[c];
            }
        }
}


void cout_all(int chod) {
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < n; j++) {
            cout << dp[chod%2][i][j] << ' ';
        }
        cout << endl;
    }
}


void find_max() {
    long long max_num = 0;
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < n; j++) {
            max_num = max(max_num , dp[n%2][i][j]);
        }
    }
    cout << max_num << endl;
}

void clear_pref(int chod) {
    for (int i = 0; i < n + 1; i++) pref[i][chod%2] = 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    pref.resize(n + 1, vector < long long > (2));
    dp.resize(2,vector<vector<long long> >(n + 1,vector<long long>(n)));
    druzyny.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> druzyny[i];
    }
    set_start();
    for (int chod = 2; chod < n+1; chod++) {
        cout_all(chod - 1);
        cout << endl << endl << endl << endl;
        cout_all(chod);
        cout << endl << endl << endl << endl;
        clear_dp(chod);
        clear_pref(chod);
        replace_last_dp(chod);
        for (int krokow = 0; krokow <= chod; krokow++){
            int min_last = min(chod*2 , n);
            for (int nr_druzyny = chod - 1; nr_druzyny < min_last ; nr_druzyny++){
//                if (krokow - 1 > -1 && dp[(chod - 1)%2][krokow - 1][nr_druzyny] != 0)
//                    dp[chod%2][krokow][nr_druzyny] = dp[(chod - 1)%2][krokow - 1][nr_druzyny] + druzyny[nr_druzyny];
                if (nr_druzyny - chod < krokow ) {
                    int prefix_raw = krokow - ( (nr_druzyny + 1)  - chod);
                    cerr << prefix_raw << endl;
                    dp[chod%2][krokow][nr_druzyny] = max(dp[chod%2][krokow][nr_druzyny], pref[prefix_raw][(chod-1)%2] + druzyny[nr_druzyny]);
                    pref[krokow][chod%2] = max(pref[krokow][chod%2] , dp[chod%2][krokow][nr_druzyny]);
                } else {
                    break;
                }
            }
        }
    }
    cout_all(n);
    cout << endl << endl << endl << endl;
    find_max();
    return 0;
}

