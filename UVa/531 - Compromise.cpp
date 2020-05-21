/*
Author :: Moniba
Problem id ::   UVA 531
Problem name :: Compromise
*/

/*
I got Wrong Answer with
while( true ){
  if( cin.peek() == EOf)
    break;
    ...
}
*/

#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define pii pair< int, int >
#define sz(v) ((int)v.size())

vector < string > a, b;
string x;
int dp[ N ][ N ];
pii parent[ N ][ N ];

int main(){
    
    while( cin >> x ){

        a.clear();a.pb("+");
        b.clear();b.pb("-");
        a.pb(x);
        while( cin >> x, x !="#"){
            a.pb( x );
        }
        while( cin >> x, x !="#"){
            b.pb( x );
        }
        for( int i = 1 ; i < sz( a ); i ++ ){
            for( int j = 1; j < sz( b ); j ++ ){
                if( a[ i ] == b[ j ] ){
                    dp[ i ][ j ] = dp[ i - 1][ j - 1] + 1;
                    parent[ i ][ j ] = pii(i - 1, j - 1);
                }else{
                    dp[ i ][ j ] = max( dp[ i - 1][ j ],
                                       dp[ i ][ j - 1] );
                    if( dp[ i ][ j ] == dp[ i - 1][ j ] )
                        parent[ i ][ j ] = pii( i - 1, j );
                    if( dp[ i ][ j ] == dp[ i ][ j - 1] )
                        parent[ i ][ j ] = pii( i, j - 1);
                }
            }
        }

        vector< string  > ans;
        int i = sz(a) - 1, j = sz(b) - 1;
        while( i != 0 && j != 0 ){
            if( i - 1 == parent[ i ][ j ].first && j - 1 == parent[ i ][ j ].second ){
                ans.pb( a[ i ] );
                i--;
                j--;
            }else{
                pii p = parent[ i ][ j ];
                i = p.first;
                j = p.second;
            }
        }
        reverse( ans.begin(), ans.end() );
        for( i = 0 ; i < sz(ans); i ++ ){
            if( i != 0 )
                cout<<" ";
            cout << ans[ i ];
        }
        cout <<"\n";
    }

    return 0;
}
