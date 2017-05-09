int n=0;
void reset()
{
  for(int i=8;i<12;i++)
  digitalWrite(i,LOW);
}

void num(int n)
{
  int n1=n/10;
  int n2=n%10;
  int data[10][7]={{1,1,1,1,1,1,0},{0,1,1,0,0,0,0},{1,1,0,1,1,0,1},{1,1,1,1,0,0,1},{0,1,1,0,0,1,1},{1,0,1,1,0,1,1},{1,0,1,1,1,1,1},{1,1,1,0,0,0,0},{1,1,1,1,1,1,1},{1,1,1,1,0,1,1}};
  for(int i=0;i<7;i++)
  {
    digitalWrite(i+30,data[n2][i]);
    digitalWrite(i+40,data[n1][i]);
    delay(5);
  }
}

void setup()
{
  for(int i=8;i<12;i++)
  pinMode(i,OUTPUT);
  for(int k=30;k<51;k++)
  pinMode(k,OUTPUT);
  for(int j=2;j<6;j++)
  pinMode(j,INPUT);
  num(0);
  randomSeed(analogRead(0));
}
int prev=0,input=0;
void loop()
{
  long last=millis();
  if(last<30000)
  {
    k:
    reset();
    int r=random(1,5);
    if(r==prev)
    goto k;
    else
    {
      prev=r;
      digitalWrite(r+7,HIGH);
      delay(1);
      input=digitalRead(r+1);
      while(input==0)
      {
        while(!(input=digitalRead(r+1)));
        delay(10);
      }
      reset();
      n++;
      num(n);
    }
  }
  else
  {
    for(int i=8;i<12;i++)
    digitalWrite(i,HIGH);
    num(n);
  }
}
