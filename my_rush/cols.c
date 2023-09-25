int cols(char *str)
{
    char *col1;
    char *col2;
    char *col3;
    char *col4;

    col1 = malloc(3);
    col2 = malloc(3);
    col3 = malloc(3);
    col4 = malloc(3);
    col1[0] = str[0];
    col1[1] = str[1];
    col1[2] = '\0';
    col2[0] = str[2];
    col2[1] = str[3];
    col2[2] = '\0';
    col3[0] = str[4];
    col3[1] = str[5];
    col3[2] = '\0';
    col4[0] = str[6];
    col4[1] = str[7];
    col4[2] = '\0';
}