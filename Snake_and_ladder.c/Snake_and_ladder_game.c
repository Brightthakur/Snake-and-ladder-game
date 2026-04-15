#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

typedef struct{
	char name[50];
	int position;
	int unlocked;
} Player;


// Rolling the dice
int rolldice(){
	return (rand()%6)+1; }
	
// Moving player to next:-

int move(int current,int roll){
	// Normal condition;
	int next = current+roll;
	
	if (next>100){
		return current;
	}
	// snakes positions
	if(next==16){
		printf("\n /////Oh NOOOOOO Bitten by a snake go from 16 to 5////// \n");
	return 5;	
	}
	if(next==23){
		printf("\n //////nOh NOOOOOO Bitten by a snake go from 23 to 12 /////// \n");
		return 12;
	 } 
	if(next==56) {
		printf("\n ///////Oh NOOOOOO Bitten by a snake go from 56 to 47 /////// \n");
		return 47;
	}
	if(next==84){
		printf("\n /////// Oh NOOOOOO Bitten by a snake go from 84 to 66 //////// \n");
		return 66;
	} 
	if(next == 99){
		printf("\n /////// Oh NOOOOOO Bitten by a snake go from 99 to 7 /////// \n");
		return 7;
	}
	if(next == 39){
		printf("\n /////// Oh NOOOOOO Bitten by a snake go from 39 to 4 /////// \n");
		return 4;
	}
	if(next == 27){
		printf("\n /////// Oh NOOOOOO Bitten by a snake go from 27 to 11 /////// \n");
		return 11;
	}
	if(next == 44){
		printf("\n /////// Oh NOOOOOO Bitten by a snake go from 44 to 21 /////// \n");
		return 21;
	}
	if(next == 94){
		printf("\n /////// Oh NOOOOOO Bitten by a snake go from 94 to 77 /////// \n");
		return 77;
	}
	
	// Ladder positions
	
	if(next==8){
		printf("\nYay! ** climbed a ladder go from 8 to 24 **\n");
		 return 24;
	}
	if(next==19){
		printf("\n ** Yay! climbed a ladder go from 19 to 35 **\n ");
		return 35;
	} 
	if(next==44){
		printf("\n ** Yay! climbed a ladder go from 44 to 59 **\n ");
		return 59;
	} 
	if(next==69){
		printf("\n ** Yay! climbed a ladder go from 69 to 98 **\n ");
		return 98;
	} 
	if(next==14){
		printf("\n ** Yay! climbed a ladder go from 14 to 79 **\n");
		return 79;
	} 
	if(next==38){
		printf("\n ** Yay! climbed a ladder go from 38 to 48 **\n");
		return 48;
	} 
	if(next==9){
		printf("\n ** Yay! climbed a ladder go from 9 to 40 **\n");
		return 40;
	}
	if(next==83){
		printf("\n ** Yay! climbed a ladder go from 83 to 95 **\n");
		return 95;
	}  
	// Normal condition 
	return next;
}

int main(){
	
	Player players[2];
	int turn = 0;
	
	printf("\n=========================================================================");
	printf("\n YOU ARE WELCOME TO THE SNAKE AND LADDER GAME\n");
	
	printf("\nEnter the name of player 1:- ");
	fgets(players[0].name,sizeof(players[0].name),stdin);
	players[0].name[strcspn(players[0].name, "\n")] = '\0';

	srand(time(NULL));
	
	players[0].position = 0;
	players[1].position = 0;
	players[0].unlocked = 0;
	players[1].unlocked = 0;
	
	
	printf("\nEnter the name of player 2:-");
	fgets(players[1].name,sizeof(players[1].name),stdin);
	players[1].name[strcspn(players[1].name, "\n")] = '\0';

	
	printf("\n+++++++  LET'S START THE GAME  +++++++\n");
	
	printf("%s  and  %s \n ++++ YOU BOTH ARE WELCOME ++++ \n",players[0].name,players[1].name);
	
	while(1){
	    printf("\n===============================================================\n");
	    // Showing snake's Positions
	    printf("Snake's position are:-{16->5} {23->12} {27->11} {39->4} {44->21} {56->47} {84->66} {99->7}");
	    printf("\n");
	    // Showing Ladder's Positions 
	    printf("\nLadder's Positions:- {8->24} {19->35} {44->59} {69->98} {14->79} {38->48} {9->40} {83->95}");
	    
		printf("\nIt is player %s 's turn \n Please Enter to roll the dice:-\n",players[turn].name);
		printf("Current position:- %d ",players[turn].position);
		getchar();
		
		int dice = rolldice();
		printf("\nYou Rolled a %d\n",dice);
		 	
		 if(!players[turn].unlocked){
		 	
		 	if(dice==1){
		 		players[turn].unlocked=1;
		 		printf("\nNow %s is unlocked ! you get a bonus\n",players[turn].name);
		 		printf("\n Please Enter for BONUS roll \n");
		 		getchar();
		 		//printf("\n=====================================\n");
			 }
			 else{
			 	printf("\n %s is still locked!! Need a 1 to unlock\n",players[turn].name);
			 	//printf("\n=====================================\n");
			 	turn = (turn+1)%2;
			 	continue;
			 }
		 }
		
		 players[turn].position = move(players[turn].position, dice);
		 printf("%s moved to position %d\n", players[turn].name, players[turn].position);

		 if(players[turn].position==100){
		 	printf("*********************************************");
		 	printf("\n**** Congratulations %s you won the game ****\n",players[turn].name);
		 	printf("*********************************************");
		 	 break;
		 }
		turn = (turn+1)%2;
		 }
		 	 
	return 0;	
}