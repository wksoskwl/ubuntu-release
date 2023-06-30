#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_STR 1024

typedef char* String;

struct die{
	char name[MAX_STR];
	char argv[3][MAX_STR];
	String reason;
	int dcnt;
	char time[MAX_STR];
	int noOfArgv;
}p[10];

String rtrim(const char * s);
String ltrim(const char * s);
String trim(const char * s);
void readFileList();
void handler(int signum);
int flag = 0;
int signum = 0;
int pidn = 0;
int statusn = 0;
int ranTime[10];
void delay(clock_t n);

int main() {
	time_t timer;
    struct tm* t;
    timer = time(NULL); // 1970년 1월 1일 0시 0분 0초부터 시작하여 현재까지의 초
    t = localtime(&timer); // 포맷팅을 위해 구조체에 넣기
	readFileList();
	struct sigaction act;
	sigset_t set;

	sigfillset(&(act.sa_mask));
	act.sa_handler = handler;

	sigaction(SIGCHLD, &act, NULL);

	int NUM = 10;
	pid_t pid[NUM];
	int status[NUM];
	int i = 0;
	srand((unsigned int)time(NULL));
	FILE* fp = fopen("log/restart.txt","w");
	for (i = 0; i < NUM; i++) {
		pid[i] = -1;
        ranTime[i] = rand() %5 +3;
		//printf("%d:%d\n",i,ranTime[i]);
		p[i].reason = "init";
		p[i].dcnt++;
		sprintf(p[i].time,"%d/%d/%d/%d:%d:%d", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
		char buff[3080] = {};
		fputs(buff,fp);
	}
	fclose(fp);
	pid[0] = fork();
	for (int n = 1; n < NUM; n++) {
		if (pid[n - 1] > 0) {
			pid[n] = fork();
			delay(10000);
			//sleep(1);
		}
	}
	int cnt = 0;
	for (i = 0; i < NUM; i++) {
		if (pid[i] > 0)  cnt++;
		else break;
	}
	
	if (cnt == NUM) {
		while(1){
			if (flag == 1) {
				time_t timer;
				struct tm* t;
				timer = time(NULL); // 1970년 1월 1일 0시 0분 0초부터 시작하여 현재까지의 초
				t = localtime(&timer); // 포맷팅을 위해 구조체에 넣기
				flag = 0;
				if(WIFSIGNALED(statusn)){
					for(i = 0;i<10;i++){
						if(waitpid(pid[i],&status[i],WNOHANG) == -1)
							break;
						//	printf("%d ",waitpid(pid[i],&status[i],WNOHANG));
					}
					pid[i] = fork();

					//printf("\n");
				}
				p[i].dcnt++;
				p[i].reason = strsignal(WTERMSIG(statusn));
				sprintf(p[i].time,"%d/%d/%d/%d:%d:%d", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
				//FILE* fp = fopen("log/restart.txt","aw");
				//char buff[3080];
				//sprintf(buff,"%s %d %s %s\n",p[i].name,p[i].dcnt,p[i].reason,p[i].time);
				//fputs(buff,fp);
				//fclose(fp);
				if(pid[i] == 0) break;
			}
		}
	}
	fp = fopen("log/restart.txt","aw");
	char buff[3080];
	sprintf(buff,"%5s %5d %10s %15s\n",p[i].name,p[i].dcnt,p[i].reason,p[i].time);
	fputs(buff,fp);
	fclose(fp);
	printf("%5s cnt : %5d reason : %10s time : %15s\n",p[i].name,p[i].dcnt,p[i].reason,p[i].time);
	int ranNum = 0;
	srand((unsigned int)time(NULL));
	while(1){
		srand((unsigned int)time(NULL));
		sleep(ranTime[i]);
		ranNum = rand() % ranTime[i];
		if(ranNum == 0)
				kill(getpid(),SIGKILL);
		if(ranNum == 1)
				kill(getpid(),SIGINT);
		if(ranNum == 2)
				kill(getpid(),SIGTERM);	
	}
}

void handler(int sig) {
	int pid;
	int status;
	while ((pidn = waitpid(-1, &status, WNOHANG)) > 0) {
		flag = 1;
		signum = sig;
		statusn = status;
		//      printf("SIGCHLD, %d %d\n", pid, signum);
		//      if(WIFEXITED(status)){
		//          printf("exit %d\n", WEXITSTATUS(status));
		//      }
		//      if(WIFSIGNALED(status)){
		//          printf("signal %d\n", WTERMSIG(status));
		//      }
	}
}

void readFileList() {
    FILE *fp;
    fp = fopen("SWBlockInfo.txt", "r");
	char str[MAX_STR];
    int swno = 0;
    while(fgets(str, MAX_STR, fp)) {
		//printf("h\n");
        int n = 0;
        char result[MAX_STR];
		strcpy(result,strtok(str,";"));
        strcpy(p[swno].name, result);
        strcpy(p[swno].name, trim(p[swno].name));
        while(result !=NULL && n<3) {
            char* result;
            result=strtok(NULL,";");
            if(result != NULL && *result != 10) {
                strcpy(p[swno].argv[n], result);
                strcpy(p[swno].argv[n], trim(p[swno].argv[n]));
			}
            else break;
			n++;
        }
        p[swno].noOfArgv = n;
        //printf( "%d\n", n);
        swno++;
		//printf("haha\n");
    }
    fclose(fp);
}

String rtrim(const char * s) {
    while (isspace( * s) || !isprint( * s)) 
        ++s;
    return strdup(s);
}

String ltrim(const char * s) {
    String r = strdup(s);
    if (r != NULL) {
        String fr = r + strlen(s) - 1;
        while ((isspace( * fr) || !isprint( * fr) || * fr == 0) && fr >= r) 
            --fr;
        
        *++fr = 0;
    }
    return r;
}

String trim(const char * s) {
    String r = rtrim(s);
    String f = ltrim(r);
    free(r);
    return f;
}

void delay(clock_t n)

{

  clock_t start = clock();

  while(clock() - start < n);

}
