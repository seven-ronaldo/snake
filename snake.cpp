#include <stdio.h>
#include <windows.h>
enum state{
	MENU = 0, INGAME, SETTING, GUIDING, INFORMATION, GAMEOVER
} state;
void addscore(){
	SetColor(14);
	gotoxy(79,9); 
	printf("%d",(score%100000)/10000);
 	gotoxy(79,10);
 	printf("%d",(score%10000)/1000);
 	gotoxy(79,11);
 	printf("%d",(score%1000)/100);
 	gotoxy(79,12);
 	printf("%d",(score%100)/10);
 	gotoxy(79,13);
 	printf("%d",score%10);
}
void ingame()
int main(){
	state = MENU;
    menu();
    while(1){
	switch (state){
		case MENU : 
		     menu();
		     break;
		case INGAME :
			ingame();
			break;
		case GAMEOVER : 
		     gameover();
		     break;
		case INFORMATION :
			 information();
			 break;
		case SETTING:
			 setting();
			 break;} 
   }
}
