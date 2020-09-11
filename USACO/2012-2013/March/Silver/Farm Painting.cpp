#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50000;

int N, rectangles[MAXN][4];
pair<int, int> values[2*MAXN];

set<pair<int, int> > stored; // (top y value, index)
set<pair<int, int> >::iterator it;

int answer;

int main() {
    ifstream cin("painting.in");
	ofstream cout("painting.out");
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> rectangles[i][0] >> rectangles[i][1] >> rectangles[i][2] >> rectangles[i][3];
		values[2*i] = make_pair(rectangles[i][0], i);
		values[2*i+1] = make_pair(rectangles[i][2], i);
	}
	sort(values, values+ (2*N));	
	
	for (int i=0; i<2*N; i++) {
		int index = values[i].second;
		
		if (rectangles[index][0] == values[i].first) {
			// this is an open range
			
			// check if the current range is covered by an already open range
			it = stored.upper_bound(make_pair(rectangles[index][1], 0));
			if (it == stored.end()) {
				answer++; // update the answer
				stored.insert(make_pair(rectangles[index][3], index)); // update stored information (set called stored)
				continue;
			}
			
			pair<int, int> above = (*it);
			int index2 = above.second;
			if (rectangles[index2][1] > rectangles[index][3]) {
				// the previous ranges don't cover the current range
				answer++; // update the answer
				stored.insert(make_pair(rectangles[index][3], index)); // update stored information (set called stored)
			}
		}
		else {
			// it is a close range
			// don't need to update the answer
			// update stored inormation
			it = stored.find(make_pair(rectangles[index][3], index));
			if (it != stored.end() ) {
				stored.erase(it);
			}
			
		}
		
	}
	cout << answer << endl;
}

