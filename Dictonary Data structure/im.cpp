/*
name BAMLAK ASMARE ID FX3407
NAME AMANUEL MEHARI IF OV6906
*/



#include<iostream>
#include<string>
#include"avl.cpp"
#include"linkedlist.cpp"
#include <fstream>
struct dictionary{
char word[50];
char type[4];
char pron[60];
char meaning[200];
};
template <class T>
struct dicindex{
char word[50];
linkedlist<T> pos;
};

void copy(ifstream &input,ofstream &output,string select){
    string temp1,temp2;
    int x;
output.clear();
    while(!input.eof()){

        getline(input,temp1,':');
        x=temp1.compare(select);
        if(x==0){
            cout<<select<<" "<<temp1;
        input.ignore(200,'.');

        }else{
         cout<<select<<" "<<temp1<<" ="<<x<<endl;
        output<<temp1<<endl;

    }

    }

    while(!output.eof()){
//        getline(output,temp1);
output<<temp1;

input>>temp1;
    }
input.close();output.close();

}

void displayus(){
  char c;
  char answer;
  int ch;
  AVL<string> co;
dictionary dic;
  ifstream file("dics.txt",ios::app);
ofstream files;
while(!file.eof()){
        file.ignore();
        if(!file.eof()){
    file.getline(dic.word,50,':');
    file.ignore(200,'.');
   co.insert(dic.word);
        }
    cout<<dic.word<<endl;;
}
  	  file.close();

  do
  {
      cout<<"*********************************";
	  cout<<"\n 1.Display the AVL tree.";
	  cout<<"\n 2.Search a keyword";
	  cout<<"\n 3.Logout";
	  cout<<"\n Enter your choice : ";
	  cin>>ch;

        if(ch==1){
		co.display();	}
      	else if(ch==2){
      	    int x;
        ifstream file("dics.txt",ios::app);
                string select,temp;
		co.search_value(select);
		while(!file.eof()){
                file.ignore();
                getline(file,temp,':');
       x= select.compare(temp);
            if(x==0){
            //    file.getline(dic.pron,60);
              //  file.getline(dic.type,4);
                file.getline(dic.meaning,200,'.');
               // file.ignore();
                cout<<dic.meaning;
                break;
            }else
                file.ignore(200,'.');
		}
		              	  file.close();

		 }
		//else if(ch==3){
	//login();
		// }
      	else{
      	  cout<<"\n Wrong choice ! "; }
	  cout<<"\n Are you sure you want to Logout? (y/n): ";
	  cin>>c;
  	  }
  	  while(c=='n'||c=='N');

  }
  //
  //        DISPLAY ADMIN
  //
  //


void displayadmin(){
  char c;
  char answer;
  int ch;
  AVL<string> co;
  dictionary dic;
  //dicindex<st index;
  ifstream file("dics.txt",ios::app);
ofstream files;
while(!file.eof()){
        file.ignore();
        if(!file.eof()){
    file.getline(dic.word,50,':');
    file.ignore(200,'.');
    if(co.src1(dic.word)==0){
    co.insert(dic.word);}

        }
    cout<<dic.word<<endl;;
}
  	  file.close();

  do
  {
      cout<<"*********************************";
	  cout<<"\n 1.Insert a keyword in AVL tree.";
	  cout<<"\n 2.Display the AVL tree.";
	  cout<<"\n 3.Search a keyword";
	  cout<<"\n 4.Delete a keyword.";
	  cout<<"\n 5.Edit a keyword.";
	  cout<<"\n 6.Logout.";
	  cout<<"\n Enter your choice : ";
	  cin>>ch;
	  if(ch==1)
	  {
      	do
		{
		files.open("dics.txt",ios::app);
		//dicindex index;
		//int pos;

		cout<<"enter a word: ";
		cin.ignore();
		//pos=files.tellp();
	 cin.getline(dic.word,50,'\n');
	 cout<<"enter meaning: ";
	 cin.getline(dic.meaning,200,'\n');
	 files<<dic.word<<":"<<dic.meaning<<".";
		co.insert(dic.word);
		cout<<"\n Do you want to add another word?(y/n)";
		cin>>answer;
		}while(answer=='y'||answer=='Y');
		files.close();
		}
      	else if(ch==2){
		co.display();
		}
      	else if(ch==3){
            	    int x;
        ifstream file("dics.txt",ios::in);
        ofstream files("copy.txt",ios::out|ios::in);
                string select,temp;
		co.search_value(select);
		while(!file.eof()){
                file.ignore();
                getline(file,temp,':');
       x= select.compare(temp);
            if(x==0){
            //    file.getline(dic.pron,60);
              //  file.getline(dic.type,4);
                file.getline(dic.meaning,200,'.');

                cout<<dic.meaning;
                break;
            }else
                file.ignore(200,'.');
		}
                            files.close();
		              	  file.close();
		 }else if(ch==4){
		      string temp1,temp2;
		     ifstream input("dics.txt",ios::in);
        ofstream output("copy.txt",ios::out);
			string y;

	  			co.search_value(y);
	  				  		//	dic.word=y;
co.remove(y);
    cout<<y<< " removed successfully";


//copy(input,output,y);


			input.close();
			output.close();
		}
		else if(ch==5){
		string y;
	  	string t;
	  		  	co.search_value(y);
	  	cout<<"\n Enter new value:";
	  	cin.ignore();
	  	cin.getline(dic.word,50,'\n');
	  	cout<<"\nEnter new type: ";
	  		  	cin.ignore();
	  	cin.getline(dic.type,4,'\n');
	  	cout<<"\nEnter new pron: ";
	  		  	cin.ignore();
	  	cin.getline(dic.pron,60,'\n');
	  	cout<<"\nEnter new meaning: ";
	  		  	cin.ignore();
	  	cin.getline(dic.meaning,200,'\n');
	  	t=dic.word;
			co.edit(y,t);
		}
		else if(ch==6){
		return;
		}
      	else{
      	  cout<<"\n Wrong choice ! "; }
	  cout<<"\n Do you want to continue? (y/n): ";
	  cin>>c;
  	  }
  	  while(c=='y'||c=='Y');

  	  file.close();

}
void login(){
int p=0;
  string us,pass;
  string usn[]={"Amanuel","Samuel","Danel"};
  string usp[]={"aaa","sss","ddd"};
  string adn[]={"Bamlak","Bambambam","Kidus"};
  string adp[]={"pgg","hh","jj"};
do{
	cout<<"\n Input user name: ";
	cin>>us;
	cout<<"\n Input password: ";
	cin>>pass;
	system("cls");
	for(int i=0;i<3;i++){
		if (pass==usp[i]&&us==usn[i]){
        displayus();
		}
		else
		p=2;}
	for(int i=0;i<3;i++){
		if (pass==adp[i]&&us==adn[i]){
        displayadmin();}
		else
		p=2;}
	if(p==2){
	cout<<"\n The username or password you gave were invalid";
	}
}while(p==0||p==2);
}
int main(){
    char ans;
    ofstream output("copy.txt",ios::app);
    do{
            system("cls");
         login();
 cout<<"exit program or login again Y/N"<<endl;
 cin>>ans;
    }while(ans=='y'||ans=='Y');
return 0;}
