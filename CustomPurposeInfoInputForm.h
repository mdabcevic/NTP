//---------------------------------------------------------------------------

#ifndef CustomPurposeInfoInputFormH
#define CustomPurposeInfoInputFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.NumberBox.hpp>
#include "Data\AllData.h"
#include <map>
//---------------------------------------------------------------------------
class TForm11 : public TForm
{
__published:	// IDE-managed Components
	TLabeledEdit *purposeNameBox;
	TLabeledEdit *purposeDescBox;
	TNumberBox *purposeCodeBox;
	TLabel *CodeLabel;
	TUpDown *UpDown1;
	TCheckBox *isClassified;
	TLabel *Title;
	TButton *SubmitButton;
	void __fastcall SubmitButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm11(TComponent* Owner);
	std::map<String, std::map<String, String>> translation;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm11 *Form11;
//---------------------------------------------------------------------------
#endif
