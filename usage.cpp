
#include "mem.h"
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <ctime>
#include <unistd.h>

using namespace std;

auto read_file() -> std::vector<std::string>
{
    std::vector<std::string> data;
    std::string line;
    ifstream myfile("src/data.txt");

    if (myfile.is_open())
    {
        while (getline (myfile, line))
        {
            data.push_back(line);
        }
        myfile.close();
    }

    return data;
}

int main () {

    // auto data;
    int count = 0;
    std::vector<std::string> all_data;
    while (true)
    {
        count++;
        if (count % 5 == 0)
        {
            auto data = read_file();
            all_data.insert(
                std::end(all_data),
                std::begin(data),
                std::end(data));
        }

        auto now = std::chrono::system_clock::now();
        std::time_t time_now = std::chrono::system_clock::to_time_t(now);
        std::string t( ctime( &time_now ) );
        std::stringstream stime;
        stime << t.substr( 0, t.length() -1  );

        std::cout
            << "[" << stime.str() << "] " << count << " pid=" << getpid()
            << " rss=" << float(getCurrentRSS()) / 1024 / 1024
            << "MB " << std::endl;

        // std::this_thread::sleep_for(std::chrono::milliseconds(5000));

        if (count > 31)
        {
            break;
        }
    }

    return 0;
}