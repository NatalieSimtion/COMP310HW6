#include <stdio.h>
#include <stdlib.h>

#define N 8 //vertices

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

