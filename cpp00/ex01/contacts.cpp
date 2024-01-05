/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliamorozova <yuliamorozova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 09:39:36 by yuliamorozo       #+#    #+#             */
/*   Updated: 2023/09/23 10:57:59 by yuliamorozo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Contact::Contact() {
    ;
}

Contact::~Contact() {
    ;
}

void Contact::add_contact(int i) {
    id = std::to_string(i + 1);
    std::cout << "Enter first name: ";
    std::cin >> firstname;
    while (firstname.length() == 0) {
        std::cout << "\nEmpty! Try again: ";
        std::cin >> firstname;
    }
    std::cout << "Enter last name: ";
    std::cin >> lastname;
    while (lastname.length() == 0) {
        std::cout << "\nEmpty! Try again: ";
        std::cin >> lastname;
    }
    std::cout << "Enter nickname: ";
    std::cin >> nickname;
    while (nickname.length() == 0) {
        std::cout << "\nEmpty! Try again: ";
        std::cin >> nickname;
    }
    std::cout << "Enter phone number: ";
    std::cin >> number;
    while (number.length() == 0) {
        std::cout << "\nEmpty! Try again: ";
        std::cin >> number;
    }
    std::cout << "Enter the darkest secret: ";
    std::cin >> darkest_secret;
    while (darkest_secret.length() == 0) {
        std::cout << "\nEmpty! Try again: ";
        std::cin >> darkest_secret;
    }
}

std::string Contact::get_id() {
    return(id);
}

std::string Contact::get_firstname() {
    return(firstname);
}

std::string Contact::get_lastname() {
    return(lastname);
}

std::string Contact::get_nickname() {
    return(nickname);
}

std::string Contact::get_number() {
    return(number);
}

std::string Contact::get_secret() {
    return(darkest_secret);
}