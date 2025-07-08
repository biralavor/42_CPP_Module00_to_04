/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DatabaseManager.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:17:28 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/07 19:47:06 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

bool databaseLoader(const std::string &filename, 
    std::vector<std::string> &originalContent);

bool outputFileCreator(std::ofstream &outputFile,
    const std::string &filename);

void databaseManager(char **argv);
