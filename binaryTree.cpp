#include <iostream>
using namespace std;

string isBal = "YES";

struct Node
{
    int x;
    Node *l,*r;
};

int getHeight(Node *&Tree, int depth, int maxDepth)
{
    if (Tree!=NULL)
    {
        maxDepth = max(depth, maxDepth);
        maxDepth = max(maxDepth, getHeight(Tree->l, depth + 1, maxDepth));
        maxDepth = max(depth, maxDepth);
        maxDepth = max(maxDepth, getHeight(Tree->r, depth + 1, maxDepth));
        return maxDepth;
    }
    else{
        return 0;
    }
}

void add_node(int x,Node *&MyTree)
{
    if (NULL==MyTree)
    {
        MyTree=new Node;
        MyTree->x=x;
        MyTree->l=MyTree->r=NULL;
    }

    if (x<MyTree->x)
    {
        if (MyTree->l!=NULL) add_node(x,MyTree->l);
        else
        {
            MyTree->l=new Node;
            MyTree->l->l=MyTree->l->r=NULL;
            MyTree->l->x=x;
        }
    }

    if (x>MyTree->x)
    {
        if (MyTree->r!=NULL) add_node(x,MyTree->r);
        else
        {
            MyTree->r=new Node;
            MyTree->r->l=MyTree->r->r=NULL;
            MyTree->r->x=x;
        }
    }
}

void check(Node *&Tree)
{
    if (Tree!=NULL)
    {
        if ((abs(getHeight(Tree->r, 1, 1) - getHeight(Tree->l, 1, 1))) > 1)
            isBal = "NO";
        check(Tree->l);
        check(Tree->r);
    }
}
