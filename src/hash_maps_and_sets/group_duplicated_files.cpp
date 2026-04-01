#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

vector<vector<string>> groupDuplicatedFiles(const vector<string>& paths) {
    vector<vector<string>> res;
    unordered_map<string, vector<string>> um;
    // 1. parsing
    for (string path : paths) {
        stringstream ss(path);
        string directory;
        ss >> directory;
        string fileToken;
        while (ss >> fileToken) {
            size_t openBracket = fileToken.find('(');
            size_t closeBracket = fileToken.find(')');

            string fileName = fileToken.substr(0, openBracket);
            string fileContent = fileToken.substr(openBracket + 1, closeBracket - openBracket - 1);
            string totalPath = directory + "/" + fileName;
            um[fileContent].push_back(totalPath);
        }
    }
    for (const auto& [k, v] : um) {
        res.push_back(v);
    }

    return res;
}// Implement your logic here.
