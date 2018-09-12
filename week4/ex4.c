#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
	char cmd[99];
	while(1) 
    {
		printf(">");
		gets(cmd, sizeof(cmd), stdin);
		char *address = strchr(cmd, "&"); //detects '&' sign to run command in 'bg'
		if (address) 
        {
				*address = '\0';
				int pid = fork();
				if (!pid) system(cmd);
		} else 
        {
			system(cmd);
		}
	}

	return 0;
}
