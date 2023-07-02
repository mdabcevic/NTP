//---------------------------------------------------------------------------

#ifndef LoginFormH
#define LoginFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Graphics.hpp> // Convert from hex to TColor
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
	TCheckBox *isRememberMe;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	void __fastcall isRegisterClick(TObject *Sender);
	void __fastcall loginButtonClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall isRememberMeClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
