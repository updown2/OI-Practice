/*
Find the longest continuous sequence of K+1 ids using 2 pointers
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, M)
#define ffa ffi ffj
#define s <<" "<<
#define w cout
#define e "\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
#define int ll
const int MAXN=100000, INF=100000000;
///500,000,000
int N, K, on, out, inp[MAXN];
map<int, int> curr;


void add(int i) {
    if (curr.find(inp[i]) == curr.end()) curr[inp[i]] = 0;
    if (curr[inp[i]] == 0) on++;
    curr[inp[i]]++;
}
void del(int i) {
    i = inp[i];
    curr[i] --;
    if (curr[i] == 0) on--;
}

main() {
    //ifstream cin("test.in");
    ifstream cin("lineup.in"); ofstream cout("lineup.out");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    ffi cin >> inp[i];
    int at1 = 0, at2 = 0;
    while (at2 != N) {
        add (at2);
        while (on > K+1) {del(at1); at1++;}
        out = max(out, curr[inp[at2]]);
        at2++;
    }
    w<< out<<e;
}