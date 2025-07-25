/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:25:44 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/18 17:28:31 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main(void)
{
	{
		std::cout
		<< BLUE << ":::::::::::::::::::::: HUNGRY ANIMALS ::::::::::::::::::::::"
		<< RESET << std::endl;
		int size = 6;
		AAnimal *hungryAnimal[size];
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
	}
	
	{
		std::cout
		<< BLUE << "\n:::::::::::::::::::::: ACCESSING THE BRAIN ::::::::::::::::::::::"
		<< RESET << std::endl;
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
	}

	{
		std::cout
		<< BLUE << "\n:::::::::::::::::::::: HEAP ANIMALS ::::::::::::::::::::::"
		<< RESET << std::endl;
		const AAnimal* j = new Dog();
		const AAnimal* i = new Cat();
		AAnimal* h = new Cat();
		j->makeSound();
		h->makeSound();
		delete j;
		delete i;
		delete h;
	}

	// std::cout << RED << "\n\n ::::: now, trying to initialize a class \n"
	// << "with a pure virtual class member function \n :::" << RESET<< std::endl;
	// AAnimal purevirtual;
	return 0;
}
