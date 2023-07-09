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
#include <map>
//---------------------------------------------------------------------------
class TForm4 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Title;
	TDBGrid *DBGrid1;
	TButton *AddButton;
	TButton *DeleteButton;
	TButton *EditButton;
	TRadioButton *NoSortOption;
	TRadioButton *DepartmentSortOption;
	TRadioButton *LnSortOption;
	TRadioButton *AscSortOption;
	TRadioButton *DescSortOption;
	TRadioButton *FnSortOption;
	TGroupBox *SortingBox;
	TGroupBox *Sorting2Box;
	TGroupBox *FilteringBox;
	TRadioButton *FnFilterOption;
	TRadioButton *LnFilterOption;
	TRadioButton *DepartmentFilterOption;
	TEdit *FilterBox;
	TButton *ClearFilter;
	TButton *ReportPrint;
	TGroupBox *ReportBox;
	TRadioButton *PDFRadio;
	TRadioButton *RDFRadio;
	void __fastcall AddButtonClick(TObject *Sender);
	void __fastcall DeleteButtonClick(TObject *Sender);
	void __fastcall EditButtonClick(TObject *Sender);
	void __fastcall Sort(TObject *Sender);
    void __fastcall Filter(TObject *Sender);
	void __fastcall ClearFilterClick(TObject *Sender);
	void __fastcall ReportPrintClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm4(TComponent* Owner);
	std::map<String, std::map<String, String>> translation;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif
