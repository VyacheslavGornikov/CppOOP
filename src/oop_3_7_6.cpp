#include <iostream>
#include <string>
#include <vector>

class ExtensionFilter
{
    std::vector <std::string> filter;
public:
    ExtensionFilter(const std::string& extensions)
    {
        char delimeter = '|';
        size_t start = 0;
        size_t end = extensions.find(delimeter);

        while (end != std::string::npos)
        {
            filter.push_back(extensions.substr(start, end - start));
            start = end + 1;
            end = extensions.find(delimeter, start);
        }

        filter.push_back(extensions.substr(start));
    }

    int operator() (const std::string* lst, size_t size_lst,
                    std::string* flt_lst, size_t max_count_files)
    {
        size_t count = 0;

        for (size_t i = 0; i < size_lst && count < max_count_files; i++)
        {
            for (size_t j = 0; j < filter.size(); j++)
            {
                if (lst[i].find(filter[j]) != std::string::npos)
                {
                    flt_lst[count++] = lst[i];
                    break;
                }
            }
        }
        return (int)count;
    }
};

int main(void)
{
    enum { max_count_files = 100 };
    ExtensionFilter image_flt("bmp|png|jpg");
    std::string lst[] = {"jim.jpg", "net.avi", "out1.png", "rep1.gif", "text.docx", "ava.8.jpg"};
    size_t size_lst = sizeof(lst) / sizeof(lst[0]);
    std::string flt_lst[max_count_files];
    int count = image_flt(lst, size_lst, flt_lst, max_count_files);
    std::cout << count << std::endl;

    for (int i = 0; i < count; i++)
    {
        std::cout << flt_lst[i] << std::endl;
    }

    return 0;
}

