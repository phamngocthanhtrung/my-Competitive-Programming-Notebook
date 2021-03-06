
// http://codeforces.com/contest/778/problem/A

/*------------------------------------- CONFIG ---------------------------------------------------------------*/
#define DEBUG
//#define LINUX

/*------------------------------------- TEMPLATE ---------------------------------------------------------------*/
#ifdef LINUX
#include <bits/stdc++.h>
#endif

#ifndef LINUX
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <bitset>
#include <iostream>
#include <fstream>
#include <streambuf>
#include <istream>
#include <vector>
#include <list>
#include <forward_list>
#include <string>
#include <map>
#include <algorithm>
#include <functional>
#include <numeric>
#include <stack>
#include <queue>
#include <set>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <ctime>
#include <random>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <utility>
#include <climits>
#include <cassert>
#include <istream>
#include <random>
#include <iterator>
#include <memory>
#include <cctype>
#endif
using namespace std;

#define int long long
#define double long double
#define ll long long
#define ull unsigned long long

#define for_i(start,end,step) for(int i = start; i < (int)end; i += step) // [start, end)
#define for_id(start,end,step) for(int i = start; i > (int)end; i += step) // [start, end)
#define for_j(start,end,step) for(int j = start; j < (int)end; j += step) // [start, end)
#define for_jd(start,end,step) for(int j = start; j > (int)end; j += step) // [start, end)
#define for_(start,end,step) for(int _ = start; _ < (int)end; _ += step) // [start, end)

#define pr(X) { cerr << #X << " = " << (X) << endl; }
#define pra(A, start, end) { cerr << #A << '[' << start << ',' << (end - 1) << "] = "; for_(start, end, 1) cerr << A[_] << ' '; cerr << endl; }

const int inf = 1e9 + 7;
#define sqr(x) ((x) * (x))
#define PI (2 * acos((double)0))
double safe_sqrt(double x) { return sqrt(max((double)0.0, x)); }

typedef pair<int, int> pii;
typedef vector<int> vi;
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define ms(a,x) memset(a, x, sizeof(a)) //Care: Only init with 0,-1 and char[]
/*----------------------------------- PARAMETERS -----------------------------------------------------------------*/
string t;
string p;
ll idx[200001];

bool del[200001];
/*------------------------------------- FUNCTIONS ---------------------------------------------------------------*/
bool checkSubstr(ll m) {
	for_i(0, m, 1)
		del[idx[i]] = true;
	for_i(m, sz(t), 1)
		del[idx[i]] = false;

	ll i = 0;
	for_j(0, sz(p), 1) {
		while (i < sz(t) && (del[i] || t[i] != p[j]))
			++i;
		if (i >= sz(t))
			return false;
		++i;
	}
	return true;
}

ll binSearch(ll l, ll r) {
	ll pos = 0;
	--r;
	while (true) {
		if (l > r)
			return pos;

		ll m = l + (r - l) / 2;
		if (checkSubstr(m)) {
			pos = m;
			l = m + 1;
		}
		else
			r = m - 1;
	}
}

ll solve() {
	return binSearch(0, sz(t));
}
/*------------------------------------- MAIN ---------------------------------------------------------------*/
int32_t main(int agrc, char *argv[]) {
#ifdef DEBUG
	freopen("..\\Debug\\Input.txt", "r", stdin);
	freopen("..\\Debug\\Output.txt", "w", stdout);
	freopen("..\\Debug\\Cerr.txt", "w", stderr);
#endif
	ios::sync_with_stdio(false);
	cin.tie(false);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);
	/*----------------------------------------------------------------------------------------------------*/
	//InOut
	cin >> t >> p;
	for_i(0, sz(t), 1)
		cin >> idx[i], --idx[i];

	//Clear parameter


	//solve
	cout << solve() << endl;
	return 0;
}
