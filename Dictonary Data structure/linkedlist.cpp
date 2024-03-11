#include "linkedlist.h"
template <class T>
linkedlist<T>::linkedlist()
{
    head=nullptr;
    tail=nullptr;
}
template <class T>

linkedlist<T>::~linkedlist()
{
    clear();

}
template <class T>

void linkedlist<T>::clear(){
    node<T> *temp;
while(head!=nullptr){
    temp=head;
    head=head->next;
    delete temp;

}
}
template <class T>

bool linkedlist<T>::insert(T data){
node<T> *p,*prev;
p=new(nothrow)node<T>;
if(p!=nullptr){
        p->data=data;
    prev=insertionSlot(p);
    insertNode(p,prev);
    return true;
}
return false;
}
template <class T>

void linkedlist<T>::insertNode(node<T> *p,node<T> *prev){
if(head==nullptr){
    p->next=nullptr;
    head=tail=p;
}else if(prev==nullptr){
p->next=head;
head=p;
}else{
p->next=prev->next;
prev->next=p;
if(prev==tail) tail=p;
}

}
template <class T>

node<T>  *linkedlist<T>::insertionSlot(node<T> *p){
node<T> *prev,*temp=head;
while(temp!=nullptr){
        prev=temp;
if(temp->data==p->data){
    return prev;
}
temp->next;
}
}

template <class T>

node<T> * linkedlist<T>::findnode(T target){
node<T> *prev,*temp=head;
while(temp!=nullptr){
            prev=temp;
    if(temp->data==target){
        return prev;
    }
    temp->data;
}
return -1;
}
template <class T>

bool linkedlist<T>::remove(T data){
node<T> *prev,*temp;
nodeTODelete(data,prev);
if(head==prev){
head=head->next;
delete prev;
return true;
}else if(prev->next==tail){
temp=tail;
tail=prev;
prev->next=nullptr;
delete temp;
return true;
}else{
temp=prev->next;
prev->next=temp->next;
delete temp;
return true;
}
return false;
}
template <class T>

bool linkedlist<T>::nodeTODelete(T target,node<T> *&prev){
node<T> *temp=head;
while(temp!=nullptr){
            prev=temp;
    if(temp->data==target){
        return true;
    }
    temp->data;
}
return false;
}











