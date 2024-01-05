/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliamorozova <yuliamorozova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:14:22 by ymorozov          #+#    #+#             */
/*   Updated: 2023/10/23 12:37:55 by yuliamorozo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int argc, char **argv) {

	if (argc != 4) {
		std::cerr << "Error, wrong number of arguments" << std::endl;
		return 1;
	}
	std::string inf = argv[1];
	std::string outf = inf + ".replace";
	std::string str_find = argv[2];
	std::string str_repl = argv[3];
	
	std::ifstream in_file;
	in_file.open(inf.c_str(), std::ios::in);
	if (!in_file.is_open()) {
		std::cerr << "Error, can't open infile" << std::endl;
		return 2;
	}
	std::ofstream out_file;
	out_file.open(outf.c_str(), std::ios::out);
	if (!out_file.is_open()) {
		std::cerr << "Error, can't open outfile" << std::endl;
		in_file.close();
		return 3;
	}
	std::string str_readed;
	
	for(std::string line; getline(in_file, line); ) {
		str_readed += line;
		str_readed += "\n";
		size_t idx = 1;
		while (idx != std::string::npos)
		{
			idx = str_readed.find(str_find, 0);
			if (idx == std::string::npos)
				break;
			str_readed.erase(idx, str_find.length());
			str_readed.insert(idx, str_repl);
		}
		out_file << str_readed;
		str_readed.clear();
	}
	in_file.close();
	out_file.close();
	return 0;
}