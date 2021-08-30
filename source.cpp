#include <time.h>
#include <iostream>

using namespace std;

time_t start_time;
time_t hold_time = 0;
time_t end_time;
time_t current_time_1;
time_t current_time_2;
bool paused = false;

int main() {

	string input = "";
	char buffer[1024];

	while (input != string("s") && input != string("S")) {
		cin >> input;
	}

	
	time(&start_time);

	ctime_s(buffer, sizeof(buffer), &start_time);

	std::cout << buffer << endl;

	while ((input != string("p") && input != string("P")) && (input != string("end") && input != string("end"))) {
		cin >> input;
	}


	while ((input == string("p") || input == string("P"))) {
		input = "";
		
		if (!paused) {
			time(&current_time_1);
			std::cout << "PAUSED : " << "Time elapsed : " << (current_time_1 - (start_time) - hold_time) / 3600 << " : " << ((current_time_1 - (start_time) - hold_time) % 3600) / 60 << " : " << ((current_time_1 - (start_time) - hold_time) % 3600) % 60 << endl;
			paused = true;
			while ((input != string("p") && input != string("P")) && (input != string("end") && input != string("end"))) {
				cin >> input;
			}
		}
		else if(paused) {
			time(&current_time_2);
			hold_time += (current_time_2 - current_time_1);
			std::cout << "RESUMED : " << "Hold time : " << (hold_time) / 3600 << " : " << ((hold_time) % 3600)/60 << " : " << ((hold_time) % 3600) % 60 << endl;
			paused = false;
			while ((input != string("p") && input != string("P")) && (input != string("end") && input != string("end"))) {
				cin >> input;
			}
		}
	}
	
	if (paused) {
		time(&current_time_2);
		hold_time += (current_time_2 - current_time_1);
	}

	time(&end_time);

	end_time = end_time - start_time - hold_time;
	
	std::cout << "\n\nTotal time : " << end_time / 3600 << " : " << (end_time % 3600) / 60 << " : " << (end_time % 3600) % 60 << endl;
	std::cout << "Hold time : " << (hold_time) / 3600 << " : " << ((hold_time) % 3600) / 60 << " : " << ((hold_time) % 3600) % 60 << endl;

	cin >> input;

	return 0;

}
