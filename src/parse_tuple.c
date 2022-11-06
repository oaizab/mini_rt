/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tuple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 09:07:01 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/06 09:12:59 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static float	parse_float(char const *str)
{
	if (check_float(str) == false)
	{
		ft_fprintf(STDERR_FILENO, "Parsing error: invalid coordinates\n");
		exit(EXIT_FAILURE);
	}
	return (ft_atof(str));
}

t_tuple	parse_tuple(char const *line)
{
	t_tuple	res;
	char	**split;

	split = ft_split(line, ',');
	if (split == NULL)
		(perror("parse_tuple"), exit(EXIT_FAILURE));
	if (args_len(split) != 3)
		(ft_fprintf(2, "Parsing error: invalid camera coordinates\n"), exit(1));
	res.x = parse_float(split[0]);
	res.y = parse_float(split[1]);
	res.z = parse_float(split[2]);
	free_args(split);
	return (res);
}