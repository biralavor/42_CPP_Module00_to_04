/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReplaceManager.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:23:22 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/07 18:25:09 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "DatabaseManager.hpp"

void replaceManager(std::vector<std::string> &originalContent,
    const std::string &s1, const std::string &s2,
    std::ofstream &outputFile);
