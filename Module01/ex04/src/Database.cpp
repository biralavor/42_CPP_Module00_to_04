/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Database.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:23:23 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/10 18:06:48 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Database.hpp"

Database::Database()
{
    // Default constructor
}

Database::~Database()
{
    // Default destructor
}

bool Database::databaseLoader(const std::string &filename,
    std::string &_inputContent)
{
    std::ifstream   file;
    std::string     line;
    int             lines_counter = 0;

    file.open(filename.c_str());
    if(!file)
    {
        std::cerr
        << "Error: Could not open file " << filename
        << std::endl;
        return false;
    }
    while(std::getline(file, line))
    {
        _inputContent += line + "\n";
        lines_counter++;
    }
    if (lines_counter == 0)
    {
        std::cerr
        << "Error: File " << filename << " is empty."
        << std::endl;
        return false;
    }
    file.close();
    return true;
}

bool Database::outputFileCreator(std::ofstream &outputFile,
    const std::string &filename)
{
    outputFile.open((filename + ".replace").c_str());
    if (!outputFile)
    {
        std::cerr
        << "Error: Could not create output file "
        << filename << ".replace" << std::endl;
        return false;
    }
    return true;
}

bool Database::databaseManager(char **argv, std::string &_inputContent,
    std::ofstream &_outputFile)
{
    std::string filename;

    filename = argv[1];
    if (databaseLoader(filename, _inputContent))
    {
        if (outputFileCreator(_outputFile, filename))
            return true;
    }
    return false;
}
