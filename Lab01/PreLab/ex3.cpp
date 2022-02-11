int Power(int x, int y)
{
    int product = 1;
    for (int i = 1; i <= y; i++)
    {
        product *= x;
    }
    return product;
}

int count(const char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}


int calc(const char* str) {
    // TODO
    int length = count(str);
    int decimal = 0;
    for (int i = 0; i < length; i++)
    {
        int k = (int)str[i] - 48;
        decimal += k * Power(2, length - i - 1);
    }
    return decimal;
}
