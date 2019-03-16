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
ii a ,b , c;
bool check = true;

vii moves = {{1 , 1} , {1 , 0} , {0 , 1} , {-1 , -1} , {0 , -1 }, {-1 , 0} , {-1 , 1} , {1 , -1}};
vvi flags;

bool back(ii x){
    flags[x.first][x.second] = 1;
    if(x == c)
        return 1;
    if(x.first == a.first || x.second == a.second)
        return 0;
    bool ans = false;
    for (int i = 0; i < 8 && check; ++i) {
        if(moves[i].first + x.first > 0 && moves[i].first + x.first <= n && moves[i].second + x.second > 0 && moves[i].second + x.second <= n
           && !flags[moves[i].first + x.first][moves[i].second + x.second])
            ans |= back(ii(moves[i].first + x.first , moves[i].second + x.second));
        if(ans)
            check = false;
    }
    return ans;
}

int main(){
    cin >> n >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second;
    flags.assign(n + 1 ,vi(n+1 , 0));
    if(back(b))
        cout << "YES";
    else
        cout << "NO";

}
