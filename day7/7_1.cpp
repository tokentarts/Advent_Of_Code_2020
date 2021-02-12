#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define INPUT_FILE "inputfile_7.txt"

int main()
{
    FILE *fp = fopen(INPUT_FILE, "r");
    if (fp == NULL)
    {
        std::cout << "Could not open input file.\n";
        exit(EXIT_FAILURE);
    }

    char *line = NULL;
    size_t len = 0;
    string delimiter = "bags";

    vector<string> keys;
    vector<string> lines;
    string shiny("shiny gold");

    int lineCount = 0;
    while ((getline(&line, &len, fp)) != -1)
    {
        string s = line;
        lines.push_back(string(s));
        lineCount++;
        // Find shiny bag
        std::size_t found = s.find(shiny);
        if (found != std::string::npos)
        {
            std::cout << " line : " << line << '\n';
            std::cout << " 'shiny gold' found at: " << found << '\n';

            // if shiny, find new key

            size_t pos = 0;

            pos = s.find(delimiter, 0);
            std::string key = s.substr(0, pos);
            int temp = found;

            if (std::find(keys.begin(), keys.end(), key) != keys.end()) // element is present
                break;
            else // element is not present
                keys.push_back(string(key));

            std::cout << "line: " << line << '\n';
            std::cout << "line count : " << lineCount << '\n';
            std::cout << "temp: " << temp << '\n';
            std::cout << "key : " << key << "\n\n";
        }
    }

    fclose(fp);
    if (line)
        free(line);

    for (int c = 0; c < keys.size(); c++)
    {
        std::cout << "keys [" << c << "] :" << keys[c] << '\n';
    }

    for (size_t i = 0; i < keys.size(); i++)
    {
        string type = keys[i];
        for (size_t j = 0; j < lines.size(); j++)
        {
            std::string s = lines[j];

            std::size_t found = s.find(type);
            if (found != std::string::npos)
            {
                std::cout << " line : " << lines[j] << '\n';
                std::cout << " '" << keys[i] << "' found at: " << found << '\n';

                // if shiny, find new key

                size_t pos = 0;

                pos = s.find(delimiter, 0);
                std::string key = s.substr(0, pos);

                if (std::find(keys.begin(), keys.end(), key) != keys.end()) // element is present
                    key = "";
                else // element is not present
                    keys.push_back(string(key));
                key = "";
            }
        }
    }
    for (int i = 0; i < keys.size(); i++)
    {
        cout << " key[" << i << "] :" << keys[i] << '\n';
    }

    return 0;
}