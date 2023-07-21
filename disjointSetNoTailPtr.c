#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct header *head;
	struct node *next;
}node;

typedef struct head{
	struct node *rep;
}header;

typedef struct find{
	int rep;
	int indx;
}findNode;

//Linked List Implementation - without tail pointer
void MakeSet(int n,header **ptr){		//Time Complexity of MakeSet - O(n)
	for(int i=0;i<n;i++){
		ptr[i] = malloc(sizeof(header));
		node *temp = malloc(sizeof(node));
		temp->data = i+1;
		temp->next = NULL;
		ptr[i]->rep = temp;
		temp->head = ptr[i]; 
	}
}

findNode *Find(header **ptr,int n,int s){
	findNode *temp = malloc(sizeof(findNode));
	temp->indx = temp->rep = 0;
	for(int i=0;i<n;i++){
		node *head = ptr[i]->rep;
		while(head!=NULL){
			if(head->data == s){
				temp->indx = i;
				temp->rep = ptr[i]->rep->data;
				return temp;
			}
			head = head->next;
		}
	}
	return temp;
}

void Union(header **ptr,int n,int a,int b){
	findNode *node1 = Find(ptr,n,a);
	findNode *node2 = Find(ptr,n,b);
	
	if(node1->indx == node2->indx)
		return;
		
	node *pt = ptr[node1->indx]->rep;
	while(pt->next!=NULL)
		pt=pt->next;
	pt->next = ptr[node2->indx]->rep;
	ptr[node2->indx]->rep = NULL;
	
	return;	
			
}

int main(){
	int n=5;
	header *ptr[n];
	MakeSet(n,ptr);
	
	for(int i=0;i<n;i++){
		printf("%d ",ptr[i]->rep->data);
	}
	
	printf("\n%d",Find(ptr,n,2)->rep);
	
	Union(ptr,n,1,3);
	
	printf("\n%d",Find(ptr,n,1)->rep);
	printf("\n%d",Find(ptr,n,3)->rep);
	
	return 0;
}
