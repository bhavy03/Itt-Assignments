#include <stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node *next;
};
struct Node *insertAtEnd1(struct Node *head,int data) {
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->next = NULL;
	newNode->data = data;
	if(head == NULL) {
		return newNode;
	}
	struct Node *ptr = head;
	while(ptr->next !=NULL) {
		ptr = ptr->next;
	}
	ptr->next = newNode;
	return head;
}
struct Node *insertAtEnd2(struct Node *head,int data) {
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->next = NULL;
	newNode->data = data;
	if(head == NULL) {
		return newNode;
	}
	struct Node *ptr = head;
	while(ptr->next !=NULL) {
		ptr = ptr->next;
	}
	ptr->next = newNode;
	return head;
}
void display(struct Node *head) {
	struct Node *ptr = head;
	if(head == NULL) {
		printf("NULL");
	}
	while(ptr != NULL) {
		printf("%d",ptr->data);
		ptr = ptr->next;
	}
}
void rotate(struct Node *head1,struct Node *head2,int k,int length) {
	struct Node *ptr = head1;
	while(ptr->next != NULL) {
		ptr = ptr->next;
	}

	ptr->next = head2;
	struct Node *headptr = head1;
	int index = 0;
	int value = 0;

	if(k>length) {
		value = k%length;
	} else {
		value = k;
	}

	while(index<value) {
		headptr = headptr->next;
		index++;
	}

	while(length > 0) {
		printf("%d ",headptr->data);
		headptr = headptr->next;
		length--;
	}
}
int findLength(struct Node *head1) {
	struct Node *ptr = head1;
	int length = 0;
	while(ptr != NULL) {
		ptr = ptr->next;
		length++;
	}
	return length;
}
int main()
{
	struct Node *head1 = NULL;
	struct Node *head2 = NULL;
	int n;
	scanf("%d",&n);
	int data = 0;
	for(int i = 0; i<n; i++) {
		scanf("%d",&data);
		head1 = insertAtEnd1(head1,data);
		head2 = insertAtEnd2(head2,data);

	}

	int k ;
	scanf("%d",&k);

	int length = findLength(head1);
	printf("Output:\n");
	rotate(head1,head2,k,length);

	return 0;
}
