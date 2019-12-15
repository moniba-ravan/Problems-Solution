  
/*
Author :: Moniba
Problem id ::   GCPC 2017 G
Problem name ::  Water Testing
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define double long double
#define pii pair<int , int >
#define pll pair< ll, ll >
#define pb push_back
#define N 100005

//using Pick's Theorem Area = ( b / 2 ) + answer - 1

pll points[ N ];
int n;
ll area = 0, b = 0;
int main(){
    cin >> n;
    b = n;
    for( int i = 0; i < n ; i++ ){
        cin >> points[ i ].first >> points[ i ].second;
        if( i != 0 ){
            area += (points[ i ].second * points[ i - 1 ].first) - ( points[ i - 1 ].second * points[ i ].first );
            if( points[ i ] .first == points[ i - 1 ].first ){
                b += abs( points[ i ].second - points[ i - 1 ].second ) - 1;
            }else if( points[ i ] .second == points[ i - 1 ].second ){
                b += abs( points[ i ].first - points[ i - 1].first ) - 1;
            }else{

                b += __gcd( abs( points[ i ].first - points[ i - 1 ].first )
                         ,abs( points[ i ].second - points[ i - 1 ].second )  ) - 1;
            }
        }
    }
    area += (points[ 0 ].second * points[ n - 1 ].first) - ( points[ n - 1 ].second * points[ 0 ].first );
    if( points[ 0 ] .first == points[ n - 1 ].first ){
                b += abs( points[ 0 ].second - points[ n - 1 ].second ) - 1;
    }else if( points[ 0 ] .second == points[ n - 1 ].second ){
                b += abs( points[ 0 ].first - points[ n - 1].first ) - 1;
    }else{

        b += __gcd( abs( points[ 0 ].first - points[ n - 1].first )
                         ,abs( points[ 0 ].second - points[ n - 1 ].second )  ) - 1;
    }

    ll temp = abs( area ) - b;
    ll ans = (temp / 2) + 1;
    cout << ans << endl;

	return 0;
}
