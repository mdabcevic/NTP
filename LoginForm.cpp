//---------------------------------------------------------------------------
#include "CountryInfoService.h"
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
#include "AvatarGeneration.h"
#include "DownloadResourcesForm.h"
#include "PreparationThread.h"
#include "LoadIconsThread.h"
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
		loginButton->Top = 350;
		loginButton->Caption = "Register";
	}
//Hide additional input information needed for registering.
	else{
		pwConfirmLabel->Visible = false;
		pwConfirmBox->Visible = false;
		emailLabel->Visible = false;
		emailBox->Visible = false;
		loginButton->Top = 225;
        loginButton->Caption = "Login";
	}
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
    //move this to onShow + set isRegister to false
	loginButton->Top = 224;

	translation["ActionLabel"] = {
		{
			{"EN", "What would you like to do?"},
			{"HR", "Odaberite željenu radnju:"}

		}
	};

	translation["ElseBox"] = {
		{
			{"EN", "Something else..."},
			{"HR", "Ostale radnje"}
		}
	};

	translation["AddExpensesButton"] = {
		{
			{"EN", "Upload travel expenses"},
			{"HR", "Priložite račune"}
		}
	};

	translation["AddPurposeButton"] = {
		{
			{"EN", "Add a purpose"},
			{"HR", "Dodajte svrhu putovanja"}
		}
	};

	translation["CreateAvatarButton"] = {
		{
			{"EN", "Create new profile picture"},
			{"HR", "Izradite profilnu sliku"}
		}
	};

	translation["DownloadButton"] = {
		{
			{"EN", "Download company resources"},
			{"HR", "Preuzmite materijale"}
		}
	};

	translation["SeeDepartments"] = {
		{
			{"EN", "All departments"},
			{"HR", "Pregled svih odjela"}
		}
	};

	translation["EmployeesBox"] = {
		{
			{"EN", "Employees, clients and cars"},
			{"HR", "Zaposlenici, klijenti i automobili"}
		}
	};

    translation["AddCar"] = {
		{
			{"EN", "Add new company car"},
			{"HR", "Upišite vozilo"}
		}
	};

	translation["AddClient"] = {
		{
			{"EN", "Add new client"},
			{"HR", "Upišite klijenta na popis"}
		}
	};

	translation["AddEmployee"] = {
		{
			{"EN", "Add new employee"},
			{"HR", "Upišite zaposlenika"}
		}
	};

	translation["AllCars"] = {
		{
			{"EN", "See all company cars"},
			{"HR", "Pregled svih vozila"}
		}
	};

	translation["AllEmployees"] = {
		{
			{"EN", "See all employees"},
			{"HR", "Pregled svih zaposlenika"}
		}
	};

	translation["SeeClients"] = {
		{
			{"EN", "See all clients"},
			{"HR", "Pregled svih klijenata"}
		}
	};

	translation["isRegister"] = {
		{
			{"EN", "I'd like to register"},
			{"HR", "Želim se registrirati"}
		}
	};

	translation["isRememberMe"] = {
		{
			{"EN", "Remember me"},
			{"HR", "Zapamti postavke za prijavu"}
		}
	};

	translation["loginButton"] = {
		{
			{"EN", "Login"},
			{"HR", "Prijava"}
		}
	};

	translation["pwConfirmLabel"] = {
		{
			{"EN", "Password confirmation:"},
			{"HR", "Potvrdite lozinku:"}
		}
	};

	translation["pwLabel"] = {
		{
			{"EN", "Password"},
			{"HR", "Lozinka"}
		}
	};

	translation["usernameLabel"] = {
		{
			{"EN", "Username: "},
			{"HR", "Korisničko ime: "}
		}
	};

	translation["DepartmentLabel"] = {
		{
			{"EN", "Department: "},
			{"HR", "Odjel: "}
		}
	};

	translation["EmployeeIDLabel"] = {
		{
			{"EN", "Code: "},
			{"HR", "Šifra radnika: "}
		}
	};

	translation["FirstNameLabel"] = {
		{
			{"EN", "First Name: "},
			{"HR", "Ime: "}
		}
	};

	translation["SecondNameLabel"] = {
		{
			{"EN", "Last Name: "},
			{"HR", "Prezime: "}
		}
	};

	translation["PhoneLabel"] = {
		{
			{"EN", "Phone: "},
			{"HR", "Broj mobitela: "}
		}
	};

	translation["PIDLabel"] = {
		{
			{"EN", "PID"},
			{"HR", "OIB"}
		}
	};

    translation["AddPurposeButton"] = {
		{
			{"EN", "Add a purpose"},
			{"HR", "Dodajte svrhu putovanja"}
		}
	};

	translation["Username2Label"] = {
		{
			{"EN", "Username: "},
			{"HR", "Korisničko ime: "}
		}
	};

	translation["WelcomeLabel"] = {
		{
			{"EN", "Welcome!"},
			{"HR", "Dobrodošli!"}
		}
	};

	translation["WarrantsBox"] = {
		{
			{"EN", "Warrants..."},
			{"HR", "Putni nalozi..."}
		}
	};

	translation["AllWarrants"] = {
		{
			{"EN", "See all"},
			{"HR", "Pregled..."}
		}
	};

	translation["AuthorizeButton"] = {
		{
			{"EN", "Authorize"},
			{"HR", "Potpišite..."}
		}
	};

	translation["NewWarrant"] = {
		{
			{"EN", "Add new"},
			{"HR", "Kreirajte nalog"}
		}
	};

}
//---------------------------------------------------------------------------
void __fastcall TForm1::loginButtonClick(TObject *Sender)
{



//ShowMessage(DataModule1->service->CountryFlag("HR"));
//TO DO:

//grananje:


	//Registration
	if(isRegister->Checked){
		if(pwBox->Text == pwConfirmBox->Text){
			//start Registration process
			DataModule1->Registration(usernameBox->Text, pwBox->Text, emailBox->Text);
            isRegister->Checked = false;
            return;
		}
	}
	//Login
	else{
		//try to log in
		if(DataModule1->Login(usernameBox->Text, pwBox->Text)){
			VisualChangeLogin();
            //save settings - move to its own function
			if(isRememberMe->Checked){
                DataModule1->wrSettingsHelper.isRememberMe = true;
				DataModule1->wrSettingsHelper.username = usernameBox->Text;
				DataModule1->wrSettingsHelper.password = pwBox->Text;
				DataModule1->wrSettingsHelper.SaveSettings();
			}
		}
		else{
            return;
        }

		//thread here!
		Preparation *threadedPrep = new Preparation(false);
        //move to thread after UI makeover
		DataModule1->CheckAuthentication();
		//move to toolbar
		DataModule1->MakeAnnouncement("test");
        DataModule1->CheckForAnnouncement();
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormShow(TObject *Sender)
{
	//move into thread with keygen, sendkey & sendJSON
    Inconvenient();
    LoadIcons *threadedLoad = new LoadIcons(false);



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
	else {
        DataModule1->wrSettingsHelper.DeleteSettings();
    }

}
//---------------------------------------------------------------------------


//Deletes settings in Windows Registry when isRegister is unchecked
void __fastcall TForm1::isRememberMeClick(TObject *Sender)
{
	if(!Form1->isRememberMe->Checked){
		DataModule1->wrSettingsHelper.DeleteSettings();
	}
	//move saving from test window
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AddPurposeButtonClick(TObject *Sender)
{
	Form11->ShowModal();

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


void __fastcall TForm1::WarrantsButtonClick(TObject *Sender)
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
	Form11->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
    Form12->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
	//Form13->ShowModal();       moved to dll
	TForm13 *Download = new TForm13(this);
	Download->ShowModal();


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
{
	//Form14->ShowModal();      moved to dll
	TForm14 *Avatars = new TForm14(this);
    Avatars->ShowModal();
}
//---------------------------------------------------------------------------

void TForm1::ShowImg(TImage* image, TMemoryStream* memory){
	image->Picture->LoadFromStream(memory);
}

void __fastcall TForm1::ResetFont2Click(TObject *Sender)
{
	DataModule1->wrSettingsHelper.DeleteSettings();
	DataModule1->fontHelper.ResetToDefault();
	DataModule1->themeHelper.ResetToDefault();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Dark1Click(TObject *Sender)
{
	DataModule1->themeHelper.LoadSection("DARK THEME");
	DataModule1->themeHelper.SaveCurrent();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Light1Click(TObject *Sender)
{
	DataModule1->themeHelper.LoadSection("LIGHT THEME");
    DataModule1->themeHelper.SaveCurrent();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Default1Click(TObject *Sender)
{
    DataModule1->themeHelper.ResetToDefault();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Small1Click(TObject *Sender)
{
	DataModule1->fontHelper.LoadSection("SMALL FONT");
	DataModule1->fontHelper.SaveCurrent();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Medium1Click(TObject *Sender)
{
	DataModule1->fontHelper.LoadSection("MEDIUM FONT");
	DataModule1->fontHelper.SaveCurrent();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Medium2Click(TObject *Sender)
{
    DataModule1->fontHelper.LoadSection("LARGE FONT");
	DataModule1->fontHelper.SaveCurrent();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ResetTheme1Click(TObject *Sender)
{
    DataModule1->themeHelper.ResetToDefault();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ResetFont1Click(TObject *Sender)
{
    DataModule1->fontHelper.ResetToDefault();
}
//---------------------------------------------------------------------------
void TForm1::VisualChangeLogin()
{
	Form1->UserInfoRibbon->Visible = true;
	Form1->UserInfoRibbon->Top = 48;
	Form1->UserInfoRibbon->Left = 15;
	ActionLabel->Visible = true;
	ActionLabel->Top = 48;
	ActionLabel->Left = 248;
	WarrantsBox->Visible = true;
	WarrantsBox->Top = 82;
	WarrantsBox->Left = 248;
	EmployeesBox->Visible = true;
	EmployeesBox->Top = 163;
	EmployeesBox->Left = 248;
    ElseBox->Visible = true;
	ElseBox->Top = 301;
    ElseBox->Left = 248;


	//hide login stuff
	usernameLabel->Visible = false;
	usernameBox->Visible = false;
	pwLabel->Visible = false;
	pwBox->Visible = false;
	pwConfirmLabel->Visible = false;
	pwConfirmBox->Visible = false;
	loginButton->Visible = false;
	isRegister->Visible = false;
    isRememberMe->Visible = false;
}
//---------------------------------------------------------------------------
void TForm1::Inconvenient()
{
	WarrantsBox->SendToBack();
}
void __fastcall TForm1::AllWarrantsClick(TObject *Sender)
{
    Form9->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::NewWarrantClick(TObject *Sender)
{
    Form7->CreateMode();
    Form7->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AllEmployeesClick(TObject *Sender)
{
	Form4->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DownloadButtonClick(TObject *Sender)
{
	TForm13 *Download = new TForm13(this);
	Download->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CreateAvatarButtonClick(TObject *Sender)
{
	TForm14 *Avatars = new TForm14(this);
	Avatars->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SeeDepartmentsClick(TObject *Sender)
{
	Form5->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AllCarsClick(TObject *Sender)
{
	Form12->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SeeClientsClick(TObject *Sender)
{
	Form10->ShowModal();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::ImgHrClick(TObject *Sender)
{
	DataModule1->translateForm(this, "HR", translation);
	DataModule1->translateForm(Form3, "HR", Form3->translation);
	DataModule1->translateForm(Form10, "HR", Form10->translation);
	DataModule1->translateForm(Form12, "HR", Form12->translation);
	DataModule1->translateForm(Form11, "HR", Form11->translation);
	DataModule1->translateForm(Form5, "HR", Form5->translation);
	DataModule1->translateForm(Form6, "HR", Form6->translation);
	DataModule1->translateForm(Form4, "HR", Form4->translation);
	DataModule1->translateForm(Form7, "HR", Form7->translation);
	DataModule1->translateForm(Form9, "HR", Form9->translation);
	DataModule1->translateForm(Form8, "HR", Form8->translation);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ImgEnClick(TObject *Sender)
{
	DataModule1->translateForm(this, "EN", translation);
    DataModule1->translateForm(Form3, "EN", Form3->translation);
	DataModule1->translateForm(Form10, "EN", Form10->translation);
	DataModule1->translateForm(Form12, "EN", Form12->translation);
	DataModule1->translateForm(Form11, "EN", Form11->translation);
	DataModule1->translateForm(Form5, "EN", Form5->translation);
	DataModule1->translateForm(Form6, "EN", Form6->translation);
	DataModule1->translateForm(Form4, "EN", Form4->translation);
	DataModule1->translateForm(Form7, "EN", Form7->translation);
	DataModule1->translateForm(Form9, "EN", Form9->translation);
    DataModule1->translateForm(Form8, "EN", Form8->translation);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AddCarClick(TObject *Sender)
{
    Form3->AddCarMode();
    Form3->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AddEmployeeClick(TObject *Sender)
{
    Form6->CreateMode();
	Form6->ShowModal();
}
//---------------------------------------------------------------------------

