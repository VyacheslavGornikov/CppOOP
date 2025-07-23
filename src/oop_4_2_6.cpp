#include <iostream>

enum type_filter_water {
        flt_none = 0,
        flt_mechanical = 1,
        flt_aragon = 2,
        flt_calcium = 3
    };

class FilterWater
{
protected:
    unsigned date {0}; // дата установки фильтра (начало работы)
    type_filter_water type {flt_none}; // тип фильтра
public:
    FilterWater(unsigned date = 0) : date(date)
    {}
    unsigned get_date() const { return date; } // возвращает значение поля date
    type_filter_water get_type() const { return type; } // возвращает значение поля type
};

class Mechanical : public FilterWater
{
public:
    Mechanical(unsigned date = 0) : FilterWater(date) { type = flt_mechanical; }
};

class Aragon : public FilterWater
{
public:
    Aragon(unsigned date = 0) : FilterWater(date) { type = flt_aragon; }
};


class Calcium : public FilterWater
{
public:
    Calcium(unsigned date = 0) : FilterWater(date) { type = flt_calcium; }
};

class GeyserClassic
{
public:
    enum { total_slots = 3 };
private:
    FilterWater* slots[total_slots] {nullptr}; // слоты с фильтрами для воды
public:
    GeyserClassic(FilterWater* slot1 = nullptr, FilterWater* slot2 = nullptr,
                  FilterWater* slot3 = nullptr)
    {
        add_filter(1, slot1);
        add_filter(2, slot2);
        add_filter(3, slot3);
    }

    const FilterWater* operator[](int index) const
    { return (index >=0 && index < total_slots) ? slots[index] : nullptr; } // получение фильтра (из массива slots) по индексу index; если index неверный, то возвращается nullptr; если фильтр в текущем слоте отсутствует, то возвращается nullptr

    void add_filter(int slot_num, FilterWater* filter)
    {
        if (slot_num < 1 || slot_num > 3) return;

        if (filter == nullptr || slots[slot_num - 1] != nullptr) return;

        const type_filter_water expected_types[] = {
            flt_mechanical,
            flt_aragon,
            flt_calcium
        };

        if (filter->get_type() == expected_types[slot_num - 1])
            slots[slot_num - 1] = filter;
    } // добавление filter в слот с номером slot_num (нумерация: 1, 2, 3)
};

int main(void)
{
    Mechanical filter_1(100);
    Aragon filter_2(100);
    Calcium filter_3(100);

    GeyserClassic gc_1;
    std::cout << "gc_1" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        if (gc_1[i] != nullptr)
        {
            std::cout << gc_1[i]->get_date() << " " << gc_1[i]->get_type() <<
            std::endl;
        }
    }

    GeyserClassic gc_2(&filter_1); // filter_1 для 1-го слота (два остальных nullptr)
    std::cout << "gc_2" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        if (gc_2[i] != nullptr)
        {
            std::cout << gc_2[i]->get_date() << " " << gc_2[i]->get_type() <<
            std::endl;
        }
    }

    GeyserClassic gc_3(&filter_1, &filter_2); // filter_1 для 1-го слота; filter_2 для 2-го слота
    std::cout << "gc_3" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        if (gc_3[i] != nullptr)
        {
            std::cout << gc_3[i]->get_date() << " " << gc_3[i]->get_type() <<
            std::endl;
        }
    }

    GeyserClassic gc_4(&filter_1, &filter_2, &filter_3); // каждый фильтр в свой слот (по порядку)
    std::cout << "gc_4" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        if (gc_4[i] != nullptr)
        {
            std::cout << gc_4[i]->get_date() << " " << gc_4[i]->get_type() <<
            std::endl;
        }
    }



    return 0;
}