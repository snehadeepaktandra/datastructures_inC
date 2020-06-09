/* Program to show single Linked-list implementation and various operations */ 

#include<stdio.h>
#include<stdlib.h>  

struct node {
	int data; 
	struct node *link; 
};

struct node *head = NULL; 

struct node *get_new_node(int value) 
{ 
	struct node *newnode = (struct node *)malloc(sizeof(struct node));  
	newnode->data = value; 
	newnode->link = NULL; 

	return newnode; 
}

void print_list()
{
	struct node *temp; 
	temp = head; 
	printf("Updated list is : ");
	while(temp != NULL)
	{
		printf("%d \t", temp->data); 
		temp = temp->link; 	
	}
	printf("\n"); 
}

void insert_at_beginning(void) 
{
	int value;
	struct node *temp;  
	printf("Enter value to be inserted : ");
	scanf(" %d", &value); 

	temp = get_new_node(value);  
	
	if(head == NULL) {
		head = temp; 	
	}
	
	else {
	temp->link = head; 
	head = temp; 
	}
} 

void insert_at_end(void) 
{

	int value;
	struct node *newnode, *temp;  
	printf("Enter value to be inserted : ");
	scanf(" %d", &value); 

	newnode = get_new_node(value); 
	
	if(head == NULL) {
		head = newnode; 	
	}

	else { 
	temp = head; 
	while(temp->link != NULL) {
	temp = temp->link;
	}
	temp->link = newnode; 
	}
}

void insert_at_npos(void)
{
	int value,pos,i; 
	struct node *newnode, *temp; 
	
	printf("Enter value to be inserted : ");
	scanf(" %d", &value); 
	printf("Enter position at which value to be inserted : ");
	scanf(" %d", &pos); 

	newnode = get_new_node(value); 
	
	temp = head; 
	for(i = 1; i < pos-1; i++) {
		temp = temp->link; 
	}

	newnode->link = temp->link; 
	temp->link = newnode; 
}

void delete_at_beginning(void) 
{
	struct node *temp; 

	if (head == NULL) {
		printf("list is empty \n"); 
	}
	else {
	temp = head; 
	head = temp->link; 
	free(temp); 
	}

}

void delete_at_end(void) 
{	
	struct node *current, *prev; 

	if (head == NULL) {
	printf("list is empty \n"); 
	return;  
	}

	//below if condition is to address when list contains only one element --> This condition doesn't seem working. 
	if(head->link == NULL) {
		current = head; 
		head == NULL; 
		free(current); 
		return; ; 	
	}
	current = head;  
	prev = head; 
	current = current->link;
	while(current->link != NULL) {
		current = current->link; 
		prev = prev->link; 
	}	
	prev->link = NULL; 
	free(current);   
}

void delete_at_npos(void) 
{
	int pos,i;
	struct node *current, *prev;  

	if(head == NULL) {
	printf("list is empty \n"); 
	}

	else {
	printf("Enter Position at which element is to be deleted : "); 
	scanf(" %d", &pos);
	
	current = head; 
	prev = head; 
	current = current->link; 	
	for(i = 1; i < pos-1; i++)  {
		current= current->link; 
		prev = prev->link; 
	}
	prev->link = current->link; 
	free(current); 					
	 
	}
}

void reverse_iterative(void) 
{
	struct node *prev, *current, *next; 

	if(head == NULL) {
		printf("List is empty \n");  	
	}

	else {
		current = head;  
		prev = NULL;  

		while(current != NULL) {
			next = current->link; 
			current->link = prev; 
			prev = current; 
			current = next; 
		}
		head = prev; 
	}
}

void reverse_recursive(struct node *temp) 
{
	if(temp->link == NULL) {
		head = temp; 
		return; 
	}	

	reverse_recursive(temp->link); 
	struct node *next = temp->link; 
	next->link = temp; 
	temp->link = NULL; 
}

void reverse_print_recursion(struct node *temp)
{
	if (temp == NULL) {
	return; 
	}
	reverse_print_recursion(temp->link); 
	printf("%d \t", temp->data); 
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
		reverse_iterative();
		print_list(); 
		break; 
	case 'h' :
	case 'H' :
		reverse_recursive(head); 
		print_list();  
		break; 
	case 'i' :
	case 'I' :
		printf("Printing in reverse order using recursion :  \n"); 			
		reverse_print_recursion(head); 
		printf("\n");
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
	printf("g or G: Reverse linked list using iterative solution \n"); 
	printf("h or H: Reverse linked list using recurssion solution \n");
	printf("i or I: Print linked list from the end - No reversal \n"); 
	printf("Prints the list at end of each operation by default \n"); 
	printf("x or X: For Exit \n");	
}
 
int main()
{

	char oper;  

	printf("************************Program for Single Linked List******************* \n"); 
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

