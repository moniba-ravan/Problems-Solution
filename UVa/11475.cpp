
/*
Author :: Moniba
Problem id ::   UVA 11475
Problem name :: Extend to Palindrome
*/

#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ll long long
#define N 100005
#define p 307LL
#define mod 1000000007LL

string s,ss;
int n;
ll power[ N ];
ll pre[ N ], post[ N ];
int main(){

    power[ 0 ] = 1;
    for( int i = 1; i < N ; i ++ ){
        power[ i ] = p*power[ i - 1] ;
        power[ i ] %= mod;
    }

    while( cin >> s){
        n = s.size();


        // pre[ i ] = a0*p^(n - 1 -0 ) + a1*p^(n - 1 - 1) + .. + ai*p^(n - 1 - i)
        for( int i = 0 ; i < n ; i ++ ){
            pre[ i ] =  s[ i ] * power[ n - 1 - i ];
            if( i != 0)
                pre[ i ] += pre[ i - 1 ];
            pre[ i ] %= mod;
        }

        //post[ i ] = an-1*p^(n - 1) + an-2*p^(n - 2) + .. + ai*p^(i)
        for( int i = n - 1 ; i >= 0 ; i -- ){
            post[ i ] =  s[ i ] * power[ i ];
            if( i != n - 1)
                post[ i ] += post[ i + 1 ];
            post[ i ] %= mod;
        }



        int idx =  n - 2 ;
        for( int i = ( n + 1)/2; i < n ; i++ ){
            ll temp = 0;


            if(2*i - n - 1 >= 0 ) temp = pre[ 2*i - n - 1];
            if( post[ i ] == (( mod + pre[ i - 1] - temp)* power[ 2*i - n])% mod ){
                idx = min( idx, 2*i - n - 1);
            }



            temp = 0;
            if(2*i - n - 2 >= 0 ) temp = pre[ 2*i - n - 2];
            if(post[ i ] == (( mod + pre[ i - 2] - temp)* power[ 2*i - n - 1])% mod ){
                idx = min(idx, 2*i - n - 2);

            }


        }

        //ans is s + ss
        ss = s.substr(0, idx + 1);
        reverse(ss.begin(), ss.end() );
        cout << s << ss << endl;

    }
    return 0;
}
