#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
    struct node *p;
};

typedef struct node *node;

struct tree
{
    node root;
};

typedef struct tree *tree;

struct node2
{
    char data;
    struct node2 *next;
};

typedef struct node2 *node2;

struct stack
{
    node2 top;
};

typedef struct stack *stack;

node CREATENODE(int k)
{
    node selected;
    selected=(node)malloc(sizeof(struct node));
    if(selected==NULL)
    {
        exit(0);
    }
    selected->key=k;
    selected->left=NULL;
    selected->right=NULL;
    selected->p=NULL;
    return selected;
}

node2 CREATENODE2(char k)
{
    node2 selected;
    selected=(node2)malloc(sizeof(struct node2));
    if(selected==NULL)
    {
        exit(0);
    }
    selected->data=k;
    selected->next=NULL;
    return selected--;
}

void PUSH(stack S, char k)
{
    node2 x=CREATENODE2(k);
    if(S->top==NULL)
    {
        S->top=x;
    }
    else
    {
        x->next=S->top;
        S->top=x;
    }
}

char POP(stack S)
{
    if(S->top==NULL)
    {
        return 0;
    }
    else
    {
        int x=S->top->data;
        S->top=S->top->next;
        return x;
    }
}

int indexx(char e[], int a, int b)
{
    stack S;
    S=(stack)malloc(sizeof(struct stack));
    S->top=NULL;
    if(a>b)
    {
        return 0;
    }
    for(int i=a;i<b;i++)
    {
        if(e[i]=='(')
        {
            PUSH(S,e[i]);
        }
        else if(e[i]==')')
        {
            if(S->top->data=='(')
            {
                POP(S);
                if(S->top==NULL)
                {
                return i;
               }
            }
        }
    }
    return -1;
}

void PRINT(node x)
{
    if(x!=NULL)
    {
        PRINT(x->left);
        PRINT(x->right);
        printf("%d ",x->key);
    }
}

node BUILDTREE(char a[])
{
    char g[1000];
    char h[1000];
    int i;
    int data=0;
    if(a[2]==')')
    {
        return NULL;
    }
    if(a[2]=='-')
    {
        for(i=3;a[i]!=' ';i++)
        {  
          int b=a[i]-'0';
          data=data*10+b;      
        }
        data=data*-1;
    }
    else
    {
        for(i=2;a[i]!=' ';i++)
        {  
           int b=a[i]-'0';
           data=data*10+b;      
        }
    }
    node node=CREATENODE(data);
   
    int c=strlen(a)-1;
   
    int f=indexx(a,i+1,c);
   
    int count=0;

    for(int j=i+1;j<=f;j++)
    {
        g[count]=a[j];
        count++;
    }
   
    node->left=BUILDTREE(g);

    int l=indexx(a,f+2,c);

    for(int j=f+2;j<=l;j++)
    {
        h[j-(f+2)]=a[j];
    }

    node->right=BUILDTREE(h);
    return node;
}
node SEARCH(node x,int k)
{
    node y=x;
    if(x!=NULL)
    {
        if(x->key==k)
        {
            return x;
        }
        y=SEARCH(x->left,k);
        if(y==NULL)
        {
            y=SEARCH(x->right,k);
        }
    }
    return y;
}
void FIND_DESCENDANT(node t,int k)
{
if(t==NULL || k<0)
return;
if(k==0)
{
printf("%d ",t->key);
return;
}
FIND_DESCENDANT(t->left,k-1);
FIND_DESCENDANT(t->right,k-1);
}


int main()
{
    tree T=(tree)malloc(sizeof(struct tree));
    T->root=NULL;
    int x;
   
    int k;
    char e[1000];
    fgets(e,1000,stdin);
    scanf ("%d",&x);
    scanf("%d",&k);
    T->root=BUILDTREE(e);
   
    node n=SEARCH(T->root,x);
   
    FIND_DESCENDANT(n,k);
   
   
}