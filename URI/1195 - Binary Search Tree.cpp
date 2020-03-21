#include<bits/stdc++.h>
using namespace std;

struct node
{
    long data;
    struct node *left, *right;
} A, *head = NULL;

void insert(long a)
{
    struct node *bb = head;
    while(1)
    {
        if(bb == NULL)
        {
            head = (struct node*) malloc(sizeof(struct node));
            head->data = a;     head->left = NULL;     head->right = NULL;
            break;
        }
        else
        {
            if(bb->data > a)
            {
                if(bb->left == NULL)
                {
                    bb->left = (struct node*) malloc(sizeof(struct node));
                    bb->left->data = a;     bb->left->left = NULL;      bb->left->right = NULL;
                    break;
                }
                else bb = bb->left;
            }
            else
            {
                if(bb->right == NULL)
                {
                    bb->right = (struct node*) malloc(sizeof(struct node));
                    bb->right->data = a;    bb->right->left = NULL;     bb->right->right = NULL;
                    break;
                }
                else bb = bb->right;
            }
        }
    }
}

void search(long a)
{
    struct node *aa = head;
    while(aa != NULL)
    {
        if(aa -> data == a)
        {
            printf("Found\n");
            break;
        }
        else if(aa -> data > a)
        {
            aa = aa -> left;
            //printf("L\n");
        }
        else
        {
            aa = aa -> right;
            //printf("R\n");
        }
    }
    if(aa == NULL) printf("Not found\n");
}

long minNode(struct node *a)
{
    while(a && a->left != NULL)
        a = a->left;
    return a->data;
}

struct node* del(struct node *a, long val)
{
    if(a == NULL) return NULL;

    if(a->data > val) 
    { 
        a->left = del(a->left, val); 
        return a; 
    }
    else if(a->data < val) 
    { 
        a->right = del(a->right, val); 
        return a; 
    }
    else
    {
        if(a->left == NULL && a->right == NULL)
        {
            free(a); return NULL;
        }
        else if(a->left == NULL)
        {
            free(a); return a->right;
        }
        else if(a->right == NULL) 
        { 
            free(a); return a->left;
        }
        else
        {
            long num = minNode(a->right);
            a->data = num;
            a->right = del(a->right, num);
            return a;    
        }
    }
}

void preOrder(struct node *a)
{
    if(a==NULL) return;

    printf(" %ld", a->data);
    preOrder(a->left);
    preOrder(a->right);
}

void inOrder(struct node *a)
{
    if(a==NULL) return;

    inOrder(a->left);
    printf(" %ld", a->data);
    inOrder(a->right);
}

void postOrder(struct node *a)
{
    if(a==NULL) return;

    postOrder(a->left);
    postOrder(a->right);
    printf(" %ld", a->data);
}

void delAll(struct node *a)
{
    if(a==NULL) return;
    delAll(a->left);
    delAll(a->right);
    free(a);
}

int main()
{
    long loop, test, a, b, c;
    scanf("%ld", &test);
    for(loop=1 ; loop<=test ; loop++)
    {
        scanf("%ld", &a);
        while (a--)
        {
            scanf("%ld", &b);
            insert(b);
        }

        printf("Case %ld:\n", loop);

        printf("Pre.:");
        preOrder(head);
        printf("\n");

        printf("In..:");
        inOrder(head);
        printf("\n");

        printf("Post:");
        postOrder(head);
        printf("\n");

        printf("\n");

        delAll(head);
        head=NULL;
    }
    return 0;
}