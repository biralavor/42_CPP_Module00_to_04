/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Printers.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 18:51:21 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/05 18:51:22 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include <iomanip>

class PhoneBook;
class Contact;

class Printers
{
public:
    void oneCellAlignToCenterPrinter(const std::string &str) const;
    void oneCellAlignToRightPrinter(const std::string &str) const;
    void contactDetailsAsARowPrinter(const Contact &contact) const;
    void searchContactDetailsPrinter(int idx, const Contact &contact) const;
    void phoneBookHeaderPrinter() const;
    void searchContactHeaderPrinter() const;
    void phoneBookPrinter(const PhoneBook &phoneBook) const;
    void phoneBookMainMenuPrinter() const;
};
