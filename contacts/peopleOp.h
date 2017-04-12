#ifndef PEOPLE_OP_H
#define PEOPLE_OP_H


class peopleOp{

    private:
        people* m_pList;
        int m_length;

    public:
        peopleOp();
        ~peopleOp();
        void clearList();   //除了头节点,释放
        void listTraverse();
        bool listEmpty();
//        bool initList();
        bool getElem(int i, Node* pNode);
        bool priorElem(Node* currentNode, Node* preNode);
        bool nextElem(Node* currentNode, Node* nextNode);
        bool listInsert(int i, Node* pNode);
        bool listDelete(int i, Node* pNode);
        bool listInsertHead(Node* pNode);
        bool listInsertTail(Node* pNode);
        int listLength();
        int locateElem(Node* pNode);

};

#endif  //PEOPLE_OP_H
