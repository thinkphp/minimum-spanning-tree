#include <stdio.h>
#define INFINIT 888
#define FIN "apm.in"
#define FOUT "apm.out"
#define MAX 15000

int num_nodes, num_edges;
int S[ MAX ], F[ MAX ];
long int cost = 0;
int mat[ MAX ][ MAX ];

void read() 
{
     int i,
         j,
         c;

     freopen(FIN, "r", stdin);      

     scanf("%d %d", &num_nodes, &num_edges); 

     for(i = 1; i <= num_nodes; i++) {

         for(j = 1; j <= num_nodes; j++) {

             if( i == j) { 

                   mat[i][j] = 0;

             } else {

                   mat[i][j] = INFINIT;
             }
        }
     }

      
     while(num_edges--) {

           scanf("%d %d %d", &i, &j, &c);

           mat[ i ][ j ] = c;     
           mat[ j ][ i ] = c;
     } 

     fclose( stdin ); 

};

void matrix() {

     int i,j;

     for(i = 1; i <= num_nodes; i++) {

         for(j = 1; j <= num_nodes; j++) {

             printf("%5d ",mat[i][j]);
         }

         printf("\n");
     }
};

void solve() {

     int i,
         j,
         min, posMin = -1;  

     int start;

     start = 1;
 
     for(i = 1; i <= num_nodes; i++) {

         if(i == start) S[ i ] = 0;

                 else   

                        S[ i ] = start;
     }   

     for(i = 1; i <= num_nodes - 1; i++) {

             min = INFINIT;      
         
             for(j = 1; j <= num_nodes; j++) {

                 if(S[ j ]) {

                             if( mat[ S[j] ][ j ] < min) {

                                 min = mat[ S[j] ][ j ];

                                 posMin = j; 
                             }               
                 }
                  
             } 


             F[ posMin ] = S[ posMin ]; 

             cost += mat[S[posMin]][posMin]; 

             S[ posMin ] = 0;
 
             //updated the rest of the nodes
             for(j = 1; j <= num_nodes; j++){

                     if(S[j] && mat[ posMin ][ j ] < mat[ S[j] ][ j ] ) S[j] = posMin;  
             }
     }     

     freopen(FOUT, "w", stdout);      

     printf("%ld\n%d\n", cost, num_nodes-1);

             for(j = 1; j <= num_nodes; j++){

                      if(F[j]) printf("%d %d\n", j, F[j]);

             }
     fclose( stdout ); 

};

int main() 
{
 
    read();  
    solve();

    return(0);
};