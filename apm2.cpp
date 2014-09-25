/*
 *  @ Description: Kruskal's Algorithm.
 *  @ Author: Adrian Statescu <mergesortv@gmail.com>, <http://thinkphp.ro>
 *  @ License: MIT
 *  
 *  @ using vector<pair<int,int> > and iterator for display
 */
#include <cstdio>
#include <algorithm>
#include <vector>
#define x first
#define y second
#define FIN "apm2.in"
#define FOUT "apm2.out"
#define MAXE 400005

using namespace std;
 
struct Edge {
 
       int x;
       int y;
       int c;
 
} V[ MAXE ];
 
vector<pair <int, int> > Sol;
 
int num_nodes, 
    num_edges;
 
int X, Y, Cost, Father[ MAXE ];
 
int sumCost = 0;
  
void matrix() {
  
     for(int i = 1; i <= num_edges; i++) {
 
         printf("%d %d %d\n", V[i].x, V[i].y, V[i].c);
     } 
};
 
void read() {
 
     int i;
 
     freopen(FIN, "r", stdin);
 
     scanf("%d %d", &num_nodes, &num_edges);
 
     for(i = 1; i <= num_edges; i++) {
 
         scanf("%d %d %d", &V[i].x, &V[i].y, &V[i].c);
     } 
 
     fclose( stdin );
};
 
int cmp(Edge m1, Edge m2) {
 
    return m1.c < m2.c;
};
 
int find(int x) {
 
    if( Father[ x ] != x ) Father[ x ] = find( Father[ x ] );
 
    return Father[ x ];
};

void kruskal();
 
void unified(int x, int y) {
 
     Father[ x ] = y;
};

int main() {
  
    read();

    kruskal();

   return(0);
};

void kruskal() {

    int i; int k = 0;
 
    freopen(FOUT, "w", stdout);

    for(i = 1; i <= num_nodes; i++) Father[i] = i;
 
    sort(V + 1, V + num_edges + 1, cmp);
 
    for(i = 1; i <= num_edges; i++) {
 
        X = V[i].x; 
 
        Y = V[i].y;
 
        Cost = V[i].c;
 
        if(find(X) == find(Y)) continue;
 
        Sol.push_back( make_pair(X, Y) );
 
        sumCost += Cost;
  
        unified(find(X), find(Y));
    }
 
    printf("%d\n%d\n", sumCost, num_nodes-1);
 
    for(vector<pair <int,int> >::iterator i = Sol.begin(); i != Sol.end() ;++i) {

        printf("%d %d\n", i->x, i->y); 
    }

    fclose( stdout );

}