/*
Name: <Ben Skinner>
email <bts277@msstate.edu>
Compiler Used: <Qt Creator>
Program Description:
<This program allows the user to manage player characters with an AVL>
*/
#include "node.h"
#include "avl.h"

AVL::~AVL()
{

}
void AVL::balance(Node *&node)   // will be used to balance the tree

{
int balance = BF(node);

if (balance > 1)
{
    if (BF(node->left) < 0)
        leftRotate(node->left);
    rightRotate(node);
}

if (balance < -1)
{
    if (BF(node->right) > 0)
        rightRotate(node->right);
    leftRotate(node);
}
}

bool AVL::BF(Node* node) // calculates balance factor
{
if (node == nullptr)
return 0;
return height(node->left) - height(node->right);
}

int AVL::height(Node *node)
{
    if (node == nullptr){return 0;}
    else return node -> height;
}

void AVL::rightRotate(Node *&node)
{
Node *left = node->left;
Node *hold = left->right;
left->right = node;
node->left = hold;
node->height = max(height(node->left),
height(node->right))+1;
left->height = max(height(left->left),
height(left->right))+1;
node = left;
}

void AVL::leftRotate(Node *&node)
{
Node *right = node->right;
Node *hold = right->left;
right->left = node;
node->right = hold;
node->height = max(height(node->right),
height(node->left))+1;
right->height = max(height(right->right),
height(right->left))+1;
node = right;
}

bool AVL::insert(Node*& node, string data, string race, string job, string lvl)
{
bool success = false;
if (node == nullptr) {
    node = new Node(data, race, job, lvl);
    return true; }
if (data < node->data)
    success = insert(node->left, data, race, job, lvl);
if (data > node->data)
    success = insert(node->right, data, race, job, lvl);
if (!success) return false;

node->height = max(height(node->left),
height(node->right)) + 1;

balance(node); // performs whatever operations needed to balance tree

return true;
}

bool AVL::insert(string data)
{
 return insert(root,data, "human", "villager", "1");
}

void AVL::inOrder(Node* node, ostream& os)
{
if (node == nullptr) {return;}
inOrder(node->left, os);
os << node->data << " " << node->race << " " << node->job << " lvl " << node->lvl << endl;
inOrder(node->right, os);
}

void AVL::inOrder(ostream &os)
{
    return inOrder(root, os);
}


bool AVL::remove(Node*& node, string data) // Deletes node ,,, is a little broken
{
    bool success = false;
    if (node == nullptr)
    return false;
    if (data < node->data)
    success = remove(node->left, data);
    if (data > node->data)
    success = remove(node->right, data);

    int deg = node->degree();

    if (deg == 0)
    {
        delete node;
        node = nullptr;
    }
    else if (deg == 1)
    {
        Node* tmp = node;
        if (node->left != nullptr) {
        node = node->left;
    }
    else {
        node = node->right;
    }
    delete tmp;
    }
    else
    {
        Node *tmp = node->left;
        while (tmp->right != nullptr)
        {
            tmp = tmp->right;
        }
        node->data = tmp->data;
        remove(node->left, tmp->data);
    }

    if (!success) return false;
    node->height = max(height(node->left),
    height(node->right)) + 1;

    balance(node);

    return true;
}

bool AVL::remove(string data)
{
    return remove(root, data);
}

void AVL::set(Node* &node, string data, string stat, string pval) // can set the desired attribute to whatever the user likes
{
    if (node == nullptr)
    return;
    set(node->left, data, stat, pval);
    if (node->data == data)
    {
        if (stat == "lvl")
        {
            node->lvl = pval;
        }
        else if(stat == "race")
        {
            node->race = pval;
        }
        else if(stat == "job")
        {
            node->job = pval;
        }
    }
    set(node->right, data, stat, pval);
}

void AVL::set(string name, string stat, string val)
{
    return set(root, name, stat, val); //
}

void AVL::search(Node* &node, string stat, string val)
{
    if (node == nullptr)
    return;
    if (stat < node->data)
    search(node->left, stat, val);
    if (stat > node->data)
    search(node->right, stat, val);
        if (stat == "lvl")
        {
            if (node->lvl == val)
            {
                cout << node->data << " " << node->race << " " << node->job << " lvl " << node->lvl << endl;
            }
        }
        else if(stat == "race")
        {
            if (node->race == val)
            {
                cout << node->data << " " << node->race << " " << node->job << " lvl " << node->lvl << endl;
            }
        }
        else if(stat == "job")
        {
            if (node->job == val)
            {
                cout << node->data << " " << node->race << " " << node->job << " lvl " << node->lvl << endl;
            }
        }
}

void AVL::search(string data, string val)
{
    return search(root, data, val);
}






