/*
Author :: Moniba
Problem id ::   UVA 11888
Problem name :: Abnormal 89's
Time complexity :: O(n)
*/

#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ll long long
#define N 200005
#define p 203
int t, n;
string s;
ll pre[ N ], post[ N ], power[ N ];
bool pal,ali;
int main(){
    cin >> t;
    while( t -- ){
        cin >> s;
        n = s.size();

        power[ 0 ] = 1;
        for( int i = 1; i < n ; i ++ ){
            power[ i ] = power[ i - 1] * p;
        }

        // pre[ i ] = a0 + a1*p + .. + ai*p^(i-1)
        for( int i = 0 ; i < n ; i ++){
            if( i == 0){
                pre[ i ] = s[ i ];
            }else{
                pre[ i ] = pre[ i - 1] + s[ i ]*power[ i ];
            }
        }

        //post[ i ] = an-1 + an-2*p + .. ai*p^(n - 1 - i)
        for( int i = n - 1 ; i >= 0 ; i -- ){
            if( i == n - 1){
                post[ i ] = s[ i ];
            }else{
                post[ i ] = post[ i + 1 ] + s[ i ] * power[ n - 1 - i];
            }
        }

        //check if alindrome
        ali = pal = false;
        for( int i = 0 ; i < n - 1; i ++ ){
               if( pre[ i ] * power[ n - 1 - i ] == post[ 0 ] - post[ i + 1] &&
                   pre[ n - 1 ] - pre[ i ] == post[  i + 1 ] * power[ i + 1 ] )
                    ali = true;
        }
        //check if palindrome
        if( pre[ n - 1 ] == post[ 0 ] ) pal = true;


        if( ali ){
            cout<<"alindrome\n";
        }else if( pal ) cout <<"palindrome\n";
        else cout <<"simple\n";

    }
    return 0;
}
