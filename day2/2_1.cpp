#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define INPUT_FILE "inputfile_2.txt"

int main()
{
    cout << " Advent Of Code 2020: day 2: part 1\n";

    std::vector<string> lines;
    std::vector<int> lowNum;
    std::vector<int> highNum;
    std::vector<int> countNum;
    std::vector<string> letter;
    std::vector<string> password;
    std::string delimiter1 = "-";
    std::string delimiter2 = " ";
    std::string delimiter3 = ":";
    int valid = 0;

    FILE *fp = fopen(INPUT_FILE, "r");
    if (fp == NULL)
    {
        cout << " ERROR: Could not open input file.\n";
        exit(EXIT_FAILURE);
    }

    char *line = NULL;
    size_t len = 0;
    while ((getline(&line, &len, fp)) != -1)
    {
        lines.push_back(string(line));
    }
    fclose(fp);
    if (line)
        free(line);

    for (size_t i = 0; i < 1000; i++)
    {
        std::string s = lines[i];
        size_t pos1 = 0;

        pos1 = s.find(delimiter1, 0);
        std::string key1 = s.substr(0, pos1);
        lowNum.push_back(std::stoi(key1));

        size_t pos2 = s.find(delimiter2);
        std::string key2 = s.substr(pos1 + 1, pos2 - (pos1 + 1));
        highNum.push_back(std::stoi(key2));

        size_t pos3 = s.find(delimiter3);
        std::string key3 = s.substr(pos2 + 1, 1);
        letter.push_back(key3);

        size_t pos4 = (pos3 + 2);
        std::string key4 = s.substr(pos4, ' ');
        password.push_back(std::string(key4));

        int letterCount = 0;
        for (int k = 0; k < key4.size(); k++)
        {
            if (key4[k] == key3[0])
            {
                letterCount++;
            }
        }
        countNum.push_back(letterCount);

        if (countNum[i] >= lowNum[i] &&
            countNum[i] <= highNum[i])
        {
            valid++;
        }
    }

    cout << " Valid passwords : " << valid << '\n';
    return 0;
}