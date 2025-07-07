#include <iostream>

enum type_memory {mem_none = -1, mem_corsair = 1, mem_adata = 2, mem_kingston = 3};

class Memory {
    unsigned volume {0}; // объем ОЗУ в Мб
    type_memory type {mem_none}; // тип (производитель) ОЗУ

public:
    Memory(unsigned volume = 0) : volume(volume), type(mem_none)
    {}
    Memory(unsigned volume, type_memory type) : Memory(volume)
    { this->type = type; }
    friend void set_memory_data(Memory& mem, unsigned vol, type_memory tp); // заносит в поля volume и type объекта mem переданные значения
    friend void get_memory_data(const Memory& mem, unsigned& vol, type_memory& tp); // возвращает значение полей volume и type объекта mem
    friend Memory operator + (const Memory& left, const Memory& right);
};

void set_memory_data(Memory& mem, unsigned vol, type_memory tp)
{ mem.type = tp; mem.volume = vol; } // заносит в поля volume и type объекта mem переданные значения
void get_memory_data(const Memory& mem, unsigned& vol, type_memory& tp)
{ tp = mem.type; vol = mem.volume; } // возвращает значение полей volume и type объекта mem
Memory operator + (const Memory& left, const Memory& right)
{
    if (left.type == right.type)
        return Memory(left.volume + right.volume, left.type);
    return left;
}

int main(void)
{
    // здесь продолжайте функцию main
    Memory mem_1(8000, mem_adata), mem_2(4000, mem_adata);
    Memory res = mem_1 + mem_2;
    unsigned vol;
    type_memory tp;
    get_memory_data(res, vol, tp);
    std::cout << vol << " " << tp;
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}