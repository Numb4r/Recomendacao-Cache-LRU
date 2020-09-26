#include <map>

// constexpr char *USERFILE = "users.dat";
// constexpr char *MOVIEFILE = "movies.dat";
// constexpr char *RATINGSFILE = "ratings.dat";
namespace consts
{
    const std::map<const char *, const char *> Age{
        {"1", "Under 18"},
        {"18", "18-24"},
        {"25", "35-44"},
        {"35", "35-44"},
        {"45", "45-49"},
        {"50", "50-59"},
        {"56", "56+"}};

    const std::map<const char *, const char *> Occupation{
        {"0", "other or not specified"},
        {"1", "academic/educator"},
        {"2", "artist"},
        {"3", "clerical/admin"},
        {"4", "college/grad student"},
        {"5", "customer service"},
        {"6", "doctor/health care"},
        {"7", "executive/managerial"},
        {"8", "farmer"},
        {"9", "homemaker"},
        {"10", "K-12 student"},
        {"11", "lawyer"},
        {"12", "programmer"},
        {"13", "retired"},
        {"14", "sales/marketing"},
        {"15", "scientist"},
        {"16", "self-employed"},
        {"17", "technician/engineer"},
        {"18", "tradesman/craftsman"},
        {"19", "unemployed"},
        {"20", "writer"}};

} // namespace consts
