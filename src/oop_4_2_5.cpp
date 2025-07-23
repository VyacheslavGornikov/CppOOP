#include <iostream>
#include <string>

class Thing {
protected:
    std::string name;
    int price {0};
public:
    Thing() = default;
    Thing(const std::string& name, int price) : name(name), price(price)
    {}
    void set_base_info(const std::string& name, int& price)
    {
        this->name = name; this->price = price;
    }
    void get_base_info(std::string& name, int& price)
    {
        name = this->name; price = this->price;
    }
};

class TV : public Thing
{
    int size {0};
    double weight {0.0};
public:
    TV(const std::string& name, int price, int size, double weight) :
    Thing(name, price) { this->size = size; this->weight = weight; }
    void get_data(std::string& name, int& price, int& size, double& weight)
    {
        name = this->name;
        price = this->price;
        size = this->size;
        weight = this->weight;
    }
};

class Book : public Thing
{
    std::string author;
    int pages {0};
public:
    Book(const std::string& name, int price, const std::string& author, int pages) :
    Thing(name, price) { this->author = author; this->pages = pages; }
    void get_data(std::string& name, int& price, std::string& author, int& pages)
    {
        name = this->name;
        price = this->price;
        author = this->author;
        pages = this->pages;
    }
};

class Store : public Thing
{
    enum {max_total = 100}; // максимальное количество товаров
    Thing* things[max_total] { nullptr }; // товары магазина
    int total {0}; // текущее количество товаров
public:
    Store() = default;
    void append(Thing* th)
    {
        if (total < max_total) things[total++] = th;
    } // добавление товара th в конец массива things (хранится указатель на объект)
    Thing* operator[](int index)
    {
        return (index >= 0 && index < total) ? things[index] : nullptr;
    } // возвращает указатель на товар массива things по индексу index; если index неверный, возвращается nullptr
    int get_total() const { return total; } // возвращает значение поля total
    ~Store()
    {
        for (int i = 0; i < total; i++)
        {
            delete things[i];
        }
    }
};

int main(void)
{
    // здесь продолжайте функцию main
    Store st;

    st.append(new TV("Samsung", 54300, 43, 5.4));
    st.append(new Book("C++", 2000, "Balakirev", 543));
    st.append(new TV("Sony", 97000, 80, 7.5));
    auto obj = (Book*) st[1];
    std::string name; int price; std::string author; int pages;
    obj->get_data(name, price, author, pages);
    std::cout << name << " " << price << " " << author << " " << pages <<
    std::endl;

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}