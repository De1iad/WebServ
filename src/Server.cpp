/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibby <obibby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:32:51 by obibby            #+#    #+#             */
/*   Updated: 2023/01/27 12:52:31 by obibby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Server.hpp"

int	toInt(std::string str)
{
	int	x;
	std::istringstream ss(str);
	ss >> x;
	return x;
}
Server::Server(std::ifstream &stream)
{
	std::string buff;
	size_t	pos;
	while (std::getline(stream, buff))
	{
		if (buff.find("listen"))
		{
			pos = buff.find_first_not_of("listen\n\t\b\f\r");
			if (pos == std::string::npos)
				throw std::invalid_argument("Bad configuration file.");
			printf("%s\n", buff.c_str());
			port = toInt(&buff[pos]);
			printf("port: %d", port);
		}
	}
}

Server::Server(const Server &src)
{
	*this = src;
}

Server &Server::operator=(const Server &src)
{
	if (this != &src)
	{
		port = src.port;
		name = src.name;
		max_body_size = src.max_body_size;
		location = src.location;
		local_root = src.local_root;
		local_methods = src.local_methods;
	}
	return *this;
}

