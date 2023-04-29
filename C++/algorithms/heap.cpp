#include<iostream>
#include<vector>

using namespace std;


struct Node{
    int val = 0;
    int id = 0;
};

struct Otvet{
    int perv;
    int vtor;
};

 vector < Node > drew;
 int ostatni = -1;


  void go()
{
    int i=1;
    while(i<=ostatni)
    {
        int best_go = i;
        int was=i/2;
        if (drew[i+1].val>drew[i].val || (drew[i+1].val == drew[i].val && drew[i+1].id<drew[i].id)) best_go = i + 1;
        if(drew[best_go].val>drew[was].val || (drew[best_go].val == drew[was].val && drew[best_go].id < drew[was].id)) swap(drew[best_go],drew[was]);
        else return;
        i=best_go*2;
    }
}

void push(){
    int now = ostatni, go = now/2;
    while(now>0)
    {
        if (drew[now].val > drew[go].val || (drew[now].val == drew[go].val && drew[now].id<drew[go].id))
        {
            swap(drew[now], drew[go]);
            now/=2; go=now/2;
        }
        else return;
    }
}


Node get(){
    Node x;
    x=drew[0];
    drew[0]=drew[ostatni];
    ostatni--;
    go();
    return x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tests;
    cin >> tests;
    for (int test=0; test < tests; test++)
    {
        ostatni=-1;
        int n; cin>>n;
        drew.clear();
        for (int i=0;i<n;i++)
        {
            int val,id;
            cin >> val; id=i+1;
            if (val>0)
            {
                drew.push_back({val , id});
                ostatni++;
                push();
            }
        }
        vector < Otvet > odpowiedz;
        int ans = 0;
        while (ostatni>0){
            Node raz[2];
            raz[0]=get();
            raz[1]=get();
            ans++;
            raz[1].val--;
            raz[0].val--;
            if (raz[1].id < raz[0].id) swap(raz[0] , raz[1]);
            odpowiedz.push_back({raz[0].id , raz[1].id});
            if (raz[0].val>0)
            {
                ostatni++;
                drew[ostatni]=raz[0];
                push();
            }
            if (raz[1].val>0) {
                ostatni++;
                drew[ostatni]=raz[1];
                push();
            }

        }
        cout << ans << "\n";
        for (int i = 0; i < odpowiedz.size(); i++) {
            cout << odpowiedz[i].perv << ' ' << odpowiedz[i].vtor<< "\n";
        }
    }
    return 0;
}


