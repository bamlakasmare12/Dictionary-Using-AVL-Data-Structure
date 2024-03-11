#include<iostream>
#include<string>
#include<string.h>
using namespace std;
template <class T>
struct avlNode{
    T key;
    string meaning;
    int height;
    avlNode<T> * left;
    avlNode<T> * right;

};
template <class T>
class AVL{
    public:
        AVL();//default constructor
        AVL(AVL<T> & avl); //copy constructor
        virtual ~AVL(); //destructor
        void makeEmpty(avlNode<T> * t);
        int isEmpty();
        void search_value(string & select);
        void inorder();
        void edit(T valo,T valn);
        void insert(T data); //uses insert private
	 	void remove(T target);//uses remove private
        void display(); //uses inorder private
        avlNode<T> * src(T val);
        int src1(T val);
        avlNode<T> * findMin(avlNode<T> * r);
        avlNode<T> * findMax(avlNode<T> * r);
    protected:
    private:
    	avlNode<T>* bl(avlNode<T>* t);
    	bool startsWith(string str, string prefix);
    	bool endsWith(string str,string suffix);
    	avlNode<T>* searchinf(avlNode<T> *cur,string key1,string *&str,int &num);
    	avlNode<T>* searchpost(avlNode<T> *cur,string key1,string *&str,int &num);
    	avlNode<T>* searchpre(avlNode<T> *cur,string key1,string *&str,int &num);
        avlNode<T> * root;
        int height(avlNode<T> * n);
        avlNode<T> * LeftRotate(avlNode<T> * n);
        avlNode<T> * LeftRightRotate(avlNode<T> * n);
        avlNode<T> * RightRotate(avlNode<T> * n);
        avlNode<T> * RightLeftRotate(avlNode<T> * n);
        int getBalance(avlNode<T> * n);
        avlNode<T> * insert(avlNode<T> * avlRoot,avlNode<T> * tmp);
        avlNode<T> * remove(avlNode<T> * avlRoot,T data);
        void inorder(avlNode<T> * avlRoot);
        void edit(T valo,T valn,avlNode<T> *root);
        avlNode<T> * src(avlNode<T> * r, T val);
        int src1(avlNode<T> * r, T val);

};

