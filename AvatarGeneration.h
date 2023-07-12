//---------------------------------------------------------------------------

#ifndef AvatarGenerationH
#define AvatarGenerationH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.EngExt.hpp>
#include <Data.Bind.ObjectScope.hpp>
#include <REST.Client.hpp>
#include <REST.Types.hpp>
#include <System.Bindings.Outputs.hpp>
#include <System.Rtti.hpp>
#include <Vcl.Bind.DBEngExt.hpp>
#include <Vcl.Bind.Editors.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Mask.hpp>
//---------------------------------------------------------------------------

#ifdef EXPORTS
	#define DLL_EXPORT __declspec(dllexport)
#else
	#define DLL_EXPORT __declspec(dllimport)
#endif

class DLL_EXPORT TForm14 : public TForm
{
__published:	// IDE-managed Components
	TMemo *Memo1;
	TRESTClient *RESTClient1;
	TRESTRequest *RESTRequest1;
	TRESTResponse *RESTResponse1;
	TBindingsList *BindingsList1;
	TLinkControlToField *LinkControlToField1;
	TLabeledEdit *LabeledEdit1;
	TButton *Button1;
	TLabeledEdit *LabeledEdit2;
	TLinkControlToField *LinkControlToField2;
	TLinkControlToField *LinkControlToField3;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm14(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TForm14 *Form14;
//---------------------------------------------------------------------------
#endif
