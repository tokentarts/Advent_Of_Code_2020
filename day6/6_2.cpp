#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

#define INPUT_FILE "inputfile_6.txt"

int main()
{
    cout << " Advent Of Code 2020: day 6: part 2\n";

    int total = 0;
    char *line = NULL;
    size_t len = 0;
    int lineCount = 0;
    int alphabet[26] = {0};

    FILE *fp = fopen(INPUT_FILE, "r");
    if (fp == NULL)
    {
        cout << "Could not open input file.\n";
        exit(EXIT_FAILURE);
    }

    while ((getline(&line, &len, fp)) != -1)
    {
        if (line[0] != '\n')
        {
            for (int i = 0; i < int(len); i++)
            {
                if (line[i] == '\0') // endline, leave
                {
                    break;
                }
                else
                {
                    char c = line[i];
                    int alphabetIndex = (int(c)) - 'a';
                    if (c == 10) // dont add to index
                    {
                        break;
                    }
                    else // add to index
                    {
                        alphabet[alphabetIndex] += 1;
                    }
                }
            }
            lineCount++;
        }
        if (line[0] == '\n')
        {
            for (int i = 0; i < 26; i++)
            {
                if (lineCount == alphabet[i]) // check, # of votes == # of ppl in group
                {
                    total++;
                }
            }
            lineCount = 0;               // reset
            for (int i = 0; i < 26; i++) // reset
            {
                alphabet[i] = 0;
            }
        }
    }

    fclose(fp);
    if (line)
        free(line);

    cout << " Total : " << total << '\n';
    return 0; // Return me, since u want comments (:
}