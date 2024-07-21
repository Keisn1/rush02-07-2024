#include "rush02.h"


void parse_buffer(char* buffer,  t_SpellNode** head)
{
    char *line_start = buffer;
    char *line_end = NULL;
    int index = 0;
    while((line_end = ft_strchr(line_start, '\n')) != NULL )
    {
        *line_end = '\0';

        char* separator = ft_strchr(line_start, ':');

        if (separator != NULL)
        {
            *separator = '\0';
            separator++;

            *head = create_node(ft_strdup(line_start), ft_strdup(separator));
            head = &(*head)->next;
            index++;
        }
        line_start = line_end + 1;
    }
}

int open_file(int *fd, char* filename)
{
	*fd = open(filename, O_RDONLY);
	if (*fd == -1)
	{
        // TODO: handle error
		return (-1);
	}

    return 0;
}


int close_file(int *fd)
{
    if(close(*fd) == -1)
    {
        // TODO: handle error
    }

    return 0;
}

int read_file(int *fd, char *buffer, int buffer_size)
{
    int bytes_read = read(*fd, buffer, buffer_size - 1);
    buffer[bytes_read] = '\0';
    // TODO: handle error
    return 0;
}
