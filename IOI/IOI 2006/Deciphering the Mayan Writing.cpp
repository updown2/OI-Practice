/*
Keep a map to store the current window of letters
Loop through all 26*2 letters in the map to see if there is a match
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, M)
#define ffa ffi ffj
#define s <<" "<<
#define c <<" : "<<
#define w cout
#define e endl
#define pb push_back
#define mp make_pair
#define a first
#define b second
#define int ll
const int MAXN = 3000000;
//500,000,000 operations
int M, N, out;
char inp[MAXN];
map<char, int> goal, window;

void check() {
    For (i, 0, 26) {
        if (goal['A'+i] != window['A'+i]) return;
        if (goal['a'+i] != window['a'+i]) return;
    }
    out++;
}

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    For (i, 0, 26) {goal['A'+i] = 0; goal['a'+i] = 0; window['A'+i] = 0; window['a'+i] = 0;}
    cin >> M >> N;
    ffj {char a; cin >> a; goal[a]++;}
    ffi cin >> inp[i];
    ffj window[inp[j]]++;
    check();
    For (i, M, N) {
        window[inp[i-M]]--;
        window[inp[i]]++;
        check();
    }
    w<< out<<e;
}
