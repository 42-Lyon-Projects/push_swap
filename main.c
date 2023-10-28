/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:47:51 by jbadaire          #+#    #+#             */
/*   Updated: 2023/10/27 17:47:51 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	int	*array;

	array = NULL;
	if(argc < 2)
		return (0);
	else
	{
		array = handle_inputs_digit(argv);
		if(array == NULL)
			return (0);
		if (check_duplicates(array))
			return (ft_printf("Error\n", 0));

		free(array);
	}
	return 0;
}
