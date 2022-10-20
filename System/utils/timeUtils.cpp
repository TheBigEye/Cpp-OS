#include "timeUtils.h"

#include <ctime>
#include <string.h>
#include <sstream>
#include <windows.h>

std::string getCurrentTime() {
	time_t currentTime;
	struct tm *localTime;

	std::string type;

	time(&currentTime);                   // Get the current time
	localTime = localtime(&currentTime);  // Convert the current time to the local time

	int Hour   = localTime -> tm_hour;
	int Min    = localTime -> tm_min;
	//int Sec    = localTime -> tm_sec;

	if (Hour > 12) {
		type = "pm";
	} else {
		type = "am";
	}

	// Make and return as a string
	std::stringstream sh; sh << Hour; std::string strHour = sh.str();
	std::stringstream sm; sm << Min; std::string strMin = sm.str();

	std::stringstream st; // This for avoid wrong string format, like; 1:9 am -> 01:09 am
	if (strHour.length() < 2 && strMin.length() < 2) {
		st << "0" << strHour << ":" << "0" << strMin << " " << type;

	} else if (strHour.length() < 2) {
		st << "0" << strHour << ":" << strMin << " " << type;

	} else if (strMin.length() < 2) {
		st << strHour << ":" << "0" << strMin << " " << type;

	} else {
		st << strHour << ":" << strMin << " " << type;
	}

	std::string strTime = st.str();
	return strTime;
}

std::string getCurrentTimeHour() {
    SYSTEMTIME st;
    GetLocalTime(&st);
    std::string time = std::to_string(st.wHour) + ":" + std::to_string(st.wMinute) + ":" + std::to_string(st.wSecond);
    return time;
}

std::string getCurrentTimePeriod() {
    SYSTEMTIME st;
    GetLocalTime(&st);
    std::string period;

    if (st.wHour >= 12) {
        period = "pm";
    } else {
        period = "am";
    }

    return period;
}


