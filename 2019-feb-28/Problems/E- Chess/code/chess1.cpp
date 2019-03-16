//                                                  In The Name Of God
//                                              programmer:Mohammad Dehghan
#include <iostream>
using namespace std;

#include <random>
#include <vector>
#include <bitset>
#include <set>
#include <string>
#include <string.h>
#include <math.h>
#include <map>
#include <algorithm>
#include <iomanip>
#include <queue>
//#include<omp.h>
#include <sstream>
#include <stdlib.h>
#include <time.h>

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<ll , ll> ill;
typedef pair<int, ii> iii;
typedef pair<ii , ii> iiii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef vector<vvii> vvvii;
typedef vector<vector<viii>> vvviii;
typedef vector<vector<iii>> vviii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;
typedef vector<dd> vdd;
typedef pair<dd, double> ddd;
typedef vector<ddd> vddd;


int n;

int get(int x, int y, int a, int b) {
    if (a > x && b > y)
        return 0;
    else if (a > x && b < y)
        return 1;
    else if (a < x && b > y)
        return 2;
    else if (a < x && b < y)
        return 3;
}

int ax, ay, bx, by, cx, cy;

int main() {
    cin >> n;
    cin >> ax >> ay;
    cin >> bx >> by;
    cin >> cx >> cy;
    int x = get(ax, ay, bx, by);
    int y = get(ax, ay, cx, cy);
    if (x == y)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
