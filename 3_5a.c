#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void){
	//Generating to random number between 1-100, these will be the secrete coordinates//
	srand(time(NULL));
	int secret_x = rand() % 100 + 1;
	int secret_y = rand() % 100 + 1;
	
	//Inializing needed variables//
	char dir_x, dir_y; //Direction (output)
	int guess_x=0, guess_y=0; //The numbers guessed
	int guesses=0; //Number of attempts
	
	//Introduction statement and Colecting the first guess//
	printf ("Welcome! In this game you will try to guess a secret random set of coordinates.\nIn each attempt, the game will tell you your position realtive to the secret.\nGood Luck!\n \n------------------------------------------\n\n");
	printf("Please guess the correct coordinates in the formar xxx,yyy\n");
	scanf ("%d,%d", &guess_x, &guess_y);
	
	
	//Cycle that reads te coordinates, changes de direction output acordingly and asks for a new value//
	//This cycle only ends once the value entered is equal to the secret
	while(guess_x!=secret_x || guess_y!=secret_y) {
		if ((guess_x<=100 && guess_x>=1) && (guess_y<=100 && guess_y>=1)) //reads if it the value is valid (between 1 and 100)
		{
			guesses++; //if the value is valid, increase guesses by 1
			
			//deciding the direction
			if (guess_x>secret_x){ 
				dir_x='E';
			} else if (guess_x<secret_x) {
				dir_x='W';
			} else {
				dir_x=' '; //x is correct
			}
			if (guess_y>secret_y){
				dir_y='N';
			} else if (guess_y<secret_y) {
				dir_y='S';
			} else {
				dir_y=' '; //y is correct
			}
			
			//Output (Only if coordinates are valid)
			printf ("You are %c%c of the correct coordinates!\n", dir_y, dir_x); //indicating the position relative to the secret
			printf ("Guess again:\n");
			scanf ("%d,%d", &guess_x, &guess_y); //Scans the next guess, if it's wrong the cycle repeats
			
		} 
		else //In case coordinates are invalid 
		{
			printf("invalid coordinates, try again! Remember: x and y are between 1 and 100\n");//Output for invalid coordinates
			printf ("Guess again:\n");
			scanf ("%d,%d", &guess_x, &guess_y); //Scans the next guess
		} 
	} //END OF THE CYCLE 
	
	guesses++; //Adds 1 final guess
	//Final output when guesses correctly
	printf("Congratulations! You guessed %d,%d correctly in %d attempts", secret_x, secret_y, guesses);
					
	
	return 0;
}
