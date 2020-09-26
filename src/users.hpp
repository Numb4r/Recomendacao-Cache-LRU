#include <initializer_list>
#include <vector>
#include <string>
// struct user
// {
//     const char *UserID;
//     const char *Gender;
//     const char *Age;
//     const char *Occupation;
//     const char *ZipCode;
// };
using string = std::string; //caso precise mudar o tipo para std::string

class User
{
private:
    string UserID;
    string Gender;
    string Age;
    string Occupation;
    string ZipCode;

public:
    User() = default;
    void imprimir();
    User(std::initializer_list<string> init);
    User(std::vector<string> vec);
};
