/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReplaceThisWithThat.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:25:20 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/10 16:55:09 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ReplaceThisWithThat.hpp"
#include "Database.hpp"

ReplaceThisWithThat::ReplaceThisWithThat()
{
    // Default constructor
}

ReplaceThisWithThat::~ReplaceThisWithThat()
{
    // Default destructor
}

std::string ReplaceThisWithThat::replaceLineRunner(const std::string &fullLine,
    const std::string &s1, const std::string &s2)
{
    std::string modifiedLine;
    size_t      pos;

    pos = 0;
    while (pos < fullLine.length())
    {
        if (fullLine.substr(pos, s1.length()) == s1)
        {
            modifiedLine += s2;
            pos += s1.length();
        }
        else
        {
            modifiedLine += fullLine[pos];
            pos++;
        }
    }
    return modifiedLine;
}

void ReplaceThisWithThat::replaceManager(char **argv)
{
    _s1 = argv[2];
    _s2 = argv[3];
    _inputContent = "";
    if (this->_database.databaseManager(argv, _inputContent, _outputFile))
    {
        _outputFile << replaceLineRunner(_inputContent, _s1, _s2);
    }
    this->_outputFile.close();
}
