/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:10:17 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/07 19:16:10 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DatabaseManager.hpp"
#include "ReplaceManager.hpp"

int main(int argc, char **argv)
{
    std::string filename;
    std::string s1;
    std::string s2;
    std::vector<std::string> originalContent;
    std::ofstream outputFile;

    if (argc != 4 || argv[1][0] == '\0'
        || argv[2][0] == '\0'  || argv[3][0] == '\0')
    {
        std::cerr
        << "Usage: " << argv[0]
        << " filename string_to_be_replaced string_to_replace_with"
        << std::endl;
        return 1;
    }
    filename = argv[1];
    s1 = argv[2];
    s2 = argv[3];
    if (databaseLoader(filename, originalContent))
    {
        if (outputFileCreator(outputFile, filename))
        {
            replaceManager(originalContent, s1, s2, outputFile);
        }
    }
    outputFile.close();
    return 0;
}
