//
//  ttt.cpp
//
//
//  Created by Giorgio Figus on 05/12/2021.
//

#include "ttt_functions.hpp"


int main(){
    
    std::cout << " Tic Tac Toe ";

    //array initialized with blanks..
    char matrix [m_size] [m_size] = {   ' ', ' ', ' ',
                                        ' ', ' ', ' ',
                                        ' ', ' ', ' '   };
    
    int colum = 0;
    int row = 0;
    bool end_game = false;
    int n_moves = 0;
    
    displayMatrix( matrix );
    
    do{
                // player1 choice, symbol X
                std::cout << " Player1 :  ";
                userChoice( colum, row, matrix );
                matrix [row] [colum] = 'X';
                displayMatrix( matrix );
                // n_moves is incremented after any moves
                n_moves++;
        
                if (n_moves < 9 ){
                    if ( !playerWin(matrix, 'X') ){
                    // if player1 not win it's up to Player2
                            // player2 choice, symbol O
                            userChoice( colum, row, matrix);
                            matrix [row] [colum] = 'O';
                            displayMatrix ( matrix );
                            // n_moves is incremented after any moves
                            n_moves++;
                        
                    }
                    else {
                        std::cout << "\n  ! ! ! ! ! ! ! P L A Y E R 1   W O N   ! ! ! ! ! ! ! ! !\n";
                        end_game = true;
                    }
                
                    if (playerWin(matrix, 'O')){
                        std::cout << "\n  ! ! ! ! ! ! ! P L A Y E R 2   W O N   ! ! ! ! ! ! ! ! !\n";
                            end_game = true;
                    }
                    
                }

    } while (end_game==false && n_moves != 9 );
     //while true
    
    // possible
    if (end_game == false ){
        displayMatrix( matrix );
        std::cout << ( " no Chance, it's a draw ! ");
    }

    return 0;
}
