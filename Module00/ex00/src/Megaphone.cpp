/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:31:21 by umeneses          #+#    #+#             */
/*   Updated: 2025/04/03 13:28:19 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Megaphone.hpp"

int main()
{
	int a, b;
	int sum;
	char megaphone[50];
	
	a = 40;
	b = 2;
	sum = a + b;
	strcpy(megaphone,"Helloooooooo World");
	std::cout <<
		megaphone << ", " << sum << "!" << std::endl;
	return 0;
}
