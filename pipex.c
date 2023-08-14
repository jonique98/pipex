#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

// int main() {
//     int pid;
//     int pipe_fd[2]; // 파이프 파일 디스크립터 배열

//     char arr[20] = "Hello World";

//     // 파이프 생성
//     if (pipe(pipe_fd) == -1) {
//         perror("pipe error");
//         return 1;
//     }

//     pid = fork();
//     if (pid == 0) {
//         close(pipe_fd[0]); // 자식 프로세스에서는 읽기용 파이프 닫음
//         printf("Child: %s\n", arr);
//         arr[0] = 'J';
//         write(pipe_fd[1], arr, strlen(arr) + 1); // 파이프를 통해 데이터 전송
//         close(pipe_fd[1]); // 데이터 전송 후 쓰기용 파이프 닫음
//     } else {
//         close(pipe_fd[1]); // 부모 프로세스에서는 쓰기용 파이프 닫음
//         wait(NULL); // 자식 프로세스 종료 대기

//         read(pipe_fd[0], arr, sizeof(arr)); // 파이프를 통해 데이터 수신
//         printf("Parent: %s\n", arr);

//         close(pipe_fd[0]); // 데이터 수신 후 읽기용 파이프 닫음
//     }

//     return 0;
// }
#include <string.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
    int	i;

    i = 0;
    while (str != 0 && str[i])
        i++;
    return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*arr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	arr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!arr)
	{
		free(s1);
		return (0);
	}
	while (s1 != 0 && s1[i])
	{
		arr[i] = s1[i];
		i++;
	}
	while (s2 != 0 && s2[j])
		arr[i++] = s2[j++];
	arr[i] = '\0';
	// free(s1);
	return (arr);
}

int main(int ac, char**av) {
    char *const env[] = {NULL};
    ac = 3;

    av += 1;
    av[0] = ft_strjoin("/bin/", av[0]);

    execve(av[0], av, env);

    perror("execve"); // execve 함수가 실패한 경우 에러 메시지 출력

    return 0;
}


 
// int main(){
    
//     fork();
//     printf("%d\n", getpid());

// }