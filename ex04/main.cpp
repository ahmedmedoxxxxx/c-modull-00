/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 00:00:00 by student           #+#    #+#             */
/*   Updated: 2025/12/11 00:00:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <fstream>
#include <iostream>
#include <fstream>
#include <string>

int main (int ac,char **av)
{
    if (ac != 4)
    {
         std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
         return 1;
    }
    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

    if (s1.empty())
    {
        std::cerr << "Error: s1 cannot be empty." << std::endl;
        return 1;
    }
    // Open input file for reading
    std::ifstream input_file(filename.c_str());
    if (!input_file.is_open())
    {
        std::cerr << "Error: Could not open file: " << filename << std::endl;
        return 1;
    }

    // Read entire file content into a string
    std::string content;
    std::string line;
    while (std::getline(input_file, line))
    {
        content = content + line;
        if (!input_file.eof())
            content += '\n';
    }
    input_file.close();

    // Manual string replacement (without using std::string::replace)
    std::string result;
    size_t pos = 0;
    size_t found;

    while (pos < content.length())
    {
        found = content.find(s1, pos);
        if (found == std::string::npos)
        {
            // No more occurrences, append the rest
            result += content.substr(pos);
            break;
        }
        // Append everything before the found position
        result += content.substr(pos, found - pos);
        // Append s2 instead of s1
        result += s2;
        pos = found + s1.length();
    }
    std::string output_filename = filename + ".replace";
    std::ofstream output_file(output_filename.c_str());
    if (!output_file.is_open())
    {
        std::cerr << "Error: Could not create output file: " << output_filename << std::endl;
        return 1;
    }

    output_file << result;
    output_file.close();

    std::cout << "Success! Created: " << output_filename << std::endl;
    return (0);
}
