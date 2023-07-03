//---------------------------------------------------------------------------

#ifndef TravelWarrantInputInfoFormH
#define TravelWarrantInputInfoFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.CheckLst.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.NumberBox.hpp>
//---------------------------------------------------------------------------
class TForm7 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TDateTimePicker *DepartureDateTime;
	TDateTimePicker *ArrivalDateTime;
	TLabel *DepartureLabel;
	TLabel *ArrivalLabel;
	TLabel *isInternationalLabel;
	TCheckBox *isInternational;
	TCheckListBox *PartnersList;
	TLabel *Label5;
	TCheckListBox *PurposesList;
	TLabel *Label6;
	TLabel *CarSelectionLabel;
	TButtonedEdit *CarSelection;
	TLabel *OdometerStartLabel;
	TLabel *OdometerEndLabel;
	TNumberBox *OdometerStart;
	TNumberBox *OdometerEnd;
	TUpDown *UpDownStart;
	TUpDown *UpDownEnd;
	TLabel *Label10;
	TLabel *TollInfoLabel;
	TLabel *Label12;
	TButton *AddAttachments;
	TButton *WarrantAction;
	TComboBox *TollInfo;
	void __fastcall WarrantActionClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm7(TComponent* Owner);
	void EditMode();
    void CreateMode();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm7 *Form7;
//---------------------------------------------------------------------------
#endif
