//AcerQiu��2048С��Ϸ1.3.4�汾
//������game_winning����ģ��
#include <stdio.h>
#include <stdlib.h> // for rand() and srand() and exit()
#include <time.h>   // for time()
#include <conio.h> //Ϊ�˶�ȡ�����#include <windows.h>    // for system()

//------------------ȫ�ֱ���-------------------------------
// ��Ϸ��������һ�� 4*4 �� 16 ����ʹ�ö�ά������б�ʾ���� 0 ��ʾ�ո�
int a[4][4];

// 16 �����пո�ĸ���
int empty;
// �û���
int name[30];
// ����ͳ��
int score = 0;

//��Ϸ�����ж�
int gameover = 0;
int gamewinning = 0;

void init(void);      // ��ʼ���������ֵ��һ�������ά����Ԫ�� 
void draw(void);      // ����4 * 4����ͼ 
void play(void);      // �����ƶ�����
void to_up(void);     // �����ƶ� 
void to_down(void);   // �����ƶ� 
void to_left(void);   // �����ƶ� 
void to_right(void);  // �����ƶ� 
void add_number(void);  // ���µ���
void game_winning(void); //��Ϸ��ʤ�ж�
void game_over(void);  //������Ϸ�ж�
void rank(void);      //����������Ϸ��������������

int main()
{
    system("color f9");
    printf("****************************************\n"); 
    printf("     2048(by AcerQiu)(4*4)     \n\n"); 
    printf("           Control by:\n"
           "w/s/a/d or W/S/A/D or up/down/left/right \n"); 
    printf("      press q or Q quit game!\n");
    printf("****************************************\n"); 
    printf("  Please enter the name of player\n");
    scanf("%s", name);
    printf("           Hello %s\n", name);
    printf("  Press any key to continue . . .\n"); 
    getch();
    system("cls"); 
    
    init();
    draw();
    while(1)
        play();
    

    return 0;
} 


void init(void)
{
    //��ʼʱ��ʾ�������ַ��±�λ��
    int x, y;

    for(x=0; x<4; x++)
        for(y=0; y<4; y++)
            a[x][y] = 0;
    srand(time(0));
    x = rand() % 4;
    y = rand() % 4;
    a[x][y] = 2;
    empty = 15;
}

void draw(void)              //����4*4���� ÿһ����ʵ��������� �ո�-�������ֿո�
{
    int i, j;                      

    for(i=0; i<4; i++) 
    {                              // һ������������������� 
        for(j=0; j<4; j++)     // ��һ������ ÿ������֮��ռ5���� 
            printf("|    ");       //��ӡ�ĸ����ߺ����һ������һ��\nת�з�������һ��
        printf("|\n");
        
        for(j=0; j<4; j++) {   // �ڶ������������� (���е����ֶ���ÿ�����ӵĵڶ��ų���)
            if(a[i][j] == 0)
                printf("|    ");
            else
                printf("|%4d", a[i][j]);
        } 
        printf("|\n"); 
        
        for(j=0; j<4; j++)     // ���������߼ӵ��� 
            printf("|____");
        printf("|\n");
    }

    printf("Current Score: %d", score);  //���һ����ʾʵʱ����ֵ
} //draw��������

void play(void)
{
    int ch;
    ch = getch();//<conio.h>ͷ�ļ�����getch()����һ�������� �䷵��ֵΪACII��
    //������Ķ�ȡ--case��ֻ��Ϊ��ֵ
    switch (ch)
    {
    case 72:     //up���ʹ�Сд��Ww������Ϊ����ָ��
    case 'w':
    case 'W':
        to_up();
        system("cls");   //����ָ��
        add_number();
        draw();     
        break;
    case 80:     
    case 's':
    case 'S':
        to_down();
        system("cls");
        add_number(); 
        draw(); 
        break;
    case 75:     
    case 'a':
    case 'A':
        to_left();
        system("cls");
        add_number(); 
        draw(); 
        break;
    case 77:     
    case 'd':
    case 'D':
        to_right();
        system("cls");
        add_number(); 
        draw(); 
        break;
    case 'q':
    case 'Q':
        exit(0);
        break;
    case 0:
    case 224:
        break;
    default:
        printf("\nWRONG INPUT!!!\n\n");
        printf("Please type:\nw/s/a/d or W/S/A/D or up/down/left/right \n");
        break;
    }
    

    game_winning(); //��game_winning()�����ж��Ƿ�����2048�Ӷ��ж���Ϸ��ʤ
    if(gamewinning == 1){
        printf("\nCONGRATES!!!\n\n  %s\n", name);
                printf("YOU WIN!!!\n\n");
                printf("Your final score is %d\n", score);
                rank();
                system("PAUSE");
                printf("\nInput 'q' or 'Q' to quit\n");
                switch (ch){
                case 'q':
                case 'Q':
                exit(0);
                break;
                }
    }

     
    game_over();     //��game_over()�����ж��Ƿ��������������������������gameover������ֵΪ1
    
    if(gameover == 1){       
        printf("\nGAME OVER!\n");
        printf("Your final score is %d\n", score);
        rank();
        system("PAUSE");
        printf("\nInput 'q' or 'Q' to quit\n");
        switch (ch){
        case 'q':
        case 'Q':
        exit(0);
        break;
        }    
    }    


} //play������


void rank(void)
{
    if(score<100){
        printf("Rank F\n");
    } else if((score>100)&&(score<1000)){
        printf("Rank E\n");
    } else if((score>1000)&&(score<2500)){
        printf("Rank D\n");
    } else if((score>2500)&&(score<5000)){
        printf("Rank C\n");
    } else if((score>5000)&&(score<7500)){
        printf("Rank B\n");
    } else if((score>7500)&&(score<10000)){
        printf("Rank A\n");
    } else if((score>10000)&&(score<12500)){
        printf("Rank S\n");
    } else if((score>12500)&&(score<15000)){
        printf("Rank SS\n");
    } else if((score>15000)&&(score<17500)){
        printf("Rank SSS\n");
    } else if(score>17500){
        printf("Rank LEGENDARY!!!\n");
    }
}

void game_winning(void)
{
    
    int j, k;
    for(j=0; j<4; j++){
        for(k=0; k<4; k++){
            if(a[j][k] == 64){
                gamewinning = 1;     
            } 
        }
    }
}

void game_over(void)
{
    //�ж�ʧ������
    //forѭ���������� �ú��ݶ������ʱ��emptyΪ0ʱ����(x)
    //��˼·:forѭ������������||�����ж��������ݷ�����һһ���򶼿ɺϲ���������������(return)����gameover��ֵ0
    //��k��ֵҪ��0-2֮�䣨Ϊ�˱���k=4��ʱ��ǿ����û���κθ�ֵ��a[x][4]/a[4][y]���бȽϣ�
    int j, k;
    for(j=0; j<4; j++){
        for(k=0; k<3; k++){
            if(a[j][k]==a[j][k+1]||a[k][j]==a[k+1][j]){    //���ڵ�������ͬ��ʱ���������
                gameover = 0;                              //�ұ����ڱ����������������ܶ�gameover�����ж���ֵ
                return;             //������������ʱֱ��return���ؼ�������
            }
        }
    }
    //�����������������ǰ�����Ҷ������ڵ�������ͬ����������gameoverֵΪ1
    if(empty == 0){
        gameover = 1;
    }
}



void add_number(void)
{
    int temp, number;
    int x, y;

    if(empty > 0) {      // �ҳ��ո� 
        srand(time(0));   //srand()��������rand()���������ʱ����������ӣ�����seed����������
        do {                //ͨ��������time(0)�ķ���ֵ��Ϊseed.���ÿ��seed��������ͬ��ֵ��rand()�����������ֵÿ�ζ�һ����
            x = rand() % 4;    //%4��ֻ������0��1��2��3��ǡ�������������
            y = rand() % 4;
        } while(a[x][y] != 0);
        
        number = rand();
        temp = number % 2; //��Ϊֻ������2��4 �����%2����ʽ
                            //��������if������2ѡ1
    
        if(temp == 1) {  // �ж�����������2����������4
            a[x][y] = 2;
            empty--;    //�������2��4�󣬿ո�����һ
        } 
        if(temp == 0) {
            a[x][y] = 4;
            empty--;
        }
    }
}





void to_up(void)
{
    int x, y, i;    //x-����  y-����

    for(y=0; y<4; y++){            //��ֱ���������У�row��--x�����㣬���ȱ���ÿһ��--y
        for(x=0; x<4; x++){       // �������Ϻϲ���ͬ�ķ��� 
            if(a[x][y] != 0){   
                for(i=x+1; i<4; i++){
                    if(a[i][y] != 0){
                        if(a[x][y] == a[i][y]){       
                        a[x][y] += a[i][y];  //���������������ͬ�͵��Ӳ�����һ������Ϊ0
                        a[i][y] = 0;
                        empty++;             //��0��Ϊ�ո� �ʺϲ���ո���Ӧ�ü�һ
                        score += a[x][y];
                        x = i;
                        break;
                        } else{
                            break;
                        }  
                    }  
                }
            }    
        }
    }   //��һȦforѭ��һ��Ҫ�����������еĲ�����������������

    for(y=0; y<4; y++){
        for(x=0; x<4; x++){
            if(a[x][y] != 0){
                for(i=x;(i>0)&&(a[i-1][y]==0);i--){
                    a[i-1][y] = a[i][y];
                    a[i][y] = 0;
                }
            }
        }
    }

}

void to_down(void)
{
    int x, y, i;

    for(y=0; y<4; y++){
        for(x=3; x>=0; x--){
            if(a[x][y]!=0){         //�����λ��Ϊ��������ɨ��������
                for(i=x-1; i>=0; i--){
                    if(a[i][y] != 0){
                        if(a[i][y] == a[x][y]){
                            a[x][y] += a[i][y];    //���ºϲ���ͬ��������
                            a[i][y] = 0;
                            empty++;
                            score += a[x][y];
                            x = i;        //��������1���ɨ�裬��������2���ɨ�裨��Ϊ�кϲ����������пո�
                            break;
                        } else{
                            break;
                            }
                    }
                }     
            }
        }
    }

    for(y=0; y<4; y++){
        for(x=3; x>=0; x--){
            if(a[x][y] != 0){       //�����⵽��λ��Ϊ0
                for(i=x;(i<3)&&(a[i+1][y]==0);i++){   //������һλҲΪ0ʱ(���������ƶ�)
                    a[i+1][y] = a[i][y];        //����Ϊ0����һλ��ֵ����һλ
                    a[i][y] = 0;                //ԭλ��ֵΪ0
                }
            }
        }
    }

}

void to_left(void) 
{
    int x, y, i;
        //�����ƶ�����ͬһ����ÿһ�е��������ȱ�������--x
    for(x=0; x<4; x++){       //��������ϲ���ͬ����
        for(y=0; y<4; y++){
            if(a[x][y] != 0){
                for(i=y+1; i<4; i++)     //ɨ���λ�Ҳ��������
                    if(a[x][i] != 0){
                        if(a[x][i] == a[x][y]){
                            a[x][y] += a[x][i];   //�����λ�Ҳ�������ڸ�λ����ϲ�
                            a[x][i] = 0;
                            empty++;
                            score += a[x][y];
                            y = i;
                            break;
                        }else {
                            break;
                        }
                    }
            }
        }
    }

    for(x=0; x<4; x++){
        for(y=0; y<4; y++){
            if(a[x][y] != 0){
                for(i=y;(i>0)&&(a[x][i-1]==0);i--){    //�����ƶ��ո� ֻҪ���Ϊ0�Ϳ����ƶ�
                    a[x][i-1] = a[x][i];
                    a[x][i] = 0;
                }
            }
        }
    }


}

void to_right(void)
{
    int x, y, i;

    for(x=0; x<4; x++){
        for(y=3; y>=0; y--){
            if(a[x][y] != 0){         //�����λ��Ϊ��������ɨ��������
                for(i=y-1; i>=0; i--){
                    if(a[x][i] != 0){
                        if(a[x][i] == a[x][y]){
                            a[x][y] += a[x][i];    //���Һϲ���ͬ��������
                            a[x][i] = 0;
                            empty++;
                            score += a[x][y];
                            y = i;        //��������1���ɨ�裬��������2���ɨ�裨��Ϊ�кϲ����������пո�
                            break;
                        } else{
                            break;
                            }
                    }
                }     
            }
        }
    }

    for(x=0; x<4; x++){
        for(y=3; y>=0; y--){
            if(a[x][y] != 0){       //�����⵽��λ��Ϊ0
                for(i=y;(i<3)&&(a[x][i+1]==0);i++){   //������һλҲΪ0ʱ(�������Ҷ�)
                    a[x][i+1] = a[x][i];        //����Ϊ0����һλ��ֵ����һλ
                    a[x][i] = 0;                //ԭλ��ֵΪ0
                }
            }
        }
    }

}
