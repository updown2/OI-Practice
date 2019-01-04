/*
store the count of each letter for the range x to x+N-M+1
add the count of the letter in the small string to the answer for every x
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
#define e endl//"\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
//#define int ll
const int MAXN=2000001, INF=1000000000;
///500,000,000
int N, M, cnt[26];
ll out;
string a, b;

main() {
    //ifstream cin("test.in");
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> b >> a; N = a.length(); M = b.length();
    For (i, 1, N+1) {
        cnt[a[i-1]-'a']++;
        if (i-N+M-1 >= 0) {
            out += cnt[b[i-N+M-1]-'a'];
            cnt[a[i-N+M-1]-'a']--;
        }
    }
	w<< out<<e;
}
