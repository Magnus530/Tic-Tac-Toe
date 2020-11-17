#include <iostream>
#include <vector>
#include <algorithm>

int ticTacToe();

int main()
{
    char choice;

    /* This do while loop makes ticTacToe replayable by taking in the chars 'y' and 'Y'.
    Any other key returned by the player makes us exit the do while loop, and the game ends. */

    do
        {
            ticTacToe();

            std::cout << "Would you like to replay? Yes(y) or No(n)\n";
            std::cin >> choice;
        
            if (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore(32767, '\n');
                }

        } while (choice == 'y' || choice == 'Y');

        return(0);
}


int ticTacToe()
{
    

    /*The vector is assignet a char type to accept player1 and player2 who are also of char type, under the name
    of gameTile. */

    std::vector <char> gameTile{ '0', 'l', '2', '3', '4', '5', '6', '7', '8', '9' };

    bool gameWon = false;
    char player1{ 'X' }, player2{ 'O' };
    int tileChoice1{}, tileChoice2{};

    /* Writing welcome to TicTacToe outside the while loop, so it is only printed out at the start of the game,
     * or on a replay */

    std::cout << "************Welcome to TicTacToe!************\n" << std::endl;

    auto shortcut = [&gameTile](char tiles)
    {
        if (gameTile[1] == 'X' && gameTile[2] == 'X' && gameTile [3] == 'X')
        {
            return false;
        } 
    };  

 

    while (true)            // The game loops til a wincondition breaks out of the loop has yet to become true
    {

        /* Printing of the gameboard and player 1's first choice. We are now in the loop, so the turns will switch between player 1
        and player 2 as long as gameWon has yet to become true.*/

        std::cout << "\t\t_____________\n";
        std::cout << "\t\t| " << gameTile[1] << " | " << gameTile[2] << " | " << gameTile[3] << " |\n";
        std::cout << "\t\t| " << gameTile[4] << " | " << gameTile[5] << " | " << gameTile[6] << " |\n";
        std::cout << "\t\t| " << gameTile[7] << " | " << gameTile[8] << " | " << gameTile[9] << " |\n";
        std::cout << "\t\t|___|___|___|\n";

        std::cout << "\nPlayer 1, please write a number from: 1-9 that has yet to be chosen" << std::endl;
        std::cin >> tileChoice1;
        if (gameTile[tileChoice1] == gameTile[tileChoice2] || gameTile[tileChoice1] == 'X')
        {
            while (gameTile[tileChoice1] == gameTile[tileChoice2] || gameTile[tileChoice1] == 'X')
            {
                std::cout << "That tile is occupied, please select another number.\n";
                std::cin >> tileChoice1;
                std::endl(std::cout);
            }
            gameTile[tileChoice1] = player1;
        }
        else if (gameTile[tileChoice1] != gameTile[tileChoice2])
        {
            gameTile[tileChoice1] = player1;
        }

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        }

        /* In this section one can see the win conditions. If there are 3 'X''s or 'O''s in a row, column or diagonally,
        break out of the loop, and a winner is declared depending on who has 3 in a row. We then go from the while
        loop to the main function.*/

        if (((gameTile[1] == 'X') && (gameTile[2] == 'X') && (gameTile[3] == 'X')) || ((gameTile[4] == 'X')
            && (gameTile[5] == 'X') && (gameTile[6] == 'X')) || ((gameTile[7] == 'X') && (gameTile[8] == 'X')
                && (gameTile[9] == 'X')) || ((gameTile[1] == 'X') && (gameTile[4] == 'X') && (gameTile[7] == 'X')) || ((gameTile[2] == 'X')
                    && (gameTile[5] == 'X') && (gameTile[8] == 'X')) || ((gameTile[3] == 'X') && (gameTile[6] == 'X')
                        && (gameTile[9] == 'X')) || ((gameTile[1] == 'X')
                            && (gameTile[5] == 'X') && (gameTile[9] == 'X')) || ((gameTile[3] == 'X') && (gameTile[5] == 'X')
                                && (gameTile[7] == 'X')))

        
        
        {
            std::cout << "\t\t_____________\n";
            std::cout << "\t\t| " << gameTile[1] << " | " << gameTile[2] << " | " << gameTile[3] << " |\n";
            std::cout << "\t\t| " << gameTile[4] << " | " << gameTile[5] << " | " << gameTile[6] << " |\n";
            std::cout << "\t\t| " << gameTile[7] << " | " << gameTile[8] << " | " << gameTile[9] << " |\n";
            std::cout << "\t\t|___|___|___|\n";

            std::cout << "\nTictactoe, that's three in a row. Congratulations player 1, you win!\n";
            break;
        }


        /* In this part the board is being checked to see if all the available gameTiles are 'X' and 'O'. If they all are, a tie is called,
         we exit the while loop and return to the main function. */

        if ((((gameTile[1] == 'X') || (gameTile[1] == 'O')) && ((gameTile[2] == 'X') ||
            (gameTile[2] == 'O'))) && (((gameTile[3] == 'X') || (gameTile[3] == 'O'))) &&
            (((gameTile[4] == 'X') || (gameTile[4] == 'O')) && ((gameTile[5] == 'X') ||
                (gameTile[5] == 'O'))) && (((gameTile[6] == 'X') || (gameTile[6] == 'O'))) &&
            (((gameTile[7] == 'X') || (gameTile[7] == 'O')) && ((gameTile[8] == 'X') ||
                (gameTile[8] == 'O'))) && (((gameTile[9] == 'X') || (gameTile[9] == 'O'))))
        {

            std::cout << "\t\t_____________\n";
            std::cout << "\t\t| " << gameTile[1] << " | " << gameTile[2] << " | " << gameTile[3] << " |\n";
            std::cout << "\t\t| " << gameTile[4] << " | " << gameTile[5] << " | " << gameTile[6] << " |\n";
            std::cout << "\t\t| " << gameTile[7] << " | " << gameTile[8] << " | " << gameTile[9] << " |\n";
            std::cout << "\t\t|___|___|___|\n";

            std::cout << "Thats a tie!\n";
            break;
        }


        /* It is now player 2's turn to pick the second tile */

        std::cout << "\t\t_____________\n";
        std::cout << "\t\t| " << gameTile[1] << " | " << gameTile[2] << " | " << gameTile[3] << " |\n";
        std::cout << "\t\t| " << gameTile[4] << " | " << gameTile[5] << " | " << gameTile[6] << " |\n";
        std::cout << "\t\t| " << gameTile[7] << " | " << gameTile[8] << " | " << gameTile[9] << " |\n";
        std::cout << "\t\t|___|___|___|\n";

        std::cout << "\nPlayer 2, please write a number from: 1-9 that has yet to be chosen" << std::endl;
        std::cin >> tileChoice2;
        if ((gameTile[tileChoice2] == gameTile[tileChoice1]) || (gameTile[tileChoice2] == 'O'))            /*Here player 2's tilechoice is compared to player 1's tile choice. If their tile choice is the same then player 2 has to choose again, if player 2 chose this tile before. Player 2 also has to choose a new tile again.*/
        {
            while ((gameTile[tileChoice2] == gameTile[tileChoice1]) || (gameTile[tileChoice2] == 'O'))
            {
                std::cout << "That tile is occupied, please select a another number.\n";
                std::cin >> tileChoice2;                                                        /*Here player 2's choice is being taken in, if the game tile is free. We make it equal to 'O' */
                std::endl(std::cout);
            }
            gameTile[tileChoice2] = player2;
        }
        else if ((gameTile[tileChoice2]) != (gameTile[tileChoice1]))
        {
            gameTile[tileChoice2] = player2;
        }

        if (std::cin.fail())        /* A test if cin fails, if it does ignore the input. */
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        }

        /* In this section one can see the win conditions. If there are 3 'X''s or 'O''s in a row, column or diagonally,
        gameWon is to be returned true, and a winner is declared depending on who has 3 in a row. We then go from the while
        loop to the main function.*/

        if (((gameTile[1] == 'O') && (gameTile[2] == 'O') && (gameTile[3] == 'O')) || ((gameTile[4] == 'O')
            && (gameTile[5] == 'O') && (gameTile[6] == 'O')) || ((gameTile[7] == 'O') && (gameTile[8] == 'O')
                && (gameTile[9] == 'O')) || ((gameTile[1] == 'O') && (gameTile[4] == 'O') && (gameTile[7] == 'O')) || ((gameTile[2] == 'O')
                    && (gameTile[5] == 'O') && (gameTile[8] == 'O')) || ((gameTile[3] == 'O') && (gameTile[6] == 'O')
                        && (gameTile[9] == 'O')) || ((gameTile[1] == 'O')
                            && (gameTile[5] == 'O') && (gameTile[9] == 'O')) || ((gameTile[3] == 'O') && (gameTile[5] == 'O')
                                && (gameTile[7] == 'O')))
        {
            std::cout << "\t\t_____________\n";
            std::cout << "\t\t| " << gameTile[1] << " | " << gameTile[2] << " | " << gameTile[3] << " |\n";
            std::cout << "\t\t| " << gameTile[4] << " | " << gameTile[5] << " | " << gameTile[6] << " |\n";
            std::cout << "\t\t| " << gameTile[7] << " | " << gameTile[8] << " | " << gameTile[9] << " |\n";
            std::cout << "\t\t|___|___|___|\n";

            std::cout << "\nTictactoe, that's three in a row. Congratulations player 2, you win!\n";
            break;
        }



    }


    return(0);
}

