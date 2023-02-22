/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibby <obibby@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 22:40:01 by libacchu          #+#    #+#             */
/*   Updated: 2023/02/01 10:31:58 by obibby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WebServ.hpp"

int main(int ac, char ** av)
{
	(void) ac;
	
	/* Create socket */

	
	try
	{
		Config config(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	int server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_fd < 1)
		return (1); // fail to create socket

	/* Bind */
	sockaddr_in sockaddr;
	sockaddr.sin_family = AF_INET;
	sockaddr.sin_addr.s_addr = INADDR_ANY;
	sockaddr.sin_port = htons(7676);
	//int list;
	int addrlen;
	int bytesRead;
	int connection = 0;
	if (bind(server_fd, (struct sockaddr*)&sockaddr, sizeof(sockaddr)))
	{
		perror("failed to bind");
	}
	char buffer[10000];
	struct pollfd poll_fd;
	poll_fd.events = POLLIN;
	poll_fd.fd = server_fd;
	char *str = strdup("wordpress/readme.html");
	std::ifstream myfile;
	while (1)
	{
		listen(server_fd, 10);
		addrlen = sizeof(sockaddr);
		connection = accept(server_fd, (struct sockaddr*)&sockaddr, (socklen_t*)&addrlen);
		if (connection < 0)
			exit (1);
		/* listen */
		// list = listen(server_fd, 10);
		// if (list < 0)
		// 	exit (1);

		/* accept */
		/* read from connection */
		myfile.open (str);
		std::string response; 
		std::string line;

		while ( getline (myfile,line))
		{
			response = response + line;
			response = response + '\n';
		}
		if (!strcmp(&str[strlen(str) - 4], "html"))
		{
			response = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n" + response;
			send(connection, response.c_str(), response.length(), 0);
		}
		else if (!strcmp(&str[strlen(str) - 3], "png"))
		{
			response = "HTTP/1.1 200 OK\nContent-Type: image/png\n\n" + response;
			send(connection, response.c_str(), response.length(), 0);
			send(connection, &myfile, sizeof(myfile), 0);
		}
		myfile.close();
		bytesRead = read(connection, buffer, 10000);
		if (bytesRead < 0)
			exit (1);
		//Response(buffer);
		std::cout << buffer << std::endl;
		// std::cout << buffer[0] << buffer[1] << buffer[2] << std::endl;
		int i = 4;
		while (buffer[i] && strncmp(&buffer[i], " HTTP", 5))
			i++;
		str = strndup(&buffer[4], i - 4);
		char *tmp_str = strdup("wordpress");
		str = strcat(tmp_str, str);
		std::cout << str << std::endl;
		poll(&poll_fd, 1, -1);
		close(connection);
	}
	close(server_fd);
	return (0);
}
