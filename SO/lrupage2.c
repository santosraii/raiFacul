#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int main()
{
    int frames[MAX], pages[MAX], temp[MAX], last_referenced[MAX];
    int total_pages, m, n, position, k = 0, l, total_frames, page_faults = 0;

    printf("Digite o número total de páginas: ");
    scanf("%d", &total_pages);

    printf("Digite o número total de quadros de página: ");
    scanf("%d", &total_frames);

    if(total_frames > MAX || total_pages > MAX)
    {
        printf("O número total de páginas ou quadros excede o máximo permitido (%d)", MAX);
        return 1;
    }

    // Inicializa last_referenced com -1, ou seja nenhuma página foi referenciada ainda.
    for(m = 0; m < total_pages; m++)
    {
        last_referenced[m] = -1;
    }

    printf("Digite as referências de página: \n");
    for(m = 0; m < total_pages; m++)
    {
        printf("Referência %d: ", m + 1);
        scanf("%d", &pages[m]);
    }

    for(m = 0; m < total_frames; m++)
    {
        frames[m] = -1;
    }

    for(m = 0; m < total_pages; m++)
    {
        int flag = 0;
        for(n = 0; n < total_frames; n++)
        {
            if(frames[n] == pages[m])
            {
                flag = 1;
                // Atualiza o tempo da última referência para a página referenciada.
                last_referenced[pages[m]] = m;
                printf("\t");
                break;
            }
        }
        if(flag == 0)
        {
            if (k < total_frames)
            {
                frames[k++] = pages[m];
            }
            else
            {
                int min_time = last_referenced[frames[0]];
                position = 0;

                for(n = 1; n < total_frames; n++)
                {
                    if (last_referenced[frames[n]] < min_time)
                    {
                        min_time = last_referenced[frames[n]];
                        position = n;
                    }
                }

                // Remove a página referenciada mais tempo atrás.
                frames[position] = pages[m];
                // Atualiza o tempo da última referência para a nova página referenciada.
                last_referenced[pages[m]] = m;

                page_faults++;
            }
            printf("F ");
        }
        for(n = 0; n < total_frames; n++)
        {
            if(frames[n] != -1)
            {
                printf("[%d] ", frames[n]);
            }
        }
        printf("\n");
    }
    printf("O número total de page faults é: %d\n", page_faults);

    return 0;
}