#include <iostream.h>
#include<conio.h>
#include<string.h>

struct Student {

	int id ;
	char name[20];
};


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
	Node* prev ;
	Node* next ;

};

Node* head  ;
Node* tail  ;

//Node createNode (Student st);
Node* createNode (Student st){

	Node* ptr ;
	ptr = new (Node);
	if(ptr){
	ptr->st.id = st.id ;
	strcpy(ptr->st.name , st.name);
	ptr->prev = NULL ;
	ptr->next = NULL ;
	}
     return ptr ;

}
int addNode(Student st ){
	int ret = 0 ;
	Node* ptr ;
	ptr = createNode(st);
	if(ptr){
		if(head){
		tail->next = ptr ;
		ptr->prev = tail ;
		tail = ptr ;
		}
	else head = tail = ptr ;
	}
	else return ret;
	ret = 1 ;
	return ret ;
}

Node* Search (Student st){
	Node* ptr;
	ptr=head;
	while(ptr->st.id != st.id &&ptr){
		ptr=ptr->next;
	}
	return ptr ;
}

/*int UpdateNode(student d)
{
	int retval = 0;
	cout << "Please Enter Student Number ID : " << endl;
	cin >> d.id;
	Node* ptr;
	ptr = head;
	while (ptr->st.id != st.id && ptr)
	{
		ptr = ptr->pnext;
		if (ptr->d.id != st.id)
		{
			cout << "Please Enter New ID" << endl;
			cin >> st.id;
			cout << "Please Enter New Name" << endl;
			//cin >> st.name;

			break;
		}
		retval = 1;
	}
	return retval;
}*/
void free (){
	Node* ptr ;
	while(head){
		ptr=head;
		head = head->next ;
		delete(ptr);
	}
	tail= NULL ;
}
int insertNode (Student st , int loc){

	int ret = 0;
	Node* ptr , *current ;
	ptr = createNode(st);
	if (ptr){
		if(!head){
		head = tail = ptr ;
		}
		else{ //LIST
			if (loc == 0){
			ptr->next = head ;
			head->prev = ptr ;
			head = ptr;
			}
		else{
		current = head ;
		for(int i =0 ; i<loc-1 && current ; i++){
		current = current->next;
		}

		if(current == tail || current == NULL){
			ptr->prev = tail;
			tail->next = ptr ;
			tail = ptr ;
		}
		else {
		ptr->next = current->next ;
		current->next->prev =ptr ;
		current ->next = ptr ;
		ptr -> prev = current ;
		}
	}
}
		ret = 1 ;
}
		return ret ;
}

void Print(){
	Node* ptr ;
	ptr=head ;
	while(ptr != tail){
		PrintStudent (ptr->st);
		ptr = ptr->next;
	}
	PrintStudent (ptr -> st);
}
void PrintMenu (){
	cout << " 1 ==> ADD NODE " << endl ;
	cout << " 2 ==> INSERT NODE " << endl ;
	cout << " 3 ==> UPDATE NODE " << endl ;
	cout << " 4 ==> DELETE ALL NODES " << endl ;
	cout << " 5 ==> SEARCH NODE BY ID " << endl ;
}

int main (){
int c;
Student test ;
int loc ;
//int d ;
		clrscr ();
		PrintMenu ();
		cin>>c;
		switch (c) {
case 1 :
			test = FillStudent ();
			addNode (test);
			Print();
			break ;
case 2 :
			cout<<"ENTER LOCATION "<< endl;
			cin >>loc;
			test = FillStudent ();
			insertNode (test,loc);
			Print();
			break;
case 3 :
			UpdateNode(test);
			break;
case 4 :
			free ();
			break ;
case 5 :
			test = FillStudent () ;
//cin>>d;
			Search (test);
			break;
}
Print();
getch();
return 0 ;

}