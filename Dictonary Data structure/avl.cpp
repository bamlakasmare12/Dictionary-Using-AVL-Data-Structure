#include<iostream>
#include <string>
#include <string.h>
#include<cstring>
#include<iomanip>
#include<stdlib.h>
#include <stdio.h>
#include"avl.h"
using namespace std;
template <class T>
AVL<T>::AVL(){
   root=nullptr;
}
template <class T>
AVL<T>::~AVL()
{
    makeEmpty(root);
}
template <class T>
int AVL<T>::src1(T val){
	return src1(root,val);
}
template <class T>
void AVL<T>::makeEmpty(avlNode<T> * t){
   makeEmpty(root);
}
template <class T>
void AVL<T>::edit(T valo,T valn){
edit(valo,valn,root);
}
template <class T>
void AVL<T>::insert(T data){
	avlNode<T> *temp;
    temp=new avlNode<T>();
	temp->key=data;
	//temp->meaning=meaning;
	temp->left=temp->right=NULL;
	root=insert(root,temp);

}
template <class T>
void AVL<T>::remove(T data){
    root=remove(root,data);
}
template <class T>
void AVL<T>::display(){
    inorder(root);
}

template <class T>
avlNode<T>* AVL<T>::insert(avlNode<T>* cur,avlNode<T>* temp)
{
	if(cur==NULL)
	{
		return temp;
	}
	if(temp->key<cur->key)
	{
	cur->left=insert(cur->left,temp);
		int bal;
	bal=getBalance(cur);
	if(bal>=2)
	{
		if(getBalance(cur->left)<0)
		    cur=LeftRightRotate(cur);
		else
		    cur=RightRotate(cur);

	}
	else if(bal<=-2)
	{
		if(getBalance(cur->right)<0)
			cur=LeftRotate(cur);
		else
			cur=RightLeftRotate(cur);
	}
	}
	else if(temp->key>cur->key)
	{
	cur->right=insert(cur->right,temp);
		int bal;
	bal=getBalance(cur);
	if(bal>=2)
	{
		if(getBalance(cur->left)<0)
		    cur=LeftRightRotate(cur);
		else
		    cur=RightRotate(cur);

	}
	else if(bal<=-2)
	{
		if(getBalance(cur->right)<0)
			cur=LeftRotate(cur);
		else
			cur=RightLeftRotate(cur);
	}
	}
	int bal;
	bal=getBalance(cur);
	if(bal>=2)
	{
		if(getBalance(cur->left)<0)
		    cur=LeftRightRotate(cur);
		else
		    cur=RightRotate(cur);

	}
	else if(bal<=-2)
	{
		if(getBalance(cur->right)<0)
			cur=LeftRotate(cur);
		else
			cur=RightLeftRotate(cur);
	}
	return cur;
}
template <class T>
int AVL<T>::getBalance(avlNode<T> *temp)
{
	int l,r;
	l=height(temp->left);
	r=height(temp->right);
	return(l-r);
}
template <class T>
int AVL<T>::height(avlNode<T> *temp)
{
	if(temp==NULL)
		return(-1);
	else
		return(max(height(temp->left),height(temp->right))+1);
}
template <class T>
avlNode<T>* AVL<T>::RightRotate(avlNode<T> *par)
{
	avlNode<T> *temp,*temp1;
	temp=par->left;
	temp1=temp->right;
	temp->right=par;
	par->left=temp1;
	return temp;
}
template <class T>
avlNode<T>* AVL<T>::LeftRotate(avlNode<T> *par)
{
	avlNode<T> *temp,*temp1;
	temp=par->right;
	temp1=temp->left;
	temp->left=par;
	par->right=temp1;
	return temp;
}
template <class T>
avlNode<T>* AVL<T>::RightLeftRotate(avlNode<T> *par)
{
	par->right=RightRotate(par->right);
	return(LeftRotate(par));
}
template <class T>
avlNode<T>* AVL<T>::LeftRightRotate(avlNode<T> *par)
{
	par->left=LeftRotate(par->left);
	return(RightRotate(par));
}
template <class T>
void AVL<T>::inorder(avlNode<T> *temp)
{
        if(temp!=NULL)
        {
                inorder(temp->left);
                cout<<"\n\t"<<temp->key;
                inorder(temp->right);
        }
}
template<class T>
bool AVL<T>::endsWith(string str,string suffix)
{

    return str.size() >= suffix.size() && 0 == str.compare(str.size()-suffix.size(), suffix.size(), suffix);
}
template<class T>
bool AVL<T>::startsWith(string str, string prefix)
{

    return str.size() >= prefix.size() && 0 == str.compare(0, prefix.size(), prefix);
}
template<class T>
  avlNode<T>* AVL<T>::searchinf(avlNode<T> *cur,string key1,string *&str,int &i)
{
//  static int i=0;
  if(cur!=NULL)
  {
    if(cur->key.find(key1)!= std::string::npos){
      str[i]=cur->key;
      i=i+1;
      searchinf(cur -> left, key1,str,i);
       searchinf(cur -> right, key1,str,i);
      return cur;}
    if(cur->key>key1)
      return (searchinf(cur->left,key1,str,i),searchinf(cur->right,key1,str,i));
    else if(cur->key<key1)
      return (searchinf(cur->right,key1,str,i),searchinf(cur->left,key1,str,i));
  }
  return cur;
}
template<class T>
  avlNode<T>* AVL<T>::searchpost(avlNode<T> *cur,string key1,string *&str,int &i)
{
 // static int i=0;
  if(cur!=NULL)
  {

    if(endsWith(cur->key,key1)){
      str[i]=cur->key;
      i=i+1;
      searchpost(cur -> left, key1,str,i);

        searchpost(cur -> right, key1,str,i);
      }
    else if(cur->key>key1){
      return (searchpost(cur->left,key1,str,i),searchpost(cur->right,key1,str,i));
    }    else if(cur->key<key1){
      return (searchpost(cur->left,key1,str,i),searchpost(cur->right,key1,str,i));
    }

  }
  return cur;
}
template<class T>
  avlNode<T>* AVL<T>::searchpre(avlNode<T> *r,string val,string *&str,int &i)
{
 //static int i=0;
 if(r!=NULL){
  if(startsWith(r->key,val)){
      str[i]=r->key;
      i=i+1;
      searchpre(r -> left, val,str,i);

        searchpre(r -> right, val,str,i);
      }
    else if (val < r -> key){
      return searchpre(r -> left, val,str,i);

   } else
      return searchpre(r -> right, val,str,i);
 }
 else
    return r;

}
template<class T>
void AVL<T>::search_value(string &select)
{  int a=0;
	 cout<<"\n 1.postfix";
	cout<<"\n 2.prefix";
	cout<<"\n 3.infix";
	cout<<"\n Enter the type of search";
	cin>>a;
	if(a==1){
		int k=0;
		char key2[50];
        cout<<"\n Enter the keyword you wish to search : ";
        cin.ignore();
        cin.getline(key2,50,'\n');
        string *str=new(nothrow) string[5];
        int num;
        searchpost(root,key2,str,num);
        int len=sizeof(str)/sizeof(*str);
        if(num!=0){

                cout<<"\n The entered keyword is present in the AVL tree";
                int i;
                for(i=0;i<num;i++){
                	cout<<"\n"<<i+1<<". "<<str[i];
                }
                	cout<<endl<<"select the word: ";
				cin>>k;
				select=str[k-1];
				}
				  else
                cout<<"\n The entered keyword is not present in the AVL tree";
	}
	else if(a==2){
            int k;
		string key2;
        cout<<"\n Enter the keyword you wish to search : ";
        cin>>key2;
        string *str=new (nothrow) string[10];
        int num;
        searchpre(root,key2,str,num);
        int len;

        if(num!=0){

                cout<<"\n The entered keyword is not present in the AVL tree"<<endl<<endl;
                int i;
                for(i=0;i<num;i++){
                	cout<<"\n"<<i+1<<". "<<str[i];
				}
				cout<<endl<<"select the word: ";
				cin>>k;
				select=str[k-1];
				}

        else
                cout<<"\n The entered keyword is not present in the AVL tree"<<endl<<endl;
	}
	else{
int k;
	string key2;
        cout<<"\n Enter the keyword you wish to search : ";
        cin>>key2;
        string *str=new(nothrow) string[50];
        int num;
        searchinf(root,key2,str,num);
        if(num!=0){

                cout<<"\n The entered keyword is present in the AVL tree";
                int i;
                for(i=0;i<num;i++){
                	cout<<"\n"<<i+1<<". "<<str[i];
				}
				cout<<endl<<"select the word: ";
				cin>>k;
				select=str[k-1];
				}
        else
                cout<<"\n The entered keyword is not present in the AVL tree"<<endl<<endl;
}
}
template <class T>
avlNode<T>* AVL<T>::remove(avlNode<T>* t,T data)
{      avlNode<T> * temp;
    if(t==NULL)
        return NULL;
    else if(data < t->key){
        t->left=remove(t->left,data);

    }else if(data > t->key){
        t->right=remove(t->right,data);
    }else if(t->left !=NULL  && t->right!=NULL){
        temp=findMax(t->left);
        t->key=temp->key;
        t->left=remove(t->left,temp->key);
    }else{
        temp=t;
        if(t->left==NULL)
            t=t->right;
        else if(t->right==NULL)
            t=t->left;
        delete temp;

    }}
template <class T>
avlNode<T> *AVL<T>::findMin(avlNode<T> *r)
{
  if (r->left!=NULL)
    return findMin(r->left);
  return r;
}
    template <class T>
avlNode<T> *AVL<T>::findMax(avlNode<T> *r)
{
  if (r->right!=NULL)
    return findMax(r->right);
  return r;
}
template<class T>
avlNode<T> * AVL<T>::src(avlNode<T> * r, T val) {
    if (r == NULL || r -> key == val)
      return r;

    else if (val < r -> key)
      return src(r -> left, val);

    else
      return src(r -> right, val);
  }
template<class T>
void AVL<T>::edit(T valo,T valn,avlNode<T> * root)
{
avlNode<T> *t;
t=src(root,valo);
T st;
st=t->meaning;
remove(valo);
insert(valn);
}
template<class T>
int AVL<T>::src1(avlNode<T> * r, T val) {
    if (r == NULL )
      return 0;
	else if (r -> key == val)
	  return 1;
    else if (val < r -> key)
      return src1(r -> left, val);
    else
      return src1(r -> right, val);
  }
