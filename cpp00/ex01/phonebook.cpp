/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliamorozova <yuliamorozova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:30:10 by yuliamorozo       #+#    #+#             */
/*   Updated: 2023/10/19 11:18:53 by yuliamorozo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

//using namespace std;

Phonebook::Phonebook() {
    counter = 0;
    std::cout << "Welcome to Awesome PhoneBook\nUsage:" << std::endl;
    std::cout << "  [ADD]   [SEARCH]    [EXIT]" << std::endl;
}

Phonebook::~Phonebook() {
    std::cout << "Bye!" << std::endl;
}

void Phonebook::add() {
    int i = counter;
    
    if (i > 7) {
        i = counter % 8;
        std::cout << "Contact [" << i + 1 << "/8] will be overwritten" << std::endl;
    }
    contacts[i].add_contact(i);
    counter++;
    std::cout << "Contact [" << i + 1 << "/8] added" << std::endl;
}

void Phonebook::search() {
    std::string str;
    int i;
    
    if (counter == 0) {
        std::cout << "Empty phonebook" << std::endl;
        return;
    }
    print_table();
    std::cout << "Select index from 1 to 8: ";
    std::cin >> i;
    if (1 <= i && i <= 8) {
        if (i - 1 >= counter) {
            std::cout << "Invalid ID" << std::endl;
            return;
        }
        std::cout << "First name: " << contacts[i - 1].get_firstname() << std::endl;
        std::cout << "Last name: " << contacts[i - 1].get_lastname() << std::endl;
        std::cout << "Nickname: " << contacts[i - 1].get_nickname() << std::endl;
        std::cout << "Phone number: " << contacts[i - 1].get_number() << std::endl;
        std::cout << "The darkest secret: " << contacts[i - 1].get_secret() << std::endl;
    }
    else {
        std::cout << "Invalid index" << std::endl;
    }
}

void print_field(std::string str) {
    std::string tmp = str;
    
	if (tmp.length() < 10)
	{
		while (tmp.length() < 10)
			tmp.insert(0, " ");
	}
	else if (tmp.length() >= 10)
		tmp = tmp.substr(0, 9) + ".";
	std::cout << tmp << "|";
}

void Phonebook::print_table() {
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    for (int i = 0; i < counter; i++)
    {
        std::cout << "|";
        print_field(contacts[i].get_id());
        print_field(contacts[i].get_firstname());
        print_field(contacts[i].get_lastname());
        print_field(contacts[i].get_nickname());
        std::cout << std::endl;
    } 
}

int main() {
    Phonebook phonebook;
    std::string str;
    
    while (str != "EXIT") {
        std::cout << "Choose the command:   >";
        std::cin >> str;
        if (std::cin.eof())
            break;
        if (str == "ADD")
            phonebook.add();
        else if (str == "SEARCH")
            phonebook.search();
    }
    return 0;
}