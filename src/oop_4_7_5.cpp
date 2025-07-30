#include <iostream>
#include <string>

enum request_method { // обрабатываемые методы
    method_get = 1,
    method_post = 2,
    method_put = 3,
    method_delete = 4
};

struct Request { // объект запроса
    request_method method {method_get};
    std::string url;
    std::string data;
};

class RetriveMixin {
    request_method method{ method_get };
public:
    RetriveMixin() = default;
    RetriveMixin(request_method* ms, int index) { ms[index] = method; }
    virtual ~RetriveMixin() { }
    std::string get(const Request& request) { return "GET: " + request.url; }
};

class CreateMixin {
    request_method method{ method_post };
public:
    CreateMixin() = default;
    CreateMixin(request_method* ms, int index) { ms[index] = method; }
    virtual ~CreateMixin() { }
    std::string post(const Request& request) { return "POST: " + request.url; }
};

class UpdateMixin {
    request_method method{ method_put };
public:
    UpdateMixin() = default;
    UpdateMixin(request_method* ms, int index) { ms[index] = method; }
    virtual ~UpdateMixin() { }
    std::string put(const Request& request) { return "PUT: " + request.url; }
};

// здесь объявляйте класс GeneralView
class GeneralView : public RetriveMixin, public CreateMixin
{
    enum { max_methods = 4 }; // максимальное число разрешенных методов
    int count_methods{ 0 }; // число разрешенных методов
    request_method allowed_methods[max_methods]{ method_get, method_post }; // массив из разрешенных методов
    bool is_method_exists(request_method method)
    {
        for (request_method cur_method : allowed_methods)
        {
            if (cur_method == method) return true;
        }
        return false;
    } // возвращает true, если method присутствует в массиве allowed_methods, иначе false

public:
    GeneralView() = default;
    std::string render_request(const Request& request)
    {
        std::string result = "";
        if (is_method_exists(request.method))
        {
            switch (request.method)
            {
                case method_get:
                    result = get(request);
                    break;
                case method_post:
                    result = post(request);
                default:
                    break;
            }
        }
        return result;
    }
};

int main(void)
{
    // здесь продолжайте функцию main
    GeneralView gw;
    Request req {method_post, "https://proproprogs.ru/cpp_oop/cpp-oop-mnozhestvennoe-nasledovanie-poryadok-vyzova-konstruktorov-i-destruktorov",
                 "<h1>Множественное наследование</h1>"};
    std::string res =  gw.render_request(req);
    std::cout << res << std::endl;
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}