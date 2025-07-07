/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DatabaseManager.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:23:23 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/07 19:10:00 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DatabaseManager.hpp"

bool databaseLoader(const std::string &filename,
    std::vector<std::string> &originalContent)
{
    std::ifstream file;
    std::string line;
    int words_counter = 0;

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
        originalContent.push_back(line + "\n");
        words_counter++;
    }
    if (words_counter == 0)
    {
        std::cerr
        << "Error: File " << filename << " is empty."
        << std::endl;
        return false;
    }
    file.close();
    return true;
}

bool outputFileCreator(std::ofstream &outputFile,
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