#include <iostream>
#include <windows.h>

#define N 6

using namespace std;

int board[N][N];

void printBoard(){
	system("cls");
    for(int i=0 ; i<N ; i++){
        for(int j=0 ; j<N ; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
}

bool isSafe(int row, int col){

    int i , j;

    for(i=0 ; i<row ; i++){
        if(board[i][col])
            return false;
    }
    for(i=row , j=col ; i>=0 && j>=0 ; i-- , j--){
        if(board[i][j])
            return false;
    }
    for(i=row , j=col ; i>=0 && j<N ; i-- , j++){
        if(board[i][j])
            return false;
    }
    return true;
}

bool letsPlay(int row){

    if(row >= N){
        return true;
    }

    for(int col = 0; col<N ; col++){
        if(isSafe(row, col)){
            board[row][col] = 1;
      
//			printBoard();
//			cin.get();

            if(letsPlay(row+1)){
                return true;
            }
        }
      board[row][col] = 0;
    }
    return false;
}

void start(){

    if(letsPlay(0)){
        printBoard();
    }else{
        cout<<"there is no solution"<<endl;
    }
}

int main(){

    start();
	cin.get();
    return 0;
}
