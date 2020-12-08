#include <iostream>
#include <vector>
using namespace std;

#define INPUT_FILE "inputfile_1.txt"

int main()
{
    FILE *fp = fopen(INPUT_FILE, "r");
    if (fp == NULL)
    {
        cout << "Could not open input file.\n";
        exit(EXIT_FAILURE);
    }

    std::vector<int> ints;
    char *line = NULL;
    size_t len = 0;
    while ((getline(&line, &len, fp)) != -1)
    {
        ints.push_back(atoi(line));
    }
    fclose(fp);
    if (line)
        free(line);
    int lineCount = ints.size();
    cout << "Line count : " << lineCount << '\n';

    // part 1
    for (size_t i = 0; i < ints.size(); i++)
    {
        for (size_t j = i + 1; j < ints.size(); j++)
        {
            if (ints[i] + ints[j] == 2020)
            {
                cout << "The 2020 pair product is: ";
                cout << ints[i] << ' ';
                cout << ints[j] << '\n';
                cout << (ints[i] * ints[j]);
            }
        }
    }

    // part 2
    for (size_t i = 0; i < ints.size(); i++)
    {
        for (size_t j = i + 1; j < ints.size(); j++)
        {
            for (size_t k = j + 1; k < ints.size(); k++)
            {
                if (ints[i] + ints[j] + ints[k] == 2020)
                {
                    cout << "The 2020 triplet product is: ";
                cout << ints[i] << ' ';
                cout << ints[j] << ' ';
                cout << ints[k] << '\n';
                cout << (ints[i] * ints[j] * ints[k]);
                }
            }
        }
    }
    return 0;
}