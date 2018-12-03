#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, Q)
#define ffa ffi ffj
#define s <<" "<<
#define c <<" : "<<
#define w cout
#define e endl // "/n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
#define int ll
//500,000,000 operations
const int MAXN = 2000, INF = 100000000000000;
//Global Variables
int T, x, y;
string a, b;
map<string, int> val;

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    val["Straight flush"] = 1;
    val["Four of a kind"] = 2;
    val["Full house"] = 3;
    val["Flush"] = 4;
    val["Straight"] = 5;
    val["Three of a kind"] = 6;
    val["Two pair"] = 7;
    val["Pair"] = 8;
    val["High card"] = 9;

    cin >> T;
    getline(cin, a);
    For (t, 1, T+1) {
        getline(cin, a);
        getline(cin, b);
        x = val[a]; y = val[b];
        if (x < y) w<< "Game #" << t<< ": Ryan"<<e;
        else w<< "Game #" << t<< ": Tyler"<<e;
    }
}
