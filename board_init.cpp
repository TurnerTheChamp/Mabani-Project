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
    int insert(int x, int y, bool bcolor)
    {
        int color;
        if (bcolor)
            color = 1;
        else
            color = -1;

        if (board[x][y] == 0)
        {
            board[x][y] = color;
            return 0;
        }
        else
            return 1;
    }
    int hCheckWin()
    {
        bool pass;
        int winner = 0;
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
                    winner = board[j][i];
                break;
            }
            if (!pass)
                break;
        }
        return winner;
    }
    int vCheckWin()
    {
        bool pass;
        int winner = 0;
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
                {
                    winner = board[j][i];
                    break;
                }
            }
            if (!pass)
                break;
        }
        return winner;
    }
    int dCheckWin()
    {
        int winner = 0;
        bool pass;
        for (int i = 0; i < 2; i++)
        {
            pass = false;
            for (int j = 0; j < 2; j++)
            {
                if (board[j][i] != 0)
                {
                    for (int shift = 1; shift != 5; shift++)
                    {
                        if (board[j][i] != board[j + shift][i + shift])
                        {
                            pass = true;
                            break;
                        }
                    }
                }
                else
                    pass = true;
                if (!pass)
                {
                    winner = board[j][i];
                    break;
                }
            }
            if (!pass)
                break;
        }
        return winner;
    }
    int checkWin()
    {
        if (hCheckWin() != 0)
            return hCheckWin();
        else if (vCheckWin() != 0)
            return vCheckWin();
        else if (dCheckWin() != 0)
            return dCheckWin();
        else
            return 2;
    }
    bool checkFull()
    {
        for (int i = 0; i < dim_board; i++)
        {
            for (int j = 0; j < dim_board; j++)
            {
                if (board[i][j] == 0)
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    Board table;
    int x, y, grid_num;
    bool bead_color = false;
    while (true)
    {
        table.print();
        if (bead_color == false)
            bead_color = true;
        else if (bead_color == true)
            bead_color = false;
        if (table.checkFull())
            break;
        cout << "x , y> ";
        cin >> x >> y;
        cout << endl;
        table.insert(x, y, bead_color);
        table.print();
        cout << endl;
        if (table.checkWin() != 2)
            break;
        cout << "grid num> ";
        cin >> grid_num;
        cout << endl;
        table.crop(grid_num);
        table.rotate();
        table.join(grid_num);
        table.print();
        cout << endl
             << endl;
        if (table.checkWin() != 2)
            break;
    }
    if (table.checkFull())
    {
        for (int i = 0; i < 10; i++)
        {
            cout << "grid num> ";
            cin >> grid_num;
            cout << endl;
            table.crop(grid_num);
            table.rotate();
            table.join(grid_num);
            table.print();
            cout << endl;
            if (table.checkWin() != 2)
                break;
        }
    }
    cout << table.checkWin() << endl;
}