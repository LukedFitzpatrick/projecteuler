#include <iostream>
#include <fstream>
#include <vector>
#include <istream>
#include <iterator>
#include <sstream>
#include <memory>

using namespace std;

struct Position
{
    int value;
    shared_ptr<Position> left;
    shared_ptr<Position> right;
};

int maxDescendingSum(Position* p)
{
    // base case, for items at the bottom of the pyramid
    if(!p->left && !p->right)
    {
	return p->value;
    }
    else if(!p->left)
    {
	return p->value + maxDescendingSum(p->right.get());
    }
    else if(!p->right)
    {
	return p->value + maxDescendingSum(p->left.get());
    }
    else
    {
	return p->value + max(maxDescendingSum(p->right.get()),
			      maxDescendingSum(p->left.get()));
    }
}


int main()
{
    // wow why is it so complicated to build this data structure
    ifstream infile("data.txt");

    vector<vector<shared_ptr<Position>>> lines;
    string line;

    for(int lineNum = 0; getline(infile, line); lineNum++)
    {
	//cout<<line<<endl;

	// split line into strings based on spaces
	stringstream ss(line);
	istream_iterator<string> begin(ss);
	istream_iterator<string> end;
	vector<string> vstrings(begin, end);

	unsigned int columnNum = 0;

	vector<shared_ptr<Position>> thisLine;

	for(string v : vstrings)
	{
	    shared_ptr<Position> p;
	    p.reset(new Position);
	    
	    p->value = stoi(v);
	    thisLine.push_back(p);

	    // build the tree structure
	    if(lineNum > 0)
	    {
		if(lines[lineNum - 1].size() > columnNum)
		{
		    lines[lineNum - 1][columnNum]->left = p;
		}
		if(columnNum > 0)
		{
		    lines[lineNum - 1][columnNum-1]->right = p;
		}
	    }
	    
	    columnNum++;
	}
	lines.push_back(thisLine);
    }

    cout<<maxDescendingSum(lines[0][0].get())<<endl;
}
