#include <iostream>

using namespace std;

class Board
{
    const int dim_board = 6;
    string board[6][6];
    public:
        Board() {
            int counter = 0;
            for (int i = 0; i<6; i++) {
                for (int j = 0; j<6; j++) {
                    board[i][j]="0";
                }
            }
        }
        void print()
        {
            for (int i = 0; i < 6; i++)
            {
                for (int j = 0; j < 6; j++)
                {
                    cout << board[i][j] << " ";
                }
                cout << endl;
            }
        }
        void crop(int input, string (&grid)[3][3]) {
            if(input == 1) {
                for(int i=0; i<3; i++) {
                    for(int j=0; j<3; j++) {
                        grid[i][j]=board[i][j];
                    }
                }
            }
            else if(input == 2) {
                int c;
                for(int i=0; i<3; i++) {
                    c=3;
                    for(int j=0; j<3; j++) {
                        grid[i][j]=board[i][c];
                        c++;
                    }
                }
            } 
            else if(input == 3) {
                int r = 3;
                for(int i=0; i<3; i++) {
                    for(int j=0; j<3; j++) {
                        grid[i][j]=board[r][j];
                    }
                    r++;
                }
            }
            else if(input == 4) {
                int r = 3;
                int c;
                for(int i=0; i<3; i++) {
                    c = 3;
                    for(int j=0; j<3; j++) {
                        grid[i][j]=board[r][c];
                        c++;
                    }
                    r++;
                }
            }
        }
        void rotate(string (&grid)[3][3]) {
            string rotated_grid[3][3];
            for(int i = 0; i<3; i++) {
                for(int j = 0;  j<3; j++){
                    rotated_grid[i][j] = grid[2-j][i];
                }
            }
            for(int i = 0; i<3; i++) {
                for(int j = 0;  j<3; j++){
                    grid[i][j] = rotated_grid[i][j];
                }
            }
        }
        void join(int input, string grid[3][3]) {
            if(input == 1) {
                for(int i=0; i<3; i++) {
                    for(int j=0; j<3; j++) {
                        board[i][j]=grid[i][j];
                    }
                }
            }
            else if(input == 2) {
                int c;
                for(int i=0; i<3; i++) {
                    c=3;
                    for(int j=0; j<3; j++) {
                        board[i][c]=grid[i][j];
                        c++;
                    }
                }
            } 
            else if(input == 3) {
                int r = 3;
                for(int i=0; i<3; i++) {
                    for(int j=0; j<3; j++) {
                        board[r][j]=grid[i][j];
                    }
                    r++;
                }
            }
            else if(input == 4) {
                int r = 3;
                int c;
                for(int i=0; i<3; i++) {
                    c = 3;
                    for(int j=0; j<3; j++) {
                        board[r][c]=grid[i][j];
                        c++;
                    }
                    r++;
                }
            }
        }
};

int main() {
    Board obj;
    string grid[3][3];
    int input;
    cin>>input;
    obj.crop(input, grid);
    obj.rotate(grid);
    obj.join(input, grid);
    obj.print();
}
