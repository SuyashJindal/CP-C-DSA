#include<stdio.h>
#include<stdlib.h>
#include"assign3.h"
#include<limits.h>

#define MAX_NODES 100005
typedef struct TreeNode{
    int val;
    struct TreeNode* left,*right;
}TreeNode;
TreeNode* createNode(int val){
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
      newNode->val = val;
      newNode->left = newNode->right = NULL;
      return newNode;
}
TreeNode* insert(TreeNode* root,int val){
    if(root==NULL) return createNode(val);
    if(val<root->val)
    root->left = insert(root->left,val);
    else 
    root->right = insert(root->right,val);
    return root;
}
int getHeight(TreeNode* root){
    if(root==NULL) return 0;
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return 1+(leftHeight>rightHeight?leftHeight:rightHeight);
}
void function1(){
    int n;
    scanf("%d",&n);
    TreeNode* root= NULL;
    for(int i =0 ;i<n;i++){
        int num;
        scanf("%d",&num);
        root = insert(root,num);
    }
    printf("%d\n",getHeight(root));
   
}
/*
typedef struct {
    int pv,p1,k1,p2,k2,p3;
}Node;
int search(Node*tree,int x,int current_index){
    Node current_node = tree[current_index];
    if(x== current_node.k1|| x==current_node.k2){
        return 1;
    }
    if(x<current_node.k1 && current_node.p1!=-1){
        return search(tree,x,current_node.p1);
    }
    if(current_node.k2!=-1 && x>current_node.k1 && x<current_node.k2 && current_node.p2!=-1){
        return search(tree,x,current_node.p2);
    }
    if(current_node.k2!=-1 && x>current_node.k2 && current_node.p3!=-1){
        return search(tree,x,current_node.p3);
    }
    return 0;
}
int successor(Node* tree,int x,int current_index){
    Node current_node = tree[current_index];
    if(x<current_node.k1){
        if(current_node.p1!=-1){
            int left_successor = successor(tree,x,current_node.p1);
            return left_successor?left_successor:current_node.k1;
        }
        return current_node.k1;
    }
    if(current_node.k2!=-1 && x > current_node.k1 && x <current_node.k2){
        if(current_node.p2!=-1){
            int middle_successor = successor(tree,x,current_node.p2);
            return middle_successor? middle_successor:current_node.k2;
        }
        return current_node.k2;
    }
    if(current_node.k2!=-1 && x>=current_node.k2 && current_node.p3!=-1){
        return successor(tree,x,current_node.p3);
    }
    return 0;
}
    */
typedef struct {
    int pv,p1,k1,p2,k2,p3;
}Node;
int find_min(Node tree[],int i){
    while(tree[i].p1!=-1){
        i=tree[i].p1;
    }
    return tree[i].k1;
}
void function2(){
    int n,q;
scanf("%d %d",&n,&q);
Node tree[n];
for(int i =0;i<n;i++){
    scanf("%d %d %d %d %d %d",&tree[i].pv,&tree[i].p1,&tree[i].k1,&tree[i].p2,&tree[i].k2,&tree[i].p3);

}
for(int query =0;query<q;query++){
    int qi,x;
    scanf("%d %d",&qi,&x);
    int current =0;
    int found = 0 ; 
    int node_found  = -1 ; 
    int key_pos = -1 ;
    while(current!=-1){
        if(x==tree[current].k1){
            found =1;
            node_found = current;
            key_pos = 0;
            break;
        } else if(tree[current].k2!=-1 && x== tree[current].k2){
            found =1;
            node_found = current;
            key_pos =1;
            break;
        }
        if(tree[current].k2 == -1){
            if(x<tree[current].k1){
                current = tree[current].p1;
            } else{
                current = tree[current].p2;
            }
        }else{
            if(x<tree[current].k1){
                current = tree[current].p1;
            }else if(x<tree[current].k2){
                current = tree[current].p2;
            }else{
                current = tree[current].p3;
            }
        }
    }
    if(qi==1){
        printf("%d\n",found);
    } else{
        if(!found){
            printf("0\n");
        } else{
            int successor =0;
            if(key_pos ==0){
                if(tree[node_found].p2!=-1){
                    successor = find_min(tree,tree[node_found].p2);
                }else if(tree[node_found].k2!=-1){
                    successor = tree[node_found].k2;
                } else{
                    current = node_found;
                    while(current!=-1){
                        int parent = tree[current].pv;
                        if(parent ==-1){
                            successor =0 ; 
                            break;
                        }
                        if(tree[parent].p1 ==current){
                            successor = tree[parent].k1;
                            break;
                        }else if(tree[parent].p2 ==current && tree[parent].k2!=-1){
                            successor = tree[parent].k2;
                            break;
                        }
                        current = parent;
                    }
                }
            }else{
                  if(tree[node_found].p3!=-1){
                    successor = find_min(tree,tree[node_found].p3);
                  }else{
                    current = node_found;
                    while(current!=-1){
                        int parent = tree[current].pv;
                        if(parent ==-1){
                            successor =0;
                            break;
                        }
                        if(tree[parent].p1 ==current){
                            successor = tree[parent].k1;
                            break;
                        } else if(tree[parent].p2 ==current){
                            if(tree[parent].k2 !=-1){
                                successor = tree[parent].k2;
                                break;
                            } else{
                                current = parent;
                            }
                        }else{
                            current  = parent;
                        }
                    }
                  }
            }
            printf("%d\n",successor);
        }
    }
}

}
typedef struct node_graph{
    int vertex;
    struct node_graph* next;
}node_graph;
typedef struct{
node_graph* head;
}AdjList;
AdjList graph[MAX_NODES];
int distances_office[MAX_NODES],distances_home[MAX_NODES];
int queue[MAX_NODES];
void add_edge(int u ,int v){
    node_graph* newNode = (node_graph*)malloc(sizeof(node_graph));
    newNode->vertex  = v;
    newNode->next = graph[u].head;
    graph[u].head = newNode;
    newNode = (node_graph*)malloc(sizeof(node_graph));
    newNode->vertex = u;
    newNode->next = graph[v].head;
    graph[v].head = newNode;
}
void bfs(int start,int*distances,int n){
    for(int i = 0 ; i<n;i++){
        distances[i]=INT_MAX;
    }
    distances[start]=0;
    int front = 0 ,rear = 0 ; 
    queue[rear++] = start;
    while(front<rear){
        int current = queue[front++];
        node_graph*temp = graph[current].head;
        while(temp!=NULL){
            int neighbor = temp->vertex;
            if(distances[neighbor]==INT_MAX){
                distances[neighbor] = distances[current]+1;
                queue[rear++] = neighbor;
            }
            temp = temp->next;
        }


    }
}
void function3(){
    int n,e,m;
    scanf("%d %d %d",&n,&e,&m);
    for(int i=0;i<e;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        add_edge(u,v);
    }
    int office,home;
    scanf("%d %d",&office,&home);
    int markets[m];
    for(int i =0;i<m;i++){
        scanf("%d",&markets[i]);
    
    }
    bfs(office,distances_office,n);
    bfs(home,distances_home,n);
    int min_distance = INT_MAX;
    int result_markets[m],result_count = 0 ; 
    for(int i  = 0 ; i<m;i++){
        int market = markets[i];
        int total_distance = distances_office[market]+distances_home[market];
        if(total_distance<min_distance){
            min_distance = total_distance;
            result_count = 0;
            result_markets[result_count++] = market;
    
    }
    else if(total_distance == min_distance){
        result_markets[result_count++] = market;
    }
    
    }
    for (int i = 0; i < result_count - 1; i++) {
        for (int j = i + 1; j < result_count; j++) {
            if (result_markets[i] > result_markets[j]) {
                int temp = result_markets[i];
                result_markets[i] = result_markets[j];
                result_markets[j] = temp;
            }
        }
    }
    printf("%d %d\n", min_distance, result_count);
    for (int i = 0; i < result_count; i++) {
        printf("%d ", result_markets[i]);
    }
}
typedef struct{
    int left;
    int right;
    int height;
}Building;
typedef struct{
    int x;
    int height;   
}Point;
typedef struct{
    Point* points;
    int count;
    int capacity;
}Skyline;
Skyline* createSkyline(int capacity){
Skyline* skyline = (Skyline*)malloc(sizeof(Skyline));
skyline->points = (Point*)malloc(sizeof(Point)*capacity);
skyline->count = 0;
skyline->capacity = capacity;
return skyline;
}
void addPoint(Skyline*skyline,int x,int height){
 if(skyline->count >0 && skyline->points[skyline->count-1].height==height)
 return ; 
 if(skyline->count>0 && skyline->points[skyline->count-1].x==x){
    skyline->points[skyline->count-1].height = height ;
    return;
 }
 if(skyline->count == skyline->capacity){
    skyline->capacity *=2;
    skyline->points = (Point*)realloc(skyline->points,skyline->capacity * sizeof(Point));

 }
 skyline->points[skyline->count].x  = x;
 skyline->points[skyline->count].height = height;
 skyline->count++;

}
Skyline*mergeSkylines(Skyline*leftSkyline,Skyline*rightSkyline){
    Skyline*merged = createSkyline(leftSkyline->count + rightSkyline->count);
    int h1 = 0 ,h2=0;
    int i = 0 ,j = 0 ; 
    while(i<leftSkyline->count && j<rightSkyline->count){
        if(leftSkyline->points[i].x<rightSkyline->points[j].x){
            int x = leftSkyline->points[i].x;
            h1 = leftSkyline->points[i].height;
            int maxHeight = (h1>h2)? h1:h2;
            addPoint(merged,x,maxHeight);
            i++;
        }else{
           int x = rightSkyline->points[j].x;
           h2 = rightSkyline->points[j].height;
           int maxHeight = (h1>h2) ? h1:h2;
           addPoint(merged,x,maxHeight);
           j++;


        }
}
while(i<leftSkyline->count){
    addPoint(merged,leftSkyline->points[i].x,leftSkyline->points[i].height);
    i++;
}
while(j<rightSkyline->count){
    addPoint(merged,rightSkyline->points[j].x,rightSkyline->points[j].height);
    j++;
}

return merged;
}
Skyline* findSkyline(Building* buildings, int left, int right) {
    if (left == right) {
        Skyline* skyline = createSkyline(2);
        addPoint(skyline, buildings[left].left, buildings[left].height);
        addPoint(skyline, buildings[left].right, 0);
        return skyline;
    }
    int mid = (left + right) / 2;
    Skyline* leftSkyline = findSkyline(buildings, left, mid);
    Skyline* rightSkyline = findSkyline(buildings, mid + 1, right);
    Skyline* mergedSkyline = mergeSkylines(leftSkyline, rightSkyline);
    free(leftSkyline->points);
    free(leftSkyline);
    free(rightSkyline->points);
    free(rightSkyline);
    return mergedSkyline;
}
void function4(){
    int N;
    scanf("%d", &N);
    Building* buildings = (Building*)malloc(N * sizeof(Building));
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &buildings[i].left, &buildings[i].right, &buildings[i].height);
    }
    Skyline* skyline = findSkyline(buildings, 0, N - 1);
    for (int i = 0; i < skyline->count; i++) {
        printf("%d %d ", skyline->points[i].x, skyline->points[i].height);
    }
    printf("\n");
    free(skyline->points);
    free(skyline);
    free(buildings);


}

/*
int main(){
    int n;
    scanf("%d",&n);
    TreeNode* root= NULL;
    for(int i =0 ;i<n;i++){
        int num;
        scanf("%d",&num);
        root = insert(root,num);
    }
    printf("%d\n",getHeight(root));
    return 0;
}
*/
/*
typedef struct {
    int pv,p1,k1,p2,k2,p3;
}Node;
int search(Node*tree,int x,int current_index){
    Node current_node = tree[current_index];
    if(x== current_node.k1|| x==current_node.k2){
        return 1;
    }
    if(x<current_node.k1 && current_node.p1!=-1){
        return search(tree,x,current_node.p1);
    }
    if(current_node.k2!=-1 && x>current_node.k1 && x<current_node.k2 && current_node.p2!=-1){
        return search(tree,x,current_node.p2);
    }
    if(current_node.k2!=-1 && x>current_node.k2 && current_node.p3!=-1){
        return search(tree,x,current_node.p3);
    }
    return 0;
}
int successor(Node* tree,int x,int current_index){
    Node current_node = tree[current_index];
    if(x<current_node.k1){
        if(current_node.p1!=-1){
            int left_successor = successor(tree,x,current_node.p1);
            return left_successor?left_successor:current_node.k1;
        }
        return current_node.k1;
    }
    if(current_node.k2!=-1 && x > current_node.k1 && x <current_node.k2){
        if(current_node.p2!=-1){
            int middle_successor = successor(tree,x,current_node.p2);
            return middle_successor? middle_successor:current_node.k2;
        }
        return current_node.k2;
    }
    if(current_node.k2!=-1 && x>=current_node.k2 && current_node.p3!=-1){
        return successor(tree,x,current_node.p3);
    }
    return 0;
}
int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    Node* tree = (Node*)malloc(n*sizeof(Node));
    for(int i = 0 ; i<n;i++){
        scanf("%d %d %d %d %d %d",&tree[i].pv,&tree[i].p1,&tree[i].k1, &tree[i].p2, &tree[i].k2, &tree[i].p3);
    }
for(int i =0 ; i<q;i++){
    int qi,x;
    scanf("%d %d",&qi,&x);
    if(qi==1){
        printf("%d\n",search(tree,x,0));
    }else if(qi==2){
        printf("%d\n",successor(tree,x,0));
    }
}
free(tree);
return 0;
}
*/