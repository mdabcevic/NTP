//---------------------------------------------------------------------------

#ifndef LoginFormH
#define LoginFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *usernameLabel;
	TLabel *pwLabel;
	TEdit *usernameBox;
	TEdit *pwBox;
	TCheckBox *isRegister;
	TCheckBox *isAdmin;
	TLabel *pwConfirmLabel;
	TEdit *pwConfirmBox;
	TLabel *emailLabel;
	TEdit *emailBox;
	TButton *loginButton;
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
