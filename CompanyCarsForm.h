//---------------------------------------------------------------------------

#ifndef CompanyCarsFormH
#define CompanyCarsFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include "Data\AllData.h"
#include "CarInfoInputForm.h"
#include <map>
//---------------------------------------------------------------------------
class TForm12 : public TForm
{
__published:	// IDE-managed Components
	TListView *ListView1;
	TLabel *Title;
	TButton *LoadAll;
	TButton *AddNewCar;
	TButton *EditCar;
	TButton *RemoveCar;
	void __fastcall AddNewCarClick(TObject *Sender);
	void __fastcall EditCarClick(TObject *Sender);
	void __fastcall RemoveCarClick(TObject *Sender);
	void __fastcall ListView1SelectItem(TObject *Sender, TListItem *Item, bool Selected);
	void __fastcall LoadAllClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TForm12(TComponent* Owner);
	void __fastcall FillListView();
	std::map<String, std::map<String, String>> translation;
};

//---------------------------------------------------------------------------
extern PACKAGE TForm12 *Form12;
//---------------------------------------------------------------------------
#endif
