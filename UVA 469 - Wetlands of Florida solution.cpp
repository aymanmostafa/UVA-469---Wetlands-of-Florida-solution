//============================================================================
// Name        : ayman.cpp
// Author      : Ayman Mostafa
// Email       : ayman93live@hotmail.com
// Version     : v5.0
//============================================================================

#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>
#include <bitset>

using namespace std;

#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()

void fastInOut();

int endr, endc, cnt;
char y[100][100];
bool yvis[100][100];
bool val(int r, int c) {
	if (r >= 0 && r <= endr && c >= 0 && c <= endc)
		return true;
	return false;
}
void maze(int r, int c) {
	if (!val(r, c) || y[r][c] == 'L' || yvis[r][c])
		return;
	yvis[r][c] = true;
	cnt++;
	maze(r + 1, c);
	maze(r, c + 1);
	maze(r - 1, c);
	maze(r, c - 1);
	maze(r + 1, c + 1);
	maze(r - 1, c - 1);
	maze(r - 1, c + 1);
	maze(r + 1, c - 1);
}
//##########################################################################################
//###################################MAIN FUNCTION##########################################
//##########################################################################################
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
//freopen("output.txt", "wt", stdout);
#endif
	fastInOut();
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
// 469 - Wetlands of Florida
	int n, m;
	string s, uva = "";
	getline(cin, s);
	stringstream(s) >> n;
	while (n--) {
		hell: while (getline(cin, s))
			if (s == "") {
				m = 0;
				if (!n)
					goto hell;
				if (uva == "shit")
					cout << endl;
				continue;
			} else {
				if (isalpha(s[0])) {
					for (int i = 0; i < s.size(); i++)
						y[m][i] = s[i];
					endc = s.size() - 1;
					m++;
				} else {
					uva = "shit";
					endr = m - 1;
					cnt = 0;
					int k[2], i = 0;
					stringstream ss(s);
					for (int ayman = 0; ayman < 100; ayman++)
						for (int mos = 0; mos < 100; mos++)
							yvis[ayman][mos] = false;
					while (ss >> k[i++])
						;
					maze(k[0] - 1, k[1] - 1);
					cout << cnt << endl;
				}
			}
	}
}
void fastInOut() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);
}
