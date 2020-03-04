
/*
Author :: Moniba
Problem id ::   UVA 11367
Problem name :: Full Tank?
*/

#include<bits/stdc++.h>
using namespace std;

#define N 1005
#define pii pair<int , int>
#define pb push_back

struct triple{
    int node, fuel, cost;
    triple( int _node=0, int _fuel=0, int _cost=0){
        node = _node;
        fuel = _fuel;
        cost = _cost;
    }
    bool operator<( const triple& t )const{
        return this->cost > t.cost;
    }
};

int n, m;
vector< pii > adj[ N ];
int ans[ N ][ 105 ];
int p[ N ];

void dijkstra( int s, int e, int c ){

    for( int i = 0 ; i < n ; i++ ){
        for( int j = 0 ; j <= c ; j ++){
            ans[ i ][ j ] = -1;
        }
    }

    priority_queue< triple > pq;
    pq.push( triple( s, 0, 0) );
    ans[ s ][ 0 ] = 0;

    while( !pq.empty() ){
        int node =pq.top().node;
        int fuel = pq.top().fuel;
        int cost = pq.top().cost;
        pq.pop();

        if( cost > ans[ node ][ fuel ] ) continue;

        if( fuel < c && ( ans[ node ][ fuel + 1 ] == -1 || ans[ node ][ fuel + 1 ] > cost + p[ node ] ) ){
            ans[ node ][ fuel + 1 ] = p[ node ] + cost;
            pq.push( triple( node, fuel + 1, ans[ node ][ fuel + 1 ]));
        }

        for( int i = 0 ; i < (int)adj[ node ].size(); i ++ ){
            int other = adj[ node ][ i ].first;
            int w = adj[ node ][ i ].second;
            if( fuel < w || (ans[ other ][ fuel - w ] != -1 && ans[ other ][ fuel - w ] <= cost ) )
                continue;
            ans[ other ][ fuel - w ] = cost;
            pq.push( triple( other, fuel - w , ans[ other ][ fuel - w ]));
        }

    }
}

int main(){
    scanf("%d %d", &n, &m);
    for( int i = 0 ; i < n ; i ++ ){
        scanf("%d", &p[ i ] );
    }
    int s,e,c;
    for( int i = 0; i < m ; i ++ ){
        scanf("%d %d %d", &s, &e, &c);
        adj[ s ].pb( pii( e, c));
        adj[ e ].pb( pii( s, c));
    }

    int q;
    scanf("%d", &q);
    while( q-- ){

        scanf("%d %d %d", &c, &s, &e);
        dijkstra(s, e, c);

        if( ans[ e ][ 0 ] == -1 )
            printf("impossible\n");
        else printf("%d\n",ans[ e ][ 0 ]);

    }
    return 0;

}
