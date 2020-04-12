
/*
Author :: Moniba
Problem id ::   UVA 422
Problem name :: Word-Search Wonder
*/


#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ll long long
#define pii pair< ll, int >

const int N = 105;

struct Answer{
    int ax,ay; // it's first letter
    int bx,by; // it's last letter
    Answer( int a=N, int b=N, int c=N, int d=N){
        ax = a;
        ay = b;
        bx = c;
        by = d;
    }
};


int t, n, m, q;
string mat[ N ],pat[ N ];
int lps[ N ][ N ];
bool vis[ 2 ][ N ][ N ];
Answer ans[ N ]; // The answers arr in this array


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


// Kmp matches the k-th pattern with text(txt) that is in "dir" direction
// If it found none match it returns -1
int kmp( string txt, int k , int dir){
    string p = pat[ k ];
    int i = 0, j = 0;
    while( i <= (int) txt.size()){

        if( j == (int) p.size() ){
            return i - (int)p.size(); //Found the pattern

        }else if( i == (int)txt.size())
            break;

         else if( txt[ i ] == p[ j]){
            i++;
            j++;

        }else if ( j == 0 )
            i++;

        else j = lps[ k ][ j - 1];
    }
    return -1;// notFound
}


int main(){
    ios_base::sync_with_stdio(0);
    memset(vis, 0, sizeof vis);

        cin >> n ;
        m = n;
        for( int i = 0; i < n ; i ++ ){
            // The Matrix
            cin >> mat[ i ];

        }

        q=0;
        // Patterns
        while( cin >> pat[ q ]){
            if(pat[ q ] == "0")
                break;
            ans[ q ] = Answer();
            q++;
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
                if( p != -1)
                    ans[ k ] = Answer( i, p, i, p + (int) pat[ k ].size() - 1);

                reverse(txt.begin(), txt.end() );
                p = kmp( txt , k, 1); //toLeft
                if( p != -1)
                    ans[ k ] = Answer( i, m - 1 - p, i, m - 1- p - (int) pat[ k ].size() + 1);
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
                if( p != -1)
                    ans[ k ] = Answer( p, j, p + (int) pat[ k ].size() - 1, j);

                reverse(txt.begin(), txt.end() );
                p = kmp( txt, k, 3); //toUp
                if( p != -1)
                    ans[ k ] = Answer( n - 1 - p, j, n - 1 - p - (int)pat[ k ].size() + 1, j);
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
                    if( p != -1)
                        ans[ k ] = Answer( i + p, j + p, i + p + (int) pat[ k ].size() - 1, j + p + (int) pat[ k ].size() - 1);

                    reverse(txt.begin(), txt.end() );
                    p = kmp( txt, k, 5 ); //toUpLeft
                    if( p != -1){
                        p = (int)txt.size() - 1 - p;
                        ans[ k ] = Answer( i + p, j + p, i + p - (int) pat[ k ].size() + 1, j + p - (int) pat[ k ].size() + 1);
                    }
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

                    if( p != -1)
                        ans[ k ] = Answer( i + p, j - p, i + p + (int) pat[ k ].size() - 1, j - p - (int) pat[ k ].size() + 1);

                    reverse(txt.begin(), txt.end() );
                    p = kmp( txt, k, 7);//toUpRight
                    if( p != -1){
                        p = (int)txt.size() - 1 - p;
                        ans[ k ] = Answer( i + p, j - p, i + p - (int) pat[ k ].size() + 1, j - p + (int) pat[ k ].size()- 1);
                    }

                }
            }
        }
        //It prints the answers
        for( int i = 0 ; i < q ; i ++ ){
            if(ans[ i ].ax == N)
                cout<<"Not found\n";
            else
                cout << ans[ i ].ax + 1<< "," << ans[ i ].ay + 1<<" "<< ans[ i ].bx + 1<< "," << ans[ i ].by + 1<< "\n";
        }
    return 0;
}
