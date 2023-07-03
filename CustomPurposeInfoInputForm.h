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
//---------------------------------------------------------------------------
class TForm11 : public TForm
{
__published:	// IDE-managed Components
	TLabeledEdit *purposeNameBox;
	TLabeledEdit *purposeDescBox;
	TNumberBox *purposeCodeBox;
	TLabel *Label1;
	TUpDown *UpDown1;
	TCheckBox *isClassified;
	TLabel *Label2;
	TButton *Button1;
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm11(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm11 *Form11;
//---------------------------------------------------------------------------
#endif
