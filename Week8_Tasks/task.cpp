#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;

int main(int argc, char* argv[])
{
	int m, h;
	string d;
	const char* task;
	for(int i = 1; i < argc; i++)
	{
		if(string(argv[i]) == "-m")
		{
			m = atoi(argv[i+1]);
		}
		else if(string(argv[i]) == "-h")
		{
			h = atoi(argv[i+1]);
		}
		else if(string(argv[i]) == "-d")
		{
			d = string(argv[i+1]);
		}
	}
	task = argv[argc-1];

	time_t now = time(nullptr);
	tm target = *localtime(&now);
	target.tm_min = m;
	target.tm_hour = h;
	if (d == "sunday")
	{
		target.tm_wday = 0;
	}
	else if (d == "monday")
	{
		target.tm_wday = 1;
	}
	else if (d == "tuesday")
	{
		target.tm_wday = 2;
	}
	else if (d == "wednesday")
	{
		target.tm_wday = 3;
	}
	else if (d == "thursday")
	{
		target.tm_wday = 4;
	}
	else if (d == "friday")
	{
		target.tm_wday = 5;
	}
	else if (d == "saturday")
	{
		target.tm_wday = 6;
	}

	time_t targetTime = mktime(&target);
	int delaySeconds = static_cast<int>(difftime(targetTime,now));

	if (delaySeconds < 0)
	{
		cerr<<"The specified time has already passes"<<endl;
		return 1;
	}

	cout<<"Current Time: "<<asctime(localtime(&now))<<endl;
	cout<<"Target Time: "<<asctime(&target)<<endl;
	cout<<"Delay Seconds: "<<delaySeconds<<endl;

	this_thread::sleep_for(chrono::seconds(delaySeconds));
	system(task);

	

	return 0;
}
