/*
 *  @ Description
 *    An implementation of Kruskal's Algorithm.
 *
 */
#include <cstdio>
#include <algorithm>
#define FIN "apm.in"
#define FOUT "apm.out"
#define MAXE 400005

struct Edge {

       int x;
       int y;
       int c;

} V[ MAXE ];

struct Sol {

       int x;
       int y;
       int c;

} S[ MAXE ];

int num_nodes, 
    num_edges;

int X, Y, Cost, Father[ MAXE ];

int sumCost = 0;

using namespace std;

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

void unified(int x, int y) {

     Father[ x ] = y;
}


int main() {

    int i; int k = 0;

    freopen(FOUT, "w", stdout);

    read();

    for(i = 1; i <= num_nodes; i++) Father[i] = i;

    sort(V + 1, V + num_edges + 1, cmp);

    for(i = 1; i <= num_edges; i++) {

        X = V[i].x; 

        Y = V[i].y;

        Cost = V[i].c;

        if(find(X) == find(Y)) continue;

        S[k].x = X; S[k++].y = Y; 

        sumCost += Cost;
 
        unified(find(X), find(Y));
    }

    printf("%d\n%d\n", sumCost, num_nodes-1);

    for(i=0;i<k;i++) printf("%d %d\n", S[i].x, S[i].y);

    fclose( stdout );

    return(0);
};