/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibby <obibby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:48:25 by obibby            #+#    #+#             */
/*   Updated: 2023/01/26 14:58:09 by obibby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_HPP
# define CONFIG_HPP

# include "Server.hpp" 

class Config {
	public:
		Config(int fd);
		Server getServer();
		int getServNo();
		~Config();
	private:
		unsigned int	serv_no;
		Server	*servers;
};

#endif