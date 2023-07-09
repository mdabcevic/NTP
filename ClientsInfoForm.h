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
#include <map>
//---------------------------------------------------------------------------
class TForm10 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Title;
	TListView *ListView1;
	TButton *AddClient;
	TButton *EditClient;
	TButton *DeleteClient;
	TGroupBox *GroupBox1;
	TEdit *CompanyNameBox;
	TEdit *AddressBox;
	TEdit *IDBox;
	TEdit *EmailBox;
	TEdit *ContactPersonBox;
	TLabel *CompanyLabel;
	TLabel *ContactPersonLabel;
	TLabel *EmailLabel;
	TLabel *IDLabel;
	TLabel *AddressLabel;
	void __fastcall AddClientClick(TObject *Sender);
	void __fastcall DeleteClientClick(TObject *Sender);
	void __fastcall ListView1SelectItem(TObject *Sender, TListItem *Item, bool Selected);
	void __fastcall EditClientClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TForm10(TComponent* Owner);
	void LoadListView();
    std::map<String, std::map<String, String>> translation;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm10 *Form10;
//---------------------------------------------------------------------------
#endif
