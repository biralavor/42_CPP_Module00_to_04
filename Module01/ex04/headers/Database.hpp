/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Database.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:17:28 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/10 18:07:20 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <fstream>
#include <iostream>
#include <string>

class Database
{

public:
    bool databaseLoader(const std::string &filename, 
        std::string &inputContent);
    
    bool outputFileCreator(std::ofstream &outputFile,
        const std::string &filename);
    
    bool databaseManager(char **argv, std::string &_inputContent,
        std::ofstream &_outputFile);
    Database();
    ~Database();
};
