/*
Name: <Ben Skinner>
email <bts277@msstate.edu>
Compiler Used: <Qt Creator>
Program Description:
<This program allows the user to manage player characters with an AVL>
*/
#include <node.h>
#include <iostream>
#include <string>
#include <string>
using namespace std;
#ifndef AVL_H
#define AVL_H


class AVL
{
private:
    // private functions
Node* root;
int height(Node* node);
bool BF(Node* node);
void rightRotate(Node*& node);
void leftRotate(Node*& node);
void balance(Node*& node);
bool insert(Node *&node, string data, string race, string job, string lvl);
bool remove(Node *&node, string data);
bool find(Node* node, int data);
void inOrder(Node* node, ostream& os);
void preOrder(Node* node, ostream& os);
void postOrder(Node* node, ostream& os);
void destroy(Node*& node);
void set(Node* &node, string pname, string pstat, string pval);
void search(Node* &node, string stat, string val);

public:
// use these to call private functions
void search(string data, string val);
AVL(): root(nullptr) {}
~AVL();
bool insert(string data);
bool remove(string data);
string find(string data);
void inOrder(ostream& os);
void preOrder(ostream& os);
void postOrder(ostream& os);
void set(string name, string stat, string val);

void setRace(string pRace);
void setJob(string pJob);
void setlvl(int plvl);

};

#endif // AVL_H

