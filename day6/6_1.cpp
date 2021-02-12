#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define INPUT_FILE "inputfile_6.txt"

string clean(string temp)
{
    sort(temp.begin(), temp.end()); // Sort a-z

    // No duplicates
    for (int i = 0; i < temp.size(); i++)
    {
        char c = temp[i];
        for (int j = i + 1; j < temp.size(); j++)
        {
            if (c == temp[j])
            {
                temp[j] = ' ';
            }
        }
    }
    temp.erase(remove(temp.begin(), temp.end(), ' '), temp.end()); // Remove spaces
    return temp;
}

string clean2(string countMe)
{
    countMe.erase(remove(countMe.begin(), countMe.end(), '\n'), countMe.end()); // Remove spaces

    return countMe;
}

int main()
{
    std::cout << " Advent Of Code 2020: day 6: part 1\n";

    FILE *fp = fopen(INPUT_FILE, "r");
    if (fp == NULL)
    {
        std::cout << " Could not open input file.\n";
        exit(EXIT_FAILURE);
    }

    char *line = NULL;
    size_t len = 0;
    string temp = "";
    string countMe = "";
    while ((getline(&line, &len, fp)) != -1)
    {
        if (line[0] != '\n')
        {
            temp.append(line);
        }
        else
        {
            temp = clean(temp);
            countMe.append(temp);
            temp = "";
        }
    }
    fclose(fp);
    if (line)
        free(line);

    countMe = clean2(countMe);
    cout << " Total: ";
    cout << countMe.size();
    return 0;
}