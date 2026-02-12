#include "std_aliases.hpp"

using namespace stl;
using namespace io;

std::vector<vector<string>> readInputFileClassic(const string & path,bool debug)
{
    std::ifstream inFile(path);

    if (!inFile.is_open())
    {
        throw std::runtime_error("Cannot open input file: "+path);
    }
    int T = 0;
    if (!(inFile >> T))
        throw std::runtime_error("Failed to read T from file: " + path);
    std::string line;
    std::getline(inFile,line);

    vector<vector<string>> cases;
    cases.reserve(T);
    for (int tc = 0; tc < T; ++tc)
    {
        //skip possible empty lines
        do
        {
            if (!std::getline(inFile,line))
            {
                throw std::runtime_error("unexpected EOF while reading case "+std::to_string(tc));
            }
        }
        while (line.empty());


        std::istringstream iss(line);
        vector<string> rawCase;
        string s;
        //load everything as it is
        while (iss>>s)
        {
            rawCase.push_back(s);//single test
        }
        cases.push_back(std::move(rawCase));
    }

    //print parsed input (optional)
    if (debug)
    {
        for (int i = 0; i < (int)cases.size(); ++i) {
            std::cout << "case[" << i << "]: ";
            for (const auto& x : cases[i]) std::cout << x << ' ';
            std::cout << '\n';
        }
    }
    return cases;

}
