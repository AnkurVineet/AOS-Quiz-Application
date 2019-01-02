/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _ASSIGN_H_RPCGEN
#define _ASSIGN_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct ques {
	int q_id;
	char ques[200];
};
typedef struct ques ques;

struct ans {
	int q_id;
	int c_id;
	char ans[30];
};
typedef struct ans ans;

struct board {
	int id[10];
	int score[10];
	int size;
};
typedef struct board board;

#define ASSIGN 0x13451111
#define ASSIGN_VERS 1

#if defined(__STDC__) || defined(__cplusplus)
#define First 1
extern  int * first_1(void *, CLIENT *);
extern  int * first_1_svc(void *, struct svc_req *);
#define Get_ques 2
extern  ques * get_ques_1(int *, CLIENT *);
extern  ques * get_ques_1_svc(int *, struct svc_req *);
#define Check_ans 3
extern  int * check_ans_1(ans *, CLIENT *);
extern  int * check_ans_1_svc(ans *, struct svc_req *);
#define Ask_score 4
extern  int * ask_score_1(int *, CLIENT *);
extern  int * ask_score_1_svc(int *, struct svc_req *);
#define Ask_rank 5
extern  int * ask_rank_1(int *, CLIENT *);
extern  int * ask_rank_1_svc(int *, struct svc_req *);
#define Get_board 6
extern  board * get_board_1(void *, CLIENT *);
extern  board * get_board_1_svc(void *, struct svc_req *);
#define Exit 7
extern  void * exit_1(int *, CLIENT *);
extern  void * exit_1_svc(int *, struct svc_req *);
extern int assign_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define First 1
extern  int * first_1();
extern  int * first_1_svc();
#define Get_ques 2
extern  ques * get_ques_1();
extern  ques * get_ques_1_svc();
#define Check_ans 3
extern  int * check_ans_1();
extern  int * check_ans_1_svc();
#define Ask_score 4
extern  int * ask_score_1();
extern  int * ask_score_1_svc();
#define Ask_rank 5
extern  int * ask_rank_1();
extern  int * ask_rank_1_svc();
#define Get_board 6
extern  board * get_board_1();
extern  board * get_board_1_svc();
#define Exit 7
extern  void * exit_1();
extern  void * exit_1_svc();
extern int assign_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_ques (XDR *, ques*);
extern  bool_t xdr_ans (XDR *, ans*);
extern  bool_t xdr_board (XDR *, board*);

#else /* K&R C */
extern bool_t xdr_ques ();
extern bool_t xdr_ans ();
extern bool_t xdr_board ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_ASSIGN_H_RPCGEN */
