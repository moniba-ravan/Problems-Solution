/*
Author :: Moniba
Problem id ::   UVA 12359
Problem name :: Diccionário Portuñol
*/

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define sz( x ) (int)(x).size()
#define all( x ) x.begin(),x.end()

const char nl = '\n';
const int MAX = 1000 + 5;

struct Node{
    Node* ch[ 26 ];
};

Node* getNode(){
    Node* node = new Node();
    for( int i = 0 ; i < 26 ; i ++ )
        node->ch[ i ] = NULL;
    return node;
}

void insert( Node* node, string s ){
    for( int i = 0 ; i < sz( s ) ; i ++ ){
        if( !node->ch[ s[ i ] - 'a' ] )
            node->ch[ s[ i ] - 'a' ] = getNode();
        node = node->ch[ s[ i ] - 'a'] ;
    }
}

// isEnd[i] is true if there is a suffix ( of Spanish words ) that its last letter is the i-th letter
bool isEnd[ 26 ];
// letter[i] is number of suffix start with i-th letter
ll letter[ 26 ];
// total number of distinct suffix
ll total;
int n, m;
string por[ MAX ], es[ MAX ];

void dfs( Node* node){
    for( int i = 0 ; i < 26 ; i ++ ){
        if( !node->ch[ i ] ) continue;
        dfs( node->ch[ i ]);
        total++;
        letter[ i ] ++;
    }
}

ll dfs222( Node* node, int len ){
    ll res = 0 , sum = 0;
    for( int i = 0 ; i < 26 ; i ++ ){
        if( !node->ch[ i ] ) continue;
        res += dfs222(node->ch[ i ] , len+1);
        if( len > 0 && isEnd[ i ])
            res++;
        sum += letter[ i ];
    }
    if( len != 0 ) res += total - sum;
    return res;
}
int main(){

    while( cin >> n >> m, !( n == 0 && m == 0 ) ){

        for( int i = 0 ; i < 26 ; i++ ){
            isEnd[ i ] = letter[ i ] = 0;
        }

        // Root of Portuguese Trie
        Node* porroot = getNode();
        // Root of Spanish Trie
        Node* esroot = getNode();

        //make a Trie of Portuguese words
        for( int i = 0 ; i < n ;i ++ ){
            cin >> por[ i ];
            insert(porroot, por[ i ] );
        }

        //make a Trie of Spanish reversed words
        for( int i = 0 ; i < m ; i ++ ){
            cin >> es[ i ];
            reverse(all( es[ i ] ) );
            insert(esroot, es[ i ] );
            isEnd[ es[i][0] - 'a' ] = true;
        }
        total = 0;

        //find the total number of distinct suffix
        dfs(esroot);

        //find the total Portunol words
        cout << dfs222(porroot, 0) << nl;
    }

    return 0;
}
