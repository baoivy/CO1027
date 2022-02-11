// Student may implement another function as need
void Delete(char* str,int index)
{
	if (index == strlen(str) - 1)
	{
		str[index] = '\0';
	}
	for (int i = index; i < strlen(str); i++)
	{
		str[i] = str[i + 1];
	}
	str[strlen(str)] = '\0';
}

void process(char str[], char outstr[]) {
    // TODO
    for (int i = 0; i < strlen(str); i++)
	{
		outstr[i] = str[i];
	}
	outstr[strlen(str)] = '\0';
	for (int i = 0; i < strlen(outstr); i++)
	{
		if (outstr[i] == ' ' && outstr[i + 1] == ' ')
		{
			Delete(outstr, i);
			i--;
		}
	}

	if (outstr[0] == ' ')
		Delete(outstr, 0);
	if (outstr[strlen(outstr) - 1] == ' ')
		Delete(outstr, strlen(outstr) - 1);
}
