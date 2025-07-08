/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:10:17 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/07 19:47:16 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DatabaseManager.hpp"

int main(int argc, char **argv)
{
    if (argc != 4 || argv[1][0] == '\0'
        || argv[2][0] == '\0'  || argv[3][0] == '\0')
    {
        std::cerr
        << "Usage: " << argv[0]
        << " filename string_to_be_replaced string_to_replace_with"
        << std::endl;
        return 1;
    }
    databaseManager(argv);
    return 0;
}
