#include "unordered_map"
#include "string"

// Implement your longest_substring_without_repeating_characters logic here.

int longestStringWithoutRepeatingCharacters(const std::string& str)
{
    std::unordered_map<char, int> charCounter;
    int left = 0; //start of current window
    int right = 0; //iterate through string
    int result = 0;
    while (right < str.length())
    {
        char r = str[right];
        charCounter[r]++;
        while (charCounter[r] > 1)
        {
            //we shring the window if we see that for a character we already saw it.
            char l = str[left];
            charCounter[l]--;
            left++;
        }
        result = std::max(result, right - left + 1);
        right++;
    }
    return result;
}

std::string longestStringWithoutRepeatingCharactersExplicite(const std::string& str)
{
    std::string out;
    int bestL = 0;
    int bestR = -1;
    std::unordered_map<char, int> charCounter;
    int left = 0; //start of current window
    int right = 0; //iterate through string
    int result = 0;
    while (right < str.length())
    {
        char r = str[right];
        charCounter[r]++;
        while (charCounter[r] > 1)
        {
            //we shring the window if we see that for a character we already saw it.
            char l = str[left];
            charCounter[l]--;
            left++;
        }
        int currentLen = right - left + 1;
        if (currentLen > result)
        {
            result = currentLen;
            bestL = left;
            bestR = right;
        }
        right++;
    }
    //subs (pos, len) , len =r-l+1
    out = (bestR >= bestL) ? str.substr(bestL, bestR - bestL + 1) : std::string{};


    return out;
}
