/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 09:55:46 by volivier          #+#    #+#             */
/*   Updated: 2024/06/20 14:54:26 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "printf/ft_printf.h"
#include <signal.h>



void    signal_handler(int signal)
{
    static char c; //by default static variables are automatically initialized to zero (0) if no explicit initializer is provided
    static int  counter; //by default static variables are automatically initialized to zero (0)
    
    if (signal == SIGUSR1)
        c = c | 1; //LSB is turned into 1 otherwise it is kept 0
        //l'operatore | confronta bit per bit il carattere c e 1 (00000001) restituendo 1 se il LSB di c e' 0 
    counter++;
    if (counter == 8) //8 bits received, now print character
    {
        if (c == '\0')
            write(1, "\n", 1);
        else
            write(1, &c, 1);
        c = 0;
        counter = 0;
    }
    else
        c = c<<1; //bit shifting by one position to make space for next bit represented by next signal
}

int main()
{
    ft_printf("%d\n", getpid());
    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);
    while (1)
        pause();
    return(1);
}