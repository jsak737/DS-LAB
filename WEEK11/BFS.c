#include <stdio.h>
#include <stdlib.h>

#define MAX 100


int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;


void enqueue(int item) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = item;
}


int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return -1;
    }
    return queue[front++];
}


void bfs(int start, int n) {
    int i;
    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");
    while (front <= rear) {
        int current = dequeue();
        printf("%d ", current);

        for (i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}


int main() {
    int n, start;


    printf("Enter the number of vertices: ");
    scanf("%d", &n);


    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }


    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }


    printf("Enter the starting vertex: ");
    scanf("%d", &start);


    bfs(start, n);

    return 0;
}
