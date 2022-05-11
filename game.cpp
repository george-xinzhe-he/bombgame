/*注意：新建一个game2.cpp：
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>
using namespace std;
char getch(){
    char buf = 0;
    termios old = { 0 };
    fflush( stdout );
    if ( tcgetattr( 0, &old ) < 0 )
    perror( "tcsetattr()" );
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if ( tcsetattr( 0, TCSANOW, &old ) < 0 )
    perror( "tcsetattr ICANON" );
    if ( read( 0, &buf, 1 ) < 0 )
    perror( "read()" );
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if ( tcsetattr( 0, TCSADRAIN, &old ) < 0 )
    perror( "tcsetattr ~ICANON" );
    return buf;
}
void printf_red(const char *s){
    printf("\033[0m\033[1;31m%s\033[0m", s);
}
void printf_green(const char *s){
    printf("\033[0m\033[1;32m%s\033[0m", s);
}
void printf_yellow(const char *s){
    printf("\033[0m\033[1;33m%s\033[0m", s);
}
void printf_blue(const char *s){
    printf("\033[0m\033[1;34m%s\033[0m", s);
}
void printf_pink(const char *s){
    printf("\033[0m\033[1;35m%s\033[0m", s);
}
void printf_cyan(const char *s){
    printf("\033[0m\033[1;36m%s\033[0m", s);
}
int main(){
	system("reset");
	char fenlei;
	printf_cyan("1:双人爽\n");
	printf_pink("2:三人耍\n");
	printf_blue("3:五人嗨\n");
	printf_yellow("4:十人聚\n");
	printf_red("5:二十玩\n");
	printf_green("6:其他\n");
	fenlei=getch();
	system("reset");
	int n;
	if(fenlei=='1'){
		n=2;
	}else if(fenlei=='2'){
		n=3;
	}else if(fenlei=='3'){
		n=5;
	}else if(fenlei=='4'){
		n=10;
	}else if(fenlei=='5'){
		n=20;
	}else if(fenlei=='6'){
		printf_green("其他请输入:");
		cin>>n;
	}
	int tmp=n;
	int a[10000];
	vector<bool> zbz(n);
	for(int i=0;i<n;i++)
		zbz[i]=true;
	vector<int> chaidan(n);
	vector<int> chakan(n);
	vector<int> fandi(n);
	vector<int> haoma(n);
	for(int i=0;i<n;i++)
		haoma[i]=i;
	for(int i=0;i<10000;i++){
		srand(time(0)+i);
		a[i]=rand()%5;
	}
	int who=0;
	int i=0;
	char command;
	cout<<"炸弹猫游戏规则："<<endl;
	cout<<"每人轮流抽牌。"<<endl;
	cout<<"白板牌：无事发生。"<<endl;
	cout<<"拆弹牌：拆除炸弹。"<<endl;
	cout<<"炸弹牌：若有拆弹牌，互相抵消，并放回	若无拆弹牌，则被淘汰。"<<endl;
	cout<<"翻底牌：将顶上的牌和底下的牌交换。"<<endl;
	cout<<"查看牌：查看牌顶的三张牌。"<<endl;
	cout<<"最后剩一人为赢家。"<<endl;
	sleep(5);
	while(1){
		system("reset");
		if(n==1){
			for(int i=0;i<tmp;i++){
				if(zbz[i]){
					printf("\033[1;43;31m                                玩家%d赢了！                                    \033[0m\n", i);
					sleep(1);
					cout<<"是否新开一局？"<<endl<<"1:YES"<<endl<<"0:NO"<<endl;
					char pd;
					pd=getch();
					int tmp=(int)pd-48;
					if(tmp)
						system("/Users/datatang/Desktop/b");
					return 0;
				}
			}
					
		}
		if(i==9999){
			cout<<"玩家";
			for(int i=0;i<n;i++){
				if(zbz[i]){
					cout<<i<<"、"<<endl;
					return 0;
				}
			}
			cout<<"\b"<<"赢了！"<<endl;
			sleep(1);
			cout<<"是否新开一局？"<<endl<<"1:YES"<<endl<<"0:NO"<<endl;
			char pd;
			pd=getch();
			int tmp=(int)pd-48;
			if(tmp)
				system("/Users/datatang/Desktop/b");
			return 0;
		}
		while(!zbz[who]){
			who++;
			if(who==n) who=0;
		}
		for(int i=0;i<tmp;i++){
			if(zbz[i])
				cout<<"玩家"<<haoma[i]<<"的拆弹牌有"<<chaidan[haoma[i]]<<"张，"<<"玩家"<<haoma[i]<<"的查看弹牌有"<<chakan[haoma[i]]<<"张，"<<"玩家"<<haoma[i]<<"的翻底牌有"<<fandi[haoma[i]]<<"张。"<<endl;
		}
		cout<<"剩余"<<n<<"个玩家。"<<endl;
		cout<<"该玩家"<<haoma[who]<<"了。"<<endl;
		cout<<"F:交换顶和底，C:查看前三张，N:翻顶牌，S:退出，Q:新开一局。"<<endl;
		char command;
		command=getch();
		if(command=='F'){
			if(fandi[haoma[who]]>0){
				swap(a[i], a[9999]);
				cout<<"完成!"<<endl;
				fandi[haoma[who]]--;
			}else{
				printf("\033[25;47;31m你没有翻底牌！\033[0m\n");
			}
			who--;
			i--;
		}else if(command=='C'){
			if(chakan[haoma[who]]>0){
				chakan[haoma[who]]--;
				cout<<"第一张是:";
				if(a[i]==0) cout<<"炸弹牌。"<<endl;
				if(a[i]==1) cout<<"拆弹牌。"<<endl;
				if(a[i]==2) cout<<"白板牌。"<<endl;
				if(a[i]==3) cout<<"查看牌。"<<endl;
				if(a[i]==4) cout<<"翻底牌。"<<endl;
				if(i+1<10000){
					cout<<"第二张是:";
					if(a[i+1]==0) cout<<"炸弹牌。"<<endl;
					if(a[i+1]==1) cout<<"拆弹牌。"<<endl;
					if(a[i+1]==2) cout<<"白板牌。"<<endl;
					if(a[i+1]==3) cout<<"查看牌。"<<endl;
					if(a[i+1]==4) cout<<"翻底牌。"<<endl;
				}
				if(i+2<10000){
					cout<<"第三张是:";
					if(a[i+2]==0) cout<<"炸弹牌。"<<endl;
					if(a[i+2]==1) cout<<"拆弹牌。"<<endl;
					if(a[i+2]==2) cout<<"白板牌。"<<endl;
					if(a[i+2]==3) cout<<"查看牌。"<<endl;
					if(a[i+2]==4) cout<<"翻底牌。"<<endl;
				}
			}else{
				printf("\033[25;47;31m你没有查看牌！\033[0m\n");
			}
			who--;
			i--;
		}else if(command=='N'){
			if(a[i]==0){
				printf("\033[5;42;31m！！！！！！！炸弹牌！！！！！！！\033[0m\n");
				sleep(3);
				if(chaidan[haoma[who]]==0){
					zbz[haoma[who]]=false;
					n--;
					cout<<"player"<<haoma[who]<<" gamed over......"<<endl;
				}else{
					chaidan[haoma[who]]--;
					cout<<"玩家"<<haoma[who]<<"幸免。"<<endl;
				}
			}else if(a[i]==1){
				cout<<"拆弹牌。"<<endl;
				chaidan[haoma[who]]++;
			}else if(a[i]==2){
				cout<<"白板牌。"<<endl;
			}else if(a[i]==3){
				cout<<"查看牌。"<<endl;
				chakan[haoma[who]]++;
			}else if(a[i]==4){
				cout<<"翻底牌。"<<endl;
				fandi[haoma[who]]++;
			}
		}else if(command=='S'){
			return 0;
		}else if(command=='Q'){
			system("/Users/datatang/Desktop/b");
			return 0;
		}else{
			cout<<"你操作了个寂寞!"<<endl;
			who--;
			i--;
		}
		i++;
		who++;
		if(who>=tmp) who=0;
		sleep(2);
	}
	return 0;
}
然后g++ -o b game2.cpp
*/
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>
using namespace std;
char getch(){
    char buf = 0;
    termios old = { 0 };
    fflush( stdout );
    if ( tcgetattr( 0, &old ) < 0 )
    perror( "tcsetattr()" );
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if ( tcsetattr( 0, TCSANOW, &old ) < 0 )
    perror( "tcsetattr ICANON" );
    if ( read( 0, &buf, 1 ) < 0 )
    perror( "read()" );
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if ( tcsetattr( 0, TCSADRAIN, &old ) < 0 )
    perror( "tcsetattr ~ICANON" );
    return buf;
}
void printf_red(const char *s){
    printf("\033[0m\033[1;31m%s\033[0m", s);
}
void printf_green(const char *s){
    printf("\033[0m\033[1;32m%s\033[0m", s);
}
void printf_yellow(const char *s){
    printf("\033[0m\033[1;33m%s\033[0m", s);
}
void printf_blue(const char *s){
    printf("\033[0m\033[1;34m%s\033[0m", s);
}
void printf_pink(const char *s){
    printf("\033[0m\033[1;35m%s\033[0m", s);
}
void printf_cyan(const char *s){
    printf("\033[0m\033[1;36m%s\033[0m", s);
}
int main(){
	system("reset");
	printf("\033[5;47;34m                       ！！！！欢迎进入炸弹猫官网！！！！                       \033[0m\n");
	sleep(2);
	system("reset");
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<"                              健康游戏忠告"<<endl;
	cout<<"                        抵制不良游戏，拒绝盗版游戏。"<<endl;
	cout<<"                        注意自我保护，谨防受骗上当。"<<endl;
	cout<<"                        适度游戏益脑，沉迷游戏伤身。"<<endl;
	cout<<"                        合理安排时间，享受健康生活。"<<endl;
	cout<<endl<<endl;
	cout<<"                               loading..."<<endl<<endl;
	cout<<"--------------------------------------------------------------------------------\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
	for(int i=0;i<80;i++){
		cout<<">"<<flush;
		usleep(1000*100);
	}
	cout<<endl;
	system("reset");
	char fenlei;
	printf_cyan("1:双人爽\n");
	printf_pink("2:三人耍\n");
	printf_blue("3:五人嗨\n");
	printf_yellow("4:十人聚\n");
	printf_red("5:二十玩\n");
	printf_green("6:其他\n");
	fenlei=getch();
	system("reset");
	int n;
	if(fenlei=='1'){
		n=2;
	}else if(fenlei=='2'){
		n=3;
	}else if(fenlei=='3'){
		n=5;
	}else if(fenlei=='4'){
		n=10;
	}else if(fenlei=='5'){
		n=20;
	}else if(fenlei=='6'){
		printf_green("其他请输入:");
		cin>>n;
	}
	int tmp=n;
	int a[10000];
	vector<bool> zbz(n);
	for(int i=0;i<n;i++)
		zbz[i]=true;
	vector<int> chaidan(n);
	vector<int> chakan(n);
	vector<int> fandi(n);
	vector<int> haoma(n);
	for(int i=0;i<n;i++)
		haoma[i]=i;
	for(int i=0;i<10000;i++){
		srand(time(0)+i);
		a[i]=rand()%5;
	}
	int who=0;
	int i=0;
	char command;
	cout<<"炸弹猫游戏规则："<<endl;
	cout<<"每人轮流抽牌。"<<endl;
	cout<<"白板牌：无事发生。"<<endl;
	cout<<"拆弹牌：拆除炸弹。"<<endl;
	cout<<"炸弹牌：若有拆弹牌，互相抵消，并放回	若无拆弹牌，则被淘汰。"<<endl;
	cout<<"翻底牌：将顶上的牌和底下的牌交换。"<<endl;
	cout<<"查看牌：查看牌顶的三张牌。"<<endl;
	cout<<"最后剩一人为赢家。"<<endl;
	sleep(5);
	while(1){
		system("reset");
		if(n==1){
			for(int i=0;i<tmp;i++){
				if(zbz[i]){
					printf("\033[1;43;31m                                 玩家%d赢了！                                    \033[0m\n", i);
					sleep(1);
					cout<<"是否新开一局？"<<endl<<"1:YES"<<endl<<"0:NO"<<endl;
					char pd;
					pd=getch();
					int tmp=(int)pd-48;
					if(tmp)
						system("/Users/datatang/Desktop/b");
					return 0;
				}
			}
					
		}
		if(i==9999){
			cout<<"玩家";
			for(int i=0;i<n;i++){
				if(zbz[i]){
					cout<<i<<"、"<<endl;
					return 0;
				}
			}
			cout<<"\b"<<"赢了！"<<endl;
			sleep(1);
			cout<<"是否新开一局？"<<endl<<"1:YES"<<endl<<"0:NO"<<endl;
			char pd;
			pd=getch();
			int tmp=(int)pd-48;
			if(tmp)
				system("/Users/datatang/Desktop/b");
			return 0;
		}
		while(!zbz[who]){
			who++;
			if(who==tmp) who=0;
		}
		for(int i=0;i<tmp;i++){
			if(zbz[i])
				cout<<"玩家"<<haoma[i]<<"的拆弹牌有"<<chaidan[haoma[i]]<<"张，"<<"玩家"<<haoma[i]<<"的查看弹牌有"<<chakan[haoma[i]]<<"张，"<<"玩家"<<haoma[i]<<"的翻底牌有"<<fandi[haoma[i]]<<"张。"<<endl;
		}
		cout<<"剩余"<<n<<"个玩家。"<<endl;
		cout<<"该玩家"<<haoma[who]<<"了。"<<endl;
		cout<<"F:交换顶和底，C:查看前三张，N:翻顶牌，S:退出，Q:新开一局。"<<endl;
		char command;
		command=getch();
		if(command=='F'){
			if(fandi[haoma[who]]>0){
				swap(a[i], a[9999]);
				cout<<"完成!"<<endl;
				fandi[haoma[who]]--;
			}else{
				printf("\033[25;47;31m你没有翻底牌！\033[0m\n");
			}
			who--;
			i--;
		}else if(command=='C'){
			if(chakan[haoma[who]]>0){
				chakan[haoma[who]]--;
				cout<<"第一张是:";
				if(a[i]==0) cout<<"炸弹牌。"<<endl;
				if(a[i]==1) cout<<"拆弹牌。"<<endl;
				if(a[i]==2) cout<<"白板牌。"<<endl;
				if(a[i]==3) cout<<"查看牌。"<<endl;
				if(a[i]==4) cout<<"翻底牌。"<<endl;
				if(i+1<10000){
					cout<<"第二张是:";
					if(a[i+1]==0) cout<<"炸弹牌。"<<endl;
					if(a[i+1]==1) cout<<"拆弹牌。"<<endl;
					if(a[i+1]==2) cout<<"白板牌。"<<endl;
					if(a[i+1]==3) cout<<"查看牌。"<<endl;
					if(a[i+1]==4) cout<<"翻底牌。"<<endl;
				}
				if(i+2<10000){
					cout<<"第三张是:";
					if(a[i+2]==0) cout<<"炸弹牌。"<<endl;
					if(a[i+2]==1) cout<<"拆弹牌。"<<endl;
					if(a[i+2]==2) cout<<"白板牌。"<<endl;
					if(a[i+2]==3) cout<<"查看牌。"<<endl;
					if(a[i+2]==4) cout<<"翻底牌。"<<endl;
				}
			}else{
				printf("\033[25;47;31m你没有查看牌！\033[0m\n");
			}
			who--;
			i--;
		}else if(command=='N'){
			if(a[i]==0){
				printf("\033[5;42;31m！！！！！！！炸弹牌！！！！！！！\033[0m\n");
				sleep(3);
				if(chaidan[haoma[who]]==0){
					zbz[haoma[who]]=false;
					n--;
					cout<<"player"<<haoma[who]<<" gamed over......"<<endl;
				}else{
					chaidan[haoma[who]]--;
					cout<<"玩家"<<haoma[who]<<"幸免。"<<endl;
				}
			}else if(a[i]==1){
				cout<<"拆弹牌。"<<endl;
				chaidan[haoma[who]]++;
			}else if(a[i]==2){
				cout<<"白板牌。"<<endl;
			}else if(a[i]==3){
				cout<<"查看牌。"<<endl;
				chakan[haoma[who]]++;
			}else if(a[i]==4){
				cout<<"翻底牌。"<<endl;
				fandi[haoma[who]]++;
			}
		}else if(command=='S'){
			return 0;
		}else if(command=='Q'){
			system("/Users/datatang/Desktop/b");
			return 0;
		}else{
			cout<<"你操作了个寂寞!"<<endl;
			who--;
			i--;
		}
		i++;
		who++;
		if(who>=tmp) who=0;
		sleep(2);
	}
	return 0;
}