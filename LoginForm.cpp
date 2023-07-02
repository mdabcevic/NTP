//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "LoginForm.h"
#include "TestWindow.h"
#include "EmployeesForm.h"
#include "DepartmentsForm.h"
#include "ExpensesInputInfoForm.h"
#include "TravelWarrantInputInfoForm.h"
#include "TravelWarrantsForm.h"
#include "ClientsInfoForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
void __fastcall TForm1::isRegisterClick(TObject *Sender)
{
//Show additional input information needed for registering.
if (isRegister->Checked) {
		pwConfirmLabel->Visible = true;
		pwConfirmBox->Visible = true;
		emailLabel->Visible = true;
		emailBox->Visible = true;
		loginButton->Top = 376;
		loginButton->Caption = "Register";
	}
//Hide additional input information needed for registering.
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
    //move this to onShow + set isRegister to false
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
	//load theme and font for window (INI)
	DataModule1->themeHelper.LoadSection("CURRENT THEME");
	Form1->Color = DataModule1->themeHelper.backgroundColour;
	Form1->Font->Color = DataModule1->themeHelper.textColour;
	DataModule1->fontHelper.LoadSection("CURRENT FONT");
	Form1->Font->Name = DataModule1->fontHelper.fontName;
	Form1->Font->Size = DataModule1->fontHelper.textHeight;

	//Auto-fill credentials (Windows Registry)
	DataModule1->wrSettingsHelper.LoadSettings();
	Form1->isRememberMe->Checked = DataModule1->wrSettingsHelper.isRememberMe;
	if (DataModule1->wrSettingsHelper.isRememberMe) {
		Form1->usernameBox->Text = DataModule1->wrSettingsHelper.username;
		Form1->pwBox->Text = DataModule1->wrSettingsHelper.password;
	}

}
//---------------------------------------------------------------------------


//Deletes settings in Windows Registry when isRegister is unchecked
void __fastcall TForm1::isRememberMeClick(TObject *Sender)
{
	if(!Form1->isRememberMe->Checked){
		DataModule1->wrSettingsHelper.DeleteSettings();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	Form4->ShowModal();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
    Form5->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
    Form8->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BClick(TObject *Sender)
{
    Form7->CreateMode();
    Form7->ShowModal();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button4Click(TObject *Sender)
{

    Form9->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
    Form10->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
	DataModule1->purposesHelper.SaveHardcoded();
	DataModule1->purposesHelper.ReadFromFile();
	ShowMessage(DataModule1->purposesHelper.allPurposes[1].name);
}
//---------------------------------------------------------------------------

