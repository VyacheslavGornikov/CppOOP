#include <iostream>
#include <cstring>

// здесь объявляйте класс
class StringChars
{
private:
    char* buffer {nullptr}; // массив символов строки
    size_t length {0}; // длина строки (число символов)
public:
    StringChars(const char *str);
    StringChars operator= (const StringChars& right) { return StringChars(buffer); }
    StringChars operator+ (const StringChars& right);
    StringChars(const StringChars& other); // Конструктор копирования
    ~StringChars();
    char* to_str() const; // возвращает массив buffer
    size_t get_length() const; // возвращает значение поля length

};

StringChars::StringChars(const char *str)
{
    length = strlen(str);
    buffer = (char*)malloc(length + 1);
    strncpy(buffer, str, length + 1);    
}

// Конструктор копирования
StringChars::StringChars(const StringChars& other) {
    length = other.length;
    buffer = (char*)malloc(length + 1);
    strncpy(buffer, other.buffer, length + 1);
}

StringChars::~StringChars() { if (buffer != NULL) free(buffer); }

StringChars StringChars::operator+ (const StringChars& right)
{
    // std::string result = std::string(buffer) + std::string(right.buffer);
    // return StringChars(result.c_str());
    char* new_buffer = (char*)malloc(length + right.length + 1);
    strcpy(new_buffer, buffer);
    strcat(new_buffer, right.buffer);
    StringChars result(new_buffer);
    free(new_buffer); // освобождаем временный буфер
    return result;
}

char* StringChars::to_str() const { return buffer; }
size_t StringChars::get_length() const { return length; }


int main(void)
{
    // здесь продолжайте функцию main
    StringChars* ptr_str1 = new StringChars("Language");
    StringChars* ptr_str2 = new StringChars(" C++");
    StringChars* ptr_str3 = new StringChars("Language");
    
    StringChars res = *ptr_str1 + *ptr_str3;
    std::cout << ptr_str1->to_str() << " " << ptr_str1->get_length() << std::endl;
    std::cout << ptr_str2->to_str() << " " << ptr_str2->get_length() << std::endl;
    std::cout << ptr_str3->to_str() << " " << ptr_str3->get_length() << std::endl;
    std::cout << res.to_str() << " " << res.get_length() << std::endl;
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    // здесь освобождайте память (если необходимо)
    delete ptr_str1;
    delete ptr_str2;
    delete ptr_str3;

    return 0;
}