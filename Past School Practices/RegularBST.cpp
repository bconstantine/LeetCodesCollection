#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node* left;
    Node* right;
    int leastBelow; //sum right including the variable
    int leastNumber; //number of nodes on the right
    int mostBelow; //sum left including the variable
    int mostNumber; //number of nodes on the left
};

void printAll(Node* head)
{
    if (head == NULL)
    {
        return;
    }
    else
    {
        cout << head->value << "(";
        printAll(head->left);
        cout << ")(";
        printAll(head->right);
        cout << ")";
    }
}

int MCount(Node* head, int threshold, int prevValue = 0)
{
    Node* roaming = head;
    Node* previousNode = NULL;
    bool edgeReached = false;
    int subtotal = head->leastBelow + prevValue;
    //cout << "Subtotal = " << subtotal << endl;
    int nodesNumber = head->leastNumber;
    bool enterOnce = false;


    //cout << "curnode value: " << roaming->value << endl;
    //as long as the num
    while (subtotal < threshold)
    {
        if (roaming->left != NULL)
        {
            enterOnce = true;
            previousNode = roaming;
            roaming = roaming->left;
           // cout << "curnode value0: " << roaming->value << endl;
            subtotal += roaming->leastBelow;
           // cout << "subtotalnow: " << subtotal << endl;
            nodesNumber += roaming->leastNumber;
            //cout << "nodesnow: " << nodesNumber << endl;
        }
        else
        {
            edgeReached = true;
            break;
        }
    }
    //cout << "break, current subtotal : " << subtotal << endl;
    //cout << "break, current nodes number : " << nodesNumber << endl;
    if (edgeReached)
    {
        return nodesNumber;
    }
    else if (subtotal == threshold)
    {
        return nodesNumber;
    }
    else if (roaming->right == NULL && roaming->left == NULL)
    {
       // cout << "Enter here!\n";
        if (subtotal - roaming->value >= threshold)
        {
            return (nodesNumber - 1);
        }
        else
        {
            return nodesNumber;
        }
    }
    else
    {
        //subtotal is now bigger than threshold
        int previousAnswer = nodesNumber;
        //try to traverse the rightt branch
        //cout << "subtotal before: " << subtotal << endl;
        //since too much, the root must be removed
        subtotal -= roaming->value;
        //cout << "subtotal after: " << subtotal << endl;
        nodesNumber -= 1;

        //while still fulfills, keep on removing the nodes


        if (subtotal > threshold)
        {
            Node* anotherPrev = NULL;
            edgeReached = false;
            enterOnce = false;
            //keep on removing until it is still valid
            while (subtotal > threshold)
            {
                if (roaming->right != NULL)
                {
                    enterOnce = true;
                    anotherPrev = roaming;
                    roaming = roaming->right;
                    subtotal -= roaming->mostBelow;
                    nodesNumber -= roaming->mostNumber;
                    //cout << "curnode value1: " << roaming->value << endl;
                   // cout << "subtotal1: " << subtotal << endl;
                    //cout << "nodesnumber1: " << nodesNumber << endl;
                }
                else
                {
                    //cout << "Edge reached!\n";
                    edgeReached = true;
                    break;
                }
            }

            if (edgeReached)
            {
                return nodesNumber;
            }
            else if (subtotal == threshold)
            {
                return nodesNumber;
            }
            else
            {
                

                //Editted
                //check for the possibility of the value still be reduced on the ground
                if (roaming->left != NULL && subtotal < threshold)
                {
                    //cout << "Enter here2!\n";
                    int restoreValue = subtotal + roaming->mostBelow; //this is the last limit for elimination
                    int restoreNodes = nodesNumber;
                    Node* leftest = roaming->left;
                    while (leftest->left != NULL)
                    {
                        leftest = leftest->left;
                    }

                    restoreValue -= leftest->value;
                    //cout << "Restore value: " << restoreValue << endl;
                    if (restoreValue > threshold)
                    {
                        //restore value may still do elimination, proceed
                        //top will no wonder be included
                        restoreValue = subtotal + roaming->value;
                        restoreNodes += 1;
                        //cout << "Restore nodes = " << restoreNodes << endl;
                        //cout << "Mcount result: " << MCount(roaming->left, threshold, restoreValue) << endl;
                        restoreNodes += MCount(roaming->left, threshold, restoreValue);
                        //cout << "Mistake here!\n";
                        return restoreNodes;
                    }
                    else if (restoreValue == threshold)
                    {
                        return (restoreNodes+roaming->mostNumber-1);
                    }
                    else
                    {

                        //not possible, return the previous value
                        return restoreNodes + roaming->mostNumber;
                    }
                }
                else
                {
                    //if subtotal + roaming < threshold
                    if (subtotal < threshold)
                    {
                        return nodesNumber + roaming->mostNumber;
                    }
                    else
                    {
                        return nodesNumber;
                    }
                }
            }
            
        }
        else if(subtotal < threshold)
        {
            return previousAnswer;
        }
        else
        {
            return nodesNumber; 
        }
    }
    //return nodesNumber; //lolos
}

int LCount(Node* head, int threshold, int prevValue = 0)
{
    Node* roaming = head;
    Node* previousNode = NULL;
    bool edgeReached = false;
    int subtotal = head->mostBelow + prevValue;;
    int nodesNumber = head->mostNumber;
    bool enterOnce = false;
    //cout << "Current node: " << roaming->value << endl;
    while (subtotal < threshold)
    {
        if (roaming->right != NULL)
        {
            enterOnce = true;
            previousNode = roaming;
            roaming = roaming->right;
            //cout << "Current node0: " << roaming->value << endl;
            subtotal += roaming->mostBelow;
            nodesNumber += roaming->mostNumber;
        }
        else
        {
            edgeReached = true;
            break;
        }
    }
    if (subtotal == threshold)
    {
        return nodesNumber;
    }
    else if (edgeReached)
    {
        // still fulfills, but has reached the edge, then no need to erase anything
        return nodesNumber;
    }
    else
    {
        int previousNodesNumber = nodesNumber - roaming->mostNumber;
        //subtotal is now greater than threshold, keep previous fit, if not found, then answer is in previous fit
        subtotal -= roaming->value;
        nodesNumber -= 1;
        Node* anotherPrev = NULL;
        edgeReached = false;
        enterOnce = false;
        while (subtotal > threshold)
        {
            if (roaming->left != NULL)
            {
                enterOnce = true;
                anotherPrev = roaming;
                roaming = roaming->left;
                //cout << "Current node1: " << roaming->value << endl;
                subtotal -= roaming->leastBelow;
                nodesNumber -= roaming->leastNumber;
                //cout << "subtotal" << subtotal << endl;
                    
            }
            else
            {
                edgeReached = true;
                break;
            }
        }

        if (edgeReached)
        {
            //cout << "Edge reached!\n";
            //edge reached, but still greater, return previous fit
            return previousNodesNumber;
        }
        else
        {
            if (subtotal == threshold)
            { 
                //cout << "Should have enter here!\n";
                //cout << "subtotal = " << subtotal << endl;
                return nodesNumber;
            }
            else if (subtotal < threshold)
            {
                if (subtotal + roaming->value == threshold)
                {
                    return nodesNumber + 1;
                }
                else if (subtotal + roaming->value < threshold)
                {
                    //cout << "Enter here!\n";
                    subtotal += roaming->value;
                    nodesNumber += 1;
                    //cout << "NodesNumber : " << nodesNumber << endl;
                    if (roaming->right != NULL)
                    {
                        //left recursive
                        int recursiveResult = LCount(roaming->right, threshold, subtotal);
                        //cout << "recursive result : " << recursiveResult << endl;
                        //cout << "nodesNumber: " << nodesNumber << endl;
                        nodesNumber += recursiveResult;
                    }
                }
                return nodesNumber;
            }
            else
            {
                //child testt case!
                //cout << "Should not enter here!\n";
            }
        }
        return nodesNumber;
    }
}

int main()
{

    int initialVal;
    cin >> initialVal;
    Node* head = NULL;

    //trying if moving outside will help
    int curVal;
    int eraseValue;
    Node* curNode, * prevNode, * replacement, * newNode;
    int subtotal = 0;
    for (int i = 0; i < initialVal; i++)
    {
        //int curVal;
        cin >> curVal;
        subtotal += curVal;
        Node* newNode = new Node;
        newNode->value = curVal;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->leastBelow = curVal;
        newNode->mostBelow = curVal;
        newNode->mostNumber = 1;
        newNode->leastNumber = 1;
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node* curNode = head;
            while (curNode != NULL)
            {
                if (newNode->value > curNode->value)
                {
                    //since this one will be a right, then
                    //the least below of curNode will be accumulated with the newNode
                    curNode->leastBelow += newNode->value;
                    curNode->leastNumber += 1;
                    
                    if (curNode->right == NULL)
                    {
                        curNode->right = newNode;
                        break;
                    }
                    else
                    {
                        curNode = curNode->right;
                    }
                }
                else if (newNode->value <= curNode->value)
                {
                    //go to left child
                    //the mostBelow of the curNode will be accumulated
                    curNode->mostBelow += newNode->value;
                    curNode->mostNumber += 1;
                    if (curNode->left == NULL)
                    {
                        curNode->left = newNode;
                        break;
                    }
                    else
                    {
                        curNode = curNode->left;
                    }
                }
            }
        }
    }

    char command;
    while (cin >> command)
    {
        if (command == 'I')
        {
            //Insert
            cin >> curVal;
            subtotal += curVal;
            initialVal++;
            Node* newNode = new Node;
            newNode->value = curVal;
            newNode->left = NULL;
            newNode->right = NULL;
            newNode->leastBelow = curVal;
            newNode->mostBelow = curVal;
            newNode->mostNumber = 1;
            newNode->leastNumber = 1;
            if (head == NULL)
            {
                head = newNode;
            }
            else
            {
                Node* curNode = head;
                while (curNode != NULL)
                {
                    if (newNode->value > curNode->value)
                    {

                        //goright
                        //the least below of curNode will be accumulated with the newNode
                        curNode->leastBelow += newNode->value;
                        curNode->leastNumber += 1;
                        if (curNode->right == NULL)
                        {
                            curNode->right = newNode;
                            break;
                        }
                        else
                        {
                            curNode = curNode->right;
                        }
                    }
                    else if (newNode->value <= curNode->value)
                    {
                        //go to left child
                        //the mostBelow of the curNode will be accumulated
                        curNode->mostBelow += newNode->value;
                        curNode->mostNumber += 1;
                        if (curNode->left == NULL)
                        {
                            curNode->left = newNode;
                            break;
                        }
                        else
                        {
                            curNode = curNode->left;
                        }
                    }
                }
            }
        }
        else if (command == 'D')
        {
            //erase
            //int eraseValue;
            cin >> eraseValue;
            subtotal -= eraseValue;
            initialVal--;
            /*Node* curNode = head;
            Node* prevNode = NULL;*/

            Node* curNode = head;
            Node* prevNode = NULL;
            while (curNode != NULL && curNode->value != eraseValue)
            {
                //since we are sure to know that the node exist in the bottom, we can reverse the input process
                if (eraseValue == curNode->value)
                {
                    break;
                }
                else if (eraseValue < curNode->value)
                {
                    //go left
                    //reverse the operation of mostbelow
                    curNode->mostBelow -= eraseValue;
                    curNode->mostNumber--;

                    prevNode = curNode;
                    curNode = curNode->left;
                }
                else if (eraseValue > curNode->value)
                {
                    //go right
                    //reverse the operation of least below
                    curNode->leastBelow -= eraseValue;
                    curNode->leastNumber--;
                    prevNode = curNode;
                    curNode = curNode->right;
                }
            }

            if (curNode->left != NULL && curNode->right != NULL)
            {
                //since not null, we know that it is not at the edge
                //replace with greatest value in left subtree
                //this time we need to subtract the eraseValue from the curNode, and subtract the replacement
                curNode->leastBelow-= eraseValue;
                curNode->mostBelow -= eraseValue;
                curNode->mostNumber--;
                curNode->leastNumber--;
                replacement = curNode->left;
                Node* replacementPrev = curNode;
                while (replacement->right != NULL)
                {
                    replacementPrev = replacement;
                    replacement = replacement->right;
                }

                //with the number of the found replacement, subtract all the way up
                Node* curNodeLeft = curNode->left;
                while (curNodeLeft != replacement)
                {
                    //since it must be on the right, reverse the least below
                    curNode->leastBelow -= replacement->value;
                    curNode->leastNumber--;
                    curNodeLeft = curNodeLeft->right;
                }

                curNode->value = replacement->value;
                //the replacemet will be the one that is eras
                //replacementPrev
                //editting the child of the replacement
                //if replacement left child is not null, connect to replacement prev

                //replace the curNode->left if the replacement 
                if (curNode != replacementPrev)
                {
                    //stick the rep
                    if (replacement->left != NULL)
                    {
                        replacementPrev->right = replacement->left;
                    }
                    else
                    {
                        replacementPrev->right = NULL;
                    }
                }
                else
                {
                    //replacementNode is directly under the curNode
                    curNode->left = replacement->left;
                }
                delete replacement;
            }
            else if (curNode->left != NULL)
            {
                //right not null, but left is null

                if (curNode != head)
                {
                    if (prevNode->right == curNode)
                    {
                        prevNode->right = curNode->left;
                    }
                    else if (prevNode->left == curNode)
                    {
                        prevNode->left = curNode->left;
                    }
                }
                else
                {
                    head = curNode->left;
                }
                delete curNode;
            }
            else if (curNode->right != NULL)
            {
                //right not null, but left is null
                if (curNode != head)
                {
                    if (prevNode->right == curNode)
                    {
                        prevNode->right = curNode->right;
                    }
                    else if (prevNode->left == curNode)
                    {
                        prevNode->left = curNode->right;
                    }
                }
                else
                {
                    head = curNode->right;
                }
                delete curNode;
            }
            else
            {
                //both NULL
                if (curNode != head)
                {
                    if (prevNode->right == curNode)
                    {
                        prevNode->right = NULL;
                    }
                    else if (prevNode->left == curNode)
                    {
                        prevNode->left = NULL;
                    }
                }
                else
                {
                    //beware, this is only for the both null case
                    head = NULL;
                }
                delete curNode;
            }
        }
        else if (command == 'P')
        {
            //print
            printAll(head);
            cout << "\n";
        }
        else if (command == 'L')
        {
            //print the LStart
            //do backward and count the L
            int requiredAmount;
            cin >> requiredAmount;
            if (head == NULL)
            {
                cout << 0 << "\n";
            }
            else
            {
                int included = LCount(head, requiredAmount);
                cout << initialVal - included << endl;
                //cout << countL(head, subtotal, requiredAmount) << "\n";
            }
            
        }
        else if (command == 'M')
        {
            //print the MStart
            int requiredAmount;
            cin >> requiredAmount;
            if (head == NULL)
            {
                cout << 0 << "\n";
            }
            else
            {
                int included = MCount(head, requiredAmount);
                cout << initialVal - included << endl;
            }
        }
        else
        {
            cout << "Undetected command! Breaking!\n";
            return 0;
        }
    }
    return 0;
}