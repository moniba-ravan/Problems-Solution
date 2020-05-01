
/*
Author :: Moniba
Problem id ::   UVA 10192
Problem name :: Vacation
*/

#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define fastc ios_base::sync_with_stdio(0)

const int N = 105;

string a, b;
int dp[ N ][ N ];
int cas = 1;

int f( int id_a, int id_b ){
    if( id_a == (int)a.size() || id_b == (int)b.size() )
        return 0;

    if( dp[ id_a ][ id_b ] != -1 )
        return dp[ id_a ][ id_b ];

    int res = f( id_a + 1, id_b );

    for( int i = id_b ; i < (int)b.size() ; i ++ ){
        if( a[ id_a ] != b[ i ] )
            continue;
        res = max( res, f( id_a + 1, i + 1) + 1);
        break;
    }
    dp[ id_a ][ id_b ] = res ;
    return res;
}

int main(){
    fastc;
    while( getline(cin, a) , a != "#" ){
        getline(cin, b);

        for( int i = 0 ; i < (int) a.size() ; i ++ )
        for( int j = 0 ; j < (int) b.size() ; j ++ )
            dp[ i ][ j ] = -1;

        cout <<"Case #"<< cas++ <<": you can visit at most "<< f( 0, 0 ) <<" cities.\n";
    }
    return 0;
}
