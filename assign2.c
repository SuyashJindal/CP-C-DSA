#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>
#include<string.h>
#define MAXN 100007
#define MOD 1000000007
int *B;
#define MAXA 100005
#include"assign2.h"
typedef struct QueueNode{
    int value;
    struct QueueNode *next;

}QueueNode;
typedef struct{
    QueueNode *front,*rear;
}Queue;

typedef  struct DequeNode{
    int value;
    struct DequeNode *next,*prev;
}DequeNode;

typedef struct{
    DequeNode *front,*rear;
}Deque;

Queue* createQueue(){
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q ; 
}
Deque*createDeque(){
    Deque *dq = (Deque*)malloc(sizeof(Deque));
    dq->front = dq->rear = NULL;
    return dq ;
}
void enqueue(Queue *q,int val){
    QueueNode *newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->value = val ;
    newNode->next = NULL ;
    if(!q->rear){
        q->front   = q->rear = newNode;
    }else{
        q->rear->next = newNode ;
        q->rear = newNode ;
    }

}
int dequeue(Queue *q){
    if(!q->front) return -1 ; 
    int val = q->front->value;
    QueueNode *temp  = q->front;
    q->front = q->front->next ;
    if(!q->front) q->rear = NULL;
    free(temp);
    return val;

}
int isEmptyQueue(Queue*q){
    return q->front ==NULL;
}
void insertMax(Deque *dq,int val){
    DequeNode*newNode = (DequeNode*)malloc(sizeof(Deque));
    newNode->value = val ;
    newNode->next = newNode->prev = NULL ;
    while(dq->rear && dq->rear->value<val){
        DequeNode*temp = dq->rear;
        dq->rear = dq->rear->prev ;
        if(dq->rear) dq->rear->next = NULL;
        free(temp);
    }
    if(!dq->rear){
        dq->front = dq->rear = newNode;
    }else{
        dq->rear->next = newNode;
        newNode->prev = dq->rear;
        dq->rear = newNode;
    }
    
}
void removeMax(Deque *dq,int val){
    if(dq->front && dq->front->value == val){
        DequeNode*temp = dq->front;
        dq->front = dq->front->next ;
        if(dq->front) dq->front->prev = NULL ;
        else dq->rear = NULL;
        free(temp);
    }
}
int getMax(Deque*dq){
    return dq->front ? dq->front->value:-1;
}
void buildSparseTable(int arr[],int n ){
    int j ,i,k = 17;
    B = (int*)malloc(n*k*sizeof(int));
    for(i = 0 ; i<n;i++)
    B[i*k] = arr[i];
    for(j = 1; (1<<j)<=n;j++){
        for(i = 0 ; i+(1<<j)<=n;i++){
            B[i*k+j] =(B[i*k+(j-1)]<B[(i+(1<<(j-1)))*k+(j-1)])?B[i*k+(j-1)]:B[(i+(1<<(j-1)))*k + (j-1)];
        }
    }
}
int query(int i , int j ){
    int L = j-i+1;
    int  k = 31 - __builtin_clz(L);
    int t = (1<<k);
    return (B[i*17+k]<B[(j-t+1)*17+k])?B[i*17+k]:B[(j-t+1)*17+k];
}
void function1(){
   int q;
   scanf("%d",&q);
   Queue *queue = createQueue();
   Deque *maxDeque = createDeque();
    for(int i = 0 ; i<q;i++){
        int type;
        scanf("%d",&type);
        if(type == 1){
            int v;
            scanf("%d",&v);
             enqueue(queue,v);
             insertMax(maxDeque,v);
            
    }
    else if(type==2){
        if(!isEmptyQueue(queue)){
            int removed = dequeue(queue);
            removeMax(maxDeque,removed);
        }
    }
    else if(type==3){
        printf("%d\n",getMax(maxDeque));
    }
}
}
void function2(){
     int n, q, i, j;
    scanf("%d %d", &n, &q);

    int arr[MAXN];
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    buildSparseTable(arr, n);

    while (q--) {
        scanf("%d %d", &i, &j);
        printf("%d\n", query(i - 1, j - 1));  
    }

    free(B);
    /*
    int n , q; 
    scanf("%d %d",&n,&q);
    int arr[MAXN];
  

    for(int i = 0; i<n;i++)
    scanf("%d",&arr[i]);
    buildSparseTable(arr,n);
    while (q--) {
        scanf("%d %d", &i, &j);
        printf("%d\n", query(i - 1, j - 1));  // Convert 1-based index to 0-based
    }

    free(B);  // Free allocated memory
  
    int queries[q][2];
    int results[q];
    for(int k = 0 ; k<q;k++){
        scanf("%d %d",&queries[k][0],&queries[k][1]);
    }
    for(int k = 0 ; k<q;k++){
        int i = queries[k][0]-1;
        int j  = queries[k][1]-1;
        results[k] = query(i,j);
}
for(int k =0 ;k<q;k++){
    printf("%d\n",results[k]);
}
*/
}
void function3(){
int n;
scanf("%d",&n);
long long dp[1001]={0};
dp[0]=1;
for(int i= 1;i<=n;i++){
    dp[i]=0;
    for(int j = 0 ;j<i;j++){
        dp[i]=(dp[i]+(dp[j]*dp[i-1-j])%MOD)%MOD;
    }
}

printf("%lld\n",dp[n]);
}

void function4(){
        int n, q;
    if (scanf("%d %d", &n, &q) != 2) {
        return 1;
    }
    
    
    int *a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    int *L = (int*)malloc(n * sizeof(int));
    int *R = (int*)malloc(n * sizeof(int));

    int *stack = (int*)malloc(n * sizeof(int));
    int top = -1;  
    
   
    for (int i = 0; i < n; i++) {
        while (top >= 0 && a[stack[top]] >= a[i]) {
            top--;
        }
        if (top >= 0)
            L[i] = stack[top];
        else
            L[i] = -1;
        stack[++top] = i;
    }
    
    
    top = -1;

    for (int i = n - 1; i >= 0; i--) {
        while (top >= 0 && a[stack[top]] >= a[i]) {
            top--;
        }
        if (top >= 0)
            R[i] = stack[top];
        else
            R[i] = n;
        stack[++top] = i;
    }
    
    
    free(stack);

    int maxSub[MAXA];
    for (int i = 0; i < MAXA; i++) {
        maxSub[i] = 0;
    }
    

    for (int i = 0; i < n; i++) {
        int len = R[i] - L[i] - 1;
        
        if (len > maxSub[a[i]])
            maxSub[a[i]] = len;
    }
    
    for (int i = 0; i < q; i++) {
        int k;
        scanf("%d", &k);
        if (k < 0 || k >= MAXA) {
            printf("0\n");
        } else {
            printf("%d\n", maxSub[k]);
        }
    }
    free(a);
    free(L);
    free(R);
    
    return 0;
}
