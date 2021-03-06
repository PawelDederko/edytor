//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <ActnList.hpp>
#include <ImgList.hpp>
#include <ToolWin.hpp>
#include <Dialogs.hpp>
class TDocument : public TTabSheet
{
public:
 TDocument(TPageControl *APageControl);
 __fastcall ~TDocument();
 void LoadFromFile(String AFileName);
 void SaveToFile(String AFileName);
 TRichEdit *RichEdit;
 String FileName;
};
#endif
