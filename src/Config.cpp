/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibby <obibby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:55:20 by obibby            #+#    #+#             */
/*   Updated: 2023/01/27 12:47:55 by obibby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Config.hpp"

Config::Config(char *path)
{
	std::ifstream config_file;
	config_file.open(path);
	total_servers = 0;
	std::string buff;
	while (std::getline(config_file, buff))
	{
		if (buff.find("server") && buff.find('{'))
		{
			servers.push_back(Server(config_file));
			total_servers++;
		}
	}
}

Config::Config(const Config &src)
{
	*this = src;
}

Config &Config::operator=(const Config &src)
{
	if (this != &src)
	{
		total_servers = src.total_servers;
		servers = src.servers;
	}
	return (*this);
}

Server Config::getServer(int i)
{
	if (i > total_servers || i < 0)
		throw std::out_of_range("Out of bounds.");
	return (servers[i]);
}

int Config::getServTotal()
{
	return (total_servers);
}

Config::~Config()
{
	
}

