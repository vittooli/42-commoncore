/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:25:43 by volivier          #+#    #+#             */
/*   Updated: 2024/06/20 15:33:12 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "printf/ft_printf.h"
#include <signal.h>



void    signal_handler(int signal, siginfo_t *info, void *context)
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
    if (signal == SIGUSR1)
        kill(info->si_pid, SIGUSR1);
    else if (signal == SIGUSR2)
        kill(info->si_pid, SIGUSR2);
}

int main()
{
    struct sigaction    sa;
    sa.sa_sigaction = &signal_handler;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    ft_printf("%d\n", getpid());
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while (1)
        pause();
    return(1);
}