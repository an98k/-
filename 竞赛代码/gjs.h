#include <stdio.h>
#include <stdlib.h>

#define		MEMBERNUM	4    /*会员数量*/
#define		GOODSNUM		7	 /*商品数量*/

#define		FILEPATH		/home		/**/
/*定义折扣规则*/
#define		DISCOUNT_1		1	/*可使用9折打折券*/
#define		DISCOUNT_2 		2	/*可使用95折打折券*/  

/*定义优惠规则*/
#define		OFFER_1		1	/*每满3000元减350*/
#define		OFFER_2		2	/*每满2000元减30*/
#define		OFFER_3		3	/*每满1000元减10*/
#define		OFFER_4		4	/*第3件半价（买3件及以上，其中1件半价）*/
#define		OFFER_5		5	/*满3送1（买4件及以上，其中1件免费）*/

typedef struct/*定义会员信息结构体*/
{
	char		name		[20]; /*姓名*/
	char		level		[20];/*等级*/
	char		cardNo		[32];/*卡号*/
	long		integral;			/*积分*/
}MemberInfo_def;

typedef struct/*定义商品信息结构体*/
{
	char		goodNo		[20];/*商品编号*/
	char		goodName	[100]; /*商品名称*/
	double	price			;/*单价*/
	char		offerList		[32];/*满减规则*/
	char		discountList	[32];/*折扣规则*/
}GoodsInfo_def;

typedef struct/*定义子订单信息*/
{
	char		goodNo		[20];/*商品编号*/
	char		goodName	[100]; /*商品名称*/
	int		amount;			/*商品数量*/
	double	price;			/*单价*/
	double	sumAmt;		/*商品总金额*/
	double	reliefAmt;		/*优惠金额*/
	
}Itemsinfo_def;

typedef struct/*定义订单信息结构体*/
{
	char		orderId		[20];/*订单编号*/
	char		memberId	[50]; /*会员编号*/
	char		createTime	[50]; /*订单时间*/
	int		itemNum;		/*商品数量*/
	Itemsinfo_def 		items[50];/*商品列表*/
	char		paytype[20];		/*支付方式*/
	double	balamt;			/*余额*/
	char		discountCards[20];/*折扣券*/
	double	orderSumAmt;	/*订单合计金额*/
	double	reliefSumAmt;	/*优惠合计金额*/
	int		addintegral;		/*新增积分*/
}OrderInfo_def;



