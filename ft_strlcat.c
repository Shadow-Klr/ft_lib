/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 07:44:37 by codespace         #+#    #+#             */
/*   Updated: 2025/10/25 21:42:39 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t  i;
    size_t  j;

    i = 0;
    j = 0;
    if (size > 0)
    {
        while (dst[i] != '\0')
            i++;
        while (src[j] != '\0' && (i + j) < (size - 1))
        {
            dst[i + j] = src[j];
            j++;
        }
        dst[i + j] = '\0';
    }
    if (size <= i)
        return size + ft_strlen(src);
    return (i + ft_strlen(src));
}