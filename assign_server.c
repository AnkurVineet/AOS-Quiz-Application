/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "assign.h"
#include<unistd.h>
#include<stdlib.h>
#include<time.h>

int *
first_1_svc(void *argp, struct svc_req *rqstp)
{
	static int  result;
	int max_id = 0,max_rank = 0;
	int rank,id = 0 ,score,lques;
	if( access( "Score.txt", F_OK ) != -1 ) {
		FILE *fp = fopen("Score.txt","r");
		while(fscanf(fp,"%d %d %d %d",&rank,&id,&score,&lques) == 4){
			if(id > max_id)
				max_id = id;
			if(rank > max_rank)
				max_rank = rank;
		}
		fclose(fp);
		FILE *fpw = fopen("Score.txt","a");
		fprintf(fpw,"%d %d %d %d\n",max_rank+1,max_id+1,0,-1);
		fclose(fpw);
	} else {
	    	FILE *fpw = fopen("Score.txt","w");
		fprintf(fpw,"%d %d %d %d\n",1,1,0,-1);
		fclose(fpw);
	}
	result = max_id + 1;
	return &result;
}

ques *
get_ques_1_svc(int *argp, struct svc_req *rqstp)
{
	static ques result;
	time_t t;
	int rand_ques;
	srand((unsigned) time(&t));
	if(*argp == -1)
		rand_ques = rand() % 50;	
	else
		rand_ques = *argp;
	char ques_str[200];
	result.q_id = rand_ques;
	FILE *fp = fopen("questions.txt","r");
	for(int i = 0 ; i <= rand_ques; i++)
		fgets(ques_str,200,fp);
	strcpy(result.ques,ques_str);
	fclose(fp);
	return &result;
}

int *
check_ans_1_svc(ans *argp, struct svc_req *rqstp)
{
	static int  result;
	int t_rank[100],t_id[100],t_score[100],t_lques[100];
	int rank,id,score,lques;
	char ans_str[30];
	char q_num[3];
	FILE *fp = fopen("answer.txt","r");
	for(int i = 0 ; i <= argp->q_id; i++)
		fgets(ans_str,30,fp);
	int i = 0;			
	for(i = 0 ; ans_str[i] != ')'; i++);
		//printf("%d\n",i);
	i++;
	int j = 0;
	char new_str[20];
	for(;ans_str[i] != '\n'; i++){
		new_str[j] = ans_str[i];
		j++;
	}
	new_str[j] = '\0';
	int size = 0;
	//printf("%s",argp->ans);
	fflush(stdout);
	if(strcmp(new_str,argp->ans) == 0){
		result = 1;
		FILE *fp = fopen("Score.txt","r");
		while(fscanf(fp,"%d %d %d %d",&rank,&id,&score,&lques) == 4){
			if(id == argp->c_id)
				score++;
			t_rank[size] = rank;
			t_id[size] = id;
			t_score[size] = score;
			t_lques[size] = lques;
			size++;
		}
		fclose(fp);
		//Sorting
		int a, key_rank,key_id,key_score,key_lques, b;
   		for (a = 1; a < size; a++)
   		{
       			key_rank = t_rank[a];
			key_id = t_id[a];
			key_score = t_score[a];
			key_lques = t_lques[a];
       			b = a-1; 	
		 	while (b >= 0 && t_score[b] < key_score)
		 	{
				t_rank[b+1] = t_rank[b];
				t_id[b+1] = t_id[b];
				t_score[b+1] = t_score[b];
				t_lques[b+1] = t_lques[b];
				b = b-1;
			}
			t_rank[b+1] = key_rank;
			t_id[b+1] = key_id;
			t_score[b+1] = key_score;
			t_lques[b+1] = key_lques;
		}
		//Sorting complete
		FILE *fpw = fopen("check.txt","w");
		for(int i = 0 ; i < size ; i++)
		{
			t_rank[i] = i+1;
			fprintf(fpw,"%d %d %d %d\n",t_rank[i],t_id[i],t_score[i],t_lques[i]);
		}
		fclose(fpw);
		remove("Score.txt");
		rename("check.txt","Score.txt");
	}
	else
		result = 0;
	return &result;
}

int *
ask_score_1_svc(int *argp, struct svc_req *rqstp)
{
	static int  result;
	int rank,id,score,lques;
	FILE *fp = fopen("Score.txt","r");
	while(fscanf(fp,"%d %d %d %d",&rank,&id,&score,&lques) == 4){
		if(id == *argp)
			result = score;
	}
	fclose(fp);
	return &result;
}

int *
ask_rank_1_svc(int *argp, struct svc_req *rqstp)
{
	static int result;
	int rank,id,score,lques;
	FILE *fp = fopen("Score.txt","r");
	while(fscanf(fp,"%d %d %d %d",&rank,&id,&score,&lques) == 4){
		if(id == *argp)
			result = rank;
	}
	fclose(fp);
	return &result;
}

board *
get_board_1_svc(void *argp, struct svc_req *rqstp)
{
	static board result;
	int rank,id,score,lques;
	int i = 0;
	FILE *fp = fopen("Score.txt","r");
	while(fscanf(fp,"%d %d %d %d",&rank,&id,&score,&lques) == 4 && i<10){
		result.id[i] = id;
		result.score[i] = score;
		i++;
	}
	result.size = i;
	return &result;
}

void *
exit_1_svc(int *argp, struct svc_req *rqstp)
{
	static char * result;
	FILE *fp = fopen("Score.txt","r");
	int i = 0;
	int rank,id,score,lques;
	FILE *fpw = fopen("check.txt","w");	
	while(fscanf(fp,"%d %d %d %d",&rank,&id,&score,&lques) == 4){
		if(id != *argp)
		{
			fprintf(fpw,"%d %d %d %d\n",i+1,id,score,lques);
			i++;
		}
	}
	fclose(fpw);
	fclose(fp);
	remove("Score.txt");
	rename("check.txt","Score.txt");
	return (void *) &result;
}
/*
FILE *fp = fopen("answers.txt","r");
	for(int i = 0 ; i <= argp->q_id; i++)
		fgets(ans_str,15,fp);
	fclose(fp);
	sprintf(q_num,"%d",(argp->q_id+1));
	FILE *fpw = fopen("check.txt","w");
	fprintf(fpw,"%s %s",strcat(strcat(q_num ,")"),argp->ans), ans_str);
	fclose(fpw);
	if(strcmp(ans_str,strcat(')',argp->ans))==0)
		result = 1;
	else
		result = 0;*/
	
