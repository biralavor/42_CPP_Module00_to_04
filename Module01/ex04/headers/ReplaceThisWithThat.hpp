/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReplaceThisWithThat.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:23:22 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/10 17:00:37 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Database.hpp"

class ReplaceThisWithThat
{
    std::string     _inputContent;
    std::ofstream   _outputFile;
    std::string     _s1;
    std::string     _s2;
    Database        _database;

    std::string replaceLineRunner(const std::string &fullLine,
        const std::string &s1, const std::string &s2);
public:
    ReplaceThisWithThat();
    ~ReplaceThisWithThat();
    void replaceManager(char **argv);
};
