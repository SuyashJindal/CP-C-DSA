struct Node{
    int key;
    Node*left,*right;
    Node(int x){
        key= x; 
     left = right = NULL; 
     
    }
};
bool search(Node * root , int x){
    if(root ==NULL) return false;
    else if (root->key==x)
    return true;
    else if(root->key>x)
    return search(root->left,x);
    else
      
        return search(root->right,x);
}
bool search(Node* root, int x){
    while(root!=NULL){
        if(root->key==x)
        return true;
        else if (root->key<x)
        root = root->right; 
        else 
        root = root->left;
    }
    return false;
}
Node *insert(Node*root,int x){
    if(root ==NULL)
    return new Node(x);
    else if (root->key<x)
    root->right = insert(root->right,x);
    else if (root->key>x)
    root->left = insert(root->left,x);
    return root;
}
Node*insert(Node*root, int x){
    Node*temp  = new Node (x);
    Node*parent = NULL,*curr = root;
    
    while(curr!=NULL){ 
        parent = curr;
        if(curr->key>x)
        curr = curr->left;
        else if(curr->key< x)
        curr = curr->right;
        else 
        return root;
    }
    if(parent ==NULL) return temp;
    if(parent->key<x)
    parent->right = temp;
    else parent->left =temp;
    return root;
}
