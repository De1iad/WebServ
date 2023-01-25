/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 22:40:01 by libacchu          #+#    #+#             */
/*   Updated: 2023/01/25 09:46:26 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/webserv.hpp"

int main(int ac, char ** av)
{
	(void) ac;
	(void) av;
	
	/* Create socket */
	
	int server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_fd < 1)
		return (1); // fail to create socket

	/* Bind */
	sockaddr_in sockaddr;
	sockaddr.sin_family = AF_INET;
	sockaddr.sin_addr.s_addr = INADDR_ANY;
	sockaddr.sin_port = htons(7676);
	
	int bi;
	int list;
	int addrlen;
	int bytesRead;
	int connection;
	char buffer[10000];
	std::ifstream myfile;
	
	std::cout << "--- HERE ---\n";
	while (1)
	{
		bi = bind(server_fd, (struct sockaddr*)&sockaddr, sizeof(sockaddr));
		if (bi < 0)
			exit (1);

		/* listen */
		list = listen(server_fd, 10);
		if (list < 0)
			exit (1);

		/* accept */
		addrlen = sizeof(sockaddr);
		connection = accept(server_fd, (struct sockaddr*)&sockaddr, (socklen_t*)&addrlen);
		if (connection < 0)
			exit (1);
		
		/* read from connection */
		bytesRead = read(connection, buffer, 10000);
		if (bytesRead < 0)
			exit (1);
		std::cout << buffer << std::endl;
		
		myfile.open ("website/index.html");
		
		std::string response;
		std::string line;
		while ( getline (myfile,line) && line.size() != 0)
		{
			response = response + line;
			response = response + "\n";
			if (myfile.eof() || line.size() == 0)
				break;
		}
		std::cout << response << std::endl;
		send(connection, response.c_str(), response.size(), 0);
		myfile.close();
	}
		close(connection);
		close(server_fd);
	return (0);
}
