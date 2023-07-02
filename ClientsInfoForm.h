//---------------------------------------------------------------------------

#ifndef ClientsInfoFormH
#define ClientsInfoFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <System.Classes.hpp>
#include <System.JSON.hpp>
//---------------------------------------------------------------------------
class TForm10 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Title;
	TListView *ListView1;
private:	// User declarations
public:		// User declarations
	__fastcall TForm10(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm10 *Form10;
//---------------------------------------------------------------------------
#endif
