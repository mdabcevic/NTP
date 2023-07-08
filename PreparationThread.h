//---------------------------------------------------------------------------

#ifndef PreparationThreadH
#define PreparationThreadH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class Preparation : public TThread
{
private:
protected:
	void __fastcall Execute();
public:
	__fastcall Preparation(bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
