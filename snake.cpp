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
void ingame(){
	int key;
	int i;
	initgame();
 	vekhung();
 	drawscore();
 	state = INGAME;
 	SetColor(13);
 	gotoxy(getx(fruit),gety(fruit));
 	printf("O");
 	SetColor(12);
 	gotoxy(getx(character[0]),gety(character[0]));
	printf("#");
	i = 1;
	SetColor(2);
 	for(i;i<length;i++){
		gotoxy(getx(character[i]),gety(character[i]));
		printf("o");}
	while(state == INGAME){
	if(kbhit()){
			key = getch();
			switch (key) {
				//nut len
				case 72:
					if(vy == 0){
						vx = 0;
						vy = -1;}
					break;
					//nut xuong
				case 80:
					if(vy == 0){
						vx = 0;
						vy = 1;}
					break;
					//nut trai
				case 75:
					if(vx == 0){
						vy = 0;
						vx = -1;}
					break;
					// nut phai
				case 77:
					if(vx == 0){
						vy = 0;
						vx = 1;}
					break;		}						     
	}	
	if((clock()-t)>=s_e){
			if(character[length-1]!=0){			
			gotoxy(getx(character[length-1]),gety(character[length-1]));
			printf(" ");}
			i =length-1;
			for(i;i>0;i--){
			  character[i]=character[i-1];}
			SetColor(2);
			gotoxy(getx(character[0]),gety(character[0]));
			printf("o");
		    character[0] += vx*100;
		    character[0] += vy;	
		    if(character[0] == fruit){
		    	length+= 1;
		    	score += (speed/10 + 5);
		    	addscore();
		    	creatfruit();
		    	SetColor(13);
		    	gotoxy(getx(fruit),gety(fruit));
 	            printf("O");}
			if((vx>0)&&(getx(character[0])==78)){
				character[0]-=7700;}    
			if((vx<0)&&(getx(character[0])==0)){
				character[0]+=7700;}  
			if((vy>0)&&(gety(character[0])==24)){
				character[0]-=23;}   
			if((vy<0)&&(gety(character[0])==0)){
				character[0]+=23;}   
			SetColor(12);
			gotoxy(getx(character[0]),gety(character[0]));
				printf("#");
			i = 1;
			for(i;i<length;i++){
				if(character[i]==character[0]){
					system("cls");					
					state = GAMEOVER;}
			}  
		   t = clock();  		    
		}	
	}	
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
