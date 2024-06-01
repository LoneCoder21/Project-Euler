#define _CRT_SECURE_NO_WARNINGS
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <array>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <bitset>
#include <cassert>
#include <fstream>
#include <limits>
#include <numeric>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
const double eps = 1e-12;
#define all(a) a.begin(),a.end()

const bool USEFILE = 1;
const bool ONECASE = 1;
const bool OUTPUTFILE = 0;

template<typename T>
void printvector(vector<vector<T>>& v) {
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[i].size(); ++j) {
            cout << v[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

template<typename T>
void printvector(vector<T>& v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << ' ';
    }
}

ll get(int mat[20][20], int i, int j) {
    if (i >= 20 || j >= 20||i < 0 || j < 0)return 0;
    return mat[i][j];
}

void solve() {
    int mat[20][20] = {};
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            cin >> mat[i][j];
        }
    }
    ll mx = 0;
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            mx = max(mx, get(mat, i, j) * get(mat, i+1, j) * get(mat, i+2, j) * get(mat, i+3, j));
            mx = max(mx, get(mat, i, j) * get(mat, i, j+1) * get(mat, i, j+2) * get(mat, i , j+3));

            mx = max(mx, get(mat, i, j) * get(mat, i+1, j + 1) * get(mat, i+2, j + 2) * get(mat, i+3, j + 3));
            mx = max(mx, get(mat, i, j) *get(mat, i + 1, j - 1) * get(mat, i + 2, j - 2) * get(mat, i + 3, j - 3));
        }
    }
    cout << mx << endl;
}

int main() {
    ll t = 1;
    ofstream file;
    file.open("output.txt", std::ofstream::app);

    if (USEFILE) freopen("samples.txt", "r", stdin);
    if (!ONECASE) cin >> t;

    if (OUTPUTFILE) freopen("pails.out", "w", stdout);

    for (int i = 1; i <= t; ++i) {
        solve();
    }

    return 0;
}