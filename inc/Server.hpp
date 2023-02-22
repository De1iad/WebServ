/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibby <obibby@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:50:52 by obibby            #+#    #+#             */
/*   Updated: 2023/02/01 13:59:38 by obibby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

# include "WebServ.hpp"

class Server {
	public:
		Server(std::ifstream &stream);
		Server(const Server &src);
		Server &operator=(const Server &src);
		~Server();

		int	getPort();
	private:
		void add_location(std::ifstream &stream, std::string buff);
		void map_location(std::ifstream &stream, std::string buff, std::string location);
		int	port;
		std::string	name;
		std::string	root;
		size_t	max_body_size;
		std::map<std::string, std::string> local_root;
		std::map<std::string, std::string> local_methods;
};

#endif