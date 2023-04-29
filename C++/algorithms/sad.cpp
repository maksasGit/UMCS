#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define pb push_back

struct Node{
    int val = 0;
    int id = 0;
    int pred = 0;
};

 vector < Node > heap;
 int last = -1;

 int get_pred(int x) {
    if (x == 0) return -1;
    return (x - 1) / 2;
 }

 void go(int to , int curr) {
    if (to < 0) return ;
    if (heap[to].val < heap[curr].val) {
        int a, b;
        a = heap[curr].pred;
        b = heap[to].pred;
        swap(heap[to], heap[curr]);
        heap[curr].pred = a;
        heap[to].pred = b;
        go(heap[to].pred , to);
    }
 }

 pair < int , int > take(){
    int x = heap[0].val;
    int y = heap[0].id;
    heap[0] = heap[last];
    heap[0].pred = -1;
    heap[last].val = -100;
    heap[last].id = -101;
    heap[last].pred = -102;
    last--;
    return {x, y};
 }

void push(int curr) {
//    for (int i = 0; i <= last; i++) {
//            cout << heap[i].val << ' ' << heap[i].id << ' ' << heap[i].pred << endl;
//        }
//        cout << endl;
    int to_1 = curr * 2 + 1;
    int to_2 = curr * 2 + 2;
    if (to_2 > last) to_2 = to_1;
    int to = to_1;
    if (to > last) return;
    if (heap[to_1].val < heap[to_2].val) {
        to = to_2;
    } else if (heap[to_1].val == heap[to_2].val && heap[to_1].id > heap[to_2].id) {
        to = to_2;
    }
    if (heap[curr].val < heap[to].val) {
            int a, b;
        a = heap[curr].pred;
        b = heap[to].pred;
        swap(heap[curr] , heap[to]);
        heap[curr].pred = a;
        heap[to].pred = b;
        push(to);
    } else if (heap[curr].val == heap[to].val && heap[curr].id > heap[to].id){
        int a, b;
        a = heap[curr].pred;
        b = heap[to].pred;
        swap(heap[curr] , heap[to]);
        heap[curr].pred = a;
        heap[to].pred = b;
        push(to);
    }
//    for (int i = 0; i <= last; i++) {
//            cout << heap[i].val << ' ' << heap[i].id << ' ' << heap[i].pred << endl;
//        }
//        cout << endl;
}

 void add(int x , int id) {
    last++;
    Node push;
    Node per;
    per.val = x;
    per.id = id;
    per.pred = get_pred(last);
    heap.pb(per);
    go(heap[last].pred , last);

 }

  void add_after(int x , int id) {
    last++;
    Node push;
    Node per;
    per.val = x;
    per.id = id;
    per.pred = get_pred(last);
    heap[last] = per;
    go(heap[last].pred , last);

 }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        heap.clear();
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            add(x , i + 1);
        }
        pair < int , int > talk[2];
        int kol = -1;
        long long ans = 0;
        vector <pair < int , int > > talks;
        int it = 0;
//        for (int i = 0; i <= last; i++) {
//            cout << heap[i].val << ' ' << heap[i].id << ' ' << heap[i].pred << endl;
//        }
//        cout << endl;
        while (last > -1) {
            kol++;
            talk[kol] = take();
            push(0);
            if (kol == 0 || talk[1].F == 0) continue;
            talk[0].F--;
            talk[1].F--;
            kol = -1;
            ans++;
//            for (int i = 0; i <= last; i++) {
//                cout << heap[i].val << ' ' << heap[i].id << ' ' << heap[i].pred << endl;
//            }
//            cout << endl;
            if (talk[0].F > 0) add_after(talk[0].F , talk[0].S);
            if (talk[1].F > 0) add_after(talk[1].F , talk[1].S);
            int push_x = min(talk[0].S , talk[1].S);
            int push_y = max(talk[0].S , talk[1].S);
            talks.pb({push_x , push_y});
//            for (int i = 0; i <= last; i++) {
//                cout << heap[i].val << ' ' << heap[i].id << ' ' << heap[i].pred << endl;
//            }
//            cout << endl;
        }
        cout << ans << endl;
        for (int i = 0; i < talks.size(); i++) {
            cout << talks[i].F << ' ' << talks[i].S << "\n" ;
        }
    }
    return 0;
}


