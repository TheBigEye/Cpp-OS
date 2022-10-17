#ifndef SYSTEM_UTILS_NETWORKUTILS_H_
#define SYSTEM_UTILS_NETWORKUTILS_H_

#include <iostream>
#include <windows.h>
#include <wininet.h>

#pragma comment(lib, "Wininet.lib")

bool isNetworkConnected() {
	char url[128]; // Store the url
	strcat(url, "http://www.google.com"); // Do ping to google.com
	bool isConnected = InternetCheckConnection(url, FLAG_ICC_FORCE_CONNECTION, 0); // Get server response to bool value
	return isConnected;
}

#endif /* SYSTEM_UTILS_NETWORKUTILS_H_ */
