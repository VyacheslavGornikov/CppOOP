#include <iostream>
#include <string>

class Thing
{
    unsigned id {0}; // идентификатор
protected:
    std::string name; // название
    int price {0}; // цена
public:
    Thing() = default;
    Thing(const std::string& name, int price) : name(name), price(price)
    {}
    void set_data(const std::string& name, int price) { this->name = name; this->price = price; } // заносит в поля name и price переданные значения
    unsigned get_id() const { return id; } // возвращает значение поля id
    std::string get_name() const { return name; } // возвращает значение поля name
    int get_price() const { return price; } // возвращает значение поля price
};

class ThingPhisical : public Thing
{
    unsigned width {0}, height {0}, depth {0}; // габариты товара
    double weight {0.0}; // вес товара
public:
    ThingPhisical() = default;
    ThingPhisical(const std::string& name, int price) : Thing(name, price) {}
    ThingPhisical(const std::string& name, int price,
    unsigned width, unsigned height, unsigned depth, double weight) : ThingPhisical(name, price)
    {
        set_dims(width, height, depth);
        set_weight(weight);
    }
    void set_dims(unsigned width, unsigned height, unsigned depth)
    {
        this->width = width; this->height = height; this->depth = depth;
    } // заносит в поля width, height, depth переданные значения
    void set_weight(double weight) { this->weight = weight; } // заносит в поле weight переданное значение
    void get_dims(unsigned& width, unsigned& height, unsigned& depth) const
    { width = this->width; height = this->height; depth = this->depth; } // возвращает габариты товара
    double get_weight() const { return weight; } // возвращает вес товара
};

class ThingElectro : public Thing
{
    unsigned volume {0}; // объем в килобайтах
public:
    ThingElectro() = default;
    ThingElectro(const std::string& name, int price) : Thing(name, price)
    {}
    ThingElectro(const std::string& name, int price, unsigned volume) : Thing(name, price)
    { set_volume(volume); }
    void set_volume(unsigned volume) { this->volume = volume; } // заносит в поле volume переданное значение
    unsigned get_volume() const { return volume; } // возвращает значение поля volume
};
