#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
    fstream input("myfile", ios::in | ios::binary);
    Person person;
    person.ParseFromIstream(&input);
    std::cout << "Name: " << person.name() << std::endl;
    std::cout << "E-mail: " << person.email() << std::endl;

    return 0;
}
