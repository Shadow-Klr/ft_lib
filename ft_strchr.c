/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 01:37:32 by codespace         #+#    #+#             */
/*   Updated: 2025/11/10 01:45:38 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
    int i;

    if(!str)
        return (NULL);
    i = 0;
    while(str[i])
    {
        if(str[i] == c)
            return ((char *)&str[i]);
        i++;
    }
    if(str[i] == c)
            return ((char *)&str[i]);
    return (NULL);
}