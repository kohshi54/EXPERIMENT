#include <unistd.h>
#include <fcntl.h>
#define BUFFER_SIZE 3
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	char	buf[BUFFER_SIZE];
	int		fd;
	ssize_t ret;

	fd = open("null_file", O_RDONLY);		// "\0" > null_file
	if (fd == -1)
		printf("ERROR OPENING FILE");
	ret = read(fd, buf, BUFFER_SIZE);
	printf("ret: %zu\n", ret);				// ret; 1
	if (ret == 0)
		printf("NOTHING TO READ");
	else if (ret == -1)
		printf("ERROR READING FILE");
	buf[ret] = '\0';
	printf("ptr: %p, buf: %s", buf, buf);	// "ptr: 0x16daeb5a9, buf: "
	return (0);
}

// ヌル文字１バイトだけ含むファイルを作るコマンド
// echo -n -e "\0" > null_file

// このファイルをread()した場合、返り値は１となる。
// read()の返り値で確保するメモリバイト数を決定している場合は、メモリリークする可能性がある。