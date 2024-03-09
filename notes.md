*< redirects input.*
*> redirects output.*
*| is a pipe, which redirects the output of one command to the input of another command.*


## Creating a Pipe ##

int pipe(int pipe[2]);

    pipefd[0]: the read end
    pipefd[1]: the write end

On sucess, pipe returns 0;
However, on failure, it returns -1 and describes the encountered error in errno, without filling the provided table.
Its important to keep in mind that the pipe has a limit of processes that he can handle, it depends on the OS.
So, if this achieves this limit, the pipe wont work until one another finish.

To read/write soething from a file, we can use the read() write() functions from <unistd.h>

- If a process attempts to read from an empty pipe, read will remain blocked until data is written to it.
- Inversely, if a process tries to write to a full pipe (one that has reached its size limit), write will remain blocked until enough data has been read to allow the write operation to complete

To close a pipe we can use close() from <unistd.h> lib

Combining fork() with pipe() opens up opportunities for communication between processes.

The shell creates a pipe() and 2 child processes
one for the first command and one for the second.


          [Parent Process]
                  /       \
   [Child Process 1]       [Child Process 2]
    (cmd1, input)           (cmd2, output)
         |                       |
         |                       |
    [Pipe Input]           [Pipe Output]

## Fork()
fork()
pid of the child process is always gonna be 0
if pid == 0 is child
else is parent

## Wait()
wait()
A função wait() em C é usada em sistemas Unix e Unix-like para aguardar o término de um processo filho. 
Ela suspende a execução do processo pai até que um dos seus processos filhos termine. 
Quando um processo filho termina, o processo pai pode usar a função wait() para obter o status de saída do processo filho.

Useful
>https://medium.com/@omimouni33/pipex-the-42-project-understanding-pipelines-in-c-71984b3f2103

>https://www.rozmichelle.com/pipes-forks-dups/

>https://csnotes.medium.com/pipex-tutorial-42-project-4469f5dd5901

>https://www.codequoi.com/en/pipe-an-inter-process-communication-method/?source=post_page-----71984b3f2103--------------------------------

>https://github.com/GiovannaCoqueiro/42cursus-pipex/blob/main/srcs/pipex.c

>Playlist
>https://www.youtube.com/watch?v=2hba3etpoJg&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=9

Useful but forbiddent functions
getpid(), getppid(),





`` C
//code to better undertstand process
    int main(int argc, char **argv)
{
	int pipefd[2];
	//fd[0] read
	//fd[1] write
	int pid;
	//int	pid2;

	(void)argc;
	(void)argv;
//   if (argc != 5 || pipe(fd) == -1)
//		ft_printf("argc error");
	if (pipe(pipefd) == -1)
	{
		ft_printf("Pipe Error\n");
		return (1);
	}

	pid = fork(); // Here, I create a parent and a child. They have access to the same FDs.
	//pid2 = fork(); // Here, the same.

	if (pid != 0)
	{
		int	i;
		ft_printf("Processo pai\n");
		for (i = 1; i <= 5; i++)
			ft_printf("%i\n", i);
	}
	else
	{
		int i;
		ft_printf("processo filho\n");
		for (i = 6; i <= 10; i++)
			ft_printf("%i\n", i);
	}
	//The question is that the shell creates a pipe for each command.

	//close() to close the pipe
	return (0);
}