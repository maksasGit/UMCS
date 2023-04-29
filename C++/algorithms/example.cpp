#include<bits/stdc++.h>

using namespace std;


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string s;
    cin >> s;
    int t[26];
    for (int i = 0; i < 26; i++) {
        t[i] = 0;
    }
    for (int i = 0; i < s.size(); i++) {
        t[s[i]-'a']++;
    }
    for (int i = 0; i < 26; i++) {
        cout << t[i] << endl;
    }
    int maxx=-1;
    char max_char=' ';
    for (int i = 0; i < 26; i++) {
        if (t[i]>maxx) {
            maxx = t[i];
            max_char=char(i+97);
        }
    }
    cout << "MAX LICZBA : " <<max_char << ' ' << maxx << endl;
    return 0;
}


