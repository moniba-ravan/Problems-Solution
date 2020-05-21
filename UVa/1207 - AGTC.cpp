/*
Author :: Moniba
Problem id ::  UVA 1207
Problem name :: AGTC
*/

#include<bits/stdc++.h>

using namespace std;


string a, b;
int n, m;

int main(){
    while( cin >> n ){
        cin >> a >> m >> b;
        a = '+' + a;n++;
        b = '-' + b;m++;

        int dp[ n ][ m ];
        for( int i = 0 ; i < n ; i ++ )
            dp[ i ][ 0 ] = i;
        for( int j = 0 ; j < m ; j ++ )
            dp[ 0 ][ j ] = j;

        for( int i = 1 ; i < n ; i ++ ){
            for( int j = 1 ; j < m ; j ++ ){
                if( a[ i ] == b[ j ] ){
                    dp[ i ][ j ] = dp[ i - 1][ j - 1];
                }else dp[ i ][ j ] = min( dp[ i - 1][ j ],
                                         min(dp[ i ][ j - 1],
                                             dp[ i - 1][ j - 1])
                                         ) + 1;

            }
        }
        cout << dp[ n - 1][ m - 1] << endl;
    }

    return 0;
}
