#include <iostream>
#include <string> // Needed to use strings
#include <cstdlib> // Needed to use random numbers
#include <ctime>
#include <string.h>
#include <stdio.h>

using namespace std;

class Display
{
	public:
        void printMessageCenter(const char* message);
        void headMessage(const char *message);
        void welcomeMessage();
        void drawLine(int n, char symbol);
        void rules();
};

void Display::drawLine(int n, char symbol)
{
  for (int i=0;i<n;i++)
  {
    cout<< symbol;
  }
  cout<<"\n";
}

void Display::rules()
{
	headMessage("\t\t\t RULES OF THE GAME");
	cout<<"\n\n\n\n";
	drawLine(100,'-');
	cout<<"Rule1. Choose any number between 1 to 10. \n";
	cout<<"Rule2. If you win you will get 10 times the money you bet. \n";
	cout<<"Rule3. If you bet on the wrong number you will lose your money that you have used for betting. \n\n";
	drawLine(100,'-');
	cout<< "\n\n\n\t\t\t Enter to continue....................";
	getchar();
}

void Display::printMessageCenter(const char* message)
{
	
	int len=0;
	int pos=0;
	// claculate how many space need to print
	len=(78-strlen(message))/2;
	cout<<"\t\t\t";
	
	for(pos=0;pos<len;pos++)
	{
		cout<<" ";     // print space
	}
	
	cout<<message;     //print message
}


void Display::headMessage(const char *message)
{
	system("cls");
	cout<<"\t\t\t####################################################################################################################";
	cout<<"\n\t\t\t#########################                                                                 ##########################";
	cout<<"\n\t\t\t#########################                Casino Game Project in C++                       ##########################";
	cout<<"\n\t\t\t#########################                                                                 ##########################";
	cout<<"\n\t\t\t####################################################################################################################";
	cout<<"\n\t\t\t--------------------------------------------------------------------------------------------------------------------\n";
	printMessageCenter(message);
	cout<<"\n\t\t\t--------------------------------------------------------------------------------------------------------------------\n";
}

void Display::welcomeMessage()
{
	headMessage("\t\t\t by Repala Swaraj");
	cout<< "\n\n\n\n\n\n";
    cout<< "\t\t\t\t\t     ***-***-***-***-***-***-***-***-***-***-***-***-***-***-***-***-***-***-***-***-*** \n";
	cout<< "\t\t\t\t\t             =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=   \n";
    cout<< "\t\t\t\t\t             =                                                                 =   \n";
    cout<< "\t\t\t\t\t             =                              WELCOME                            =   \n";
    cout<< "\t\t\t\t\t             =                                 TO                              =   \n";
    cout<< "\t\t\t\t\t             =                            CASINO GAME                          =   \n";
    cout<< "\t\t\t\t\t             =                                                                 =   \n";
    cout<< "\t\t\t\t\t             =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=   \n";
    cout<< "\t\t\t\t\t     ***-***-***-***-***-***-***-***-***-***-***-***-***-***-***-***-***-***-***-***-*** \n";
    cout<< "\n\n\n\t\t\t      Enter to continue......................";
    getchar();
}

class PlayerInfo:public Display
{
	public:
		int getGuessNumber();
		void setGuessNumber();
		void setAmount();
		float getAmount();
		int getdice();
		void updateAmount(const bool isWin);
		void setBettingAmount();
		bool isPlayerWin();
		void init();
		void displayMessageAfterPlay(const bool isWin);
		PlayerInfo() : m_amount(0.00), m_bettingAmount(0.00), m_guessNumber(-1)
		{
			
		}
		
	private:
		float m_amount;           // Total balance of a player
		float m_bettingAmount;    // Betting Amount
		int m_guessNumber;     // Number guessed by player
		
};

// Set Wallet Amount

void PlayerInfo::setAmount()
{
	headMessage("\t\t\t Set Amount");
	do{
		cout<< "\n\n Enter Deposit amount to play game: $";
		cin>> m_amount;
		if(m_amount < 0.01f)
		{
			cout<< "\n\n Please Enter valid amount to play the Game!";
		}
	}
	while(m_amount < 0.01f);
}
//Get Wallet Amount

float PlayerInfo::getAmount()
{
	return m_amount;
}
int PlayerInfo::getGuessNumber()
{
	return m_guessNumber;
}

//Get a Number from player
void PlayerInfo::setGuessNumber()
{
	headMessage("\t\t\t Set Guess Number");
	do
	{
		cout<<"\n\n Guess your Number to bet between 1 to 10 : ";
		cin>> m_guessNumber;
		if(m_guessNumber<=0 || m_guessNumber> 10)
		{
			cout<<"\n\n Please check the Number, it should be between 1 to 10 only \n"<<"\nRe-enter the Number\n";
		}
	}
	while(m_guessNumber<=0 || m_guessNumber>10);
}
// Update wallet Amount
void PlayerInfo::updateAmount(const bool isWin)
{
	m_amount = isWin ? (m_amount + (m_bettingAmount * 10)): (m_amount - m_bettingAmount);
}
//Set betting Amount
void PlayerInfo::setBettingAmount()
{
	headMessage("\t\t\t Set Bet Amount");
	do{
		cout<<"\n\nEnter money that you want to bet : $";
		cin>>m_bettingAmount;
		if(m_bettingAmount > m_amount)
		{
			cout<< "\n\nYour Wallet Amount is $"<<m_amount;
			cout<< "\n\nYour betting amount is more than your wallet amount";
		}
	}
	while(m_bettingAmount>m_amount);
 } 
 
 //check weather player is win
 bool PlayerInfo::isPlayerWin()
 {
    const int dice = rand()%10 + 1;
    return((dice == getGuessNumber()) ? true:false);
 }
 
 //Init the Game
 void PlayerInfo::init()
 {
 	welcomeMessage();
 	srand(time(0)); // the random generator
 	rules();
 }
 // Display message after each play
 void PlayerInfo::displayMessageAfterPlay(const bool isWin)
 {
 	if(isWin)
 	{
 		cout<<"\n\nCongratulations! You have won $" << m_bettingAmount*10;
 		cout<<"\n\nNow your current wallet amount is $" << m_amount;
	}
	else{
		cout<<"\n\n Better Luck Next Time!! You Lost $" <<m_bettingAmount;
		cout<<"\n\n now update amount is $" << m_amount;
	}
 }
 
 int main()
 {
    class PlayerInfo obj_player;
    char choice;
    obj_player.init();
    obj_player.setAmount();
    do{
	   cout<<"\n\nYour wallet Balance is $"<<obj_player.getAmount()<<"\n";
    obj_player.setBettingAmount();
    obj_player.setGuessNumber();  // set Guess number
    const bool isPlayerWin = obj_player.isPlayerWin();  
    obj_player.updateAmount(isPlayerWin);  // update wallet amount
    obj_player.displayMessageAfterPlay(isPlayerWin);  // Display the result after the  each game play
	// check weather the wallet amount is sufficient to bet
	if(obj_player.getAmount() == 0.00f)
	{
	   cout<<"\n You have no money to play..........";
	   break;	
	} 
	//Ask choice for replay
	cout<<"\n\n Do you want to play again (y/n)?";
	cin>>choice;
   }
   while(choice == 'y' || choice=='Y');
   cout<<"\n\n\n";
   obj_player.drawLine(80,'=');
   cout<<"\n\nThanks for playing the game.Your balance amount is $"<<obj_player.getAmount()<<"\n\n";
   cout<<"***********************************GAMEOVER**************************************\n\n";
   obj_player.drawLine(80,'=');
   return 0;
 }
