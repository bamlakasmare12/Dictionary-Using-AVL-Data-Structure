#ifndef LINKEDLIST_H
#define LINKEDLIST_H
template <class T>
struct node{
T data;
node<T> *next;
};
template <class T>
class linkedlist
{
    public:
        linkedlist();
        virtual ~linkedlist();
        bool isEmpty();
        bool insert(T data);
        bool remove(T data);
        node<T> *findnode(T target);
        int count();
        void clear();

    protected:

    private:

        node<T> *head;
        node<T> *tail;
        void insertNode(node<T> *p,node<T> *prev);
        node<T> *insertionSlot(node<T> *p);
        bool nodeTODelete(T target, node<T>*&prev);
};

#endif // LINKEDLIST_H
