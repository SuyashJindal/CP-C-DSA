#include"assign4.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_K 1000
#define MAX_N 100000
typedef struct{
    int value;
    int row;
    int col;
}HeapNode;
HeapNode heap[MAX_N];
int heapSize=0;
void swap(HeapNode*a,HeapNode*b){
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}
void heapifyUp(int i){
    while(i>0){
        int parent = (i-1)/2;
        if(heap[i].value<heap[parent].value){
            swap(&heap[i],&heap[parent]);
            i = parent;
        }
        else break;
    }
}
void heapifyDown(int i){
    int left,right,smallest;
    while(1){
        left = 2*i+1;
        right = 2*i+2;
        smallest = i;
        if(left<heapSize && heap[left].value<heap[smallest].value)
        smallest = left;
        if(right<heapSize && heap[right].value<heap[smallest].value)
        smallest = right;
        if(smallest!=i){
            swap(&heap[i],&heap[smallest]);
            i = smallest;

        }else break;
    }
}
void push(HeapNode node){
    heap[heapSize]=node;
    heapifyUp(heapSize);
    heapSize++;
}
HeapNode pop(){
    HeapNode minNode = heap[0];
    heap[0] = heap[--heapSize];
    heapifyDown(0);
    return minNode;
}
#define MAXN 100005
typedef struct {
    int u, v;
} Edge;

int n, m;
int timer = 0;
int disc[MAXN], low[MAXN];
int visited[MAXN];
Edge bridges[MAXN]; 
int bridgeCount = 0;
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adj[MAXN] = {0};
void addEdge(int u, int v) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->vertex = v;
    node->next = adj[u];
    adj[u] = node;
}
int cmp(const void *a, const void *b) {
    Edge *e1 = (Edge *)a;
    Edge *e2 = (Edge *)b;
    if (e1->u != e2->u)
        return e1->u - e2->u;
    return e1->v - e2->v;
}

void dfs(int u, int parent) {
    visited[u] = 1;
    disc[u] = low[u] = ++timer;

    for (Node* temp = adj[u]; temp != NULL; temp = temp->next) {
        int v = temp->vertex;

    
        if(v == parent)
            continue;

        if(!visited[v]) {
            dfs(v, u);
            
            if(low[v] < low[u])
                low[u] = low[v];

            
            if(low[v] > disc[u]) {
             
                if(u < v) {
                    bridges[bridgeCount].u = u;
                    bridges[bridgeCount].v = v;
                } else {
                    bridges[bridgeCount].u = v;
                    bridges[bridgeCount].v = u;
                }
                bridgeCount++;
            }
        } else { 

            if(disc[v] < low[u])
                low[u] = disc[v];
        }
    }
}

void function3(){
    int k;
    scanf("%d",&k);
    int *arrays[MAX_K];
    int sizes[MAX_K];
    for (int i = 0; i < k; i++) {
        scanf("%d", &sizes[i]);
        arrays[i] = (int *)malloc(sizes[i] * sizeof(int));
        for (int j = 0; j < sizes[i]; j++) {
            scanf("%d", &arrays[i][j]);
        }
       
        if (sizes[i] > 0) {
            HeapNode node = {arrays[i][0], i, 0};
            push(node);
        }
    }
while(heapSize>0){
    HeapNode curr  = pop();
    printf("%d ",curr.value);
    if(curr.col+1<sizes[curr.row]){
        HeapNode nextNode ={
            arrays[curr.row][curr.col+1],
            curr.row,
            curr.col+1
        };
        push(nextNode);
    }
}
for(int i =0;i<k;i++){
    free(arrays[i]);
}
}
void function2(){
    scanf("%d %d", &n, &m);
    int u, v;

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i])
            dfs(i, -1);
    }

    if(bridgeCount == 0) {
        printf("-1\n");
    } else {
      
        qsort(bridges, bridgeCount, sizeof(Edge), cmp);
        for (int i = 0; i < bridgeCount; i++) {
            printf("%d %d\n", bridges[i].u, bridges[i].v);
        }
    }

    for (int i = 0; i < n; i++) {
        Node* current = adj[i];
        while(current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
}
void function1(){
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);
        int *arr = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        int cand1 = -1, cand2 = -1;
        int count1 = 0, count2 = 0;

        
        for (int i = 0; i < n; i++) {
            if (arr[i] == cand1) {
                count1++;
            } else if (arr[i] == cand2) {
                count2++;
            } else if (count1 == 0) {
                cand1 = arr[i];
                count1 = 1;
            } else if (count2 == 0) {
                cand2 = arr[i];
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }

        
        count1 = 0;
        count2 = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] == cand1) count1++;
            else if (arr[i] == cand2) count2++;
        }

        int threshold = n / 3;
        if (count1 > threshold && count2 > threshold && cand1 != cand2) {
            if (cand1 > cand2) {
                int temp = cand1;
                cand1 = cand2;
                cand2 = temp;
            }
            printf("YES\n%d %d\n", cand1, cand2);
        } else {
            printf("NO\n");
        }

        free(arr);
    }
}