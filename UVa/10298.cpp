/*
Author :: Moniba
Problem id ::   UVA 10298
Problem name :: Power Strings
*/

#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ll long long
#define N 1000005
#define p 307

int power[ N ], h[ N ];
int n;
string s;

int rep( int len ){
    int counter = 1;
    for( int i = len; i < n  ; i += len){
        if( h[ len - 1 ] == (h[ i + len - 1] - h[ i - 1 ])* power[ i ] )
            counter ++;
        else return 0;
    }
    return counter;
}

int main(){

    power[ 0 ] = 1;
    for( int i = 1 ; i < N ; i ++ )
        power[ i ] =  p * power[ i - 1];

    while( cin >> s, s!="." ){
        n = s.size();
        for( int i = 0 ; i < n ; i ++ ){
            h[ i  ] = s[ i ] * power[ n - 1 - i ];
            if( i != 0 )
                h[ i ] += h[ i - 1];
        }

        int res = 0, counter;
        for( int i = 1 ; i <= sqrt( n ) ; i ++ ){
            if(  n % i != 0 ) continue;
            counter = max( rep( i ), rep ( n / i ) );
            res = max( res, counter );
        }

        cout << res << "\n";

    }
    return 0;
}
