
/*
Author :: Moniba
Problem id ::   UVA 526
Problem name :: String Distance and Transform Process
*/

using namespace std;

const int N = 85;

int n, m, cas = 1;
string a, b;
int dp[ N ][ N ], act[ N ][ N ];
int main(){
    while( true){
    
        if(cin.peek() == EOF)
            break;
        // Don't forget about empty strings
        getline(cin, a);
        getline(cin, b);

        if( 1 != cas ++ )
            cout <<'\n';
            
        a = '+' + a;
        b = '-' + b;
        n = a.size();
        m = b.size();
        
        for( int i = 1 ; i < n ; i ++ ){
            dp[ i ][ 0 ] = i;
            act[ i ][ 0 ] = 2;
        }
        for( int j = 1 ; j < m ; j ++ ){
            dp[ 0 ][ j ] = j;
            act[ 0 ][ j ] = 3;
        }

        for( int i = 1 ; i < n ; i ++ ){
            for( int j = 1 ; j < m ; j ++ ){
                if( a[ i ] == b[ j ] ){
                    dp[ i ][ j ] = dp[ i - 1][ j - 1] ;
                    act[ i ][ j ] = 0; //no action
                }else{
                    dp[ i ][ j ] = min(dp[ i - 1][ j - 1], // replace
                                       min(dp[ i - 1][ j ], // delete
                                           dp[ i ][ j - 1 ] // insert
                                           )
                                       ) + 1;
                    
                    if( dp[ i ][ j ] == dp[ i - 1][ j - 1] + 1){
                        act[ i ][ j ] = 1; // replace
                    }else if( dp[ i ][ j ] == dp[ i - 1][ j ] + 1){
                        act[ i ][ j ] = 2; // delete
                    }else if( dp[ i ][ j ] == dp[ i ][ j - 1 ] + 1){
                        act[ i ][ j ] = 3; // insert
                    }
                }
            }
        }

        int i = n - 1, j = m - 1;
        int sz = dp[ i ][ j ];
        cout << sz << '\n';
        for( int k = 1 ; k <= sz ; k ++ ){
            int temp = act[ i ][ j ];
            if( temp == 0 ){
                k--;
                i--;
                j--;
            }
            if( temp == 1 ){
                cout << k << " Replace " << i <<"," << b[ j ] <<"\n";
                i--;
                j--;
            }
            if( temp == 2 ){
                cout << k << " Delete " << i <<"\n";
                i--;
            }
            if( temp == 3 ){
                cout << k << " Insert " << i + 1 <<"," << b[ j ] <<"\n";
                j--;
            }
        }


    }
    return 0;
}
