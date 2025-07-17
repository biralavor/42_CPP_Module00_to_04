/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:25:44 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/17 20:00:11 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main(void)
{
	int size = 6;
	
	Animal *hungryAnimal[size];
	
	for (int idx = 0; idx < size; idx++)
	{
		if (idx % 2 == 0)
			hungryAnimal[idx] = new Cat();
		else
			hungryAnimal[idx] = new Dog();
	}
	
	std::cout
	<< BLUE << "\nhey, I have a steak on my hand!\n" << RESET
	<< std::endl;
	
	for (int idx = 0; idx < size; idx++)
		hungryAnimal[idx]->makeSound();
	
	Dog Lancelot;
	
	Lancelot.getBrain()->setIdea(0, "Sit");
	Lancelot.getBrain()->setIdea(1, "Babar");
	Lancelot.getBrain()->setIdea(2, "Bark");
	
	for (int idx = 0; idx < 3; idx++)
	{
		std::cout << "\n show the ideias: "
		<< Lancelot.getBrain()->getIdea(idx) << std::endl;
	}
	
	return 0;
}
