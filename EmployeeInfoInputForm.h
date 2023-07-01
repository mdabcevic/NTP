//---------------------------------------------------------------------------

#ifndef EmployeeInfoInputFormH
#define EmployeeInfoInputFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.NumberBox.hpp>
//---------------------------------------------------------------------------
class TForm6 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TButton *Button1;
	TEdit *FirstNameBox;
	TLabel *FirstNameLabel;
	TEdit *LastNameBox;
	TLabel *LastNameLabel;
	TEdit *IDNumberBox;
	TLabel *IDNumberLabel;
	TEdit *EducationBox;
	TLabel *EducationLabel;
	TEdit *AddressBox;
	TLabel *AddressLabel;
	TEdit *DepositAccBox;
	TLabel *DepositAccountLabel;
	TLabel *DepartmentCodeLabel;
	TDBLookupComboBox *DepartmentLookup;
	TNumberBox *TenureBox;
	TLabel *TenureLabel;
	TUpDown *UpDown1;
	TLabel *DriverLicenseLabel;
	TCheckBox *isDriver;
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm6(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm6 *Form6;
//---------------------------------------------------------------------------
#endif
