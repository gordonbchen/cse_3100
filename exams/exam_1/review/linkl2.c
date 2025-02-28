#include <stdio.h>
#include <stdlib.h>

typedef struct NodeT {
	struct NodeT* next;
	int val;
} Node;

Node* create_node(int val) {
	Node* node = malloc(sizeof(Node));
	node->next = NULL;
	node->val = val;
	return node;
}

void print(Node* head) {
	while (head != NULL) {
		printf("%d ", head->val);
		head = head->next;
	}
	printf("\n");
}

void destroy(Node* head) {
	Node* next;
	while (head != NULL) {
		next = head->next;
		free(head);
		head = next;
	}
}

Node* prepend(Node* head, Node* node) {
	if (head == NULL) {
		free(head);
		return node;
	}
	node->next = head;
	return node;
}

void prepend_inplace(Node** head, Node* node) {
	node->next = *head;
	*head = node;
}

Node* get_last(Node* head) {
	if (head == NULL) {
		return head;
	}
	while (head->next != NULL) {
		head = head->next;
	}
	return head;
}

Node* append(Node* head, Node* node) {
	Node* last = get_last(head);
	if (last == NULL) {
		free(head);
		return node;
	}

	last->next = node;
	return head;
}

Node* reverse(Node* head) {
	Node* prev = NULL;
	Node* curr = head;
	Node* next;
	while (curr != NULL) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}

Node* remove_val(Node* head, int val) {
	Node* prev = NULL;
	Node* curr = head;
	while (curr != NULL) {
		if (curr->val == val) {
			if (prev == NULL) {
				head = head->next;
			}
			else {
				prev->next = curr->next;
			}
			free(curr);
			return head;
		}
		prev = curr;
		curr = curr->next;
	}
	printf("%d not found in ll\n", val);
	return head;
}

int main() {
	Node* head = NULL;
	for (int i = 0; i < 5; ++i) {
		head = append(head, create_node(i));
		head = prepend(head, create_node(10+i));
		prepend_inplace(&head, create_node(100+i));
	}

	print(head);
	head = reverse(head);
	print(head);
	head = reverse(head);
	print(head);

	head = remove_val(head, 14);
	print(head);
	head = remove_val(head, 4);
	print(head);
	head = remove_val(head, 0);
	print(head);

	destroy(head);
}
