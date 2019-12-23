#include <iostream>

#include <etl/vector.h>
#include <etl/iterator.h>

int main(int argc, char** argv)
{
    etl::vector<int, 100> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    for (int i = 0; i < vec.size(); i++)
        std::cout << vec.at(i) << std::endl;

    return 0;
}