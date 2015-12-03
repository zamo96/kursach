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
#include <Dialogs.hpp>


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSalaries_of_employees *Salaries_of_employees;



//--------------------------------------------------------------------------
     int counter = 0;
     int selected;
     int cgounter_for_id = 0;
     int massiv_for_id [20];
        int gcount = 0;
     int id_counter = 0;
      int pp = 0;
      int number_id=0;
       bool rev=true;
       int nrec2 = 0;
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






int nrec = 0;

char DOL[16];
float AVE_DOL;
long SUM_DOL;
bool B_DOL;

char REZ[16];
float AVE_REZ;
long SUM_REZ;
bool B_REZ;



void __fastcall TSalaries_of_employees::ZPpoDoljnostiClick(TObject *Sender)
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

void __fastcall TSalaries_of_employees::ZPpoRejimuClick(TObject *Sender)
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
void TSalaries_of_employees:: build_massiv() {
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
      fscanf(inp, "%s %s %s %d %s %s",&data[nrec].Surname,
             &data[nrec].Name, &data[nrec].Otchestvo, &data[nrec].Zarplata, &data[nrec].Rejim,
             &data[nrec].Doljnost);
                    counter++;
                    data[nrec].id = counter;
      number_id++;
      nrec++;
   }
   fclose(inp);
}

void __fastcall TSalaries_of_employees::DownloadClick(TObject *Sender)
{
   build_massiv();
   build(data,EmploersView,true);

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

   for (int i=0;i<count;i++)    {
   ComboBox1->Items->Add(Mass1[i].Name);
   ComboBox4->Items->Add(Mass1[i].Name);
   ComboBox2->Items->Add(Mass2[i].Name);
   ComboBox3->Items->Add(Mass2[i].Name);
   }

   count = 0;
   for (int i=0;i<nrec;i++)
   {
     for (int j=0;j<i;j++)
     if (strcmp(data[j].Rejim,data[i].Rejim)==0)
     b=true;

     if (b==false) strcpy(Mass2[count++].Name,data[i].Rejim);
     else b=false;
   }

}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
__fastcall TSalaries_of_employees::TSalaries_of_employees(TComponent* Owner):TForm(Owner){}

void __fastcall TSalaries_of_employees::Add_sotrClick(TObject *Sender)
{

if ((Edit1->Text == "")||(Edit2->Text == "")||(Edit3->Text == "")||
   (Edit4->Text == "")||(ComboBox3->Text == "")|| (ComboBox4->Text == "")||(Edit7->Text== "") )
   {
     ShowMessage("Заполните все поля!");
     B_REZ = true;
     return;
   }




   for (int i = 0;i<=nrec;i++)
   {
   int a;
   sscanf(Edit7->Text.c_str(),"%i",&a);


   if((data[i].id == a))
   {
   ShowMessage ("Ошибка,сотрудник с таким id уже есть в базе данных");
   return;
   }

   }
     strcpy(data[nrec].Surname,Edit1->Text.c_str());
   strcpy(data[nrec].Name,Edit2->Text.c_str());
   strcpy(data[nrec].Otchestvo,Edit3->Text.c_str());
   sscanf(Edit4->Text.c_str(),"%d",&data[nrec].Zarplata);


    sscanf(Edit7->Text.c_str(),"%d",&data[nrec].id) ;



   strcpy(data[nrec].Rejim,ComboBox3->Text.c_str());
   strcpy(data[nrec].Doljnost,ComboBox4->Text.c_str());  //заполнение массива


   build(data,EmploersView,false);





   Edit1->Clear();
   Edit2->Clear();
   Edit3->Clear();
   Edit4->Clear();


}
//---------------------------------------------------------------------------


void __fastcall TSalaries_of_employees::DeleteZapisClick(TObject *Sender)
{
 if ( !EmploersView->Selected == NULL)
  if (MessageDlg("Вы точно хотите удалить запись?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo,0) == mrYes)
  {


    int num_del = EmploersView->ItemIndex;

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

    EmploersView->Selected->Delete();
  }


}
//---------------------------------------------------------------------------

void __fastcall TSalaries_of_employees::ClearListViewClick(TObject *Sender)
{
 EmploersView->Clear();           //очистка таблицы

   ComboBox1->Items->Clear() ;
   ComboBox2->Items->Clear() ;
   ComboBox3->Items->Clear() ;
   ComboBox4->Items->Clear() ;
   nrec=0;
   counter = 0;
  }
//---------------------------------------------------------------------------


void __fastcall TSalaries_of_employees::SaveZarplatyClick(TObject *Sender)
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


void __fastcall TSalaries_of_employees::graphClick(TObject *Sender)
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

void __fastcall TSalaries_of_employees::SaveListViewClick(TObject *Sender)
{
if(!SaveDialog2->Execute())
{
    return;
  }
  FILE* out = fopen(SaveDialog2->FileName.c_str(), "w");
  for (int i=0;i<nrec-1;i++)
  {
  fprintf(out,"%i %-9s %-11s %-14s %i %-9s %s\n",StrToInt(EmploersView->Items->Item[i]->Caption.c_str()),
  EmploersView->Items->Item[i]->SubItems->Strings[0].c_str(), EmploersView->Items->Item[i]->SubItems->Strings[1].c_str(),
  EmploersView->Items->Item[i]->SubItems->Strings[2].c_str(), StrToInt(EmploersView->Items->Item[i]->SubItems->Strings[3].c_str()),
  EmploersView->Items->Item[i]->SubItems->Strings[4].c_str(),EmploersView->Items->Item[i]->SubItems->Strings[5].c_str());
  }


  fprintf(out,"%i %-9s %-11s %-14s %i %-9s %s",StrToInt(EmploersView->Items->Item[nrec-1]->Caption.c_str()),
  EmploersView->Items->Item[nrec-1]->SubItems->Strings[0].c_str(), EmploersView->Items->Item[nrec-1]->SubItems->Strings[1].c_str(),
  EmploersView->Items->Item[nrec-1]->SubItems->Strings[2].c_str(), StrToInt(EmploersView->Items->Item[nrec-1]->SubItems->Strings[3].c_str()),
  EmploersView->Items->Item[nrec-1]->SubItems->Strings[4].c_str(),EmploersView->Items->Item[nrec-1]->SubItems->Strings[5].c_str());
  ShowMessage("Данные успешно записаны");


  fclose(out);
}
//---------------------------------------------------------------------------


void __fastcall TSalaries_of_employees::add_dol_rezClick(TObject *Sender)
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





void __fastcall TSalaries_of_employees::EmploersViewColumnClick(TObject *Sender,
      TListColumn *Column)
{
if ((rev==true)||(ColumnToSort != Column->Index)){rev=false;}
    else if((rev==false)||(ColumnToSort != Column->Index)){rev=true;}
    ColumnToSort = Column->Index;
    ((TCustomListView *)Sender)->AlphaSort();
}
//---------------------------------------------------------------------------

void __fastcall TSalaries_of_employees::EmploersViewCompare(TObject *Sender, TListItem *Item1,
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



void __fastcall TSalaries_of_employees::Edit4KeyPress(TObject *Sender, char &Key)
{
    if(IsCharAlpha(Key))
     {
         Key = 0;
            Application->MessageBox("Вводите только цифры","Ошибка", MB_OK | MB_ICONERROR);
         }
}
//---------------------------------------------------------------------------





void __fastcall TSalaries_of_employees::zp_po_dolClick(TObject *Sender)
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


void __fastcall TSalaries_of_employees::zp_po_rejClick(TObject *Sender)
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


void __fastcall TSalaries_of_employees::Delete_bez_zpClick(TObject *Sender)
{
if ( !Emploers_no_zp->Selected == NULL)
  if (MessageDlg("Вы точно хотите удалить запись?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo,0) == mrYes)
  {


    int num_del = Emploers_no_zp->ItemIndex;

  for (int i=num_del;i<cgounter_for_id-1;i++)
  {
     strcpy(bezZP[i].Surname,bezZP[i+1].Surname);
     strcpy(bezZP[i].Name,bezZP[i+1].Name);
     strcpy(bezZP[i].Otchestvo,bezZP[i+1].Otchestvo);
     bezZP[i].Zarplata  = bezZP[i+1].Zarplata;
     strcpy(bezZP[i].Rejim,bezZP[i+1].Rejim);
     strcpy(bezZP[i].Doljnost,bezZP[i+1].Doljnost);
     bezZP[i].id = bezZP[i+1].id;
  }
    cgounter_for_id--;

    Emploers_no_zp->Selected->Delete();
  }

}
//---------------------------------------------------------------------------
  void TSalaries_of_employees::build_for_search(int i)
   {
          TListItem *Item = EmploersView->Items->Add();
     Item->Caption =data[i].id;
      Item->SubItems->Add(data[i].Surname);
      Item->SubItems->Add(data[i].Name);
      Item->SubItems->Add(data[i].Otchestvo);
      Item->SubItems->Add(data[i].Zarplata);
      Item->SubItems->Add(data[i].Rejim);
      Item->SubItems->Add(data[i].Doljnost);
  }
  void TSalaries_of_employees::build(A *uk,TListView * lst,bool type)   {
  if(type){
   for(int i = 0; i<nrec;i++){
   TListItem *Item = lst->Items->Add();
    Item->Caption =uk[i].id;
      Item->SubItems->Add(uk[i].Surname);
      Item->SubItems->Add(uk[i].Name);
      Item->SubItems->Add(uk[i].Otchestvo);
      Item->SubItems->Add(uk[i].Zarplata);
      Item->SubItems->Add(uk[i].Rejim);
      Item->SubItems->Add(uk[i].Doljnost);
      }
      }
      else
      {
        TListItem *Item = lst->Items->Add();
    Item->Caption =data[nrec].id;
      Item->SubItems->Add(uk[nrec].Surname);
      Item->SubItems->Add(uk[nrec].Name);
      Item->SubItems->Add(uk[nrec].Otchestvo);
      Item->SubItems->Add(uk[nrec].Zarplata);
      Item->SubItems->Add(uk[nrec].Rejim);
      Item->SubItems->Add(uk[nrec++].Doljnost);
      }

  }

 void TSalaries_of_employees::build_lv_nozp()
 {
       TListItem *Item = Emploers_no_zp->Items->Add();
      Item->Caption =bezZP[nrec2].id;
      Item->SubItems->Add(bezZP[nrec2].Surname);
      Item->SubItems->Add(bezZP[nrec2].Name);
      Item->SubItems->Add(bezZP[nrec2].Otchestvo);
      Item->SubItems->Add(bezZP[nrec2].Rejim);
      Item->SubItems->Add(bezZP[nrec2].Doljnost);
 }
 void TSalaries_of_employees::download_no_zp()
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
      fscanf(inp, "%s %s %s %s %s",&bezZP[nrec2].Surname,
             &bezZP[nrec2].Name, &bezZP[nrec2].Otchestvo,&bezZP[nrec2].Rejim,
             &bezZP[nrec2].Doljnost);
             counter++;
      bezZP[nrec2].id = counter;
      build_lv_nozp();
      nrec2++;
   }
 }

void TSalaries_of_employees::search_2()
{

        char *stroka = new char[Edit14->Text.Length()+1]; // массив со строкой
        strcpy(stroka, Edit14->Text.c_str());
        int p = Edit14->Text.Length(); // длина строки
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

         build_for_search(i);

        pp++;
      }
  }
  for(int i = 0;i<nrec;i++)
  {
   EmploersView->Items->Item[0]->Delete();
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

   for (int i=0;i<count;i++)  {
   ComboBox1->Items->Add(Mass1[i].Name);
   ComboBox4->Items->Add(Mass1[i].Name);
   }

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
   {
   ComboBox2->Items->Add(Mass2[i].Name);
   ComboBox3->Items->Add(Mass2[i].Name);
   }

}


void __fastcall TSalaries_of_employees::searchClick(TObject *Sender)
{
zp_po_dol->Visible = true;
zp_po_rej->Visible = true;
ZPpoDoljnosti->Visible = false;
ZPpoRejimu->Visible = false;

search_2();
}
//---------------------------------------------------------------------------





void __fastcall TSalaries_of_employees::return_tableClick(TObject *Sender)
{
ComboBox1->Items->Clear() ;
ComboBox2->Items->Clear() ;
ComboBox3->Items->Clear() ;
ComboBox4->Items->Clear() ;
 EmploersView->Clear();
 pp = 0;
 zp_po_dol->Visible = false;
 zp_po_rej->Visible = false;
 ZPpoDoljnosti->Visible = true;
 ZPpoRejimu->Visible = true;
 build(data,EmploersView,true);


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





void __fastcall TSalaries_of_employees::download_zpClick(TObject *Sender)
{
cgounter_for_id = 0;
if (!OpenDialog1->Execute()) return;
   FILE* inp = fopen(OpenDialog1->FileName.c_str(), "r");

   if (inp == NULL)
   {
      ShowMessage("Файл не найден");
      return;
   }

   while(!feof(inp))
   {
     fscanf(inp, "%d %d %d %d %d %d ",&ZP[cgounter_for_id].pers, &ZP[cgounter_for_id].Jan,&ZP[cgounter_for_id].Feb,
   &ZP[cgounter_for_id].Mar, &ZP[cgounter_for_id].Apr, &ZP[cgounter_for_id].May);
   cgounter_for_id++;
   }
   for (int i = 0;i<cgounter_for_id;i++)
   {
   for(int j = 0;j<cgounter_for_id;j++)
   {
   int ct = 0;
    if (bezZP[i].id == ZP[j].pers)
    {
     for(int k = 0;k<nrec;k++){
   if (bezZP[i].id == data[k].id )
   {
   ct = 1;
   }
   }
   if(ct == 0 )
   {
       data[nrec].id = bezZP[i].id ;
       strcpy(data[nrec].Surname,bezZP[i].Surname);
       strcpy(data[nrec].Name,bezZP[i].Name);
       strcpy(data[nrec].Otchestvo,bezZP[i].Otchestvo);
       strcpy(data[nrec].Rejim,bezZP[i].Rejim);
       strcpy(data[nrec].Doljnost,bezZP[i].Doljnost);
       char buf[1024];
       sprintf(buf, "Введите зарплату  %s %s %s", data[nrec].Surname,
         data[nrec].Name,
         data[nrec].Otchestvo);

         AnsiString InputString = InputBox("Зарплата", buf,"");
         int zp = StrToInt(InputString);
         data[nrec].Zarplata = zp;
          build(data,EmploersView,false);
         break;
         }
         }
    }
   }


for (int i = 0;i<cgounter_for_id;i++)
   {

       for (int j = 0; j<nrec;j++)
       {

       if (ZP[i].pers==data[j].id)
       {
       int countof = 0;
       for(int i  = 0 ; i<16;i++)
       {
       if(data[j].Surname[i]=='\0')
       break;
       countof++;
       }
       strcpy(ZP[i].name_surname,data[j].Surname );
       ZP[i].name_surname[countof] = ' ';
       ZP[i].name_surname[countof+1] = data[j].Name[0];
       ZP[i].name_surname[countof+2] = '.';
       ZP[i].name_surname[countof+3] = data[j].Otchestvo[0];
       build_lv3(ZP,i);
         break;
         }

       }


             }


}
//---------------------------------------------------------------------------






void __fastcall TSalaries_of_employees::TabSheet2Show(TObject *Sender)
{
main->Visible = false;
Panel1->Visible = true;
clear_table->Visible = false;
PageControl1->Width =929;
PageControl1->Height = 321;
}
//---------------------------------------------------------------------------




void __fastcall TSalaries_of_employees::TabSheet1Show(TObject *Sender)
{
main->Visible = true;
Panel1->Visible = false;
clear_table->Visible = false;
Emploers_no_zp->Width =561;
PageControl1->Width =569;
PageControl1->Height = 321;
}
//---------------------------------------------------------------------------


void __fastcall TSalaries_of_employees::download_nozpClick(TObject *Sender)
{
download_no_zp();
}

//---------------------------------------------------------------------------


void __fastcall TSalaries_of_employees::TabSheet3Show(TObject *Sender)
{
main->Visible = false;
Panel1->Visible = false;
clear_table->Visible = true;
PageControl1->Width =929;
PageControl1->Height = 321;
}
//---------------------------------------------------------------------------


void __fastcall TSalaries_of_employees::changeClick(TObject *Sender)
{
if (!EmploersView->Selected == NULL) {

int nomerlist = EmploersView->Selected->Index;
selected = nomerlist;
Edit1->Text = data[nomerlist].Surname;
Edit2->Text = data[nomerlist].Name;
Edit3->Text = data[nomerlist].Otchestvo;
Edit4->Text = data[nomerlist].Zarplata;
ComboBox3->Text = data[nomerlist].Rejim;
ComboBox4->Text = data[nomerlist].Doljnost;
}

else
ShowMessage ("Выбирете сотрудника");
}
//---------------------------------------------------------------------------
void TSalaries_of_employees::build_listv3()
{

 for(int i = 0;i<cgounter_for_id;i++) {

   for (int j = 0; j<nrec;j++)
       {

       if (ZP[i].pers==data[j].id)
       {
       TListItem *Item = ListView3->Items->Add();
      Item->Caption =ZP[i].pers;
      Item->SubItems->Add(ZP[i].name_surname);
      Item->SubItems->Add(ZP[i].Jan);
      Item->SubItems->Add(ZP[i].Feb);
      Item->SubItems->Add(ZP[i].Mar);
      Item->SubItems->Add(ZP[i].Apr);
      Item->SubItems->Add(ZP[i].May);
         break;
         }

       }



      }
}
void TSalaries_of_employees::build_lv3(D * uk,int i)
{
   TListItem *Item = ListView3->Items->Add();
      Item->Caption =uk[i].pers;
      Item->SubItems->Add(uk[i].name_surname);
      Item->SubItems->Add(uk[i].Jan);
      Item->SubItems->Add(uk[i].Feb);
      Item->SubItems->Add(uk[i].Mar);
      Item->SubItems->Add(uk[i].Apr);
      Item->SubItems->Add(uk[i].May);
}

 void TSalaries_of_employees::build_MandL3() {

  for(int i = 0;i<cgounter_for_id;i++){
 if (data[selected].id == ZP[i].pers){
 int countof = 0;
       for(int j  = 0 ; j<16;j++)
       {
       if(data[selected].Surname[j]=='\0')
       break;
       countof++;
       }
       strcpy(ZP[i].name_surname,data[selected].Surname);
       ZP[i].name_surname[countof] = ' ';
       ZP[i].name_surname[countof+1] = data[selected].Name[0];
       ZP[i].name_surname[countof+2] = '.';
       ZP[i].name_surname[countof+3] = data[selected].Otchestvo[0];
       break;
 }
}

 }

void __fastcall TSalaries_of_employees::change_sotrClick(TObject *Sender)
{

strcpy(data[selected].Surname,Edit1->Text.c_str());
strcpy(data[selected].Name,Edit2->Text.c_str());
strcpy(data[selected].Otchestvo,Edit3->Text.c_str());
sscanf(Edit4->Text.c_str(),"%d",&data[selected].Zarplata);
strcpy(data[selected].Rejim,ComboBox3->Text.c_str());
strcpy(data[selected].Doljnost,ComboBox4->Text.c_str());

build_MandL3();



EmploersView->Clear();

build(data,EmploersView,true);

  ShowMessage(ZP[selected].name_surname);

 ListView3->Clear();


build_listv3();



}
//---------------------------------------------------------------------------

void __fastcall TSalaries_of_employees::clear_tableClick(TObject *Sender)
{
  ListView3->Clear();
}
//---------------------------------------------------------------------------

void TSalaries_of_employees::sortirovka(bool param)
{
A exsort1[100];

for (int i = 0;i<nrec;i++)
exsort1[i] = data[i];
 for (int i = 0 ; i < nrec ; i++) {
  for (int j = (i+1) ; j<nrec; j++)
  {
  switch(param){
  case true:
    if (exsort1[i].Zarplata > exsort1[j].Zarplata)
   swap(exsort1[i],exsort1[j])  ;
   break;
   case false:
     if (exsort1[i].Surname[0] > exsort1[j].Surname[0])
   swap(exsort1[i],exsort1[j])  ;
   break;
   }
  }
       sort[i] = exsort1[i];
 }
 EmploersView->Clear();
     build(sort,EmploersView,true);
}

void __fastcall TSalaries_of_employees::SortClick(TObject *Sender)
{
switch(Sortirovka->ItemIndex){
 case 0 :
 sortirovka(false);
 break;
 case 1 :
 sortirovka(true);
 break;
}
}
//---------------------------------------------------------------------------




void __fastcall TSalaries_of_employees::Button8Click(TObject *Sender)
{
 Emploers_no_zp->Clear();
}
//---------------------------------------------------------------------------

