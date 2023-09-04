#include <pthread.h>
#include <stdio.h>


typedef struct resources{
	char *hi;
}res;


void	*pthread_start(void *message)
{
	printf("%s\n", (char *)message);
	return (message);
}

int main(){
	pthread_t thing1, thing2;

	char *message1 = "message1";
	char *message2 = "message2";
	pthread_create(&thing1, NULL, pthread_start, (void *)message1);
	pthread_create(&thing2, NULL, pthread_start, (void *)message2);

	pthread_join(thing1, NULL);
	pthread_join(thing2, NULL);
}
