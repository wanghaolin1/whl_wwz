#ifndef STRUCT_H
#define STRUCT_H
#define MY_EXIT    0
#define MY_CREAT   1		/*开户*/
#define MY_SAVE    2		/*存钱*/
#define MY_TAKE    3		/*取钱*/
#define MY_QUERY   4		/*查询余额*/
#define MY_TRANS   5		/*转账*/
#define MY_MODIFY  6		/*修改密码*/
#define MY_DESTORY 7		/*销户*/
#define MY_LOAD	   8		/*登录*/
#define SAME       9   	 	/*信息相同*/
#define UNLOCK	   10		/*解锁*/
#define LOCK	   11		/*加锁*/
#define NO_EXIST   12		/*不存在用户*/
typedef struct Account
{
	int id;					/*卡号*/
	char name[20];			/*姓名*/
	char identify[20];		/*身份证*/
	char password[7];		/*密码*/
	double money;			/*余额*/
	int cnt;				/*锁的标志,代表剩余几次登录机会*/
	int online;				/*是否在线*/
	int res;				/*操作标志位*/
}Acc;

typedef struct Trans
{
	int id_my;				/*转账用户卡号*/
	int id_obj;				/*目标用户卡号*/
	double money;			/*金额*/
	int res;				/*操作标志位*/
}Tra;

typedef struct Modify
{
	int id;					/*卡号*/
	char password_old[7];	/*旧密码*/
	char password_new[7];	/*新密码*/
	int res;				/*操作标志位*/
}Mod;

#endif // STRUCT_H
