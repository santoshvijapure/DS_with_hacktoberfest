#include <stdio.h>
#include <stdlib.h>

#define NULL_DEQUE_ERR		printf("Error! Deque is NULL.\n");
#define MEM_ALLOC_ERR		printf("Error! Could not allocate memory.\n");
#define EMPTY_DEQUE_ERR		printf("Error! Deque is empty.\n");

typedef struct Deque Deque;
typedef struct Element Element;

struct Deque {
	Element* front;
	Element* back;
};

struct Element {
	int data;
	Element* next;
	Element* prev;
};

Deque* newDeque() {
	Deque* deque = malloc(sizeof(Deque));

	if (deque != NULL) {
		deque->front = NULL;
		deque->back = NULL;

		return deque;
	}
	else {
		MEM_ALLOC_ERR
		return NULL;
	}
}

int back(Deque* deque) {
	if (deque != NULL) {
		if (deque->back != NULL)
			return deque->back->data;
		else {
			printf("Error! Deque back is NULL.\n");
			return 0;
		}
	}
	else {
		NULL_DEQUE_ERR
		return 0;
	}
}

void push_back(int data, Deque* deque) {
	if (deque != NULL) {
		Element *e = malloc(sizeof(Element));

		if (e != NULL) {
			e->data = data;
			e->next = NULL;

			// If deque is NULL
			if (deque->front == NULL) {
				e->prev = NULL;
				deque->front = e;
			} else {
				deque->back->next = e;
				e->prev = deque->back;
			}

			// back points to the new element
			deque->back = e;

		}
		else
			MEM_ALLOC_ERR
	}
	else
		NULL_DEQUE_ERR
}

void pop_back(Deque* deque) {
	if (deque != NULL) {
		if (deque->back != NULL) {
			// If last element
			if (deque->back->prev == NULL) {
				free(deque->back);

				// Deque initial state (empty)
				deque->back = NULL;
				deque->front = NULL;
			} else {
				Element *aux = deque->back;

				deque->back = deque->back->prev;
				// Since its the most recent element, it must point to NULL
				deque->back->next = NULL;

				free(aux);
			}
		}
		else
			EMPTY_DEQUE_ERR
	}
	else
		NULL_DEQUE_ERR
}

int front(Deque* deque) {
	if (deque != NULL) {
		if (deque->front != NULL)
			return deque->front->data;
		else {
			printf("Error! Deque front is NULL.\n");
			return 0;
		}
	}
	else {
		NULL_DEQUE_ERR
		return 0;
	}
}

void push_front(int data, Deque* deque) {
	if (deque != NULL) {
		Element *e = malloc(sizeof(Element));

		if (e != NULL) {
			e->data = data;
			// First element
			e->prev = NULL;

			// If empty
			if (deque->front == NULL) {
				deque->back = e;
				e->next = NULL;
			}
			else {
				e->next = deque->front;
				deque->front->prev = e;
			}

			deque->front = e;
		}
		else
			MEM_ALLOC_ERR
	}
	else
		NULL_DEQUE_ERR
}

void pop_front(Deque* deque) {
	if (deque != NULL) {
		if (deque->front != NULL) {
			// If last element
			if (deque->front->next == NULL) {
				free(deque->front);

				deque->front = NULL;
				deque->back = NULL;
			} else {
				Element *aux = deque->front;

				// aux->next is now the first element
				deque->front = deque->front->next;
				deque->front->prev = NULL;

				free(aux);
			}
		}
		else
			EMPTY_DEQUE_ERR
	}
	else
		NULL_DEQUE_ERR
}

// Some examples
int main() {
	Deque* deque = newDeque();
	int i;

	for (i = 0; i<10; i++)
		push_back(i, deque);

	printf("Deque back to front (push_back): \n");

	for (i = 0; i<10; i++) {
		printf("%d ", back(deque));
		pop_back(deque);
	}

	printf("\n");

	for (i = 0; i<10; i++)
		push_front(i, deque);

	printf("\nDeque front to back (push_front): \n");

	for (i = 0; i<10; i++) {
		printf("%d ", front(deque));
		pop_front(deque);
	}

	printf("\n");

	return 0;
}
