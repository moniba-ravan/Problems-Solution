/*
Author :: Moniba
Problem id ::   NWERC 2016 B
Problem name ::  British Menu
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int , int >
#define pb push_back
#define N 100005

vector< int > adj[ 100000 + 5 ], rev[ 100000 + 5];
int visited[ 100000 + 5 ], parent[ 100000 + 5 ],dis[ 100000 + 5 ];
vector<int> sorted;
int n, m;
int x, y;

void dfs( int node ){
    visited[ node ] = 1;
    for( int i = 0 ; i < (int) adj[ node ].size() ; i ++ ){
        int other = adj[ node ][ i ];
        if( visited[ other ] )
            continue;
        dfs( other );
    }
    sorted.pb( node );

}

int find_parent(int node ){
    if( parent[ node ] == node )
        return node;
    parent[ node ] = find_parent( parent[ node ]);
    return parent[ node ];
}

void joint( int a, int b ){
    parent[ find_parent( b ) ] = find_parent( a );
}

void dfs222( int node, int p ){
    visited[ node ] = 1;
    for( int i = 0 ; i < ( int) rev[ node ].size() ; i ++ ){
        int other = rev[ node ][ i ];
        if( visited[ other ] )
            continue;

        joint(p, other );
        dfs222( other, p );
    }

}

int longestpath( int node){
    int d = 1;
    for( int i = 0 ; i < ( int )adj [ node ].size() ; i++ ){
        int other = adj[node][ i ];
        if( visited[ other ] ) continue;
        if( find_parent( other ) != find_parent( node ) ){
            visited[ other ] = 1;
               if( dis[ other ] == -1)
                   dis[ other ] = longestpath( other);
                d = max( d, dis[ other ] + 1);
                visited[ other ] = 0;

        }else{
            visited[ other ] = 1;
            d = max( d, longestpath( other) + 1);
            visited[ other ] = 0;
        }
    }
    return d;

}


int main(){
    ios_base::sync_with_stdio(0);
    memset( visited, 0, sizeof visited);
    cin >> n >> m;
    for( int i = 1 ; i <= m ; i++ ){
        cin >> x >> y;
        adj[ x ].pb( y );
        rev[ y ].pb( x );
    }
    //Topology Sort
    for( int i = 1; i <= n ; i++ ){
        parent[ i ] = i ;
        if(visited[ i ] ) continue;
        dfs( i );
    }
    //SCC
    memset( visited, 0, sizeof visited );
    for( int i = (int)sorted.size() - 1; i >=0 ; i -- ){
        int node = sorted[ i ];
        if( visited[ node ] )
            continue;
        dfs222( node, node );

    }
  
    //Longest Path
    memset( visited, 0, sizeof visited );
    memset( dis, -1, sizeof dis );
    int ans = 0;
    for( int i = 0 ; i < ( int) sorted.size() ; i ++ ){
        int node = sorted[ i ];
        if( dis[ node ] != -1 ) continue;
        visited[ node ] = 1;
        dis[ node ] = longestpath( node ) ;
        ans = max( ans, dis[ node ]);
        visited[ node ] = 0;
    }
    cout << ans << endl;
	return 0;
}
