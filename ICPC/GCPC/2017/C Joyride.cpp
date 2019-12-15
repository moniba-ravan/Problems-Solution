  
/*
Author :: Moniba
Problem id ::   GCPC 2017 C
Problem name ::  Joyride

*/

#include <bits/stdc++.h>
 
using namespace std;
#define double long double
#define pdi pair<double , int>
#define fi first
#define se second
#define pb push_back
#define N 1005
#define MAX 1000000007LL
#define ll long long
#define INF 2e18
 
int n, m, t, x;
int timee[ N ];
ll cost[ N ];
ll dp[ N ][ N ];
vector< int > adj[ N ];
ll f( int idx, int minutes ){
    if( minutes > x )
        return MAX;
 
    if( minutes == x && idx == 1 ){
        return 0;
    }
 
    if( dp[ idx ][ minutes ] != -1 )
        return dp[ idx ][ minutes ];
 
    ll temp, ans = MAX;
 
    temp = f( idx, minutes + timee[ idx ] );
    if( temp != MAX ){
        ans = min( ans, temp + cost[ idx ] );
    }
 
    for( int i = 0 ; i < ( int )adj[ idx ].size() ; i ++ ){
        int other= adj[ idx ][ i ];
        temp = f( other, minutes + timee[ other ] + t );
        if( temp == MAX ) continue;
 
        ans = min( ans, temp + cost[ other ]  );
    }
    dp[ idx ][ minutes ] = ans;
    return ans;
 
}
 
int main( ){
    memset( dp, -1, sizeof dp );
    cin >> x;
    cin >> n >> m >> t;
    int x,y;
    for( int i = 0; i < m ; i++){
        cin >> x >>y;
        adj[ x ].pb( y );
        adj[ y ].pb( x );
    }
 
    for( int i = 1; i <= n ;i++){
        cin >> timee[ i ] >> cost[ i ];
    }
 
 
    ll ans = f( 1, timee[ 1 ]);
    if( ans == MAX ){
        cout << "It is a trap."<<endl;
    }else{
        ans += cost[ 1 ];
        cout << ans << endl;
    }
    return 0;
}
