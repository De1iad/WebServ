/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   webserv.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibby <obibby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 22:41:18 by libacchu          #+#    #+#             */
/*   Updated: 2023/01/26 14:45:48 by obibby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_HPP
# define WEBSERV_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <map>

# include <sys/socket.h> // For socket function
# include <poll.h>
# include <netinet/in.h> //For sockaddr_in
# include <unistd.h> //For read
#include <fcntl.h> // open

class Server {
	public:
		Server()
};

# define PORT 4242

#endif
