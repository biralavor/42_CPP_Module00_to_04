/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:25:44 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/18 17:00:46 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
	{
		std::cout << ":::::::::: Classic STACK Animals ::::::::::"
		<< std::endl;
		Animal defaultAnimal;
		Animal parameterizedAnimal("Dog");
		Animal copiedAnimal(parameterizedAnimal);
		Animal assignedAnimal = defaultAnimal;

		Dog defaultDog;
		Dog parameterizedDog("Lancelot");
		Dog copiedDog(parameterizedDog);
		Dog assignedDog = defaultDog;

		Cat defaultCat;
		Cat parameterizedCat("Whiskers");
		Cat copiedCat(parameterizedCat);
		Cat assignedCat = defaultCat;

		std::cout << "\n\n defaultAnimal Type: "
		<< defaultAnimal.getType() << std::endl;
		defaultAnimal.makeSound();
		std::cout << "\n\n parameterizedAnimal Type: "
		<< parameterizedAnimal.getType() << std::endl;
		parameterizedAnimal.makeSound();
		std::cout << "\n\n copiedAnimal Type: "
		<< copiedAnimal.getType() << std::endl;
		copiedAnimal.makeSound();
		std::cout << "\n\n assignedAnimal Type: "
		<< assignedAnimal.getType() << std::endl;
		assignedAnimal.makeSound();
		std::cout << "\n\n defaultDog Type: "
		<< defaultDog.getType() << std::endl;
		defaultDog.makeSound();
		std::cout << "\n\n parameterizedDog Type: "
		<< parameterizedDog.getType() << std::endl;
		parameterizedDog.makeSound();
		std::cout << "\n\n copiedDog Type: "
		<< copiedDog.getType() << std::endl;
		copiedDog.makeSound();
		std::cout << "\n\n assignedDog Type: "
		<< assignedDog.getType() << std::endl;
		assignedDog.makeSound();
		std::cout << "\n\n defaultCat Type: "
		<< defaultCat.getType() << std::endl;
		defaultCat.makeSound();
		std::cout << "\n\n parameterizedCat Type: "
		<< parameterizedCat.getType() << std::endl;
		parameterizedCat.makeSound();
		std::cout << "\n\n copiedCat Type: "
		<< copiedCat.getType() << std::endl;
		copiedCat.makeSound();
		std::cout << "\n\n assignedCat Type: "
		<< assignedCat.getType() << std::endl;
		assignedCat.makeSound();
	}
	
	{
		std::cout << "\n:::::::::::::::::: HEAP Animals ::::::::::::::::::"
		<< std::endl;
		Animal *ani = new Animal();
		Animal *doug = new Dog("Doug");
		Animal *puffy = new Cat("Puffy");
		ani->makeSound();
		doug->makeSound();
		puffy->makeSound();
		delete ani;
		delete doug;
		delete puffy;
	}

	{
		std::cout
		<< RED << "\n\n:::::::::::::::::: WRONG Animals ::::::::::::::::::"
		<< RESET
		<< std::endl;
	
		WrongAnimal *badAnimal = new WrongAnimal("My name is badAnimal");
		WrongAnimal 	*badCat = new WrongCat("my name is badCat");
		badAnimal->makeSound();
		badCat->makeSound();
		delete badAnimal;
		delete badCat;
	}
	return 0;
}
