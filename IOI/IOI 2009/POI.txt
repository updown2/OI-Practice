/*
Brute force
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, T)
#define ffa ffi ffj
#define s <<" "<<
#define w cout
#define e "\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
#define int ll
//500,000,000 operations
const int MAXN = 2000;
//Global Variables
int N, T, P, pts[MAXN];
bool got[MAXN][MAXN];
pair<int, pair<int, int> > ord[MAXN]; /// (-score, (-num tasks solved, id))

main() {
	//ifstream cin ("test.in");
	ios_base::sync_with_stdio; cin.tie(0);
	cin >> N >> T >> P;
	ffa {
		int a; cin >> a; got[i][j] = (a == 1);
		if (a == 0) pts[j]++;
	}
	ffa if (got[i][j]) {
		ord[i].a -= pts[j];
		ord[i].b.a --;
	}
	ffi ord[i].b.b = i;
	sort(ord, ord+N);
	ffi if (ord[i].b.b == P-1) w<< -ord[i].a s i+1<<e;
}