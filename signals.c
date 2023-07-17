#include "shell.h"

/**
*handle_segfault- handles the segmantation fault
*@signo: signal number
*/
void handle_segfault(int signo __attribute__((unused)))
{
	exit(1);
}
