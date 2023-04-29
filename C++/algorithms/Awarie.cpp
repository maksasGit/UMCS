#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define pb push_back
#define endl '\n'

class MinHeap {
  private:
    vector< pair <int , int > > heap;
    int left(int parent);
    int right(int parent);
    int parent(int child);
    void heapify_up(int index);
    void heapify_down(int index);
  public:
    MinHeap();
    pair < int , int > top();
    void push(pair < int , int > element);
    void pop();
    void remove_last();
    pair < int , int > last();
    bool empty();
    void print();
};

MinHeap::MinHeap() {}

int MinHeap::left(int parent) {
    return (parent*2)+1;
}

int MinHeap::right(int parent) {
    return (parent*2)+2;
}

int MinHeap::parent(int child) {
    return (child-1)/2;
}

void MinHeap::heapify_up(int index) {
    if(index && heap[index].F < heap[parent(index)].F) {
        swap(heap[index], heap[parent(index)]);
        heapify_up(parent(index));
    }
}

void MinHeap::heapify_down(int index) {
    int child = left(index);
    int child_r = right(index);
    if(child_r < heap.size() && heap[child_r].F < heap[child].F) {
        child = child_r;
    }
    if(child < heap.size() && heap[child].F < heap[index].F) {
        swap(heap[index], heap[child]);
        heapify_down(child);
    }
}

pair < int , int >  MinHeap::top() {
    return heap[0];
}

void MinHeap::push(pair < int , int > element) {
     heap.push_back(element);
     int index = heap.size() - 1;
     heapify_up(index);
}

void MinHeap::pop() {
    int last = heap.size() - 1;
    swap(heap[0], heap[last]);
    heap.pop_back();
    heapify_down(0);
}

bool MinHeap::empty() {
    return heap.empty();
}

void MinHeap::print() {
    for(auto x: heap) {
        cout << x.F<<"-"<<x.S << " ";
    }
    cout << endl;
}

void MinHeap::remove_last() {
    heap.pop_back();
}

pair < int , int >  MinHeap::last() {
    return heap.back();
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--){
        int m;
        cin >> m;
        MinHeap heap = MinHeap();
        for (int i = 0; i < m; i++){
            int x; cin >> x;
            switch(x){
            case 0:
                int a , b;
                cin >> a >> b;
                heap.push(make_pair(-b , a));
                break;
            case 1:
                if (!heap.empty()) {
                cout << heap.top().S << endl;
                heap.pop();
                }
                break;
            case 2:
                if (!heap.empty()){
                cout << heap.last().S << endl;
                heap.remove_last();
                }
                break;
            }
        //heap.print();
        }
    }
    return 0;
}

