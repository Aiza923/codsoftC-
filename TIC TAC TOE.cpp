#include <iostream>
using namespace std;

char arr[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

int checkwin();
void board();
void resetBoard();

void resetBoard()
{
    
    arr[0][0] = '1';
    arr[0][1] = '2';
    arr[0][2] = '3';
    arr[1][0] = '4';
    arr[1][1] = '5';
    arr[1][2] = '6';
    arr[2][0] = '7';
    arr[2][1] = '8';
    arr[2][2] = '9';
}

void board()
{
    system("cls");
    cout << "\n\n\n";
    cout << "\n\n\n";
    cout << "\t\t\t\t ***** ***** *****   ***** ***** *****   ***** ***** *****  " << endl;
    cout << "\t\t\t\t   *     *   *         *   *   * *         *   *   * *      " << endl;
    cout << "\t\t\t\t   *     *   *         *   ***** *         *   *   * *****  " << endl;
    cout << "\t\t\t\t   *     *   *         *   *   * *         *   *   * *      " << endl;
    cout << "\t\t\t\t   *   ***** *****     *   *   * *****     *   ***** *****  " << endl;
    cout << "\n\n\n";
    cout << "\t\t The symbol for player 1 is 'X' and the symbol for player 2 is 'O'." << endl;
    cout << "\n\n\n";
    cout << "\t\t\t\t\t\t\t   |     |    \t\t\t" << endl;
    cout << "\t\t\t\t\t\t\t " << arr[0][0] << " |  " << arr[0][1] << "  | " << arr[0][2] << "  \t\t\t" << endl;
    cout << "\t\t\t\t\t\t\t___|_____|____\t\t\t" << endl;
    cout << "\t\t\t\t\t\t\t   |     |    \t\t\t" << endl;
    cout << "\t\t\t\t\t\t\t " << arr[1][0] << " |  " << arr[1][1] << "  | " << arr[1][2] << "  \t\t\t" << endl;
    cout << "\t\t\t\t\t\t\t___|_____|____\t\t\t" << endl;
    cout << "\t\t\t\t\t\t\t   |     |    \t\t\t" << endl;
    cout << "\t\t\t\t\t\t\t " << arr[2][0] << " |  " << arr[2][1] << "  | " << arr[2][2] << "  \t\t\t" << endl;
    cout << "\t\t\t\t\t\t\t   |     |    \t\t\t" << endl;
}

int checkwin()
{
    for (int i = 0; i < 3; i++)
    {
        if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2])
            return 1; // Rows

        if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i])
            return 1; // Columns
    }

    if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2])
        return 1; // Diagonal

    if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0])
        return 1; // Anti-Diagonal

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] != 'X' && arr[i][j] != 'O')
                return -1; // Game in progress
        }
    }
    
    return 0; // Draw
}

int main()
{
    int player = 2, choice;
    char mark;
    char playAgain;

    do
    {
        resetBoard(); // Reset the board for a new game

        do
        {
            board();

            player = 3 - player; // Alternate between Player 1 and Player 2

            cout << "Player " << player << ", enter a number: ";
            cin >> choice;

            char mark = (player == 1) ? 'X' : 'O';


            if (choice >= 1 && choice <= 9 && arr[(choice - 1) / 3][(choice - 1) % 3] == '1' + choice - 1)
                arr[(choice - 1) / 3][(choice - 1) % 3] = mark;
            else
            {
                cout << "Invalid move. Please try again." << endl;
                player--;
                cin.ignore();
                cin.get();
            }

        } while (checkwin() == -1);

        board();

        int winner = checkwin();


if (winner == 1)
    cout << " Player " << 3 - player << " wins!";
else if (winner == 0)
    cout << " The match is a draw.";


        cout << "\nDo you want to play again? (Y or N): ";
        cin >> playAgain;

    } while (playAgain == 'Y' || playAgain == 'y');

    return 0;
}

