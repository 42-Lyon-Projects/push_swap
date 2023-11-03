/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:46:18 by jbadaire          #+#    #+#             */
/*   Updated: 2023/11/03 19:46:44 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../dependencies/libft/libft.h"
# include <values.h>

long		*handle_inputs_digit(char **input);
long		handle_input_digit(char *input);

t_boolean	has_duplicates(long *array);
t_boolean	is_duplicated(long nb, long *array);
t_boolean	contains_only_int(long *array);

void	push_swap(long *array);
#endif
