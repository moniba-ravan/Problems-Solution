
/*
Author :: Moniba
Problem id ::   UVA 10010
Problem name :: Where's Waldorf?
*/

#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ll long long
#define pii pair< ll, int >

const int N = 55;

int t, n, m, q;
string mat[ N ],pat[ N ];
int lps[ N ][ N ];
bool vis[ 2 ][ N ][ N ];
pii ans[ N ]; // The answers arr in this array


// turns Upper case to lower case
string low_case( string s ){
    for( int i = 0 ; i < (int)s.size() ; i++ ){
        if( s[ i ] >= 'A' && s[ i ] <= 'Z'){
            s[ i ] -='A';
            s[ i ] +='a';
        }
    }
    return s;
}


// finds the better answer between the old one( a ) and the new one( b )
//better answer means the one which problem wants (Upmost then left most)
bool better( pii a, pii b){
    if( b.first == -1 || b.second == -1 || b.first == n || b.second == m)
        return false;
    if( a.first == b.first )
        return a.second > b.second;
    return a.first > b.first;
}

// finds lps array of all of the patterns
void LPS( ){
    for( int k = 0 ; k < q; k ++ ){
        int sz = pat[ k ].size();
        int i = 1, j = 0;
        lps[ k ][ 0 ] = 0;
        while( i < sz ){
            if( pat[ k ][ i ] == pat[ k ][ j ] ){
                lps[ k ][ i ] = j + 1;
                i++;
                j++;
            }else if( j == 0 ){
                lps[ k ][ i ] = 0;
                i++;
            }else j = lps[ k ][ j - 1];
        }
    }
}
//If two substring with start position a and b matched with the pattern
//which function will choose the better answer base on the direction
//better answer means the one which problem wants (Upmost then left most)
int which( int a, int b, int d){
    if( a == -1)
        return b;
    switch( d ){
    case 0://toRight
        if( b < a)
            return b;
        break;
    case 1://toLeft
        if( b > a )
            return b;
        break;
    case 2://toDown
        if( b < a )
            return b;
        break;
    case 3://toUp
        if( b > a)
            return b;
        break;
    case 4://toDownRight
        if( b < a )
            return b;
        break;
    case 5://toUpLeft
        if( b > a)
            return b;
        break;
    case 6://toDownLeft
        if( b < a)
            return b;
        break;
    case 7://toUpRight
        if( b > a )
            return b;
        break;
    }
    return a;
}
// Kmp matches the k-th pattern with text(txt) that is in "dir" direction
// If it found none match it returns -1
int kmp( string txt, int k , int dir){
    string p = pat[ k ];
    int i = 0, j = 0, res = -1;
    while( i <= (int) txt.size()){
        if( j == (int) p.size() ){
            res = which( res , i - (int)p.size(), dir);
            j = lps[ k ][ j - 1];
        }else if( i == (int)txt.size())
            break;
         else if( txt[ i ] == p[ j]){
            i++;
            j++;
        }else if ( j == 0 )
            i++;
        else j = lps[ k ][ j - 1];
    }
    return res;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin >> t;
    while( t-- ){
        memset(vis, 0, sizeof vis);

        cin >> n >> m;
        for( int i = 0; i < n ; i ++ ){
            // The Matrix
            cin >> mat[ i ];
            mat[ i ] = low_case( mat[ i ] );

        }

        cin >> q;
        for( int i = 0; i < q; i ++ ){
            //Patterns
            cin >> pat[ i ];
            pat[ i ] = low_case( pat[ i ] );
            ans[ i ] = pii( N, N);

        }

        LPS();

        string txt, temp;
        int p;

        //vertically
        for( int i = 0 ; i < n ; i ++){
            temp = mat[ i ];

            for( int k = 0 ; k < q; k ++){
                txt = temp;
                p = kmp( txt , k, 0); //toRight
                if( better( ans[ k ], pii( i, p)))
                    ans[ k ] = pii( i, p);

                reverse(txt.begin(), txt.end() );
                p = kmp( txt , k, 1); //toLeft
                p = m - 1 - p;
                if( better( ans[ k ], pii( i, p)))
                    ans[ k ] = pii( i, p);
            }
        }

        //horizontally
        for( int j = 0 ; j < m ; j++ ){
            temp = "";
            for( int i = 0 ; i < n; i++ )
                temp += mat[ i ][ j ];

            for( int k = 0 ; k < q; k ++ ){
                txt = temp;
                p = kmp( txt , k, 2); //toDown
                if( better( ans[ k ], pii( p, j)))
                    ans[ k ] = pii( p, j);

                reverse(txt.begin(), txt.end() );
                p = kmp( txt, k, 3); //toUp
                if( better( ans[ k ], pii( n - 1 - p, j)))
                    ans[ k ] = pii( n - 1 - p, j);
            }
        }

        //toDiagonally"\"
        for( int i = 0 ; i < n ; i ++ ){
            for( int j = 0 ; j < m ; j ++ ){
                if( vis[ 0 ][ i ][ j ] )
                    continue;
                temp = "";
                int a = i, b = j;
                while( a < n && b < m){
                    temp += mat[ a ][ b ];
                    vis[ 0 ][ a ][ b ] = true;
                    a++;
                    b++;
                }
                for( int k = 0 ; k < q ; k ++ ){
                    txt = temp;
                    p = kmp( txt, k, 4); //toDownRight
                    if( better( ans[ k ], pii( i + p, j + p)))
                        ans[ k ] = pii( i + p, j + p);

                    reverse(txt.begin(), txt.end() );
                    p = kmp( txt, k, 5 ); //toUpLeft
                    p = (int)txt.size() - 1 - p;
                    if( better( ans[ k ], pii( i + p,  j + p)))
                        ans[ k ] = pii( i + p , j + p);
                }
            }
        }

        //toDiagonally"/"
        for( int i = 0 ; i < n ; i ++ ){
            for( int j = 0 ; j < m ; j ++ ){
                if( vis[ 1 ][ i ][ j ] )
                    continue;
                temp = "";
                int a = i, b = j;
                while( a < n && b >= 0){
                    temp += mat[ a ][ b ];
                    vis[ 1 ][ a ][ b ] = true;
                    a++;
                    b--;
                }
                for( int k = 0 ; k < q ; k ++ ){
                    txt = temp;
                    p = kmp( txt, k, 6);//toDownLeft
                    if( better( ans[ k ], pii( i + p, j - p)))
                        ans[ k ] = pii( i + p, j - p);

                    reverse(txt.begin(), txt.end() );
                    p = kmp( txt, k, 7);//toUpRight
                    p = (int)txt.size() - 1 - p;
                    if( better( ans[ k ], pii( i + p,  j - p)))
                        ans[ k ] = pii( i + p , j - p);
                }
            }
        }
        //It prints the answers
        for( int i = 0 ; i < q ; i ++ ){
            cout << ans[ i ].first + 1<< " " << ans[ i ].second + 1<< "\n";
        }
        if( t!=0) cout <<"\n";

    }

    return 0;
}
