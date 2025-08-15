#include <iostream>
#include <string>
#include <memory>

class LinkedListIndexError : public std::exception
{
    std::string msg;
public:
    LinkedListIndexError(const std::string& message) : msg(message) {}
    const char* what() const noexcept override { return msg.c_str(); }
}; //- класс для генерации исключения.

template <typename T>
class Object
{
protected:
    T data {0};
    Object<T> *next {nullptr};
public:
    Object(T data) : data(data), next(nullptr) {}
    const T& get_data() const { return data; } // получение значения поля data
    Object<T>* get_next() const { return next; } // получение значения поля next
    void set_next(Object<T>* next) { this->next = next; }
}; //- для представления отдельных элементов в односвязном списке;

template <typename T>
class LinkedList
{
    Object<T>* head = nullptr;
    Object<T>* tail = nullptr;
    size_t size = 0;
public:
    LinkedList() = default;
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;
    Object<T>* get_head() const { return head; }
    Object<T>* get_tail() const { return tail; }
    size_t get_size() const { return size; }
    bool is_empty() const { return head == nullptr; }

    void push_back(const T& data); // добавление в конец списка
    void push_front(const T& data); // добавление в начало списка
    void pop_back(); // удаление последнего элемента (если его нет, то ничего не делать)
    void pop_front(); // удаление первого элемента (если его нет, то ничего не делать)

    T& operator[] (size_t index);
    //const T& operator[] (size_t index) const;

    ~LinkedList();

}; //- для представления односвязного списка в целом;

template <typename T>
void LinkedList<T>::push_back(const T& data)
{
    Object<T> *new_node = new Object<T>(data);

    if(is_empty())
        head = tail = new_node;
    else
    {
        tail->set_next(new_node);
        tail = new_node;
    }
    size++;
} // добавление в конец списка

template <typename T>
void LinkedList<T>::push_front(const T& data)
{
    Object<T> *new_node = new Object<T>(data);

    if(is_empty())
        head = tail = new_node;
    else
    {
        new_node->set_next(head);
        head = new_node;
    }
    size++;
} // добавление в начало списка

template <typename T>
void LinkedList<T>::pop_back()
{
    if(is_empty())
        return;

    if (head == tail)
    {
        delete head;
        head = tail = nullptr;
    }
    else
    {
        Object<T> *current = head;
        while (current->get_next() != tail)
        {
            current = current->get_next();
        }
        delete tail;
        tail = current;
        tail->set_next(nullptr);
    }
    size--;
} // удаление последнего элемента (если его нет, то ничего не делать)

template <typename T>
void LinkedList<T>::pop_front()
{
    if (is_empty())
        return;

    Object<T> *temp = head;
    head = head->get_next();
    delete temp;

    if (head == nullptr)
        tail = nullptr;

    size--;
} // удаление первого элемента (если его нет, то ничего не делать)

template <typename T>
LinkedList<T>::~LinkedList()
{
    while (!is_empty())
    {
        pop_front();
    }

}

template <typename T>
T& LinkedList<T>::operator[] (size_t index)
{
    if (index >= size)
        throw LinkedListIndexError("Invalid element index.");

    Object<T> *current = head;
    size_t count = 0;

    while (count < index)
    {
        current = current->get_next();
        count++;
    }

    return const_cast<T&> (current->get_data());
}

/////////////////////////////////
struct Point
{
    int x{0}, y{0};
};


int main()
{
    LinkedList<Point> lst; // пустой односвязный список для хранения данных типа Complex (структура)

    lst.push_back(Point {1, 2}); // добавление в конец списка
    lst.push_back(Point {3, 4}); // добавление в конец списка
    lst.push_front(Point {-1, -2}); // добавление в начало списка
    lst.pop_back(); // удаление последнего элемента (если его нет, то ничего не делать)
    lst.pop_front(); // удаление первого элемента (если его нет, то ничего не делать)

    Point d = lst[0];  // получение первого элемента по индексу
    std::cout << "Point d:\n" << d.x << " " << d.y << std::endl;
    lst[0] = Point {5, 8}; // запись в первый элемент по индексу

    LinkedList<int> lst_int; // еще один односвязный список для хранения данных типа int

    lst_int.push_back(1); // добавление в конец списка
    lst_int.push_back(2);
    lst_int.push_back(3);

    int var = lst_int[1]; // чтение данных из второго элемента списка
    std::cout << "int var:\n" << var << std::endl;
    lst_int[2] = -5; // запись данных в третий элемент списка

    // перебор первого списка
    Object<Point>* ptr_lst = lst.get_head();
    std::cout << "Point list:" << std::endl;
    while(ptr_lst) {
        Point res = ptr_lst->get_data();
        std::cout << res.x << "," << res.y << " ";
        ptr_lst = ptr_lst->get_next();
    }
    std::cout << std::endl;
    // перебор второго списка
    std::cout << "Int list:" << std::endl;
    Object<int>* ptr_lst_int = lst_int.get_head();
    while(ptr_lst_int) {
        int a = ptr_lst_int->get_data();
        std::cout << a << " ";
        ptr_lst_int = ptr_lst_int->get_next();
    }
    std::cout << std::endl;
    return 0;
}