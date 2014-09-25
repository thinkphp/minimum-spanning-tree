/*
 *  @ Description: Kruskal's Algorithm.
 *  @ Author: Adrian Statescu <mergesortv@gmail.com>, <http://thinkphp.ro>
 *  @ License: MIT
 *  
 *  @ using vector<pair <int, pair<int,int> > > and iterator for display
 */
#include <cstdio>
#include <algorithm>
#include <vector>
#define x first
#define y second
#define FIN "apm3.in"
#define FOUT "apm3.out"
#define MAXE 400005

using namespace std;
 
vector<pair <int, pair<int, int> > > Edge; //here we'll store the edges
 
vector<pair <int, int> > Sol; //here we'll store the edges with minimum cost
 
int num_nodes, //number of nodes
    num_edges; //number of edges
 
int X, 
    Y, 
    Cost, 
    Father[ MAXE ],
    sumCost = 0;
  
void read() {
 
     int i;
 
     freopen(FIN, "r", stdin);
 
     scanf("%d %d", &num_nodes, &num_edges);
 
     for(i = 1; i <= num_edges; i++) {
 
         scanf("%d %d %d", &X, &Y, &Cost);

         Edge.push_back( make_pair(Cost, make_pair(X, Y)) );
     } 
 
     fclose( stdin );
};
 
bool cmp(pair <int, pair<int, int> > A, pair <int, pair<int, int> > B) {

     return A.first < B.first;
};
 
int find(int x) {
 
    if( Father[ x ] != x ) Father[ x ] = find( Father[ x ] );
 
    return Father[ x ];
};

void unified(int x, int y) {
 
     Father[ x ] = y;
};

void kruskal() {

    int i; 

    for(i = 1; i <= num_nodes; i++) Father[i] = i;
 
    sort(Edge.begin(), Edge.end(), cmp);
       
    for(i = 0 ; i < Edge.size(); i++) {
           
        Cost = Edge[i].first;

        X = Edge[ i ].second.first;

        Y = Edge[ i ].second.second;

        if(find( X ) == find( Y )) continue;
 
        Sol.push_back( make_pair(X, Y) );
 
        sumCost += Cost;
  
        unified(find( X ), find( Y ));
    }
 
 };

void write() {

    freopen(FOUT, "w", stdout);

    printf("%d\n%d\n", sumCost, num_nodes-1);
 
    for(vector<pair <int,int> >::iterator i = Sol.begin(); i != Sol.end() ;++i) {

        printf("%d %d\n", i->x, i->y); 
    }

    fclose( stdout );
};

int main() {
  
    read();
    kruskal();
    write();
 
   return(0);
};

