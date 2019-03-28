#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 1, N+1)
#define ffj For(j, 1, N+1)
#define ffa ffi ffj
#define s <<" "<<
#define c <<" : "<<
#define w cout
#define e "\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
#define double long double
//500,000,000 operations
const int MAXN = 1000001;
//Global Variables
int N;
double inp[MAXN], pre[MAXN], out;

main() {
    //ifstream cin ("test.in");
    ifstream cin("cowdate.in"); ofstream cout("cowdate.out");
    ios_base::sync_with_stdio; cin.tie(0);
    cin >> N;
    pre[0] = 1;
    ffi {
        int a; cin >> a; inp[i] = a/(double)1000000;
        pre[i] = pre[i-1]*(1-inp[i]);
        out = max(inp[i], out);
    }
    //ffi w<< inp[i]<<e;
    int i=1, j = 2;
    double curr = inp[1];
    while (j <= N) {
        /// add j
        curr *= (1-inp[j]);
        //w<< curr<<e;
        curr += pre[j-1]/pre[i-1] * inp[j];
        //w<< "add" s i s j c curr<<e;
        out = max(curr, out);
        //w<< (curr-inp[i]*pre[j]/pre[i])/(1-inp[i])<<e;
        while (i < j && (curr-inp[i]*pre[j]/pre[i])/(1-inp[i]) > curr ) {
            /// remove i
            curr = (curr-inp[i]*pre[j]/pre[i])/(1-inp[i]);
            //w<< "remove" s i s j c curr<<e;
            out = max(curr, out);
            i++;
        }
        j++;
    }
    w<< (int)((out+.000000001)*1000000)<<e;
}

