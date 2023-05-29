#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define DIM_MAT 57

void print_matrice(bool matrice[DIM_MAT][DIM_MAT])
{
    int i=0, j=0;

    for (i=0; i<DIM_MAT; i++)
    {
        for (j=0; j<DIM_MAT; j++)
        {
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
}

void apply_mask(bool* row, int mask_number)
{
    int i, j;

    switch (mask_number)
    {
    case 0b0111:
        for (i=0; i<DIM_MAT; i++)
        {
            for (j=0; j<DIM_MAT; j++)
            {
                if (j%3 == 0)
                    *(row+i*DIM_MAT + j) = true;
                else
                    *(row+i*DIM_MAT + j) = false;                   
            }
        }
        break;

    case 0b0110:
        for (i=0; i<DIM_MAT; i++)
        {
            for (j=0; j<DIM_MAT; j++)
            {
                if ((i+j)%3 == 0)
                    *(row+i*DIM_MAT + j) = true;
                else
                    *(row+i*DIM_MAT + j) = false;                   
            }
        }
        break;
    
    case 0b0101:
        for (i=0; i<DIM_MAT; i++)
        {
            for (j=0; j<DIM_MAT; j++)
            {
                if ((i+j)%2 == 0)
                    *(row+i*DIM_MAT + j) = true;
                else
                    *(row+i*DIM_MAT + j) = false;                   
            }
        }
        break;

    case 0b0100:
        for (i=0; i<DIM_MAT; i++)
        {
            for (j=0; j<DIM_MAT; j++)
            {
                if (i%2 == 0)
                    *(row+i*DIM_MAT + j) = true;
                else
                    *(row+i*DIM_MAT + j) = false;                   
            }
        }
        break;

    case 0b0011:
        for (i=0; i<DIM_MAT; i++)
        {
            for (j=0; j<DIM_MAT; j++)
            {
                if (((i*j)%3 + i*j)%2 == 0)
                    *(row+i*DIM_MAT + j) = true;
                else
                    *(row+i*DIM_MAT + j) = false;                   
            }
        }
        break;

    case 0b0010:
        for (i=0; i<DIM_MAT; i++)
        {
            for (j=0; j<DIM_MAT; j++)
            {
                if (((i*j)%3 + i+j)%2 == 0)
                    *(row+i*DIM_MAT + j) = true;
                else
                    *(row+i*DIM_MAT + j) = false;                   
            }
        }
        break;

    case 0b0001:
        for (i=0; i<DIM_MAT; i++)
        {
            for (j=0; j<DIM_MAT; j++)
            {
                if ((i/2 + j/3)%2 == 0)
                    *(row+i*DIM_MAT + j) = true;
                else
                    *(row+i*DIM_MAT + j) = false;                   
            }
        }
        break;

    case 0b0000:
        for (i=0; i<DIM_MAT; i++)
        {
            for (j=0; j<DIM_MAT; j++)
            {
                if ((i*j)%2 + (i*j)%3 == 0)
                    *(row+i*DIM_MAT + j) = true;
                else
                    *(row+i*DIM_MAT + j) = false;                   
            }
        }
        break;

    default:
        printf("Invalide mask value");
        break;
    }
}

//PP

int main()
{
    bool matrice[DIM_MAT][DIM_MAT] = {{false}};
    bool* row = &matrice[0][0];
    bool test_value_mask = false;
    int mask_number;


    //PP

    //Selecting the mask
    while (test_value_mask == false)
    {
        printf("\nChoose a mask : ");
        scanf("%d", &mask_number);
        if (mask_number == 0b0111 || mask_number == 0b0110 || mask_number == 0b0101 || mask_number == 0b0100 || mask_number == 0b0011 || mask_number == 0b0010 || mask_number == 0b0001 || mask_number == 0b0000)
            test_value_mask = true;
    }
    
    apply_mask(row, mask_number);
    print_matrice(matrice);

    return 0;
}

