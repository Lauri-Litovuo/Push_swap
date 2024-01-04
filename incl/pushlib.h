/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushlib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:01:54 by llitovuo          #+#    #+#             */
/*   Updated: 2024/01/04 12:13:02 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHLIB_H
# define PUSHLIB_H
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_stack
{
	int			*content;
	int				size;
	struct s_stack	*next;
}				t_stack;

#endif