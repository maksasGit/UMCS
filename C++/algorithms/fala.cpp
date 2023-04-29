#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define pb push_back
#define endl '\n'

short n;
bool kierunek;

struct czlowiek{
    bool strona; // 0 - right , 1 - left
    short numer;
    czlowiek * next;
    czlowiek * past;
};

czlowiek * curr;
czlowiek krug[20000];
short all;

struct koleja{
    int val;
    koleja * next;
};



koleja * tail;
koleja * head;


koleja oczered[4000];
int rozmiar = 0;
int next_empt = 0;

koleja empty_space[4000];
int rozmiar_empty_space = 0;
int next_empt_2 = 0;

koleja * head_e;
koleja * tail_e;

void add2(int val){

    if (!rozmiar_empty_space) {
        rozmiar_empty_space++;
        next_empt_2++;
        empty_space[next_empt_2].val = val;
        tail_e = &empty_space[next_empt_2];
        head_e = &empty_space[next_empt_2];
    } else{
        rozmiar_empty_space++;
        next_empt_2++;
        empty_space[next_empt_2].val = val;
        empty_space[next_empt_2-1].next = &empty_space[next_empt_2];
        tail_e = &empty_space[next_empt_2];
    }
}

void del_kol_2() {
    if (rozmiar_empty_space) {
        head_e = head_e->next;
        rozmiar_empty_space--;
    }
}


void add(int val){
    if (!rozmiar) {
        rozmiar++;
        next_empt++;
        oczered[next_empt].val = val;
        tail = &oczered[next_empt];
        head = &oczered[next_empt];
    } else{
        rozmiar++;
        next_empt++;
        oczered[next_empt].val = val;
        oczered[next_empt-1].next = &oczered[next_empt];
        tail = &oczered[next_empt];
    }
}


void del_kol() {
    if (rozmiar) {
        head = head->next;
        rozmiar--;
    }
}


void go(short steps, bool show_trip){
     for (short i = 0; i < steps - 1; i++) {
        if (show_trip) cout << curr->numer << " ";
        if (kierunek) {   // go by kierunek
            curr = curr->past;
        } else {
            curr = curr->next;
        }
    }
    if (show_trip) cout << curr->numer << endl;
}


bool del[10000];

void kill(bool death){
     for (short i = 0; i < n*2; i++) {
        if (curr->numer == krug[i].numer && curr->strona == krug[i].strona) {
            kierunek^=1;
            go(2,0);

            czlowiek * left = krug[i].past;
            czlowiek * right = krug[i].next;
            left->next = right;
            right->past = left;

            all--;
            add2(i);
            if (del[krug[i].numer]) {
                add(krug[i].numer);
                del[krug[i].numer] = 0;
            }
            else del[krug[i].numer]=1;
            krug[i].numer=-228;
            krug[i].strona=0;

            if (all <= 3) death = true;
            if (death && rozmiar){
                short new_id_1 = head_e->val;
                del_kol_2();
                all++;
                short new_id_2 = head_e->val;
                del_kol_2();
                all++;
                krug[new_id_1].numer = head->val;
                del_kol();
                krug[new_id_1].strona=false;
                krug[new_id_2].numer = krug[new_id_1].numer;
                krug[new_id_2].strona = true;
                czlowiek * lewy = right;
                czlowiek * prawy = lewy->next;
                czlowiek * nowy = &krug[new_id_1];
                lewy->next = nowy;
                nowy->past = lewy;
                nowy->next = prawy;
                prawy->past = nowy;
                prawy = left;
                lewy = prawy->past;
                nowy = &krug[new_id_2];
                lewy->next = nowy;
                nowy->past = lewy;
                nowy->next = prawy;
                prawy->past = nowy;
            }
            break;

        }
     }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    short start;
    cin >> n >> start >> kierunek;
    all = n*2;
    for (short i = 0; i < n*2; i++) {    // создаем n*2 массив. Один левый, другой правый.
        if (i%2) {
            krug[i].numer = (i/2) ;       // if не нужен
            krug[i].strona = i%2;
        } else {
            krug[i].numer = (i / 2);
            krug[i].strona = i%2;
        }
    }
    for (short i = 0; i < n*2; i++) {          // указываем соседей => создаем круг
        if (!i) {
            krug[i].next = &krug[i + 1];
            krug[i].past = &krug[n*2-1];
        } else if (i==(n*2-1)) {
            krug[i].next = &krug[0];
            krug[i].past = &krug[i - 1];
        } else {
            krug[i].next = &krug[i + 1];
            krug[i].past = &krug[i - 1];
        }
    }

    for (short i = 0; i < n * 2; i++) {    // сдвигаем правых вправо
        if (krug[i].strona) {
            if (krug[i].numer == 0) krug[i].numer = n-1;
            else {
                krug[i].numer--;
            }
        }
    }
    short m; cin >> m;
    for (short i = 0; i < n*2; i++) {      // находим стартовый
        if (krug[i].numer == start && !krug[i].strona) curr = &krug[i];
    }
    while (m--) {               // выполняем запросы
        short mov;
        cin >> mov;
        short steps; cin >> steps;
        go(steps , 0);          // двигаемся
        switch(mov){
            case 0: {           //
                czlowiek * save = curr;
                go(all, 1);
                curr = save;
                }break;
            case 1:     // убиваем если можно
                bool death; cin >> death;
                kill(death);
                break;
            case 2:         // меняем направление
                kierunek ^= 1;
                break;
        }
    }
    return 0;
}
