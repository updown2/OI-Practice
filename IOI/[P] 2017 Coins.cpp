/*
https://ivaniscoding.wordpress.com/2018/08/25/communication-1-coins/
*/
#include "coins.h"

using namespace std;
vector<int> coin_flips(vector<int> b, int c) {
    vector<int> flips(1);
    int curr = 0;
    for (int i=0; i<64; i++) if (b[i] == 1) curr ^= i;
    flips[0] = curr^c;
    return flips;
}

int find_coin(vector<int> b) {
    int out = 0;
    for (int i=0; i<64; i++) if (b[i] == 1) out ^= i;
    return out;
}

	int tests;
	cin >> tests;
	for (int t = 1; t <= tests; t++) {
		string result = run_test();
		printf("test #%d: %s\n", t, result.c_str());
	}
	return 0;
}
