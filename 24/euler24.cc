#include <iostream>
#include <vector>
#include <map>

std::map<std::string, std::vector<std::string>> ResultCache;

std::vector<std::string> allPermutations(std::string input)
{
    if(ResultCache.count(input))
    {
	return ResultCache[input];
    }
    // base case
    if(input.length() == 1)
    {
	std::vector<std::string> result = {input};
	ResultCache[input] = result;
	return result;
    }
    // recursively calculate
    else
    {
	std::vector<std::string> result;
        // for each letter in the string, put it first and append permutations of the others
	for(unsigned int i = 0; i<input.length(); i++)
	{
	    std::string starter = std::string(1, input[i]);
	    std::string remainder = input;
	    remainder.erase(i, 1);
	    std::vector<std::string> remainderPerms = allPermutations(remainder);
	    for(auto s : remainderPerms)
	    {
		result.push_back(starter+s);
	    }
	}
	ResultCache[input] = result;
	return result;
    }
}


int main()
{
    std::string input = "0123456789";
    auto result = allPermutations(input);
    for(auto s : result)
    {
	std::cout<<s<<std::endl;
    }
}
