/* Program to show doubly Linked-list implementation and various operations */ 

#include<stdio.h>
#include<stdlib.h>  

struct node {
	int data; 
	struct node *flink; //forward link
	struct node *blink; //backward link 

};

struct node *head = NULL;  

struct node *get_new_node(int data) 
{
	
	struct node *temp = (struct node *)malloc(sizeof(struct node)); 

	temp->data = data; 
	temp->flink = NULL; 
	temp->blink = NULL; 

	return temp;  
	
}

void print_list(void) 
{

	if(head == NULL) {
		printf("list is empty \n"); 
	return ; 	
	}
	
	struct node *temp = head;
	printf("Updated list is : "); 
	while(temp != NULL) {
		printf("%d \t", temp->data); 	
		temp = temp->flink; 
	}

	printf("\n");

}

void insert_at_beginning(void) 
{

	int data; 
	printf("Enter data to be inserted : ");
	scanf(" %d", &data); 

	struct node *newnode = get_new_node(data); 

	if(head == NULL) {
		head = newnode; 
	}
	else {
		head->blink = newnode; 
		newnode->flink = head; 
		head = newnode; 
	}

}

void insert_at_end(void)
{
	int data; 
	printf("Enter element to be inserted : ");
	scanf(" %d", &data ); 
	
	struct node *newnode = get_new_node(data);

	if(head == NULL) {
		head = newnode; 
	}
	else {
		struct node *temp = head; 
		while(temp->flink != NULL) {
			temp = temp->flink; 	
	}
	temp->flink = newnode; 
	newnode->blink = temp; 
	}
}

void insert_at_npos() 
{
	int data, pos, i; 
	
	struct node *newnode, *temp_next, *temp_prev; 

	printf("Enter element to be inserted : "); 
	scanf(" %d", &data); 
	printf("Enter position at which element to be inserted : "); 
	scanf(" %d", &pos);    

	newnode = get_new_node(data); 
	
	temp_next = head; 
	temp_prev = head;  
	temp_next = temp_next->flink;   

	for (i = 1; i<pos-1; i++) {
		temp_prev = temp_prev->flink; 
		temp_next = temp_next->flink;  
	}
	newnode->flink = temp_next; 
	temp_next->blink = newnode; 
	
	newnode->blink = temp_prev;  	
	temp_prev->flink = newnode; 	

}

void delete_at_beginning(void)
{

	struct node *temp; 
	
	if(head == NULL) {
		printf("List is empty \n"); 
	}
	else {
		temp = head; 	
		head = temp->flink; 
		free(temp); 		
	}

}

void delete_at_end(void) 
{

	struct node *temp, *temp_prev; 
	if(head == NULL) {
		printf("list is empty \n");
		}
	else {
		temp = head; 
		while (temp->flink != NULL) {
			temp = temp->flink; 
		}
		temp_prev = temp->blink; 
		temp_prev->flink = NULL; 
		free(temp); 		
	}

}

void delete_at_npos(void) 
{
	int pos, i;
	struct node *temp_prev, *temp_curr, *temp_next;  	
	
	printf("Enter position at which element is to be deleted : "); 
	scanf(" %d", &pos); 
	
	if(head == NULL) {
		printf("List is empty \n"); 
	}
	else {
		temp_prev = head; 
		for(i = 1; i< pos-1; i++)	{
			temp_prev = temp_prev->flink; 
		}	
		temp_curr = temp_prev->flink; 
		temp_next = temp_curr->flink; 	

		temp_prev->flink = temp_next; 
		temp_next->blink = temp_prev; 
		
		free(temp_curr); 
	}

}

void reverse_print(void)
{
	struct node *temp = head; 

	while (temp->flink != NULL) {
		temp = temp->flink; 
	}
	
	while(temp != NULL) {
		printf(" %d \t", temp->data);
		temp = temp->blink; 	
	}	
	printf("\n");
}

void operation_handler(char ch) 
{
	switch(ch) {
	case 'a' :
	case 'A' : 
		insert_at_beginning();
		print_list();   
		break; 
	case 'b' :
	case 'B' : 
		insert_at_end(); 
		print_list();
		break;  
	case 'c' :
	case 'C' : 
		insert_at_npos(); 
		print_list(); 
		break; 
	case 'd' :
	case 'D' :
		delete_at_beginning();
		print_list();  
		break; 
	case 'e' :
	case 'E' :
		delete_at_end(); 
		print_list(); 
		break; 
	case 'f' :
	case 'F' :
		delete_at_npos(); 
		print_list(); 
		break; 
	case 'g' :
	case 'G' :
		reverse_print();
		break; 
	case 'x' :
	case 'X' :
		printf("Received input to exit and exiting!! \n");
		exit(0); 
	default : 
		printf("Invalid input, please enter valid option from Menu \n");
		exit(0);
	};
}

void print_menu(void) 
{

	printf("**********************************Menu**********************************  \n"); 
	printf("a or A: Insert element at the beginning \n"); 
	printf("b or B: Insert element at the end \n"); 
	printf("c or C: Insert element at nth position \n");
	printf("d or D: Delete element at the beginning \n");   
	printf("e or E: Delete element at the end \n"); 
	printf("f or F: Delete element at nth position \n");  
	printf("g or G: Revese print \n");  
	printf("Forward prints the list at end of each operation by default \n"); 
	printf("x or X: For Exit \n");	
}
 
int main()
{

	char oper;  

	printf("************************Program for Doubly Linked List******************* \n"); 
	print_menu();	 

	do {	
	printf("Enter operation to be performed :  ");
	scanf(" %c", &oper); //Add a space before conversion charecter when multiple charecters are expected to read from keyboard
	
	operation_handler(oper);
	printf("Do you wish to continue? (y/n) : ");  	
	scanf(" %c", &oper);
	} while(oper == 'y' || oper == 'Y'); 

	printf("Exiting program \n");
 
}

