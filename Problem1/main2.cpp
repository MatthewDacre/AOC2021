#include <fstream>
#include <algorithm>
#include <string>
#include <optional>
#include <array>
#include <iostream>
#include <numeric>


int firstDaySolution2()
{
    std::ifstream data("input");
    if(data.fail()) std::cout << "Error";

    std::string current;
    int condition = 0;
    auto increased = 0;
    std::array<int, 3> firstWindow{};
    std::array<int, 3> secondWindow{};
    std::pair<int, int> positions = {-1, -2};
    bool gotFirst = false;
    int sum1;
    int sum2;

    while(std::getline(data, current))
    {
        condition++;
        positions.first++; positions.second++;

        auto currentToInt = std::stoi(current);

        if (gotFirst)
        {
            secondWindow[positions.second] = currentToInt;
            if(condition >=4)
            {
                sum2 = std::accumulate(secondWindow.begin(), secondWindow.end(), 0);
                if(sum1 < sum2) ++increased;
            }
        }

        firstWindow[positions.first] = currentToInt;
        if(condition >= 3)
            sum1 = std::accumulate(firstWindow.begin(), firstWindow.end(), 0);

        gotFirst = true;
        if(positions.first == 2) positions.first = -1;
        if(positions.second == 2) positions.second = -1;
    }
    data.close();
    return increased;
}

int main(int argc, char const *argv[])
{
    std::cout<<firstDaySolution2()<<std::endl;
    return 0;
}
