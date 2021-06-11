#ifndef _MATRIX
    #include "rdarray.h"

    #define _MATRIX
#endif

namespace sudoku{
    class matrix{
        public:
        bool you_win();
        void write(int i, int j, int val);
        void new_puzzle();
        void solve();
        void reset();
        int read(int i, int j);
        int output(int (*mat)[10]);
        int input(int (*mat)[10]);
        matrix(int (*mat)[10]);
        matrix();

        private:
        int obj[9][9];
        int row[9];
        int col[9];
        int block[5][5];
        int ne[9][9];
        sudoku::rdarray ra;
        int dfs(int ni, int nj);
        void empty();
        void init();
    };
}
