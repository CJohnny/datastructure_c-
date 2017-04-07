#include <iostream>
#include "List2.h"

using namespace std;

List::List(){

    m_plist=new Node;
    m_plist->data=0;
    m_plist->next=NULL;
    m_length=0;
}

List::~List(){

   clearList();
   delete m_pList;
   m_pList=NULL;

}

void List::clearList(){

    Node* currentNode=m_pList->next;
    while(currentNode!=NULL){

       NOde* temp=currentNode->next;
       delete currentNode;
       currentNode=temp;
    }
    m_pList->next=NULL;
}

bool List::listInsertHead(Node* pNode){


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
