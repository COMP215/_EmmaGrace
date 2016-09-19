#include <iostream>
#include <stack>
#include <time.h>
#include <stdlib.h>

using namespace std;

const short kNodes = 10;
const short kMod = 20;
const short kAdd = 1;

class node
{
    public:
        node();
        node(short);
        short data;
        node* leftNode;
        node* rightNode;
};

node::node()
{
    leftNode = NULL;
    rightNode = NULL;
    data = 0;
}

node::node(short input)
{
    leftNode = NULL;
    rightNode = NULL;
    data = input;
}

class tree
{
    public:
        tree();
        node* root;
        void AddNode(node*);
        stack<short> InOrder(node*);

    private:
        stack<short> S;
};

int main()
{
    tree T;
    short num;
    stack<short> ordered;

    srand((unsigned)time(NULL));

    T.root->data = 5;
    node N(3);
    T.AddNode(&N);

    node M(2);
    T.AddNode(&M);

    node O(4);
    T.AddNode(&O);

    /*
    T.root->data = rand()%kMod + kAdd;

    num = rand()%kMod + kAdd;
    node N(num);
    T.AddNode(&N);
    */

    /*
    for (short i = 0; i < kNodes; i++)
    {
        num = rand()%kMod + kAdd;
        node N(num);
        T.AddNode(&N);
    }
    */

    stack<short> temp = T.InOrder(T.root);
    while (!temp.empty())
    {
        ordered.push(temp.top());
        temp.pop();
    }

    while(!ordered.empty())
    {
        cout << ordered.top() << " ";
        ordered.pop();
    }

    return 0;
}

tree::tree()
{
    root = new node;
}

void tree::AddNode(node* new_node)
{
    bool placed = false;
    node* current = root;

    while (!placed)
    {
        if (new_node->data < current->data)
        {
            if (current->leftNode == NULL)
            {
                current->leftNode = new_node;
                placed = true;
            }

            else
            {
                current = current->leftNode;
            }
        }

        else if (new_node->data > current->data)
        {
            if (current->rightNode == NULL)
            {
                current->rightNode = new_node;
                placed = true;
            }

            else
            {
                current = current->rightNode;
            }
        }

        else
        {
            placed = true;
        }
    }
}

stack<short> tree::InOrder(node* current)
{
    if (current->leftNode != 0)
        InOrder(current->leftNode);

    S.push(current->data);

    if (current->rightNode != 0)
        InOrder(current->rightNode);

    return S;
}
