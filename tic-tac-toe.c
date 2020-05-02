#include<LiquidCrystal.h>

const int rs = 8, en = 7, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int a,b,c,d,inp,res,counter=0;
char s1,s2,arr[9];

int check(char arr[9])
{
  if(arr[0]==arr[1] && arr[1]==arr[2] && arr[2]==s1 || arr[3]==arr[4] && arr[4]==arr[5] && arr[5]==s1 || arr[6]==arr[7] && arr[7]==arr[8] && arr[8]==s1 || arr[0]==arr[3] && arr[3]==arr[6] && arr[6]==s1 || arr[1]==arr[4] && arr[4]==arr[7] && arr[7]==s1 ||    
 arr[2]==arr[5] && arr[5]==arr[8] && arr[8]==s1 || arr[0]==arr[4] && arr[4]==arr[8] && arr[8]==s1 || arr[2]==arr[4] && arr[4]==arr[6] && arr[6]==s1 )
 {
  return 1;
 }
 else if(arr[0]==arr[1] && arr[1]==arr[2] && arr[2]==s2 || arr[3]==arr[4] && arr[4]==arr[5] && arr[5]==s2 || arr[6]==arr[7] && arr[7]==arr[8] && arr[8]==s2 || arr[0]==arr[3] && arr[3]==arr[6] && arr[6]==s2 || arr[1]==arr[4] && arr[4]==arr[7] && arr[7]==s2 ||    
 arr[2]==arr[5] && arr[5]==arr[8] && arr[8]==s2 || arr[0]==arr[4] && arr[4]==arr[8] && arr[8]==s2 || arr[2]==arr[4] && arr[4]==arr[6] && arr[6]==s2)
 {
  return 2;
 }
 else
 {
  return 3;
 }
}  

void read()
{
  delay(3000);
  a=digitalRead(12);
  b=digitalRead(11);
  c=digitalRead(10);
  d=digitalRead(9);
}

int btod(int a,int b,int c,int d)
{
  if(a==0 && b==0 && c==0 && d==1)
  {
    return 1;
  }
  else if(a==0 && b==0 && c==1 && d==0)
  {
    return 2;
  }
  else if(a==0 && b==0 && c==1 && d==1)
  {
    return 3;
  }
  else if(a==0 && b==1 && c==0 && d==0)
  {
    return 4;
  }
  else if(a==0 && b==1 && c==0 && d==1)
  {
    return 5;
  }
  else if(a==0 && b==1 && c==1 && d==0)
  {
    return 6;
  }
  else if(a==0 && b==1 && c==1 && d==1)
  {
    return 7;
  }
  else if(a==1 && b==0 && c==0 && d==0)
  {
    return 8;
  }
  else if(a==1 && b==0 && c==0 && d==1)
  {
    return 9;
  }
  else
  {
    return -1;
  }
}

void printmat(char arr[9])
{
  int l,i,j;
  for(i=1;i<=3;i++)
  {
    l=0;
    for(j=3*(i-1);j<3*i;j++)
    {
      l++;
      lcd.setCursor(l,i-1);
      if(arr[j]!='t')
      {
        lcd.print(arr[j]);
      }
      else
      {
          lcd.print(" ");
      }
      l++;
      if(l!=6)
      {
        lcd.setCursor(l,i-1);
        lcd.print("|");
      }
    }
  }
   delay(1000);  
}
void setup()
{
  pinMode(13,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(2,OUTPUT);

  pinMode(9,INPUT);
  pinMode(10,INPUT);
  pinMode(11,INPUT);
  pinMode(12,INPUT);

 
  //digitalWrite(,HIGH);
  for(int i=0;i<9;i++)
  {
    arr[i]='t';
  }
 
  lcd.begin(20,4);
 
  lcd.setCursor(4,1);
  lcd.print("TIC-TAC-TOE");
  for(int i=5;i>=0;i--)
  {
    lcd.setCursor(0,3);
    lcd.print("Game Starts in ");
    lcd.setCursor(15,3);
    lcd.print(i);
    delay(1000);
  }
 
l:  lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("User 1 select :");
    lcd.setCursor(1,1);
    lcd.print("1.'x'");
    lcd.setCursor(1,2 );
    lcd.print("2.'o'");
    read();
    inp=btod(a,b,c,d);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Option Selected : ");
    lcd.setCursor(18,0);
    lcd.print(inp);
   
   
    if(inp==1)
    {
      s1='x';
      s2='o';
    }
    else if(inp==2)
    {
      s1='o';
      s2='x';
    }
    else
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Enter valid option :");
      goto l;
    }
}

void loop()
{
      lcd.clear();
   
l1:   lcd.setCursor(0,0);
      printmat(arr);
      lcd.setCursor(17,2);
      lcd.print("  ");
      lcd.setCursor(12,2);
      lcd.print("P1 : ");
      lcd.setCursor(17,2);
      read();
      inp=btod(a,b,c,d);
      if(inp!=-1)
      {
        lcd.print(inp);
      }
      else
      {
        lcd.print("  ");
      }
      if(1<=inp && inp<=9 && arr[inp-1]=='t')
      {
        arr[inp-1]=s1;        
        printmat(arr);
        res=check(arr);
        if(res==1)
        {
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("User 1 you won");
          digitalWrite(13,HIGH);
          delay(10000);
          exit(0);
        }
        else if(res==2)
        {
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("User 2 you won");
          digitalWrite(13,HIGH);
          delay(10000);
          exit(0);
        }
        else
        {
          counter++;
        }
      }
      else
      {
        goto l1;
      }
      if(counter==9)
      {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Match is Tied");
        exit(0);
      }
     
l2:   lcd.setCursor(0,0);
      printmat(arr);
      lcd.setCursor(17,2);
      lcd.print("  ");
      lcd.setCursor(12,2);
      lcd.print("P2 : ");
      lcd.setCursor(17,2);
      read();
      inp=btod(a,b,c,d);
      if(inp!=-1)
      {
        lcd.print(inp);
      }
      else
      {
        lcd.print("  ");
      }
     
   
      if(1<=inp && inp<=9 && arr[inp-1]=='t')
      {
        arr[inp-1]=s2;        
        printmat(arr);
        res=check(arr);
        if(res==1)
        {
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("User 1 you won");
          digitalWrite(13,HIGH);
          delay(10000);
          exit(0);
        }
        else if(res==2)
        {
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("User 2 you won");
          digitalWrite(13,HIGH);
          delay(10000);
          exit(0);
        }
        else
        {
          counter++;
        }
      }
      else
      {
        goto l2;
      }
      if(counter==9)
      {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Match is Tied");
        exit(0);
      }
     
}
