#include <log.h>

int log_level=log_impossible;

int enable_log_position=1;
int enable_log_color=1;
char log_text[][20]={"IMPOSSIBLE","FATAL","ERROR","WARN","INFO","DEBUG","TRACE"};
char log_color[][20]={RED,RED,RED,YEL,GRN,BLU,""};
void log0(const char * file,const char * function,int line,int level,const char* str, ...) {

	if(level>log_level) return ;
	if(level>log_trace||level<0) return ;


	time_t timer;
	char buffer[100];
	struct tm* tm_info;

	time(&timer);
	tm_info = localtime(&timer);

	if(enable_log_color)
	printf(log_color[level]);

	strftime(buffer, 100, "%Y-%m-%d %H:%M:%S", tm_info);
	printf("[%s][%s]",buffer,log_text[level],file,line);

	if(enable_log_position)printf("[%s,func:%s,line:%d]",file,function,line);

	va_list vlist;
	va_start(vlist, str);
	vfprintf(stdout, str, vlist);
	va_end(vlist);
	if(enable_log_color)
		printf(RESET);
	//printf("\n");
	fflush(stdout);
}
