/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibby <obibby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:32:51 by obibby            #+#    #+#             */
/*   Updated: 2023/01/26 15:46:28 by obibby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Server.hpp"

Server::Server(std::ifstream stream)
{
	std::string buff;
	while (std::getline(stream, buff))
	{
		if (buff.find('{'))
		{
			
		}
	}
}
