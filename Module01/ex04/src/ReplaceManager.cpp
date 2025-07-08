/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReplaceManager.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:25:20 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/08 13:18:16 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ReplaceManager.hpp"

std::string replaceLineRunner(std::string &originalLine,
    const std::string &s1, const std::string &s2)
{
    std::string modifiedLine;
    std::string word;
    size_t      pos;

    pos = 0;
    while (pos < originalLine.length())
    {
        if (originalLine.substr(pos, s1.length()) == s1)
        {
            modifiedLine += s2;
            pos += s1.length();
        }
        else
        {
            modifiedLine += originalLine[pos];
            pos++;
        }
    }
    return modifiedLine;
}

void replaceManager(std::vector<std::string> &originalContent,
    const std::string &s1, const std::string &s2,
    std::ofstream &outputFile)
{
    std::string line;

    for (size_t idx = 0; idx < originalContent.size(); idx++)
    {
        line = originalContent[idx];
        outputFile << replaceLineRunner(line, s1, s2);
    }
}
