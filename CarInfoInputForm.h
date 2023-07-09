//---------------------------------------------------------------------------

#ifndef CarInfoInputFormH
#define CarInfoInputFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <map>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TLabel *LicensePlate_Label;
	TLabel *InternalName_Label;
	TLabel *Assigned_Label;
	TLabel *User_Label;
	TLabel *Location_Label;
	TEdit *LicensePlate_Box;
	TEdit *InternalName_Box;
	TEdit *Assigned_Box;
	TEdit *User_Box;
	TEdit *Location_Box;
	TButton *SaveCarChanges_Button;
	void __fastcall SaveCarChanges_ButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations

	__fastcall TForm3(TComponent* Owner);
	void AddCarMode();
	void EditCarMode();
	bool CheckPlates();

	std::map<String, std::map<String, String>> translation;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
