#include <iostream>
#include <vector>
#include <map>

// if too slow could use sieve
bool isAbundant(int n)
{
    int sum = 0;
    for(int i = 1; i<=n/2; i++)
    {
	if(n % i == 0)
	{
	    sum += i;
	}

	if(sum > n)
	{
	    return true;
	}
    }
    return false;
}

bool foundTwoVectorMembersThatSum(std::vector<int> v, int n)
{
    // assumes v is sorted
    //std::cout<<"starting with n = "<<n<<std::endl;
    // i is the bigger of the two numbers in the sum
    for(int i = v.size()-1; i>=0; i--)
    {
	if(v[i] < (n/2)-1)
	{
	    // the bigger number must be at least half the total, if we're here we'll never find one
	    return false;
	}

	// TODO could binary search straight to here rather than decrementing down
	if(v[i] >= n)
	{
	    // too big
	    continue;
	}

		
	// this number is worth checking
	bool done = false;
	for(unsigned int j = 0; j < (v.size()/2)+1 && !done; j++)
	{
	    int sum = v[j] + v[i];
	    if(sum == n)
	    {
		return true;
	    }
	    else if(sum > n)
	    {
		done = true;
	    }
	}
	
    }
    //std::cout<<v[i]<<std::endl;

    return false;
}

int main()
{
    std::cout<<"Finding abundants..."<<std::endl;

    std::vector<int> abundants;
    
    for(int i = 1; i<=28123; i++)
    {
	if(isAbundant(i))
	{
	    abundants.push_back(i);
	    //std::cout<<i<<std::endl;
	}


    }

    unsigned long totalSum = 0;
    // for(int i = 0; i<=28123; i++)
    // {
    // 	if(!foundTwoVectorMembersThatSum(abundants, i))
    // 	{
    // 	    std::cout<<i<<std::endl;
    // 	    totalSum += i;
    // 	}
    // }
    
    std::map<int, bool> found;
    for(unsigned int i = 0; i <= abundants.size(); i++)
    {
	std::cout<<i<<std::endl;
	for(unsigned int j = 0; j <= abundants.size(); j++)
	{
	    found[abundants[i] + abundants[j]] = true;
	    // no-op
	}
    }
    std::cout<<"Total Sum: "<<totalSum<<std::endl;
}


// 12
// 18
// 20
// 24
// 30
// 36
// 40
// 42
// 48
// 54
// 56
// 60
// 66
// 70
// 72
// 78
// 80
// 84
// 88
// 90
// 96
// 100
// 102
// 104
// 108
// 112
// 114
