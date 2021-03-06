//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "mmsystem.h"

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int dX = 0;
int dY = 0;

int rightPoints = 0;
int leftPoints = 0;
int numberOfHits = 0;

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
        if (Ball->Top <= 0 && dY < 0)
                dY = -dY;
        //hit bottom wall
        if ((Ball->Top+Ball->Height) >= Background->Height && dY > 0)
                dY = -dY;
        //right paddle hit or miss
        if (Ball->Left+Ball->Width >= RightPaddle->Left+RightPaddle->Width/2 &&
            Ball->Top <= RightPaddle->Top+RightPaddle->Height &&
            Ball->Top+Ball->Height >= RightPaddle->Top) {
                if (dX > 0)
                        dX = -dX;
                numberOfHits++;
                if (numberOfHits%5 == 0 && numberOfHits < 20){
                        dX-=2;
                }
                if ( Ball->Top <= RightPaddle->Top+RightPaddle->Height/4)
                        dY = -8;
                else if ( Ball->Top >= RightPaddle->Top+(3*RightPaddle->Height/4))
                        dY = 8;
                else {
                        if (dY > 0)
                                dY = 5;
                        else
                                dY = -5;
                }
                sndPlaySound("snd/paddle.wav", SND_ASYNC);
        } else if (Ball->Left+Ball->Width > RightPaddle->Left+RightPaddle->Width/2){
                BallTimer->Enabled = false;
                Ball->Visible = false;
                leftPoints++;
                Scores->Caption = IntToStr(leftPoints) + " : " + IntToStr(rightPoints);
                Scores->Visible = true;
                NextRound->Visible = true;
                WhoGotsPoint->Caption = "< Punkt dla gracza lewego";
                WhoGotsPoint->Visible = true;
                NumberOfHits->Caption = "Liczba odbi�: " + IntToStr(numberOfHits);
                NumberOfHits->Visible = true;
                NewGame->Visible = true;
        }
        //left paddle hit or miss
        if (Ball->Left <= LeftPaddle->Left+LeftPaddle->Width/2 &&
            Ball->Top <= LeftPaddle->Top+LeftPaddle->Height &&
            Ball->Top+Ball->Height >= LeftPaddle->Top) {
                if (dX < 0)
                        dX = -dX;
                numberOfHits++;
                if (numberOfHits%5 == 0 && numberOfHits < 20){
                        dX+=2;
                }
                if ( Ball->Top <= LeftPaddle->Top+LeftPaddle->Height/4)
                        dY = -8;
                else if ( Ball->Top >= LeftPaddle->Top+(3*LeftPaddle->Height/4))
                        dY = 8;
                else {
                        if (dY > 0)
                                dY = 5;
                        else
                                dY = -5;
                }
                sndPlaySound("snd/paddle.wav", SND_ASYNC);
        } else if (Ball->Left < LeftPaddle->Left+LeftPaddle->Width/2){
                BallTimer->Enabled = false;
                rightPoints++;
                Scores->Caption = IntToStr(leftPoints) + " : " + IntToStr(rightPoints);
                Scores->Visible = true;
                NextRound->Visible = true;
                WhoGotsPoint->Caption = "Punkt dla gracza prawego >";
                WhoGotsPoint->Visible = true;
                NumberOfHits->Caption = "Liczba odbi�: " + IntToStr(numberOfHits);
                NumberOfHits->Visible = true;
                NewGame->Visible = true;
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RightPaddleDownTimer(TObject *Sender)
{
        if (RightPaddle->Top+RightPaddle->Height < Background->Height)
                RightPaddle->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RightPaddleUpTimer(TObject *Sender)
{
        if (RightPaddle->Top > 0)
                RightPaddle->Top -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        //right paddle up
        if (Key == VK_UP)
                RightPaddleUp->Enabled = true;
        //right paddle down
        if (Key == VK_DOWN)
                RightPaddleDown->Enabled = true;
         //left paddle up
        if (Key == 'A' || Key == 'a')
                LeftPaddleUp->Enabled = true;
        //left paddle down
        if (Key == 'Z' || Key == 'z')
                LeftPaddleDown->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        // right paddle up - stop
        if (Key == VK_UP)
                RightPaddleUp->Enabled = false;
        // right paddle down - stop
        if (Key == VK_DOWN)
                RightPaddleDown->Enabled = false;
        //left paddle up - stop
        if (Key == 'A' || Key == 'a')
                LeftPaddleUp->Enabled = false;
        //left paddle down - stop
        if (Key == 'Z' || Key == 'z')
                LeftPaddleDown->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::LeftPaddleUpTimer(TObject *Sender)
{
        if (LeftPaddle->Top > 0)
                LeftPaddle->Top -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::LeftPaddleDownTimer(TObject *Sender)
{
        if (LeftPaddle->Top+LeftPaddle->Height < Background->Height)
                LeftPaddle->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::NextRoundClick(TObject *Sender)
{
        Scores->Visible = false;
        NextRound->Visible = false;
        if (dX > 0)
                dX = -6;
        else
                dX = 6;
        dY = 5;
        Ball->Left = Background->Width/2 - Ball->Width/2;
        Ball->Top = Background->Height/2 - Ball->Height/2;
        Ball->Visible = true;
        BallTimer->Enabled = true;
        WhoGotsPoint->Visible = false;
        NumberOfHits->Visible = false;
        numberOfHits = 0;
        NewGame->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::NewGameClick(TObject *Sender)
{
        NewGame->Visible = false;
        WhoGotsPoint->Visible = false;
        dX = 6;
        dY = 5;
        rightPoints = 0;
        leftPoints = 0;
        numberOfHits = 0;
        Scores->Visible = false;
        NextRound->Visible = false;
        Ball->Left = Background->Width/2 - Ball->Width/2;
        Ball->Top = Background->Height/2 - Ball->Height/2;
        Ball->Visible = true;
        BallTimer->Enabled = true;
        WhoGotsPoint->Visible = false;
        NumberOfHits->Visible = false;
}
//---------------------------------------------------------------------------

