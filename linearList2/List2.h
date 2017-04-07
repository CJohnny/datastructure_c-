#ifndef NODE_H
#define NODE_H
#include "Node.h"

class List{

private:

    int* m_pList;
    int m_length;


public:
    List();
    ~List();    //����ͷ�ڵ㣬�ͷ�
//    void deleteList();
    void clearList();   //����ͷ�ڵ�,�ͷ�
    void listTraverse();
    bool listEmpty();
    bool initList();
    bool getElem(int i, int* e);
    bool priorElem(int* currentElem, int* preElem);
    bool nextElem(int* currentElem, int* nextElem);
    bool listInsert(int i, int* e);
    bool listDelete(int i, int* e);
    bool listInsertHead(Node* pNode);
    bool listInsertTail(Node* pNode);
    int listLength();
    int locateElem(int*e);
};



#endif // NODE_H
