#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, M)
#define s <<" "<<
#define w cout
#define e endl
#define pb push_back
#define mp make_pair
#define a first
#define b second
//500,000,000 operations
//Global Variables
struct Node {
	int inside, left, right;
};
int N, Q;
Node on[4*500000+1];
int lazy[4*500000+1];

void push(int ind, int L, int R) {
	if (lazy[ind] == -1) return;
	if (lazy[ind] == 0) {
		on[ind].inside = on[ind].left = on[ind].right = 0;
	}
	else {
		on[ind].inside = on[ind].left = on[ind].right = R-L+1;
	}

	if (L != R) {
		lazy[ind*2] = lazy[ind];
		lazy[ind*2+1] = lazy[ind];
	}
	lazy[ind] = -1;
}
void build (int index, int L, int R) {
	lazy[index] = -1;
	on[index].inside = on[index].left = on[index].right = R-L+1;
	if (L != R) {
		build(index*2, L, (L+R)/2);
		build(index*2+1, 1+(L+R)/2, R);
	}
}
int query (int index, int L, int R, int oL) {
	push(index, L, R);
	if ( L==R ) {
		if (on[index].inside >= oL) return L;
		return 1000000;
	}

	if (on[index].inside >= oL) {
		int out = query(index*2, L, (L+R)/2, oL);
		if (out != 1000000) return out;
		out = query(index*2+1, 1+(L+R)/2, R, oL);
		if (on[index*2].right+on[index*2+1].left >= oL) out = min(out, (L+R)/2-on[index*2].right+1);
		//w<< index s oL s on[index].inside s out<<e;
		return out;
	}
	return 1000000;
} //returns smallest index
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
		on[index].inside = max(on[index*2].inside, on[index*2+1].inside);
		on[index].inside = max(on[index].inside, on[index*2].right+on[index*2+1].left);
		on[index].right = on[index*2+1].right;
		if (on[index].right == R-(L+R)/2) on[index].right += on[index*2].right;
		on[index].left = on[index*2].left;
		if (on[index].left == (L+R)/2-L+1) on[index].left += on[index*2+1].left;
	}
}

int main() {
	//ifstream cin ("test.in");
	ifstream cin ("seating.in"); ofstream cout ("seating.out");
	cin >> N >> Q;

	build(1, 1, N);

	int out = 0;
	char a;
	int b, c;
	//w<< query(1, 1, N, 2)<<e;
	For (i, 0, Q) {
		cin >> a >> b;
		if (a == 'A') {
			int d = query(1, 1, N, b);
			if ( d == 1000000) out++;
			else {
				update_range(1, 1, N, d, d+b-1, 0);
			}
		}
		else {
			cin >> c;
			update_range(1, 1, N, b, c, 1);
		}
	}
	w<<out<<e;
	return 0;
}
