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

class GenericView { // базовый класс для обработки запросов
protected:
    enum {total_methods = 3}; // количество обрабатываемых методов
    request_method methods[total_methods] = {method_get, method_post, method_put}; // массив допустимых методов
public:
    virtual std::string get(const Request& request)
    {
        return request.data;
    }
    virtual std::string post(const Request& request)
    {
        return request.data;
    }
    virtual std::string put(const Request& request)
    {
        return request.data;
    }
    virtual std::string del(const Request& request)
    {
        return request.data;
    }
};

class DetailView : public GenericView
{
    bool is_method_exists(request_method method)
    {
        for (request_method cur_method : methods)
        {
            if (cur_method == method) return true;
        }
        return false;
    }
public:
    virtual std::string get(const Request& request) { return request.url; } // возвращает поле url объекта request
    const std::string render_request(const Request& request)
    {
        std::string render_result = "";

        if (!is_method_exists(request.method)) return render_result;

        switch (request.method)
        {
            case method_get:
                render_result = get(request);
                break;
            case method_post:
                render_result = post(request);
                break;
            case method_put:
                render_result = put(request);
                break;
            case method_delete:
                render_result = del(request);
            default:
                break;
        }

        return render_result;
    }
};

int main(void)
{
    // здесь продолжайте функцию main
    DetailView dw;
    Request req;
    req.data = "<h1>Заголовок</h1>";
    req.method = method_get;
    req.url = "https://proproprogs.ru/cpp_oop/cpp-oop-virtualnye-virtual-metody-funkcii";

    std::string res = dw.render_request(req);

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}