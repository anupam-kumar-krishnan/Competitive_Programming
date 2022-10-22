
#include <stdio.h>//Header file for input and output
#include <stdlib.h>
// Here structure is created with a name tree
struct tree
{
    int info;// It will represent the info part of tree which is of integer type
    struct tree *left;  // It is a ponter of type struct which will point left tree
    unsigned int rthread : 1;// This is bitfield
    struct tree *right; // It is a ponter of type struct which will point right tree
};

struct tree *root = NULL;
struct tree *insertelement(struct tree *root, int item);
struct tree *createbst(struct tree *root);
void inorderbst(struct tree *root);

static int item;

int main()
{
    int choice;
    printf("\n ** C Program to Implement One Way Right Threaded Bst and its Traversal **\n");
    do
    {
        printf("\n---- Main Menu -----\n");
        printf("1.To Create One-Way Right-Threaded BST\n");
        printf("2.To Inorder Traversed The One-Way Right-Threaded BST\n");
        printf("3.To Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            root = createbst(root);
            printf("** One Way Right Threaded BST created successfully **\n");
            break;
        case 2:
            printf("\nIn-Order Traversal is :\n");
            inorderbst(root);
            printf("**In-Order Traversal Done Successfully**\n");
            break;
        case 3:
            exit(0);
            break;
        }
    } while (choice <= 2);
    return 0;
}

struct tree *createbst(struct tree *root)
{
    int x;
    do
    {
        printf("Enter Data items:\n");
        scanf("%d", &item);
        root = insertelement(root, item);
        printf("press 1 to continue or any other number to stop\n");
        scanf("%d", &x);
    } while (x == 1);
    return root;
}
struct tree *insertelement(struct tree *root, int item)
{
    struct tree *newnode, *par, *save;
    newnode = (struct tree *)malloc(sizeof(struct tree));
    if (newnode == NULL)
    {
        printf("Overflow\n");
        exit(0);
    }
    newnode->info = item;
    newnode->left = NULL;
    newnode->rthread = 1;
    if (root == NULL)
    {
        root = newnode;
        newnode->right = NULL;
        newnode->rthread = 0;
        return root;
    }

    par = NULL;
    save = root;
    while (save != NULL)
    {
        par = save;
        if (item < save->info)
        {
            save = save->left;
        }
        else
        {
            if (save->rthread == 1)
            {
                save = NULL;
            }
            else
            {
                save = save->right;
            }
        }
    }
    if (item < par->info)
    {
        par->left = newnode;
        newnode->right = par;
        newnode->rthread = 1;
    }
    else
    {
        if (par->rthread == 1)
        {
            par->rthread = 0;
            newnode->rthread = 1;
            newnode->right = par->right;
            par->right = newnode;
        }
        else
        {
            newnode->rthread = 0;
            newnode->right = NULL;
            par->right = newnode;
        }
    }
    return root;
}

void inorderbst(struct tree *root)
{
    struct tree *save, *par;
    save = root;
    do
    {
        par = NULL;
        while (save != NULL)
        {
            par = save;
            save = save->left;
        }
        if (par != NULL)
        {
            printf("%d\n", par->info);
            save = par->right;
            while (par->rthread == 1 && save != NULL)
            {
                printf("%d\n", save->info);
                par = save;
                save = save->right;
            }
        }
    } while (save != NULL);
}