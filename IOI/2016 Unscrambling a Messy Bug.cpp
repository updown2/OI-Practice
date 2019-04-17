#include "messy.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, K)
#define ffa ffi ffj
//#define s <<" "<<
#define c <<" : "<<
//#define w cout
#define e "\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
//#define int ll
const int MAXN = 128;

int N, al[MAXN], ar[MAXN];

void add_stuff(int l, int r) {
    if (l == r) return;
    string curr;
    ffi curr += '1';
    For (i, l, r+1) curr[i] = '0';
    For (i, l, (l+r)/2+1) {
        curr[i] = '1';
        add_element(curr);
        curr[i] = '0';
    }
    add_stuff(l, (l+r)/2); add_stuff((l+r)/2+1, r);
}
void solve(int l, int r) {
    if (l == r) return;
    int mid = (l+r)/2;
    /// r-l+1 elements will be in this range
    string curr;
    ffi curr += '1';
    ffi if (l == al[i] && r == ar[i]) curr[i] = '0';
    ffi if (l == al[i] && r == ar[i]) {
        curr[i] = '1';
        if (check_element(curr)) ar[i] = mid;
        else al[i] = mid+1;
        curr[i] = '0';
    }
    solve(l, mid); solve(mid+1, r);
}

std::vector<int> restore_permutation(int n, int w, int r) {
    N = n;
    /// add elements
    add_stuff(0, n-1);
    compile_set();
    /// do checks and solve
    vector<int> ret;
    ffi ar[i] = n-1;
    solve(0, n-1);
    //ffi cout<< al[i] << " " << ar[i]<<e;
    ffi ret.pb(al[i]);
    return ret;
}
