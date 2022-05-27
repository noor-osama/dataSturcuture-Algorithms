#include<iostream.h>
#include<conio.h>
#include<string.h>


struct Student {
	int id ;
	char name [5];

} ;

Student FillStudent () {
Student s;
	char n [20];
	int d;
	Student st ;

	cout<<" Enter name :"<<endl;
	cin>>n;
	cout<<"Enter ID : "<< endl ;
	cin>>d;
	st.id = d;
	strcpy(st.name , n );
return st ;
}
void PrintStudent (Student s){
	int sid ;
	char sname [20] ;

cout<< "NAME " << s.name <<endl ;
cout<< "ID " << s.id << endl ;
}

struct Node {
	Student st ;
	Node* left ;
	Node* right ;
} ;
Node* CreateNode (Student st)
{
	Node* ptr ;
	ptr = new (Node);
		if(ptr){
			ptr->st.id = st.id;
			strcpy(ptr->st.name , st.name);
			ptr->left = NULL;
			ptr->right=NULL;
		}
		return ptr ;
}
Node* InsertNode (Node* tree , Student s ){
		if (tree == NULL ){
			tree = CreateNode ( s );
		}
		else if (tree->st.id > s.id) {
			tree->left = InsertNode(tree->left , s);
		}
		else
		{
			tree->right = InsertNode (tree->right , s);
		}
                return tree ;

}
void PostOrder (Node* node){ //left, right,node
	if (node == NULL){
		return;
	}
	//left
	PostOrder (node->left);
	//right
	PostOrder (node->right);
	//node
	PrintStudent (node->st);

}

void InOrder (Node* node){  //left,root,right
	if (node == NULL){
		return;
	}
	//left
	InOrder (node->left);
	//node
	PrintStudent (node->st);
	//right
	InOrder (node->right);

}

void PreOrder (Node* node){ //node , left.right
       if (node == NULL){
		return;
	}
	//node
	PrintStudent (node->st);
	//left
	InOrder (node->left);
	//right
	InOrder (node->right);


}



int main (){
clrscr();
Student st1;
Student st2;
Student st3;
Student st4;
Student st5;
	st1 = FillStudent ();
	st2 = FillStudent ();
	st3 = FillStudent ();
	st4 = FillStudent ();
	st5 = FillStudent ();


	Node * root = NULL;
	root = InsertNode (root , st1);
	root = InsertNode (root , st2);
	root = InsertNode (root , st3);
	root = InsertNode (root , st4);
	root = InsertNode (root , st5);
	cout << "InOrder Tree Traverse "<< endl;
	InOrder(root);
	cout << "InOrder Tree Traverse "<< endl;
	PreOrder(root);
	cout << "InOrder Tree Traverse "<< endl;
	PostOrder (root);
	getch();


}