/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibby <obibby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:50:52 by obibby            #+#    #+#             */
/*   Updated: 2023/01/27 12:47:50 by obibby           ###   ########.fr       */
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
		//~Server();

		int	getPort();
	private:
		int	port;
		std::string	name;
		std::string	root;
		size_t	max_body_size;
		std::string	*location;
		std::map<std::string, std::string> local_root;
		std::map<std::string, std::string> local_methods;
};

#endif