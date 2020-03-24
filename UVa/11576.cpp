/*
Author :: Moniba
Problem id ::   UVA 11576
Problem name :: Scrolling Sign
*/

#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ll long long
#define N 105
#define p 307LL
#define mod 998244353LL

ll pre[ N ][ N ], power[ N ];

void make_power( int n ){
    power[ 0 ] = 1;
    for( int i = 1; i < n ; i ++ ){
        power[ i ] = p * power[ i - 1];
        power[ i ] %= mod;
    }
}

void make_hash( string s, int idx){
    int n = s.size() ;
    for( int i = 0 ; i < n ; i ++){
        pre[ idx ][ i ] = (s[ i ]-'A') * power[ n - 1 - i ];
        if( i != 0 ) pre[ idx ][ i ] += pre[ idx ][ i - 1];
        pre[ idx ][ i ] %= mod;
    }
}


int main(){
    make_power( N );

    int t, k, w;
    cin >> t;
    while( t-- ){


        cin >> k >> w;
        for( int i = 0 ; i < w ; i++ ){
            string s;
            cin >> s;
            make_hash(s, i );
        }


        int ans = k;
        for( int i = 1 ; i < w ; i ++ ){
            int j = 0;
            for( j = 0 ; j < k ;j ++ ){
                ll temp = 0;
                if( j - 1 >= 0 ) temp = pre[ i - 1][ j - 1];
                if( ((mod + pre[i - 1][ k - 1 ] - temp )*power[ j ] ) % mod == pre[ i ][ k - 1 - j] )
                    break;
            }
            ans +=j;
        }
        cout << ans << endl;


    }
    return 0;
}
