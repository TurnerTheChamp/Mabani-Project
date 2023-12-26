#include <iostream>

using namespace std;

class Board
{
    const int dim_board = 6;

public:
    int board[6][6];

private:
    int grid[3][3];

public:
    Board()
    {
        for (int i = 0; i < dim_board; i++)
        {
            for (int j = 0; j < dim_board; j++)
            {
                board[i][j] = 0;
            }
        }
    }
    void print()
    {
        for (int i = 0; i < dim_board; i++)
        {
            for (int j = 0; j < dim_board; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    void crop(int input)
    {
        if (input == 1)
        {
            for (int i = 0; i < (dim_board) / 2; i++)
            {
                for (int j = 0; j < (dim_board) / 2; j++)
                {
                    grid[i][j] = board[i][j];
                }
            }
        }
        else if (input == 2)
        {
            int c;
            for (int i = 0; i < (dim_board / 2); i++)
            {
                c = 3;
                for (int j = 0; j < (dim_board / 2); j++)
                {
                    grid[i][j] = board[i][c];
                    c++;
                }
            }
        }
        else if (input == 3)
        {
            int r = 3;
            for (int i = 0; i < (dim_board / 2); i++)
            {
                for (int j = 0; j < (dim_board / 2); j++)
                {
                    grid[i][j] = board[r][j];
                }
                r++;
            }
        }
        else if (input == 4)
        {
            int r = 3;
            int c;
            for (int i = 0; i < (dim_board / 2); i++)
            {
                c = 3;
                for (int j = 0; j < (dim_board / 2); j++)
                {
                    grid[i][j] = board[r][c];
                    c++;
                }
                r++;
            }
        }
    }
    void rotate()
    {
        int rotated_grid[3][3];
        for (int i = 0; i < (dim_board / 2); i++)
        {
            for (int j = 0; j < (dim_board / 2); j++)
            {
                rotated_grid[i][j] = grid[2 - j][i];
            }
        }
        for (int i = 0; i < (dim_board / 2); i++)
        {
            for (int j = 0; j < (dim_board / 2); j++)
            {
                grid[i][j] = rotated_grid[i][j];
            }
        }
    }
    void join(int input)
    {
        if (input == 1)
        {
            for (int i = 0; i < (dim_board / 2); i++)
            {
                for (int j = 0; j < (dim_board / 2); j++)
                {
                    board[i][j] = grid[i][j];
                }
            }
        }
        else if (input == 2)
        {
            int c;
            for (int i = 0; i < (dim_board / 2); i++)
            {
                c = 3;
                for (int j = 0; j < (dim_board / 2); j++)
                {
                    board[i][c] = grid[i][j];
                    c++;
                }
            }
        }
        else if (input == 3)
        {
            int r = 3;
            for (int i = 0; i < (dim_board / 2); i++)
            {
                for (int j = 0; j < (dim_board / 2); j++)
                {
                    board[r][j] = grid[i][j];
                }
                r++;
            }
        }
        else if (input == 4)
        {
            int r = 3;
            int c;
            for (int i = 0; i < (dim_board / 2); i++)
            {
                c = 3;
                for (int j = 0; j < (dim_board / 2); j++)
                {
                    board[r][c] = grid[i][j];
                    c++;
                }
                r++;
            }
        }
    }

    bool hCheckWin()
    {
        bool pass;
        for (int j = 0; j < dim_board; j++)
        {
            pass = false;
            for (int i = 0; i < 2; i++)
            {
                if (board[j][i] != 0)
                {
                    for (int shift = 1; shift != 5; shift++)
                    {
                        if (board[j][i] != board[j][i + shift])
                        {
                            pass = true;
                            break;
                        }
                    }
                }
                else
                    pass = true;
                if (!pass)
                    break;
            }
            if (!pass)
                break;
        }
        return !pass;
    }

    bool vCheckWin()
    {
        bool pass;
        for (int i = 0; i < dim_board; i++)
        {
            pass = false;
            for (int j = 0; j < 2; j++)
            {
                if (board[j][i] != 0)
                {
                    for (int shift = 1; shift != 5; shift++)
                    {
                        if (board[j][i] != board[j + shift][i])
                        {
                            pass = true;
                            break;
                        }
                    }
                }
                else
                    pass = true;
                if (!pass)
                    break;
            }
            if (!pass)
                break;
        }
        return !pass;
    }
};

int main()
{
    Board table;
    for (int i = 0; i < 6; i++)
    {
        table.board[0][i] = 1;
    }
    for (int i = 0 ; i < 6 ; i++) {
        table.board[i][3] = -1;
        
    }
    // table.board[0][3] = -1;
    cout << table.hCheckWin() << endl;
    cout << table.vCheckWin() << endl;
    table.print();
}