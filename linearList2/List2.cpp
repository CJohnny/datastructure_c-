#include <iostream>
#include "List2.h"
#include "Node.h"

using namespace std;

List::List(){

    m_pList=new Node;
    m_pList->data=0;
    m_pList->next=NULL;
    m_length=0;
}

List::~List(){

   clearList();
   delete m_pList;
   m_pList=NULL;

}

bool List::listInsertHead(Node* pNode){

    Node* temp=m_pList->next;
    Node* newNode=new Node;

    if(newNode==NULL)
        return false;

    newNode->data=pNode->data;
    m_pList->next=newNode;
    newNode->next=temp;

    m_length++;

    return true;

}

bool List::listInsertTail(Node* pNode){

    Node* currentNode=m_pList;
    while(currentNode->next!=NULL){

        currentNode=currentNode->next;
    }

    Node* newNode=new Node;

    if(newNode==NULL)
        return false;

    newNode->data=pNode->data;
    newNode->next=NULL;
    currentNode->next=newNode;

    m_length++;

    return true;
}

bool List::listInsert(int i, Node* pNode){

    if(i<0 || i>m_length)
        return false;
    Node* currentNode=m_pList;
    for(int k=0;k<i;k++){

        currentNode=currentNode->next;
    }

    Node* newNode=new Node;

    if(newNode==NULL)
        return false;

    newNode->data=pNode->data;
    newNode->next=currentNode->next;
    currentNode->next=newNode;
}

bool List::listDelete(int i, Node* pNode){

    if(i<0 || i>=m_length)
        return false;
    Node* currentNode=m_pList;
    Node* currentNodePrior=NULL;
    for(int k=0;k<=i;k++){

        currentNodePrior=currentNode;
        currentNode=currentNode->next;
    }

    currentNodePrior->next=currentNode->next;
    pNode->data=currentNode->data;

    delete currentNode;
    currentNode=NULL;

    m_length--;

    return true;

}
void List::clearList(){

    Node* currentNode=m_pList->next;
    while(currentNode!=NULL){

       Node* temp=currentNode->next;
       delete currentNode;
       currentNode=temp;
    }
    m_pList->next=NULL;
}

bool List::getElem(int i, Node* pNode){

    if(i<0 || i>m_length)
        return false;
    Node* currentNode=m_pList;
    Node* currentNodePrior=NULL;
    for(int k=0;k<=i;k++){

        currentNodePrior=currentNode;
        currentNode=currentNode->next;
    }

    pNode->data=currentNode->data;
    return true;
}

int List::locateElem(Node* pNode){  //只返回第一个对应元素的位置

    Node* currentNode=m_pList;
    int count=1;
    while(currentNode->next!=NULL){

        currentNode=currentNode->next;
        if(currentNode->data==pNode->data)
            return count;
        count++;
    }
    return -1;
}

bool List::priorElem(Node* pNode, Node* preNode){

    Node* currentNode=m_pList;
    Node* temp=NULL;
    while(currentNode->next!=NULL){

        temp=currentNode;
        currentNode=currentNode->next;
        if(currentNode->data==pNode->data){
            if(temp=m_pList){
                return false;
            }

            preNode->data=temp->data;
            return true;
        }
    }
}

bool List::nextElem(Node* pNode, Node* nextNode){

    Node* currentNode=m_pList;

    while(currentNode->next!=NULL){

        currentNode=currentNode->next;
        if(currentNode->data==pNode->data){
            if(currentNode->next==NULL){
                return false;
            }

            nextNode->data=currentNode->next->data;
            return true;
        }
    }
}

void List::listTraverse(){

    Node* currentNode=m_pList;
    while(currentNode->next!=NULL){

        currentNode=currentNode->next;
        currentNode->printNode();
    }
}
bool List::listEmpty(){

    if(m_length==0)
        return true;
    else
        return false;
}

int List::listLength(){

    return m_length;
}
