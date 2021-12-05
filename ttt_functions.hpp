//
//  ttt_functions.hpp
//  
//
//  Created by Giorgio Figus on 05/12/2021.
//

#ifndef ttt_functions_hpp
#define ttt_functions_hpp

#include <iostream>

const int m_size = 3;
void userChoice (int& colum, int& row, const char m[m_size][m_size] );

void displayMatrix( const char matr [m_size ] [m_size] );
//check status 0 keep playng,  1 draft, 2 P1x win, p2O win
bool playerWin (const char m [m_size ] [m_size], const char& symbol);
    
#endif /* ttt_functions_hpp */
