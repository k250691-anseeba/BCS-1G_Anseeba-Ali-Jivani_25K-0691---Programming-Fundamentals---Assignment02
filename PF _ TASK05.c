#include <stdio.h>
#include <string.h>

void encode_msg();
void decode_msg();

int main(){
	
	int i, j, k, n, m, choice;
	char str[100], reverse[100], decoded[100];
	
    do{
		printf(" ===== MAIN MENU ===== \n");
		printf("  1. Encode Message\n");
		printf("  2. Decode Message\n");
		printf("  3. EXIT\n\n");
		printf("Enter your choice:  ");
		scanf(" %d", &choice);
		
	switch (choice){
	
        case 1: //encoding
	        encode_msg();
	        break;
	
       case 2: //decoding
            decode_msg();
            break;
	    
	    case 3:
	    	printf("\nGoodbye!");
	        break;
	        
	    default: printf("Invalid choosed option.");
	    
        }
    }while(choice!=3);
	
	return 0;
}

    void encode_msg(){
    	char str[100], reverse[100];
        int i, j, m;
        
    	printf("\nEnter the message:\n");
	    scanf(" %[^\n]", str);
	
	    //reversal step
	    j = 0;
	    for (i= (strlen(str)-1) ; i>=0 ; i--){
	        reverse[j] = str[i];
	        j++;
	    }
	    reverse[j] = '\0';
	    printf("\n\n");
	    
		//bit toggling step
	/*using XOR 18 because in binary 18 has bit 2 (index bit 1) = 1 and bit 5 (index bit 4) = 1 so XOR of this bit with
	any other char's ASCII binary value at it 2 and 5 would result in changing bit 1 to 0 and 0 to 1 as required.*/
	    
		printf("Encoded message: ");
	    for(m=0 ; reverse[m] != '\0' ; m++){
		    reverse[m] = reverse[m] ^ 18;
		    printf("%c", reverse[m]);
	    }
	    printf("\n\n");
    	
	}
	
	
	void decode_msg(){
		char decoded[100], reverse[100], str[100];
		int i,m,k;
		
		printf("\nEnter the encoded message:\n");
        scanf(" %[^\n]", str);
            
        //untoggle    
        for(m=0 ; str[m] != '\0' ; m++){
		    reverse[m] = str[m] ^ 18;
	    }
	    reverse[m] = '\0';
	    
	    //reversal step
	    k = 0;
	    for (i=(strlen(reverse)-1) ; i>=0 ; i--){
	        decoded[k] = reverse[i];
	        k++;
	    }
	    decoded[k] ='\0';
	    printf("\nDecoded Message: %s\n\n", decoded);	
	}
