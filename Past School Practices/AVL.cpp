#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node* left;
    Node* right;
    int height; //including itself, so the height will always be max of height child + 1
};

void printPre(Node* head)
{
    if (head == NULL)
    {
        return;
    }
    else
    {
        cout << head->value << "(";
        printPre(head->left);
        cout << ")(";
        printPre(head->right);
        cout << ")";
    }
}

void printIn(Node* head)
{
    if (head == NULL)
    {
        return;
    }
    else
    {
        cout << "(";
        printIn(head->left);
        cout << ")" << head->value << "(";
        printIn(head->right);
        cout << ")";
    }
}

void printPost(Node* head)
{
    if (head == NULL)
    {
        return;
    }
    else
    {
        cout << "(";
        printPost(head->left);
        cout << ")(";
        printPost(head->right);
        cout << ")" << head->value;
    }
}

int maxVal(int a, int b)
{
    if (a >= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int height(Node* head)
{
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        return head->height;
    }
}

int balanceNum(Node* head)
{
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        return height(head->left) - height(head->right);
    }
}

Node* rotatingRight(Node* head)
{
    Node* newHead = head->left;
    head->left = newHead->right; //place the right to the left of the head, since we will overwrite the right after this
    newHead->right = head;

    //remember to update the heights of the head and newHead
    head->height = max(height(head->right), height(head->left)) + 1;
    newHead->height = max(height(newHead->right), height(newHead->left)) + 1;
    
    //only return the root, because data on the head will be updated by reference, we just need to update
    //where the root points to
    return newHead;
}

Node* rotatingLeft(Node* head)
{
    Node* newHead = head->right;
    head->right = newHead->left; //pass the left, since we are going to overwrite it with head
    newHead->left = head;

    //update the heights
    head->height = max(height(head->right), height(head->left)) + 1;
    newHead->height = max(height(newHead->right), height(newHead->left)) + 1;

    //only return the root, because data on the head will be updated by reference, we just need to update
    //where the root points to
    return newHead;
}

void insertion(Node* &head, Node* insertNode)
{
    if (head == NULL)
    {
        head = insertNode;
        return;
    }
    else
    {
        if (insertNode->value > head->value)
        {
            insertion(head->right, insertNode);
        }
        else
        {
            insertion(head->left, insertNode);
        }
    }

    //count the height of itself, the recursion cant stop unlike in wikipedia, because we
    //must update all heights
    head->height = 1 + maxVal(height(head->left), height(head->right));
    //the height is not that similar with in theory, as an example if
    //the height of a child may be 1, then parents 3, this is because parents
    //use maxval when counting the height

    int curBFactor = balanceNum(head);

    //see if there is an irregular case where any of the four rotations needed
    //dont need to be afraid if insertNode == head-> left or insertNode == head->right, since it must be
    //the curBFactor still around 1 or -1
    if (curBFactor > 1 && (insertNode->value <= head-> left->value))
    {
        //cout << "enter here: value = " << head->value << endl;
        //cout << "head->height = " << head->height << endl;
        //left left, do right rotation once is enough
        head = rotatingRight(head);
        //cout << "enter here: new value = " << head->value << endl;
        //cout << "head->height = " << head->height << endl;
    }
    else if (curBFactor > 1 && (insertNode->value > head->left->value))
    {
        // left right, the child does left rotation first, then the parents does right
        head->left = rotatingLeft(head->left);
        head = rotatingRight(head);
    }
    else if (curBFactor < -1 && (insertNode->value > head->right->value))
    {
        //right right, left rotation once is enough
        head = rotatingLeft(head);
    }
    else if (curBFactor < -1 && (insertNode->value <= head->right->value))
    {
        // right left, the child does right rotation first, then the parents does left
        head->right = rotatingRight(head->right);
        head = rotatingLeft(head);
    }
}

void deleteNode(Node*& head, int curVal)
{
    //recursive method, search through the tree
    if (head == NULL)
    {
        //items doesn't exist, just in case
        return;
    }
    if (curVal < head->value)
    {
        //noneed to be afraid head->left is error, since it always guarantee that curVal exist in tree
        deleteNode(head->left, curVal);
    }
    else if (curVal > head->value)
    {
        deleteNode(head->right, curVal);
    }
    else
    {
        //delete this node, but check how many child it has
        if (head->right == NULL || head->left == NULL)
        {
            //it is easy because we can do direct substitution to the node below
            Node* replacement = NULL;
            if (head->right != NULL)
            {
                replacement = head->right;
            }
            else if (head->left != NULL)
            {
                replacement = head->left;
            }

            //direct substitution to the below.
            if (replacement == NULL)
            {
                replacement = head;
                head = NULL;
            }
            else
            {
                *head = *replacement;
            }
            delete replacement;
        }
        else
        {
            //two child node, find first the largest node on the left of the subtree
            Node* biggest = head->left;
            while (biggest->right != NULL)
            {
                biggest = biggest->right;
            }
            //replace the value of this node with the value
            head->value = biggest->value;
            //now proceed erasing the biggest value
            deleteNode(head->left, biggest->value); // no need to free, it will enter the previous subcase
        }
    }

    if (head == NULL)
    {
        // no need to proceed
        return;
    }
    else
    {
        //update the height
        head->height = max(height(head->left), height(head->right)) + 1;

        int bFactor = balanceNum(head);

        if (bFactor > 1)
        {
            //uneven on the left
            //test the balance factor of the left child
            int childBalance = balanceNum(head->left);
            if (childBalance < 0)
            {
                //this is because if we just do regular right rotate only, the right subtree will be the
                //one that is uneven
                //for zero, we can do both, but we take the easier one, which is left left
                head->left = rotatingLeft(head->left);
            }
            head = rotatingRight(head);
        }
        else if (bFactor < -1)
        {
            //uneven on the right, test the balance factor of the right
            int childBalance = balanceNum(head->right);
            if (childBalance > 0)
            {
                //this is because if we just do regular right rotate only, the left subtree will be the
                //one that is uneven
                //for zero, we can do both, but we take the easier one, which is right right
                head->right = rotatingRight(head->right);
            }
            head = rotatingLeft(head);
        }
    }
}

//create a function for insertion, deletion, and print preorder, inorder,postorder
int main()
{
    int nodesNumber;
    Node* head = NULL;
    cin >> nodesNumber;
    
    for (int i = 0; i < nodesNumber; i++)
    {
        int curVal;
        Node* newNode = new Node;
        cin >> curVal;
        newNode->value = curVal;
        newNode->right = NULL;
        newNode->left = NULL;
        newNode->height = 1;
        insertion(head, newNode);
    }
    char command;
    while (cin >> command)
    {
        if (command == 'I')
        {
            int curVal;
            Node* newNode = new Node;
            cin >> curVal;
            newNode->value = curVal;
            newNode->right = NULL;
            newNode->left = NULL;
            newNode->height = 1;
            insertion(head, newNode);
        }
        else if (command == 'D')
        {
            int curVal;
            cin >> curVal;
            deleteNode(head, curVal);
        }
        else if (command == 'P')
        {
            int printType;
            cin >> printType;
            if (printType == 1)
            {
                printPre(head);
                cout << "\n";
            }
            else if (printType == 2)
            {
                printIn(head);
                cout << "\n";
            }
            else
            {
                printPost(head);
                cout << "\n";
            }
        }
    }
}