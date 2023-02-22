/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibby <obibby@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:32:51 by obibby            #+#    #+#             */
/*   Updated: 2023/02/01 13:59:25 by obibby           ###   ########.fr       */
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
		if (buff.find("listen") != std::string::npos)
		{
			pos = buff.find_first_of("1234567890");
			if (pos == std::string::npos)
				throw std::invalid_argument("Bad configuration file.");
			port = toInt(&buff[pos]);
		}
		else if (buff.find("server_name") != std::string::npos)
		{
			pos = buff.find_first_not_of(" \r\t\b\f");
			if (pos == std::string::npos)
				throw std::invalid_argument("Bad configuration file.");
			name = buff.substr(pos, buff.size() - (1 + pos));
		}
		else if (buff.find("root") != std::string::npos)
		{
			pos = buff.find_first_not_of(" \r\t\b\f");
			if (pos == std::string::npos)
				throw std::invalid_argument("Bad configuration file.");
			root = buff.substr(pos, buff.size() - (1 + pos));
		}
		else if (buff.find("location") != std::string::npos)
		{
			add_location(stream, buff);
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
		local_root = src.local_root;
		local_methods = src.local_methods;
	}
	return *this;
}

void Server::add_location(std::ifstream &stream, std::string buff)
{
	size_t	pos;
	size_t	pos2;
	std::string location;

	pos = buff.find_first_not_of(" \r\t\b\f");
	pos = buff.find_first_of(" \r\t\b\f", pos);
	pos = buff.find_first_not_of(" \r\t\b\f", pos);
	pos2 = buff.find_first_of(" \r\t\b\f", pos);
	if (pos == std::string::npos || pos2 == std::string::npos)
		throw std::invalid_argument("Bad configuration file.");
	location = buff.substr(pos, pos2 - pos);
	while (!stream.eof() && buff.find_first_of('{') == std::string::npos)
		std::getline(stream, buff);
	map_location(stream, buff, location);
}

void	Server::map_location(std::ifstream &stream, std::string buff, std::string location)
{
	size_t pos;

	if (buff.find("root") != std::string::npos)
	{
		pos = buff.find_first_not_of(" \r\t\b\f");
		if (pos == std::string::npos)
			throw std::invalid_argument("Bad configuration file.");
		local_root.insert(location, )
	}
	else if (buff.find("methods") != std::string::npos)
	{
		pos = buff.find_first_not_of(" \r\t\b\f");
		if (pos == std::string::npos)
			throw std::invalid_argument("Bad configuration file.");

	}
}

Server::~Server()
{

}
