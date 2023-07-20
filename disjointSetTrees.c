#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	int rank;
	struct node *parent;
}node;

node *MakeSet(int n){
	node *temp = malloc(sizeof(node));
	temp->data = n;
	temp->rank = 0;
	temp->parent = temp;
	
	return temp;
}

node *FindSet(node *node){
	if(node != node->parent)
		node->parent = FindSet(node->parent); //Path Compression Method
		
	return node->parent;
}

void UnionSet(node *node1,node *node2){
	node *root1 = FindSet(node1);
	node *root2 = FindSet(node2);
	
	if(root1==root2)					//Union by rank - Attach the tree with smaller rank to the root of the tree with the larger rank
		return;
	
	if(root1->rank > root2->rank)
		root2->parent = root1;
	else if(root1->rank < root2->rank)
		root1->parent = root2;
	else{
		root2->parent = root1;
		root1->rank++;
	}
}

int main(){
	int n = 10;
	node *ptr[n];
	
	for(int i=0;i<n;i++){
		ptr[i] = MakeSet(i+1);
	}
	
	for(int i=0;i<n;i++){
		printf("%d ",ptr[i]->data);
	}
	
	printf("\nFind of 3: %d ",FindSet(ptr[2])->data);
	printf("Find of 5: %d ",FindSet(ptr[4])->data);
	
	UnionSet(ptr[1],ptr[2]);
	UnionSet(ptr[3],ptr[4]);
	UnionSet(ptr[1],ptr[3]);
	
	printf("\nFind of 1: %d ",FindSet(ptr[0])->data);
	printf("\nFind of 2: %d ",FindSet(ptr[1])->data);
	printf("\nFind of 3: %d ",FindSet(ptr[2])->data);
	printf("\nFind of 4: %d ",FindSet(ptr[3])->data);
	printf("\nFind of 5: %d ",FindSet(ptr[4])->data);
	printf("\nFind of 6: %d ",FindSet(ptr[5])->data);
	
	return 0;
	
}
