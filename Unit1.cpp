//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int dX = 0;
int dY = -5;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BallTimerTimer(TObject *Sender)
{
        Ball->Left += dX;
        Ball->Top += dY;

        //hit top wall
        if (Ball->Top <= 0)
                dY = -dY;
        //hit bottom wall
        if ((Ball->Top+Ball->Height) >= Background->Height)
                dY = -dY;
}
//---------------------------------------------------------------------------
