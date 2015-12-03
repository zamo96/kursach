//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <ValEdit.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ADODB.hpp>
#include <Chart.hpp>
#include <DB.hpp>
#include <DbChart.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include <Dialogs.hpp>
#include <jpeg.hpp>

//---------------------------------------------------------------------------
class TSalaries_of_employees : public TForm
{
__published:	// IDE-managed Components
        TListView *EmploersView;
        TPanel *Panel2;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TEdit *Edit1;
        TEdit *Edit2;
        TEdit *Edit3;
        TEdit *Edit4;
        TButton *Add_sotr;
        TButton *DeleteZapis;
        TButton *SaveListView;
        TButton *ClearListView;
        TEdit *sum_rez_fl;
        TEdit *sr_job_fl;
        TEdit *sum_job_fl;
        TEdit *sr_rez_fl;
        TComboBox *ComboBox1;
        TButton *ZPpoDoljnosti;
        TButton *ZPpoRejimu;
        TComboBox *ComboBox2;
        TButton *Download;
        TOpenDialog *OpenDialog1;
        TSaveDialog *SaveDialog1;
        TSaveDialog *SaveDialog2;
        TButton *SaveZarplaty;
        TButton *graph;
        TPanel *save_zar;
        TSplitter *Splitter1;
        TSplitter *Splitter2;
        TSplitter *Splitter3;
        TLabel *Label11;
        TComboBox *ComboBox3;
        TComboBox *ComboBox4;
        TImage *Image1;
        TPanel *Panel4;
        TEdit *Edit5;
        TEdit *Edit6;
        TButton *add_dol_rez;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label9;
        TEdit *Edit14;
        TButton *search;
        TButton *return_table;
        TButton *zp_po_dol;
        TButton *zp_po_rej;
        TButton *download_zp;
        TEdit *Edit7;
        TLabel *Label10;
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TTabSheet *TabSheet3;
        TListView *Emploers_no_zp;
        TPanel *main;
        TPanel *Panel1;
        TButton *download_nozp;
        TButton *Delete_bez_zp;
        TListView *ListView3;
        TButton *Button8;
        TButton *change;
        TButton *change_sotr;
        TButton *clear_table;
        TButton *Sort;
        TComboBox *Sortirovka;
        void __fastcall ZPpoDoljnostiClick(TObject *Sender);
        void __fastcall ZPpoRejimuClick(TObject *Sender);
        void __fastcall DownloadClick(TObject *Sender);
        void __fastcall Add_sotrClick(TObject *Sender);
        void __fastcall DeleteZapisClick(TObject *Sender);
        void __fastcall ClearListViewClick(TObject *Sender);
        void __fastcall SaveZarplatyClick(TObject *Sender);
        void __fastcall graphClick(TObject *Sender);
        void __fastcall SaveListViewClick(TObject *Sender);
        void __fastcall add_dol_rezClick(TObject *Sender);
        void __fastcall EmploersViewColumnClick(TObject *Sender,
          TListColumn *Column);
        void __fastcall EmploersViewCompare(TObject *Sender, TListItem *Item1,
          TListItem *Item2, int Data, int &Compare);
        void __fastcall Edit4KeyPress(TObject *Sender, char &Key);
        void __fastcall zp_po_dolClick(TObject *Sender);
        void __fastcall zp_po_rejClick(TObject *Sender);
        void __fastcall Delete_bez_zpClick(TObject *Sender);
        void __fastcall searchClick(TObject *Sender);
        void __fastcall return_tableClick(TObject *Sender);
        void __fastcall download_zpClick(TObject *Sender);
        void __fastcall TabSheet2Show(TObject *Sender);
        void __fastcall TabSheet1Show(TObject *Sender);
        void __fastcall download_nozpClick(TObject *Sender);
        void __fastcall TabSheet3Show(TObject *Sender);
        void __fastcall changeClick(TObject *Sender);
        void __fastcall change_sotrClick(TObject *Sender);
        void __fastcall clear_tableClick(TObject *Sender);
        void __fastcall SortClick(TObject *Sender);
        void __fastcall Button8Click(TObject *Sender);
private:
public:
typedef struct
{
 int Jan;
 int Feb;
 int Mar;
 int Apr;
 int May;
 int pers;
 char name_surname[16];
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
A bezZP[100];
A sort[100];
void search_2();
void build(A* uk,TListView * lst,bool type);
void build_massiv();
void build_listv3();
void build_MandL3();
void build_lv3(D* uk,int i)  ;
void build_lv_nozp();
void download_no_zp();
void build_for_search(int i);
void sortirovka(bool param);
        __fastcall TSalaries_of_employees(TComponent* Owner);
};



//---------------------------------------------------------------------------
extern PACKAGE TSalaries_of_employees *Salaries_of_employees;
//---------------------------------------------------------------------------
#endif





