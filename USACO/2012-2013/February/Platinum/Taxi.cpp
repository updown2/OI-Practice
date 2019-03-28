#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 1, K)
#define ffa ffi ffj
#define s <<" "<<
#define c <<" : "<<
#define w cout
#define e "\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
#define int ll
//500,000,000 operations
const int MAXN = 200002;
//Global Variables
int N, M, inp[MAXN][2], K, up[MAXN], down[MAXN], out;
set<int> loc;
vector<int> ranges;

void updateup(int x, int y) {
    /// binary search to find where x is
    int a = 0, b = K-1; /// could make b = K-2
    while (a != b) {
        int mid = (a+b)/2;
        if (ranges[mid] < x) a = mid+1;
        else b = mid;
    }
    up[a+1]++;
    a = 0, b = K-1; /// could make a = 1
    while (a != b) {
        int mid = (a+b)/2;
        if (ranges[mid] < y) a = mid+1;
        else b = mid;
    }
    up[a+1]--;
}
void updatedown(int x, int y) {
    /// binary search to find where x is
    int a = 0, b = K-1; /// could make b = K-2
    while (a != b) {
        int mid = (a+b)/2;
        if (ranges[mid] < x) a = mid+1;
        else b = mid;
    }
    down[a+1]++;
    a = 0, b = K-1; /// could make a = 1
    while (a != b) {
        int mid = (a+b)/2;
        if (ranges[mid] < y) a = mid+1;
        else b = mid;
    }
    down[a+1]--;
}

main() {
    //ifstream cin ("test.in");
    ifstream cin("taxi.in"); ofstream cout("taxi.out");
    ios_base::sync_with_stdio; cin.tie(0);
    cin >> N >> M;
    ffi {
        cin >> inp[i][0] >> inp[i][1];
        loc.insert(inp[i][0]);
        loc.insert(inp[i][1]);
    }
    loc.insert(0); loc.insert(M);
    for (int i: loc) ranges.pb(i); K = ranges.size();
    ffi {
        if (inp[i][0] < inp[i][1]) updateup  (inp[i][0], inp[i][1]);
        if (inp[i][0] > inp[i][1]) updatedown(inp[i][1], inp[i][0]);
    }
    ffj {
        up[j] += up[j-1];
        down[j] += down[j-1];
    }
    ffj {
        up[j] = max((int)1, up[j]);
        int range = ranges[j] - ranges[j-1];
        if (up[j] > down[j]) out += range*(up[j]*2-1);
        else out += range*(2*down[j]+1);
    }
    //ffj w<< up[j] s down[j]<<e;
    w<< out<<e;
}
