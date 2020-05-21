  
/*
Author :: Moniba
Problem id ::   UVA 164
Problem name :: String Computer
*/

#include<bits/stdc++.h>

using namespace std;

#define sz(v) ((int)v.size())

string a, b, line;
int n;
int dp[ 25 ][ 25 ], act[ 25 ][ 25 ];

string pos( int i ){
    string ans ;
    if( i < 10 ){
        ans = "0";
        ans += (char)(i + '0') ;
    }else{
        ans = (char)(i/10 + '0');
        ans += (char)(i%10 + '0');
    }
    return ans;
}

int main(){
    while( true ){
        getline(cin , line );
        if( line == "#")
            break;
        n = line.size();
        for( int i = 0 ; i < n ; i ++ ){
            if( line[ i ] != ' ')
                continue;
            a = '+' + line.substr(0, i);
            b = '-' + line.substr(i + 1, n - 1 - i);
            break;
        }
        for( int i = 0 ; i < sz(a) ; i ++ ){
            dp[ i ][ 0 ] = i;
            act[ i ][ 0 ] = 1;
        }
        for( int j  = 0 ; j < sz(b) ; j ++ ){
            dp[ 0 ][ j ] = j;
            act[ 0 ][ j ] = 2;
        }

        for( int i = 1; i < sz(a); i ++ ){
            for( int j = 1 ; j < sz(b); j  ++ ){
                if( a[ i ] == b[ j ] ){
                    dp[ i ][ j ] = dp[ i - 1][ j - 1];
                    act[ i ][ j ] = 0;
                }else{
                    dp[ i ][ j ] = min( dp[ i - 1][ j ],
                                       min( dp[ i ][ j - 1],
                                           dp[ i - 1 ][ j - 1])
                                       ) + 1;
                    if( dp[ i ][ j ] == dp[ i - 1][ j ] + 1 )
                        act[ i ][ j ] = 1; // D
                    if( dp[ i ][ j ] == dp [ i ][ j - 1 ] + 1)
                        act[ i ][ j ] = 2; // I
                    if( dp[ i ][ j ] == dp[ i - 1][ j - 1] + 1 )
                        act[ i ][ j ] = 3;
                }
            }
        }

        line = "";
        int i = sz(a) - 1, j = sz( b ) - 1;
        while( i != 0 || j != 0 ){
            int val = act[ i ][ j ];
            if( val == 0 ){
                i --;
                j --;
            }else if( val == 1 ){
                line += "D";
                line +=a[ i ];
                line += pos(i);
                i --;
            }else if( val == 2 ){
                line += "I";
                line +=b[ j ];
                line += pos(i+1);
                j --;
            }else{
                line += "C";
                line +=b[ j ];
                line += pos(i);

                i --;
                j --;
            }
        }
        cout << line << "E\n";

    }
    return 0;
}
