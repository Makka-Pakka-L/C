 /*************************************************
name :���� 
writer: ���Ľ� 
date :2005-10 
����һ��ģ�������õ���Ϸ 
�ж�����Ҳ���  
**************************************************/ 
#include<graphics.h>/*�õ��Ŀ⺯��*/ 
#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 
#include<bios.h> 
#include<dos.h> 
#define ESC 0x011b /*������ʹ�õ��ļ�ֵ*/ 
#define UP1 0x1177 
#define DOWN1 0x1f73 
#define LEFT1 0x1e61 
#define RIGHT1 0x2064 
#define UP2 0x4800 
#define DOWN2 0x5000 
#define LEFT2 0x4b00 
#define RIGHT2 0x4d00 
#define Z 0x2c7a 
#define DEL 0x5300 
#define ENTER 0x1c0d 
#define SPACE 0x3920 

#define MX 21 /*ÿ�еķ�����*/ 
#define MY 16 /*ÿ�еķ�����*/ 
#define BOXLONG 30 /*����ĳ���*/ 


typedef struct/*������Ϸ ���˵Ľṹ��*/ 
{int x; 
int y;/*�˵�λ��*/ 
int definetime; /*�Ƿ����ը����ʱ*/ 
int maxball;/*�����ԷŶ���ը��*/ 
int power;/*ը����ը�ĳ��ȣ�Ҳ��������*/ 
int ballnum;/*���ڷ��˶���ը��*/ 
}human; 


typedef struct/*����ը�������ݽṹ��������ֵ������ը������Ϣ*/ 
{ 
int used;/*��ը���Ƿ�ʹ��*/ 
int x; 
int y;/*ը��λ��*/ 
int man;/*˭�ŵ�ը��*/ 
int page;/*��ǰը���ǵڼ�֡����������ը���Ķ�̬Ч��*/ 
int time;/*ը�����õ�ʱ��*/ 
}tball; 


tball ball[10];/*����10��ը��*/ 
human man[2];/*����2����*/ 
void *tu[13];/*����13��ָ��ͼ���ָ�룬����ָ����Ϸ����Ҫ��ͼ��*/ 


int map[MX][MY];/*����洢��Ī��Ϣ������*/ 
int ballnum=0;/*�������浱ǰ����ը�����ܸ���*/ 

/*********************************** 
��Ϸ���õ����Զ��庯�� 
�����ں������崦���� 
***********************************/ 

/*
viod initgra();
int message(char *s);
viod draw();
viod initgame();
viod ZaLine(int x1,int y1,int num);
viod HuanYuan(int x1,int y1,int num);
viod BaoZa(int num);
viod PutZaDan(int mann);
viod DrawZaDan();
viod CheckZaDan();
viod DefineZa(int n);
viod move(int x1 ,int y1,int mann );
viod GameOver();

 */
/*���������������ʼ����Ļ*/
initgra()
{int dr=DETECT,mode=0;
registerbgidriver(EGAVGA_driver);

initgraph(&dr,&mode,""); 

} 



/*********************************** 
�����������������Ϸ�в���һ����Ϣ�Ի��� 

����Ϊһ���ַ���ָ�� 

����ֵΪһ���������� 
�������Ϊ ��n�� 
����0 
���򷵻� 1 
*********************************/ 
int message(char *s) 
{ char c; 
setfillstyle(1,4); 
setcolor(1); 
settextstyle(0,0,3); 
bar(640/2-200,480/2-50,640/2+250,480/2+50); 
outtextxy(640/2-200,480/2-20,s); 
c=getch(); 
sleep(2); 
if(c=='n'|| c=='N')return(0);else return(1); 

} 



/**************************************** 


�ÿ⺯�������Ϸ�����õ���ͼ�񣬱��浽�����пռ���  

**************************************/ 
draw() 
{int i=0; 
cleardevice(); 
for (i=0;i<13;i++) if(i!=6) tu[i]=malloc(imagesize(0,0,29,29)); 
/*��Ϊ����ָ���õ���ը������֡��ͼ�񣬱��Բ��÷���ռ�*/ 

/*��һ���հ�ͼ��浽0�ſռ���*/ 

getimage(0,0,29,29,tu[0]); 

/*�����ǻ�������ը���Ķ�̬Ч�����ĸ�ͼ��1~4 �ſռ���*/ 

setcolor(4); 
setfillstyle(1,4); 
for(i=0;i<4;i++) 
{ 
fillellipse(15,15,7+i*2,7+i*2); 
getimage(0,0,29,29,tu[i+1]); 
} 

putimage(0,0,tu[4],1);/*���ͼ���Ի���ͼ*/ 

/*����ʱ����ͼ�񲢴浽5�ſռ���*/ 
 
 
setcolor(12); 
line(3,5,20,25); 
line(20,25,28,5); 
line(28,5,3,5); 
fillellipse(16,15,4,4); 
getimage(0,0,29,29,tu[5]); 
putimage(0,0,tu[5],1); 

tu[6]=tu[4];/*���ſմ����ը��ͼ�񣬳��˿������ӷŵ�ը������*/ 
  /*�������ʹ��ը������֡��ͼ��*/ 



/*������ͼ��浽7�ſռ���*/ 

setcolor(4); 
setlinestyle(0,0,3); 
line(20,2,7,16); 
line(20,2,16,12); 
line(16,12,24,13); 
line(7,16,15,15); 
line(15,15,8,29); 
line(24,13,8,29); 
getimage(0,0,29,29,tu[7]); 
putimage(0,0,tu[7],1); 

/*��ģ�ⱬըЧ����ͼ��浽8�ſռ���*/ 

for(i=0;i<200;i++) 
putpixel(random(30),random(30),random(16)); 
getimage(0,0,29,29,tu[8]); 
putimage(0,0,tu[8],1); 



/*�ѿ��ƶ�������ͼ��浽9�ſռ���*/ 

setcolor(1); 
setfillstyle(1,14); 
bar(1,1,28,28); 
setcolor(1); 
line(15,1,15,10); 
line(1,10,28,10); 
line(1,20,29,20); 
line(15,20,15,28); 
getimage(0,0,29,29,tu[9]); 
putimage(0,0,tu[9],1); 

/*�Ѳ����ƶ�������ͼ��浽10�ſռ���*/ 

setcolor(9); 
setfillstyle(1,12); 
bar3d(1,1,26,26,1,1); 
getimage(0,0,29,29,tu[10]); 
putimage (0,0,tu[0],0); 


/*�ѵ�һ������ͼ��浽11�ſռ���*/ 

setlinestyle(0,0,3); 
setcolor(4); 
circle(15,15,13); 
circle(8,13,4); 
circle(24,13,4); 
line(11,18,17,15); 
line(11,18,15,19); 
setlinestyle(0,0,3); 
arc(15,15,225,320,9); 
getimage(0,0,29,29,tu[11]); 
putimage(0,0,tu[11],1); 

/*�ѵڶ�������ͼ��浽11�ſռ���*/ 

setlinestyle(0,0,3); 
setcolor(1); 
circle(15,15,13); 
circle(8,13,4); 
circle(24,13,4); 
line(11,18,17,15); 
line(11,18,15,19); 
setlinestyle(0,0,3); 
arc(15,15,225,320,9); 
getimage(0,0,29,29,tu[12]); 
putimage(0,0,tu[12],1); 


} 


/*************************** 
��ʼ����Ϸ 
�����������ͼ 
****************************/ 
initgame() 
{int i,j; 
cleardevice(); 

randomize(); 

/*�������ը��*/ 
for(i=0;i<10;i++) ball[i].used=0; 
/*�Ȱ���Ļ��Ϣ�����ʼ��ʲΪ100*/ 
for (i=0;i<22;i++) 
for (j=0;j<16;j++) 
map[i][j]=100; 
/*�Ȱ���Ļ��Ϣ�����˵�λ�ã�ʼ������ÿ�ζ�����*/ 


man[0].x=0; 
man[0].y=0; 
man[0].maxball=1; 
man[0].ballnum=0; 
man[0].power=2; 

man[0].definetime=0; 
man[1].x=MX-1; 
man[1].y=MY-1; 
man[1].maxball=1; 
man[1].ballnum=0; 
man[1].power=2; 
man[1].definetime=0; 
map[0][0]=11; 
map[0][1]=0; 
map[1][0]=0; 
map[MX-1][MY-1]=12; 
map[MX-1][MY-2]=0 ; 
map[MX-2][MY-1]=0; 
/*���˵�ͼ���*/ 

putimage(0,0,tu[11],1); 

putimage(600,15*30,tu[12],0); 

/*������������ͼ*/ 
for (i=0;i<21;i++) 
for (j=0;j<16;j++) 
{ if (map[i][j]!=100) continue; 

if (random(1000)%2==0||random(1000)%6==0) 
{ 
map[i][j]=9; 
putimage(i*30,j*30,tu[9],0); 
}else if(random(1000)%2==0||random(1000)%5==0) 
{map[i][j]=10; 
putimage(i*30,j*30,tu[10],0); 
}else 
map[i][j]=0; 
} 


} 




/*************************************** 
��һ�����������ըЧ�� 
����num��Ҫ��ը��ը����� 
x1,y1 ը�ķ��� 
0,1 ������ 
0,-1 ����
��1,0 ����
1,0 ����

****************************************/

ZaLine(int x1,int y1,int num)
{int x,y,x2,y2,i,l,j;
x=ball[num].x;/* ȡ��ը��λ�� */
y2=ball[num].y;

l=man[ball[num].man].power;/* ը����ը�ĳ��� */
for(i=0,j=0;abs(i)<l&&abs(j)<l;i+=x1,j+=y1)/*���û�е�ָ������ */


 { x=x2+i;
 y=y2+j;/* ��ǰ�鵽��λ��λ�� */


if(x<0||x>20||y<0||y>15) return 0;/* ���������Ļ��Χ���˳�����ִ�� */

 if ((x==man[0].x&&y==man[0].y)||(x==man[1].x&&y==man[1].y))/* ���ը������ */
{  if (!(x==man[0].x&&y==man[0].y))/* �������һ�� */
message("the red win!");/* ��ʾ��ɫ���ʤ����Ϣ */
  else
message("the green win!");/* ��ʾ��ɫ���ʤ����Ϣ */

gameover();/* ������Ϸ */

}else if(map[x][y]==0)/* ���Ϊ�� */

{ putimage((x)*30,(y)*30,tu[8],0);/*�ű�ըЧ��ͼ */

}else if(map[x][y]==9)/* ���Ϊ�������� */

{ putimage((x)*30,(y)*30,tu[0],0);/* ��ȥԭʼͼ��*/

putimage((x)*30,(y)*30,tu[8],0);/*�ű�ըЧ��ͼ */
if (random(1000)%4==0) /*������������Ч��*/
{ int r;
r=random(3)+5;
if(r>7)r--;
map[x][y]=r;
}
else map[x][y]=0;
return 0;/* ��Ϊը���˶���������ֹͣ��ը */
}else if (map[x][y]>=20) BaoZa(map[x][y]%10);/* ����鵽ը��������ը */

else if (map[x][y]==10) return 0;/* ���������ը�������ӣ�ֹͣ��ը */

else/* ����������϶������������ԳԵĶ������������磬��ʱ������ը��������ը����������ը */
{ putimage((x)*30,(y)*30,tu[0],0);
putimage((x)*30,(y)*30,tu[8],0);
if (random(1000)%3==0)
map[x][y]=random(3)+5;
else
map[x][y]=0;
  return(0);
}
}/* end of for */
}/* end of ZaLine*/

/**************************************
��ը������ը�ֳ�
������Zaline()һ��
�ѱ�ը�����Ķ�����ʾ����
���ѱ�ըЧ��ͼ��ȥ 
**********************************/ 
HuanYuan(int x1,int y1,int num) 
{ 
int x,y,x2,y2,l,i,j; 
x2=ball[num].x; 
y2=ball[num].y; 
l=man[ball[num].man].power; 

for(i=0,j=0;abs(i)<l&&abs(j)<l;i+=x1,j+=y1) 
{x=x2+i;y=y2+j; 
if(x<0||x>20||y<0||y>15)return 0; 
if(map[x][y]==0) 
{ putimage((x)*30,(y)*30,tu[0],0); 
map[x][y]=0; 
}else if (map[x][y]>=5&&map[x][y]<=7) 
{ putimage(x*30,y*30,tu[0],0); 
putimage(x*30,y*30,tu[map[x][y]],0); 
}else return 0; 


} 
} 

/************************ 
 ����ZALINE() ��huanyuan()���� 
������ըЧ�� 
******************************/ 
BaoZa(int num) 
{ 
map[ball[num].x][ball[num].y]=0;/* ��ȥ��Ϸ��Ϣ�����������*/ 
man[ball[num].man].ballnum--;/* ʹ���˵ĵ�ǰ�ŵ�ը������1 */ 
ballnum--;/* ʹǰ�ŵ���ը������1 */ 
ball[num].used=0;/*ʹ���ը������ĩʹ�� */ 
/* ��ը */ 
ZaLine(-1,0,num); 
ZaLine(1,0,num); 
ZaLine(0,-1,num); 
ZaLine(0,1,num); 

delay(10000);/* ��ʱ*/ 
/*��ԭ�ֳ�*/ 

HuanYuan(-1,0,num); 
HuanYuan(1,0,num); 
HuanYuan(0,-1,num); 
HuanYuan(0,1,num); 


/*end of for */ 

} 
/*************************** 
��һ��ը�� 
����Ϊ��ը�� ���˵ı� �� 
**************************/ 

PutZaDan(int mann) 
{ 
int i; 
struct time s; 
gettime(&s);/* ȡ��ǰʱ��*/ 
if (ballnum>9 || man[mann].ballnum>=man[mann].maxball) return 0; 
/* �����ǰ��ը�� ��>9���˵ĵ�ǰ������ը����>���������ŵ�������������ִ��*/ 


ballnum++;/* ʹ��ǰ�ŵ���ը������1 */ 
man[mann].ballnum++;/* ʹ���˵ĵ�ǰ�ŵ�ը������1 */ 
for (i=0;i<10;i++) if (ball[i].used==0)break;/* �ҵ�ǰĩʹ�õ�ը�� */ 
ball[i].man=mann;/* ����ը����Ϣ*/ 
ball[i].time=s.ti_sec; 
ball[i].x=man[mann].x; 
ball[i].y=man[mann].y; 
ball[i].page=1; 
ball[i].used=1; 
 
 /* ����Ļ�Ϸ�һ��ը����λ��Ϊ�ŵ��˵�λ�� */ 
putimage(ball[i].x*30,ball[i].y*30,tu[1],0); 
map[ball[i].x][ball[i].y]=20+i; 
} 
/*********************** 
����ը���Ķ�̬��ʾ 
*************************/ 

DrawZaDan() 
{int i; 
for (i=0;i<10;i++) 
{ if (ball[i].used==0)continue;/* ���ը��ĩʹ�ü���ѭ��*/ 
if (ball[i].page<4)/* ���ը��֡��<4��֡����1��ֱ����ը��λ�÷���һ֡*/ 
{ball[i].page++; 
putimage(ball[i].x*30,ball[i].y*30,tu[ball[i].page],0); 
} 
else/* ��֡����Ϊ1����ȥԭͼ�����һ֡*/ 
{ball[i].page=1; 
putimage(ball[i].x*30,ball[i].y*30,tu[0],0); 
putimage(ball[i].x*30,ball[i].y*30,tu[1],0); 
} 
} 
} 
/***************************** 
����Ƿ��и�ը��ը�� 
������������� 
****************************/ 
CheckZaDan() 
{ 
int i,t; 
struct time t1; 
gettime(&t1); 
t=t1.ti_sec; 
for (i=0;i<10;i++) 
if (ball[i].used==1&&(t+60-ball[i].time)%60>=2&&man[ball[i].man].definetime==0) BaoZa(i); 
} 

/*********************** 
 ��ʱ������ը��  
����Ϊ�����˵ı�� 
*************************/ 
DefineZa(int n) 
{ 
int i; 
if (man[n].definetime==0) return 0; 
for (i=0;i<10;i++) 
if (ball[i].used==1&&ball[i].man==n)BaoZa(i); 

} 

/*************************** 
�����˵��ƶ�Ч�� 

���а����Զ����������ӵȹ��� 

����x1,y1Ϊ�ƶ��ķ���  
��zaline()��ͬ 
mannΪҪ�ƶ��˵ı�� 
****************************/ 


 move(int x1 ,int y1,int mann ) 
{ 
int fx ,fy,x,y;/*x,y Ϊ���ڵ�λ�ã�fx,fy,���Ҫ�ƶ�����λ��*/ 

x=man[mann].x;/*ȡҪ�ƶ��˵�λ��*/ 
y=man[mann].y; 

fx=x+x1;/*Ҫ�ƶ��� ��λ��Ϊ*/ 
fy=y+y1; 

if ((fx>=0&&fx<MX&&fy>=0&&fy<MY))/*Ҫ�ƶ�����λ���Ƿ�������Χ��*/ 

{ switch(map[fx][fy]) 
{ case 0:/*���Ҫ�ƶ�����λ��Ϊ��*/ 

putimage(x*BOXLONG,y*BOXLONG,tu[0],0); 
putimage(fx*BOXLONG,fy*BOXLONG,tu[11+mann],0); 

break; 
case 5:/*���Ҫ�ƶ�����λ��Ϊ��ʱ��*/ 
putimage(x*BOXLONG,y*BOXLONG,tu[0],0); 
putimage(fx*BOXLONG,fy*BOXLONG,tu[11+mann],0); 
man[mann].definetime=1; 
break; 
  case 6:/*���Ҫ�ƶ�����λ��Ϊ������ը��*/ 
putimage(x*BOXLONG,y*BOXLONG,tu[0],0); 
putimage(fx*BOXLONG,fy*BOXLONG,tu[11+mann],0); 
man[mann].maxball++; 
break; 

  case 7:/*���Ҫ�ƶ�����λ��Ϊ���磬��*/ 
putimage(x*BOXLONG,y*BOXLONG,tu[0],0); 
putimage(fx*BOXLONG,fy*BOXLONG,tu[11+mann],0); 
man[mann].power++; 
break; 

case 9:/*���Ҫ�ƶ�����λ��Ϊ���Ƶ����ӣ���������Ч��*/ 
 if(x+x1*2>=0&&x+x1*2<MX&&y+y1*2>=0&&y+y1*2<MY&&map[x+x1*2][y+y1*2]==0) 
{putimage((x+x1*2)*BOXLONG,(y+y1*2)*BOXLONG,tu[9],0); 
putimage((fx)*BOXLONG,(fy)*BOXLONG,tu[0],0); 
putimage((fx)*BOXLONG,(fy)*BOXLONG,tu[mann+11],0); 
putimage(x*30,y*30,tu[0],0); 
map[x+x1*2][y+y1*2]=9; 
map[fx][fy]=mann+11; 
map[x][y]=0; 

break;} 
default:return 0; 
}/* end of switch*/ 
/*�ƶ���ϣ��޸���Ļ������Ϣ*/  
map[x][y]=0; 
map[fx][fy]=11+mann; 
/*�޸��ƶ��˵���Ϣ*/ 
man[mann].x=fx; 
man[mann].y=fy; 
}/*end of if ��Χ*/ 

}/* end of funtion*/ 

GameOver() 
{ int i; 
/*�ͷ��ڴ�ռ�*/ 
for(i=0;i<13;i++) if (i!=6) free(tu[i]); 
/*�ر�ͼ����ʾģʽ*/ 
closegraph(); 
/*��������*/ 
exit(1); 
} 


main() 
{ 

int key=0,oldtime=0;/*K�������水��ֵ��oldtime������ʱ*/ 
struct time t1;/*����һ��ʱ���ͽṹ��*/ 


initgra();/*��Ļ��ʼ��*/ 
draw();/*��ͼ������ͼ��*/ 
initgame();/*��Ϸ��ʼ��*/ 


while(1) 
{if (bioskey(1)==0)/*û�а���*/ 

 { /*ÿ90�ٷ��룬���һ��ը���Ƿ񵽱�ըʱ�䣬���ػ�һ��ը����������̬Ч��*/ 

gettime(&t1); 
if(t1.ti_hund+100-oldtime>90) 

{ 
CheckZaDan(); 
DrawZaDan(); 

} 

 }else{
/*���ݰ���ֵ��ִ����Ӧ������*/

key=bioskey(0); 
switch(key) 
{case UP1: move(0,-1,0);break; 
case DOWN1: move(0,1,0);break; 
case LEFT1: move(-1,0,0);break; 
case RIGHT1:move(1,0,0);break; 
case UP2:move(0,-1,1);break; 
case DOWN2:move(0,1,1);break; 
case LEFT2:move(-1,0,1);break; 
case RIGHT2:move(1,0,1);break; 
case ENTER:PutZaDan(1);break; 
case SPACE:PutZaDan(0);break; 
case Z:DefineZa(0);break; 
case DEL:DefineZa(1);break; 
case ESC: GameOver();break; 

} 

 } 

 } 

} 
 
 
