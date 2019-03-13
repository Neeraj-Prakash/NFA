//NFA to accept strings having last but one symbol as 0

#define N_st 3
#define N_ip 2
#define N_Fst 1

int stats[N_st]={0,1,2};
int input[N_ip]={0,1};
int fin[N_Fst]={2};
int rules[N_st][N_ip][N_st]={{{0,1,-1},{0,-1,-1}},{{-1,-1,2},{-1,-1,2}},{{-1,-1,-1},{-1,-1,-1}}};
int in_st=0;

