#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct header *head;
	struct node *next;
}node;

typedef struct head{
	struct node *rep;
	struct node *tail;
}header;

//Linked List Implementation - with tail pointer
void MakeSet(int n,header **ptr){		//Time Complexity of MakeSet - O(n)
	for(int i=0;i<n;i++){
		ptr[i] = malloc(sizeof(header));
		node *temp = malloc(sizeof(node));
		temp->data = i+1;
		temp->next = NULL;
		ptr[i]->rep = temp;
		ptr[i]->tail = temp;
		temp->head = ptr[i]; 
	}
}

int Find(header **ptr,int n,int s){
	for(int i=0;i<n;i++){
		node *t = ptr[i]->rep;
		while(t!=NULL){
			if(t->data==s)
				return ptr[i]->rep->data;
			t=t->next;	
		}
	}
	return -1;
}

void Union(header **ptr,int n,int a,int b){
	int rep1 = Find(ptr,n,a);
	int rep2 = Find(ptr,n,b);
	int ab,cd;
	if(rep1!=rep2){					
		for(int i=0;i<n;i++){				 // use an extra variable to store the index of the head pointers {return from Find function}
										    // time complexity of the code reduces to O(1) when used {except the Find operation}
			if(ptr[i]->rep->data==rep1)
				ab=i;
			if(ptr[i]->rep->data==rep2)
				cd=i;
		}
		ptr[ab]->tail->next = ptr[cd]->rep;
		ptr[ab]->tail = ptr[cd]->tail;
		ptr[cd]->rep = ptr[cd]->tail = NULL;
	}
	return;	
			
}

int main(){
	int n=5;
	header *ptr[n];
	MakeSet(n,ptr);
	
	for(int i=0;i<n;i++){
		printf("%d ",ptr[i]->rep->data);
	}
	
	printf("\n%d",Find(ptr,n,2));
	
	Union(ptr,n,1,3);
	
	printf("\n%d",Find(ptr,n,1));
	printf("\n%d",Find(ptr,n,3));
	
	return 0;
}
