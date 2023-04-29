#include<iostream>

using namespace std;

#define F first
#define S second
#define pb push_back
#define endl '\n'


bool is_exp_of_2(long long n) {
    return ( n & (n - 1) ) == 0;
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        long long gor[n];
        string gor_name[n];
        int gor_name_id[n];
        int size = 0;
        for (int i = 0; i < n; i++){
            cin >> gor_name[i] >> gor[i];
            gor_name_id[i] = i;
            for (int j = i - 1; j > -1; j--){
                if (gor[j] > gor[j+1]) {
                    gor[j] ^= gor[j+1];
                    gor[j + 1] ^= gor[j];
                    gor[j] ^= gor[j + 1];

                    gor_name_id[j] ^= gor_name_id[j+1];
                    gor_name_id[j + 1] ^= gor_name_id[j];
                    gor_name_id[j] ^= gor_name_id[j + 1];

                } else {
                    break;
                }
            }
        }
        for (int i = 0; i < n; i++){
            if (is_exp_of_2(gor[i])) cout<< gor_name[gor_name_id[i]] <<  "-" << gor[i] <<  " ";
        }
        for (int i = 0; i < n; i++){
            if (!is_exp_of_2(gor[i])) cout<< gor_name[gor_name_id[i]]  <<  "-" << gor[i] <<  " ";
        }
        cout<< endl;
    }
    return 0;
}
