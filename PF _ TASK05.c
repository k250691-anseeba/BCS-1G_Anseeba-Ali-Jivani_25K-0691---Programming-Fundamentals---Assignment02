#include <stdio.h>
#include <string.h>

int main(){
	
	int i, j=0, n, m, choice;
	char str[100], reverse[100], decoded[100];
	
    do{
		printf(" ===== MAIN MENU ===== \n");
		printf("  1. Encode Message\n");
		printf("  2. Decode Message\n");
		printf("  3. EXIT\n\n");
		printf("Enter your choice:  ");
		scanf("%d", &choice);
		
	switch (choice){
	
        case 1: //encoding
	        printf("\nEnter the message:\n");
	        scanf(" %[^\n]", str);
	
	    //reversal step
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
	    break;
	
       case 2: //decoding
            printf("\nEnter the encoded message:\n");
            scanf(" %[^\n]", str);
            
        //untoggle    
        for(m=0 ; str[m] != '\0' ; m++){
		    str[m] = str[m] ^ 18;
		    reverse[m] = str[m];
	    }
	    //reversal step
	    for (i=(strlen(reverse)-1) ; i>=0 ; i--){
	        decoded[j] = reverse[i];
	        j++;
	    }
	    decoded[j] ='\0';
	    printf("Decoded Message: %s\n\n", decoded);
	    
	    break;
	    
	    case 3:
	    	printf("\nGoodbye!");
	    break;
	    
        }
    }while(choice>=1 && choice<3);
	
	return 0;
}
