#include "linkedlist.h"

Linkedlist::Linkedlist()
{
    qDebug()<<"Linkedlist::Linkedlist()";

}

void Linkedlist:: addFirst(int data){
    qDebug()<<"Linkedlist::addFirst()";
    node *nn = new node;
    nn->data = data;

    if(m_head == nullptr && m_tail == nullptr){
        m_head = nn;
        m_tail = nn;
    }else {
        /*Adding element at first*/
        node *temp = m_head;
        m_head = nn;
        nn->next = temp;
    }
}

void Linkedlist::addLast(int data){
    qDebug()<<"Linkedlist::addLast()";
    node *nn = new node;
    nn->data = data;
    if(m_head == nullptr && m_tail == nullptr){
        m_head = nn;
        m_tail = nn;
    }else{
        node* temp = m_tail;
        m_tail = nn;
        temp->next = nn;
    }
}

void Linkedlist:: display(){
    qDebug()<<"Linkedlist::display()";
    node *trav = m_head;
    while (trav != nullptr) {
        qDebug()<<" \t"<<trav->data;
        trav = trav->next;
    }
    qDebug()<<"Linkedlist::display() - end";
}

void Linkedlist::deleteFirst()
{
    qDebug()<<"Linkedlist::deleteFirst()";
    if(m_head != nullptr){
        node *temp = m_head;
        m_head = m_head->next;
        if(temp == m_tail){
            m_tail = nullptr;
        }
        delete temp;
    }else{
        qDebug()<<"List is empty";
    }
}

void Linkedlist:: deleteLast(){
    qDebug()<<"Linkedlist::deleteLast()";
    node *temp=nullptr, *trav=nullptr;
    trav = m_head;
    while(trav != m_tail){
        temp = trav;
        trav = trav->next;
    }
    m_tail = temp;
    m_tail->next = nullptr;
    delete trav;
}

void Linkedlist::deleteLast_fast()
{
//    node *slow = m_head;
    node *fast = m_head;
    node *fast_prev = m_head;

    while(fast != nullptr && fast->next != nullptr){
        qDebug()<<"fast :"<<fast->data<<" fast_prev:"<<fast_prev->data;
        fast_prev = fast;
        fast = fast->next->next;
    }

    if(fast == nullptr){
        qDebug()<<"fast == nullptr";
        node *temp = fast_prev->next;
        fast_prev->next = nullptr;
        m_tail = fast_prev;
        delete temp;
    }
    else if(fast->next == nullptr){
        qDebug()<<"fast->next == nullptr";
        node *temp = fast;
        fast_prev->next->next = nullptr;
        m_tail = fast_prev->next;
        delete temp;
    }

}

void Linkedlist::deleteMiddleElement(){
    node *trav=nullptr, *f_trav = nullptr, *prev=nullptr;
    trav = m_head;
    f_trav = m_head;//trav->next->next;
    while(f_trav != nullptr && f_trav->next != nullptr){
        qDebug()<<"f_trav "<<f_trav->data;
        prev = trav;
        trav = trav->next;
        f_trav = f_trav->next->next;
    }

    qDebug()<<"middle :"<<trav->data;
    prev->next = trav->next;
    delete  trav;
}

void Linkedlist::reverseList()
{
    qDebug()<<"Linkedlist::reverseList()";
    node *t1, *t2, *t3;
    t1 = m_head;
    t2 = t1->next;
    t1->next = nullptr;
    t3 = nullptr;
    while (t2 != nullptr) {
        t3 = t2->next;
        t2->next = t1;
        t1 = t2;
        t2 = t3;
    }
    m_head = t1;
}

void Linkedlist::reverseLL()
{
    qDebug()<<Q_FUNC_INFO;
    node *cur, *prev=nullptr;
    cur = m_head;
    while(cur != nullptr){
        node *tmp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = tmp;
    }
    m_tail = m_head;
    m_head = prev;
    /*update the head in the last*/

}



void Linkedlist:: findLoop(){
    qDebug()<<"Linkedlist::findLoop()";
    node *trav=nullptr, *f_trav=nullptr;
    trav = m_head;
    f_trav = m_head;
    bool isLoop = false;

    while(f_trav != nullptr && f_trav->next != nullptr ){
        trav = trav->next;
        f_trav = f_trav->next->next;
        if(trav == f_trav){
            isLoop = true;
            qDebug()<<"Loop detected";
            break;
        }
    }

    if(!isLoop){
        qDebug()<<"No Loop in LinkedList";
    }

}


/*Loop exact location*/
void Linkedlist:: findExactLoop(){
    qDebug()<<"Linkedlist::findExactLoop()";
    std::unordered_set<node*> list;
    node *trav=nullptr, *f_trav=nullptr;
    trav = m_head;
    f_trav = m_head;
    bool isLoop = false;

    while(f_trav != nullptr && f_trav->next != nullptr ){
        auto loopLoc = list.find(trav);
        if(loopLoc != list.end()){
            isLoop = true;
            qDebug()<<"Loop detected :"<<trav->data;
            break;
        }
        list.insert(trav);
        trav = trav->next;
        f_trav = f_trav->next->next;
    }

    if(!isLoop){
        qDebug()<<"No Loop in LinkedList";
    }

}

void Linkedlist::searchElementLL(int val)
{
    qDebug()<<Q_FUNC_INFO<<" val :"<<val;
    node /**trav=m_head,*/ *f_odd=nullptr, *f_even=m_head;
    if(m_head->next != nullptr){
        f_odd = m_head->next;
    }
    int index = 0;
    bool isElementFound = false;
    while(/*trav != nullptr &&*/ (f_even != nullptr || f_odd != nullptr)/*&&(f_even->next != nullptr || f_odd->next != nullptr)*/ /*&&(f_even->next == nullptr || f_odd->next != nullptr) && (f_even->next != nullptr || f_odd->next == nullptr)*/){
//        if(trav->data == val){
//            qDebug()<<"Value found at position :"<<index -1;
//            break;
//        }
        qDebug()<<"f_even->data :"<<f_even->data<<" #f_odd->data :"<<f_odd->data;

        if(f_even != nullptr && f_even->data == val){
            qDebug()<<"--------------Value found at position :"<<index*2;
            index = index *2;
            isElementFound = true;
            break;
        }
        if(f_odd != nullptr && f_odd->data == val){
            qDebug()<<"--------------Value found at position :"<<(index*2)+1;
            index = (index*2)+1;
            isElementFound = true;
            break;
        }
        if(f_odd->next == nullptr || f_odd->next->next == nullptr){
            break;
        }
        f_even = f_even->next->next;
        f_odd = f_odd->next->next;
        ++index;
    }

    if(isElementFound){
        qDebug()<<"Element found at position :"<<index;
    }else{
        qDebug()<<"Element not found";
    }

}
