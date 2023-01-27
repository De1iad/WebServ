/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibby <obibby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:48:25 by obibby            #+#    #+#             */
/*   Updated: 2023/01/27 12:48:57 by obibby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_HPP
# define CONFIG_HPP

# include "Server.hpp"
# include "WebServ.hpp"

class Server;

class Config {
	public:
		Config(char *path);
		Config(const Config &src);
		Config &operator=(const Config &src);
		Server getServer(int i);
		int getServTotal();
		~Config();
	private:
		int	total_servers;
		std::vector<Server>	servers;
};

#endif