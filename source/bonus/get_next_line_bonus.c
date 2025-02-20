/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelferreira <raphaelferreira@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 00:53:29 by raphaelferr       #+#    #+#             */
/*   Updated: 2025/02/20 12:55:25 by raphaelferr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/get_next_line_bonus.h"

void	remove_fd_node(t_gnl **head, int fd)
{
	t_gnl	*current;
	t_gnl	*previous;

	if (!head || !*head)
		return ;
	current = *head;
	previous = NULL;
	while (current)
	{
		if (current->fd == fd)
		{
			if (previous == NULL)
				*head = current->next;
			else
				previous->next = current->next;
			if (current->remainder)
				free(current->remainder);
			free(current);
			return ;
		}
		previous = current;
		current = current->next;
	}
}

char	*read_and_extract_line(t_gnl *node, char *buffer)
{
	ssize_t	bytes_read;
	char	*temp;

	while (1)
	{
		if (ft_strchr(node->remainder, '\n'))
			return (extract_line(node));
		bytes_read = read(node->fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			if (bytes_read == 0 && node->remainder && node->remainder[0])
				return ((temp = node->remainder), node->remainder = NULL, temp);
			else
				return (NULL);
		}
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(node->remainder, buffer);
		if (!temp)
			return (NULL);
		free(node->remainder);
		node->remainder = temp;
	}
}

char	*extract_line(t_gnl *node)
{
	char	*newline_pos;
	char	*line;
	char	*temp_remainder;
	size_t	line_len;

	newline_pos = ft_strchr(node->remainder, '\n');
	if (!newline_pos)
		return (NULL);
	line_len = newline_pos - node->remainder + 1;
	line = ft_substr(node->remainder, 0, line_len);
	if (!line)
		return (NULL);
	if (ft_strlen(node->remainder + line_len) > 0)
	{
		temp_remainder = ft_substr(node->remainder, line_len, ft_strlen(
					node->remainder + line_len));
		free(node->remainder);
		node->remainder = temp_remainder;
	}
	else
	{
		free(node->remainder);
		node->remainder = NULL;
	}
	return (line);
}

t_gnl	*get_fd_node(t_gnl **head, int fd)
{
	t_gnl	*current;
	t_gnl	*new_node;

	current = *head;
	while (current)
	{
		if (current->fd == fd)
			return (current);
		current = current->next;
	}
	new_node = malloc(sizeof(t_gnl));
	if (!new_node)
		return (NULL);
	new_node->fd = fd;
	new_node->remainder = NULL;
	new_node->next = *head;
	*head = new_node;
	return (new_node);
}

char	*get_next_line(int fd)
{
	char			*buffer;
	static t_gnl	*head = NULL;
	t_gnl			*node;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	node = get_fd_node(&head, fd);
	if (!node)
	{
		free(buffer);
		return (NULL);
	}
	line = read_and_extract_line(node, buffer);
	free(buffer);
	if (!line)
	{
		remove_fd_node(&head, fd);
		return (NULL);
	}
	return (line);
}
