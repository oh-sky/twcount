#include<stdio.h>
#include<stdlib.h>
#include<mysql.h>
#define BUFFSIZE 256

my_bool twcount_init(UDF_INIT *initid, UDF_ARGS *args, char *message)
{
	return 0;
}
void twcount_deinit(UDF_INIT *initid __attribute__((unused)))
{
}
long long twcount(UDF_INIT *initid,UDF_ARGS *args, char *is_null, char *error)
{
        char buffer[BUFFSIZE];
        FILE *p;
	snprintf(buffer,BUFFSIZE,"/path/to/script/tw_count.php %s",args->args[0]);
        p = popen(buffer,"r");
        if(!p){
		return 0;
        }else{
                if(fgets(buffer,BUFFSIZE,p)){
			pclose(p);
			return atoi(buffer);
                }else{
			return 0;
		}
        }
}

