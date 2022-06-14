#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "inventory.h"
void terminate(char *ch)
{
    fprintf(stderr, "file %s cannot be open or written\n", ch);
    exit(EXIT_FAILURE);
}
bool merge_file(char *file1, char *file2,char *output_file);
int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        fprintf(stderr, "MERGE file1 file2 outputfile is its usage\n");
        exit(1);
    }
    if (merge_file(argv[1], argv[2], argv[3]))
    {
        printf("\nThe files are sucessfully merged\n");
    }
    else
    {
        fprintf(stderr, "Files cann't be merge because of error\n");
        exit(1);
    }

    return 0;
}

bool merge_file(char *file1, char *file2, char *output_file)
{
    FILE *input1, *input2, *output;
    struct part part1, part2;
    input1 = fopen(file1, "rb");
    input2 = fopen(file2, "rb");
    output = fopen(output_file, "wb");
    //if(input1 && input2 && output){
    if (input1 == NULL)
        terminate(file1);
    if (input2 == NULL)
        terminate(file2);
    if (output == NULL)
        terminate(output_file);
    int p, q;
    p = fread(&part1, sizeof(struct part), 1, input1);
    q = fread(&part2, sizeof(struct part), 1, input2);
    while (p == 1 && q == 1)
    {
        if (part1.number < part2.number)
        {
            fwrite(&part1.number, sizeof(struct part), 1, output);
            p = fread(&part1, sizeof(struct part), 1, input1);
        }
        else if (part1.number > part2.number)
        {
            fwrite(&part2.number, sizeof(struct part), 1, output);
            p = fread(&part2, sizeof(struct part), 1, input1);
        }

        else
        {
            if (strcmp(part1.name, part2.name))
            {
                fprintf(stderr, "PART NUMBER CONSIST OF DIFFERENT NAMES\n");
                return false;
            }
            else
            {
                part1.on_hand += part2.on_hand;
                fwrite(&part1, sizeof(struct part), 1, output);
                p = fread(&part1, sizeof(struct part), 1, input1);
                q = fread(&part2, sizeof(struct part), 1, input2);
            }
        }
    }
        while (p == 1)
        {
            fwrite(&part1.number, sizeof(struct part), 1, output);
            p = fread(&part1, sizeof(struct part), 1, input1);
        }

        while (q == 1)
        {
            fwrite(&part2.number, sizeof(struct part), 1, output);
            q = fread(&part2, sizeof(struct part), 1, input2);
        }
        fclose(input1);
        fclose(input2);
        fclose(output);
        return true;
}
