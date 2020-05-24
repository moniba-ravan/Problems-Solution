/*
Author :: Moniba
Problem id ::  UVA 10100
Problem name :: Longest Match
*/

#include<bits/stdc++.h>

using namespace std;

#define pb push_back

const int N = 1005;

int dp[ N ][ N ];
string s1, s2;
vector< string > a, b;
int n, m, cas = 1;
bool not_letter( char ch ){
    if( ch >= 'a' && ch <= 'z')
        return false;
    if( ch >= 'A' && ch <= 'Z')
        return false;
    if( ch >= '0' && ch <= '9')
        return false;
    return true;
}
int main(){
    while(  true ){
        if( cin.peek() == EOF )
            break;
        a.clear();a.pb("+");
        b.clear();b.pb("-");

        getline(cin, s1);getline(cin, s2);
        n = s1.size();m = s2.size();


        for( int i = 0 ; i < n ; i ++ )
            if( not_letter( s1[ i ] ) )
                 s1[ i ] = ' ';

        for( int i = 0; i < m ; i ++ )
            if( not_letter( s2[ i ] ))
                s2[ i ] = ' ';

        stringstream ss1( s1 );
        while( ss1 >>  s1)
            a.pb( s1 );
        stringstream ss2( s2 );
        while( ss2 >> s2 )
            b.pb( s2 );
        n = a.size();m = b.size();

        for( int i = 1; i < n ; i ++ ){
            for( int j = 1; j < m ; j ++ ){
                if( a[ i ] == b[ j ] )
                    dp[ i ][ j ] = dp[ i - 1][ j - 1] + 1;
                else
                    dp[ i ][ j ] = max( dp[ i - 1][ j ] , dp[ i ][ j - 1] );
            }
        }
        if( a.size() == 1 || b.size() == 1)
            printf("%2d. Blank!\n", cas++);
        else
            printf("%2d. Length of longest match: %d\n", cas ++, dp[ n - 1 ][ m - 1 ] );

    }
    return 0;
}
