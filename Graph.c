#include <stdio.h>
#include <stdlib.h>
// Create Graph 
// Create Adjacency List
// Insert data in List
struct Node{
    int data;
    struct Node* next;
};
struct Graph{
    int totalVertices;
    struct Node** adjList;
};
struct Node* createNewNode(int value){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
void addEdge(struct Graph* graph,int src,int des){
    // For Directed Graph
    struct Node* newNode1 = createNewNode(des);
    struct Node* temp = graph->adjList[src];
    while(temp != NULL){
        if(temp->data == des) break;
        temp = temp->next;
    }
    if(temp == NULL){
        newNode1->next = graph->adjList[src];
        graph->adjList[src] = newNode1;
    }

    // For Undirected Graph
    if(src != des){
        struct Node* newNode2 = createNewNode(src);
        temp = graph->adjList[des];
        while(temp != NULL){
            if(temp->data == src) break;
            temp = temp->next;
        }
        if(temp == NULL){
            newNode2->next = graph->adjList[des];
            graph->adjList[des] = newNode2;
        }
    }
}
struct Graph* createGraph(int totalVertices){
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->totalVertices = totalVertices;
    graph->adjList = (struct Node**) malloc(sizeof(struct Node*)*totalVertices);
    int i = 0;
    for(i=0;i<totalVertices;i++){
        graph->adjList[i] = NULL;
    }
    return graph;
}
void printGraph(struct Graph* graph){
    if(graph == NULL){
        printf("Graph does not exist.");
        return;
    }
    int i=0;
    for(i=0;i<graph->totalVertices;i++){
        struct Node* adjList = graph->adjList[i];
        printf("Adjacency List of %d: ",i);
        if(adjList == NULL){
            printf("NULL\n");
        }else{
            struct Node* temp = adjList;
            while(temp != NULL){
                printf("%d ",temp->data);
                temp = temp->next;
            }
        }
        printf("\n");
    }
}
void freeGraph(struct Graph* graph){
    int i=0;
    struct Node* temp;
    struct Node* delete;
    for(i=0;i<graph->totalVertices;i++){
        temp = graph->adjList[i];
        while(temp != NULL){
            delete = temp;
            temp = temp->next;
            free(delete);
        }
    }
    free(graph);
}
void main(){
    int i = 0;
    struct Graph* graph = createGraph(6);
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 3, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 4, 3);
    addEdge(graph, 5, 5);
    addEdge(graph, 0, 5);
    addEdge(graph, 1, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 4, 0);
    addEdge(graph, 5, 1);
    addEdge(graph, 3, 5);
    printGraph(graph);
    freeGraph(graph);
    return;
}