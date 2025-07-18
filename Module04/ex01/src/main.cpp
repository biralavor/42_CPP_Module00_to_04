/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:25:44 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/18 11:32:29 by umeneses         ###   ########.fr       */
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
	
	std::cout << RED << "The food has gone!" << std::endl;
	for (int idx = 0; idx < size; idx++)
		delete hungryAnimal[idx];
	
	Dog lancelot;
	
	lancelot.getBrain()->setIdea(0, "Sit");
	lancelot.getBrain()->setIdea(1, "Slobber");
	lancelot.getBrain()->setIdea(2, "Bark");
	
	for (int idx = 0; idx < 3; idx++)
	{
		std::cout << "show Dog's mind: "
		<< lancelot.getBrain()->getIdea(idx) << std::endl;
	}

	Cat lili;
	
	lili.getBrain()->setIdea(0, "Give a slice of Tuna");
	lili.getBrain()->setIdea(1, "Acctualy, could be three big slices of Tuna");
	lili.getBrain()->setIdea(2, "NOW I WANT AN ENTIRE TUNA!! ..... >('> ");

	for (int idx = 0; idx < 3; idx++)
	{
		std::cout << "show Cat's mind: "
		<< lili.getBrain()->getIdea(idx) << std::endl;
	}
	return 0;
}
