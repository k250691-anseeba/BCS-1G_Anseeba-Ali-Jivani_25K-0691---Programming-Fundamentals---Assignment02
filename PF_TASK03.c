# include <stdio.h>

void update(int grid[3][3]);
void query(int grid[3][3]);
void run(int grid [3][3]);

int main(){
	
	/*Given: 
	• Bit 0: Power Status (1 = ON, 0 = OFF)
    • Bit 1: Overload Warning (1 = Overloaded, 0 = Normal)
    • Bit 2: Maintenance Required (1 = Yes, 0 = No)*/
    
	int choice;
	int grid[3][3] = {0,0,0,0,0,0,0,0,0};   
	//assumed grid is 3x3 and each sector of it is kept 0 means OFF, normal, no maintenance required.
	
	do{
		printf("===== MAIN MENU =====\n");
	    printf("Enter your desired operation option:  \n");
	    printf("1) Update Sector Status\n");
	    printf("2) Query Sector Status\n");
	    printf("3) Run System Diagnostics\n");
	    printf("4) EXIT\n\n");
	    scanf("%d", &choice);
	    
	    switch(choice){
	    	case 1: 
	    	    update(grid);
				break;
				
			case 2: 
			    query(grid);   
				break;
				
			case 3:
				run(grid);
				break;
				
			case 4:
				printf("\n\nGOODBYE!\n\n\n");
				break;
				
			default: printf("Invalid option choice entered.");
		}

	}while (choice != 4);
	
	
	
	
	return 0;
}



    void update(int grid[3][3]){
    	int option, value;
    	int row, col;
    	printf("In the 3x3 grid, enter the row of the sector that you want to update:  ");
    	scanf("%d", &row);
    	printf("In the 3x3 grid, enter the column of the sector that you want to update:  ");
    	scanf("%d", &col);
    	
    	do{
    	printf("\nMENU FOR SECTOR UPDATION!\n");
    	printf("Select what to update:\n");
	    printf("1) Power Status\n");
	    printf("2) Overload Warning\n");
	    printf("3) Maintenance Required\n");
	    printf("4) EXIT\n\n");
	    scanf("%d", &option);
	    
        if (option >= 1 && option <= 3) {
            printf("Enter 1 to turn ON or Enter 0 to turn OFF:  ");
            scanf("%d", &value);

            if (value == 1)
                grid[row-1][col-1] = (grid[row-1][col-1]) | (1 << (option - 1));  
            else if (value == 0)
                grid[row-1][col-1] = (grid[row-1][col-1]) & ~(1 << (option - 1)); 
            else
                printf("Invalid input!\n");
        }

        else if (option == 4)
            printf("\nExiting sector update!\n\n");
        else
            printf("Invalid choice! Try again.\n");

        } while (option != 4);
	}
	
	void query(int grid[3][3]){
		int row, col;
        printf("In the 3x3 grid, enter the row of the sector that you want query status for:  ");
    	scanf("%d", &row);
    	printf("In the 3x3 grid, enter the column of the sector that you want query status for:  ");
    	scanf("%d", &col);
		
		printf("\nStatus report for Sector (%d, %d):\n", row, col);
		//power status
		if (((grid[row-1][col-1]) & (1 << 0)) != 0){
            printf("Power Status: ON\n");
		}
        else{
		    printf("Power Status: OFF\n");
		}
		//overload
        if (((grid[row-1][col-1]) & (1 << 1)) != 0){
            printf("Overload Warning: OVERLOADED\n");
		}
        else{
            printf("Overload Warning: Normal\n");
		}
        //maintenance
        if (((grid[row-1][col-1]) & (1 << 2)) != 0){
            printf("Maintenance Required: YES\n");
        }
		else{
            printf("Maintenance Required: NO\n");
		}
		printf("\n\n");
    }
    
    

    void run(int grid[3][3]){
    	int m,n;
    	int overload = 0, maintenance = 0;
    	
    	for(m=0 ; m<3 ; m++){
    		for(n=0 ; n<3 ; n++){
    			if (((grid[m][n]) & (1 << 1)) != 0){
                    overload++;
		        }
		        if (((grid[m][n]) & (1 << 2)) != 0){
                    maintenance++;
				}
			}
		}
		
		printf("\nThere are %d sectors that are currently overloaded\n", overload);
		printf("There are %d sectors that currently require maintenance\n\n", maintenance);
	}


	
	
