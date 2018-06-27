/*
the sum of angles is (A-2)*180 for A = N, N-2, N-4, ... with some exceptions
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, N)
#define ffa ffi ffj
#define s <<" "<<
#define w cout
#define e "\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
//#define int ll
const int MAXN=1000002, INF=1000000000000000000;
///500,000,000
ll N, out;
ll gcd(ll a, ll b) { return a==0 ? b:gcd(b%a, a); }

int main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N; N++;
    For (i, 1, N) if (gcd(N, i) == 1) out++;
    w<< out<<e;
}
