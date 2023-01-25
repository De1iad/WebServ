/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibby <obibby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:29:15 by obibby            #+#    #+#             */
/*   Updated: 2023/01/25 16:56:33 by obibby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESPONSE_HPP
# define RESPONSE_HPP

# include "WebServ.hpp"

class Response
{
	public:
		Response(char *buff);
		char *getPath() const;
		char *getType() const;
	private:
		char *path;
		char *type;
};

#endif