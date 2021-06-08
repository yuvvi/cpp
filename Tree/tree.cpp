#include "tree.h"


Tree::Tree():m_root(nullptr)
{
    cout<<"Tree::Tree()"<<endl;
}



void Tree::insert(int val)
{
    cout<<"Tree::insert() #val:"<<val<<endl;
    node *nn = new node;
    nn->data = val;
    nn->left = nullptr;
    nn->right = nullptr;
    if(m_root == nullptr){
        m_root = nn;
        return;
    }

    node *prev = nullptr;
    node *trav = m_root;

    while(trav != nullptr){
        cout<<"---------------------trav->data: "<<trav->data<<endl;

        if(trav->data > val){//left trav
            prev = trav;
            trav = trav->left;
        }
        else if(trav->data < val){//right trav
            prev = trav;
            trav = trav->right;
        }
    }

    if(prev->data > val){
        prev->left = nn;
        cout<<"Inserted LEFT to node :"<<prev->data<<endl;
    }else{//prev->data > val
        prev->right = nn;
        cout<<"Inserted RIGHT to node :"<<prev->data<<endl;
    }
}

void Tree::createTree()
{
//    insert(1);
//    insert(2);
//    insert(3);
//    insert(4);
//    insert(5);

    insert(8);
    insert(3);
    insert(10);
    insert(1);
    insert(6);
    insert(4);
    insert(7);
    insert(14);
    insert(13);

//    m_root = new node(1);
//    m_root->left = new node(2);
//    m_root->right = new node(3);
//    m_root->left->left = new node(4);
//    m_root->left->right = new node(5);
    cout<<"----------------"<<endl;
    printInorderRecursive(m_root);
    cout<<"----------------"<<endl;
    printInorder();
    cout<<"----------------"<<endl;
    printPreOrder();
    cout<<"----------------"<<endl;
    printPostOrder();
    cout<<"----------------"<<endl;
    BFS();
    cout<<endl;
}


void Tree::printInorder()
{
    cout<<"INORDER - LEFT->ROOT->RIGHT"<<endl;
    if(m_root == nullptr){
        cout<<"Tree is empty"<<endl;
    }
    stack<node*> q;
    node *trav =m_root;

    while(trav != nullptr || !q.empty()){

        while(trav != nullptr){
            q.push(trav);
            trav = trav->left;
        }

        trav = q.top();
        q.pop();
        cout <<" "<<trav->data;
        trav = trav->right;
    }
}

void Tree::printPreOrder()
{
    cout<<"PREORDER - ROOT->LEFT->RIGHT"<<endl;
    if(m_root == nullptr){
        cout<<"Tree is empty"<<endl;
    }
    stack<node*> q;
    node *trav =m_root;

    while(trav != nullptr || !q.empty()){
        while(trav != nullptr){
            cout <<" "<<trav->data;

            q.push(trav);
            trav = trav->left;
        }

        trav = q.top();
        q.pop();
        trav = trav->right;
    }
}

void Tree::printPostOrder()
{
    cout<<"POST ORDER - LEFT->RIGHT->ROOT"<<endl;
    if(m_root == nullptr){
        cout<<"Tree is empty"<<endl;
    }

//    stack<node*> q;
    unordered_set<node*> set;

    node *trav = m_root;

    cout<<"set.find(trav) == set.end() :"<<(set.find(trav) == set.end())<<endl;
    while(trav != nullptr && set.find(trav) == set.end()){


        if(trav->left && set.find(trav->left) == set.end()){
            trav = trav->left;
        }
        else if(trav->right && set.find(trav->right) == set.end()){
            trav = trav->right;
        }
        else{
            cout<<" "<<trav->data;
            set.insert(trav);
            trav = m_root;
        }


    }
}

void Tree::printInorderRecursive(node *nn)
{
    if(nn == nullptr){
        return;
    }
    printInorderRecursive(nn->left);
    cout<<nn->data<<" ";
    printInorderRecursive(nn->right);
}

void Tree::BFS()
{
    cout<<"BFS - Breadth First Search"<<endl;
    if(m_root == nullptr){
        return;
    }
    queue<node*> q;
    q.push(m_root);

    while(!q.empty()){
        node *nn = q.front();
        cout<<" "<<nn->data;

        q.pop();
        if(nn->left !=nullptr){
            q.push(nn->left);
        }
        if(nn->right != nullptr){
            q.push(nn->right);
        }
    }
}
