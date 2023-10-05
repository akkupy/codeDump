/*
@author: nandinisahu407
Tic Tac Toe game, probably which everyone had played in their childhood
*/
#include<iostream>
#include<ctime>
#include<random>
using namespace std;

char board[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
void show_board();
void get_x_player_choice();
void get_o_player_choice();
void get_computer_choice();
int count_board(char symbol);
char check_winner();
void computer_vs_player();
void player_vs_player();

void show_board(){          //to display board
    cout<<"   "<<"    |   "<<"    |   "<<endl;
    cout<<"   "<<board[0]<<"   |   "<<board[1]<<"   |   "<<board[2]<<endl;
    cout<<"------------------------"<<endl;
    cout<<"   "<<"    |   "<<"    |   "<<endl;
    cout<<"   "<<board[3]<<"   |   "<<board[4]<<"   |   "<<board[5]<<endl;
    cout<<"------------------------"<<endl;
    cout<<"   "<<"    |   "<<"    |   "<<endl;
    cout<<"   "<<board[6]<<"   |   "<<board[7]<<"   |   "<<board[8]<<endl;

}

void get_computer_choice(){         //to get computer choice
    srand(time(0));
    int choice;
    do{
        choice=rand()%10;
    }while(board[choice]!=' ');
    board[choice]='O';

}

void get_x_player_choice(){         //to get cross from player 1
    while(true){
        cout<<"select Your Position(1-9): ";
        int choice;
        cin>>choice;
        choice--;
        if(choice<0|| choice>8){
            cout<<"invalid choice!!  please select from 1-9"<<endl;
        }
        else if(board[choice]!=' '){
            cout<<"please select an empty position."<<endl;
        }
        else{
            board[choice]='X';
            break;
        }

        
    }
}
void get_o_player_choice(){         //to get zero from player2
    while(true){
        cout<<"select Your Position(1-9): ";
        int choice;
        cin>>choice;
        choice--;
        if(choice<0|| choice>8){
            cout<<"invalid choice!!  please select from 1-9"<<endl;
        }
        else if(board[choice]!=' '){
            cout<<"please select an empty position."<<endl;
        }
        else{
            board[choice]='O';
            break;
        }

        
    }
}

void computer_vs_player(){
    string player_name;
    cout<<"Enter your name: ";
    cin>>player_name;
    while(true){
        system("cls");
        show_board();
        if(count_board('X')==count_board('O')){
            cout<<player_name<<"'s turn."<<endl;
            get_x_player_choice();
        }
        else{
            get_computer_choice();
        }
        char winner=check_winner();
        if(winner=='X'){
            system("cls");
            show_board();
            cout<<player_name<<" WON THE GAME !!"<<endl;
            break;

        }
        else if(winner=='O'){
            system("cls");
            show_board();
            cout<<"COMPUTER  WON THE GAME !!"<<endl;
            break;
        }
        else if(winner=='D'){
            cout<<"GAME IS DRAW "<<endl;
            break;
        }

    }

}

void player_vs_player(){
    string x_player_name,o_player_name;
    cout<<"Enter X player name: ";
    cin>>x_player_name;
    cout<<"Enter O player name: ";
    cin>>o_player_name;
    while(true){
        system("cls");
        show_board();
        if(count_board('X')==count_board('O')){
            cout<<x_player_name<<"'s turn."<<endl;
            get_x_player_choice();
        }
        else{
            cout<<o_player_name<<"'s turn."<<endl;
            get_o_player_choice();
        }

        char winner=check_winner();
        if(winner=='X'){
            system("cls");
            show_board();
            cout<<x_player_name<<" WON THE GAME!!"<<endl;
            break;

        }
        else if(winner=='O'){
            system("cls");
            show_board();
            cout<<o_player_name<<" WON THE GAME !!"<<endl;
            break;
        }
        else if(winner=='D'){
            cout<<"GAME IS DRAW "<<endl;
            break;
        }



    }
    
}

int count_board(char symbol){
    int total=0;
    for(int i=0;i<9;i++){
        if(board[i]==symbol){
            total++;
        }
    }
    return total;
}

char check_winner(){
    //checking winner in horizontal
    if(board[0]==board[1]&&board[1]==board[2]&&board[0]!=' '){
        return board[0];
    }
    else if(board[3]==board[4]&&board[4]==board[5]&&board[3]!=' '){
        return board[3];
    }
    else if(board[6]==board[7]&&board[7]==board[8]&&board[6]!=' '){
        return board[6];
    }
    //checkin winner in vertical
    else if(board[0]==board[3]&&board[3]==board[6]&&board[0]!=' '){
        return board[0];
    } 
    else if(board[1]==board[4]&&board[4]==board[7]&&board[1]!=' '){
        return board[1];
    }
    else if(board[2]==board[5]&&board[5]==board[8]&&board[2]!=' '){
        return board[2];
    }

    // checking winner in diagonal
    else if(board[0]==board[4]&&board[4]==board[8]&&board[0]!=' '){
        return board[0];
    }
    else if(board[2]==board[4]&&board[4]==board[6]&&board[2]!=' '){
        return board[2];
    }

    if(count_board('X')+count_board('O')<9){
        return 'C';

    }
    else{
        return 'D';
    }

}



int main(){
    int mode;
    cout<<"\n -----------------WELCOME TO TIC TAC TOE GAME------------------"<<endl;
    cout<<"\n\t\t1. COMPUTER VS PLAYER."<<endl;
    cout<<"\t\t2. PLAYER VS PLAYER."<<endl;
    cout<<"------------------------------------------------------------------"<<endl;
    cout<<"select game mode: ";
    cin>>mode;
    
    while(true){
        if(mode==1){
            computer_vs_player();
            break;
        }
        else if(mode=2){
            player_vs_player();
            break;
        }
        else{
            cout<<"please select valid mode"<<endl;
            break;
        }
        return 0;
    }
    }