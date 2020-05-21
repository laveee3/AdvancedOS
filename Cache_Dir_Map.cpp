/* Advanced Operating System -  Assignment 4 - Lavanya Elango */
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <new>
using namespace std;

int main( )
{
    int addr;
    int *tag;
    int *valid;
    int i, j, tag_current, index;
    int accesses = 0;
    FILE *fp;

    int hits = 0;
    int miss = 0;
    int cm = 0;
    accesses = 0;
    int n = 24;
    int M = 16;
    int L = 0;
    cout << "Enter value for L: ";
    cin >> L;
    cout << "l is "<< log2(L)<< "\n" << endl;
    tag = new (nothrow) int[L];
    valid = new (nothrow) int[L];
    if (tag == NULL | valid == NULL)
        cout << "Error: memory could not be allocated";
    else
    {
        for(i = 0; i<L ; i++)
        {
          tag[i] = 0;
          valid[i] = 0;
        }
        fp = fopen("trace5.txt", "r");
        while (fscanf(fp, "%x", &addr) > 0)
        {
            /* simulate a direct-mapped cache with 8 words */
            accesses += 1;
            printf("%d: 0x%06x ", accesses, addr);
            index = (addr >> (int)log2(M)) & (L-1);
            tag_current = addr >>((int)log2(M)+(int)log2(L));

            cout << "index is:" << index << "  tag_current is:" <<std::hex <<tag_current << "\t";
            if ( valid[index] == 0 )
            {
                cm = cm + 1;
                printf("CM%d ", index);
                valid[index] = 1;
                tag[index] = tag_current;
            }else if ((tag[index] == tag_current)& valid[index] == 1 )
            {
                hits += 1;
                printf("Hit %d ", index);
            } else
            {
                /* allocate entry */
                printf("Miss %d ", index);
                miss = miss + 1;
                tag[index] = tag_current;
            }
            //for (i = 0; i < 16; i++)
            //   printf("0x%0hx ", tag[i]);
            printf("\n\n\n");
        }
        printf("\n\n\nHits = %d, Misses = %d, CMs = %d, Accesses = %d, Hit ratio = %f, CM ratio = %f\n", hits, miss, cm, accesses, ((float)hits)/accesses, (float)cm/accesses);
        fclose(fp);
        delete[] tag;
        delete[] valid;
    }
}
