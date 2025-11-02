#include <stdio.h>

    //function declare
    void newBook(int isbns[], char titles[][100], float prices[], int quantities[], int *i);
    void processSale(int isbns [], int quantities [], int *i);
	void lowStockR (int quantities [], int isbns[], char titles[][100], float prices[], int *i);

int main(){
	
	int i=0;
	int found;
	int choice;
	char buy;
	int isbns_bookPurchase, copies_needed;
	int isbns[100];
    char titles[100][100];
    float prices[100];
    int quantities[100];

    do{
	
	printf("  =======  MAIN MENU  =======   \n");
	printf("1. Add New Book.\n");
	printf("2. Process a Sale.\n");
	printf("3. Generate Low-Stock Report.\n");
	printf("4. EXIT\n\n");
	scanf("%d", &choice);
	
	
	switch(choice){
		case 1:
		    newBook(isbns, titles, prices, quantities, &i);
	        break;
		       
		case 2:
			processSale (isbns, quantities, &i);
            break;
	    
	    
		case 3:
			lowStockR (quantities, isbns, titles, prices, &i);
			break;
		
		case 4:
			printf("\nGOODBYE!\n\n");
			break;
			
		default:
			printf("\nInvalid option choosed.\n\n");
    }
			   	
    } while(choice != 4);
    
    
    
	return 0;
}


    void newBook(int isbns[], char titles[][100], float prices[], int quantities[], int *i){
		int duplicate;
		do{
		duplicate = 0;
    	printf("Enter book's ISBN: ");
	    scanf("%d", &isbns[*i]); 
		
		int m;	    
	    for(m=0 ; m<*i ; m++){
	   		if(isbns[*i] == isbns[m]){
			    printf("Duplicate ISBN. Re-enter.\n\n");
			    duplicate = 1;
			}
		}
	    }while (duplicate != 0);
	    
	    
		printf("Enter book's title: ");
		scanf(" %[^\n]", &titles[*i]);  
		printf("Enter book's price: Rs. ");
        scanf("%f", &prices[*i]);
	    printf("Enter book quantity: ");
        scanf("%d", &quantities[*i]);
        (*i)++;
        printf("\nNew Book Added Successfully!\n\n");
	}
	
	
	
    void processSale(int isbns [], int quantities [], int *i){
    	int isbns_bookPurchase, copies_needed, j;
        char buy;
        
		printf("Enter ISBN for the book being purchased:  ");
		scanf("%d", &isbns_bookPurchase);
		
	    int found = 0;
		for(j=0 ; j<*i ; j++){
			if(isbns[j] == isbns_bookPurchase){
				found = 1;
				
				printf("Enter number of copies of the book being purchased:  ");
	        	scanf("%d", &copies_needed);
				
			   	if(quantities[j] >= copies_needed){
			   	    quantities[j] = quantities[j] - copies_needed;
			   	    printf("\n\nSale Processed Successfully!\n\n");
				} 
				else if(quantities[j] == 0){
					printf("\nThe book is Out of Stock!\n\n");
							//get out of the whole case2
				}
				else{
				    printf("\nThe number of copies requested the for the book %d to purchase is not available.\n", isbns[j]);
					printf("\nThe number of copies left in stock is %d", quantities[j]);
					printf("\nDo you want to buy %d copies? (Y/N):  ", quantities[j]);
					scanf(" %c", &buy);

						if(buy == 'Y' || buy == 'y'){
							quantities[j] = 0;
							printf("\n\nSale Processed Successfully!\n");
						}
						else if(buy == 'N' || buy == 'n'){
							return;
						}
						else{								
						    printf("\nInvalid Input. Enter (Y or N).\n\n");
						    return;
						}
		
				}
				
				return; 
		    }
	    }
			if(found == 0){
			    printf("\nISBN Not Found!\n\n");
			}
	}
	
	
	
	void lowStockR (int quantities [], int isbns[], char titles[][100], float prices[], int *i){
		int k;
		printf("\n\n");
		for(k=0 ; k<*i ; k++){
			if(quantities[k] < 5){
			   	printf("--> Title: %s\n   ISBNS: %d\n   Price: %f\n   Quantity left: %d\n\n", titles[k], isbns[k], prices[k], quantities[k]); 
			}
        }
        printf("\n\n");
    }
    
