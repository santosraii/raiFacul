#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int main()
{
    int frames[MAX], pages[MAX], temp[MAX];
    int total_pages, m, n, position, k, l, total_frames, page_faults = 0;

    printf("Digite o número total de páginas: ");
    scanf("%d", &total_pages);

    printf("Digite o número total de quadros de página: ");
    scanf("%d", &total_frames);

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
                for(n = 0; n < total_frames; n++)
                {
                    temp[n] = -1;
                    for(l = m + 1; l < total_pages; l++)
                    {
                        if(frames[n] == pages[l])
                        {
                            temp[n] = l;
                            break;
                        }
                    }
                }
                int max = temp[0];
                position = 0;
                if(max == -1)
                {
                    max = 200;
                }
                for(n = 0; n < total_frames; n++)
                {
                    if(temp[n] == -1)
                    {
                        temp[n] = 200;
                    }
                    if(temp[n] > max)
                    {
                        max = temp[n];
                        position = n;
                    }
                }
                frames[position] = pages[m];
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
