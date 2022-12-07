#include <stdio.h>
#include <stdlib.h>

struct tree_node
{
    int data;
    struct tree_node *parent;
    struct tree_node *left;
    struct tree_node *right;
};

struct tree_node *root; // root node

struct tree_node *create_node(int data)
{
    struct tree_node *new_node = (struct tree_node *)malloc(sizeof(struct tree_node));
    new_node->data = data;
    new_node->parent = NULL;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct tree_node *insertLeftNode(struct tree_node *root, int value)
{
    root->left = insertNode(value);
    root->left->parent = root;
    return root->left;
}

struct tree_node *insertRightNode(struct tree_node *root, int value)
{
    root->right = insertNode(value);
    root->right->parent = root;
    return root->right;
}

struct tree_node *insertNode()
{
    int value;
    scanf("%d", &value);
    if (root == NULL)
    {
        root = insertNode(value);
        return root;
    }
    else
    {
        struct tree_node *temp = root;
        while (temp != NULL)
        {
            if (value < temp->data)
            {
                if (temp->left == NULL)
                {
                    return insertLeftNode(temp, value);
                }
                else
                {
                    temp = temp->left;
                }
            }
            else
            {
                if (temp->right == NULL)
                {
                    return insertRightNode(temp, value);
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }
}

void transplantTree (struct tree_node *u, struct tree_node *v)
{
    if (u->parent == NULL)
    {
        root = v;
    }
    else if (u == u->parent->left)
    {
        u->parent->left = v;
    }
    else
    {
        u->parent->right = v;
    }
    if (v != NULL)
    {
        v->parent = u->parent;
    }
}

void deleteTree()
{
    if (root != NULL)
    {
        deleteTree(root->left);
        deleteTree(root->right);
        free(root);
    }
}

void inorder_traversal()
{
    if (root != NULL)
    {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

void preorder_traversal()
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

void postorder_traversal()
{
    if (root != NULL)
    {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d ", root->data);
    }
}

void searchTree(){
    int value;
    printf("Enter the value to be searched: ");
    scanf("%d", &value);
    if (root == NULL){
        printf("\nValue not found");
    }
    else{
        struct tree_node *temp = root;
        while (temp != NULL){
            if (value < temp->data){
                temp = temp->left;
            }
            else if (value > temp->data){
                temp = temp->right;
            }
            else{
                printf("\nValue found");
                return;
            }
        }
        printf("\nValue not found");
    }
}

void main(){
    int value;
    int choice;
    int popped;
    while (1)
    {
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                insertNode();
                break;
            case 2:
                deleteTree();
                break;
            case 3:
                inorder_traversal();
                printf("\n");
                preorder_traversal();
                printf("\n");
                postorder_traversal();
                printf("\n");
                break;
            case 4:
                searchTree();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice");
                break;
        }
    }
}