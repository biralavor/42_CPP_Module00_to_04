/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReplaceManager.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:25:20 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/07 19:15:58 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ReplaceManager.hpp"

void replaceManager(std::vector<std::string> &originalContent,
    const std::string &s1, const std::string &s2,
    std::ofstream &outputFile)
{
    std::string line;
    for (size_t idx = 0; idx < originalContent.size(); idx++)
    {
        line = originalContent[idx];
        outputFile << line;
    }
    
    (void) s1; // Avoid unused parameter warning
    (void) s2; // Avoid unused parameter warning
}
