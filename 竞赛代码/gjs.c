#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gjs.h"

MemberInfo_def	GOLBAL_MEMINFO[MEMBERNUM];/*会员信息列表*/
GoodsInfo_def		GOLBAL_GOODSINFO[GOODSNUM];/*商品信息列表*/


/*****************************************************************
* 函数名称:    Init_Member_Info_List
* 函数描述:    初始化会员信息     
* 输入参数:    MemberInfo_def指针
* 输出参数:    无
* 返回值  :    无
* 调用者  :    无
********************************************************************/
int	Init_Member_Info_List(MemberInfo_def  *meminflist)
{
	int		i;
	int		retval;

	for(i=0;i<MEMBERNUM;i++)/*初始化会员信息结构体数组*/
	{
		memset(&meminflist[i],0,sizeof(MemberInfo_def));
	}

	for(i=0;i<MEMBERNUM;i++)/*加载会员信息*/
	{
		switch(i)
		{
			case	0:
				strcpy(meminflist[i].name,"马丁");
				strcpy(meminflist[i].level,"普卡");
				strcpy(meminflist[i].cardNo,"6236609999");
				meminflist[i].integral=9860;
				break;
			case	1:
				strcpy(meminflist[i].name,"王立");
				strcpy(meminflist[i].level,"金卡");
				strcpy(meminflist[i].cardNo,"6630009999");
				meminflist[i].integral=48860;
				break;
			case	2:
				strcpy(meminflist[i].name,"李想");
				strcpy(meminflist[i].level,"白金卡");
				strcpy(meminflist[i].cardNo,"8230009999");
				meminflist[i].integral=98860;
				break;
			case	3:
				strcpy(meminflist[i].name,"张三");
				strcpy(meminflist[i].level,"钻石卡");
				strcpy(meminflist[i].cardNo,"9230009999");
				meminflist[i].integral=198860;
				break;
			defualt:
				printf("无效的会员编号");
				return -1;
		}
		
	}
	return 0;
}

/*****************************************************************
* 函数名称:    Init_Goods_Info_List
* 函数描述:    初始化商品信息     
* 输入参数:    GoodsInfo_def指针
* 输出参数:    无
* 返回值  :    无
* 调用者  :    无
********************************************************************/
int	Init_Goods_Info_List(GoodsInfo_def  *goodsinfolist)
{
	int		i;
	int		retval;
	GoodsInfo_def		goodsInfo;

	for(i=0;i<GOODSNUM;i++)/*初始化商品信息结构体数组*/
	{
		memset(&goodsinfolist[i],0,sizeof(GoodsInfo_def));
	}

	for(i=0;i<GOODSNUM;i++)/*加载商品信息*/
	{
		memset(&goodsInfo,0,sizeof(GoodsInfo_def));
		switch(i)
		{
			case	0:
				
				strcpy(goodsInfo.goodNo,"001001");
				strcpy(goodsInfo.goodName,"世园会五十国钱币册");
				goodsInfo.price=998.00;
				memcpy(&goodsinfolist[i],&goodsInfo,sizeof(GoodsInfo_def));
				break;
			case	1:
				
				strcpy(goodsInfo.goodNo,"001002");
				strcpy(goodsInfo.goodName,"2019北京世园会纪念银章大全40g");
				goodsInfo.price=1380.00;
				goodsInfo.discountList[0]=DISCOUNT_1;
				memcpy(&goodsinfolist[i],&goodsInfo,sizeof(GoodsInfo_def));
				break;
			case	2:
				
				strcpy(goodsInfo.goodNo,"003001");
				strcpy(goodsInfo.goodName,"招财进宝");
				goodsInfo.price=1580.00;
				goodsInfo.discountList[0]=DISCOUNT_2;
				memcpy(&goodsinfolist[i],&goodsInfo,sizeof(GoodsInfo_def));
				break;
			case	3:
				
				strcpy(goodsInfo.goodNo,"003002");
				strcpy(goodsInfo.goodName,"水晶之恋");
				goodsInfo.price=980.00;
				goodsInfo.offerList[0]=OFFER_4;
				goodsInfo.offerList[1]=OFFER_5;
				memcpy(&goodsinfolist[i],&goodsInfo,sizeof(GoodsInfo_def));
				break;
			case	4:
				
				strcpy(goodsInfo.goodNo,"002002");
				strcpy(goodsInfo.goodName,"中国经典钱币套装");
				goodsInfo.price=998.00;
				goodsInfo.offerList[0]=OFFER_2;
				goodsInfo.offerList[1]=OFFER_3;
				memcpy(&goodsinfolist[i],&goodsInfo,sizeof(GoodsInfo_def));
				break;
			case	5:
				
				strcpy(goodsInfo.goodNo,"002001");
				strcpy(goodsInfo.goodName,"守扩之羽比翼双飞4.8g");
				goodsInfo.price=1080.00;
				goodsInfo.offerList[0]=OFFER_4;
				goodsInfo.offerList[1]=OFFER_5;
				goodsInfo.discountList[0]=DISCOUNT_2;
				memcpy(&goodsinfolist[i],&goodsInfo,sizeof(GoodsInfo_def));
				break;
			case	6:
				
				strcpy(goodsInfo.goodNo,"002003");
				strcpy(goodsInfo.goodName,"中国银象棋12g ");
				goodsInfo.price=698.00;
				goodsInfo.offerList[0]=OFFER_1;
				goodsInfo.offerList[1]=OFFER_2;
				goodsInfo.offerList[1]=OFFER_3;
				goodsInfo.discountList[0]=DISCOUNT_1;
				memcpy(&goodsinfolist[i],&goodsInfo,sizeof(GoodsInfo_def));
				break;
			defualt:
				printf("无效的商品编号");
				return -1;
		}
	}
	return 0;
}

/*****************************************************************
* 函数名称:    Read_OrderJson_Info
* 函数描述:    读取json文件中的订单信息    
* 输入参数:    json文件名、订单信息
* 输出参数:    无
* 返回值  :    无
* 调用者  :    无
********************************************************************/

void Read_OrderJson_Info(char *file_name,OrderInfo_def *ddxx)
{
	char *p_start=NULL;
	char *p_end=NULL;
	char order_msg[1024*4];
	char buf[1000];
	char linebuf[1024];
	int amount=0;
	double ye_amount=0.0;
	int dd_num=0;
	int good_idx=0;
	FILE *fp_json=NULL;
	fp_json=fopen(file_name,"r");
	fprintf(stdout,"%s: %d :file_name[%s]\n",__FILE__,__LINE__,file_name);
	if(fp_json==NULL)
	{
		printf("打开json文件失败");
		return ;
	}
	memset(order_msg,0x00,sizeof(order_msg));

	while(!feof(fp_json))
	{
		memset(linebuf,0x00,sizeof(linebuf));
		fgets(linebuf,sizeof(linebuf),fp_json);
		memcpy(order_msg+strlen(order_msg),linebuf,strlen(linebuf));
		//strcat(buf,linebuf);
		
	}
	fprintf(stdout,"%s: %d :order_msg[%s]\n",__FILE__,__LINE__,order_msg);

	
	p_start=strstr(order_msg,"orderId\":");
	p_start=strstr(p_start+strlen("orderId\":"),"\"");
	p_end=strstr(p_start+1,"\"");
	memset(buf,0x00,sizeof(buf));
	memcpy(buf,p_start+1,p_end-p_start-1);
	memcpy(ddxx->orderId,buf,strlen(buf));
	//printf("orderId:[%s]\n",ddxx->orderId);
	p_start=p_end+1;

	p_start=strstr(order_msg,"memberId\":");
	p_start=strstr(p_start+strlen("memberId\":"),"\"");
	p_end=strstr(p_start+1,"\"");
	memset(buf,0x00,sizeof(buf));
	memcpy(buf,p_start+1,p_end-p_start-1)	;
	memcpy(ddxx->memberId,buf,strlen(buf));
	//printf("memberId:[%s]\n",ddxx->memberId);


	p_start=strstr(order_msg,"createTime\":");
	p_start=strstr(p_start+strlen("createTime\":"),"\"");
	p_end=strstr(p_start+1,"\"");
	memset(buf,0x00,sizeof(buf));
	memcpy(buf,p_start+1,p_end-p_start-1)	;
	memcpy(ddxx->createTime,buf,strlen(buf));
	//printf("createTime:[%s]\n",ddxx->createTime);	

	

	p_start=strstr(order_msg,"items\":");
	p_start=strstr(p_start+strlen("items\":"),"product\":");
	for(;;)
	{

		p_start=strstr(p_start+strlen("product\":"),"\"");			
		p_end=strstr(p_start+1,"\"");
		memset(buf,0x00,sizeof(buf));
		memcpy(buf,p_start+1,p_end-p_start-1) ;		
		//fprintf(stdout,"%s: %d :product[%s]\n",__FILE__,__LINE__,buf);
		memcpy(ddxx->items[dd_num].goodNo,buf,strlen(buf));

		p_start=strstr(p_end,"amount");
		p_start=strstr(p_start+strlen("amount"),":");
		p_end=strstr(p_start+1,",");

		
		memset(buf,0x00,sizeof(buf));
		memcpy(buf,p_start+1,p_end-p_start-1) ;	
		//fprintf(stdout,"%s: %d :amount[%s]\n",__FILE__,__LINE__,buf);
		amount=atoi(buf);
		//printf("amount:[%d]\n",amount);
		ddxx->items[dd_num].amount=amount;

		

		p_start=strstr(p_end+strlen("items\":"),"product\":");
		dd_num++;

		for(good_idx=0;good_idx<GOODSNUM;good_idx++)
		{
			if(memcmp(ddxx->items[good_idx].goodNo,GOLBAL_GOODSINFO[good_idx].goodNo,strlen(GOLBAL_GOODSINFO[good_idx].goodNo))==0)
			{
				ddxx->items[good_idx].price=GOLBAL_GOODSINFO[good_idx].price;
				memcpy(ddxx->items[good_idx].goodName,GOLBAL_GOODSINFO[good_idx].goodName,strlen(GOLBAL_GOODSINFO[good_idx].goodName));
			}
		}
		if(p_start==NULL) break;
		

		

	}

	ddxx->itemNum=dd_num;
	
	p_start=strstr(order_msg,"payments\":");
	p_start=strstr(p_start+strlen("payments\":"),"amount");
	p_start=strstr(p_start+strlen("amount"),":");
	p_end=strstr(p_start+1,",");		
	memset(buf,0x00,sizeof(buf));
	memcpy(buf,p_start+1,p_end-p_start) ;		
	//printf("amount:[%s]",buf);
	ye_amount=atof(buf);
	//printf("ye_amount:[%.2f]",ye_amount);
	ddxx->balamt=ye_amount;

	
	p_end=strstr(order_msg,"discountCards\":");
	if(p_start=NULL) 
	{
		fclose(fp_json);
		return ;
	}
	p_start=strstr(p_end+strlen("discountCards\":"),"95");
	if(p_start!=NULL){
		memcpy(ddxx->discountCards,"2",1);/*95折券*/
	}else
	{
		memcpy(ddxx->discountCards,"1",1);/*9折券*/
	}
	fclose(fp_json);
	return  ;
}



/*****************************************************************
* 函数名称:    Txn_Deal
* 函数描述:    交易处理    
* 输入参数:    订单信息
* 输出参数:    无
* 返回值  :    无
* 调用者  :    无
********************************************************************/
int Txn_Deal(OrderInfo_def  *OrderInfo)
{
	int		i,j,k;
	int		retval;
	int		gzlen=0;
	int		addPoints=0;/*新增积分数*/
	double	totalAmt;/*总金额*/
	double	totalyhAmt;/*订单优惠合计总金额*/
	double	factAmt;/*订单实际支付金额*/
	double	zkAmt;/*折扣金额*/
	double	mjAmt;/*满减金额*/
	double	mjAmtTmp;
	


	totalAmt=0;
	fprintf(stdout,"%s: %d :OrderInfo->itemNum[%d]\n",__FILE__,__LINE__,OrderInfo->itemNum);
	for(i=0;i<OrderInfo->itemNum;i++)/*遍历客户购买的商品列表*/
	{
		zkAmt=0;
		mjAmt=0;
		for(j=0;j<GOODSNUM;j++)		/*遍历内存中加载的全部商品列表，找到对应商品*/
		{
			fprintf(stdout,"%s: %d :OrderInfo->itemNum:[%d]\n",__FILE__,__LINE__,OrderInfo->itemNum);
			fprintf(stdout,"%s: %d :OrderInfo->items[%d]goodNo:[%s]\n",__FILE__,__LINE__,i,OrderInfo->items[i].goodNo);
			fprintf(stdout,"%s: %d :GOLBAL_GOODSINFO[%d].goodNo[%s]\n",__FILE__,__LINE__,j,GOLBAL_GOODSINFO[j].goodNo);
			if(strcmp(OrderInfo->items[i].goodNo,GOLBAL_GOODSINFO[j].goodNo) == 0)/*找到商品*/
			{
				fprintf(stdout,"%s: %d : find ok !  j=[%d]\n",__FILE__,__LINE__,j);
				strcpy(OrderInfo->items[i].goodName,GOLBAL_GOODSINFO[j].goodName);
				OrderInfo->items[i].price=GOLBAL_GOODSINFO[j].price;
				OrderInfo->items[i].sumAmt=GOLBAL_GOODSINFO[j].price*OrderInfo->items[i].amount;

				fprintf(stdout,"%s: %d : find ok !  j=[%d]\n",__FILE__,__LINE__,j);
				/*判断客户是否有折扣券*/
				if(OrderInfo->discountCards[0] == 0) 
				{
					zkAmt=0;
				}
				if(OrderInfo->discountCards[0] == GOLBAL_GOODSINFO[j].discountList[0] 
					&& OrderInfo->discountCards[0] == DISCOUNT_1) /*判断该订单的折扣券是否为9折*/
				{
					zkAmt=OrderInfo->items[i].sumAmt*0.9;
				}
				else if (OrderInfo->discountCards[0] == GOLBAL_GOODSINFO[j].discountList[0]
					&& OrderInfo->discountCards[0] == DISCOUNT_2)/*判断该订单的折扣券是否为95折*/
				{
					zkAmt=OrderInfo->items[i].sumAmt*0.95;
				}

				/*计算满减规则*/
				for(k=0;k<strlen(GOLBAL_GOODSINFO[j].offerList);k++)
				{
					mjAmtTmp=0;
					if(GOLBAL_GOODSINFO[j].offerList[k] == 1)
					{
						if(OrderInfo->items[i].sumAmt >= 3000)
						{
							mjAmtTmp=350;
							if(mjAmtTmp>mjAmt)
							{
								mjAmt=mjAmtTmp;
							}
						}
					}
					if(GOLBAL_GOODSINFO[j].offerList[k] == 2)
					{
						if(OrderInfo->items[i].sumAmt >= 2000)
						{
							mjAmtTmp=30;
							if(mjAmtTmp>mjAmt)
							{
								mjAmt=mjAmtTmp;
							}
						}
					}
					if(GOLBAL_GOODSINFO[j].offerList[k] == 3)
					{
						if(OrderInfo->items[i].sumAmt >= 1000)
						{
							mjAmtTmp=10;
							if(mjAmtTmp>mjAmt)
							{
								mjAmt=mjAmtTmp;
							}
						}
					}
					if(GOLBAL_GOODSINFO[j].offerList[k] == 4)
					{
						if(OrderInfo->items[i].amount >=3)
						{
							mjAmtTmp=OrderInfo->items[i].price/2;
							if(mjAmtTmp>mjAmt)
							{
								mjAmt=mjAmtTmp;
							}
						}
					}
					if(GOLBAL_GOODSINFO[j].offerList[k] == 5)
					{
						if(OrderInfo->items[i].amount >=4)
						{
							mjAmt=OrderInfo->items[i].price;
						}
						if(mjAmtTmp>mjAmt)
						{
							mjAmt=mjAmtTmp;
						}
					}
				}/*计算满减规则结束*/

				/*判断满减和折扣金额的大小*/
				if(mjAmt > zkAmt)
				{
					OrderInfo->items[i].reliefAmt = mjAmt;
				}
				else
				{
					OrderInfo->items[i].reliefAmt = zkAmt;
				}
				
				totalyhAmt+=OrderInfo->items[i].reliefAmt;
				totalAmt +=OrderInfo->items[i].sumAmt;
				break;
			}/*找到商品,单个商品处理完成*/
		}
	}
	
	/*处理积分*/
		factAmt=0;
		OrderInfo->orderSumAmt = totalAmt;
		OrderInfo->reliefSumAmt=totalyhAmt;		
		factAmt=OrderInfo->orderSumAmt - OrderInfo->reliefSumAmt;
		fprintf(stdout,"%s: %d :factAmt=[%.2f]\n",__FILE__,__LINE__,factAmt);
		for(i=0;i<MEMBERNUM;i++)/*遍历会员列表*/
		{
			if(strcmp(OrderInfo->memberId,GOLBAL_MEMINFO[i].cardNo) == 0)
			{
				fprintf(stdout,"%s: %d :OrderInfo->memberId[%s]\n",__FILE__,__LINE__,OrderInfo->memberId);
				fprintf(stdout,"%s: %d :GOLBAL_MEMINFO[%d].cardNo[%s]\n",__FILE__,__LINE__,i,GOLBAL_MEMINFO[i].cardNo);

				if(strcmp(GOLBAL_MEMINFO[i].level,"普卡") == 0)
				{
					addPoints=(int)factAmt;
					GOLBAL_MEMINFO[i].integral+=addPoints;
				}
				if(strcmp(GOLBAL_MEMINFO[i].level,"金卡") == 0)
				{
					addPoints=factAmt*1.5;
					GOLBAL_MEMINFO[i].integral+=addPoints;
				}
				if(strcmp(GOLBAL_MEMINFO[i].level,"白金卡") == 0)
				{
					addPoints=(int)factAmt*1.8;
					GOLBAL_MEMINFO[i].integral+=addPoints;
				}
				if(strcmp(GOLBAL_MEMINFO[i].level,"钻石卡") == 0)
				{
					addPoints=(int)factAmt*2;
					GOLBAL_MEMINFO[i].integral+=addPoints;
				}
				break;
			}
		}/*处理积分完成*/
		
	OrderInfo->addintegral=addPoints;
	/*更新会员等级*/
	for(i=0;i<MEMBERNUM;i++)/*遍历会员列表*/
	{
			if(GOLBAL_MEMINFO[i].integral <10000)
			{
					strcpy(GOLBAL_MEMINFO[i].level,"普卡");
			}
			else if(GOLBAL_MEMINFO[i].integral <50000)
			{
				strcpy(GOLBAL_MEMINFO[i].level,"金卡");
			}
			else if (GOLBAL_MEMINFO[i].integral <100000)
			{
				strcpy(GOLBAL_MEMINFO[i].level,"白金卡");
			}
			else
			{
				strcpy(GOLBAL_MEMINFO[i].level,"钻石卡");
			}
	}
	/*OrderInfo->orderSumAmt = totalAmt;
	OrderInfo->reliefSumAmt=totalyhAmt;    */
	return 0;
}


/*打印函数*/
void Print_OrderInfo(OrderInfo_def *ddxx)
{
	int goods_idx=0;
	int member_idx=0;
	FILE *fp_print=NULL;
	fp_print=fopen("sample_result.txt","w");
	if(fp_print==NULL)
	{
		printf("打开结果文件sample_result.txt失败\n");
		return;

	}
	fprintf(fp_print,"方鼎银行贵金属购买凭证\n\n");
	fprintf(fp_print,"销售单号：%s 日期：%s\n",ddxx->orderId,ddxx->createTime);
	for(member_idx;member_idx<MEMBERNUM;member_idx)
	{
		if(memcmp(ddxx->memberId,GOLBAL_MEMINFO[member_idx].cardNo,strlen(GOLBAL_MEMINFO[member_idx].cardNo))==0)
		{
		 break;
		}
		if(member_idx==3) 
		{
			printf("未关联到该会员信息\n");
			fclose(fp_print);
			return;

		}
	}	
	fprintf(fp_print,"客户卡号：%s 会员姓名：%s 客户等级：%s 累计积分：%ld\n\n",
		ddxx->memberId,
		GOLBAL_MEMINFO[member_idx].name,
		GOLBAL_MEMINFO[member_idx].level,
		GOLBAL_MEMINFO[member_idx].integral);
	fprintf(fp_print,"商品及数量           单价         金额\n");
	for(goods_idx;goods_idx<ddxx->itemNum;goods_idx++)
	{
		fprintf(fp_print,"(%s)%sx%d, %.2f, %.2f\n",
			ddxx->items[goods_idx].goodNo,
			ddxx->items[goods_idx].goodName,
			ddxx->items[goods_idx].amount,
			ddxx->items[goods_idx].price,
			ddxx->items[goods_idx].sumAmt);
	}
	
	fprintf(fp_print,"合计：%.2f\n\n",ddxx->orderSumAmt);
	fprintf(fp_print,"优惠清单：\n");
	for(goods_idx=0;goods_idx<ddxx->itemNum;goods_idx++)
	{
		if(ddxx->items[goods_idx].reliefAmt>0.005 )
		{
			fprintf(fp_print,"(%s)%s: -%.2f\n",
			ddxx->items[goods_idx].goodNo,
			ddxx->items[goods_idx].goodName,
			ddxx->items[goods_idx].reliefAmt);
		}
	}
	fprintf(fp_print,"优惠合计：%.2f\n\n",ddxx->reliefSumAmt);
	fprintf(fp_print,"应收合计：%.2f\n",ddxx->orderSumAmt-ddxx->reliefSumAmt);
	fprintf(fp_print,"收款：\n");
	if(memcmp(ddxx->discountCards,"1",1)==0)
	{
		fprintf(fp_print," 9折券\n");
	}else if(memcmp(ddxx->discountCards,"2",1)==0)
	{
		fprintf(fp_print," 95折券\n");
	}
	fprintf(fp_print," 余额支付：%.2f\n\n",ddxx->balamt);
	fprintf(fp_print,"客户等级与积分：\n");
	fprintf(fp_print," 新增积分：%d\n",ddxx->addintegral);
	if(GOLBAL_MEMINFO[member_idx].integral>=100000 && GOLBAL_MEMINFO[member_idx].integral-ddxx->addintegral<100000)

	{
		fprintf(fp_print," 恭喜您升级为钻石卡客户！\n");
	}else if(GOLBAL_MEMINFO[member_idx].integral>=50000 && GOLBAL_MEMINFO[member_idx].integral<100000 && GOLBAL_MEMINFO[member_idx].integral-ddxx->addintegral<50000)
	{
		fprintf(fp_print," 恭喜您升级为白金卡客户！\n");
	}else if(GOLBAL_MEMINFO[member_idx].integral>=10000 && GOLBAL_MEMINFO[member_idx].integral<50000 && GOLBAL_MEMINFO[member_idx].integral-ddxx->addintegral<10000)
	{
		fprintf(fp_print," 恭喜您升级为金卡客户！\n");
	}
	fclose(fp_print);
//	system("iconv  -f GBK -t UTF-8 sample_result.txt -o sample_result.txt");

	
	return;
}


/*****************************************************************
* 函数名称:    main
* 函数描述:    读取订单信息，处理交易并打印凭证      
* 输入参数:    订单信息json文件
* 输出参数:    凭证文件txt
* 返回值  :    无
* 调用者  :    无
********************************************************************/
int main(int argc,char *argv[])
{
	int		retval;
	int		i;
	char		fullFilename[100];/*文件全路径*/
	char		jsonFileName[100];/*订单json文件名*/
	char		certFileName[100];/*凭证文件名*/
	

	OrderInfo_def		OrderInfo;/*订单信息*/
	
	/*加载会员信息到内存*/
	fprintf(stdout,"%s: %d : begin hui yuan \n",__FILE__,__LINE__);
	retval=Init_Member_Info_List(&GOLBAL_MEMINFO);
	if(retval)
	{
		printf("加载会员信息错误，请检查!");
		return -1;
	}
	for(i=0;i<MEMBERNUM;i++)
	{
		fprintf(stdout,"%s: %d :GOLBAL_MEMINFO[%d] name[%s],level[%s],cardNo[%s],integral[%d]  \n",__FILE__,__LINE__,i,GOLBAL_MEMINFO[i].name,GOLBAL_MEMINFO[i].level,GOLBAL_MEMINFO[i].cardNo,GOLBAL_MEMINFO[i].integral);
	}

	/*加载商品信息到内存*/
	fprintf(stdout,"%s: %d :begin  shang pin\n",__FILE__,__LINE__);
	retval=Init_Goods_Info_List(&GOLBAL_GOODSINFO);
	if(retval)
	{
		printf("加载商品信息错误，请检查!");
		return -1;
	}
	for(i=0;i<GOODSNUM;i++)
	{
		fprintf(stdout,"%s: %d : goodNo[%s],name[%s],price[%.2f] offerList[%s],[discountList[%s]\n",__FILE__,__LINE__,GOLBAL_GOODSINFO[i].goodNo,GOLBAL_GOODSINFO[i].goodName,GOLBAL_GOODSINFO[i].price,GOLBAL_GOODSINFO[i].offerList,GOLBAL_GOODSINFO[i].discountList);
	}

	/*读取json订单文件到订单信息结构体中*/
	memset(fullFilename,0,sizeof(fullFilename));
	memset(jsonFileName,0,sizeof(jsonFileName));
	strcpy(jsonFileName,argv[1]);
	/*sprintf(fullFilename,"%s/%s",FILEPATH,jsonFileName);*/
	printf("json文件[%s]",jsonFileName);
	
	Read_OrderJson_Info(jsonFileName,&OrderInfo);

	printf("orderId:[%s] memberId:[%s] itemNum:[%d] balamt:[%.2f] discountCards:[%s]\n",
		OrderInfo.orderId,OrderInfo.memberId,OrderInfo.itemNum,OrderInfo.balamt,OrderInfo.discountCards);

	for(i=0;i<OrderInfo.itemNum;i++)
	{
		printf("goodNo:[%s] goodName:[%s] price:[%.2f] \n",
			OrderInfo.items[i].goodNo,OrderInfo.items[i].goodName,OrderInfo.items[i].price);

	}

	/*调用交易处理函数*/
	retval=Txn_Deal(&OrderInfo);
	if(retval)
	{
		printf("交易处理错误，请检查!");
		return -1;
	}

	/*调用打印函数*/
	Print_OrderInfo(&OrderInfo);

	return 0;
}
