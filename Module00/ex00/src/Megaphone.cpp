/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:31:21 by umeneses          #+#    #+#             */
/*   Updated: 2025/04/03 12:23:45 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

int main()
{
	int a, b;
	int sum;
	char megaphone[50];
	
	a = 40;
	b = 2;
	sum = a + b;
	strcpy(megaphone,"Helloooooooo World!");
	std::cout <<
		megaphone << ", " << sum << std::endl;
	return 0;
}
