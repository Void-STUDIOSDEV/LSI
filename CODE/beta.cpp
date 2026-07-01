#include <iostream>
#include <string>
#include <sys/utsname.h>
#include <sys/sysinfo.h>
using namespace std;

int main() {
    string app = "Linux Systems Inspector";
    string app_version = "1.00.03 [Beta]";
    string notice = "Application will remain in BETA until further notice [until I can continue production on Personal Computer]";

    string current_os = "Unknown OS";
    string device_name = "Unknown Device";
    string version = "Unknown Version";

    struct utsname buffer;
    if (uname(&buffer) == 0) {
        current_os = buffer.sysname;
        device_name = buffer.nodename;
        version = buffer.release;
    }

    // Printing the details
    cout << app << "\n";
    cout << app_version << "\n";
    cout << notice << "\n\n";
    cout << "DEVICE NAME: " << device_name << "\n";
    cout << "OS: " << current_os << "\n";
    cout << "VERSION: " << version << "\n";
    
    struct sysinfo info;
    if (sysinfo(&info) == 0) {
        cout << "TOTAL RAM: "
            << (info.totalram * info.mem_unit) / (1024 * 1024)
            << " MiB\n";
            
        cout << "AVAILABLE RAM: "
            << (info.freeram * info.mem_unit) / (1024 * 1024)
            << " MiB\n";
    }
    else {
        perror("sysinfo\n");
    }

    return 0;
}