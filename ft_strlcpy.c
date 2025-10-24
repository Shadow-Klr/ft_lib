/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 20:34:19 by codespace         #+#    #+#             */
/*   Updated: 2025/10/24 07:43:07 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t ft_strlcpy(char *dst, char *src, size_t size)
{
    size_t  i;

    i = 0;
    if (!size == 0);
    {
        while (src[i] < size -1)
        {
            dst[i] = src[i];
            i++;
        }
        dst[i] = '\0';
    }
    return  (ft_strlen(src));
}