#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*left;
    struct node*right;
};
void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
struct node *search(struct node *root,int data)
{
    if(root==NULL)
    return NULL;
    else if(root->data==data)
    return root;
    else if(data<root->data)
    return search(root->left,data);
    else
    return search(root->right,data);
}
struct node *create(int data)
{
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->left=NULL;
    ptr->right=NULL;
    return ptr;
}
struct node *insert(struct node *root,int data)
{
    if(root==NULL)
    root=create(data);
    else if(data<root->data)
    root->left=insert(root->left,data);
    else
    root->right=insert(root->right,data);
    return root;
}
struct node *inorderpredecessor(struct node *root)
{
    root=root->left;
    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root;
}

struct node *delete(struct node *root,int data)
{
    struct node *iPre;
    if(root==NULL)
    return NULL;
    if(root->left==NULL &&root->right==NULL)
    {
        free(root);
        return NULL;
    }
    if(data<root->data)
    root->left=delete(root->left,data);
    else if(data>root->data)
    root->right=delete(root->right,data);
    else
    {
        iPre=inorderpredecessor(root);
        root->data=iPre->data;
        root->left=delete(root->left,iPre->data);
    }
    return root;
}
void main()
{
    struct node *root=NULL;
    int k,data;
    do
    {
        printf("\n1.insert\t2.delete\t3.display\t4.search\t5.exit");
        printf("\nEnter Choice\n");
        scanf("%d",&k);
        switch(k)
        {
            case 1: printf("\nEnter data\t");
                    scanf("%d",&data);
                    root=insert(root,data);
                    break;
            case 2: printf("\nEnter data to be deleted\n");
                    scanf("%d",&data);
                    root=delete(root,data);
                    break;
            case 3: inorder(root);
                    break;
            case 4: {printf("\nEnter data to be searched:\t");
                    scanf("%d",&data);
                    struct node *m=search(root,data);
                    if(m!=NULL)
                    printf("\nElement %d Found\n",m->data);
                    else
                    printf("\nElement Not Found\n");}
                    break;
            case 5: exit(0);
            default:printf("Wrong Choice");
        }
    }while(1);
}