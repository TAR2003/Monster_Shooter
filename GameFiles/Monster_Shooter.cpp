# include "iGraphics.h"
#include <iostream>
#include<sstream>
#include<string.h>
#include<conio.h>
#include<cmath>
#include<windows.h>

int main();
int pic_x=100, pic_y=10,jhu=0;
static int timingbomb=0,bombini=0,kio=0,guard=0,bulletmode=0,guardtime=0,supertimer=0,tik=0;
int ball_x=300, ball_y=300,bomb_x=900,bomb_y=350,fighterside=-1,bulletside=1,rconstant=1,bside=1,coli=0;
int dx, dy;
int a=0,b,c,d,e,f,t,bombi=0,randome=0;
int losing=0,lineflick=0;
static int j=0,jiko=0,losss=0,kl=0,i;
float dbx=2,dby=1;
int mode,m=0;
int opening=0,monster=0,mon_x=500,mon_y=621,monslide=1,bombstate=0,bombnumber=0,explo=0,bombtik=0;
int tmode=1;
static int score=0,ly=0,lx=0,gru=0;
int bullet_x=300, bullet_y=300,ex=0,supexit=0;
int heart_x=500,heart_y=550,heart=5,z=0;
int moncx=0,moncy=1;
int level=1,jir=0,picheight=0;
int fightA=0,dpyi=0,bombA=2,bombvx=-2,bombvy=7,bombcount=0;
char pl1[100],pl2[100],pl3[100],pl4[100],pl5[100],instantname[100];
int h1,h2,h3,h4,h5;
int highscoresetting=0;
char str558[100],str2558[100],strongstring[100];
int hmode,len=0,highpos=0;
int hp1=0,hp2=-600,hp3=-1300,hp4=-1800,hp5=-2400,hty=0;
bool musicOn = true;
bool thememusic = true;
bool lt = true;
int musica = 0;
POINT p;
int instruction = 0;
struct point
{
    int x=900;
    int y=470;
} musiclogo;
int credit=0;

void tir();
void highscore();
void newhighscore();

void iDraw()
{
    iClear();
    if(musicOn)
    {
    }
    else
    {
        if(musica==0)
        {
            PlaySound("click.wav", NULL, SND_ASYNC);
            musica=1;//musica is used to generate click sound for one time after one time it will be 1 there wont be overlaping sound of music

        }
    }


    if(thememusic)
    {
        if(opening==0)
        {
            if(musicOn)
                PlaySound("theme.wav", NULL, SND_ASYNC|SND_LOOP);
            thememusic=false;//after one time there wont be overlaping sound of theme music
        }//thememusic is bool which is true when theme song is needed to play
    }
    if(opening>0)
    {
        thememusic = true;//first time theme music will continue
    }//if opening is 0 that means it is in the menu page if it is 1 then it has gone past menu page
    if(credit==1)
    {
        iShowBMP(0, 0, "creditpage.bmp");//show the creditpage
    }
    else
    {
        if(instruction==1)
        {
            iShowBMP(0, 0, "instructions.bmp");
        }//instruction = 1 tell us that user want to know instructions so instructions page will be opened
        else if(instruction==0)
        {
            if(m==1)
            {
                //m=1 means that paused screen
                if(tmode==0)
                {
                    {
                        iShowBMP(0, 0, "pause.bmp");
                    }// m=1 and tmode=0 indicate it is in pause state so pause page will be shown

                    iShowBMP2(300, 50, "backto.bmp",0x00ffffff);//it shows back to main menu option in the pause page

                }
            }
            else
            {
                if(highscoresetting==1)
                {
                    //highscoresettings=1 indicates that user wants to know highscores so highscore page will be shown
                    highscore();
                    //highscore function is called to get the names and scores of the high scorers
                    //pl1-5 stores names and h1-5 stores there scores respectively
                    iShowBMP(0, 0, "highscorebg.bmp");
                    //the position of the moving scores depends on the values of hp1-5 1st will arrive at 1st, followed by others one by one
                    iSetColor(255, 255, 255);
                    iText(255, 450,"1st.", GLUT_BITMAP_TIMES_ROMAN_24);
                    iText(600-hp1, 450, pl1, GLUT_BITMAP_TIMES_ROMAN_24);
                    iText(900-hp1, 450, "----->", GLUT_BITMAP_TIMES_ROMAN_24);
                    int i= h1;//converting number to string
                    char str[100];
                    itoa(i, str, 10);
                    iText(1000-hp1, 450, str, GLUT_BITMAP_TIMES_ROMAN_24);
                    iSetColor(0, 255, 0);
                    iText(255, 350,"2nd.", GLUT_BITMAP_TIMES_ROMAN_24);
                    iText(600-hp2, 350, pl2, GLUT_BITMAP_TIMES_ROMAN_24);
                    iText(900-hp2, 350, "----->", GLUT_BITMAP_TIMES_ROMAN_24);
                    i= h2;
                    itoa(i, str, 10);
                    iText(1000-hp2, 350, str, GLUT_BITMAP_TIMES_ROMAN_24);
                    iSetColor(0, 255, 255);
                    iText(255, 250,"3rd.", GLUT_BITMAP_TIMES_ROMAN_24);
                    iText(600-hp3, 250, pl3, GLUT_BITMAP_TIMES_ROMAN_24);
                    iText(900-hp3, 250, "----->", GLUT_BITMAP_TIMES_ROMAN_24);
                    i= h3;
                    itoa(i, str, 10);
                    iText(1000-hp3, 250, str, GLUT_BITMAP_TIMES_ROMAN_24);
                    iSetColor(255, 0, 255);
                    iText(255, 150,"4th.", GLUT_BITMAP_TIMES_ROMAN_24);
                    iText(600-hp4, 150, pl4, GLUT_BITMAP_TIMES_ROMAN_24);
                    iText(900-hp4, 150, "----->", GLUT_BITMAP_TIMES_ROMAN_24);
                    i= h4;
                    itoa(i, str, 10);
                    iText(1000-hp4, 150, str, GLUT_BITMAP_TIMES_ROMAN_24);
                    iSetColor(255, 255, 0);
                    iText(255, 50,"5th.", GLUT_BITMAP_TIMES_ROMAN_24);
                    iText(600-hp5, 50, pl5, GLUT_BITMAP_TIMES_ROMAN_24);
                    iText(900-hp5, 50, "----->", GLUT_BITMAP_TIMES_ROMAN_24);
                    i= h5;
                    itoa(i, str, 10);
                    iText(1000-hp5, 50, str, GLUT_BITMAP_TIMES_ROMAN_24);
                    i=hp1;
                    if(hp1<300)
                        hp1+=4;
                    if(hp2<300)
                        hp2+=4;
                    if(hp3<300)
                        hp3+=4;
                    if(hp4<300)
                        hp4+=4;
                    if(hp5<300)
                        hp5+=4;
                    // when they arrive at there desired position, they will stop moving

                }
                else
                {
                    if(heart==0)
                    {
                        //heart 0 indicates that user has no lifes left, so game is over
                        iClear();
                        if(jiko<800)
                        {
                            if(jiko==60)
                                if(musicOn)   PlaySound("bombsound.wav",NULL,SND_ASYNC);
                            //jiko is frame count
                            //jiko is a simple variable designed to show 13 pictures blasting one by one
                            // the more the value of jiko would be the slower the pictures will be shown

                            if(jiko<61)
                                iShowBMP2(300, 200, "im1.bmp",0x00000000);
                            else if(jiko<123)
                                iShowBMP2(300, 200, "im2.bmp",0x00000000);
                            else if(jiko<183)
                                iShowBMP2(300, 200, "im3.bmp",0x00000000);
                            else if(jiko<247)
                                iShowBMP2(300, 200, "im4.bmp",0x00000000);
                            else if(jiko<304)
                                iShowBMP2(300, 200, "im5.bmp",0x00000000);
                            else if(jiko<366)
                                iShowBMP2(300,200, "im6.bmp",0x00000000);
                            else if(jiko<427)
                                iShowBMP2(300,200, "im7.bmp",0x00000000);
                            else if(jiko<487)
                                iShowBMP2(300, 200, "im8.bmp",0x00000000);
                            else if(jiko<547)
                                iShowBMP2(300, 200, "im9.bmp",0x00000000);
                            else if(jiko<610)
                                iShowBMP2(300, 200, "im10.bmp",0x00000000);
                            else if(jiko<670)
                                iShowBMP2(300, 200, "im11.bmp",0x00000000);
                            else if(jiko<730)
                                iShowBMP2(300, 200, "im12.bmp",0x00000000);
                            else if(jiko<800)
                                iShowBMP2(300, 200, "im13.bmp",0x00000000);
                            kl=1;
                            jiko++;
                            //kl=1 indiactes that now it is showing explosion sequence to the user

                        }

                        if(jiko==800)
                        {
                            jiko=0;
                            losss=2;
                            //after showing explosion sequence jiko is 0 for future use
                            //now it is the time to input users name
                            char str[5];
                            iSetColor(255, 255, 255);
                            int i= score;
                            itoa(i, str, 10);
                            iText(292, 522, str, GLUT_BITMAP_TIMES_ROMAN_24);
                            if(kl==1||kl==2)
                            {
                                iSetColor(255, 255, 255);
                                iShowBMP(0, 0, "lost.bmp");
                                iText(300, 290, "YOUR SCORE IS = ", GLUT_BITMAP_TIMES_ROMAN_24);
                                iText(515, 290, str, GLUT_BITMAP_TIMES_ROMAN_24);

                                if(kl==2)
                                {
                                    //now, kl=2 indicates we are on our final screen
                                    //score will be shown with the name
                                    if(score>h1)
                                        iShowBMP2(picheight, 180, "newhighscore.bmp",0x00ffffff);
                                    // if it the new high score then newhighscore sign will be shown
                                    iSetColor(0, 255, 255);
                                    iText(300, 255, "Your name :", GLUT_BITMAP_TIMES_ROMAN_24);
                                    iText(450, 255, instantname, GLUT_BITMAP_TIMES_ROMAN_24);
                                    iText(420, 40, "PRESS END TO EXIT", GLUT_BITMAP_8_BY_13);
                                    iShowBMP2(200, 100, "lastscreen.bmp",0x00ffffff);


                                    if(picheight<820)
                                    {
                                        picheight+=10;
                                    }
                                    newhighscore();//it is time to enter new data from this game to our highscore files
                                }
                                if(kl==1)
                                {
                                    iSetColor(0, 255, 0);
                                    iRectangle(150, 140, 450, 50);//it is the box where input will be taken and shown to the user
                                    iSetColor(0, 255, 0);
                                    iText(155, 160, str558,GLUT_BITMAP_TIMES_ROMAN_24);//here user will immediately see his/her name after entering every charachter
                                    if(lineflick==50)
                                    {
                                        if(musicOn)
                                            PlaySound("string.wav", NULL, SND_ASYNC|SND_LOOP);
                                        //we used lineflick for another different reason to playsound for only one time to avoid noise
                                    }
                                    if(lineflick%120>60)
                                    {
                                        iSetColor(0, 255, 0);
                                        iLine(155+(len*11),145,155+(len*11),183);
                                    }
                                    lineflick++;
                                    //lineflick is used for the flicking effect of text cursor
                                }
                            }
                            jiko=800;
                        }
                    }

                    else
                    {

                        if(opening==0)
                        {
                            iClear();
                            iShowBMP(0, 0, "theme.bmp");
                            //opening=0 indicate we are on opening screen so theme screen will be shown
                            if(musicOn)
                                iShowBMP2(musiclogo.x, musiclogo.y, "musiclogo.bmp",0x00ffffff);//if music is on on logo will be shown
                            else
                                iShowBMP2(musiclogo.x, musiclogo.y, "musicnotlogo.bmp",0x00ffffff);//if music is off off logo will be shown
                            iShowBMP2(800, 0, "instructionsinhome.bmp",0x00ffffff);//this shows the button of instruction in menu page
                            iShowBMP2(800, 75, "credit.bmp",0x00ffffff);
                        }


                        if(opening!=0)
                        {

                            //opening != 0 indicates that we have come past the opening page
                            if(tmode!=0)
                            {
                                //tmode!=0 means the game is not in the pause state
                                iClear();
                                if(score<10)
                                    iShowBMP(0, 0, "BACKGROUND.bmp");
                                if(score>=10 && score<20)
                                    iShowBMP(0, 0, "BACKGROUND2.bmp");
                                if(score>=20)
                                    iShowBMP(0, 0, "BACKGROUND31.bmp");
                                //three different backgrounds for three different levels
                                if(pic_y<0)
                                    pic_y=0;
                                //fighterslide is a variable that indicates whether fighter goal will be right or left
                                if(fighterside==1)
                                {
                                    iShowBMP2(pic_x, pic_y, "fi.bmp",0x00ffffff);//show fighter headed at right
                                }
                                else
                                {
                                    iShowBMP2(pic_x, pic_y, "fi3.bmp",0x00ffffff);//headed at left
                                }
                                //pic_x and pic_y are the positions of the fighter
                                if(guard==1)
                                {
                                    //guard = 1 indicates that guard is on so guard will be shown around the fighter
                                    iShowBMP2(pic_x-20, pic_y-0, "guard.bmp",0x00ffffff);
                                    guardtime++;//guard will only be available for 4 seconds
                                    //guardtime is frame count
                                    if(guardtime>400)
                                    {
                                        guardtime=0;
                                        guard=0;//after 4 seconds guard will be down so guard =0
                                    }
                                }
                                iSetColor(155, 185, 255);
                                iText(10, 10, "Use cursors to move the fighter.");
                                iText(500, 10, "PRESS SPACE KEY TO SHOOT");
                                char str[5];
                                int i= score;//converting score number to string to show
                                itoa(i, str, 10);
                                iSetColor(255, 255, 255);
                                iText(242, 559, str, GLUT_BITMAP_TIMES_ROMAN_24);

                                if(score>h1)
                                {
                                    // if it is the highest score than the score will also be shown in highscore
                                    iText(282, 519, str, GLUT_BITMAP_TIMES_ROMAN_24);
                                    if(lineflick%120>60)
                                    {
                                        iSetColor(0,255, 0);
                                        iText(100, 409, "HIGHEST SCORE",GLUT_BITMAP_TIMES_ROMAN_24);
                                    }
                                    if(lineflick==1)
                                        if(musicOn)
                                            PlaySound("celebrate.wav",NULL,SND_ASYNC);

                                    lineflick++;
                                }
                                else
                                {
                                    i= h1;
                                    itoa(i, str, 10);//converting highscore to string
                                    iSetColor(255, 255, 255);
                                    iText(282, 519, str, GLUT_BITMAP_TIMES_ROMAN_24);
                                    //it will show highscore
                                }
                                if(monster==0)
                                {
                                    //monster =0 indicates that monster is active
                                    d = mon_x - ball_x + 80;
                                    e = mon_y - ball_y + 10;
                                    //d indicates the difference between the bullet and monster
                                    //mon_x and mon_y are the positions of the monster
                                    if(mon_y<70)
                                    {
                                        if(heart>0)
                                        {
                                            heart = heart - 1;//if monster touches the ground one life will be lost heart is life
                                            mon_x=500;
                                            mon_y=621;//monster will be set at the initial position
                                        }
                                        if(heart==0)
                                            heart=0;

                                    }

                                    else if(d>110||d<-110||e<-50||e>50)
                                    {
                                        iShowBMP2(mon_x, mon_y, "monet.bmp",0x00ffffff);
                                        //if life is left monster will be shown
                                    }


                                    else
                                    {
                                        //now this means bullet has touched the monster so score will increse by 1
                                        monster = 0;
                                        lx = mon_x;
                                        ly = mon_y;
                                        if((score+5-heart)%3==0)
                                            monslide=-1;//monslide determines the slope of the monster movement
                                        else
                                            monslide=1;
                                        if(score%2==0)
                                        {
                                            mon_x=1000 - mon_x - score*100;// it is an algorithm to generate new position of the monster
                                            if(mon_x<100)
                                                mon_x=350;
                                            mon_y=601;
                                        }
                                        else
                                        {
                                            mon_x=500;
                                            mon_y=601;
                                        }
                                        score++;
                                        ball_x = 1000;//we will also set the bullet to another position until another bullet call is arrived
                                        ball_y = 601;
                                        bombi=1;//that calls the explosion sequence to began
                                    }
                                }
                                if(heart>0)
                                {
                                    z = 0;
                                    //shows the remaining lifes with some logos of heart
                                    iSetColor(255, 0, 0);
                                    iText(380, 565, "HEALTH : ", GLUT_BITMAP_TIMES_ROMAN_24);
                                    for(z=0; z<heart; z++)
                                    {
                                        iShowBMP2(heart_x + (z*60), heart_y, "heart.bmp",0x00ffffff);
                                    }


                                }
                                else
                                {
                                    losss=1;//heart 0 means loss
                                }

                                if(bulletmode==1)
                                {

                                    //bulletmode = 1 indicated that bullet has been called
                                    //bulletside also depends on the direction fighter is headed
                                    //bulletside determines the slope of the moving bullet
                                    if(bulletside==1)
                                        iShowBMP2(ball_x+50, ball_y+85, "bullet.bmp",0x00ffffff);
                                    else
                                        iShowBMP2(ball_x+50, ball_y+85, "bullet2.bmp",0x00ffffff);

                                }
                            }
                            if(guard==1)
                                iShowBMP2(780, 300, "guardon.bmp",0x00ffffff);//this show the guard button in screen is on
                            if(guard==0)
                                iShowBMP2(783, 310, "guardoff.bmp",0x00ffffff);//this show the guard button in screen is off
                            iText(800, 295, "CLICK HERE TO  ", GLUT_BITMAP_TIMES_ROMAN_24);
                            iText(825, 270, "GUARD UP ", GLUT_BITMAP_TIMES_ROMAN_24);
                            char random[12];
                            int randome= 4  - ((guardtime)/100);//this shows remaining guardtime
                            itoa(randome, random, 10);
                            if(guard==1)
                            {
                                iText(805, 240,"Time left:", GLUT_BITMAP_TIMES_ROMAN_24);
                                iText(905, 240, random, GLUT_BITMAP_TIMES_ROMAN_24);
                            }
                            if(supertimer%16==0&&tik==0&&supertimer>0)/*&&supertimer>0)*/
                            {
                                bombstate=1;//bombstate = 1 indicates that the bomb is now active
                                bombtik=0;//bombtik calculate the number of frames after the activation of bomb, later it is used to set time
                                coli =0;//how many times the bomb has hit the ground
                                bombcount++;//how many bombs have arrived total
                                if(bombcount%2==0)
                                {
                                    bside=1;//slope of the bomb
                                    bomb_x=900;
                                    bombvx=-2;
                                }
                                else
                                {
                                    bside=-1;
                                    bomb_x=100;
                                    bombvx=2;
                                }
                                //after every bomb the slope and initial position of the moving bomb is changed
                                //odd number of bombs come from left side, at even position bombs come from right side
                            }
                            if(bombstate==1)
                            {
                                iShowBMP2(bomb_x,bomb_y, "bom.bmp",0x00ffffff);
                                //if bomb is active it is showing the bomb

                                if(j==7)
                                {
                                    bombvy=bombvy-1;
                                    j=0;
                                }//here j is used only to slow down the accelaration
                                //after every 7 frames the speed will increase by 1 frame
                                bomb_x=bomb_x+bombvx;
                                bomb_y+=bombvy;
                                //those are the function for the increment of the velocity of the bomb
                                //these are done to make the fall similar to projectile equation

                                j++;
                                if(bomb_y<5)
                                {
                                    bombvy = (bombvy*4/10) - bombvy;
                                    // bow when the bomb hit the ground it will bounce back up
                                    //but it will lose energy so the after velocity will be less that the first velocity
                                    bomb_y=7;
                                    bombvx=(-1)*bside;
                                    coli++;
                                    //after a bounce colision will increase by  one
                                }
                            }
                            if(coli>3)
                            {
                                //when the bomb is bounced 3 times then it will start the procedure of exploding
                                bombstate=0;
                                if(bombtik<50)
                                {
                                    iShowBMP2(bomb_x,bomb_y, "bom.bmp",0x00ffffff);
                                    if(bombtik>25)
                                        iShowBMP2(bomb_x+30,bomb_y+50, "smoke.bmp",0x00000000);//show the smoke before blasting
                                }

                                else if(bombtik<125)
                                {
                                    if(bombtik==51)
                                        if(musicOn)   PlaySound("bombsound.wav",NULL,SND_ASYNC);//sound of the exploding bomb
                                    if(bombtik==100)
                                        if(musicOn)   PlaySound("bombsound.wav",NULL,SND_ASYNC);
                                    if(bombtik<56)
                                        iShowBMP2(bomb_x, bomb_y, "im1.bmp",0x00000000);
                                    else if(bombtik<62)
                                        iShowBMP2(bomb_x, bomb_y, "im2.bmp",0x00000000);
                                    else if(bombtik<67)
                                        iShowBMP2(bomb_x, bomb_y, "im3.bmp",0x00000000);
                                    else if(bombtik<73)
                                        iShowBMP2(bomb_x, bomb_y, "im4.bmp",0x00000000);
                                    else if(bombtik<79)
                                        iShowBMP2(bomb_x, bomb_y, "im5.bmp",0x00000000);
                                    else if(bombtik<84)
                                        iShowBMP2(bomb_x, bomb_y, "im6.bmp",0x00000000);
                                    else if(bombtik<90)
                                        iShowBMP2(bomb_x,bomb_y, "im7.bmp",0x00000000);
                                    else if(bombtik<96)
                                        iShowBMP2(bomb_x, bomb_y, "im8.bmp",0x00000000);
                                    else if(bombtik<101)
                                        iShowBMP2(bomb_x,bomb_y, "im9.bmp",0x00000000);
                                    else if(bombtik<107)
                                        iShowBMP2(bomb_x, bomb_y, "im10.bmp",0x00000000);
                                    else if(bombtik<113)
                                        iShowBMP2(bomb_x, bomb_y, "im11.bmp",0x00000000);
                                    else if(bombtik<119)
                                        iShowBMP2(bomb_x, bomb_y, "im12.bmp",0x00000000);
                                    else if(bombtik<125)
                                        iShowBMP2(bomb_x, bomb_y, "im13.bmp",0x00000000);
                                    //here bombtik is simple variable to count the number of frames after starting the explosion sequence
                                    //the speed of the sequence depends on how we relate them with frame count bombtik

                                }

                                if(bombtik>=125)
                                {
                                    j=0;
                                    bomb_x=900;
                                    bomb_y=301;
                                    bombvy=7;
                                    //after the sequence we set them at their initial position

                                }
                                bombtik++;
                            }

                            if(bombtik>25&&bombtik<125&&guard==0)
                                explo=1;//defines if guard was off in the time period of explosion explo = 1 call to start the explsion sequence

                            if(explo==1&&bombtik>=125)
                                heart=0;//without guard the bomb explosion end the game so heart becomes 0
                            if(score%10!=0)
                                kio=0;
                            if(score>=10&&kio==0&&score>0)
                            {
                                //here jhu is only used to design the filckering effect on level up text
                                //jhu is actually a frame count after score is ==10
                                if((jhu%100)>=50)
                                    iText(380, 465, "LEVEL UP -->>>", GLUT_BITMAP_TIMES_ROMAN_24);
                                if(jhu==500)
                                {

                                    jhu=0;//after the work is done we set jhu to 0

                                }
                                jhu++;

                            }
                            if(score%10==0&&score>0&&kio==0)
                            {
                                supexit=1;
                                // score is 10 means level up
                                if(score>0)
                                {
                                    if(musicOn)
                                        PlaySound("celebrate.wav",NULL,SND_ASYNC);//playing the level up celebration sound

                                }
                                kio=1;//it is used to play celebrate sound for omly one time to avoid noise
                                tir();//calling the tir function which will change the level

                            }

                            if(bombi!=0)
                            {
                                //bombi !=0 so, the bomb is about to explode
                                if(jir==1)
                                    if(musicOn)
                                        PlaySound("bombsound.wav",NULL,SND_ASYNC);//play bombsound
                                if(jir<26)
                                {
                                    //start of explosion sequence
                                    //here jir  is simple variable which is frame count after explosion so the picture s time depends on them
                                    if(jir<2)
                                        iShowBMP2(lx-100, ly-100, "im1.bmp",0x00000000);
                                    else if(jir<4)
                                        iShowBMP2(lx-100, ly-100, "im2.bmp",0x00000000);
                                    else if(jir<6)
                                        iShowBMP2(lx-100, ly-100, "im3.bmp",0x00000000);
                                    else if(jir<8)
                                        iShowBMP2(lx-100, ly-100, "im4.bmp",0x00000000);
                                    else if(jir<10)
                                        iShowBMP2(lx-100, ly-100, "im5.bmp",0x00000000);
                                    else if(jir<12)
                                        iShowBMP2(lx-100, ly-100, "im6.bmp",0x00000000);
                                    else if(jir<14)
                                        iShowBMP2(lx-100,ly - 100, "im7.bmp",0x00000000);
                                    else if(jir<16)
                                        iShowBMP2(lx-100, ly-100, "im8.bmp",0x00000000);
                                    else if(jir<18)
                                        iShowBMP2(lx-100,ly - 100, "im9.bmp",0x00000000);
                                    else if(jir<20)
                                        iShowBMP2(lx-100, ly - 100, "im10.bmp",0x00000000);
                                    else if(jir<22)
                                        iShowBMP2(lx-100, ly-100, "im11.bmp",0x00000000);
                                    else if(jir<24)
                                        iShowBMP2(lx-100, ly-100, "im12.bmp",0x00000000);
                                    else if(jir<26)
                                        iShowBMP2(lx-100, ly-100, "im13.bmp",0x00000000);
                                    jir++;
                                }
                                if(jir>=26)
                                {
                                    jir=0;
                                    bombi=0;
                                    //after the whole explosion sequence is finished jir the frame count and bombi is set to 0
                                }
                            }
                            if(tmode!=0)
                            {
                                //here is the code for showing time in the screen
                                char str23[43];
                                char str24[43];
                                itoa(supertimer, str23, 10);//converting supertimer to string
                                itoa(tik, str24, 10);//converting tik to string
                                iSetColor(0, 250, 250);
                                iText(10, 465, "TIME : ", GLUT_BITMAP_TIMES_ROMAN_24);
                                iText(100, 465, str23, GLUT_BITMAP_TIMES_ROMAN_24);
                                iText(125, 465, " . ", GLUT_BITMAP_TIMES_ROMAN_24);
                                iText(150, 465,str24, GLUT_BITMAP_TIMES_ROMAN_24);
                                tik++;//tik is always increasing by every frame
                            }
                            if(tik==100)
                            {
                                supertimer++;//it is increased by 1 after every 100 tik or frame
                                tik=0;//after each hundred tik is set to be 0
                            }
                            iSetColor(255, 0, 255);
                            //here are the codes for showing the level user is currently playing
                            if(score<10)
                                iText(10, 105, "LEVEL 1 : ", GLUT_BITMAP_TIMES_ROMAN_24);
                            else if(score<20)
                                iText(10, 105, "LEVEL 2 : ", GLUT_BITMAP_TIMES_ROMAN_24);
                            else if(score<30)
                                iText(10, 105, "LEVEL 3 : ", GLUT_BITMAP_TIMES_ROMAN_24);
                            else if(score>=30)
                                iText(10, 105, "TOP LEVEL ", GLUT_BITMAP_TIMES_ROMAN_24);

                            if((tik==0||tik==99)&&supertimer%16==0)
                            {
                                if(supertimer>0)
                                    if(musicOn)   PlaySound("siren.wav", NULL, SND_ASYNC|SND_LOOP);
                                //siren is played before the arrival of a bomb to alert the player

                            }
                            if(mon_y<450&&mon_y>447)
                                if(musicOn)   PlaySound("monshout.wav", NULL, SND_ASYNC|SND_LOOP);
                            //the shout of the monster is played when monster reach closer to the ground
                        }
                    }
                    if(ball_y>560)
                    {
                        bulletmode=0;//when bullet is out of the screen bulletmode is 0 declaring bullet is not active
                    }
                    if(bulletmode==0)
                        bulletside=fighterside;//bullet's direction is the same as the fighter's direction
                    if(pic_y>0)
                        fightA=1;//fightA describes the accelaration of the fighter towards the ground while in jumping state
                    else if(pic_y==0)
                        fightA=0;//when fighter is on the ground there will be no accelaration towards ground
                    if(pic_y<=0)
                        dpyi=0;//when fighter is on the ground there will be no speed towards ground

                }
                if(bomb_y>7&&bomb_y<17)
                {
                    if(musicOn)   PlaySound("bounce.wav",NULL, SND_ASYNC);
                    //when the bomb touches the ground there will be a sound of the bounce
                }
            }
            if(mon_y==70)
                if(musicOn)   PlaySound("mont.wav",NULL, SND_ASYNC);
            //when the minster touches the ground there will be a sound to notify the gamer that a life is lost
            if(bulletmode==1)
            {
                if(ball_x<=970&&ball_x>=930)
                {
                    bulletside=-1;
                }
                if(ball_x>=-80&&ball_x<=-60)
                {
                    bulletside=1;
                }
            }
        }
    }
}


void iMouseMove(int mx, int my)
{
    //place your codes here
}


void iMouse(int button, int state, int mx, int my)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if(instruction==1)
        {
            //instructins page is opened
            if(mx >= 920 && mx <= 1000 && my >= 550 && my <= 597)
            {
                //back button is pressed in the instruction page
                instruction = 0;//calls to close the instruction page
            }
        }
        else
        {
            if(opening==0&&gru==0)
            {
                //opening = 0 means it is in the menu page
                if(mx >= 330 && mx <= 622 && my >= 271 && my <= 346)
                {
                    //this position means button of the new game
                    m = 0;//states that m=0 so continues
                    mon_x=600;
                    mon_y=701;
                    opening = 1;//opening = 1 means that game is passed the menu page
                    if(musicOn)
                        PlaySound("click.wav",NULL,SND_ASYNC);

                }
                if(mx >= 330 && mx <= 622 && my >= 157 && my <= 236)
                {
                    m = 0;
                    highscoresetting=1;//calls the highscore page to show
                    if(musicOn)
                        PlaySound("click.wav",NULL,SND_ASYNC);
                    if(musicOn)
                        PlaySound("highscoremusic1.wav",NULL,SND_ASYNC|SND_LOOP);//playes the highscore sound

                }
                if(mx >= 330 && mx <= 622 && my >= 44 && my <= 126 && gru==0)
                {
                    if(musicOn)
                        PlaySound("click.wav",NULL,SND_ASYNC);
                    exit(0);//exit from the game

                }
                if(mx >= 815 && mx <= 982 && my >= 16 && my <= 64 && gru==0)
                {
                    //button of instruction

                    instruction = 1;//instruction is 1 so it calls instruction page to show

                }
                if(mx >= 818 && mx <= 966 && my >= 96 && my <= 137 && gru==0)
                {
                    //button of credit

                    credit = 1;//credit is 1 so it calls credit page to show

                }
                if(mx >= 900 && mx <= 970 && my >= 485 && my <= 600 && gru==0 && credit==0 && opening==0 && highscoresetting==0 && instruction == 0)
                {
                    //music button
                    if(musicOn)
                        musicOn = false;//call the music to play
                    else
                    {
                        musicOn = true;//stop the music to play
                        PlaySound("theme.wav",NULL,SND_ASYNC|SND_LOOP);
                    }
                    musica=0;//it is used so that a click sound is heard for just one time
                }
            }
        }
        if(opening!=0)
        {
            //opening !=0 means we have gone passed the menu page
            //m=1 means that the game is in paused position
            //m=0 means that the game is continueing
            if(mx >= 913 && mx <= 1000 && my >= 523 && my <= 601  && m==0 )
            {
                //user has clicked the pause  button
                m = 1;
                tmode=0;//m=1 tmode=0 both indicates that game is in the paused pasition
                if(musicOn)
                    PlaySound("click.wav",NULL,SND_ASYNC);//click sound of the pause button
                iPauseTimer(0);

            }

            if(mx >= 337 && mx <= 601 && my >= 376 && my <= 444  && m==1 )
            {
                //user has clicked the resume button
                m = 0;//call the game to conitnue

                tmode=1;//call the game to conitnue
                if(musicOn)
                    PlaySound("click.wav",NULL,SND_ASYNC);
                iResumeTimer(0);

            }
            if(mx >= 337 && mx <= 601 && my >= 277 && my <= 341  && m==1 )
            {
                //user has clicked the new game button
                m = 0;
                supexit=0;//new game and main menu
                opening = 1;//it takes it straight to new game
                if(musicOn)
                    PlaySound("click.wav",NULL,SND_ASYNC);
                iResumeTimer(0);
                iClear();
                tir();//function to go back to new game


            }
            if(mx >= 337 && mx <= 601 && my >= 180 && my <= 246  && m==1 )
            {
                //user has clicked the exit button
                m = 0;
                iResumeTimer(0);
                if(musicOn)   PlaySound("click.wav",NULL,SND_ASYNC);
                exit(0);//exit the game

            }
            if(mx >= 333 && mx <= 610 && my >= 94 && my <= 148  && m==1 )
            {
                m = 0;
                iResumeTimer(0);
                opening = 0;//opening 0 indicates that it will go to the main menu
                // printf(" hththt ");
                supexit=0;
                if(musicOn)
                    PlaySound("click.wav",NULL,SND_ASYNC);
                gru=1;
                tir();//function to go back to main menu
            }
            if(mx >= 844 && mx <= 881 && my >= 334 && my <= 354  && m==0 )
            {
                //user has clicked to guard on
                guard = 1;//turn the guard on
                guardtime=0;//frame count
                if(musicOn)
                    PlaySound("click.wav",NULL,SND_ASYNC);

            }
            if(mx >= 882 && mx <= 921 && my >= 334 && my <= 354  && m==0 )
            {
                //user has clicked to guard off
                guard = 0;//turn the guard off
                guardtime=0;
                if(musicOn)
                    PlaySound("click.wav",NULL,SND_ASYNC);

            }

        }

        if(kl==2)
        {
            //kl=2 indicates that we are at our last screem with options like main menu, new game and exit
            if(mx >= 241 && mx <= 403 && my >= 161 && my <= 211)
            {

                //user want to go to the main menu
                opening = 0;//main menu
                supexit=0;
                if(musicOn)   PlaySound("click.wav",NULL,SND_ASYNC);
                tir();//function call to go to the main menu

            }
            if(mx >= 462 && mx <= 625 && my >= 161 && my <= 211)
            {
                //user wants to start a new game
                opening = 1;//new game
                supexit=0;
                if(musicOn)   PlaySound("click.wav",NULL,SND_ASYNC);
                tir();//function call to go to new game


            }
            if(mx >= 686 && mx <= 850 && my >= 161 && my <= 211)
            {
                if(musicOn)
                    PlaySound("click.wav",NULL,SND_ASYNC);
                exit(0);//exit the game
            }
        }
        if(highscoresetting==1)
        {
            //highscore = 1 means highscore screen is open
            if(mx >= 869 && mx <= 1000 && my >= 542 && my <= 601)
            {
                //user has clicked inside highscore
                highscoresetting=0;//calls the highscorefunction to stop
                hp1=0;//these are the initial position of the highscorers names and their scores
                hp2=-600;
                hp3=-1200;
                hp4=-1800;
                hp5=-2400;
                supexit=0;//it is used to go to main menu in tir function
                if(musicOn)   PlaySound("click.wav",NULL,SND_ASYNC);
                opening = 0;
                if(musicOn)   PlaySound("theme.wav", NULL, SND_ASYNC|SND_LOOP);
                tir();//go to the main menu
            }
        }
        if(credit==1)
        {
            //credit = 1 means credit screen is open
            if(mx >= 900 && mx <= 983 && my >= 544 && my <= 586)
            {
                //user has clicked back button inside credit
                credit=0;//calls the creditpage to stop
                opening = 0;
                supexit=0;//it is used to go to main menu in tir function
                tir();//go to the main menu
            }
        }
    }
}


void iKeyboard(unsigned char key)
{

    if(key == ' ')
    {
        if(bulletmode==0)
        {
            //bulletmode 0 means bullet is not active
            if(m==0&&kl==0)
            {

                ball_x = pic_x;
                ball_y = pic_y;
                mode=1;
                bulletmode=1;//calls the bullet to be active
                if(musicOn)
                    PlaySound("bulletsound.wav",NULL,SND_ASYNC);//plays the bullet sound
            }
        }
    }

    else
    {
        mode=0;
        iResumeTimer(0);
    }
    if(key == 'g')
    {
        if(guard==0)
            guard=1;//guard=1 means guard on
        else
            guard=0;//guard=0 means guard off
    }
    if(kl==1)
    {
        if(key == '\r')
        {
            //here it ihas stopped input from the user
            mode = 0;
            strcpy(instantname, str558);//copying the name to instant name
            for(i = 0; i < len; i++)
                str558[i] = 0;//cleaning the name
            len = 0;
            kl=2;//call the game to go to the last picture indicating that name input is done
            if(musicOn)
                PlaySound("theme.wav", NULL, SND_ASYNC|SND_LOOP);
            newhighscore();//calling the function to add instant name and score to the files
        }
        else
        {
            str558[len] = key;//continue to  take input from the user
            len++;
        }
    }

    //place your codes for other keys here
}


void iSpecialKeyboard(unsigned char key)
{

    if(key == GLUT_KEY_END)
    {
        exit(0);//exit the game
    }
    if(key == GLUT_KEY_LEFT)
    {
        if(pic_x>40)
            pic_x-=40;//move the fighter to the  left
        fighterside=-1;
        if(pic_y==0)
        {
            pic_y+=2;
            dpyi=5;
            if(musicOn)   PlaySound("move.wav",NULL,SND_ASYNC);
        }
    }
    if(key == GLUT_KEY_RIGHT)
    {
        if(pic_x<920)
            pic_x+=40;//move the fighter to the right
        fighterside=1;
        if(pic_y==0)
        {
            pic_y+=2;
            dpyi=5;
            if(musicOn)   PlaySound("move.wav",NULL,SND_ASYNC);
        }
    }
    if(key == GLUT_KEY_UP)
    {
        if(pic_y==0)
        {
            pic_y+=2;
            dpyi=15;//make the fighter do a jump
            if(musicOn)   PlaySound("move.wav",NULL,SND_ASYNC);
        }
    }
    if(key == GLUT_KEY_DOWN)
    {
        if(pic_y>=20)
            pic_y-=20;
    }
    //place your codes for other keys here

}

void ballChange()
{
    //if(bulletmode==0){
    ball_x += (bulletside*dx);
    ball_y += dy;//those determines the speed of the bullet
    //m means sontinuation
    if(m==0)
    {
        if(opening!=0)
        {
            if(kl==0)
            {
                mon_x = mon_x - monslide*moncx;
                mon_y = mon_y - moncy;// those determines the speed of the monster
            }
        }
    }
    pic_y=pic_y+dpyi;
    dpyi = dpyi - fightA;//those determines the speed and accelaration of the fighter in the state of jumping
}

void monsterChange()
{

}

int main()
{
    //place your own initialization codes here.
    pic_x = 100;
    pic_y = 0;
    iSetTimer(5, ballChange);//calling ballchange
    dx = 20;
    dy = 40;
    if(musicOn)
        highscore();//calling highscore to get the previous highest scores
    iInitialize(1000, 601, "MONSTER SHOOTER");
    return 0;
}
void tir()
{
    if(supexit==0)
    {
        //new game and back to main menu
        //here all the variables are set to there intial value
        pic_x=900;
        pic_y=10;
        a=0;
        mode=0;
        m=0;
        hp1=0;
        hp2=-600;
        hp3=-1300;
        hp4=-1800;
        hp5=-2400;
        monster=0;
        mon_x=500;
        mon_y=621;
        tmode=1;
        score=0;
        bullet_x=300;
        bullet_y=300;
        moncx=0;
        moncy=1;
        kio=0;
        ex=0;
        kl=0;
        jhu=0;
        heart=5;
        bomb_x=500;
        bomb_y=601;
        bombi=0;
        pic_x = 100;
        pic_y = 0;
        timingbomb=0;
        supexit=0;
        monslide=1;
        supertimer=0;
        tik=0;
        musica=0;
        pic_x=100;
        pic_y=10;
        jhu=0;
        timingbomb=0;
        bombini=0;
        kio=0;
        guard=0;
        bulletmode=0;
        guardtime=0;
        supertimer=0;
        tik=0;
        ball_x=300;
        ball_y=300;
        bomb_x=900;
        bomb_y=350;
        fighterside=-1;
        bulletside=1;
        rconstant=1;
        bside=1;
        coli=0;
        a=0;
        bombi=0;
        randome=0;
        losing=0;
        lineflick=0;
        j=0;
        jiko=0;
        losss=0;
        kl=0;
        dbx=2;
        dby=1;
        m=0;
        monster=0;
        mon_x=500;
        mon_y=621;
        monslide=1;
        bombstate=0;
        bombnumber=0;
        explo=0;
        bombtik=0;
        tmode=1;
        score=0;
        ly=0;
        lx=0;
        gru=0;
        bullet_x=300;
        bullet_y=300;
        ex=0;
        supexit=0;
        heart_x=500;
        heart_y=550;
        heart=5;
        z=0;
        moncx=0;
        moncy=1;
        level=1;
        jir=0;
        picheight=0;
        fightA=0;
        dpyi=0;
        bombA=2;
        bombvx=-2;
        bombvy=7;
        bombcount=0;
        highscore();
        highscoresetting=0;
        len=0;
        highpos=0;
        hp1=0;
        hp2=-600;
        hp3=-1300;
        hp4=-1800;
        hp5=-2400;
        hty=0;


    }
    else if(supexit>0)
    {
        //LEVEL UP call
        if(score==10)
        {
            //when score is more than 10 level 2 arrives
            moncx=1;
            moncy=2;
        }
        if(score==20)
        {
            //when score is more than 20 level 3 arrives
            moncx=2;
            moncy=4;
        }
        if(score==30)
        {
            //when score is more than  30 the speed of the monster becomes very fast
            moncx=4;
            moncy=8;
        }
    }
    gru=0;

}


void highscore()
{
    //it is the function to take input from saved highscore file
    //pl1-5 contains the name of the high scorers
    //h1-5 contains the scores of the high scorers
    FILE *fp;
    fp = fopen("highscore.txt","r");
    fscanf(fp,"%[^\n]s",pl1);
    fseek(fp, 2, SEEK_CUR);
    fscanf(fp,"%d",&h1);
    fseek(fp, 2, SEEK_CUR);
    fscanf(fp,"%[^\n]s",pl2);
    fseek(fp, 2, SEEK_CUR);
    fscanf(fp,"%d",&h2);
    fseek(fp, 2, SEEK_CUR);
    fscanf(fp,"%[^\n]s",pl3);
    fseek(fp, 2, SEEK_CUR);
    fscanf(fp,"%d",&h3);
    fseek(fp, 2, SEEK_CUR);
    fscanf(fp,"%[^\n]s",pl4);
    fseek(fp, 2, SEEK_CUR);
    fscanf(fp,"%d",&h4);
    fseek(fp, 2, SEEK_CUR);
    fscanf(fp,"%[^\n]s",pl5);
    fseek(fp, 2, SEEK_CUR);
    fscanf(fp,"%d",&h5);
    fclose(fp);

}

void newhighscore()
{
    //this function is used to update the highscore file
    //it compares the score of the gamer with the previous ones
    //based on its score it input the name in its position and close the file
    //if the score is less than every other the file is kept the same
    FILE *fp;
    fp = fopen("highscore.txt","w");
    int repl=0;
    char space[]= {"\n"};
    if(score>h1)
        repl=1;
    else if(score>h2)
        repl=2;
    else if(score>h3)
        repl=3;
    else if(score>h4)
        repl=4;
    else if(score>h5)
        repl=5;
    if(repl==5)
    {
        //code to input name and score in 5th position
        fprintf(fp,"%s", pl1);
        fprintf(fp,"%s", space);
        fprintf(fp,"%d", h1);
        fprintf(fp,"%s", space);

        fprintf(fp,"%s", pl2);
        fprintf(fp,"%s", space);
        fprintf(fp,"%d", h2);
        fprintf(fp,"%s", space);

        fprintf(fp,"%s", pl3);
        fprintf(fp,"%s", space);
        fprintf(fp,"%d", h3);
        fprintf(fp,"%s", space);

        fprintf(fp,"%s", pl4);
        fprintf(fp,"%s", space);
        fprintf(fp,"%d", h4);
        fprintf(fp,"%s", space);

        fprintf(fp,"%s", instantname);
        fprintf(fp,"%s", space);
        fprintf(fp,"%d", score);
        fprintf(fp,"%s", space);


    }

    if(repl==4)
    {
        //code to input name and score in 4th position
        fprintf(fp,"%s", pl1);
        fprintf(fp,"%s", space);
        fprintf(fp,"%d", h1);
        fprintf(fp,"%s", space);

        fprintf(fp,"%s", pl2);
        fprintf(fp,"%s", space);
        fprintf(fp,"%d", h2);
        fprintf(fp,"%s", space);

        fprintf(fp,"%s", pl3);
        fprintf(fp,"%s", space);
        fprintf(fp,"%d", h3);
        fprintf(fp,"%s", space);

        fprintf(fp,"%s", instantname);
        fprintf(fp,"%s", space);
        fprintf(fp,"%d", score);
        fprintf(fp,"%s", space);

        fprintf(fp,"%s", pl4);
        fprintf(fp,"%s", space);
        fprintf(fp,"%d", h4);
        fprintf(fp,"%s", space);

    }

    if(repl==3)
    {
        //code to input name and score in 3rd position
        fprintf(fp,"%s", pl1);
        fprintf(fp,"%s", space);
        fprintf(fp,"%d", h1);
        fprintf(fp,"%s", space);

        fprintf(fp,"%s", pl2);
        fprintf(fp,"%s", space);
        fprintf(fp,"%d", h2);
        fprintf(fp,"%s", space);

        fprintf(fp,"%s", instantname);
        fprintf(fp,"%s", space);
        fprintf(fp,"%d", score);
        fprintf(fp,"%s", space);

        fprintf(fp,"%s", pl3);
        fprintf(fp,"%s", space);
        fprintf(fp,"%d", h3);
        fprintf(fp,"%s", space);

        fprintf(fp,"%s", pl4);
        fprintf(fp,"%s", space);
        fprintf(fp,"%d", h4);
        fprintf(fp,"%s", space);




    }

    if(repl==2)
    {
        //code to input name and score in 2nd position
        fprintf(fp,"%s", pl1);
        fprintf(fp,"%s", space);
        fprintf(fp,"%d", h1);
        fprintf(fp,"%s", space);

        fprintf(fp,"%s", instantname);
        fprintf(fp,"%s", space);
        fprintf(fp,"%d", score);
        fprintf(fp,"%s", space);

        fprintf(fp,"%s", pl2);
        fprintf(fp,"%s", space);
        fprintf(fp,"%d", h2);
        fprintf(fp,"%s", space);

        fprintf(fp,"%s", pl3);
        fprintf(fp,"%s", space);
        fprintf(fp,"%d", h3);
        fprintf(fp,"%s", space);

        fprintf(fp,"%s", pl4);
        fprintf(fp,"%s", space);
        fprintf(fp,"%d", h4);
        fprintf(fp,"%s", space);


    }

    if(repl==1)
    {
        //code to input name and score in 1st position
        fprintf(fp,"%s", instantname);
        fprintf(fp,"%s", space);
        fprintf(fp,"%d", score);
        fprintf(fp,"%s", space);

        fprintf(fp,"%s", pl1);
        fprintf(fp,"%s", space);
        fprintf(fp,"%d", h1);
        fprintf(fp,"%s", space);

        fprintf(fp,"%s", pl2);
        fprintf(fp,"%s", space);
        fprintf(fp,"%d", h2);
        fprintf(fp,"%s", space);

        fprintf(fp,"%s", pl3);
        fprintf(fp,"%s", space);
        fprintf(fp,"%d", h3);
        fprintf(fp,"%s", space);

        fprintf(fp,"%s", pl4);
        fprintf(fp,"%s", space);
        fprintf(fp,"%d", h4);
        fprintf(fp,"%s", space);
    }
    if(repl==0)
    {
        //the file is kept the same
        fprintf(fp,"%s", pl1);
        fprintf(fp,"%s", space);
        fprintf(fp,"%d", h1);
        fprintf(fp,"%s", space);

        fprintf(fp,"%s", pl2);
        fprintf(fp,"%s", space);
        fprintf(fp,"%d", h2);
        fprintf(fp,"%s", space);

        fprintf(fp,"%s", pl3);
        fprintf(fp,"%s", space);
        fprintf(fp,"%d", h3);
        fprintf(fp,"%s", space);

        fprintf(fp,"%s", pl4);
        fprintf(fp,"%s", space);
        fprintf(fp,"%d", h4);
        fprintf(fp,"%s", space);

        fprintf(fp,"%s", pl5);
        fprintf(fp,"%s", space);
        fprintf(fp,"%d", h5);
        fprintf(fp,"%s", space);
    }
    fclose(fp);//closes the file

}
