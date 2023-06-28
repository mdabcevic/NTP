//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "LoginForm.h"
#include "TestWindow.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
void __fastcall TForm1::isRegisterClick(TObject *Sender)
{
if (isRegister->Checked) {
		pwConfirmLabel->Visible = true;
		pwConfirmBox->Visible = true;
		emailLabel->Visible = true;
		emailBox->Visible = true;
		loginButton->Top = 376;
		loginButton->Caption = "Register";
	}
	else{
		pwConfirmLabel->Visible = false;
		pwConfirmBox->Visible = false;
		emailLabel->Visible = false;
		emailBox->Visible = false;
		loginButton->Top = 256;
        loginButton->Caption = "Login";
	}
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	loginButton->Top = 256;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::loginButtonClick(TObject *Sender)
{
//TO DO:

//grananje:

//1. registracija:
//1.1 provjerava dostupnost info (username i pw)
//a) false > warning message: username/email vec u uporabi
//b) true > pw i confirm match (false > warning msg: password mismatch
//true > 1.2 INSERT INTO radnik (username, email, HASHED pw)
//1.3 pokreni LOGIN nakon uspjesne registracije, instant login

//2. login:
//2.1 pronadji username (false > wm: pogresan unos)
//2.1.1 isAdmin polje checked => usporedi u bazi: (false > wm: niste administrator)
//2.2 HASH pw unos i usporedi u bazi (sol + dinamicka + papar)
//2.3 pokreni LOGIN

// Create an instance of Window2
	TForm2 *testwindow = new TForm2(this);

    // Show Window2
	testwindow->Show();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormShow(TObject *Sender)
{
	DataModule1->themeHelper.LoadSection("CURRENT THEME");
	Form1->Color = DataModule1->themeHelper.backgroundColour;
	Form1->Font->Color = DataModule1->themeHelper.textColour;
	DataModule1->fontHelper.LoadSection("DEFAULT FONT");
	Form1->Font->Name = DataModule1->fontHelper.fontName;
	Form1->Font->Size = DataModule1->fontHelper.textHeight;

}
//---------------------------------------------------------------------------


