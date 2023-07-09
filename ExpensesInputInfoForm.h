//---------------------------------------------------------------------------

#ifndef ExpensesInputInfoFormH
#define ExpensesInputInfoFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Mask.hpp>
#include "TravelWarrantInputInfoForm.h"
#include <map>
//---------------------------------------------------------------------------
class TForm8 : public TForm
{
__published:	// IDE-managed Components
	TCheckBox *isToll;
	TCheckBox *isHospitality;
	TCheckBox *isParking;
	TCheckBox *isAccomodation;
	TCheckBox *isOther;
	TLabel *Title;
	TDBImage *AttachmentPreview;
	TButton *Upload;
	TDBEdit *ExpenseIDVal;
	TLabel *ExpenseID;
	void __fastcall UploadClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm8(TComponent* Owner);
    std::map<String, std::map<String, String>> translation;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm8 *Form8;
//---------------------------------------------------------------------------
#endif
