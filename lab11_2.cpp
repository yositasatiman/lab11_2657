#include<iostream>
#include<string>
#include<ctime>
using namespace std;

string cardNames[] = {"","A","2","3","4","5","6","7","8","9","10","J","Q","K"};
int cardScores[] = {0,1,2,3,4,5,6,7,8,9,10,10,10,10};

int drawCard(){
    int x = rand()%13+1;
    return x;
}

int calScore(int x, int y, int z){
    if (x>=10) x=0;
    if (y>=10) y=0;
    if (z>=10) z=0;
    return (x+y+z)%10 ;
}

int findYugiAction(int s){	
	if(s == 9) return 2;
	else if(s < 6) return 1;
		if(rand()%100+1 <= 31) return 2;
		else return 1;
}

void checkWinner(int p, int y){
	// Write condition for cout in this function
	cout << "\n---------------------------------\n";
	if(p == y){
		cout <<   "|             Draw!!!           |"; 
	}else if(p > y){
		cout <<   "|         Player wins!!!        |";
	}else if(p < y){
		cout <<   "|          Yugi wins!!!         |";
	}
	cout << "\n---------------------------------\n";
}

int main(){	
    srand(time(0));

	int playerScore, yugiScore, playerAction, yugiAction;
	int playerCards[3] = {drawCard(), drawCard(), 0};
	int yugiCards[3] = {drawCard(), drawCard(), 0};
	
	cout << "---------ORE NO TURN, DRAW!!!------------\n";
	cout << "Your cards: " << cardNames[playerCards[0]] << " " << cardNames[playerCards[1]] << "\n";
	playerScore = calScore(playerCards[0],playerCards[1],playerCards[2]);
	cout << "Your score: " << playerScore << "\n";
	do{
		cout << "(1) Destiny draw (2) Stay, SELECT: ";
		cin >> playerAction;
	}while(playerAction != 1 && playerAction != 2); //This line of code is not completed. You need to set the condition to do loop if user's input is not 1 or 2. 
	if(playerAction == 1){
		//The following lines of code are not completed. Please correct it.
		
		playerCards[2] = drawCard();
        playerScore = calScore(playerCards[0],playerCards[1],playerCards[2]);
		cout << "Player draws the 3rd card!!!" << "\n";
		cout << "Your 3rd card: " << cardNames[playerCards[2]] << "\n";
		cout << "Your new score: " << playerScore << "\n";
		
	}
	cout << "------------ Turn end -------------------\n\n";
	
	
	//The following lines of code for Yugi's turn are not completed. Please correct it.
	
	cout << "---------YUGI'S TURN, DRAW!!!------------\n";
	cout << "Yugi's cards: " << cardNames[yugiCards[0]] << " " << cardNames[yugiCards[1]] << "\n";
	yugiScore = calScore(yugiCards[0],yugiCards[1],yugiCards[2]);
	cout << "Yugi's score: " << yugiScore << "\n";
	yugiAction = findYugiAction(yugiScore);
	if(yugiAction == 1){
		cout << "Yugi draws the 3rd card!!!\n";
		yugiCards[2] = drawCard();
        yugiScore = calScore(yugiCards[0],yugiCards[1],yugiCards[2]);
		cout << "Yugi's 3rd card: " << cardNames[yugiCards[2]] << "\n";
		cout << "Yugi's new score: " << yugiScore << "\n";
	}
	cout << "------------ Turn end -------------------\n";
	
	
	checkWinner(playerScore,yugiScore);
}