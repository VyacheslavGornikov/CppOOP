#include <iostream>
#include <string>

enum { max_size = 100 };

class CommonInterface {
public:
    virtual long long get_id() const = 0;
    virtual void set_id(long long id) = 0;
    virtual ~CommonInterface() = default;
};

class Thing : public CommonInterface
{
    long long id {0};
    std::string name;
    int price {0};
public:
    Thing(long long id, const std::string& name, int price) : id(id), name(name), price(price) {}
    virtual long long get_id() const { return id; } // возвращает значение поля id
    virtual void set_id(long long id) { this->id = id; } // меняет значение поля id
    const std::string& get_name() const { return name; } // возвращает значение поля name
    int get_price() const { return price; } // возвращает значение поля price
};

// здесь объявляйте классы

int main(void)
{
    // здесь продолжайте функцию main
    CommonInterface* lst[max_size] {nullptr};
    int lst_count = 4;
    lst[0] = new Thing(4, "Book C++", 2500);
    lst[1] = new Thing(1, "Computer HP", 125000);
    lst[2] = new Thing(10, "Mouse Lg", 4300);
    lst[3] = new Thing(19, "Monitor Samsung", 9560);

    for (int i = 0; i < lst_count; i++)
    {
        std::cout << lst[i]->get_id();
        if (i != lst_count - 1) std::cout << " ";
    }

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    // здесь освобождайте память (если необходимо)
    for (int i = 0; i < lst_count; i++)
        delete lst[i];
    return 0;
}