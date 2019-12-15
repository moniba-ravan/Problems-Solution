  
/*
Author :: Moniba
Problem id ::   GCPC 2017 I
Problem name ::  Uberwatch
*/
#include <bits/stdc++.h>
 
using namespace std;
#define double long double
#define pdi pair<double , int>
#define fi first
#define se second
#define pb push_back
#define N 200005
#define mod 1000000007
#define ll long long
#define INF 2e18
 
int n,m;
int x[ 300000 + 5 ], dp[ 300000 + 5 ];
int f( int slice ){
    if( slice > n ){
        return 0;
    }
 
    if( dp[ slice ] != -1 )
        return dp[ slice ];
    int ans = f( slice + m ) + x[ slice ];
    ans = max( f( slice + 1), ans );
    dp[ slice ] = ans;
    return ans;
}
 
int main( ){
    memset( dp, -1, sizeof dp );
    cin >> n >> m;
    for( int i = 1; i <= n ; i++){
        cin >> x[ i ];
    }
    int res = f( 1 + m);
    cout << res << endl;
    return 0;
}
