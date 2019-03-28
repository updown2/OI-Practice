#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100001;
int N, inp[MAXN], ft[MAXN];
void update(int x, int v) {while(x<=N) ft[x]+=v, x+=(x&-x);}
int query (int x) { return x>0 ? ft[x]+query(x-(x&-x)):0;}

int main() {
    ifstream cin("sleepy.in");ofstream cout("sleepy.out");
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> inp[i];
    }
    /// find the finished range at the end
    int range = 1;
    update(inp[N-1], 1);
    for (int i=N-2; i>=0; i--) {
        if (inp[i] < inp[i+1]) {
            update(inp[i], 1);
            range++;
        }
        else {
            break;
        }
    }
    int out1 = N-range;
    cout << out1 << endl;
    for (int i=0; i<out1; i++) {
        cout << N-range-1 + query(inp[i]);
        if (i != out1-1) cout<< " ";
        update(inp[i], 1);
        range++;
    }
    cout << endl;
}
