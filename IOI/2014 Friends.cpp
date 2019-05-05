/*
http://blog.brucemerry.org.za/2014/07/
*/
#include "friend.h"
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
//500,000,000 operations
const int MAXN = 300001, INF = 1000000000;
//Global Variables

int findSample(int n, int confidence[], int host[], int protocol[]){
	int ans = 0;
	for (int i=n-1; i>=1; i--) {
        int a = host[i];
        if (protocol[i] == 0) {
            /// take it
            ans += confidence[i];
            /// add reverse option
            confidence[a] = max(0, confidence[a] - confidence[i]);
        }
        if (protocol[i] == 1) {
            confidence[a] += confidence[i];
        }
        if (protocol[i] == 2) {
            confidence[a] = max(confidence[a], confidence[i]);
        }
	}
	return ans+confidence[0];
}
