#include <iostream>

// здесь объявляйте класс
enum type_filter {flt_aragon = 1, flt_calcium = 2};

class FilterWater {
    type_filter type; // тип фильтра
    unsigned date; // дата установки фильтра
    unsigned short volume; // объем фильтра
public:
    FilterWater(type_filter t, unsigned d, unsigned short v) : type(t), date(d), volume(v)
        { }
    friend type_filter get_type_filter(const FilterWater& flt); // возвращает значение поля type
    friend unsigned get_date_filter(const FilterWater& flt); // возвращает значение поля date
    friend unsigned short get_volume_filter(const FilterWater& flt); // возвращает значение поля volume
};

type_filter get_type_filter(const FilterWater& flt) { return flt.type; } // возвращает значение поля type
unsigned get_date_filter(const FilterWater& flt) { return flt.date; } // возвращает значение поля date
unsigned short get_volume_filter(const FilterWater& flt) { return flt.volume; } // возвращает значение поля volume

int main(void)
{
    // здесь продолжайте функцию main
    FilterWater filter(flt_calcium, 153564646, 108);
    std::cout << get_type_filter(filter) << " " << get_date_filter(filter) <<
    " " << get_volume_filter(filter) << std::endl;
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}