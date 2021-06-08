#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <queue>
#include <stack>
#include <unordered_set>

using namespace std;

class Tree
{
private:
    struct node{
        node(){};
        node(int val){data = val;};
        int data;
        node *left=nullptr;
        node *right=nullptr;
    };
    node *m_root;
public:
    Tree();
    void insert(int val);
    void createTree();
    void printInorder();
    void printPreOrder();
    void printPostOrder();
    void printInorderRecursive(node *nn);

    void BFS();
};

#endif // TREE_H
