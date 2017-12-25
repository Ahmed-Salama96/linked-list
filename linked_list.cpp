//Linked-List – C++
#include<iostream>
#include<stdlib.h>
using namespace std;
typedef int EleType;
 struct node
	{
	  EleType data;
	  node *next;
	};
class LinkList{
private:
	node* L;// L pointer to the first node of the list
public:
	int Construct(EleType X);
	void Destroy(void);
	void PrintList(int choice);
	int InsertRear(EleType X);
	int InsertFront(EleType X);
	int InsertPos(EleType X,int pos);
	int DeleteRear(EleType *X);
	int DeleteFront(EleType *X);
	int DeletePos(EleType *X,int pos);
	int Find(EleType X);
};

int LinkList::Find(EleType X){
  node* P;
  P = L;
  while(P != NULL && P->data != X) {
	 P = P->next;
  }
  if(P!=NULL) return 1;
  else return 0;
}

int LinkList::Construct(EleType x){
	node * P;
	P=new node;
	if(P==NULL){
		//cout"Error\n";
		return 0;
	}
	else {
		P->data=x;
		P->next=NULL;
		L=P;
		return 1;
	}

}

void LinkList::Destroy(void){
node *P, *Q;

P = L;
while(P!=NULL){
	 Q = P->next;
	 delete(P);
	 P = Q;
}
}

void LinkList::PrintList(int choice){
node* P;
P=L;
if (P==NULL){
	 cout<<"Empty list\n";
}
else {
	 while(P!=NULL) {
		 if(choice==0)
			cout<<P->data;
		 else{
			cout<<"( "<<P<<" , "<<P->data<<" , ";
cout<<P->next<<" )"<<endl;
}
		P = P->next;
	 }
	 cout<<endl;
}
}

int LinkList::InsertRear(EleType X){
  node* P, *Q;

  P=L;
  while(P->next!=NULL) {
		P = P->next;
  }
  Q=new node;
  if (Q==NULL){
	 cout<<"Error\n";
	 return 0;
  }
		Q->data=X;
		Q->next=NULL;
		P->next=Q;
		return 1;
}


int LinkList::InsertFront(EleType X){
	node* P, *Q;
	P=L;

	Q=new node;
	if (Q==NULL){
		cout<<"Error\n";
		return 0;
	}
	Q->data=X;
	Q->next=P;
	L=Q;
	return 1;
}

int LinkList::InsertPos(EleType X,int pos){
	node* P, *Q;
	int i;
	int count=0;

	P=L;
	while(!P==NULL){
		count++;
		P=P->next;
	}
	if(pos>count||pos<0){
		cout<<"Invalid Position, list is "<<count<< " elements only\n";
		return 0;
	}
	else if(pos==count){
		int y;
		y=InsertRear(X);
		return y;
	}
	else if(pos==0){
		int y;
		y=InsertFront(X);
		return y;
	}
	else{
		Q=new node;
		if (Q==NULL){
			cout<<"Error\n";
			return 0;
		}
		Q->data=X;
		P=L;
		for(i=0;i<pos-1;i++)
			P=P->next;
		Q->next=P->next;
		P->next=Q;
		return 1;
	}
}


int LinkList::DeleteRear(EleType *X){
node *P, *Q;
P=L;
Q=P->next;
while(Q->next!=NULL){
		P = P->next;
		Q = Q->next;
}
		*X=Q->data;
		delete(Q);
		P->next=NULL;
		return 1;
}

int LinkList::DeleteFront(EleType *X){
	node* P, *Q;
	P=L;
	Q=P->next;
	*X=P->data;
	L=Q;
	delete(P);
	return 1;
}

int LinkList::DeletePos(EleType *X,int pos){
	node* P, *Q;
	int i;
	int count=0;

	P=L;
	while(P!=NULL){
		count++;
		P=P->next;
	}
	if(pos>=count||pos<0)	{
		cout<<"Invalid Position, list is"<<cout<<"elements only\n";
		return 0;
	}
	else if(pos==count-1){
		int y;
		y=DeleteRear(X);
		return y;
	}
	else if(pos==0){
		int y;
		y=DeleteFront(X);
		return y;
	}


else{
		P=L;
		for(i=0;i<pos-1;i++)
			P=P->next;
		Q=P->next;
		*X=Q->data;
		P->next=Q->next;
		delete(Q);
		return 1;
	}

}

int main(void)
{
	LinkList L;
	//Node* P;
	int i;
	int x;
	L.Construct(5);
	L.PrintList(0);
	for(i=1;i<3;i++)
	{
		L.InsertRear(i);
		L.InsertPos(1, 1);
		L.PrintList(0);
		L.InsertFront(i);
		L.InsertPos(i,i+1);
		L.PrintList(0);
	}
	L.InsertPos(100,6); 		L.PrintList(0);
	L.DeletePos(&x,6);  		L.PrintList(0);
	L.PrintList(1);
	x = L.Find(7);
	if(x)	cout<<"Found\n";
	else   cout<<"Not Found\n";

	L.DeleteFront(&x);			L.PrintList(0);
	cout<<"DelF X= "<<x<<endl;

	L.Destroy();
	return 0;
}
