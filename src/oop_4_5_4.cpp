#include <iostream>
#include <string>

// здесь объявляйте классы
class Equipment
{
    inline static unsigned long next_uid {1};
    unsigned long uid {0}; // идентификатор
protected:
    bool is_exists {false}; // наличие оборудования
public:
    Equipment(bool is_exists = false) : is_exists(is_exists), uid(next_uid++) {}
    unsigned long get_uid() const { return uid; } // возвращает значение поля uid
    virtual void print() const { } // виртуальный метод, переопределяемый в дочерних классах
    virtual ~Equipment() { }
};

class PC : public Equipment
{
    std::string model; // модель компьютера
    int price {0}; // цена
public:
    PC(const std::string model, int price, bool is_exists) :
            Equipment(is_exists), model(model), price(price) { }
    const std::string get_model() const { return model; } // возвращает значение поля model
    int get_price() const { return price; } // возвращает значение поля price
    virtual void print() const override
    { printf("PC: %s, %d, %d\n", model.c_str(), price, is_exists); } // переопределяемый виртуальный метод
    virtual ~PC() { puts("~PC"); }
};

