#include <iostream>
using namespace std;

struct aika_ty {
	int hours, minutes, seconds;
};

aika_ty time_differential(aika_ty time1, aika_ty time2);
void TimeToSeconds(int& seconds_time, int& minutes, int& hours, int& seconds);
void seconds_toTime(int& seconds, int& seconds_time, int& hours, int& minutes);

int main() {
	aika_ty time1, time2, time3;
	//Asks user to give 2 times and checks that they are valid
	cout << "Give number of hours: ";
	cin >> time1.hours;
	while (time1.hours > 23 || time1.hours < 0) {
		cout << "Error! input not between 0-23" << endl;
		cin >> time1.hours;
	}
	cout << "Give number of minutes: ";
	cin >> time1.minutes;
	while (time1.minutes > 59 || time1.minutes < 0) {
		cout << "Error! input not between 0-59" << endl;
		cin >> time1.minutes;
	}
	cout << "Give number of seconds: ";
	cin >> time1.seconds;
	while (time1.seconds > 59 || time1.seconds < 0) {
		cout << "Error! input not between 0-59" << endl;
		cin >> time1.seconds;
	}
	cout << "Give number of hours: ";
	cin >> time2.hours;
	while (time2.hours > 23 || time2.hours < 0) {
		cout << "Error! input not between 0-23" << endl;
		cin >> time2.hours;
	}
	cout << "Give number of minutes: ";
	cin >> time2.minutes;
	while (time2.minutes > 59 || time2.minutes < 0) {
		cout << "Error! input not between 0-59" << endl;
		cin >> time2.minutes;
	}
	cout << "Give number of seconds: ";
	cin >> time2.seconds;
	while (time2.seconds > 59 || time2.seconds < 0) {
		cout << "Error! input not between 0-59" << endl;
		cin >> time2.seconds;
	}
	time3 = time_differential(time1, time2);
	cout << time3.hours << ":" << time3.minutes << ":" << time3.seconds << endl;
	return 0;
}


aika_ty time_differential(aika_ty time1, aika_ty time2) {
	aika_ty time3;
	int seconds,seconds2,temp;
	TimeToSeconds(time1.seconds, time1.minutes, time1.hours, seconds);
	TimeToSeconds(time2.seconds, time2.minutes, time2.hours, seconds2);
	if (seconds > seconds2) {
		temp = seconds - seconds2;
	}
	else {
		temp = seconds2 - seconds;
	}
	seconds_toTime(temp, time3.seconds, time3.hours, time3.minutes);
	return time3;
}
void TimeToSeconds(int& seconds_time, int& minutes, int& hours, int& seconds) {
	seconds = (hours * 60 * 60) + (minutes * 60) + seconds_time;
}
void seconds_toTime(int& seconds, int& seconds_time, int& hours, int& minutes) {
	hours = seconds / 60 / 60; //calculates the number of hours for given seconds
	minutes = (seconds / 60) - (hours * 60); //calculates the number of minutes for given seconds
	seconds_time = seconds - (minutes * 60) - (hours * 60 * 60);//calculates the remainding seconds. 
}