#include<iostream.h>
#include<string.h>
#include<conio.h>

struct Student  {

      char name [20];
      int id ;
};

struct Stack {

	Student st ;
	Stack* prev ;
};
Stack* head ;
int ar[5];//queue
int index;//queue

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

Stack* createNode (Student st){

	Stack* ptr ;
	ptr = new (Stack);
	if(ptr){
	ptr->st.id = st.id ;
	strcpy(ptr->st.name , st.name);
	ptr->prev = NULL ;
       //	ptr->next = NULL ;
	}
     return ptr ;

}
/*int addNode(Student st ){
	int ret = 0 ;
	Stack* ptr ;
	ptr = createNode(st);
	if(ptr){
		if(head){
		//tail->next = ptr ;
		//ptr->prev = tail ;
	       //	tail = ptr ;
		}
	else head = ptr ;
	}
	else return ret;
	ret = 1 ;
	return ret ;
}*/
//Queue

int enqueue(int d)
{
	int retval = 0;
	if (index < 5)
	{
		ar[index] = d;
		index++;
		retval = 1;
	}
	return retval;
}

int dequeue()
{
	int retval = -1;
	if (index >= 0)
	{
		retval = ar[index];
		ar[index] = ar[index + 1];
	}
	return retval;
}



int Push (Student s){

	int ret = 0;
	Stack* ptr ;
	ptr = new (Stack);
	if(ptr){
		ptr -> st.id = s.id;
		strcpy(ptr-> st.name , s.name);
			if (head == NULL){ //first element
				head=ptr;
				ptr->prev = NULL ;
			       //	ret = 1;
				}
			else{//ther is a list
			      ptr ->prev = head ;
			      head = ptr;
			      //ret=1;
				}   //else

				// head =ptr;
		       ret = 1;	}  //if(ptr)
		//ptr-> prev = null ;
		cout << "ID : " << ptr -> st.id << endl;
		cout << "Name : " << ptr -> st.name << endl;
		return ret ;
	}
void Print(){
	Stack* ptr ;
	  ptr=head ;
	while(head != NULL){
		PrintStudent (ptr->st);
		//ptr = ptr->next;
		head = ptr->prev ;
	}
	PrintStudent (ptr -> st);
}

int Pop (){
	int ret = -1;
	Stack *ptr ;
	if (head){ //there is a list
		ptr = head;
		head = ptr->prev;
		ret = ptr->st.id;
		delete (ptr);
		cout << "POPING" << endl;
		}

return ret ;
}

int main (){
Student test ;
//test.id = 1;
//strcpy(test.name , "n") ;
clrscr();
test =FillStudent ();
//addNode (test);
Push (test);
//Print();
Pop();
int ret = Pop();
cout << ret;
//Print();
getch();




return 0 ;
}






