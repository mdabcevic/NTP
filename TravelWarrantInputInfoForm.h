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
#include "CompanyCarsForm.h"
#include "ClientsInfoForm.h"
#include "ExpensesInputInfoForm.h"
#include <map>
//---------------------------------------------------------------------------
class TForm7 : public TForm
{
__published:	// IDE-managed Components
	TLabel *TitleGeneral;
	TDateTimePicker *DepartureDateTime;
	TDateTimePicker *ArrivalDateTime;
	TLabel *DepartureLabel;
	TLabel *ArrivalLabel;
	TLabel *isInternationalLabel;
	TCheckBox *isInternational;
	TCheckListBox *PartnersList;
	TCheckListBox *PurposesList;
	TLabel *PurposeLabel;
	TButtonedEdit *CarSelection;
	TLabel *OdometerStartLabel;
	TLabel *OdometerEndLabel;
	TNumberBox *OdometerStart;
	TNumberBox *OdometerEnd;
	TUpDown *UpDownStart;
	TUpDown *UpDownEnd;
	TLabel *CarTitle;
	TLabel *TollInfoLabel;
	TLabel *AttachmentTitle;
	TButton *AddAttachments;
	TButton *WarrantAction;
	TComboBox *TollInfo;
	TButton *CarSelect;
	TButton *PartnersButton;
	void __fastcall WarrantActionClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall CarSelectClick(TObject *Sender);
	void __fastcall PartnersListClick(TObject *Sender);
	void __fastcall AddAttachmentsClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm7(TComponent* Owner);
	void EditMode();
	void CreateMode();
	UnicodeString MergeIntoString(TCheckListBox* list);
	std::map<String, std::map<String, String>> translation;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm7 *Form7;
//---------------------------------------------------------------------------
#endif
