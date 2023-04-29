#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define pb push_back
#define endl '\n'
int n;
vector < vector < short > > koszt;
int global_min = 100000;
vector < vector < short > > tab;
vector < vector < short > > stan;
vector < short > odp;

void block(int x , int y){
    for (int i = 0; i < n; i++) {
        tab[i][y]++;
    }
    for (int j = 0; j < n; j++) {
        tab[x][j]++;
    }
    for (int i = 0; (x+i<n) && (y+i<n); i++) {
        tab[x+i][y+i]++;
    }
    for (int i = 0; (x+i<n) && (y-i>-1); i++) {
        tab[x+i][y-i]++;
    }
    for (int i = 0; (x-i>-1) && (y-i>-1); i++) {
        tab[x-i][y-i]++;
    }
    for (int i = 0; (x-i>-1) && (y+i<n); i++) {
        tab[x-i][y+i]++;
    }
    tab[x][y]-=5;
    stan[x][y]++;
}

void cout_tab() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cerr << tab[i][j] << " ";
        }
        cerr  << endl;
    }

    cerr << endl << endl << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cerr  << stan[i][j] << " ";
        }
        cerr << endl;
    }



    cerr << endl << endl  << "####################" << endl << endl;
}

void unblock(short x , short y){
    for (int i = 0; i < n; i++) {
        tab[i][y]--;
    }
    for (int j = 0; j < n; j++) {
        tab[x][j]--;
    }
    for (int i = 0; (x+i<n) && (y+i<n); i++) {
        tab[x+i][y+i]--;
    }
    for (int i = 0; (x+i<n) && (y-i>-1); i++) {
        tab[x+i][y-i]--;
    }
    for (int i = 0; (x-i>-1) && (y-i>-1); i++) {
        tab[x-i][y-i]--;
    }
    for (int i = 0; (x-i>-1) && (y+i<n); i++) {
        tab[x-i][y+i]--;
    }
    tab[x][y]+=5;
    stan[x][y]--;
}

void find_odp(){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (stan[i][j] != 0) {
                odp.push_back(j);
            }
        }
    }
}

void calc(int wiersz, int local_min){
    if (local_min > global_min) return;
 //   cerr << wiersz << " " << local_min << endl;
  //  cout_tab();
    for (int j = 0; j < n; j++) {
        if (!tab[wiersz][j] && (local_min + koszt[wiersz][j]) <= global_min) {
            if (wiersz == (n-1)) {
                block(wiersz, j);
                if (local_min + koszt[wiersz][j] < global_min) {
                   // cerr << local_min + koszt[wiersz][j] << endl;
                    odp.resize(0);
                    find_odp();
                    global_min = local_min + koszt[wiersz][j];
                }
                unblock(wiersz, j);
                return;
            }
            block(wiersz , j);
            calc(wiersz+1 , local_min + koszt[wiersz][j]);
            unblock(wiersz , j);
        }
    }
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    cin >> n;
    koszt.resize(n , vector < short > (n));
    tab.resize(n , vector < short > (n));
    stan.resize(n , vector < short > (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> koszt[i][j];
        }
    }
    calc(0,0);
    for (int j = 0; j < n; j++) {
        cout << odp[j] << ' ';
    }
    return 0;
}
