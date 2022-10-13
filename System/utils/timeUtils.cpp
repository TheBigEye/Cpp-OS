#include <iostream>
#include "timeUtils.h"

using namespace std;

string getCurrentTime() {
	time_t currentTime;
	struct tm *localTime;
	
	string type;
	
	time(&currentTime);                   // Get the current time
	localTime = localtime(&currentTime);  // Convert the current time to the local time
	
	int Hour   = localTime -> tm_hour;
	int Min    = localTime -> tm_min;
	int Sec    = localTime -> tm_sec;
	
	if (Hour > 12) {
		type = "pm";
	} else {
		type = "am";
	}
	
	// Make and return as a string
	stringstream sh; sh << Hour; string strHour = sh.str();
	stringstream sm; sm << Min; string strMin = sm.str();
	
	stringstream st; // This for avoid wrong string format, like; 1:9 am -> 01:09 am
	if (strHour.length() < 2 && strMin.length() < 2) {
		st << "0" << strHour << ":" << "0" << strMin << " " << type;
		
	} else if (strHour.length() < 2) {
		st << "0" << strHour << ":" << strMin << " " << type;
		
	} else if (strMin.length() < 2) {
		st << strHour << ":" << "0" << strMin << " " << type;
		
	} else {
		st << strHour << ":" << strMin << " " << type;
	}
	
	string strTime = st.str();
	return strTime;
}

string getCurrentTimeHour() {
    SYSTEMTIME st;
    GetLocalTime(&st);
    string time = to_string(st.wHour) + ":" + to_string(st.wMinute) + ":" + to_string(st.wSecond);
    return time;
}

string getCurrentTimePeriod() {
    SYSTEMTIME st;
    GetLocalTime(&st);
    string period;
    
    if (st.wHour >= 12) {
        period = "pm";
    } else {
        period = "am";
    }
    
    return period;
}


