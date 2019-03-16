#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string S , T ;
    cin >> S ;
    cin >> T ;
    reverse( T.begin() , T.end() ) ;
    if ( S == T ) cout << "YES" << endl ;
    else cout << "NO" << endl ;
    return 0 ;
}