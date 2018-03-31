#include <iostream>
#include <fstream>

int main()
{
    std::ifstream infile("namessorted.txt");
    std::string line;

    int lineCount = 1;

    unsigned long total = 0;
    
    while (std::getline(infile, line))
    {
	int alphabetValue = 0;
	for(unsigned int i = 0; i<line.length(); i++)
	{
	    alphabetValue += line[i] - 64;
	}

	total += lineCount*alphabetValue;
	std::cout<<total<<std::endl;
	
	lineCount++;
    }
}
