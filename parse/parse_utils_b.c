/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakhalil <nakhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 10:13:44 by nakhalil          #+#    #+#             */
/*   Updated: 2025/11/01 12:46:43 by nakhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	validate_map_line_chars(const char *s)
{
	int		i;
	char	c;

	i = 0;
	while (s[i])
	{
		c = s[i];
		if (!(c == '0' || c == '1' || c == ' '
				|| c == 'N' || c == 'S' || c == 'E' || c == 'W'))
			return (0);
		i++;
	}
	return (1);
}

int	parse_id_path(char **dst, char *line, const char *id)
{
	int		i;
	char	*path;

	if (ft_strncmp(line, id, (int)ft_strlen(id)) != 0)
		return (0);
	i = (int)ft_strlen(id);
	while (line[i] && is_space((unsigned char)line[i]))
		i++;
	path = ft_strdup(line + i);
	if (!path || !*path)
	{
		free(path);
		return (-1);
	}
	*dst = path;
	return (1);
}

int	lc_validate_line_or_err(t_game *g, char *ln, t_mapstate *st)
{
	(void)g;
	if (!validate_map_line_chars(ln))
		return (-1);
	if (st->ended)
		return (-2);
	if (is_blank_line_strict(ln))
	{
		if (st->in_map && st->y > 0)
			st->ended = 1;
		return (2);
	}
	st->in_map = 1;
	return (1);
}

int	lc_require_all_ids(t_parsef *f)
{
	if (!(f->no && f->so && f->we && f->ea && f->f && f->c))
	{
		write(2, "Error\nmissing identifier(s)\n", 28);
		return (0);
	}
	return (1);
}
