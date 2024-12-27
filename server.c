/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:07:18 by stefan            #+#    #+#             */
/*   Updated: 2024/12/26 17:29:04 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
void decode_and_print(int sig);

void signal_handler(int sig, siginfo_t *info, void *context)
{
    (void)context;
    kill(info->si_pid, SIGUSR1);
    static int c;
    static int i;
    if (sig == 10)
    {
        c |= 1;
    }
    else
    {
        c |= 0;
    }
    i++;
    if (i == 8)
    {
        printf("recived %c\n", c); 
        i = 0;
        c = 0;
    }
    // if (c == '\0')
    //     kill(info->si_pid, SIGUSR2);
    c <<= 1;
}    


int main() {
    struct sigaction sa;

    sa.sa_sigaction = signal_handler;
    sa.sa_flags = SA_SIGINFO;

    sigemptyset(&sa.sa_mask);

    // Handle SIGUSR1 and SIGUSR2
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    printf("PID: %d\n", getpid());
    printf("Waiting for signals...\n");

    while (1) {
        pause();
    }

    return 0;
}
