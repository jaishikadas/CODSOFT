#include <iostream>
using namespace std;
const int BOARD_SIZE = 3;

void displayBoard(char board[][BOARD_SIZE]){
  cout<<"Current Board:\n";
  for(int i=0;i<BOARD_SIZE;++i){
    for (int j=0;j<BOARD_SIZE;++j){
      cout<<board[i][j]<< " ";
    }
    cout<<endl;
  }
}
bool checkWin(char board[][BOARD_SIZE], char player){
  for (int i=0;i<BOARD_SIZE;++i){
    if((board[i][0]==player && board[i][1]==player && board[i][2]==player)||(board[0][i]==player && board[1][i]==player && board[2][i]==player))
      return true;
  }
  if (board[0][0]==player && board[1][1]==player && board[2][2]==player)
    return true;
  if (board[0][2]==player && board[1][1]==player && board[2][0]==player)
    return true;
  return false;
}
bool checkDraw(char board[][BOARD_SIZE]){
  for(int i=0;i<BOARD_SIZE;++i){
    for(int j=0;j<BOARD_SIZE;++j){
      if(board[i][j]=='-')
	  return false;
    }
  }
  return true;
}
void playerMove(char board[][BOARD_SIZE],char player){
  int row,col;
  while(true){
    cout<<"Player"<<player<<",enter your move(row and column): ";
    cin>>row>>col;
    if(row>=1 && row<=BOARD_SIZE && col>=1 && col<=BOARD_SIZE && board[row-1][col-1]=='-'){
      board[row - 1][col - 1] = player;
      break;
    } 
	else{
      cout<<"Invalid move,try again.\n";
    }
  }
}
int main(){
  char board[BOARD_SIZE][BOARD_SIZE];
  for(int i=0;i<BOARD_SIZE;++i){
    for(int j=0;j<BOARD_SIZE;++j){
      board[i][j]='-';
    }
  }
  char currentPlayer ='X';
  char playAgain;
  while (true){
    displayBoard(board);
    while(true){
      playerMove(board,currentPlayer);
      if(checkWin(board,currentPlayer)) {
        displayBoard(board);
        cout<<"Player"<<currentPlayer<<" wins!\n";
        break;
      }
      if (checkDraw(board)){
        displayBoard(board);
        cout<<"The game is a draw!\n";
        break;
      }
      currentPlayer=(currentPlayer=='X')?'O':'X';
    }
    cout<<"Do you want to play again?(y/n): ";
    cin>>playAgain;
    if(playAgain!='y')
	break;
    currentPlayer='X';
    for (int i=0;i<BOARD_SIZE;++i){
      for (int j=0;j<BOARD_SIZE;++j){
        board[i][j]='-';
      }
    }
  }
  return 0;
}

