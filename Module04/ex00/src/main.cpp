/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:25:44 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/16 19:22:37 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"

int main(void)
{
	Animal defaultAnimal;
	Animal parameterizedAnimal("Dog");
	Animal copiedAnimal(parameterizedAnimal);
	Animal assignedAnimal = defaultAnimal;

	Dog defaultDog;
	Dog parameterizedDog("Lancelot");
	Dog copiedDog(parameterizedDog);
	Dog assignedDog = defaultDog;
	
	std::cout << "\n\n defaultAnimal Type: " << defaultAnimal.getType() << std::endl;
	defaultAnimal.makeSound();
	std::cout << "\n\n parameterizedAnimal Type: " << parameterizedAnimal.getType() << std::endl;
	parameterizedAnimal.makeSound();
	std::cout << "\n\n copiedAnimal Type: " << copiedAnimal.getType() << std::endl;
	copiedAnimal.makeSound();
	std::cout << "\n\n assignedAnimal Type: " << assignedAnimal.getType() << std::endl;
	assignedAnimal.makeSound();
	std::cout << "\n\n defaultDog Type: " << defaultDog.getType() << std::endl;
	defaultDog.makeSound();
	std::cout << "\n\n parameterizedDog Type: " << parameterizedDog.getType() << std::endl;
	parameterizedDog.makeSound();
	std::cout << "\n\n copiedDog Type: " << copiedDog.getType() << std::endl;
	copiedDog.makeSound();
	std::cout << "\n\n assignedDog Type: " << assignedDog.getType() << std::endl;
	assignedDog.makeSound();
	return 0;
}
