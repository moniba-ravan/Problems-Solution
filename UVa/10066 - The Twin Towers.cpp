/*
Author :: Moniba
Problem id ::  UVA 10066
Problem name :: The Twin Towers
*/

#include<bits/stdc++.h>

using namespace std;

const int N = 105;

int dp[ N ][ N ];
int a[ N ], b[ N ];
int n, m, cas = 1;

int main(){

    while( cin >> n >> m, !(n == 0 && m == 0) ){
        for( int i = 1 ; i <= n ; i ++ )
            cin >> a[ i ];
        for( int i = 1 ; i <= m ; i ++ )
            cin >> b[ i ];

        for( int i = 1; i <= n ; i ++ ){
            for( int j = 1; j <= m ; j ++ ){
                if( a[ i ] == b[ j ] )
                    dp[ i ][ j ] = dp[ i - 1][ j - 1] + 1;
                else
                    dp[ i ][ j ] = max( dp[ i - 1][ j ] , dp[ i ][ j - 1] );
            }
        }
        printf("Twin Towers #%d\nNumber of Tiles : %d\n\n", cas ++, dp[ n ][ m ] );

    }
    return 0;
}
