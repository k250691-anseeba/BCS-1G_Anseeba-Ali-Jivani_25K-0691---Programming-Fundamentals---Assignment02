# include <stdio.h>

	//functions declare
	void push (int stack[], int *i, int maxSize);
    void pop (int stack[], int *i);
    void peek (int stack[], int *i);
    void display (int stack[], int *i, int maxSize);
    
    
int main(){
	    
	int stack[100];
	int choice;
	int i = 0 ;     //i represents the next empty index. right now since stack is empty index i=0 is the free space to add new element
	int maxSize;
			
    printf("Enter the number of elements you want in your stack:  ");
    scanf("%d", &maxSize);	    
	printf("\n\n");
	
	do{
	    
	    printf("===== MAIN MENU FOR STACK UPDATION =====\n");
	    printf("Enter your desired operation option:  \n");
	    printf("1) PUSH: Insert an element into the stack\n");
	    printf("2) POP: Remove the top element from the stack\n");
	    printf("3) PEEK: Display the top element without removing it\n");
	    printf("4) DISPLAY: Show all elements currently in the stack\n");
	    printf("5) EXIT\n\n");
	    scanf("%d", &choice);
	    
	    switch(choice){
	    	case 1: 
	    	    push(stack , &i , maxSize);
				break;
				
			case 2: 
			    pop(stack , &i);
				break;
				
			case 3:
				peek(stack, &i);
				break;
			case 4:
				display(stack, &i, maxSize);
				break;
			case 5:
				printf("\n\nGOODBYE!\n\n\n");
				break;
			default: printf("Invalid option choice entered.");
		}
			
	} while (choice != 5);
	
	
	
	return 0;
}

    //functions define
    
    void push(int stack[] , int *i, int maxSize){

    	if (*i<maxSize){
    		int element;
    	    printf("\n\nEnter an element to your stack:   ");
	        scanf("%d", &element);
	        stack[*i] = element;
	        (*i)++;
    	    printf("\nElement '%d' added successfully!\n\n", element);
        }
        else{
        	printf("Stack Overflow Detected. No space to add elements to the stack.\n\n");
		}
		
	}
	
	void pop(int stack [] , int *i){
		
	    if(*i>0){	        
	        (*i)--;
		    printf("\nTop most element removed successfully!\n\n");
		}
		else{
			printf("Stack Underflow Detected. Stack is empty. No elements remaining to remove from the stack.\n\n");			
		}
	}
	
	void peek(int stack [] , int *i){
        if(*i>0){
        	//i-1 indicates top value (since i is next free index, subtracting 1 will give the last filled index which is top value in stack)
		    printf("\n\nPeek element is: %d\n\n", stack[*i-1]);			    
		}
	    else{
			printf("Stack is empty\n\n");
		}
	}
	
	void display(int stack [] , int *i, int maxSize){
		int j;
		printf("\n\nDisplaying the stack: \n\n");
		for(j=(maxSize-1) ; j>=0 ; j--){
			if(j>((*i)-1)){
			    printf("   |       |  \n");
			    printf("   |-------|  \n");
			}
		
		    else{
		    	printf("   |   %d   |   \n", stack[j]);
			    printf("   |-------|  \n");
		    }
		}
		printf("\n\n");
	}
	
