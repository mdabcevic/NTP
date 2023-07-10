//---------------------------------------------------------------------------

#ifndef LoginFormH
#define LoginFormH
//---------------------------------------------------------------------------
#include "CountryInfoService.h"
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Graphics.hpp>
#include "CustomPurposeInfoInputForm.h"
#include "CompanyCarsForm.h"
#include "DownloadResourcesForm.h"
#include "AllData.h"
#include <Vcl.ExtCtrls.hpp>
#include "AvatarGeneration.h"
#include <Vcl.Menus.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include "EmployeeInfoInputForm.h"
#include <map>

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *usernameLabel;
	TLabel *pwLabel;
	TEdit *usernameBox;
	TEdit *pwBox;
	TCheckBox *isRegister;
	TLabel *pwConfirmLabel;
	TEdit *pwConfirmBox;
	TLabel *emailLabel;
	TEdit *emailBox;
	TButton *loginButton;
	TCheckBox *isRememberMe;
	TImage *ImgHr;
	TImage *ImgEn;
	TMainMenu *MainMenu1;
	TMenuItem *Settings1;
	TMenuItem *hemeSettings1;
	TMenuItem *Dark1;
	TMenuItem *Light1;
	TMenuItem *Default1;
	TMenuItem *FontSettings1;
	TMenuItem *Small1;
	TMenuItem *Medium1;
	TMenuItem *Medium2;
	TMenuItem *Reset;
	TMenuItem *ResetOptions1;
	TMenuItem *ResetTheme1;
	TMenuItem *ResetFont1;
	TMenuItem *ResetFont2;
	TMenuItem *Help1;
	TMenuItem *About1;
	TGroupBox *UserInfoRibbon;
	TImage *Avatar;
	TLabel *WelcomeLabel;
	TLabel *Username2Label;
	TLabel *FirstNameLabel;
	TLabel *SecondNameLabel;
	TLabel *PhoneLabel;
	TLabel *DepartmentLabel;
	TLabel *PIDLabel;
	TLabel *EmployeeIDLabel;
	TMenuItem *Announcements1;
	TMenuItem *Checkforannouncements1;
	TMenuItem *Makeanannouncement1;
	TLabel *ActionLabel;
	TGroupBox *WarrantsBox;
	TButton *AuthorizeButton;
	TButton *AllWarrants;
	TButton *NewWarrant;
	TGroupBox *EmployeesBox;
	TButton *AllEmployees;
	TGroupBox *ElseBox;
	TButton *AddPurposeButton;
	TButton *DownloadButton;
	TButton *CreateAvatarButton;
	TButton *AddExpensesButton;
	TButton *SeeDepartments;
	TButton *AddEmployee;
	TButton *SeeClients;
	TButton *AddClient;
	TButton *AllCars;
	TButton *AddCar;
	TLabel *u1;
	TLabel *f1;
	TLabel *l1;
	TLabel *e1;
	TLabel *p1;
	TLabel *d1;
	TLabel *pid1;
	TLabel *c1;
	TMenuItem *CleanrepositoryBEFORELOGIN1;
	void __fastcall isRegisterClick(TObject *Sender);
	void __fastcall loginButtonClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall isRememberMeClick(TObject *Sender);
	void __fastcall AddPurposeButtonClick(TObject *Sender);
	void __fastcall WarrantsButtonClick(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
	void __fastcall ResetFont2Click(TObject *Sender);
	void __fastcall Dark1Click(TObject *Sender);
	void __fastcall Light1Click(TObject *Sender);
	void __fastcall Default1Click(TObject *Sender);
	void __fastcall Small1Click(TObject *Sender);
	void __fastcall Medium1Click(TObject *Sender);
	void __fastcall Medium2Click(TObject *Sender);
	void __fastcall ResetTheme1Click(TObject *Sender);
	void __fastcall ResetFont1Click(TObject *Sender);
	void __fastcall AllWarrantsClick(TObject *Sender);
	void __fastcall NewWarrantClick(TObject *Sender);
	void __fastcall AllEmployeesClick(TObject *Sender);
	void __fastcall DownloadButtonClick(TObject *Sender);
	void __fastcall CreateAvatarButtonClick(TObject *Sender);
	void __fastcall SeeDepartmentsClick(TObject *Sender);
	void __fastcall AllCarsClick(TObject *Sender);
	void __fastcall SeeClientsClick(TObject *Sender);
	void __fastcall ImgHrClick(TObject *Sender);
	void __fastcall ImgEnClick(TObject *Sender);
	void __fastcall AddCarClick(TObject *Sender);
	void __fastcall AddEmployeeClick(TObject *Sender);
	void __fastcall CleanrepositoryBEFORELOGIN1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
	//TMemoryStream* picture;
	void ShowImg(TImage* image, TMemoryStream* memory);
	std::map<String, std::map<String, String>> translation;

	void ApplySettings();
	void VisualChangeLogin();
	void Inconvenient();
    void FillInfo();


};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
