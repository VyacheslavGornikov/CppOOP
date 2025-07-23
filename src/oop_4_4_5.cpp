#include <iostream>
#include <string>
#include <memory>

// здесь объявляйте классы

class Dish
{
protected:
    std::string name; // наименование
    int price {0}; // цена
public:
    Dish(const std::string& name, int price) : name(name), price(price)
    {}
    virtual void print_dish() { printf("Dish: %s; %d\n", name.c_str(), price); } // выводит информацию о блюде в выходной поток
};

class FishDish : public Dish
{
    int weight {0};
public:
    FishDish(const std::string& name, int price, int weight) : Dish(name, price), weight(weight)
    {}
    void print_dish() { printf("FishDish: %s; %d; %d\n", name.c_str(), price, weight); }
};

class MeatDish : public Dish
{
    short fry_type {1};
    int weight {0};
public:
    MeatDish(const std::string& name, int price, short fry_type, int weight) :
    Dish(name, price), fry_type(fry_type), weight(weight)
    {}
    void print_dish() { printf("MeatDish: %s; %d; %hd; %d\n", name.c_str(), price, fry_type, weight); }
};

int main(void)
{
    // здесь продолжайте функцию main

    std::unique_ptr<FishDish> ptr_fd_1 =
            std::make_unique<FishDish>("Устрицы", 900, 300);
    std::unique_ptr<MeatDish> ptr_md_1 =
            std::make_unique<MeatDish>("Бекон", 800, 2, 420);
    std::unique_ptr<FishDish> ptr_fd_2 =
            std::make_unique<FishDish>("Форель", 400, 210);
    Dish* dishes[3] =
    {
        ptr_fd_1.get(),
        ptr_md_1.get(),
        ptr_fd_2.get()
    };

    for (Dish* dish : dishes)
        dish->print_dish();

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    // здесь освобождайте память
    return 0;
}