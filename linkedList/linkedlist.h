#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <QDebug>
#include <unordered_set>

class Linkedlist
{
public:
    Linkedlist();
    void addFirst(int data);
    void addLast(int data);
    void display();

    void deleteFirst();
    void deleteLast();
    void deleteLast_fast();
    void deleteMiddleElement();
    void reverseList();

    void reverseLL();
    void findLoop();
    void findExactLoop();
    void searchElementLL(int val);

private:
    struct node{
        int data;
        node *next = nullptr;
    };

    node *m_head = nullptr;
    node *m_tail = nullptr;
};

#endif // LINKEDLIST_H
