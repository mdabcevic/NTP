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
//---------------------------------------------------------------------------
class TForm8 : public TForm
{
__published:	// IDE-managed Components
	TCheckBox *isToll;
	TCheckBox *isHospitality;
	TCheckBox *isParking;
	TCheckBox *isAccomodation;
	TCheckBox *isOther;
	TLabel *Label1;
	TDBImage *AttachmentPreview;
	TButton *Button1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm8(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm8 *Form8;
//---------------------------------------------------------------------------
#endif
