#include <iostream>
#include <map>

int divisorSum(int n)
{
    int divisorSum = 0;
    for(int i = 1; i<(n/2)+1; i++)
    {
	if(n % i == 0)
	{
	    divisorSum += i;
	}
    }

    return divisorSum;
}

bool areAmicable(int n, int m, std::map<int, int> numToDivisorSum)
{
    return(numToDivisorSum[n] == m && numToDivisorSum[m] == n);
}


int main()
{
    std::map<int, int> numToDivisorSum;
    std::map<int, bool> amicables;
    
    for(int i = 0; i < 10000; i++)
    {
	int dS = divisorSum(i);
	//std::cout<<i<<": "<<dS<<std::endl;
	numToDivisorSum[i] = dS;
    }

    for(int m = 0; m < 10000; m++)
    {
	//std::cout<<"m: "<<m<<std::endl;

	if(numToDivisorSum[m] < 10000)
	{
	    if(numToDivisorSum[numToDivisorSum[m]] == m && numToDivisorSum[m] != m)
	    {
		std::cout<<m<<", "<<numToDivisorSum[m]<<std::endl;
		amicables[m] = true;
		amicables[numToDivisorSum[m]] = true;
	    }
	}
    }

    int sum = 0;
    for (auto entry : amicables)
    {
	sum += entry.first;
	std::cout<<"item: "<<entry.first<<std::endl;
    }

    std::cout<<"Sum: "<<sum<<std::endl;
}
