#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define pb push_back
#define endl '\n'


struct KOLO{
    int x,y,r;
};

struct DOT{
    int x;
    int id;
    int type;
};

bool compare(const DOT &a, const DOT &b) {
    if (a.x != b.x) {
        return a.x < b.x;
    }
    else {
        return a.type < b.type;
    }
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int k;
    cin >> k;
    while (k--){
        int n;
        cin >> n;
        KOLO a[n];
        for (int i = 0; i < n; i++){
            cin >> a[i].x >> a[i].y >> a[i].r;
        }
        DOT b[n*2];
        map < int , pair < int , int >> y_connect;
        for (int i = 0; i < n; i++) {
            y_connect[i] = make_pair(a[i].y-a[i].r, a[i].y+a[i].r);
            b[i*2].x = a[i].x - a[i].r;
            b[i*2].id = i;
            b[i*2].type = 0;
            b[i*2+1].x = a[i].x + a[i].r;
            b[i*2+1].id = i;
            b[i*2+1].type = 1;
        }
        sort(b, b + n*2, compare);
        vector <pair < pair < int , int > , int> > curr_y;
        bool ne_ok = true;
        for (int i = 0; i < n*2; i++) {
            if (b[i].type == 0) {
                int left = y_connect[b[i].id].first;
                int right = y_connect[b[i].id].second;
                for (int j = 0; j < curr_y.size(); j++) {
                    if ((left < curr_y[j].F.S && left > curr_y[j].F.F) || (right < curr_y[j].F.S && right > curr_y[j].F.F)) {
                        ne_ok = false;
                        continue;
                    }
                }
                if (!ne_ok) break;
                curr_y.push_back({{left ,right}, b[i].id});
            } else {
                for (int j = 0; j < curr_y.size(); j++) {
                    if (curr_y[j].S == b[i].id){
                        curr_y.erase(curr_y.begin() + j);
                    }
                }
            }
        }
        if (ne_ok) {
            cout << "T\n";
        } else {
            cout << "N\n";
        }
    }
    return 0;
}


