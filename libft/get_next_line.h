/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <hiantrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 22:39:36 by hiantrin          #+#    #+#             */
/*   Updated: 2019/12/08 20:07:47 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# define BUFF_SIZE	1000
# define FD_LIMIT	4864

int	get_next_line(const int fd, char **line);

#endif
