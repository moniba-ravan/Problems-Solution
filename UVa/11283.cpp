
/*
Author :: Moniba
Problem id ::   UVA 11283
Problem name :: Playing Boggle
*/

#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ll long long
#define pii pair< int, int >
#define fastc ios_base::sync_with_stdio(0)

char mat[ 4 ][ 4 ];
bool vis[ 4 ][ 4 ];

string words[ 105 ];
bool found[ 105 ];

int t, q, cas = 1;
//8 direction
int ix[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, iy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int point[9] = {0, 0, 0, 1, 1, 2, 3, 5, 11};

bool can( int i, int j){
    if( i >= 0 && j >= 0 && i <4 && j < 4 )
        return true;
    return false;
}

bool dfs( int x, int y, int w, int idx){

    if(vis[ x ][ y ] | mat[ x ][ y ] != words[ w ][ idx ] )
        return false;

    if( idx + 1 == (int)words[ w ].size())
        return true;

    vis[ x ][ y ]= true;
    bool res = false;
    for( int i = 0 ; i < 8 && !res; i ++ ){
        if( !can(x + ix[ i ] , y + iy[ i ]))
            continue;
        res |= dfs( x + ix[ i ], y + iy[ i ], w, idx + 1);
    }
    vis[ x ][ y ] = false;
    return res;
}


int main(){
    fastc;
    cin >> t;
    while( t-- ){
        for( int i = 0 ; i < 4 ; i ++ )
            for( int j = 0 ; j < 4; j ++ )
                cin >> mat[ i ][ j ];
        cin >> q;
        for( int i = 0 ; i < q; i ++ ){
            cin >> words[ i ];
            found[ i ] = false;
        }

        int res = 0;
        for( int i = 0 ; i < 4 ; i ++ ){
            for( int j = 0 ; j < 4 ; j ++ ){
                for( int w = 0 ; w < q; w++ ){
                    if( !found[ w ] && dfs( i, j, w, 0)){
                        found[ w ] = true;
                        res += point[min(8, (int)words[ w ].size())];
                    }
                }
            }
        }
        cout <<"Score for Boggle game #"<<cas++<<": "<< res << "\n";

    }
    return 0;
}
