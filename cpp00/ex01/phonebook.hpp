/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliamorozova <yuliamorozova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:33:32 by ymorozov          #+#    #+#             */
/*   Updated: 2023/09/23 10:24:02 by yuliamorozo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <string>
// #include <iomanip>

class Contact {
    private:
        std::string id;
        std::string firstname;
        std::string lastname;
        std::string nickname;
        std::string number;
        std::string darkest_secret;
    public:
        Contact();
        ~Contact();
        void add_contact(int i);
        std::string get_id();
        std::string get_firstname();
        std::string get_lastname();
        std::string get_nickname();
        std::string get_number();
        std::string get_secret();
};

class Phonebook {
    private:
        Contact contacts[8];
        void print_table();
    public:
        Phonebook();
        ~Phonebook();
        int counter;
        void add();
        void search();
};

#endif