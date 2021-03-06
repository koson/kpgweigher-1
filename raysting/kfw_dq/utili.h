#ifndef __UTILI_H
#define __UTILI_H


#include "typedef.h"


#define HASCH1		01
#define HASCH2		02

void delay (uint us) ;
void delay1 (uint ms);
uchar strlen(uchar *s);
char lowc(uchar x);
char highc(uchar x);
#define KEY_INVALID '-'													  
#define KEY_NUM0	'0'
#define KEY_NUM1	'1'
#define KEY_NUM2	'2'
#define KEY_NUM3	'3'
#define KEY_NUM4	'4'
#define KEY_NUM5	'5'
#define KEY_NUM6	'6'
#define KEY_NUM7	'7'
#define KEY_NUM8	'8'
#define KEY_NUM9	'9'
#define KEY_DOT		'.'
#define KEY_UP		'U'
#define KEY_DN		'D'
#define KEY_CE		'C'
#define KEY_OK		'O'
#define KEY_TAB		'T'
#define KEY_BTN1	'a'
#define KEY_BTN2	'b'
#define KEY_BTN3	'c'
#define KEY_BTN4  	'd'
											
#define PG_MAIN			1
#define PG_MENU1		2
#define PG_MENU2		3
#define PG_RANGE		4
#define PG_CALISET		5
#define PG_RZERO		6
#define PG_PSET			7
#define PG_PSET_L		8
#define PG_PSET_R		9
#define PG_PSET_W		10
#define PG_PSET_H		11
#define PG_SET232		12
#define PG_HELP			13
#define PG_HELP_ADDR	14
#define PG_HELP_PREC	15
#define PG_HELP_SET		16
#define PG_MSG_RZERO	200

#define BUF_MAX		10

#define DELAY_MULTIPLE	10
#define DELAY_MASK		0x000003ff


#define PSET_NONE		0
#define PSET_RADIUS		1
#define PSET_SQUARE		2

#define CURRENT_MIN		0
#define CURRENT_SQRT0P5	0
#define CURRENT_1		1
#define CURRENT_SQRT2	2
#define CURRENT_MAX		2

#define AUTO_OFF		0
#define AUTO_ON			1

#define KTT_OFF			0
#define KTT_ON			1

#define RANGE_200k		9
#define RANGE_20k		8
#define RANGE_2k		7
#define RANGE_200		6
#define RANGE_20		5
#define RANGE_2			4
#define RANGE_200m		3
#define RANGE_20mo		2
#define RANGE_2mo		1
#define RANGE_200u		0


#define PI	3.14159
#define BAUDRATE_NONE		0
#define BAUDRATE_2400		1
#define BAUDRATE_9600		2
typedef struct _RUNDATA
{
	uchar	Current;  //current choise 0-2
	uchar	Baudrate; //baudrate
	uchar 	Range;    //0-9
	uchar	Ptype;	  //0,1,2
	uchar   Rauto;	  //0,1
	uchar   Rktt;	  //0,1

	double  Temp;	  //temperature
	double  Pvalue;	  //p value
	double  Plength;  //parameter for P caculation
	double  Pradius;  //parameter for P caculation
	double  Pwidth;   //parameter for P caculation
	double  Pheight;  //parameter for P caculation

	double  Rcali[10];//calibration data for each range
	double 	Rs1;	  //jiao-zheng zhi
	double 	Rx1;	  //cong ji celiangzhi
	double 	Rx;		  //final result
	double  R0;		  //zero value
	uchar	Delay;
	uchar	delay_cnt;
	//state control regs
	uchar	StateId;
	uchar	pos_len;
	char	tempbuf[BUF_MAX];
}RUNDATA;

extern RUNDATA rdata;
void SaveToEEPROM();
void State_Change(uchar);
void State_Display();
void State_Init();
void display_buttons(uchar pos,uchar val);
double buf2double();
int buf2byte();
void LCD_Print8X16(uchar x, uchar y,uchar *s);

#define CMD_READ	0x01	//read data
extern uchar xdata ch1buf[8];
extern uchar xdata ch2buf[8];
extern double ch1val,ch2val;


void sm_Init();
void sm_read(uchar pos,uchar ch);
void sm_write(uchar value);

#define CMD_QUERY 		0xA0	//5 bytes will be returned.

#define CMD_KTT_BASE	0xC1
#define CMD_KTT_POS		0xC1
#define CMD_KTT_NEG		0xC2

#define CMD_CURR_BASE	0xC3	//C3: 0.707; C4: 1; C5: 1.414

#define CMD_RANGE_BASE	0x01	//01: 20mo, ...



extern void DBG(uchar);

extern void Init_18b20();
extern void get_18b20();

extern uchar get_voltage();
#endif
