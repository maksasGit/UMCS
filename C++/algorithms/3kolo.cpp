#include<iostream>

using namespace std;

#define F first
#define S second
#define pb push_back
#define endl '\n'

struct KOLO{
    int x,y,r;
};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 //   freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
    int k;
    cin >> k;
    while (k--){
        int n;
        cin >> n;
        KOLO a[n];
        for (int i = 0; i < n; i++){
            cin >> KOLO.x >> KOLO.y >> KOLO.r;
        }
    }
    return 0;
}

