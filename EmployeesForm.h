//---------------------------------------------------------------------------

#ifndef EmployeesFormH
#define EmployeesFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm4 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TDBGrid *DBGrid1;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TRadioButton *NoSortOption;
	TRadioButton *DepartmentSortOption;
	TRadioButton *LnSortOption;
	TRadioButton *AscSortOption;
	TRadioButton *DescSortOption;
	TRadioButton *FnSortOption;
	TGroupBox *GroupBox1;
	TGroupBox *GroupBox2;
	TGroupBox *GroupBox3;
	TRadioButton *FnFilterOption;
	TRadioButton *LnFilterOption;
	TRadioButton *DepartmentFilterOption;
	TEdit *FilterBox;
	TButton *ClearFilter;
	TButton *ReportPrint;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Sort(TObject *Sender);
    void __fastcall Filter(TObject *Sender);
	void __fastcall ClearFilterClick(TObject *Sender);
	void __fastcall ReportPrintClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm4(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif
