// Student may implement another function as need
int count(const char* arr)
{
    int i = 0;
    while (arr[i] != '\0')
    {
        i++;
    }
    return i;
}

void process(const char* str, char* outstr) {
    // TODO
    int length = count(str);
    for (int i = 0; i < length; i++)
    {
        outstr[i] = str[length - 1 - i];
    }
    outstr[length] = '\0';
}
