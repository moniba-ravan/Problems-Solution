#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>


using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair< ll, ll > pll;
typedef pair< int, char > pic;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define pb push_back
#define fastc ios_base::sync_with_stdio(false);cin.tie(0)
#define sz( x ) (ll)(x).size()
#define all( x ) x.begin(),x.end()

const ll mod = 1000000007;
const char nl = '\n';
const int N = 5e5 + 5;
const ll q = 31; ////// change

int n, c, b;
int s[ N ];
int z[ N ];
int main(){
    cin >> n >> c >> b;

    for( int i = 0 ; i < n ; i ++ )
        s[ i ] = -1;


    for( int i = 1; i <= b ; i ++ ){
        cin >> z[ i ];
        z[ i ]--;
        s[ z[ i ] ] = 0;
    }
    if( c % 2 == 1){
        s[ 0 ] = 1;
        s[ 1 ] = 0;
        z[ 0 ] = 1;
        c--;
    }else{
        z[ 0 ] = 0;
        s[ 0 ] = 0;
    }

    b++;
    for( int i = b - 1; i-1 >= 0 ; i -- ){
        int r = z[ i ] - 1;
        int l = z[ i - 1];
        while( l < r ){
            if( c >= 2){
                c-=2;
                s[ r ] = 1;
                r--;
                if( l < r){
                    s[ r ] = 0;
                    r--;
                }
            }else{
                s[ r ]=s[ r + 1];
                r--;
            }
        }
    }


    for( int i = 0 ; i < n ; i ++ )
        cout << s[ i ];
    cout << nl;


    return 0;
}
