#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define INPUT_FILE "inputfile_2.txt"

int main()
{
    std::cout << " Advent Of Code 2020: day 2: part 2\n";

    std::vector<string> lines;
    std::string delimiter1 = "-";
    std::string delimiter2 = " ";
    std::string delimiter3 = ":";
    int valid = 0;

    FILE *fp = fopen(INPUT_FILE, "r");
    if (fp == NULL)
    {
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
        string key1 = s.substr(0, pos1);

        size_t pos2 = s.find(delimiter2);
        string key2 = s.substr(pos1 + 1, pos2 - (pos1 + 1));

        size_t pos3 = s.find(delimiter3);
        string key3 = s.substr(pos2 + 1, 1);

        size_t pos4 = (pos3 + 2);
        string key4 = s.substr(pos4, ' ');

        int match = 0;
        if (key4[stoi(key1) - 1] == key3[0])
        {
            match++;
        }
        if (key4[stoi(key2) - 1] == key3[0])
        {
            match++;
        }
        if (match == 1)
        {
            valid++;
        }
    }
    std::cout << " Valid passwords : " << valid << '\n';
    return 0;
}