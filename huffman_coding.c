#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int info;
    char alpha;
    struct node *next;
    struct node *left;
    struct node *right;
};
struct node *getnode(int info,char alpha)
{
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    p->info=info;
    p->alpha=alpha;
    p->next=NULL;
    p->left=NULL;
    p->right=NULL;
    return p;
};
void insertion(struct node **start,struct node *n)
{
    struct node *q=NULL,*p;
    p=*start;
    while(p!=NULL && p->info <= n->info)
    {
        q=p;
        p=p->next;
    }
    if(q==NULL)
    {
        n->next=*start;
        *start=n;
        return;
    }
    n->next=q->next;
    q->next=n;
}
struct node *combine(struct node *p,struct node *q)
{
    struct node *n;
    n=getnode(p->info + q->info,' ');
    p->next=NULL;
    q->next=NULL;
    n->left=p;
    n->right=q;
    return n;
};
struct node *extract_min(struct node **start)
{
    struct node *p;
    p=*start;
    *start=p->next;
    return p;
}
int present(char *temp,int t,char w)
{
    int i;
    for(i=0;i<t;i++)
        if(temp[i]==w)
        return i+1;
    return 0;
}
void swapint(int *a,int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
void swapchar(char *a,char *b)
{
    char t;
    t=*a;
    *a=*b;
    *b=t;
}
void sort(char *temp,int *count,int t)
{
    int i,j;
    for(i=0;i<t;i++)
    {
        for(j=0;j<i;j++)
        {
            if(count[j]>count[i])
            {
                swapint(&count[j],&count[i]);
                swapchar(&temp[j],&temp[i]);
            }
        }
    }
}
void inorder(struct node *tree)
{
    if(tree!=NULL)
    {
        inorder(tree->left);
        printf("  %d  ",tree->info);
        inorder(tree->right);
    }
}
int isleaf(struct node *p)
{
    if(p->left==NULL && p->right==NULL)
        return 1;
    return 0;
}
void codes(struct node *queue,int *ans,int as)
{
    int i;
    if(queue->left==NULL)
    {
        printf("\n\t\t\t %c  :  ",queue->alpha);
        for(i=0;i<as;i++)
            printf("%d",ans[i]);
    }
    else
    {
        ans[as++]=0;
        codes(queue->left,ans,as);
        ans[as-1]=1;
        codes(queue->right,ans,as);
    }
}
void huffman(char *arr)
{
    int len,t=0,var,i;
    len=strlen(arr);
    char temp[500];
    int count[500];
    for(i=0;i<len;i++)
    {
        var=present(temp,t,arr[i]);
        if(!var)
        {
            temp[t]=arr[i];
            count[t++]=1;
        }
        else
            count[var-1]++;
    }
    sort(temp,count,t);
    //for(i=0;i<t;i++)
      //  printf("\t\t\t %c  %d\n",temp[i],count[i]);
    struct node *queue=NULL,*p,*q;
    for(i=0;i<t;i++)
        insertion(&queue,getnode(count[i],temp[i]));
    while(queue->next!=NULL)
    {
        p=extract_min(&queue);
        q=extract_min(&queue);
        insertion(&queue,combine(p,q));
    }
  //  printf("\n\t\t\t %d \n\n",queue->info);
    int ans[500],as=0;
    //inorder(queue);
    printf("\n\t\t\tword  :  codes\n");
    codes(queue,ans,as);
}
int main()
{
    char arr[1000];
    printf("\t\t\tenter message : ");
    scanf("%s",arr);
    huffman(arr);
    return 0;
}
