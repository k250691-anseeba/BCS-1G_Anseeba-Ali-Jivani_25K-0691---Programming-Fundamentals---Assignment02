#include <stdio.h>
#include <string.h>

void info(char name[][100], char cnic[][20], int *i);
void display(char productCode[][4], int quantityLeft[], int pricePerproduct[]);
void update(char name[][100], char cnic[][20], int *i, char productCode[][4], int quantityLeft[], int pricePerproduct[], int *total_bill);
void cart(char name[][100], char cnic[][20], int *i, char productCode[][4], int quantityLeft[], int pricePerproduct[], int *total_bill);
void bill(char name[][100], char cnic[][20], int *i, int *total_bill, float *final_bill, char productCode[][4], int quantityLeft[], int pricePerproduct[]);
void invoice(char name[][100], char cnic[][20], int *i, int *total_bill, float *final_bill, char productCode[][4], int quantityLeft[], int pricePerproduct[]);
    

int main(){
	
	int choice;
	int i=0;
	char name[1000][100], cnic [1000][20];
	//data given in question for 4 products.
    char productCode[4][4] = {"001", "002", "003", "004"};
	int quantityLeft[4] = {50,10,20,8};
	int pricePerproduct[4] = {100,200,300,150};
	char cartPcode[4][4];
    int quantity_cart[4];
    int cartCount = 0;
    int total_bill = 0;
    float final_bill = 0;
	
	
	do{
	
	printf(" =====  MAIN MENU  =====   \n");
	printf("1. Customer Information.\n");
	printf("2. Display Inventory.\n");
	printf("3. Update Inventory.\n");
	printf("4. Add Item to Cart.\n");
	printf("5. Display Total Bill.\n");
	printf("6. Show Invoice.\n");
	printf("7. EXIT\n\n");
	scanf("%d", &choice);
    
	
	switch(choice){
		case 1:
			info(name, cnic, &i);
			break;
		case 2:
			display(productCode, quantityLeft, pricePerproduct);
			break;
		case 3:
		    update(name, cnic, &i, productCode, quantityLeft, pricePerproduct, &total_bill);
			break;
		case 4:
			cart(name, cnic, &i, productCode, quantityLeft, pricePerproduct, &total_bill);
			break;
		case 5:
			bill(name, cnic, &i, &total_bill, &final_bill, productCode, quantityLeft, pricePerproduct);
			break;
		case 6:
			invoice(name, cnic, &i, &total_bill, &final_bill, productCode, quantityLeft, pricePerproduct);
			break;
		case 7:
			printf("GOODBYE!");
			break;	
		default: printf("\nInvalid option choosed.\n\n");		
    }
    
    }while(choice!=7);


return 0;
}


    void info(char name [][100], char cnic[][20], int*i){
    	printf("Enter customer's name: ");
    	scanf(" %[^\n]" , name[*i]);
    	printf("Enter customer's CNIC. (xxxxx-xxxxxxx-x)\n ");
    	scanf(" %[^\n]", cnic[*i]);
    	(*i)++;
    	printf("\n");
	}


	void display(char productCode [][4], int quantityLeft [], int pricePerproduct []){
    	int j;
	    printf("    Product Code     |    Quantity in Stock   |    Price per Product\n");
	    printf("---------------------------------------------------------------------\n");
        for (j = 0 ; j < 4 ; j++){
		    printf("          %3s        |         %4d           |          %4d      \n", productCode [j], quantityLeft [j], pricePerproduct[j]);
	    }
	    printf("\n\n");
    }	
    
    	
	void update(char name[][100], char cnic[][20], int *i, char productCode [][4], int quantityLeft [], int pricePerproduct [], int *total_bill){
		if (*i == 0) {
            printf("Please enter customer information first!\n");
            info(name, cnic, i);
        }
        
        int j, found_index, found, quantity_needed;
        char purchase_code [4];
        char buy;
		
		do{
		
		printf("Enter the product code for the product that has been purchased: (Format: 0XX):   ");
		scanf("%3s", purchase_code);
		
		found = 0;
		for (j = 0 ; j < 4 ; j++){
		    if (strcmp(purchase_code, productCode[j]) == 0){
		    	found_index = j;
		        found = 1; 
		        break;
		    }
	    }
		
		if (found == 1){
			printf("For the product '%s', enter quantity being purchased:  ", purchase_code);
			scanf("%d", &quantity_needed);
							
			   	if(quantityLeft[found_index] >= quantity_needed){
			   	    quantityLeft[found_index] = quantityLeft[found_index] - quantity_needed;
			   	    *total_bill = *total_bill + (pricePerproduct[found_index]*quantity_needed);
			   	    printf("\n\nSale Processed Successfully!\n\n");
				} 
				else if(quantityLeft[found_index] == 0){
					printf("\nThe product '%3s' is Out of Stock!\n\n", purchase_code);
				}
				else{
				    printf("\nThe quantity requested the for the product '%3s' to purchase is not available.", purchase_code);
					printf("\nThe quantity left in stock is = %d\n\n", quantityLeft[found_index]);
					printf("\nDo you want to buy product that is remaining in the stock (Y/N):  ");
					scanf(" %c", &buy);

						if(buy == 'Y' || buy == 'y'){
							printf("\n\nSale Processed Successfully!\n");
							*total_bill = *total_bill + (pricePerproduct[found_index]*quantityLeft[found_index]);
							quantityLeft[found_index] = 0;
						}
						else if(buy == 'N' || buy == 'n'){
							return;
						}
						else{								
						    printf("\nInvalid Input. Enter (Y or N).\n\n");
						    return;
						}
		
				}
		}
		if (found == 0){
			printf("Product with code %s NOT Found!\n\n", purchase_code);
		}
	} while(found == 0);
	}
	
	
	void cart(char name[][100], char cnic[][20], int *i, char productCode[][4], int quantityLeft[], int pricePerproduct[], int *total_bill){
		if (*i == 0) {
            printf("Please enter customer information first!\n");
            info(name, cnic, i);
        }
		
		int found = 0, found_index = -1, j;
        char buy;
        char cartPcode[1][4];
        int quantity_cart [1];
        
		printf("\nEnter the product code for the product you want to add to cart  ");
		scanf("%3s", cartPcode[0]); 
				
		found = 0;
		for (j = 0 ; j < 4 ; j++){
		    if (strcmp(cartPcode[0], productCode[j]) == 0){
		    	found_index = j;
		        found = 1; 
		        break;
		    }
	    }
		
		if (found == 1){
			printf("For the product '%3s', enter quantity you want to add to the cart:  ", cartPcode[0]);
			scanf("%d", &quantity_cart[0]);
							
			   	if(quantityLeft[found_index] >= quantity_cart[0]){
			   	    quantityLeft[found_index] = quantityLeft[found_index] - quantity_cart[0];
			   	    *total_bill = *total_bill + (pricePerproduct[found_index]*quantity_cart[0]);
			   	    printf("\n\nProduct '%3s' (quantity = %d) reserved Successfully!\n\n", cartPcode[0], quantity_cart[0]);
				} 
				else if(quantityLeft[found_index] == 0){
					printf("\nThe product '%3s' is Out of Stock!\n\n", cartPcode[0]);
				}
				else{
				    printf("\nThe quantity requested the for the product '%3s' to add to cart is not available.\n", cartPcode[0]);
					printf("\nThe quantity left in stock is = %d", quantityLeft[found_index]);
					printf("\nDo you want to reserve product that is remaining in the stock (Y/N):  ");
					scanf(" %c", &buy);

						if(buy == 'Y' || buy == 'y'){
							quantityLeft[found_index] = 0;
							*total_bill = *total_bill + (pricePerproduct[found_index]*quantityLeft[found_index]);
							printf("\n\nProduct '%3s' (quantity = %d) reserved Successfully!\n\n", cartPcode[0], quantity_cart[0]);
						}
						else if(buy == 'N' || buy == 'n'){
							return;
						}
						else{								
						    printf("\nInvalid Input. Enter (Y or N).\n\n");
						    return;
						}
		
				}
		}
		else {
			printf("Product with code %3s NOT Found!\n\n", cartPcode[0]);
		}
		
	}
		
		
	void bill(char name[][100], char cnic[][20], int *i, int *total_bill, float *final_bill, char productCode[][4], int quantityLeft[], int pricePerproduct[]){
		if (*i == 0) {
            printf("Please enter customer information first!\n");
            info(name, cnic, i);
        }
        
        do{
        if(*total_bill == 0){
        	printf("Enter product for purchase first!\n");
        	update(name, cnic, i, productCode, quantityLeft, pricePerproduct, total_bill);
		}
		}while(*total_bill == 0);
		
		char promo[20];
		printf("\nTotal bill is %d\n", *total_bill);
		printf("You are applicable for a discount if you have a voucher for promo code.\n");
		printf("\nEnter promo code:  ");
		scanf("%s", promo);
		
		if(strcmp(promo, "Eid2025") == 0){
			*final_bill = *total_bill - ((*total_bill)*0.25);
		}
		else{
			*final_bill = *total_bill;
			printf("\nINVALID PROMO CODE. NO DISCOUNT FOR YOU.\n\n");
		}
		
		printf("Your final bill after discount(if applicable) is %.2f\n\n", *final_bill);
	}
	
	
    void invoice(char name[][100], char cnic[][20], int *i, int *total_bill, float *final_bill, char productCode[][4], int quantityLeft[], int pricePerproduct[]) {
    	if (*i == 0) {
            printf("Please enter customer information first!\n");
            info(name, cnic, i);
        }
        
        do{
        if(*total_bill == 0){
        	printf("Enter product for purchase first!\n");
        	update(name, cnic, i, productCode, quantityLeft, pricePerproduct, total_bill);
		}
	    }while (*total_bill == 0);
	    
		if(*final_bill == 0){
			printf("First enter promocode if applicable!\n");
			bill(name, cnic, i, total_bill, final_bill, productCode, quantityLeft, pricePerproduct);
		}

        printf("\n\n====== INVOICE ======\n\n");
        printf("Customer Name: %s\n", name[*i - 1]);
        printf("CNIC: %s\n", cnic[*i - 1]);
        printf("Total Bill: %d\n", *total_bill);
        printf("Final Bill after discount: %.2f\n", *final_bill);
    }

	
	

		

		

