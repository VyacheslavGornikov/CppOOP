#include <iostream>

class ExceptionIndexError
{
    int row{0}, col{0}; // индексы (ошибочные)
public:
    ExceptionIndexError(int row, int col) : row(row), col(col) {}
    int get_row() const { return row; } // возвращает значение поля row
    int get_col() const { return col; } // возвращает значение поля col
};

class TicTacToe {
    enum { size_pole = 3 };
    char pole[size_pole * size_pole] {0}; // игровое поле
    class RowData
    {
        TicTacToe* obj_this {nullptr};
        int index_row {0};
    public:
        RowData(TicTacToe* obj, int idx_row) : obj_this(obj), index_row(idx_row)
            {}
        char& operator[] (int index_col)
        {
            if (index_row < 0 || index_row >= size_pole ||
                index_col < 0 || index_col >= size_pole)
                throw ExceptionIndexError(index_row, index_col);
            return obj_this->pole[index_row * size_pole + index_col];
        }
    };
public:
    TicTacToe() = default;
    const char* get_pole() const { return pole; }
    int get_size() const { return size_pole; }

    RowData operator[] (int idx_row)
    {
        return RowData(this, idx_row);
    }
};

int main()
{
    // здесь продолжайте функцию main
    TicTacToe game;


    try
    {
        game[0][1] = 'o';
        game[1][1] = 'x';
        game[4][2] = 'x';
    }
    catch(const ExceptionIndexError& e)
    {
        std::cout << "Incorrect index: " << e.get_row() << ", " << e.get_col();
    }

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    return 0;
}