#pragma once
struct User
{
    const char *UserID;
    const char *Gender;
    const char *Age;
    const char *Occupation;
    const char *ZipCode;
};
User MakeUser(const char *text, const char *tokens);

// using string = std::string; //caso precise mudar o tipo para std::string

// class User
// {
// private:
//     string userID;
//     string gender;
//     string age;
//     string occupation;
//     string zipCode;

// public:
//     User() = default;
//     void imprimir();

//     User(std::vector<string> vec);
// };
