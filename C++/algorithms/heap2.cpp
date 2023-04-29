#include <iostream>

using namespace std;

int ostatni_index_tab;

struct Osoba
{
    int towarzyskosc;
    int numer;
};

void przesiewanie_w_gore(Osoba *tablica)
{
    int i=ostatni_index_tab;

    while(i>1)
    {
        if(tablica[i].towarzyskosc>tablica[i/2].towarzyskosc) swap(tablica[i],tablica[i/2]);
        else if((tablica[i].towarzyskosc==tablica[i/2].towarzyskosc)&&(tablica[i].numer<tablica[i/2].numer)) swap(tablica[i],tablica[i/2]);
        else return;

        i=i/2;
    }
}

void przesiewanie_w_dol(Osoba *tablica)
{
    int i=2;

    while(i<=ostatni_index_tab)
    {
        if(tablica[i+1].towarzyskosc>tablica[i].towarzyskosc)
        {
            if(tablica[i+1].towarzyskosc>tablica[i/2].towarzyskosc) swap(tablica[i+1],tablica[i/2]);
            else if((tablica[i+1].towarzyskosc==tablica[i/2].towarzyskosc)&&(tablica[i+1].numer<tablica[i/2].numer)) swap(tablica[i+1],tablica[i/2]);
            else return;

            i=(i+1)*2;
        }

        else if((tablica[i+1].towarzyskosc==tablica[i].towarzyskosc)&&(tablica[i+1].numer<tablica[i].numer))
        {
            if(tablica[i+1].towarzyskosc>tablica[i/2].towarzyskosc) swap(tablica[i+1],tablica[i/2]);
            else if((tablica[i+1].towarzyskosc==tablica[i/2].towarzyskosc)&&(tablica[i+1].numer<tablica[i/2].numer)) swap(tablica[i+1],tablica[i/2]);
            else return;

            i=(i+1)*2;
        }

        else
        {
            if(tablica[i].towarzyskosc>tablica[i/2].towarzyskosc) swap(tablica[i],tablica[i/2]);
            else if((tablica[i].towarzyskosc==tablica[i/2].towarzyskosc)&&(tablica[i].numer<tablica[i/2].numer)) swap(tablica[i],tablica[i/2]);
            else return;

            i=i*2;
        }
    }
}

void dodaj(Osoba *tablica, int towarzyskosc, int numer)
{
    if(towarzyskosc<1) return;

    ostatni_index_tab++;
    tablica[ostatni_index_tab].towarzyskosc=towarzyskosc;
    tablica[ostatni_index_tab].numer=numer;
    przesiewanie_w_gore(tablica);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int ilosc_rozmow, t, n, temp;
    Osoba *tablica_osob=nullptr;

    cin>>t;

    for(int i=0; i<t; i++)
    {
        cin>>n;

        tablica_osob=new Osoba[n+1];
        ilosc_rozmow=0;
        ostatni_index_tab=0;

        for(int j=1; j<=n; j++)
        {
            cin>>temp;
            dodaj(tablica_osob,temp,j);
        }

        int ostatni_index_tab_kopia=ostatni_index_tab;
        Osoba *tablica_osob_kopia=new Osoba[n+1];

        for(int i=1; i<=n; i++)
        {
            tablica_osob_kopia[i]=tablica_osob[i];
        }

        while(ostatni_index_tab>1)
        {
            Osoba osoba1;
            Osoba osoba2;

            osoba1=tablica_osob[1];
            tablica_osob[1]=tablica_osob[ostatni_index_tab];
            ostatni_index_tab--;

            przesiewanie_w_dol(tablica_osob);

            osoba2=tablica_osob[1];
            tablica_osob[1]=tablica_osob[ostatni_index_tab];
            ostatni_index_tab--;

            przesiewanie_w_dol(tablica_osob);

            ilosc_rozmow++;

            osoba1.towarzyskosc--;
            osoba2.towarzyskosc--;

            dodaj(tablica_osob,osoba1.towarzyskosc,osoba1.numer);
            dodaj(tablica_osob,osoba2.towarzyskosc,osoba2.numer);
        }

        cout<<ilosc_rozmow<<"\n";

        delete [] tablica_osob;
        tablica_osob=tablica_osob_kopia;
        tablica_osob_kopia=nullptr;
        ostatni_index_tab=ostatni_index_tab_kopia;

        while(ostatni_index_tab>1)
        {
            Osoba osoba1;
            Osoba osoba2;

            osoba1=tablica_osob[1];
            tablica_osob[1]=tablica_osob[ostatni_index_tab];
            ostatni_index_tab--;

            przesiewanie_w_dol(tablica_osob);

            osoba2=tablica_osob[1];
            tablica_osob[1]=tablica_osob[ostatni_index_tab];
            ostatni_index_tab--;

            przesiewanie_w_dol(tablica_osob);

            ilosc_rozmow++;

            osoba1.towarzyskosc--;
            osoba2.towarzyskosc--;

            dodaj(tablica_osob,osoba1.towarzyskosc,osoba1.numer);
            dodaj(tablica_osob,osoba2.towarzyskosc,osoba2.numer);

            if(osoba1.numer<osoba2.numer)
            {
                cout<<osoba1.numer;
                cout<<" ";
                cout<<osoba2.numer;
                cout<<"\n";
            }
            else
            {
                cout<<osoba2.numer;
                cout<<" ";
                cout<<osoba1.numer;
                cout<<"\n";
            }
        }

        delete [] tablica_osob;
        tablica_osob = nullptr;
    }

    return 0;
}
