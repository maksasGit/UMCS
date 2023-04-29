#include<iostream>

using namespace std;

struct Node{
    string name;
    float val[3];
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int krit[3];
    for (int i = 0; i < 3; i++) {
        cin >> krit[i];
    }
    Node warz[n];
    for (int i = 0; i < n; i++) {
        Node add;
        cin >> add.name >> add.val[0] >> add.val[1] >> add.val[2];
        int get = i;
        bool f = 1;
        for (int j = i - 1 ; j>-1; j--){
            for (int it = 0; it < 3; it++) {
                if (add.val[krit[it]-1]==warz[j].val[krit[it]-1]) continue;
                if (add.val[krit[it]-1]>warz[j].val[krit[it]-1]) {
                    warz[j+1]=warz[j];
                    f = 0;
                    get = j;
                    break;
                } else if (add.val[krit[it]-1]<warz[j].val[krit[it]-1]) {
                    f=1;
                    break;
                }
            }
            if (f) break;
        }
        warz[get]=add;
    }
    Node korn[n];
    for (int i = 0; i < n; i++) {
        Node add;
        cin >> add.name >> add.val[0] >> add.val[1] >> add.val[2];
        int get = i;
        bool f = 1;
        for (int j = i - 1 ; j>-1; j--){
            for (int it = 0; it < 3; it++) {
                if (add.val[krit[it]-1]==korn[j].val[krit[it]-1]) continue;
                if (add.val[krit[it]-1]>korn[j].val[krit[it]-1]) {
                    korn[j+1]=korn[j];
                    get=j;
                    f = 0;
                    break;
                } else if (add.val[krit[it]-1]<korn[j].val[krit[it]-1]) {
                    f = 1;
                    break;
                }
            }
            if (f) break;
        }
        korn[get]=add;
    }
    for (int i = 0; i < n; i++) cout << warz[i].name << "-"  << korn[i].name << " ";
    return 0;
}


