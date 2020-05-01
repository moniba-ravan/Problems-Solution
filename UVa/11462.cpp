  
/*
Author :: Moniba
Problem id ::   Uva 11462
Problem name ::  Age Sort
*/

#include<bits/stdc++.h>

using namespace std;

#define fastc ios_base::sync_with_stdio(0)

const int N = 105;

int cnt[ N ];
int n;

int main(){
    while( scanf("%d", &n ) ,  n != 0 ){
        memset( cnt, 0, sizeof cnt );

        for( int i = 0 ; i < n; i ++ ){
            int in;scanf("%d", &in );
            cnt[ in ] ++;
        }

        for( int i = 1 ; i <= 100 && n; i ++ ){
            while( cnt[ i ] > 0 ){
                printf("%d", i);
                cnt[ i ] --;
                n--;
                if( n ) printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
