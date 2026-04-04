#include <vector>
#include <string>
#include <unordered_map>

// Implement your group_anagrams logic here.
std::vector<std::vector<std::string>> groupAnagrams(const std::vector<std::string>& words)
{
    std::vector<std::vector<std::string>> result;
    std::unordered_map<std::string, std::vector<std::string>> anagramGroups;
    for (const std::string& word : words)
    {
        std::string sortedWord = word;
        std::sort(sortedWord.begin(), sortedWord.end());
        anagramGroups[sortedWord].push_back(word);
    }
    for (const auto& [key,group] : anagramGroups)
    {
        result.push_back(std::move(group));
    }
    return result;
}
