//---------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <vcl.h>
#include <stdio.h>
#include <string.h>
#include "Unit3.h"
#include "Unit5.h"
#pragma hdrstop
#include "Unit1.h"
#include <Math.hpp>
#include <string>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;



//--------------------------------------------------------------------------
     int massiv_for_id [20];
        int gcount = 0;
     int id_counter = 0;
      int pp = 0;
      int number_id=0;
       bool rev=true;
    int ColumnToSort;
    typedef struct
{
 char surname[16];
 char name[16];
 char otchestvo[16];
 long zarplata;
 char rejim[16];
 char doljnost[16];
 int id_sotrudnik;
}C;
C dat[10];

typedef struct
{
 int Jan;
 int Feb;
 int Mar;
 int Apr;
 int May;
}D;
  D ZP[100];


  typedef struct
{
   char Surname[16];
   char Name[16];
   char Otchestvo[16];
   long Zarplata;
   char Rejim[16];
   char Doljnost[16];
   int id;
} A;

A data[100];


 typedef struct
{
   char Surname[16];
   char Name[16];
   char Otchestvo[16];
   long Zarplata;
   char Rejim[16];
   char Doljnost[16];
} B;

B empt[100];
int nrec = 0;

char DOL[16];
float AVE_DOL;
long SUM_DOL;
bool B_DOL;

char REZ[16];
float AVE_REZ;
long SUM_REZ;
bool B_REZ;

  /* void TForm1::search() {
char y[16] ;
 strcpy(y,Edit7->Text.c_str());
        if (ComboBox5->Text == "По Фамилии")
        {
             for(int i = 0 ; i<=nrec;)
             {
                POINT3:
                for(int o = 0 ; o<16;)
                {
                POINT1:
                if (data[i].Surname[o+1] == '\0')
                  {
                strcpy(empt[0].Surname,data[i].Surname);
                strcpy(empt[0].Name,data[i].Name);
                strcpy(empt[0].Otchestvo,data[i].Otchestvo);
                empt[0].Zarplata = data[i].Zarplata;
                goto POINT2;
                           }

                 if (data[i].Surname[o] == y[o])
                 {
                 //ShowMessage(data[i].Surname[o]) ;
                 ++o;
                 goto POINT1;
                 }

                 else if (data[i].Surname[o] != y[o])
                 {
                 i++;
                 goto POINT3;
                 }
                 }
     POINT2:
     char buf[16];
     strcpy(buf,empt[0].Surname);
     Edit8->Text = buf;
     strcpy(buf,empt[0].Name)  ;
     Edit9->Text = buf;
     strcpy(buf,empt[0].Otchestvo);
     Edit10->Text = buf;
     long d = empt[0].Zarplata;
     Edit11->Text = d;
     ListView1->SetFocus();
        ListView1->Items->Item[i]->Selected=true;
          break;
         }

          }


          if (ComboBox5->Text == "По Имени")
{
             for(int i = 0 ; i<=nrec;)
{
                POINT4:
                for(int o = 0 ; o<16;)
                {
                POINT6:
                if (data[i].Name[o+1] == '\0')
                  {
                strcpy(empt[0].Surname,data[i].Surname);
                strcpy(empt[0].Name,data[i].Name);
                strcpy(empt[0].Otchestvo,data[i].Otchestvo);
                empt[0].Zarplata = data[i].Zarplata;
                goto POINT5;
                           }

                 if (data[i].Name[o] == y[o])
                 {
                 //ShowMessage(data[i].Surname[o]) ;
                 ++o;
                 goto POINT6;
                 }

                 else if (data[i].Name[o] != y[o])
                 {
                 i++;
                 goto POINT4;
                 }
                 }

     POINT5:
     char buf[16];
     strcpy(buf,empt[0].Surname);
     Edit8->Text = buf;
     strcpy(buf,empt[0].Name)  ;
     Edit9->Text = buf;
     strcpy(buf,empt[0].Otchestvo);
     Edit10->Text = buf;
     long d = empt[0].Zarplata;
     Edit11->Text = d;
     ListView1->SetFocus();
        ListView1->Items->Item[i]->Selected=true;
          break;
         }

          }

          if (ComboBox5->Text == "По Отчеству")
{
             for(int i = 0 ; i<=nrec;)
{
                POINT7:
                for(int o = 0 ; o<16;)
                {
                POINT8:
                if (data[i].Otchestvo[o+1] == '\0')
                  {
                strcpy(empt[0].Surname,data[i].Surname);
                strcpy(empt[0].Name,data[i].Name);
                strcpy(empt[0].Otchestvo,data[i].Otchestvo);
                empt[0].Zarplata = data[i].Zarplata;
                goto POINT9;
                           }

                 if (data[i].Otchestvo[o] == y[o])
                 {
                 //ShowMessage(data[i].Surname[o]) ;
                 ++o;
                 goto POINT8;
                 }

                 else if (data[i].Otchestvo[o] != y[o])
                 {
                 i++;
                 goto POINT7;
                 }
                 }

     POINT9:
     char buf[16];
     strcpy(buf,empt[0].Surname);
     Edit8->Text = buf;
     strcpy(buf,empt[0].Name)  ;
     Edit9->Text = buf;
     strcpy(buf,empt[0].Otchestvo);
     Edit10->Text = buf;
     long d = empt[0].Zarplata;
     Edit11->Text = d;
     ListView1->SetFocus();
        ListView1->Items->Item[i]->Selected=true;
          break;
         }

          }
 /* for(int i = 0 ; i<=nrec;)
{
                POINT3:
                for(int o = 0 ; o<16;)
                {
                POINT1:
                if (data[i].Surname[o+1] == '\0')
                  {
                strcpy(empt[0].Surname,data[i].Surname);
                strcpy(empt[0].Name,data[i].Name);
                strcpy(empt[0].Otchestvo,data[i].Otchestvo);
                empt[0].Zarplata = data[i].Zarplata;
                goto POINT2;
                           }

                 if (data[i].Surname[o] == y[o])
                 {
                 //ShowMessage(data[i].Surname[o]) ;
                 ++o;
                 goto POINT1;
                 }

                 else if (data[i].Surname[o] != y[o])
                 {
                 i++;
                 goto POINT3;
                 }
                 }

     POINT2:
     char buf[16];
     strcpy(buf,empt[0].Surname);
     Edit8->Text = buf;
     strcpy(buf,empt[0].Name)  ;
     Edit9->Text = buf;
     strcpy(buf,empt[0].Otchestvo);
     Edit10->Text = buf;
     long d = empt[0].Zarplata;
     Edit11->Text = d;
     ListView1->SetFocus();
        ListView1->Items->Item[i]->Selected=true;
          break;

         }
         */



void __fastcall TForm1::ZPpoDoljnostiClick(TObject *Sender)
{
  char dol[16];
   sscanf(ComboBox1->Text.c_str(), "%s", &dol);
   strcpy(DOL,dol);

   long sum_dol = 0;                           //суммарная з\п  по должности
   int count = 0;
   for (int i = 0; i<nrec; i++)
   {
      if (strcmp(data[i].Doljnost,dol)==0)
      {
         sum_dol+= data[i].Zarplata;
         count++;
      }
   }
   SUM_DOL = sum_dol;
   B_DOL=false;



   if (count == 0)
   {
      ShowMessage("Такой должности нет в списке");
      B_DOL=true;
      return;
   }
float ave_dol = (float)sum_dol/(float)count;                 //средняя з\п по должности
  AVE_DOL = ave_dol;


  char buf = 16;
  char *ptr = NULL;
  ptr = new char[buf];

  sprintf(ptr,"%.2f",ave_dol);
  sr_job_fl->Text = ptr;
  sprintf(ptr,"%d",sum_dol);
  sum_job_fl->Text = ptr;
  delete [] ptr ;




}
//---------------------------------------------------------------------------




//---------------------------------------------------------------------------

void __fastcall TForm1::ZPpoRejimuClick(TObject *Sender)
{

char rez = 16;
char *ptr = NULL;
ptr = new char [rez];                              //режим работы
   sscanf(ComboBox2->Text.c_str(), "%s", ptr);     // &ptr или ptr

   strcpy(REZ,ptr);

   long sum_rez = 0;                           //суммарная з\п  по режиму работы
   int count = 0;
   for (int i = 0; i<nrec; i++)
   {
      if (strcmp(data[i].Rejim,ptr)==0)
      {
         sum_rez+= data[i].Zarplata;
         count++;
      }
   }
   SUM_REZ = sum_rez;

   B_REZ = false;


   if (count == 0)
   {
      ShowMessage("В списке нет людей с таким режимом работы");
      B_REZ = true;
      return;
   }
   delete [] ptr;

  float ave_rez = (float)sum_rez/(float)count;                 //средняя з\п по режиму
  AVE_REZ = ave_rez;

char buf [16];
sprintf(buf,"%.2f",ave_rez);
sr_rez_fl->Text = buf;
sprintf(buf,"%d",sum_rez);
sum_rez_fl->Text = buf ;


}
//---------------------------------------------------------------------------

void __fastcall TForm1::DownloadClick(TObject *Sender)
{
 if (!OpenDialog1->Execute()) return;
   FILE* inp = fopen(OpenDialog1->FileName.c_str(), "r");

   if (inp == NULL)
   {
      ShowMessage("Файл не найден");
      return;
   }



   while(!feof(inp))
   {
      memset(&data[nrec], 0, sizeof(A));
      fscanf(inp, "%d %s %s %s %d %s %s", &data[nrec].id,&data[nrec].Surname,
             &data[nrec].Name, &data[nrec].Otchestvo, &data[nrec].Zarplata, &data[nrec].Rejim,
             &data[nrec].Doljnost);

      TListItem *Item = ListView1->Items->Add();
      Item->Caption =data[nrec].id;
      Item->SubItems->Add(data[nrec].Surname);
      Item->SubItems->Add(data[nrec].Name);
      Item->SubItems->Add(data[nrec].Otchestvo);
      Item->SubItems->Add(data[nrec].Zarplata);
      Item->SubItems->Add(data[nrec].Rejim);
      Item->SubItems->Add(data[nrec].Doljnost);
      number_id++;
      nrec++;
   }

   A Mass1[100];
   A Mass2[100];

   int count = 0;
   bool b=false;

   for (int i=0;i<nrec;i++)
   {
     for (int j=0;j<i;j++)
     if (strcmp(data[j].Doljnost,data[i].Doljnost)==0)
     b=true;

     if (b==false) strcpy(Mass1[count++].Name,data[i].Doljnost);
     else b=false;
   }

   for (int i=0;i<count;i++)
   ComboBox1->Items->Add(Mass1[i].Name);
   for (int i=0;i<count;i++)
   ComboBox4->Items->Add(Mass1[i].Name);

   count = 0;
   for (int i=0;i<nrec;i++)
   {
     for (int j=0;j<i;j++)
     if (strcmp(data[j].Rejim,data[i].Rejim)==0)
     b=true;

     if (b==false) strcpy(Mass2[count++].Name,data[i].Rejim);
     else b=false;
   }

   for (int i=0;i<count;i++)
   ComboBox2->Items->Add(Mass2[i].Name);
   for (int i=0;i<count;i++)
   ComboBox3->Items->Add(Mass2[i].Name);







   fclose(inp);   //считывание данных
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner):TForm(Owner){}

void __fastcall TForm1::Button3Click(TObject *Sender)
{

if ((Edit1->Text == "")||(Edit2->Text == "")||(Edit3->Text == "")||
   (Edit4->Text == "")||(ComboBox3->Text == "")|| (ComboBox4->Text == "")||(Edit7->Text== "") )
   {
     ShowMessage("Заполните все поля!");
     B_REZ = true;
     return;
   }
                               //проверка на заполнение


   strcpy(data[nrec].Surname,Edit1->Text.c_str());
   strcpy(data[nrec].Name,Edit2->Text.c_str());
   strcpy(data[nrec].Otchestvo,Edit3->Text.c_str());
   sscanf(Edit4->Text.c_str(),"%d",&data[nrec].Zarplata);
   for (int i = 0;i<nrec;i++)
   {
   sscanf(Edit7->Text.c_str(),"%d",&data[nrec].id);
   if(data[i].id== data[nrec].id)
   {
   ShowMessage ("ERROR");
   return;
   }
   else
   sscanf(Edit7->Text.c_str(),"%d",&data[nrec].id) ;
   }
   strcpy(data[nrec].Rejim,ComboBox3->Text.c_str());
   strcpy(data[nrec].Doljnost,ComboBox4->Text.c_str());  //заполнение массива


   TListItem *Item = ListView1->Items->Add();
   Item->Caption = data[nrec].id;
   Item->SubItems->Add(data[nrec].Surname);
   Item->SubItems->Add(data[nrec].Name);
   Item->SubItems->Add(data[nrec].Otchestvo);
   Item->SubItems->Add(data[nrec].Zarplata);    //        не строковый формат (float)
   Item->SubItems->Add(data[nrec].Rejim);          // Режим должность в отдельный файл + сортировка + поиск
   Item->SubItems->Add(data[nrec++].Doljnost);             //заполнение таблицы




   Edit1->Clear();
   Edit2->Clear();
   Edit3->Clear();
   Edit4->Clear();


}
//---------------------------------------------------------------------------


void __fastcall TForm1::DeleteZapisClick(TObject *Sender)
{
 if ( !ListView1->Selected == NULL)
  if (MessageDlg("Вы точно хотите удалить запись?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo,0) == mrYes)
  {


    int num_del = ListView1->ItemIndex;

  for (int i=num_del;i<nrec-1;i++)
  {
     strcpy(data[i].Surname,data[i+1].Surname);
     strcpy(data[i].Name,data[i+1].Name);
     strcpy(data[i].Otchestvo,data[i+1].Otchestvo);
     data[i].Zarplata  = data[i+1].Zarplata;
     strcpy(data[i].Rejim,data[i+1].Rejim);
     strcpy(data[i].Doljnost,data[i+1].Doljnost);
     data[i].id = data[i+1].id;
  }
    massiv_for_id [id_counter]= num_del+1;
    id_counter++;
  nrec--;

    ListView1->Selected->Delete();
  }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClearListViewClick(TObject *Sender)
{
 ListView1->Clear();           //очистка таблицы

   ComboBox1->Items->Clear() ;
   ComboBox2->Items->Clear() ;
   ComboBox3->Items->Clear() ;
   ComboBox4->Items->Clear() ;
   nrec=0;
  }
//---------------------------------------------------------------------------


void __fastcall TForm1::SaveZarplatyClick(TObject *Sender)
{
if (!B_DOL ==true)
  {
     if(!SaveDialog1->Execute()) return;
     FILE* out = fopen(SaveDialog1->FileName.c_str(), "a");
     fprintf(out,"Суммарная зарпата по должности '%s' равна %d руб.\n", DOL, SUM_DOL);
     fprintf(out,"Средняя зарпата по должности '%s' равна %.2f руб.\n", DOL, AVE_DOL);
     fprintf(out,"Суммарная зарпата по режиму работы '%s' равна %d руб.\n", REZ, SUM_REZ);
     fprintf(out,"Средняя зарпата по режиму работы '%s' равна %.2f руб.\n", REZ, AVE_REZ);
     fputs("\n",out);
     fclose(out);                           //вывод сум з\п по должности в файл
     ShowMessage("Данные успешно записаны");
  }
  else
  {
     B_DOL = false;
     ShowMessage("Ошибка записи в файл");
  }
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------



//---------------------------------------------------------------------------


//---------------------------------------------------------------------------






void __fastcall TForm1::Button12Click(TObject *Sender)
{
   Form3->Visible=true;
   Form3->Series1->Clear();
   for (int i=0;i<nrec;i++)
   {
      char buf = 56;
      char *ptr = NULL;
      ptr = new char [buf];

      sprintf(ptr,"%s %s %s",data[i].Surname,data[i].Name,data[i].Otchestvo);
      Form3->Series1->Add(data[i].Zarplata,ptr,clGreen);
      delete [] ptr;
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SaveListViewClick(TObject *Sender)
{
if(!SaveDialog2->Execute())
{
    return;
  }
  FILE* out = fopen(SaveDialog2->FileName.c_str(), "w");
  for (int i=0;i<nrec-1;i++)
  fprintf(out,"%-9s %-11s %-14s %d %-9s %s\n",ListView1->Items->Item[i]->Caption.c_str(),
  ListView1->Items->Item[i]->SubItems->Strings[0].c_str(), ListView1->Items->Item[i]->SubItems->Strings[1].c_str(),
  StrToInt(ListView1->Items->Item[i]->SubItems->Strings[2].c_str()), ListView1->Items->Item[i]->SubItems->Strings[3].c_str(),
  ListView1->Items->Item[i]->SubItems->Strings[4].c_str());

  fprintf(out,"%-9s %-11s %-14s %d %-9s %s",ListView1->Items->Item[nrec-1]->Caption.c_str(),
  ListView1->Items->Item[nrec-1]->SubItems->Strings[0].c_str(), ListView1->Items->Item[nrec-1]->SubItems->Strings[1].c_str(),
  StrToInt(ListView1->Items->Item[nrec-1]->SubItems->Strings[2].c_str()), ListView1->Items->Item[nrec-1]->SubItems->Strings[3].c_str(),
  ListView1->Items->Item[nrec-1]->SubItems->Strings[4].c_str());
  ShowMessage("Данные успешно записаны");

  fclose(out);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
if ((Edit5->Text == "")||(Edit6->Text == ""))
{
ShowMessage("Заполните все поля");
return;
}
else
ShowMessage("Режим работы и должность успешно добавлены");
  ComboBox1->Items->Add(Edit5->Text.c_str());
  ComboBox2->Items->Add(Edit6->Text.c_str());
  ComboBox3->Items->Add(Edit6->Text.c_str());
  ComboBox4->Items->Add(Edit5->Text.c_str());
  Edit6->Clear();
  Edit5->Clear();
}
//---------------------------------------------------------------------------





void __fastcall TForm1::ListView1ColumnClick(TObject *Sender,
      TListColumn *Column)
{
if ((rev==true)||(ColumnToSort != Column->Index)){rev=false;}
    else if((rev==false)||(ColumnToSort != Column->Index)){rev=true;}
    ColumnToSort = Column->Index;
    ((TCustomListView *)Sender)->AlphaSort();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ListView1Compare(TObject *Sender, TListItem *Item1,
      TListItem *Item2, int Data, int &Compare)
{
if (ColumnToSort == 0)
Compare = CompareText(Item1->Caption,Item2->Caption);
else
{
int ix = ColumnToSort - 1;
Compare =
CompareText(Item1->SubItems->Strings[ix], Item2->SubItems->Strings[ix]);
}
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Edit4KeyPress(TObject *Sender, char &Key)
{
    if(IsCharAlpha(Key))
     {
         Key = 0;
            Application->MessageBox("Вводите только цифры","Ошибка", MB_OK | MB_ICONERROR);
         }
}
//---------------------------------------------------------------------------





void __fastcall TForm1::Button5Click(TObject *Sender)
{
 char dol[16];
   sscanf(ComboBox1->Text.c_str(), "%s", &dol);

   long sum_dol = 0;                           //суммарная з\п  по должности
   int count = 0;
   for (int i = 0; i<pp; i++)
   {
      if (strcmp(dat[i].doljnost,dol)==0)
      {
         sum_dol+= dat[i].zarplata;
         count++;
      }
   }




   if (count == 0)
   {
      ShowMessage("Такой должности нет в списке");
      return;
   }
float ave_dol = (float)sum_dol/(float)count;                 //средняя з\п по должности


  char buf = 16;
  char *ptr = NULL;
  ptr = new char[buf];

  sprintf(ptr,"%.2f",ave_dol);
  sr_job_fl->Text = ptr;
  sprintf(ptr,"%d",sum_dol);
  sum_job_fl->Text = ptr;
  delete [] ptr ;

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button6Click(TObject *Sender)
{
char rez = 16;
char *ptr = NULL;
ptr = new char [rez];                              //режим работы
   sscanf(ComboBox2->Text.c_str(), "%s", ptr);     // &ptr или ptr



   long sum_rez = 0;                           //суммарная з\п  по режиму работы
   int count = 0;
   for (int i = 0; i<pp; i++)
   {
      if (strcmp(dat[i].rejim,ptr)==0)
      {
         sum_rez+= dat[i].zarplata;
         count++;
      }
   }





   if (count == 0)
   {
      ShowMessage("В списке нет людей с таким режимом работы");

      return;
   }
   delete [] ptr;

  float ave_rez = (float)sum_rez/(float)count;                 //средняя з\п по режиму


char buf [16];
sprintf(buf,"%.2f",ave_rez);
sr_rez_fl->Text = buf;
sprintf(buf,"%d",sum_rez);
sum_rez_fl->Text = buf ;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button7Click(TObject *Sender)
{
int i = 0;
while(i<nrec)
{
 TListItem *Item = ListView1->Items->Add();
      Item->Caption =data[i].Surname;
      Item->SubItems->Add(data[i].Name);
      Item->SubItems->Add(data[i].Otchestvo);
      Item->SubItems->Add(data[i].Zarplata);
      Item->SubItems->Add(data[i].Rejim);
      Item->SubItems->Add(data[i].Doljnost);
      i++  ;
}
}
//---------------------------------------------------------------------------


void TForm1::search_2()
{
  /*
char b[16] = "Sqew";
char *c = new char[Edit8->Text.Length()+1];
strcpy(c, Edit8->Text.c_str());
int p = Edit8->Text.Length();
        if (strncmp(b,c,p)==0)
        {
              ShowMessage("GOOD");
        }
        else
        ShowMessage("afaf");

           */
        char *stroka = new char[Edit14->Text.Length()+1]; // массив со строкой
        strcpy(stroka, Edit14->Text.c_str());
        int p = Edit14->Text.Length(); // длина строки
        int d = nrec;
  for(int i = 0;i<nrec;i++)
  {
        if(strncmp(data[i].Surname,stroka,p)==0)
        {
        strcpy (dat[pp].surname,data[i].Surname);
        strcpy(dat[pp].name,data[i].Name);
        strcpy(dat[pp].otchestvo,data[i].Otchestvo);
        dat[pp].zarplata = data[i].Zarplata;
        strcpy(dat[pp].rejim,data[i].Rejim);
        strcpy(dat[pp].doljnost,data[i].Doljnost);

          TListItem *Item = ListView1->Items->Add();
      Item->Caption =data[i].Surname;
      Item->SubItems->Add(data[i].Name);
      Item->SubItems->Add(data[i].Otchestvo);
      Item->SubItems->Add(data[i].Zarplata);
      Item->SubItems->Add(data[i].Rejim);
      Item->SubItems->Add(data[i].Doljnost);
        d++;
        pp++;
      }
  }
  for(int i = 0;i<nrec;i++)
  {
   ListView1->Items->Item[0]->Delete();
  }
   ComboBox1->Items->Clear() ;
   ComboBox2->Items->Clear() ;
   ComboBox3->Items->Clear() ;
   ComboBox4->Items->Clear() ;

   A Mass1[100];
   A Mass2[100];

   int count = 0;
   bool b=false;

   for (int i=0;i<pp;i++)
   {
     for (int j=0;j<i;j++)
     if (strcmp(dat[j].doljnost,dat[i].doljnost)==0)
     b=true;

     if (b==false) strcpy(Mass1[count++].Name,dat[i].doljnost);
     else b=false;
   }

   for (int i=0;i<count;i++)
   ComboBox1->Items->Add(Mass1[i].Name);
   for (int i=0;i<count;i++)
   ComboBox4->Items->Add(Mass1[i].Name);

   count = 0;
   for (int i=0;i<pp;i++)
   {
     for (int j=0;j<i;j++)
     if (strcmp(dat[j].rejim,dat[i].rejim)==0)
     b=true;

     if (b==false) strcpy(Mass2[count++].Name,dat[i].rejim);
     else b=false;
   }

   for (int i=0;i<count;i++)
   ComboBox2->Items->Add(Mass2[i].Name);
   for (int i=0;i<count;i++)
   ComboBox3->Items->Add(Mass2[i].Name);

}


void __fastcall TForm1::Button9Click(TObject *Sender)
{
Button5->Visible = true;
Button6->Visible = true;
ZPpoDoljnosti->Visible = false;
ZPpoRejimu->Visible = false;

search_2();
}
//---------------------------------------------------------------------------





void __fastcall TForm1::Button10Click(TObject *Sender)
{
ComboBox1->Items->Clear() ;
ComboBox2->Items->Clear() ;
ComboBox3->Items->Clear() ;
ComboBox4->Items->Clear() ;
 ListView1->Clear();
 pp = 0;
 Button5->Visible = false;
 Button6->Visible = false;
 ZPpoDoljnosti->Visible = true;
 ZPpoRejimu->Visible = true;
 for(int i = 0;i<nrec;i++)
 {
  TListItem *Item = ListView1->Items->Add();
      Item->Caption =data[i].id;
      Item->SubItems->Add(data[i].Surname);
      Item->SubItems->Add(data[i].Name);
      Item->SubItems->Add(data[i].Otchestvo);
      Item->SubItems->Add(data[i].Zarplata);
      Item->SubItems->Add(data[i].Rejim);
      Item->SubItems->Add(data[i].Doljnost);
 }


 A Mass1[100];
   A Mass2[100];

   int count = 0;
   bool b=false;

   for (int i=0;i<nrec;i++)
   {
     for (int j=0;j<i;j++)
     if (strcmp(data[j].Doljnost,data[i].Doljnost)==0)
     b=true;

     if (b==false) strcpy(Mass1[count++].Name,data[i].Doljnost);
     else b=false;
   }

   for (int i=0;i<count;i++)
   ComboBox1->Items->Add(Mass1[i].Name);
   for (int i=0;i<count;i++)
   ComboBox4->Items->Add(Mass1[i].Name);

   count = 0;
   for (int i=0;i<nrec;i++)
   {
     for (int j=0;j<i;j++)
     if (strcmp(data[j].Rejim,data[i].Rejim)==0)
     b=true;

     if (b==false) strcpy(Mass2[count++].Name,data[i].Rejim);
     else b=false;
   }

   for (int i=0;i<count;i++)
   ComboBox2->Items->Add(Mass2[i].Name);
   for (int i=0;i<count;i++)
   ComboBox3->Items->Add(Mass2[i].Name);

}
//---------------------------------------------------------------------------





void __fastcall TForm1::Button2Click(TObject *Sender)
{
if (!OpenDialog1->Execute()) return;
   FILE* inp = fopen(OpenDialog1->FileName.c_str(), "r");

   if (inp == NULL)
   {
      ShowMessage("Файл не найден");      
      return;
   }

for (int i = 0;i<nrec;i++)
   {
      fscanf(inp, "%d %d %d %d %d ", &ZP[i].Jan,&ZP[i].Feb,
             &ZP[i].Mar, &ZP[i].Apr, &ZP[i].May);
                   TListItem *Item = Form5->ListView2->Items->Add();
      Item->Caption =data[i].id;
      Item->SubItems->Add(ZP[i].Jan);
      Item->SubItems->Add(ZP[i].Feb);
      Item->SubItems->Add(ZP[i].Mar);
      Item->SubItems->Add(ZP[i].Apr);
      Item->SubItems->Add(ZP[i].May);
             }
          Form5->Visible = true;


}
//---------------------------------------------------------------------------

