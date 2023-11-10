#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* left, *right;
}node;
node* createnode(int key){
    node* newnode = (node*)malloc(sizeof(node));
    newnode -> data = key;
    newnode -> left = newnode -> right = NULL;
    
    return newnode;
}
node* insertnode(node* root, int key){
    if(root == NULL)
        return createnode(key);

    if(key < root -> data)
        root -> left = insertnode(root -> left, key);
    else if(key > root -> data)
        root -> right = insertnode(root -> right, key);

    return root;
}
void preorder(node* root){
    if(root!=NULL)
    {
        printf("| %d | -> ",root -> data);
        preorder(root -> left);
        preorder(root -> right);
    }
}
void inorder(node* root){
     if(root!=NULL){
    inorder(root -> left);
    printf("| %d | -> ",root -> data);
    inorder(root -> right);
     }
}
void postorder(node* root){
     if(root!=NULL){
    postorder(root -> left);
    postorder(root -> right);
    printf("| %d | -> ",root -> data);
     }
}
node* search(node* root, int s){
    if(root == NULL)
        return NULL;

    if(root -> data==s)
        return root;
    else if(root -> data < s)
        return search(root -> right, s);
    else
        return search(root -> left, s);
}
void min(node* root){
    while(root!=NULL&&root -> left!=NULL){
        root = root -> left;
    }
    printf("The minimum value:| %d |",root -> data);
}
void max(node* root){
    while(root!=NULL&&root -> right!=NULL){
        root = root -> right;
    }
    printf("The maximum value:| %d |",root -> data);
}
int height(node* root){
    if(root == NULL)
        return 0;
    else{
        int lh = height(root -> left);
        int rh = height(root -> right);
    if(lh > rh)
        return lh+1;
    else
        return rh+1;
    }
}
int main(){
    node* root = NULL;
    int k,c,s;
    
    while(1){
        printf("\n========================\n");
        printf("======= BST MENU =======\n");
        printf("========================\n");
        printf("1.Insert a newnode\n");
        printf("2.Display \n");
        printf("3.Display preorder\n");
        printf("4.Display inorder\n");
        printf("5.Display postorder\n");
        printf("6.Search\n");
        printf("7.Minimum value\n");
        printf("8.Maximum value\n");
        printf("9.Height\n");
        printf("10.Exit\n");
        printf("========================\n");
        
        printf("\nEnter the choice:");
        scanf("%d",&c);
        
        switch(c){
            case 1:
                printf("\nEnter the data in to the node:");
                scanf("%d",&k);
                root = insertnode(root, k);
                break;
            case 2:
                printf("\npreorder:");
                preorder(root);
                printf("NULL\n");
                printf("\ninorder:");
                inorder(root);
                printf("NULL\n");
                printf("\npostorder:");
                postorder(root);
                printf("NULL\n");
                break;
            case 3:
                printf("\npreorder:");
                preorder(root);
                break;
            case 4:
                printf("\ninorder:");
                inorder(root);
                break;
            case 5:
                printf("\npostorder:");
                postorder(root);
                break;
            case 6:
                printf("\nEnter the data to search:");
                scanf("%d",&s);
                if(search(root, s)!=NULL)
                    printf("\nThe element is found...");
                else
                    printf("\nThe element is not found...");
                break;
            case 7:
                min(root);
                break;
            case 8:
                max(root);
                break;
            case 9:
                printf("\nThe height of the BST: %d",height(root));
                break;
            case 10:
                printf("The program has been exited .............");
                exit(0);
            default:
                printf("The choice has been out of boundaries ....................\n");
                printf("Please try again ....................\n");
        }
    }
}
