#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 10

int hashFunction(int key) {
    return key % MAX_VERTICES;
}

struct Node {
    int vertex;
    struct Node* next;
};

struct GraphMatrix {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
};

struct GraphList {
    int numVertices;
    struct Node* adjLists[MAX_VERTICES];
};

void initGraphMatrix(struct GraphMatrix* g, int vertices) {
    g->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

void addEdgeMatrix(struct GraphMatrix* g, int src, int dest) {
    g->adjMatrix[src][dest] = 1;
    g->adjMatrix[dest][src] = 1;
}

void printGraphMatrix(struct GraphMatrix* g) {
    for (int i = 0; i < g->numVertices; i++) {
        for (int j = 0; j < g->numVertices; j++) {
            printf("%d ", g->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void initGraphList(struct GraphList* g, int vertices) {
    g->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        g->adjLists[i] = NULL;
    }
}

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdgeList(struct GraphList* g, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = g->adjLists[src];
    g->adjLists[src] = newNode;
    newNode = createNode(src);
    newNode->next = g->adjLists[dest];
    g->adjLists[dest] = newNode;
}

void printGraphList(struct GraphList* g) {
    for (int i = 0; i < g->numVertices; i++) {
        struct Node* temp = g->adjLists[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void BFSMatrix(struct GraphMatrix* g, int startVertex) {
    bool visited[MAX_VERTICES] = {false};
    int queue[MAX_VERTICES];
    int front = -1, rear = -1;
    visited[startVertex] = true;
    queue[++rear] = startVertex;

    printf("BFS (Matrix): ");
    while (front != rear) {
        int current = queue[++front];
        printf("%d ", current);
        for (int i = 0; i < g->numVertices; i++) {
            if (g->adjMatrix[current][i] == 1 && !visited[i]) {
                queue[++rear] = i;
                visited[i] = true;
            }
        }
    }
    printf("\n");
}

void DFSMatrix(struct GraphMatrix* g, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);
    for (int i = 0; i < g->numVertices; i++) {
        if (g->adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFSMatrix(g, i, visited);
        }
    }
}

void DFSMatrixWrapper(struct GraphMatrix* g, int startVertex) {
    bool visited[MAX_VERTICES] = {false};
    printf("DFS (Matrix): ");
    DFSMatrix(g, startVertex, visited);
    printf("\n");
}

void BFSList(struct GraphList* g, int startVertex) {
    bool visited[MAX_VERTICES] = {false};
    int queue[MAX_VERTICES];
    int front = -1, rear = -1;
    visited[startVertex] = true;
    queue[++rear] = startVertex;

    printf("BFS (List): ");
    while (front != rear) {
        int current = queue[++front];
        printf("%d ", current);
        struct Node* temp = g->adjLists[current];
        while (temp) {
            if (!visited[temp->vertex]) {
                queue[++rear] = temp->vertex;
                visited[temp->vertex] = true;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

void DFSList(struct GraphList* g, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);
    struct Node* temp = g->adjLists[vertex];
    while (temp) {
        if (!visited[temp->vertex]) {
            DFSList(g, temp->vertex, visited);
        }
        temp = temp->next;
    }
}

void DFSListWrapper(struct GraphList* g, int startVertex) {
    bool visited[MAX_VERTICES] = {false};
    printf("DFS (List): ");
    DFSList(g, startVertex, visited);
    printf("\n");
}

int main() {
    struct GraphMatrix gMatrix;
    initGraphMatrix(&gMatrix, 5);
    addEdgeMatrix(&gMatrix, 0, 1);
    addEdgeMatrix(&gMatrix, 0, 4);
    addEdgeMatrix(&gMatrix, 1, 2);
    addEdgeMatrix(&gMatrix, 1, 3);
    addEdgeMatrix(&gMatrix, 1, 4);
    addEdgeMatrix(&gMatrix, 3, 4);

    printf("Adjacency Matrix Representation:\n");
    printGraphMatrix(&gMatrix);
    BFSMatrix(&gMatrix, 0);
    DFSMatrixWrapper(&gMatrix, 0);

    struct GraphList gList;
    initGraphList(&gList, 5);
    addEdgeList(&gList, 0, 1);
    addEdgeList(&gList, 0, 4);
    addEdgeList(&gList, 1, 2);
    addEdgeList(&gList, 1, 3);
    addEdgeList(&gList, 1, 4);
    addEdgeList(&gList, 3, 4);

    printf("\nAdjacency List Representation:\n");
    printGraphList(&gList);
    BFSList(&gList, 0);
    DFSListWrapper(&gList, 0);

    return 0;
}