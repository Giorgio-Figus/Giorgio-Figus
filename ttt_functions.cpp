//
//  ttt_functions.cpp
//  
//
//  Created by Giorgio Figus on 05/12/2021.
//

#include "ttt_functions.hpp"


// user Choice
void userChoice (int& colum, int& row, const char m[m_size][m_size] ) {
    
    bool is_valid = false;
    
    while ( !is_valid ){
        
                std::cout << "make your move : \n";
                std::cout << "Colum : \n";
                std::cin >> colum;
                std::cout << "row : \n";
                std::cin >> row;
                // numbers has to be decrese as the range is 0,1,2
                row--;
                colum--;
                
                if (colum >=0 && colum < m_size && row >=0 && row < m_size ){
                    if (m[row][colum] == 'X' || m[row][colum] == 'O'  ){
                        std::cout << "\n not valid! ";
                    } else {
                        is_valid = true;
                    }
                    
                }
                else{
                    std::cout << "\n Note valid... Valid values  1,2,3\n";
                }
    }
    std::cout << " You chose (" << row << "," << colum << ") \n";
}

// display Matrix just print the matrix on the screen

void displayMatrix( const char matr [m_size ] [m_size] ) {
    /*
     possible layout
        _____________
        |   |   |   |
        +---+---+---+
        |   |   |   |
        +---+---+---+
        |   |   |   |
        -------------
     
     */
    std::cout << "\n  __1___2___3__\n";
    
        for (int i = 0; i<m_size; i++ ){
            std::cout << (i+1) << " |";
            
            for (int j = 0; j<m_size; j++ ) {
                
                std::cout <<" " << matr[i][j] << " |";
            }
            std::cout << "\n  +---+---+---+\n";
        }

}

bool playerWin (const char m [m_size ] [m_size], const char& symbol)
{
// Scan of the matrix
    int tre_in_diag = 0;
    int rev_diag = 0 ;

    for (int i=0; i<m_size; i++) {
                
                int tre_in_row = 0;
                int tre_in_col = 0;
                
                for ( int j=0; j<m_size; j++ ){
                    
                    //check for 3 X in a row
                    if (m[i][j] == symbol ) {
                        tre_in_row++;
                        if (tre_in_row == 3)
                        {
                            return true;
                        }
                    }
                    
                    //check for 3Xin a col ( index are inverted )
                    if (m[j][i] == symbol ) {
                        tre_in_col++;
                        if (tre_in_col == 3)
                        {
                            return true;
                        }
                    }
                    
                    // check diagonal (0,0) , (1,1), (2,2)
                    if ( i==j ){
                        
                        if (m[i][j] == symbol ){
                            tre_in_diag++;
                            if (tre_in_diag == 3)
                            {
                                return true;
                            }
                        }
                    }//if 3 in diagonal row
                        
                    // check revers diagonal (0,2), (1,1) (2,0)
                    if ( (j+i)==(m_size-1) ){
                        if (m[i][j] == symbol ){
                            rev_diag++;
                            if (rev_diag == 3)
                            {
                                return true;
                            }
                        } // compare to symbol
                    }
                        
                } // fot j
        
            }//for i
            return false;
}
