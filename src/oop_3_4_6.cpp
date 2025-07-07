#include <iostream>

class TicTacToe {
    enum { size_pole = 3 };
    char pole[size_pole * size_pole] {0}; // игровое поле
    class Cell
    {
        TicTacToe* item {nullptr};
        int index_row {0};
    public:
        Cell(TicTacToe* item, int index) : item(item), index_row(index)
        {}
        char& operator[] (int index_col)
        { return item->pole[index_row * item->size_pole + index_col]; }
    };


public:
    TicTacToe() = default;
    const char* get_pole() const { return pole; }
    int get_size() const { return size_pole; }
    Cell operator [] (int index_row) { return Cell(this, index_row); }
};


int main(void)
{
    // здесь продолжайте функцию main

    TicTacToe *ptr_game = new TicTacToe();
    (*ptr_game)[0][0] = 'x';
    (*ptr_game)[1][1] = 'x';
    (*ptr_game)[2][2] = 'x';

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    // здесь освобождайте память
    delete ptr_game;
    return 0;
}