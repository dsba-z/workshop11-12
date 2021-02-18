#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <map>

using std::cout;
using std::cin;
using std::endl;

typedef std::vector<int> VecInt;
typedef std::map<int, size_t> MapInt;

void printVec(const VecInt& vecInt)
{
    std::cout << "\nPrinting vector\n";
    int i = 1;
    for(int num : vecInt)
    {
        std::cout << i << ") " << num << std::endl;
        ++i;
    }
}

void printMap(const MapInt& mapInt)
{
    cout << "\nPrinting map\n";
    for (const std::pair<const int, size_t>& a : mapInt)
    {
        cout << a.first << ": " << a.second << "\n";
    }
}


VecInt generateVector(size_t n, int rangeStart, int rangeEnd)
{
    std::mt19937 gen(time(nullptr));
    std::uniform_int_distribution<int> distr(rangeStart, rangeEnd - 1);

    VecInt vec;
    for (size_t i = 0; i < n; ++i)
    {
        int rNum = distr(gen);
        vec.push_back(rNum);
    }
    return vec;
}


MapInt countElements(const VecInt& vec)
{
    MapInt countMap;
    for (int el : vec)
    {
        if (countMap.count(el))
        {
            countMap[el]++;
        }
        else
        {
            countMap[el] = 1;
        }
    }
    return countMap;
}

int main()
{

    int n;
    int r;
    int q;
    cout << "Enter how many numbers to generate:\n";
    cin >> n;
    cout << "Enter the start of the range\n";
    cin >> r;
    cout << "Enter the end of the range:\n";
    cin >> q;
    
    VecInt vec = generateVector(n, r, q);
    printVec(vec);
    
    std::map<int, size_t> countMap = countElements(vec);
    printMap(countMap);

    
    return 0;
}
