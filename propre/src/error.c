/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 12:31:23 by ele-cren          #+#    #+#             */
/*   Updated: 2017/06/06 13:38:51 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_error(void)
{
	ft_putendl("Error scene !");
	exit(1);
}

void	ft_error_file(void)
{
	perror("Error ");
	exit(1);
}

void	ft_error_sdl(void)
{
	ft_putstr("Error : ");
	ft_putendl(SDL_GetError());
	SDL_Quit();
	exit(1);
}
