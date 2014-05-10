/*  Author: Srinivas Suri.

-> Implementation of Ford Fulkerson Algorithm.
-> Basic implementation with Running Time O(Capacity)*O(|V|+|E|)
        Where by Capacity , we mean the Capacity of Maximum flow.
        |V| is the number of vertices
        |E| is the number of edges
-> Residual Graph Search : DFS.
-> Assumptions: All edges have an integer weight.
*/

#include<iostream>
#include<cstdlib>
#define true 1
#define false 0
#define INF 10000000
#define MAX 1000
using namespace std;

struct gnode{
    int v;
    int c; //capacity
    struct gnode *next;
};


struct gnode *g[MAX]; //Residual Graph
int visited[MAX]; // for DFS
int n,m; //vertices,edges
int dfs_flag; //To see if there is a path from |S| to |T|
int p[MAX],psize;  //path,pathsize
int maxflow;
int stflag[MAX][MAX];

void updateGraph(int *p,int psize){
//Get the bottleneck of this path
// update the residual graph
    int i,bottleneck;

    cout<<"Path followed is: ";
    for(i=0;i<=psize;i++)
        cout<<p[i]<<" ";
    cout<<endl;

    bottleneck = INF;

    for(i=0;i<psize;i++){
        struct gnode *trav;
        trav = g[ p[i] ];
        while(trav != NULL){
            if(trav->v == p[i+1])
                break;
            trav = trav->next;
        }
        if(  bottleneck > trav->c )
            bottleneck = trav->c;
    }//for

    cout<<"Bottleneck is: "<<bottleneck<<endl;

    maxflow += bottleneck;

    for(i=0;i<psize;i++){
        struct gnode *trav;
        trav = g[ p[i]  ];
        while(trav != NULL){
            if(trav->v == p[i+1])
                break;
            trav = trav->next;
        }
        trav->c = trav->c - bottleneck;
    }// O( |E| + |V|)

     for(i=psize;i>0;i--){
        struct gnode *trav;
        trav = g[ p[i]  ];
        while(trav != NULL){
            if(trav->v == p[i-1])
                break;
            trav = trav->next;
        }
        trav->c = trav->c + bottleneck;
    }// O( |E| + |V|)


}//updateGraph


void dfs(int v,int *p,int psize ) {
    int i;
    struct gnode *trav;
    trav = g[v];
    p[psize] = v;
    visited[v] = true;
    if(v == n-1){
                dfs_flag = true;
                updateGraph(p,psize); //As we have reached the sink vertex,update the residual graph.
                return;
                }
    //printf("%d ",v);
	while ( trav!= NULL ) {
		if ( visited [ trav->v ] == 0 && trav->c > 0) {
			visited [ trav->v ] = true;
			if(trav->v == n-1){
                dfs_flag = true;
                p[++psize] = trav->v;
                updateGraph(p,psize); //As we have reached the sink vertex,update the residual graph.
                return;
                }
			dfs( trav->v ,p, psize + 1);
		}
		trav=trav->next;
	}//end of while
}//dfs


void add(int v1,int v2,int c){ //adding vertices to the graph
    struct gnode *temp;
    temp = g[v1];

    if(temp==NULL){
        g[v1] = (struct gnode *) malloc(sizeof(struct gnode *));
        g[v1]->v = v2;
        g[v1]->c = c;
        g[v1]->next = NULL;
    }

    g[v1] = (struct gnode *) malloc(sizeof(struct gnode *));

    g[v1]->v = v2;
    g[v1]->c = c;
    g[v1]->next = temp;


}

void printVertices(struct gnode *temp){
    if(temp == NULL){
        cout<<endl;
        return;
        }

    cout<<"("<<temp->v<<","<<temp->c<<")";
    printVertices(temp->next);
}

void printGraph(int n){
    int i,j;

    for(i=0;i<n;i++){
        cout<<i<<": ";
        printVertices(g[i]);
        }
    cout<<endl;
}

void reset(){
        int i;
        dfs_flag = false;
        psize = 0;
        for(i=0;i<n;i++)
            visited[i] = false;
}



int main(){
    int t,a,b,c,i,j;

    cin>>n>>m;

    t=m;

    if(t<n-1){
        cout<<"Connectivity Error"<<endl;
        return 0;
        }

    for(i=0;i<1000;i++)
        g[i] = NULL;

    for(i=0;i<MAX;i++)
        for(j=0;j<MAX;j++)
            stflag[i][j] = 0;


    while(t--){
        //Please ensure that input follows the following strategy,0 is the source, n-1 is the sink
        cin>>a>>b>>c;
        if(a<0 || a>n-1 || b<0 || c<0){
            cout<<"Input Error"<<endl;
            return 0;
        }
        add(a,b,c);//0 based indexing
        add(b,a,0); //back edge
    }

    printGraph(n);

    maxflow = 0;

    while(true){
        reset(); // reset few values prior dfs
        dfs(0,p,psize);
        if(dfs_flag == false)
            break; // Reached a maximum flow
    }

    cout<<"Maximum flow reached: "<<maxflow<<endl;

    return 0;
}


/*   Proof of Running Time:

-> Earlier I have mentioned that Running time is O(Capacity)*O(|V|+|E|)

    Everytime ResidualGraph is updated, the capacity increases by atleast 1 ,
    Let's call the Maximum Flow as C, We can update the residual graph at most C times.
    Hence the Running Time: O(C)*O(|V|+|E|)
*/


/* Graph Generation:

->  A Maximum of 1000 vertices. (So that an n^2 implementation for the graphs will suffice)
->  A capacity of at most 10^6 for each edge.          ( Although we can go till 10^20, it will take really long time once the number of iterations exceeds 10^9)
        In the worst case, the maximum flow can be 10^9, where every edge contributes to the flow.

-> Randomised Graph Generator ensuring that S and T are connected.
Boundary Cases Included:
    Complete Graph ( Except the edge from S to T )
    Disconnected Graph ( When S and T are not connected )
    A simple Graph like a train. ( only 1 dfs will suffice)



*/

// One big problem is ensuring that graph is connected during the graph generation, how do  i ensure that? Union Find?
