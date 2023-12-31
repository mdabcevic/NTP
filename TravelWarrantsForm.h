//---------------------------------------------------------------------------

#ifndef TravelWarrantsFormH
#define TravelWarrantsFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <map>
//---------------------------------------------------------------------------
class TForm9 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Title;
	TDBGrid *DBGrid1;
	TButton *DeleteButton;
	TButton *EditButton;
	TButton *ReportWarrant;
	TGroupBox *GroupBox1;
	TRadioButton *PDFOption;
	TRadioButton *RTFOption;
	TButton *Button1;
	TButton *Button2;
	TCheckBox *CheckBox1;
	TCheckBox *CheckBox2;
	TGroupBox *GroupBox2;
	void __fastcall DeleteButtonClick(TObject *Sender);
	void __fastcall EditButtonClick(TObject *Sender);
	void __fastcall ReportWarrantClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall UpdateFilters(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm9(TComponent* Owner);
    std::map<String, std::map<String, String>> translation;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm9 *Form9;
//---------------------------------------------------------------------------
#endif
