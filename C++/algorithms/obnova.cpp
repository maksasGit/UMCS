    #include<iostream>
    #include<vector>
    #include<math.h>
    #include<algorithm>

    using namespace std;



    const int MAX = 2e8;


    struct Update{
        int koszt;
        int estetyka;
    };

    vector < Update > sad;
    int odpowiedz;

    int ostatni;

    void backtracking(int index, int koszt, int estetyka)
    {
        koszt+=sad[index].koszt;
        if (koszt>=odpowiedz)return;
        estetyka+=sad[index].estetyka;
        if (estetyka==0)
        {
            if (odpowiedz>koszt)odpowiedz=koszt;
            return;
        }
        for (int it=index+1;it<ostatni;it++){
            backtracking(it,koszt,estetyka);
        }
    }


    void start(int index,int rozmiar)
    {
        int koszt = 0;
        int estetyka = 0;
        ostatni=rozmiar;
        backtracking(index,koszt,estetyka);

    }

    void get_odpowiedz(int odpowiedz) {
        if (odpowiedz==MAX) cout<<"NIE\n";
        else cout<<odpowiedz<<"\n";
    }

    int main() {
        int tests; cin>>tests;
        while (tests--)
        {
            int rozmiar;
            cin>>rozmiar;
            sad.resize(rozmiar);
            odpowiedz = MAX;
            for (int it=0;it<rozmiar;it++)
            {
                cin>>sad[it].estetyka>>sad[it].koszt;
            }
            for (int it=0;it<rozmiar;it++)
            {
                start(it,rozmiar);
            }
            get_odpowiedz(odpowiedz);
        }
        return 0;
    }



