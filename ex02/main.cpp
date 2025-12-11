/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:08:48 by oait-si-          #+#    #+#             */
/*   Updated: 2025/12/11 18:23:42 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "Brain.h"

int main()
{
        
    // const Animal* meta = new Animal(); 
    // Animal horse ;
    std::cout << "--- Testing Valid Subclasses ---" << std::endl;

    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << "\n[Sound Check]" << std::endl;
    dog->makeSound(); // Should print "Woof"
    cat->makeSound(); // Should print "Meow"

    // --- Test 3: Destruction (Check for leaks) ---
    std::cout << "\n[Destruction Check]" << std::endl;
    delete dog;
    delete cat;

    return 0;
}