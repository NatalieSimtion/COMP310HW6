#include <stdio.h>
#include <stdlib.h>

#define N 8 //vertices T1, T2, T3, T4, T5, T6, T7, T8

//data structure 4 graph


struct GraphStructure {
  //array of pointers to Node
struct Node* head[N];

};


//data structure 4 nodes of graph
struct Node {
  int destination;
  struct Node* next;
};

//data struct 4 edge

struct Edge {
  int source, destination;
};

//adjacency list 4  from edges
struct GraphStructure* createGraph(struct Edge edges[], int n)  {

  //storage

    struct GraphStructure* graph = (struct Graph*)malloc(sizeof(struct GraphStructure));

    //head pointer 4 vertex components

    for(int i = 0;  i < N; i++) {
      graph->head[i] = NULL;
    }
    for(int i = 0; i < n; i++) {
      //source and destination vertex
      int source = edges[i].source;
      int destination = edges[i].destination;

      //new node from source to destintation
      struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
      newNode->destination = destination;

      //new node to current head
      newNode->next = graph->head[source];

      //header  to new node
      graph->head[source] = newNode;

    }
    return graph;


}

//print list of graph

void printGraph( struct GraphStructure* graph) {
  for (int i =0; i < N; i++) {
    //vertex &neighbors
        struct Node* ptr = graph->head[i];
  while (ptr != NULL) {
    printf("(%d -> %d)\t",i, ptr->destination);
    ptr = ptr->next;

  }
  printf("\n");

  }
}

int main(void) {
  struct Edge edges[] = {
    {1,2},{1,3},{1,7},{2,4},{3,4},{4,5},{7,6},{6,5},{6,8}
  };
  //edges
  int nEdges = sizeof(edges)/sizeof(edges[0]);

  struct GraphStructure *graph = createGraph(edges,nEdges);

  printGraph(graph);

  return 0;
}
//output is below
//(1 -> 7)    (1 -> 3)    (1 -> 2)
//(2 -> 4)
//(3 -> 4)
//(4 -> 5)

//(6 -> 8)    (6 -> 5)/
//(7 -> 6)
