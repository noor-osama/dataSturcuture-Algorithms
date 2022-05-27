#include<iostream.h>
#include<conio.h>
#include<string.h>

struct Student {
	char name [20];
	int id ;
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
return st;
}

Student arr [5];

void bubble (){
	int i =0 ;
	int swapped =1;
	Student temp ;
	int comp ;

		while(swapped){
			swapped=0;
			for(int j=0;j<4-i;j++){
			if (strcmp(arr[j].name , arr[j+1].name)>0){
			    swapped =1;
			    temp = arr[j];
			    arr[j] = arr[j+1];
			    arr[j+1] = temp;

			}

			}

		      i++;

		}

}

void merge_sort(int low , int high);
void merge (int low , int mid , int high );

void merge_sort(int low , int high){
	int mid ;
		if(low<high){
			mid = (low+high)/2;
			merge_sort(low,mid);
			merge_sort (mid+1 ,high);
			merge(low,mid,high);
	}
}

void merge (int low , int mid,int high){
	Student temp [5];
	int l1 ,l2,i;
	l1 = low;
	l2 = mid+1;
	i=low;
		while (l1<=mid && l2<=high){
			if (arr[l1].id < arr[l2].id){
				temp[i] = arr [l1];
				l1++;
				i++;
			}
			else {
			temp[i] = arr[l2];
			l2++;
			i++;
			}
	       //	}
		while (l1<= mid){
			temp[i] = arr[l1];
			l1++;
			i++;
		}
		while (l2<=high){
			temp[i] = arr[l2];
			l2++;
			i++;

		}
		for ( i = low ; i<=high ; i++){
			arr[i] = temp[i];
		}

} }

int binary(int low , int high , int key){
	int loc =-1 ;
	int mid ;
		while(low <=high && loc ==-1 ){
			mid =(low+high)/2;
				if (arr[mid].id == key ){
				loc = mid;
				}
				else if (arr[mid].id > key ){
				high = mid-1;
				}
				else if (arr[mid].id < key ) {
				low = mid +1;
				}
				}

                 return loc ;
		}






int main(){
clrscr();
int p ;
for (int x = 0 ;x<5 ;x++){
	arr[x] =FillStudent();
}
//merge_sort(0,4);
//merge(0,1,4);

bubble ();
//cout << "Enter key    " << endl;
//cin>>p;
//int location = binary(0,4,p);
//cout<<"location " <<location<<endl;

for(int y = 0 ; y<5 ; y++){
	cout<<"id :"<<arr[y].id <<endl;
	cout<<"namee"<<arr[y].name <<endl;
	}

getch();


}

