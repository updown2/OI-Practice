/*
At most sqrt(2*10^5) different lengths of bad words.
Hashing. Save the hash value at each location for each length.
Add letters to the current string and delete if hit any words.
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(ll i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, M)
#define ffa ffi ffj
#define s <<" "<<
#define w cout
#define e "\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
//#define int ll
//500,000,000 operations
const int MAXN = 100000, MOD = 1000000009;
//Global Variables
ll N, T, M, mI, p = 41, ppp[MAXN];
int hsh[450][MAXN];
string a, out;
set<ll> len, ans;

ll power(ll x, ll y) {
    /// returns x^y
    if (y == 0) return 1;
    if (y == 1) return x;
    ll ret = power(x, y/2);
    ret *= ret;
    ret %= MOD;
    if (y%2 == 1) ret *= x, ret %= MOD;
    //w<< x s y s ":" s ret<<e;
    return ret;
}

main() {
	ifstream cin ("censor.in"); ofstream cout("censor.out");
	//ifstream cin ("test.in");
	ios_base::sync_with_stdio(0); cin.tie(0);
	mI = power(p, MOD-2);
	ppp[0] = 1; For (i, 1, MAXN) ppp[i] = (p*ppp[i-1])%MOD;
	cin >> a >> T; N = a.length();
	For (t, 0, T) {
	    string b; cin >> b; M = b.length();
	    len.insert(-M);
	    ll at = 0;
        ffj {
            at += (b[j]-'a'+1)*ppp[j];
            at %= MOD;
        }
        ans.insert(at);
	}
	//for (ll i: ans) w<< i<<" "; w<<e;
	ll i = 0;
	For (loc, 0, N) {
        ///11
        out += a[loc];
        ll j = -1;
        for (ll M: len) {
            j++;
            M *= -1;
            if (out.size() < M) {
                if (i == 0) hsh[j][i] = (out[i]-'a'+1);
                else hsh[j][i] = (hsh[j][i-1] + (out[i]-'a'+1)*ppp[i])%MOD;
                //w<< i s hsh[i] s ":" s out<<e;
                //w<< hsh[i-1]<<e;
            }
            else {
                if (out.size() == M) hsh[j][i] = (hsh[j][i-1] + ((out[i]-'a'+1)*ppp[M-1])%MOD)%MOD;
                else hsh[j][i] = ((((hsh[j][i-1]-(out[i-M]-'a'+1)+MOD)%MOD)*mI)%MOD + ((out[i]-'a'+1)*ppp[M-1])%MOD)%MOD;
                //w<< hsh[i] s (hsh[i-1]-(out[i-M]-'a'+1)+MOD)%MOD power(p, MOD-2)<<e;
                //w<< i s j s ":" s hsh[j][i] s "," s out<<e;
                if (ans.find(hsh[j][i]) != ans.end()) {
                    //w<< "FOUND AT" s i<<e;
                    For (k, 0, M) out.pop_back();
                    i -= M;
                    //w<< "new:" s out s i<<e;
                    break;
                }
            }
        }
        i++;
	}
	w<< out<<e;
}