struct ques{
	int q_id;
	char ques[200];
};
struct ans{
	int q_id;
	int c_id;
	char ans[30];
};
struct board{
	int id[10];
	int score[10];
	int size;
};
program ASSIGN{
	version ASSIGN_VERS{
		int First(void) = 1;
		ques Get_ques(int) = 2;
		int Check_ans(ans) = 3;
		int Ask_score(int) = 4;
		int Ask_rank(int) = 5;
		board Get_board(void) = 6;
		void Exit(int) = 7;	
	} = 1;
} = 0x13451111;

