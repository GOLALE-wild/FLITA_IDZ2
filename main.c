#include <stdio.h>

int main()
{
    char line[20];
    char matrix[10][10];
    char a = '*', b = '*';
    int stroki = 0, stolbi = 0;
    FILE* in = fopen("in.txt", "r");
    FILE* out = fopen("out.txt", "w");
    fputs("graph G {", out);
    fgets(line, 20, in);
    while (fgets(line, 20, in)) {
        stolbi = 0;
        for (int i = 0; line[i]; i++) {
            if (line[i] != ' ') {
                matrix[stroki][stolbi] = line[i];
                stolbi++;
            }
        }
        stroki++;
    }
    for (int i = 1; i < stolbi; i++) {
        for (int j = 0; j < stroki; j++) {
            if (matrix[j][i] == '1') {
                b = a;
                a = matrix[j][0];
            }
        }
        fputs("\n", out);
        fputs("\t", out);
        fprintf(out, "%c", b);
        fputs("--", out);
        fprintf(out, "%c", a);
        fputs(";", out);
    }
    fputs("\n", out);
    fputs("}", out);
    fclose(out);
    fclose(in);
    return 0;
}

