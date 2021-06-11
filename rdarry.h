#ifndef RDARRY_H
#define RDARRY_H


namespace sudoku{
    class rdarray{
        public:
            rdarray();
            void narray();
            int read(int i);

        private:
            int array[10];
            int rdseed;
    };

#endif // RDARRY_H
}
