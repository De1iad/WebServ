/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibby <obibby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:50:52 by obibby            #+#    #+#             */
/*   Updated: 2023/01/26 15:41:47 by obibby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

# include "WebServ.hpp"

class Server {
	public:
		Server(std::ifstream stream);
		~Server();

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