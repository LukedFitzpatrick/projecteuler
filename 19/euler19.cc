#include <iostream>
#include <map>

enum WeekDay
{
  Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
};


std::map<WeekDay, WeekDay> NextWeekDay = {{WeekDay::Monday, WeekDay::Tuesday},
					  {WeekDay::Tuesday, WeekDay::Wednesday},
					  {WeekDay::Wednesday, WeekDay::Thursday},
					  {WeekDay::Thursday, WeekDay::Friday},
					  {WeekDay::Friday, WeekDay::Saturday},
					  {WeekDay::Saturday, WeekDay::Sunday},
					  {WeekDay::Sunday, WeekDay::Monday}};



std::map<int, int> DaysInMonth = {{1, 31},
				  {2, 28},
				  {3, 31},
				  {4, 30},
				  {5, 31},
				  {6, 30},
				  {7, 31},
				  {8, 31},
				  {9, 30},
				  {10, 31},
				  {11, 30},
				  {12, 31}};

bool isLeapYear(int year)
{
    return((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}


void advanceOneDay(WeekDay& weekDay, int& dateDay, int& dateMonth, int& dateYear)
{
    weekDay = NextWeekDay[weekDay];

    if(++dateDay > DaysInMonth[dateMonth])
    {
	// February leap year exception
	if(dateMonth == 2 && isLeapYear(dateYear) && dateDay == 29)
	{
		std::cout<<"leap year case "<<dateDay<<std::endl;
	}
	else
	{
	    dateDay = 1;
	    if(++dateMonth > 12)
	    {
		dateMonth = 1;
		dateYear++;
	    }
	}
    }

    std::cout<<"Day: "<<weekDay<<" Date: "<<dateDay<<" "<<dateMonth<<" "<<dateYear<<std::endl;
}

int main()
{
    WeekDay weekDay = WeekDay::Monday;
    int dateDay = 1;
    int dateMonth = 1;
    int dateYear = 1900;

    int firstDaySundayCount = 0;
    while(dateYear < 2001)
    {
	advanceOneDay(weekDay, dateDay, dateMonth, dateYear);
	if(weekDay == Sunday && dateDay == 1 && dateYear >= 1901 && dateYear <= 2000)
	{
	    firstDaySundayCount++;
	}
	
    }
    std::cout<<"First day sundays: "<<firstDaySundayCount<<std::endl;
}
