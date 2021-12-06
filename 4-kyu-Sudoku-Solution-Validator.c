#include<stdbool.h>

bool validSolution(unsigned int board[9][9]) {

    for (int j = 0; j < 9; ++j) {
        int line[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
        for (int i = 0; i < 9; ++i) {
            if (board[j][i] == 0)return false;
            line[board[j][i] - 1] -= 1;
        }
        for (int i = 0; i < 9; ++i) {
            if (line[i] != 0) return false;
        }
    }

    for (int j = 0; j < 9; ++j) {
        int line[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
        for (int i = 0; i < 9; ++i) {
            if (board[i][j] == 0)return false;
            line[board[i][j] - 1] -= 1;
        }
        for (int i = 0; i < 9; ++i) {
            if (line[i] != 0) return false;
        }
    }

    for (int i = 0; i < 3; ++i) {
        for (int l = 0; l < 3; ++l) {
            int line[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
            for (int j = i * 3; j < (i + 1) * 3; ++j) {
                for (int k = l * 3; k < (l + 1) * 3; ++k) {
                    if (board[j][k] == 0)return false;
                    line[board[j][k] - 1] -= 1;
                }
            }
            for (int j = 0; j < 9; ++j) {
                if (line[i] != 0)return false;
            }
        }
    }

    return true;
}
