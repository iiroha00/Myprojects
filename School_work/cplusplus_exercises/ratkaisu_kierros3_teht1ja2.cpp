#include <iostream>
using namespace std;

// TEHTÄVÄN 1 JA 2 RATKAISUT

void seconds_toTime(int &seconds, int &seconds_time, int &hours, int &minutes);
void TimeToSeconds(int &seconds_time, int &minutes, int &hours, int &seconds);

int main() {
	int seconds, seconds_time, hours, minutes;
	cout << "Give number of seconds: ";
	cin >> seconds;
	seconds_toTime(seconds, seconds_time, hours, minutes);
	cout << seconds << " seconds is " << hours << " hours " << minutes << " minutes " << seconds_time << " seconds" << endl; //prints how many hours, minutes and seconds. Some amount of seconds is.
	TimeToSeconds(seconds_time, minutes, hours, seconds);
	cout << hours << " hours " << minutes << " minutes " << seconds_time << " seconds is " << seconds << " seconds";
	return 0;
}

void seconds_toTime(int& seconds, int& seconds_time, int& hours, int& minutes) {
	hours = seconds / 60 / 60; //calculates the number of hours for given seconds
	minutes =  (seconds / 60)-(hours*60); //calculates the number of minutes for given seconds
	seconds_time =seconds-(minutes*60) - (hours * 60*60);//calculates the remainding seconds. 
}
//exercise 2 answer
void TimeToSeconds(int &seconds_time, int &minutes, int &hours, int &seconds) {
	seconds = (hours * 60 * 60) + (minutes * 60) + seconds_time;
}