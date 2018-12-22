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
#define int ll
const int MAXN=100000, INF = 1000000000000000;
///500,000,000
int N, M, dep[MAXN], ancestor[MAXN][18], on[MAXN*4+1], lazy[MAXN*4+1], loc[MAXN], ind[MAXN];
vector<int> adj[MAXN], nums, adj2[MAXN];
bool open[MAXN], done[MAXN], fail;

void dfs(int x, int par) {
	if (x != 0) {dep[x] = dep[par]+1; ancestor[x][0] = par;}
	loc[x] = nums.size();
	nums.pb(x);
	for (int i:adj[x]) if (i != par) dfs(i, x);
	ind[x] = nums.size()-1;
}
int LCA(int A, int B) {
	if (dep[A] > dep[B]) swap(A, B);
	int d = dep[B] - dep[A];
	For (i, 0, 18) {
		if (d&(1<<i) ) B = ancestor[B][i];
	}
	if (A == B) return A;

	for (int i=17; i>= 0; i--) {
		if (ancestor[A][i] != ancestor[B][i]) {
			A = ancestor[A][i];
			B = ancestor[B][i];
		}
	}
	return ancestor[A][0];
}
int before(int A, int B) {
	if (dep[A] > dep[B]) swap(A, B);
	int d = dep[B] - dep[A]-1;
	For (i, 0, 18) {
		if (d&(1<<i) ) B = ancestor[B][i];
	}
	return B;
}
void push(int index, int L, int R) {
	if (lazy[index] == 0) return;
	on[index] += lazy[index]*(R-L+1);
	if (L != R) {
		lazy[index*2] += lazy[index];
		lazy[index*2+1] += lazy[index];
	}
	lazy[index] = 0;
}
int query (int index, int L, int R, int oL, int oR) {
	push(index, L, R);
	if ( (oR < L) || (oL > R) ) return 0;
	if ( (R <= oR) && (L >= oL) ) return on[index];

	return query(index*2, L, (L+R)/2, oL, oR) + query(index*2+1, 1+(L+R)/2, R, oL, oR );
}
void update_range (int index, int L, int R, int a, int b, int v) {
	push(index, L, R);
	if (b<L || a>R) return;
	else if (a<=L && R<= b) {
		lazy[index] = v;
		push(index, L, R);
	}
	else {
		update_range(index*2, L, (L+R)/2, a, b, v);
		update_range(index*2+1, 1+(L+R)/2, R, a, b, v);
		on[index] = on[index*2]+on[index*2+1];
	}
}

void go(int at) {
    if (done[at]) return;
    if (open[at]) {fail = true; return;}
    open[at] = true;
    for (int i: adj2[at]) go(i);
    done[at] = true;
}


main() {
    //ifstream cin("test.in");
    ifstream cin("gathering.in"); ofstream cout("gathering.out");
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	For (i, 1, N) {
        int a, b; cin >> a >> b; a--; b--; adj[a].pb(b); adj[b].pb(a);
	}
	dfs(0, 0);
	//for (int i: nums) w<< i+1<<e; w<<e;
	//ffi w<< loc[i] s ind[i]<<e;
	//ffi w<< ancestor[i][0]<<e;
	For (k, 0, 17) ffi ancestor[i][k+1] = ancestor[ancestor[i][k]][k];
	int sum = 0;
	ffj {
        int a, b; cin >> a >> b; a--; b--; adj2[a].pb(b);
        if (LCA(a, b) == a) {
            /// b is below a, st(a)++
            sum++;
            a = before(a, b);
            //w<< 'a' c a+1<<e;
            if (loc[a] == ind[a]) continue;
            update_range(1, 0, N-1, loc[a], ind[a], 1);
        }
        else {
            /// st(a)--
            //w<< "b not below a"<<e;
            update_range(1, 0, N-1, loc[a], ind[a], -1);
        }
	}
	ffi go(i);
	if (fail) {ffi w<<0<<e; return 0;}
	ffi {
	    if (query(1, 0, N-1, loc[i], loc[i]) == sum) w<<1<<e;
	    else w<< 0<<e;
	}
}
