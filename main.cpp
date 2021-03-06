#include <iostream> 
using namespace std; 

char square[10] = {'_','1','2','3','4','5','6','7','8','9'};

int checkwin();
void board();
void turn(int choice, char mark, int &player);
 
/**
  Runs the game.
*/
int main() {
  int player = 1, i, choice;
 
  char mark;

  do {
    board(); 
    player = (player%2)?1:2;

    cout << "Player " << player << ", enter a number : ";

    cin >> choice;

    mark = (player == 1) ? 'X' : 'O';

    turn(choice,mark,player);

    i = checkwin();
    player++;
  }while(i==-1);

  board();
  if(i==1)
    cout << "==>\aPlayer " << --player << " win ";
  else
    cout << "==>\aGame draw";

  cin.ignore();
  cin.get();
  return 0; 
}

/**
  Change the number to the current player turn's mark.'
*/
void turn(int choice, char mark, int &player) {
  if (choice == 1 && square[1] == '1')
    square[1] = mark;
  else if (choice == 2 && square[2] == '2')
    square[2] = mark;
  else if (choice == 3 && square[3] == '3')
    square[3] = mark;
  else if (choice == 4 && square[4] == '4')
    square[4] = mark;
  else if (choice == 5 && square[5] == '5')
    square[5] = mark;
  else if (choice == 6 && square[6] == '6')
    square[6] = mark;
  else if (choice == 7 && square[7] == '7')
    square[7] = mark;
  else if (choice == 8 && square[8] == '8')
    square[8] = mark;
  else if (choice == 9 && square[9] == '9')
    square[9] = mark;
  else {
    cout << "Invalid move\n" << 
      "Please only select a number that is shown on the board" << endl;     
    
    player--;
    cin.get();
    

/*
    cin.ignore();
    cin >> choice;
    player--;
    turn(choice, mark, player);
    player--;
    //cin.ignore();
    //cin.get();
    */
  }
}

/**
 Indicates whether a player wins or runs into a tie game.
*/
int checkwin() {
  if (square[1] == square[2] && square[2] == square[3])
    return 1;
  else if (square[4] == square[5] && square[5] == square[6])
    return 1;
  else if (square[7] == square[8] && square[8] == square[9])
    return 1; 
  else if (square[1] == square[4] && square[4] == square[7])
    return 1;
  else if (square[2] == square[5] && square[5] == square[8])
    return 1; 
  else if (square[3] == square[6] && square[6] == square[9])
    return 1; 
  else if (square[1] == square[5] && square[5] == square[9])
    return 1; 
  else if (square[3] == square[5] && square[5] == square[7])
    return 1; 
  
  else if (square[1]!='1' && square[2]!='2' && square[3]!='3' 
	   && square[4]!='4' && square[5]!='5' && square[6]!='6'
	   && square[7]!='7' && square[8]!='8' && square[9]!='9')
    return 0;
  else
    return -1;
}

/**
  Display a command-line board for the game.
*/
void board() {
  system("cls");
  cout << "\n\n\tTic Tac Toe\n\n";

  cout << "Player 1 (X) - Player 2 (O)" << endl << endl;
  cout << endl;

  cout << "   |   |   " << endl;
  cout << " " << square[1] << " | " << square[2] << " | " << square[3] << endl;

  cout << "___|___|___" << endl;
  cout << "   |   |   " << endl;

  cout << " " << square[4] << " | " << square[5] << " | " << square[6] << endl;

  cout << "___|___|___"<< endl;
  cout << "   |   |   "<< endl;

  cout << " " << square[7] << " | " << square[8] << " | " << square[9] << endl;

  cout << "   |   |   " << endl << endl;
}
