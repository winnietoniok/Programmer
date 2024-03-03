#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int generateRandomNumber(int min, int max){
     return rand() % (max-min+1) + min;
}

int main(){
   srand(time(0));

   int secretNumber;
   int guess;
   int attempts=0;
   int score=100;
   int highScore=0;

   char playAgain;

   do{
     secretNumber=generateRandomNumber(1,100);

     cout<<"Welcome to the Guessing Game!\n";
     cout<<"Try to guess the secret number between 1 and 100.\n";

  do{
     cout<<"Enter your guess:";
     cin>>guess;

     attempts++;

     if(guess == secretNumber){
        cout<<"Congratulations! You guessed the correct number.\n";
        cout<<"Number of attempts:"<<attempts << endl;

        if(score>highScore)
          highScore = score;

          score=100;
          attempts=0;
     }
     else{
      score -=10;

      if(guess < secretNumber)
        cout << "Try a higher number.\n";
      else
        cout<<"Try a lower number.\n";

     cout << "Attempts left:"<< 10 - attempts << endl;

     if(attempts >=10){
        cout <<"Game over! You've run out of attempts.\n";
        cout <<"The correct number was:" << secretNumber <<endl;

        score =100;
        attempts =0;

     }
     }
  }while(guess !=secretNumber && attempts <10);

  cout <<"High Score:"<<highScore <<endl;

  cout << "Do you want to play again? (y/n):";
  cin >> playAgain;
}while(playAgain =='y' || playAgain == 'Y');

cout << "Thank you for playing!\n";

return 0;
}
