#include "shell.h"

/**
*handle_segmfault- handles the segmantation fault
*@signo: signal number
*/
void handle_segmfault(int signo __attribute__((unused)))
{
	exit(1);
}
