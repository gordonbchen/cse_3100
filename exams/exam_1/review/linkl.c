#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct NodeT {
	struct NodeT* next;
	int val;
} Node;

void print_ll(Node* head) {
	while (head != NULL) {
		printf("%d ", head->val);
		head = head->next;
	}
	printf("\n");
}

Node* create_node(int val) {
	Node* n = malloc(sizeof(Node));
	assert(n != NULL);

	n->val = val;
	n->next = NULL;
	return n;
}

Node* prepend(Node* head, Node* node) {
	node->next = head;
	return node;
}

Node* append(Node* head, Node* node) {
	if (head == NULL) {
		free(head);
		return node;
	}
	
	Node* curr = head;
	while (curr->next != NULL) {
		curr = curr->next;
	}
	curr->next = node;
	return head;
}

void destroy(Node* head) {
	Node* next;
	while (head != NULL) {
		next = head->next;
		free(head);
		head = next;
	}
}

int main() {
	Node* head = create_node(0);
	for (int i = 1; i < 5; ++i) {
		head = append(head, create_node(i));
	}
	for (int i = 1; i < 5; ++i) {
		head = prepend(head, create_node(i));
	}
	print_ll(head);

	destroy(head);
	head = NULL;
};
