/*
Name: <Ben Skinner>
email <bts277@msstate.edu>
Compiler Used: <Qt Creator>
Program Description:
<This program allows the user to manage player characters with an AVL>
*/

#include <iostream>
#include <string>
#include <string>
using namespace std;

#ifndef NODE_H
#define NODE_H


class Node
{
public:
string data;
string name, race = "human", job = "villager", lvl = "1";
int height;
Node *left;
Node *right;
Node(): data(0), height(1), left(nullptr),
right(nullptr) {}
Node(string data, string race, string job, string lvl): data(data), race(race), job(job), lvl(lvl), height(1),
left(nullptr),
right(nullptr){}
int degree() const;


private:

};

#endif // NODE_H
