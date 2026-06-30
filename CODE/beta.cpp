#include <iostream>
#include <string>
using namespace std;

#if defined(_WIN32) || defined(_WIN64)
    #include <windows.h>
    #define IS_WINDOWS true
#else
    #include <sys/utsname.h>
    #define IS_WINDOWS false
#endif

int main() {
    string app = "Lightweight Source Systems Inspect";
    string app_version = "1.00.00 [Beta]";
    string notice = "Application will remain in BETA until further notice [until I can continue production on Personal Computer]";

    string current_os = "Unknown OS";
    string device_name = "Unknown Device";
    string version = "Unknown Version";

#if IS_WINDOWS
    current_os = "Windows";
    
    // Get Device Name
    char computer_name[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD size = sizeof(computer_name);
    if (GetComputerNameA(computer_name, &size)) {
        device_name = computer_name;
    }

    // Get OS Version
    version = "Windows NT"; 
#else
    // Linux / macOS implementation
    struct utsname buffer;
    if (uname(&buffer) == 0) {
        current_os = buffer.sysname;
        device_name = buffer.nodename;
        version = buffer.release;
    }
#endif

    // Printing the details
    cout << app << "\n";
    cout << app_version << "\n";
    cout << notice << "\n\n";
    cout << "DEVICE NAME: " << device_name << "\n";
    cout << "OS: " << current_os << "\n";
    cout << "VERSION: " << version << "\n";

    return 0;
}