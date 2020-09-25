/*
Find the longest continuous sequence of K+1 ids using 2 pointers
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN=100000;

int N, K, on, out, inp[MAXN];
map<int, int> cnt;


void add(int i) {
    if (cnt.find(inp[i]) == cnt.end()) {
		cnt[inp[i]] = 0;
	}
    if (cnt[inp[i]] == 0) {
		on++;
	}
    cnt[inp[i]]++;
}
void remove(int i) {
    i = inp[i];
    cnt[i] --;
    if (cnt[i] == 0) {
		on--;
	}
}

int main() {
    //ifstream cin("test.in");
    ifstream cin("lineup.in"); ofstream cout("lineup.out");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    for (int i=0; i<N; i++) {
		cin >> inp[i];
	}
	
	int lp = 0;
	for (int rp=0; rp<N; rp++) {
		add (rp);
		while (on > K+1) {
			remove (lp);
			lp++;
		}
		out = max(out, cnt[inp[rp]]);
	}

    cout<< out<<endl;
}
