#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MEMORY_ALLOCATION_ERROR "There was an error in memory allocation"
#define ADD_ELEM "At first, add one item at least!"

struct ArrayList{
	int* array;
	size_t capacity;
	size_t size;
};
typedef struct ArrayList ArrayList;
ArrayList list;

void init();
void add(int );
void insert(int ,int );
void size();
void remove_value(int ); // 'remove' method is found in stdio.h
void set(int ,int );
void get(int );
void print_menu();
void print();
int enter_int(char* msg);
int check();
void debug();

int main(){
	int item, index;
	int menubar;
	init();
	debug();
	printf("ArrayList\n\n");
	while (1) {
		print_menu();
		scanf("%d", &menubar);
		
		switch(menubar) {
			case 1:
				item = enter_int("\nEnter the number which you want to add: ");
					
				add(item);
				break;
			case 2:
				if (check() == 0) {
					printf(ADD_ELEM);
					continue;
				}
				index = enter_int("\nEnter the index in which you want to insert the item: ");
				item = enter_int("\nEnter the item: ");
				insert(index, item);
				break;
			case 3:
				size();
				break;
			case 4:
				if (check() == 0) {
					printf(ADD_ELEM);
					continue;
				}

				index = enter_int("\nEnter the index of element which you want to get: ");
				remove_value(index);
				break;
			case 5:
				if (check() == 0) {
					printf(ADD_ELEM);
					continue;
				}
				index = enter_int("\nEnter the index of element which you want to replace: ");
				item = enter_int("\nEnter the new value of the number: ");
				set(index, item);
				break;
			case 6:
				if (check() == 0) {
					printf(ADD_ELEM);
					continue;
				}
				index = enter_int("\nEnter the index of element which you want to get: ");
				get(index);
				break;		
		
			case 0:
				exit(0);
			default:
				printf("This operation doesn't exist. Try again!\n");
				continue;
		}
	}
}

void print_menu() {
	printf("\n\n\n~~~~~\n");
	if (check() != 0) {
		print();
	}
	printf("\nAvailable operations:\n\n");
	printf("1. Add new item\n");
	printf("2. Insert new item at specific index\n");
	printf("3. ArrayList's size\n");
	printf("4. Remove specific item\n");
	printf("5. Change specific item\n");
	printf("6. Get specific item\n");
	printf("0. Exit\n");
	printf("\nEnter the number:\t");
}

void init() {
	list.capacity = 0;
	list.size = 0;
}
int enter_int(char* msg) {
	int temp;
	printf("%s", msg);
	scanf("%d", &temp);
	return temp;
}

void add(int item) {
	// if size is 0
	if (list.size == 0) {
		// increasing size and capacity to 
		list.size = list.capacity = 1;
		// allocating memory
		list.array =(int* ) malloc(list.size * sizeof(int));
		if (list.array == NULL) {
			printf(MEMORY_ALLOCATION_ERROR);
			return;
		}
		// assign item to array
		list.array[0] = item;
	} else {
		// checking whether size and capacity equal
		if (list.size == list.capacity) {
			list.size++;
			list.capacity++;;
		}
		else {
			list.size++;
		}	
		// reallocating memory
		list.array = (int* ) realloc(list.array, list.size * sizeof(int));
		if (list.array == NULL) {
			printf(MEMORY_ALLOCATION_ERROR);
			return;
		}
		// assigning item to array
		list.array[list.size - 1] = item;
	}
	printf("\nThe item was successfully added!");
} 

void remove_value(int index) {
	int old_value;
	// check index
	if ( (index < 0) || (index >= list.size) ) {
		printf("The index is out of ArrayList's bounds");
		return;	
	}
	// saving old value for loggin
	old_value = list.array[index];	
	// shift elements
	for (int i = index; i < list.size; i++) {
		list.array[i] = list.array[i + 1];
	}
	// reducing size
	list.size--;

	// reallocating memory
	list.array = realloc(list.array, list.size * sizeof(int));
	if (list.array == NULL) {
		printf(MEMORY_ALLOCATION_ERROR);
		return;
	}
	// log info
	printf("The item %d with index %d was deleted succesfully", old_value, index);
}

void debug() {
	add(1);
	add(22);
	add(33);
	add(44);
	add(5);
	add(66);
	add(7);
	size();
	print();
}

void get(int index) {
	// checking the index
	if ( (index < 0) || (index >= list.size)) {
		printf("The index is out of ArrayList's bounds");
		return;
	}
	// printing the item
	printf("arrayList[%d] = %d", index, list.array[index]);
}

void insert(int index, int item) {	
	// check index
	if (index == list.size) {
		printf("Add a new element instead!");
		return;
	}
	if ( (index < 0) || (index > list.size)) {
		printf("The index is out of ArrayList's bounds");
		return;
	}

	// increase size
	if (list.size == list.capacity) {
		list.size++;
		list.capacity++;;
	}
	else {
		list.size++;
	}
	// checking the index
	if ( (index < 0) || (index >= list.size)) {
		printf("The index is out of ArrayList's bounds");
		return;
	}	
	// printing the item
	printf("arrayList[%d] = %d", index, list.array[index]);
}
	// reallocating memory
	list.array = (int* ) realloc(list.array, list.size * sizeof(int));
	if (list.array == NULL) {
		printf(MEMORY_ALLOCATION_ERROR);
		return;
	}
	// shift elements
	for (int i = list.size - 1; i >= index; i--) {
		list.array[i + 1] = list.array[i];
	}
	// inserting the item
	list.array[index] = item;
	printf("The item %d was inserted at position %d", item, index);
}


void set(int index, int item) {	
	// checking the index
	if ( (index < 0) || (index >= list.size)) {
		printf("The index is out of ArrayList's bounds");
		return;
	}
	// saving the old value only for logging
	int old_value = list.array[index];
	// replacing item
	list.array[index] = item;
	// printing info
	printf("\nReplace %d[%d] to %d[%d]", old_value, index, item, index);
}


void size() {
	// printing the size
	printf("The size of ArrayList:\t");
	printf("%ld", list.size);
}

void print() {
	// printing array
	printf("\nYour Arraylist: [");
	for (int i = 0; i < list.size; i++) {
		printf("%d", list.array[i]);
		if (i != list.size - 1)
			printf(", ");
	}
	printf("]");
}

int  check() {
	// simple check whether arrayList has at lest one item or not
	if (list.size > 0)
		return 1;
	else
		return 0;
}