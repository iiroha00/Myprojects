#include <iostream>
using namespace std;

struct aika_ty {
	int hours, minutes, seconds;
};


int main() {
	aika_ty time;
	aika_ty *time_p = &time;
	cout << "Give number of hours: ";
	cin >> time.hours;
	while (time.hours > 23 || time.hours < 0) {
		cout << "Error! input not between 0-23" << endl;
		cin >> time.hours;
	}
	cout << "Give number of minutes: ";
	cin >> time.minutes;
	while (time.minutes > 59 || time.minutes < 0) {
		cout << "Error! input not between 0-59" << endl;
		cin >> time.minutes;
	}
	cout << "Give number of seconds: ";
	cin >> time.seconds;
	while (time.seconds > 59 || time.seconds < 0) {
		cout << "Error! input not between 0-59" << endl;
		cin >> time.seconds;
	}
	cout << time.hours << ":" << time.minutes << ":" << time.seconds << endl;
	cout << "Hours: " << time_p->hours << endl;
	cout << "Minutes: " << time_p->minutes << endl;
	cout << "Seconds: " << time_p->seconds << endl;

	aika_ty time1,time2;
	time1.hours = 23;
	time1.minutes = 59;
	time1.seconds = 59;
	time2 = time1;
	if (time2.hours == time1.hours && time2.minutes==time1.minutes && time2.seconds==time1.seconds) {
		cout << "Contents are the same";
	}
	else {
		cout << "Contents are not the same";
	}

	return 0;
}